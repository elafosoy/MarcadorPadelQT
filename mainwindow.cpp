#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTime>

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

  setWindowTitle("Marcador padel by AFO");

  connect(&m_time, &QTimer::timeout, this, &MainWindow::slotRefresTime);
  m_time.start(1000);
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
  if (!m_elapsedTime.isValid()) {
    m_elapsedTime.start();
    slotRefresTime();
  }
  Pantalla pantalla;

  m_marcador.refreshResults(&pantalla);
  ui->lcdPointsA->setStyleSheet("Background-color:none");
  ui->lcdPointsB->setStyleSheet("Background-color:none");

  if (pantalla.puntosA > 40) {
    if (pantalla.puntosA > pantalla.puntosB) {
      ui->lcdPointsA->display("1");
      ui->lcdPointsA->setStyleSheet("Background-color:green");
    } else if (pantalla.puntosA == pantalla.puntosB) {
      ui->lcdPointsA->display("-");
      ui->lcdPointsA->setStyleSheet("Background-color:red");
    }
  } else {
    ui->lcdPointsA->display(pantalla.puntosA);
  }

  if (pantalla.puntosB > 40) {
    if (pantalla.puntosB > pantalla.puntosA) {
      ui->lcdPointsB->display("1");
      ui->lcdPointsB->setStyleSheet("Background-color:green");
    } else if (pantalla.puntosA == pantalla.puntosB) {
      ui->lcdPointsB->display("-");
      ui->lcdPointsB->setStyleSheet("Background-color:red");
    }
  } else {
    ui->lcdPointsB->display(pantalla.puntosB);
  }

  ui->lcdJuegosA->display(pantalla.juegosA);
  ui->lcdJuegosB->display(pantalla.juegosB);

  ui->LabelSetsA->setNum(pantalla.setsA);
  ui->LabelSetsB->setNum(pantalla.setsB);
}

void MainWindow::slotRefresTime() {
  if (m_elapsedTime.isValid()) {
    quint64 elMill = m_elapsedTime.elapsed();
    QString txtTime =
        QDateTime::fromTime_t(elMill / 1000).toUTC().toString("hh:mm:ss");
    ui->leTime->setText("- " + txtTime + " -");
  }
}
