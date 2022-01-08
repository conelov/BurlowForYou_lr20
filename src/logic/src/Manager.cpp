//
// Created by dym on 08.01.2022.
//

#include "logic/Manager.h"

namespace lg {

Manager::~Manager() = default;
Manager::Manager()  = default;

void Manager::setDutiesList(QStringList list)
{
  dutiesList = std::move(list);
}
QStringList Manager::getDutiesList() const
{
  return dutiesList;
}

void Manager::setSlaveNameList(QStringList list)
{
  slaveNameList = std::move(list);
}
QStringList Manager::getSlaveNameList() const
{
  return slaveNameList;
}
} // namespace lg