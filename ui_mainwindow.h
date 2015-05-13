/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSalir;
    QAction *actionSaveAs;
    QAction *actionAddTeam;
    QAction *actionSearchByName;
    QAction *actionSortByPoints;
    QAction *actionSave;
    QAction *actionSortByGoals;
    QAction *actionAddPlayer;
    QAction *actionInvertTeamSort;
    QAction *actionInvertPlayerSort;
    QAction *actionOpen_Binary;
    QAction *actionSave_All_B_inary;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QListWidget *lstwPlayer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnSortPlayer;
    QPushButton *btnAddPlayer;
    QPushButton *btnEditPlayer;
    QPushButton *btnDeletePlayer;
    QPushButton *btnSearchTeam_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnSortTeam;
    QPushButton *btnAddTeam;
    QPushButton *btnEditTeam;
    QPushButton *btnDeleteTeam;
    QPushButton *btnSearchTeam;
    QListWidget *lstwTeam;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_Options;
    QMenu *menu_Players;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(850, 383);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSalir = new QAction(MainWindow);
        actionSalir->setObjectName(QStringLiteral("actionSalir"));
        actionSaveAs = new QAction(MainWindow);
        actionSaveAs->setObjectName(QStringLiteral("actionSaveAs"));
        actionAddTeam = new QAction(MainWindow);
        actionAddTeam->setObjectName(QStringLiteral("actionAddTeam"));
        actionSearchByName = new QAction(MainWindow);
        actionSearchByName->setObjectName(QStringLiteral("actionSearchByName"));
        actionSortByPoints = new QAction(MainWindow);
        actionSortByPoints->setObjectName(QStringLiteral("actionSortByPoints"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSortByGoals = new QAction(MainWindow);
        actionSortByGoals->setObjectName(QStringLiteral("actionSortByGoals"));
        actionAddPlayer = new QAction(MainWindow);
        actionAddPlayer->setObjectName(QStringLiteral("actionAddPlayer"));
        actionInvertTeamSort = new QAction(MainWindow);
        actionInvertTeamSort->setObjectName(QStringLiteral("actionInvertTeamSort"));
        actionInvertPlayerSort = new QAction(MainWindow);
        actionInvertPlayerSort->setObjectName(QStringLiteral("actionInvertPlayerSort"));
        actionOpen_Binary = new QAction(MainWindow);
        actionOpen_Binary->setObjectName(QStringLiteral("actionOpen_Binary"));
        actionSave_All_B_inary = new QAction(MainWindow);
        actionSave_All_B_inary->setObjectName(QStringLiteral("actionSave_All_B_inary"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lstwPlayer = new QListWidget(centralWidget);
        lstwPlayer->setObjectName(QStringLiteral("lstwPlayer"));
        sizePolicy.setHeightForWidth(lstwPlayer->sizePolicy().hasHeightForWidth());
        lstwPlayer->setSizePolicy(sizePolicy);
        lstwPlayer->setStyleSheet(QLatin1String("font: 12pt \"MS Shell Dlg 2\";\n"
"background-color: rgb(169, 181, 255);\n"
"selection-background-color: rgb(255, 183, 184);\n"
"alternate-background-color: rgb(176, 255, 183);\n"
""));
        lstwPlayer->setAlternatingRowColors(true);
        lstwPlayer->setSortingEnabled(false);

        gridLayout->addWidget(lstwPlayer, 0, 2, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btnSortPlayer = new QPushButton(centralWidget);
        btnSortPlayer->setObjectName(QStringLiteral("btnSortPlayer"));

        horizontalLayout_2->addWidget(btnSortPlayer);

        btnAddPlayer = new QPushButton(centralWidget);
        btnAddPlayer->setObjectName(QStringLiteral("btnAddPlayer"));

        horizontalLayout_2->addWidget(btnAddPlayer);

        btnEditPlayer = new QPushButton(centralWidget);
        btnEditPlayer->setObjectName(QStringLiteral("btnEditPlayer"));

        horizontalLayout_2->addWidget(btnEditPlayer);

        btnDeletePlayer = new QPushButton(centralWidget);
        btnDeletePlayer->setObjectName(QStringLiteral("btnDeletePlayer"));

        horizontalLayout_2->addWidget(btnDeletePlayer);

        btnSearchTeam_2 = new QPushButton(centralWidget);
        btnSearchTeam_2->setObjectName(QStringLiteral("btnSearchTeam_2"));

        horizontalLayout_2->addWidget(btnSearchTeam_2);


        gridLayout->addLayout(horizontalLayout_2, 1, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnSortTeam = new QPushButton(centralWidget);
        btnSortTeam->setObjectName(QStringLiteral("btnSortTeam"));

        horizontalLayout->addWidget(btnSortTeam);

        btnAddTeam = new QPushButton(centralWidget);
        btnAddTeam->setObjectName(QStringLiteral("btnAddTeam"));

        horizontalLayout->addWidget(btnAddTeam);

        btnEditTeam = new QPushButton(centralWidget);
        btnEditTeam->setObjectName(QStringLiteral("btnEditTeam"));

        horizontalLayout->addWidget(btnEditTeam);

        btnDeleteTeam = new QPushButton(centralWidget);
        btnDeleteTeam->setObjectName(QStringLiteral("btnDeleteTeam"));

        horizontalLayout->addWidget(btnDeleteTeam);

        btnSearchTeam = new QPushButton(centralWidget);
        btnSearchTeam->setObjectName(QStringLiteral("btnSearchTeam"));

        horizontalLayout->addWidget(btnSearchTeam);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        lstwTeam = new QListWidget(centralWidget);
        lstwTeam->setObjectName(QStringLiteral("lstwTeam"));
        sizePolicy.setHeightForWidth(lstwTeam->sizePolicy().hasHeightForWidth());
        lstwTeam->setSizePolicy(sizePolicy);
        lstwTeam->setStyleSheet(QLatin1String("font: 12pt \"MS Shell Dlg 2\";\n"
"background-color: rgb(169, 181, 255);\n"
"selection-background-color: rgb(255, 183, 184);\n"
"alternate-background-color: rgb(176, 255, 183);\n"
""));
        lstwTeam->setAlternatingRowColors(true);
        lstwTeam->setSortingEnabled(false);

        gridLayout->addWidget(lstwTeam, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 850, 18));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menu_Options = new QMenu(menuBar);
        menu_Options->setObjectName(QStringLiteral("menu_Options"));
        menu_Players = new QMenu(menuBar);
        menu_Players->setObjectName(QStringLiteral("menu_Players"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(btnSortTeam, btnAddTeam);
        QWidget::setTabOrder(btnAddTeam, btnEditTeam);
        QWidget::setTabOrder(btnEditTeam, btnDeleteTeam);
        QWidget::setTabOrder(btnDeleteTeam, btnSearchTeam);
        QWidget::setTabOrder(btnSearchTeam, btnSortPlayer);
        QWidget::setTabOrder(btnSortPlayer, btnAddPlayer);
        QWidget::setTabOrder(btnAddPlayer, btnEditPlayer);
        QWidget::setTabOrder(btnEditPlayer, btnDeletePlayer);
        QWidget::setTabOrder(btnDeletePlayer, btnSearchTeam_2);
        QWidget::setTabOrder(btnSearchTeam_2, lstwTeam);
        QWidget::setTabOrder(lstwTeam, lstwPlayer);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_Options->menuAction());
        menuBar->addAction(menu_Players->menuAction());
        menu_File->addAction(actionOpen);
        menu_File->addAction(actionSearchByName);
        menu_File->addAction(actionSave);
        menu_File->addAction(actionSaveAs);
        menu_File->addAction(actionSalir);
        menu_Options->addAction(actionSortByPoints);
        menu_Options->addAction(actionInvertTeamSort);
        menu_Options->addAction(actionAddTeam);
        menu_Players->addAction(actionSortByGoals);
        menu_Players->addAction(actionInvertPlayerSort);
        menu_Players->addAction(actionAddPlayer);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSave);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSaveAs);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSalir);

        retranslateUi(MainWindow);
        QObject::connect(actionOpen, SIGNAL(triggered()), MainWindow, SLOT(openFile()));
        QObject::connect(actionSalir, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(actionSaveAs, SIGNAL(triggered()), MainWindow, SLOT(saveAs()));
        QObject::connect(actionAddTeam, SIGNAL(triggered()), MainWindow, SLOT(addTeam()));
        QObject::connect(btnDeleteTeam, SIGNAL(clicked()), MainWindow, SLOT(deleteTeam()));
        QObject::connect(btnEditTeam, SIGNAL(clicked()), MainWindow, SLOT(editTeam()));
        QObject::connect(actionSearchByName, SIGNAL(triggered()), MainWindow, SLOT(searchTeam()));
        QObject::connect(actionSortByPoints, SIGNAL(triggered()), MainWindow, SLOT(sortTeamList()));
        QObject::connect(actionSave, SIGNAL(triggered()), MainWindow, SLOT(saveAll()));
        QObject::connect(lstwTeam, SIGNAL(currentRowChanged(int)), MainWindow, SLOT(loadPlayerList(int)));
        QObject::connect(btnSortTeam, SIGNAL(clicked()), MainWindow, SLOT(sortTeamList()));
        QObject::connect(btnSortPlayer, SIGNAL(clicked()), MainWindow, SLOT(sortPlayerList()));
        QObject::connect(btnAddTeam, SIGNAL(clicked()), MainWindow, SLOT(addTeam()));
        QObject::connect(btnAddPlayer, SIGNAL(clicked()), MainWindow, SLOT(addPlayer()));
        QObject::connect(btnEditPlayer, SIGNAL(clicked()), MainWindow, SLOT(editPlayer()));
        QObject::connect(btnDeletePlayer, SIGNAL(clicked()), MainWindow, SLOT(deletePlayer()));
        QObject::connect(btnSearchTeam, SIGNAL(clicked()), MainWindow, SLOT(searchTeam()));
        QObject::connect(btnSearchTeam_2, SIGNAL(clicked()), MainWindow, SLOT(searchPlayer()));
        QObject::connect(actionInvertPlayerSort, SIGNAL(triggered()), MainWindow, SLOT(sortPlayerListDesc()));
        QObject::connect(actionInvertTeamSort, SIGNAL(triggered()), MainWindow, SLOT(sortTeamListDesc()));
        QObject::connect(actionSortByGoals, SIGNAL(triggered()), MainWindow, SLOT(sortPlayerList()));
        QObject::connect(lstwTeam, SIGNAL(doubleClicked(QModelIndex)), MainWindow, SLOT(editTeam()));
        QObject::connect(lstwPlayer, SIGNAL(doubleClicked(QModelIndex)), MainWindow, SLOT(editPlayer()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Champion League L.P. App", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "&Open", 0));
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionSalir->setText(QApplication::translate("MainWindow", "&Exit", 0));
        actionSalir->setShortcut(QApplication::translate("MainWindow", "Ctrl+E", 0));
        actionSaveAs->setText(QApplication::translate("MainWindow", "Sa&ve As...", 0));
        actionSaveAs->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", 0));
        actionAddTeam->setText(QApplication::translate("MainWindow", "&Add", 0));
        actionSearchByName->setText(QApplication::translate("MainWindow", "Search By &Name", 0));
        actionSortByPoints->setText(QApplication::translate("MainWindow", "&Sort By Points", 0));
        actionSave->setText(QApplication::translate("MainWindow", "&Save All", 0));
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        actionSortByGoals->setText(QApplication::translate("MainWindow", "&Sort By Goals", 0));
        actionAddPlayer->setText(QApplication::translate("MainWindow", "&Add", 0));
        actionInvertTeamSort->setText(QApplication::translate("MainWindow", "&Reverse Sort", 0));
        actionInvertPlayerSort->setText(QApplication::translate("MainWindow", "Reverse Sort", 0));
        actionOpen_Binary->setText(QApplication::translate("MainWindow", "Open &Binary", 0));
        actionSave_All_B_inary->setText(QApplication::translate("MainWindow", "Save All B&inary", 0));
        btnSortPlayer->setText(QApplication::translate("MainWindow", "Sort", 0));
        btnAddPlayer->setText(QApplication::translate("MainWindow", "Add", 0));
        btnEditPlayer->setText(QApplication::translate("MainWindow", "Edit selected", 0));
        btnDeletePlayer->setText(QApplication::translate("MainWindow", "Delete Selected", 0));
        btnSearchTeam_2->setText(QApplication::translate("MainWindow", "Search", 0));
        btnSortTeam->setText(QApplication::translate("MainWindow", "Sort", 0));
        btnAddTeam->setText(QApplication::translate("MainWindow", "Add", 0));
        btnEditTeam->setText(QApplication::translate("MainWindow", "Edit selected", 0));
        btnDeleteTeam->setText(QApplication::translate("MainWindow", "Delete Selected", 0));
        btnSearchTeam->setText(QApplication::translate("MainWindow", "Search", 0));
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", 0));
        menu_Options->setTitle(QApplication::translate("MainWindow", "&Teams", 0));
        menu_Players->setTitle(QApplication::translate("MainWindow", "&Players", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
