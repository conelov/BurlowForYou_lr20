//
// Created by dym on 08.01.2022.
//

#include "widget/MainWindow.h"

#include "AddDialog.h"
#include "model/WorkerList.h"
#include "ui_MainWindow.h"

#include <boost/scope_exit.hpp>

namespace wg {

struct MainWindow::Private final
{ };

MainWindow::~MainWindow() = default;

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow {parent},
      ui {new Ui::MainWindow},
      p {new Private},
      workerModel_ {new ml::WorkerList {this}}
{
  ui->setupUi(this);

  ui->lv_central->setModel(workerModel_);
}

void MainWindow::on_pb_add_clicked()
{
  auto const d = new AddDialog {this};
  BOOST_SCOPE_EXIT(d) { d->deleteLater(); }
  BOOST_SCOPE_EXIT_END;

  if (d->exec() == QDialog::Rejected) {
    return;
  }

  workerModel_->pushBack(d->worker());
}

void MainWindow::on_pb_sort_clicked()
{
  workerModel_->sort(0);
}

} // namespace wg
