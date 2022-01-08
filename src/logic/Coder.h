//
// Created by dym on 08.01.2022.
//

#pragma once

#include "Worker.h"

namespace lg {

/// @brief младший программист
class Coder final : public Worker
{
public:
  QStringList dutiesList;

  ~Coder() override;
  Coder();

  void        setDutiesList(QStringList list) override;
  QStringList getDutiesList() const override;
  void        setSlaveNameList(QStringList list) override;
  QStringList getSlaveNameList() const override;
};
} // namespace lg