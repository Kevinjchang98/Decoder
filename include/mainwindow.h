//
// Created by Kevin Chang on 2/5/2023.
//

#ifndef DECODER__MAINWINDOW_H_
#define DECODER__MAINWINDOW_H_

#include <QMainWindow>
#include <QListWidget>
#include <QDockWidget>
#include "decoderform.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
 Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow() override;

 private:
  Ui::MainWindow *ui;
  DecoderForm *decoderForm;
  QDockWidget *dock;
  QListWidget *cipherList;
  void createCipherList();
};

#endif //DECODER__MAINWINDOW_H_
