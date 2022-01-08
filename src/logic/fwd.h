//
// Created by dym on 08.01.2022.
//

#pragma once

#include <QSharedPointer>
#include <QString>
#include <boost/hana/tuple.hpp>
#include <boost/preprocessor/stringize.hpp>

namespace lg {

QString inline const defString = "NONE";

class Worker;
class Manager;
class Developer;
class Coder;
class Group;

using WorkerIndex = std::size_t;
using WorkerPtr   = QSharedPointer<Worker>;

auto inline constexpr WorkerList_t = boost::hana::tuple_t<Manager, Developer, Coder>;

std::array inline constexpr labelArWorkerIndex = {BOOST_PP_STRINGIZE(Manager), BOOST_PP_STRINGIZE(Developer), BOOST_PP_STRINGIZE(Coder)};
} // namespace lg