//
// Created by dym on 08.01.2022.
//

#include "AddDialog.h"

#include "fwd.h"
#include "logic/Coder.h"
#include "logic/Developer.h"
#include "logic/Manager.h"
#include "ui_AddDialog.h"

#include <QPushButton>
#include <boost/hana/unpack.hpp>

namespace wg {

AddDialog::~AddDialog() = default;
AddDialog::AddDialog(QWidget* parent) : QDialog {parent}, ui {new Ui::AddDialog}
{
  ui->setupUi(this);

  for (auto const l : lg::labelArWorkerIndex) {
    ui->cb_type->addItem(l);
  }

  QObject::connect(ui->le_name, &QLineEdit::textChanged, this, &AddDialog::verificationEnableButtonAccept);

  verificationEnableButtonAccept(ui->le_name->text());
}

lg::WorkerPtr AddDialog::worker() const
{
  auto constexpr ctors = boost::hana::unpack(lg::WorkerList_t, [](auto... t) {
    return std::array<lg::WorkerPtr (*)(), sizeof...(t)> {([] { return lg::WorkerPtr {new typename decltype(t)::type}; })...};
  });

  auto w       = ctors[ui->cb_type->currentIndex()]();
  w->name      = ui->le_name->text();
  w->maserName = ui->le_maserName->text();
  w->setDutiesList(ui->le_dutiesSeq->text().split(stringListDelimiter, QString::SkipEmptyParts));
  w->setSlaveNameList(ui->le_slaveNameSeq->text().split(stringListDelimiter, QString::SkipEmptyParts));

  return w;
}

void AddDialog::verificationEnableButtonAccept(QString const& str)
{
  auto const isEnabled = !str.isEmpty();
  auto const b         = ui->bb->button(QDialogButtonBox::Ok);

  b->setEnabled(isEnabled);
  b->setToolTip(isEnabled ? QString {} : QString {"Заполните поле '%1'"}.arg(ui->l_name->text()));
}

} // namespace wg
