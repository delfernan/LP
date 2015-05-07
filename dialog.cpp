#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Dialog)
{
  ui->setupUi(this);
  iNodeToEdit_=0;
  eMode_=ADD;
}

Dialog::~Dialog()
{
  delete ui;
}

void Dialog::setMode(Dialog::ETMode peMode){
  eMode_=peMode;
  switch(eMode_) {
    case ADD: {
      ui->btnOK->setText("Add Team");
      ui->btnOK->setEnabled(true);
      ui->btnSearch->setEnabled(false);
      break;
      };
    case EDIT: {
      ui->btnOK->setText("Modify Team");
      ui->btnOK->setEnabled(true);
      ui->btnSearch->setEnabled(false);
      foreach(QLineEdit* le, findChildren<QLineEdit*>())
        le->setEnabled(true);
      break;
      };
    case SEARCH: {
      ui->btnOK->setText("Modify Team");
      ui->btnOK->setEnabled(false);
      ui->btnSearch->setEnabled(true);
      foreach(QLineEdit* le, findChildren<QLineEdit*>())
        le->setEnabled(false);
      ui->leTeam->setEnabled(true);
      break;
    }
  }
}

void Dialog::setList(List<Team> &pliga){
  liga_=&pliga;
}

void Dialog::setNode(size_t iPos){
  iNodeToEdit_=iPos;
  loadTeam();
}

void Dialog::loadTeam(){
  Team tTemp=liga_->searchPos(iNodeToEdit_);

  ui->leTeam->setText(QString::fromLocal8Bit(tTemp.getNombre()));
  ui->leWins->setText(QString("%1").arg(tTemp.getVictorias()));
  ui->leLosses->setText(QString("%1").arg(tTemp.getDerrotas()));
  ui->leDraws->setText(QString("%1").arg(tTemp.getEmpates()));
  ui->leGoals->setText(QString("%1").arg(tTemp.getGolesAFavor()));
  ui->leGoalsA->setText(QString("%1").arg(tTemp.getGolesEnContra()));
}
void Dialog::takeTeamFromUi(Team &pTeam){
  pTeam.setNombre(ui->leTeam->text().toLocal8Bit().data());
  pTeam.setVictorias(ui->leWins->text().toInt());
  pTeam.setDerrotas(ui->leLosses->text().toInt());
  pTeam.setEmpates(ui->leDraws->text().toInt());
  pTeam.setGolesAFavor(ui->leGoals->text().toInt());
  pTeam.setGolesEnContra(ui->leGoalsA->text().toInt());
}
void Dialog::callFunctionTeam(){
  if (ui->leTeam->text().isEmpty()){
    msgUser("Alert","Team name can not be empty");
    return;
  }
  Team teamTemp;
  takeTeamFromUi(teamTemp);
  if (iNodeToEdit_){ // Modificar
    liga_->modify(iNodeToEdit_,teamTemp);
    msgUser("OK","Item successfully changed.");
  }else{ // Añadir
    if (liga_->searchEleName(teamTemp))
      msgUser("Alert","Item already exists.");
    else{
      liga_->insertSorted(teamTemp);
      msgUser("OK","Item successfully added.");
    }
  }
}

void Dialog::searchTeam(){
  Team teamTemp;
  takeTeamFromUi(teamTemp);
  size_t iPosTemp=liga_->searchEleName(teamTemp);
  if (iPosTemp){
    msgUser("Team Found","The first coincidence has been found.");
    setNode(iPosTemp);
    setMode(EDIT);
  }else{
    msgUser("Team Not Found","There is no coincidence.");
  }
}
void Dialog::msgUser(const QString title, const QString message){
  QMessageBox msgBox;
  msgBox.setWindowTitle(title);
  msgBox.setText(message);
  msgBox.exec();
}
void Dialog::clearAll(){
  foreach(QLineEdit* le, findChildren<QLineEdit*>())
    le->clear();
}
