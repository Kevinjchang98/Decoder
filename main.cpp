#include <QApplication>
#include "include/mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  auto window = MainWindow();
  window.show();

  return QApplication::exec();
}
