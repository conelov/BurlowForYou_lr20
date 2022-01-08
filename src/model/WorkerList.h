//
// Created by dym on 08.01.2022.
//

#pragma once

#include "logic/fwd.h"

#include <QAbstractListModel>

namespace ml {

class WorkerList final : public QAbstractListModel
{
  Q_OBJECT

public:
  ~WorkerList() override;
  WorkerList(QObject* parent);

public slots:
  void pushBack(lg::WorkerPtr wp);
  void remove(int index);

  int      rowCount(const QModelIndex& parent = {}) const override;
  QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
  void     sort(int column, Qt::SortOrder order = Qt::SortOrder::AscendingOrder) override;

private:
  struct Private;
  QScopedPointer<Private> const p;
};
} // namespace ml