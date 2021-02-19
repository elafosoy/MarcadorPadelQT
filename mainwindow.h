#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QElapsedTimer>
#include <QMainWindow>
#include <QTimer>
#include "Marcador/marcador.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

  Marcador m_marcador;

  QTimer m_time;
  QElapsedTimer m_elapsedTime;

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void slotSumaPuntoEquipoA();
  void slotRestaPuntoEquipoA();

  void slotSumaPuntoEquipoB();
  void slotRestaPuntoEquipoB();

  void refreshScreen();
  void slotRefresTime();

 private:
  Ui::MainWindow *ui;
};
#endif  // MAINWINDOW_H
