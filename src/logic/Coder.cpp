//
// Created by dym on 08.01.2022.
//

#include "logic/Coder.h"

namespace lg {

Coder::~Coder() = default;
Coder::Coder()  = default;

void Coder::setDutiesList(QStringList list)
{
  dutiesList = std::move(list);
}
QStringList Coder::getDutiesList() const
{
  return dutiesList;
}

void Coder::setSlaveNameList(QStringList list)
{ }
QStringList Coder::getSlaveNameList() const
{
  return {};
}
} // namespace lg