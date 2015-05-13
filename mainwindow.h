/**
 * @file mainwindow.h
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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define DEFAULT_DATA_TEAM_FILE "equipos"
#define DEFAULT_DATA_PLAYER_FILE "jugadores"
#define DEFAULT_DATA_FILE_EXT ".txt"
#define DEFAULT_DATA_DIR "data"
#define BINARY_FILE false
//#define DEFAULT_DATA_DIR "binaryData"
//#define BINARY_FILE true
//#define DEFAULT_DATA_DIR "binaryData2"
//#define BINARY_FILE true
#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QDebug>
#include "dialog.h"
#include "dialog2.h"

namespace Ui {
  class MainWindow;
}
/**
 * @brief The MainWindow class
 */
class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  /**
   * @brief MainWindow constructor.
   * @param parent
   */
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private:
  Ui::MainWindow *ui;
  /**
   * @brief liga_ Team's dynamic list
   */
  List<Team> liga_;
  /**
   * @brief jugadores_ Player's dynamic list
   */
  List<Player> jugadores_;
  /**
   * @brief qsDataFile_ Team's Data file
   */
  QString qsDataFile_;
  /**
   * @brief qsDataFilePlayer_ Player's Data file
   */
  QString qsDataFilePlayer_;
  /**
   * @brief iSelectedTeam_ Selected team
   */
  size_t iSelectedTeam_;
  /**
   * @brief init method
   */
  void init();
  /**
   * @brief General messages pop up
   * @param title
   * @param message
   */
  void msgUser(const QString title, const QString message);
  /**
   * @brief loadTeamList Load data from memory to the user interfaz
   */
  void loadTeamList();
  /**
   * @brief cleanPlayerList delete actual jugadores_ list
   */
  void cleanPlayerList();
  /**
   * @brief savePlayers save players to the selected team
   */
  void savePlayers();
  /**
   * @brief deletePlayerFile delete actual player's file
   */
  void deletePlayerFile();
private slots:
  /**
   * @brief openFile Open file slot
   */
  void openFile();
  /**
   * @brief sortTeamList sort teams by points
   */
  void sortTeamList();
  /**
   * @brief saveAll Save all into data files
   */
  void saveAll();
  /**
   * @brief saveAs Save as... slot function
   */
  void saveAs();
  /**
   * @brief addTeam Open dialog in order to add new teams
   */
  void addTeam();
  /**
   * @brief editTeam Edit the selected team
   */
  void editTeam();
  /**
   * @brief deleteTeam Delete selected item... slot function
   */
  void deleteTeam();
  /**
   * @brief searchTeam Search some item
   */
  void searchTeam();

  /**
   * @brief loadList Load player data from memory to the user interfaz
   */
  void loadPlayerList(int iTeamPos);
  /**
   * @brief sortPlayerList sort players by goals
   */
  void sortPlayerList();
  /**
   * @brief addTeam Open dialog in order to add new teams
   */
  void addPlayer();
  /**
   * @brief editTeam Edit the selected team
   */
  void editPlayer();
  /**
   * @brief deleteTeam Delete selected item... slot function
   */
  void deletePlayer();
  /**
   * @brief searchTeam Search some item
   */
  void searchPlayer();
  /**
   * @brief sortTeamListDesc Reverse sort teams by points
   */
  void sortTeamListDesc();
  /**
   * @brief sortPlayerListDesc Reverse sort player by goals
   */
  void sortPlayerListDesc();

};

#endif // MAINWINDOW_H
