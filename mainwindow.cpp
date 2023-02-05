//
// Created by Kevin Chang on 2/5/2023.
//

#include "mainwindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  // Set title
  setWindowTitle(tr("Decoder"));
  setUnifiedTitleAndToolBarOnMac(true);

  // Initialize main decoder form
  decoderForm = new DecoderForm(this);

  // Set as central widget
  setCentralWidget(decoderForm);

  statusBar()->showMessage("test");
}

MainWindow::~MainWindow() {
  delete ui;
}
