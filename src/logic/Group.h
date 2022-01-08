//
// Created by dym on 08.01.2022.
//

#pragma once

#include "fwd.h"

namespace lg {

class Group final
{
public:
  std::vector<WorkerPtr> workersArray;

  ~Group();
  Group();
};
} // namespace lg