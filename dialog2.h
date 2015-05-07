#ifndef DIALOG2_H
#define DIALOG2_H
#include "list.cpp"
#include <QDialog>
#include <QMessageBox>

namespace Ui {
  class Dialog2;
}

class Dialog2 : public QDialog
{
  Q_OBJECT

public:
  enum ETMode { ADD, EDIT, SEARCH};
  explicit Dialog2(QWidget *parent = 0);
  ~Dialog2();
  void setMode(ETMode peMode);
  void setList(List<Player> & pjugadores);
  void setNode(size_t iPos);
private:
  Ui::Dialog2 *ui;
  List<Player> * jugadores_;
  size_t iNodeToEdit_;
  ETMode eMode_;
  void loadPlayer();
  void msgUser(const QString title, const QString message);
  void takePlayerFromUi(Player &pPlayer);
private slots:
  void callFunctionPlayer();
  void clearAll();
  void searchPlayer();
};

#endif // DIALOG2_H
