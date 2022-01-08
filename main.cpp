#include "widget/MainWindow.h"

#include <QApplication>

int main(int argc, char* argv[])
{
  QApplication a(argc, argv);

  wg::MainWindow mainWindow;
  mainWindow.show();

  return QApplication::exec();
}
