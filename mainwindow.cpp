#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->pbSumaA, &QPushButton::clicked, this,
          &MainWindow::slotSumaPuntoEquipoA);
  connect(ui->pbRestaA, &QPushButton::clicked, this,
          &MainWindow::slotRestaPuntoEquipoA);

  connect(ui->pbSumaB, &QPushButton::clicked, this,
          &MainWindow::slotSumaPuntoEquipoB);
  connect(ui->pbRestaB, &QPushButton::clicked, this,
          &MainWindow::slotRestaPuntoEquipoB);
}

MainWindow::~MainWindow() {
  disconnect(ui->pbSumaA, &QPushButton::clicked, this,
             &MainWindow::slotSumaPuntoEquipoA);
  disconnect(ui->pbRestaA, &QPushButton::clicked, this,
             &MainWindow::slotRestaPuntoEquipoA);

  disconnect(ui->pbSumaB, &QPushButton::clicked, this,
             &MainWindow::slotSumaPuntoEquipoB);
  disconnect(ui->pbRestaB, &QPushButton::clicked, this,
             &MainWindow::slotRestaPuntoEquipoB);
  delete ui;
}

void MainWindow::slotSumaPuntoEquipoA() {
  m_marcador.sumaA();
  refreshScreen();
}

void MainWindow::slotSumaPuntoEquipoB() {
  m_marcador.sumaB();
  refreshScreen();
}

void MainWindow::slotRestaPuntoEquipoA() {
  m_marcador.restaA();
  refreshScreen();
}

void MainWindow::slotRestaPuntoEquipoB() {
  m_marcador.restaB();
  refreshScreen();
}

void MainWindow::refreshScreen() {
  Pantalla pantalla;

  m_marcador.refreshResults(&pantalla);

  ui->lcdPointsA->display(pantalla.puntosA);
  ui->lcdPointsB->display(pantalla.puntosB);

  ui->lcdJuegosA->display(pantalla.juegosA);
  ui->lcdJuegosB->display(pantalla.juegosB);

  ui->LabelSetsA->setNum(pantalla.setsA);
  ui->LabelSetsB->setNum(pantalla.setsB);
}
