//
// Created by dym on 08.01.2022.
//

#include "model/WorkerList.h"

#include "logic/Group.h"
#include "logic/Worker.h"

namespace ml {

struct WorkerList::Private final
{
  lg::Group worker;
};

WorkerList::~WorkerList() = default;

WorkerList::WorkerList(QObject* parent) : QAbstractListModel(parent), p {new Private}
{ }

void WorkerList::pushBack(lg::WorkerPtr wp)
{
  beginInsertRows({}, rowCount(), rowCount());
  p->worker.workersArray.push_back(std::move(wp));
  endInsertRows();
}

void WorkerList::remove(int index)
{
  beginRemoveColumns({}, index, index);
  p->worker.workersArray.erase(std::next(p->worker.workersArray.cbegin(), index));
  endRemoveColumns();
}

int WorkerList::rowCount(const QModelIndex& parent) const
{
  return p->worker.workersArray.size();
}

QVariant WorkerList::data(const QModelIndex& index, int role) const
{
  if (!index.isValid()) {
    return {};
  }

  auto const& worker = *p->worker.workersArray[index.row()];

  switch (role) {
  case Qt::DisplayRole:
    return worker.name;
  case Qt::ToolTipRole:
    return QStringLiteral("Фамилия руководителя: %1\nОбязанности: %2\nПодчиненные: %3")
        .arg(worker.maserName, worker.getDutiesList().join(", "), worker.getSlaveNameList().join(", "));
  }

  return {};
}

void WorkerList::sort(int column, Qt::SortOrder order)
{
  emit layoutAboutToBeChanged();
  std::sort(p->worker.workersArray.begin(), p->worker.workersArray.end(), [](lg::WorkerPtr const& lhs, lg::WorkerPtr const& rhs) {
    return lhs->name < rhs->name;
  });
  emit layoutChanged();
}
} // namespace ml