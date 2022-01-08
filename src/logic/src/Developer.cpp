//
// Created by dym on 08.01.2022.
//

#include "logic/Developer.h"

namespace lg {

Developer::~Developer() = default;
Developer::Developer()  = default;

void Developer::setDutiesList(QStringList list)
{
  dutiesList = std::move(list);
}
QStringList Developer::getDutiesList() const
{
  return dutiesList;
}

void Developer::setSlaveNameList(QStringList list)
{
  slaveNameList = std::move(list);
}
QStringList Developer::getSlaveNameList() const
{
  return slaveNameList;
}
} // namespace lg