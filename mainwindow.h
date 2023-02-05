//
// Created by Kevin Chang on 2/5/2023.
//

#ifndef DECODER__MAINWINDOW_H_
#define DECODER__MAINWINDOW_H_

#include <QMainWindow>

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
};

#endif //DECODER__MAINWINDOW_H_
