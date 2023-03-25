//
// Created by Kevin Chang on 2/5/2023.
//

#include "../include/mainwindow.h"
#include "ui_MainWindow.h"
#include <QDockWidget>
#include <QListWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  // Set title
  setWindowTitle(tr("src"));
  setUnifiedTitleAndToolBarOnMac(true);

  // Initialize main decoder form
  decoderForm = new DecoderForm(this);
  setCentralWidget(decoderForm);

  // Create cipher list (left dock)
  createCipherList();

//  statusBar()->showMessage("test");
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::createCipherList() {
  // Create dock
  dock = new QDockWidget(tr("Ciphers"), this);
  dock->setAllowedAreas(Qt::LeftDockWidgetArea);

  // Create cipherList
  cipherList = new QListWidget(dock);
  cipherList->addItems(QStringList() << "Caesar Shift" << "Vigenère");

  // Set main widget in dock to be cipherList
  dock->setWidget(cipherList);

  // Add dock to MainWindow
  addDockWidget(Qt::LeftDockWidgetArea, dock);
}
