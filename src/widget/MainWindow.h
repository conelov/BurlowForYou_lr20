//
// Created by dym on 08.01.2022.
//

#pragma once

#include "model/fwd.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
} // namespace Ui

namespace wg {

class MainWindow final : public QMainWindow
{
  Q_OBJECT

public:
  ~MainWindow() override;
  MainWindow(QWidget* parent = nullptr);

private slots:
  void on_pb_add_clicked();
  void on_pb_sort_clicked();

private:
  QScopedPointer<Ui::MainWindow> const ui;

  struct Private;
  QScopedPointer<Private> const p;

  ml::WorkerList* const workerModel_;
};
} // namespace wg
