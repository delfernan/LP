#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  init();
}
void MainWindow::init(){
  iSelectedTeam_=0;
  qsDataFile_=QString("%1%2%3%4").arg(DEFAULT_DATA_DIR).arg(QDir::separator()).
      arg(DEFAULT_DATA_TEAM_FILE).arg(DEFAULT_DATA_FILE_EXT);
  qsDataFilePlayer_=QString("%1%2%3").arg(DEFAULT_DATA_DIR).arg(QDir::separator()).
      arg(DEFAULT_DATA_PLAYER_FILE);
  bool f;
  if (BINARY_FILE)
    f=liga_.readFromBinaryFile2(qsDataFile_.toLocal8Bit().data());
  else
    f=liga_.readFromFile(qsDataFile_.toLocal8Bit().data());
  if (f)
    loadTeamList();
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::openFile(){
  //parametros: parent dialog, ti­tulo de la ventana, directorio de busqueda, filtro
  QString fileN=QFileDialog::getOpenFileName(this,tr("Open Data File"),
                                             DEFAULT_DATA_DIR,"*.txt;*.dat");
  if (!fileN.isEmpty()){
    List<Team> ligaTemp;
    //carga
    bool f;
    if (BINARY_FILE)
      f=ligaTemp.readFromBinaryFile2(fileN.toLocal8Bit().data());
    else
      f=ligaTemp.readFromFile(fileN.toLocal8Bit().data());
    if (f){
      //Nuevos ficheros
      qsDataFile_=fileN;
      QFileInfo qfiTemp(fileN);
      qsDataFilePlayer_=QString("%1%2%3").arg(qfiTemp.absolutePath()).arg(QDir::separator()).
          arg(DEFAULT_DATA_PLAYER_FILE);
      qDebug()<<"File Loaded ("+qsDataFile_+")";
      qDebug()<<"New dir: "<<qfiTemp.absolutePath();
      //Borrado de la lista anterior
      size_t iLigaLon=liga_.length();
      for (size_t i=1;i<iLigaLon+1;i++)
        liga_.erase(1);

      //cargamos la nueva liga
      ligaTemp.copy(liga_);
      loadTeamList();
    }else
      msgUser("Alert","Error loading file "+fileN);
  }
}
void MainWindow::saveAll(){
  if (qsDataFile_.isEmpty())
    qDebug() << "Team's File name is Empty";
  else{
    bool f;
    if (BINARY_FILE)
      f=liga_.writeToBinaryFile2(qsDataFile_.toLocal8Bit().data());
    else
      f=liga_.writeToFile(qsDataFile_.toLocal8Bit().data());
    if(f){
      qDebug()<<"File saved ("+qsDataFile_+")";
      //Salvando ficheros de equipos
      for (iSelectedTeam_=1;iSelectedTeam_<liga_.length()+1;iSelectedTeam_++){
        //Borrado y carga de la lista de jugadores en bucle
        loadPlayerList(iSelectedTeam_-1);
        //Salva los jugadores
        savePlayers();
      }
      if(!liga_.isEmpty()){
        ui->lstwTeam->setCurrentRow(0);
        loadPlayerList(0);
        }
    }else
      msgUser("Alert","Some error ocurred saving file "+qsDataFile_);
  }
}
void MainWindow::saveAs(){
  if (liga_.isEmpty()){
    msgUser("Alert","There is nothing to save.");
    return;
  }
  QString fileN=QFileDialog::getSaveFileName(this,tr("Select Data File"),
                                             DEFAULT_DATA_DIR,"*.txt;*.dat");
  if (fileN.isEmpty()){
    qDebug() << "File name is Empty";
  }else {
    bool f;
    if (BINARY_FILE)
      f=liga_.writeToBinaryFile2(fileN.toLocal8Bit().data());
    else
      f=liga_.writeToFile(fileN.toLocal8Bit().data());
    //f=liga_.writeToBinaryFile2(fileN.toLocal8Bit().data());
    if(f){
      //Nuevo fichero de datos
      qsDataFile_=fileN;
      qDebug()<<"File saved ("+qsDataFile_+")";
      QFileInfo qfiTemp(fileN);
      QString qsDataFilePlayerTemp=QString("%1%2%3").arg(qfiTemp.absolutePath()).arg(QDir::separator()).
          arg(DEFAULT_DATA_PLAYER_FILE);

      qDebug()<<"New file player path: "<<qfiTemp.absolutePath();
      //Salvando ficheros de equipos
      for (size_t i=1;i<liga_.length()+1;i++){
        //Borrado y Carga de la lista de jugadores en bucle
        loadPlayerList(i-1);
        QString qsPlayerFile=QString("%1_%2%3").arg(qsDataFilePlayerTemp).
            arg(QString::fromLocal8Bit(liga_.searchPos(i).getNombre())).
            arg(DEFAULT_DATA_FILE_EXT);
        bool fp;
        if (BINARY_FILE)
          fp=jugadores_.writeToBinaryFile2(qsPlayerFile.toLocal8Bit().data());
        else
          fp=jugadores_.writeToFile(qsPlayerFile.toLocal8Bit().data());
        //fp=jugadores_.writeToBinaryFile2(qsPlayerFile.toLocal8Bit().data());
        if (fp)
          qDebug()<<"\tFile saved ("+qsPlayerFile+")";
        else
          msgUser("Alert","Some error ocurred saving file "+qsPlayerFile);
      }
      //exit(0);
      qsDataFilePlayer_=qsDataFilePlayerTemp;
      if(!liga_.isEmpty()){
        ui->lstwTeam->setCurrentRow(0);
        loadPlayerList(0);
        }

    }else
      msgUser("Alert","Some error ocurred saving file "+fileN);
  }
}
void MainWindow::savePlayers(){
  QString qsPlayerFile=QString("%1_%2%3").arg(qsDataFilePlayer_).
      arg(QString::fromLocal8Bit(liga_.searchPos(iSelectedTeam_).getNombre())).
      arg(DEFAULT_DATA_FILE_EXT);
  if (qsPlayerFile.isEmpty())
    qDebug() << "Player's File name is Empty";
  else{
    bool fp;
    if (BINARY_FILE)
      fp=jugadores_.writeToBinaryFile2(qsPlayerFile.toLocal8Bit().data());
    else
      fp=jugadores_.writeToFile(qsPlayerFile.toLocal8Bit().data());
    if (fp)
      qDebug()<<"File saved ("+qsPlayerFile+")";
    else
      msgUser("Alert","Some error ocurred saving file "+qsPlayerFile);
  }
}
void MainWindow::deletePlayerFile(){
  QString qsPlayerFile=QString("%1_%2%3").arg(qsDataFilePlayer_).
      arg(QString::fromLocal8Bit(liga_.searchPos(iSelectedTeam_).getNombre())).
      arg(DEFAULT_DATA_FILE_EXT);
  if (QFile::remove(qsPlayerFile))
    qDebug() << "Fichero borrado: "<<qsPlayerFile;
  else
    qDebug() << "Problema borrando: "<<qsPlayerFile;
}

void MainWindow::deleteTeam(){
  qDebug()<<"item selected: "<<iSelectedTeam_;
  if (!iSelectedTeam_ || liga_.isEmpty()){
    msgUser("Alert","Please, select some item.");
  }else{
    if (QMessageBox::Yes == QMessageBox(
          QMessageBox::Information, "Alert", "Are you sure?",
          QMessageBox::Yes|QMessageBox::No).exec()){
      //Borrado de jugadores
      cleanPlayerList();
      //Salvamos para borrar datos
      //savePlayers();
      //También se puede borrar el fichero
      deletePlayerFile();
      //Borrado de equipo
      liga_.erase(iSelectedTeam_);
      //Carga de la lista de equipos
      loadTeamList();
      saveAll();
    }
  }
}
void MainWindow::addTeam(){
  Dialog d;
  d.setMode(Dialog::ADD);
  d.setList(liga_);
  d.exec();
  loadTeamList();
  saveAll();
}
void MainWindow::editTeam(){
  qDebug()<<"item selected: "<<iSelectedTeam_;
  if (!iSelectedTeam_ || liga_.isEmpty()){
    msgUser("Alert","Please, select some item.");
  }else{
    Dialog d;
    d.setList(liga_);
    d.setMode(Dialog::EDIT);
    d.setNode(iSelectedTeam_);
    d.exec();
    loadTeamList();
    saveAll();
    }
}

void MainWindow::searchTeam(){
  if (!liga_.isEmpty()){
    Dialog d;
    d.setList(liga_);
    d.setMode(Dialog::SEARCH);
    d.exec();
    loadTeamList();
    saveAll();
  }else
    msgUser("Alert","There is nothing to search");
}

void MainWindow::loadTeamList(){
  ui->lstwTeam->clear();
  if (!liga_.isEmpty()){
    for (size_t i=1;i<liga_.length()+1;i++){
      QString qNode=QString::fromLocal8Bit(liga_.searchPos(i).toStd().c_str());
      ui->lstwTeam->addItem(new QListWidgetItem(qNode));
      qDebug()<<qNode;
    }
  }else
    qDebug() << "Empty list";
}

void MainWindow::cleanPlayerList(){
  if(!jugadores_.isEmpty()){
    size_t iPlayerLon=jugadores_.length();
    for (size_t j=1;j<iPlayerLon+1;j++)
      jugadores_.erase(1);
  }else
    qDebug() << "Empty list";
}
void MainWindow::loadPlayerList(int iTeamPos){
  iSelectedTeam_=iTeamPos+1;
  qDebug()<<"Selected team position: "<<iSelectedTeam_;
  //Borrado de jugadores actual
  cleanPlayerList();
  //Borrado del widget
  ui->lstwPlayer->clear();
  if(!iSelectedTeam_)
    return;
  QString qsPlayerFile=QString("%1_%2%3").arg(qsDataFilePlayer_).
      arg(QString::fromLocal8Bit(liga_.searchPos(iSelectedTeam_).getNombre())).
      arg(DEFAULT_DATA_FILE_EXT);
  bool fp;
  if (BINARY_FILE)
    fp=jugadores_.readFromBinaryFile2(qsPlayerFile.toLocal8Bit().data());
  else
    fp=jugadores_.readFromFile(qsPlayerFile.toLocal8Bit().data());
  if(fp){
    qDebug()<<"Reading Player File: "<<qsPlayerFile;
    if (!jugadores_.isEmpty()){
      for (size_t i=1;i<jugadores_.length()+1;i++){
        QString qNode=QString::fromLocal8Bit(jugadores_.searchPos(i).toStd().c_str());
        ui->lstwPlayer->addItem(new QListWidgetItem(qNode));
        qDebug()<<qNode;
      }
    }else
      qDebug() << "Player Empty list";
  }else
    qDebug() << "Problem reading file "<<qsPlayerFile;
}
void MainWindow::sortTeamList(){
  if (!liga_.isEmpty()){
    liga_.sort();
    loadTeamList();
  }else{
    qDebug() << "Empty list";
    msgUser("Alert","There is nothing to sort");
  }
}
void MainWindow::sortTeamListDesc(){
  if (!liga_.isEmpty()){
    liga_.sortDesc();
    loadTeamList();
  }else{
    qDebug() << "Empty list";
    msgUser("Alert","There is nothing to sort");
  }
}
void MainWindow::sortPlayerList(){
  if (!jugadores_.isEmpty()){
    jugadores_.sort();
    savePlayers();
    loadPlayerList(iSelectedTeam_-1);
  }else{
    qDebug() << "Empty Player list";
    msgUser("Alert","There is nothing to sort");
  }
}
void MainWindow::sortPlayerListDesc(){
  if (!jugadores_.isEmpty()){
    jugadores_.sortDesc();
    savePlayers();
    loadPlayerList(iSelectedTeam_-1);
  }else{
    qDebug() << "Empty Player list";
    msgUser("Alert","There is nothing to sort");
  }
}
void MainWindow::addPlayer(){
  Dialog2 d;
  d.setMode(Dialog2::ADD);
  d.setList(jugadores_);
  d.exec();
  savePlayers();
  loadPlayerList(iSelectedTeam_-1);
}

void MainWindow::editPlayer(){
  int itemSelected=ui->lstwPlayer->currentRow();
  qDebug()<<"item selected: "<<itemSelected;
  if (itemSelected<0 || jugadores_.isEmpty()){
    msgUser("Alert","Please, select some item.");
  }else{
    Dialog2 d;
    d.setList(jugadores_);
    d.setMode(Dialog2::EDIT);
    d.setNode(itemSelected+1);
    d.exec();
    savePlayers();
    loadPlayerList(iSelectedTeam_-1);
    }
}

void MainWindow::deletePlayer(){
  int itemSelected=ui->lstwPlayer->currentRow();
  qDebug()<<"Player item selected: "<<itemSelected;
  if (itemSelected<0 || jugadores_.isEmpty()){
    msgUser("Alert","Please, select some item.");
  }else{
    if (QMessageBox::Yes == QMessageBox(
          QMessageBox::Information, "Alert", "Are you sure?",
          QMessageBox::Yes|QMessageBox::No).exec()){
      //Borrado de jugador
      jugadores_.erase(itemSelected+1);
      savePlayers();
      qDebug()<<"Cargando equipo"<<iSelectedTeam_;
      loadPlayerList(iSelectedTeam_-1);
    }
  }
}

void MainWindow::searchPlayer(){
  if (!jugadores_.isEmpty()){
    Dialog2 d;
    d.setList(jugadores_);
    d.setMode(Dialog2::SEARCH);
    d.exec();
    savePlayers();
    loadPlayerList(iSelectedTeam_-1);
  }else
    msgUser("Alert","There is nothing to search");
}
void MainWindow::msgUser(const QString title, const QString message){
  QMessageBox msgBox;
  msgBox.setWindowTitle(title);
  msgBox.setText(message);
  msgBox.exec();
}
