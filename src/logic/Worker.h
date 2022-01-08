//
// Created by dym on 08.01.2022.
//

#pragma once

#include "fwd.h"

#include <QStringList>
#include <QVariant>

namespace lg {

/// @brief абстрактный класс
class Worker
{
public:
  QString name      = defString;
  QString maserName = defString;

  virtual ~Worker();
  Worker();

  virtual void        setDutiesList(QStringList list)    = 0;
  virtual QStringList getDutiesList() const              = 0;
  virtual void        setSlaveNameList(QStringList list) = 0;
  virtual QStringList getSlaveNameList() const           = 0;
};
} // namespace lg

Q_DECLARE_METATYPE(lg::WorkerPtr)