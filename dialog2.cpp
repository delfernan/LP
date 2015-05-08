#include "dialog2.h"
#include "ui_dialog2.h"

Dialog2::Dialog2(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Dialog2)
{
  ui->setupUi(this);
  iNodeToEdit_=0;
  eMode_=ADD;
}

Dialog2::~Dialog2()
{
  delete ui;
}

void Dialog2::setMode(Dialog2::ETMode peMode){
  eMode_=peMode;
  switch(eMode_) {
    case ADD: {
      ui->btnOK->setText("Add Player");
      ui->btnOK->setEnabled(true);
      ui->btnSearch->setEnabled(false);
      break;
      };
    case EDIT: {
      ui->btnOK->setText("Modify Player");
      ui->btnOK->setEnabled(true);
      ui->btnSearch->setEnabled(false);
      foreach(QLineEdit* le, findChildren<QLineEdit*>())
        le->setEnabled(true);
      break;
      };
    case SEARCH: {
      ui->btnOK->setText("Modify Player");
      ui->btnOK->setEnabled(false);
      ui->btnSearch->setEnabled(true);
      foreach(QLineEdit* le, findChildren<QLineEdit*>())
        le->setEnabled(false);
      ui->lePlayer->setEnabled(true);
      break;
    }
  }
}

void Dialog2::setList(List<Player> &pjugadores){
  jugadores_=&pjugadores;
}

void Dialog2::setNode(size_t iPos){
  iNodeToEdit_=iPos;
  loadPlayer();
}

void Dialog2::loadPlayer(){
  Player tTemp=jugadores_->searchPos(iNodeToEdit_);
  ui->lePlayer->setText(QString::fromLocal8Bit(tTemp.getNombre()));
  ui->lePlayerG->setText(QString("%1").arg(tTemp.getNGoles()));
}
void Dialog2::takePlayerFromUi(Player &pPlayer){
  pPlayer.setNombre(ui->lePlayer->text().toLocal8Bit().data());
  pPlayer.setNGoles(ui->lePlayerG->text().toInt());
}
void Dialog2::callFunctionPlayer(){
  if (ui->lePlayer->text().isEmpty()){
    msgUser("Alert","Player name can not be empty");
    return;
  }
  Player playerTemp;
  takePlayerFromUi(playerTemp);
  if (iNodeToEdit_){ // Modificar
    jugadores_->modify(iNodeToEdit_,playerTemp);
    msgUser("OK","Item was successfully changed.");
  }else{ // Añadir
    //jugadores_->insertAfter(playerTemp);
    jugadores_->insertSorted(playerTemp);
    msgUser("OK","Item successfully added.");
  }
}

void Dialog2::searchPlayer(){
  Player playerTemp;
  takePlayerFromUi(playerTemp);
  size_t iPosTemp=jugadores_->searchEleName(playerTemp);
  if (iPosTemp){
    msgUser("Player Found","The first coincidence has been found.");
    setNode(iPosTemp);
    setMode(EDIT);
  }else{
    msgUser("Player Not Found","There is no player coincidence.");
  }
}
void Dialog2::msgUser(const QString title, const QString message){
  QMessageBox msgBox;
  msgBox.setWindowTitle(title);
  msgBox.setText(message);
  msgBox.exec();
}
void Dialog2::clearAll(){
  foreach(QLineEdit* le, findChildren<QLineEdit*>())
    le->clear();
}
