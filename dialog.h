/**
 * @file dialog.h
 * @author  Fernando Aparicio Galisteo fernando.aparicio@uem.es
 * @version 1.0
 *
 * @section LICENSE
 * Copyright 2015 Fernando Aparicio Galisteo Licensed under the
 * Educational Community License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License. You may
 * obtain a copy of the License at
 *
 * http://www.osedu.org/licenses/ECL-2.0
 *
 */
#ifndef DIALOG_H
#define DIALOG_H
#include "list.cpp"
#include <QDialog>
#include <QMessageBox>

namespace Ui {
  class Dialog;
}

class Dialog : public QDialog
{
  Q_OBJECT

public:
  enum ETMode { ADD, EDIT, SEARCH};
  explicit Dialog(QWidget *parent = 0);
  ~Dialog();
  void setMode(ETMode peMode);
  void setList(List<Team> & pliga);
  void setNode(size_t iPos);
  void setId(size_t pId);
private:
  Ui::Dialog *ui;
  List<Team> * liga_;
  size_t iNodeToEdit_;
  ETMode eMode_;
  int idTeam_;
  void loadTeam();
  void msgUser(const QString title, const QString message);
  void takeTeamFromUi(Team &pTeam);
private slots:
  void callFunctionTeam();
  void clearAll();
  void searchTeam();
};

#endif // DIALOG_H
