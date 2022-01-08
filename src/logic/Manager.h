//
// Created by dym on 08.01.2022.
//

#pragma once

#include "Worker.h"

namespace lg {

/// @brief руководитель проекта
class Manager final : public Worker
{
public:
  QStringList dutiesList;
  QStringList slaveNameList;

  ~Manager() override;
  Manager();

  void        setDutiesList(QStringList list) override;
  QStringList getDutiesList() const override;
  void        setSlaveNameList(QStringList list) override;
  QStringList getSlaveNameList() const override;
};
} // namespace lg