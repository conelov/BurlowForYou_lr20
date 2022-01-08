cmake_minimum_required(VERSION 3.16.3)
project(lab20 VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

set(REQUIRED_LIBS_QUALIFIED)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets Quick)
foreach (lib ${REQUIRED_LIBS})
    list(APPEND REQUIRED_LIBS_QUALIFIED Qt${QT_VERSION}::${lib})
endforeach ()
find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)

add_executable(lab20
        main.cpp

        src/widget/fwd.h
        src/widget/MainWindow.h src/widget/src/MainWindow.cpp
        src/widget/AddDialog.h src/widget/src/AddDialog.cpp

        src/logic/fwd.h
        src/logic/Worker.h src/logic/src/Worker.cpp
        src/logic/Manager.h src/logic/src/Manager.cpp
        src/logic/Developer.h src/logic/src/Developer.cpp
        src/logic/Coder.h src/logic/Coder.cpp
        src/logic/Group.h src/logic/Group.cpp

        src/model/fwd.h
        src/model/WorkerList.h src/model/src/WorkerList.cpp
        )
target_link_libraries(lab20 PUBLIC ${REQUIRED_LIBS_QUALIFIED})
set_target_properties(lab20 PROPERTIES
        AUTOMOC ON
        AUTOUIC ON
        AUTOUIC_SEARCH_PATHS src/widget/ui
        INCLUDE_CURRENT_DIR ON
        )
target_include_directories(lab20
        PUBLIC
        src
        ${BOOST_ROOT}

        PRIVATE
        src/widget
        "${CMAKE_BINARY_DIR}"
        )

