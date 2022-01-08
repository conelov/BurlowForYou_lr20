//
// Created by dym on 08.01.2022.
//

#pragma once

#include "logic/fwd.h"

#include <QDialog>

namespace Ui {
class AddDialog;
} // namespace Ui

namespace wg {

class AddDialog final : public QDialog
{
  Q_OBJECT

public:
  ~AddDialog() override;
  AddDialog(QWidget* parent = nullptr);

  lg::WorkerPtr worker() const;

private slots:
  void verificationEnableButtonAccept(QString const& str);

private:
  QScopedPointer<Ui::AddDialog> const ui;
};
} // namespace wg
