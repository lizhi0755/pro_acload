#cmake_minimum_required(VERSION 3.16)

project(ACLoadTool VERSION 0.1 LANGUAGES CXX)

set(TARGET_NAME appACLoad)

find_package(Qt6 REQUIRED COMPONENTS
    Core
    Quick
    QuickControls2
    Qml
    Gui
    LinguistTools
)

qt_standard_project_setup(REQUIRES 6.8)

file(GLOB_RECURSE SOURCE_FILES
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/main/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/basic/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/basic/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/comm/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/comm/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/data/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/data/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/model/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/model/*.h"
)
file(GLOB_RECURSE QML_FILES RELATIVE
  ${CMAKE_CURRENT_SOURCE_DIR} "view/qmls/*.qml"
)
file(GLOB_RECURSE IMG_FILES RELATIVE
    ${CMAKE_CURRENT_SOURCE_DIR} "view/images/*.svg"
)
file(GLOB_RECURSE VMS_FILES RELATIVE
    ${CMAKE_CURRENT_SOURCE_DIR} "data/*.cpp"
    ${CMAKE_CURRENT_SOURCE_DIR} "data/*.h"
    ${CMAKE_CURRENT_SOURCE_DIR} "model/*.cpp"
    ${CMAKE_CURRENT_SOURCE_DIR} "model/*.h"
)

file(GLOB_RECURSE TTS_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/view/translations/*.ts"
)
qt_add_translation(TQM_FILES
    ${TTS_FILES}
)
target_sources(${TARGET_NAME} PRIVATE ${TQM_FILES})


target_include_directories(${TARGET_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/basic
    ${CMAKE_CURRENT_SOURCE_DIR}/comm
    ${CMAKE_CURRENT_SOURCE_DIR}/data
    ${CMAKE_CURRENT_SOURCE_DIR}/model
)

foreach(QML_FILE ${QML_FILES})
    message(STATUS "Found QML file: ${QML_FILE}")
endforeach()
foreach(VMS_FILE ${VMS_FILES})
    message(STATUS "Found VMS file: ${VMS_FILE}")
endforeach()

set(QT_LIBRARIES
    Qt6::Core
    Qt6::Quick
    Qt6::QuickControls2
    Qt6::Qml
    Qt6::Gui
)

qt_add_executable(${TARGET_NAME}
    ${SOURCE_FILES}
)
qt_add_qml_module(${TARGET_NAME}
    URI ${PROJECT_NAME}
    VERSION 1.0
    RESOURCE_PREFIX  "/"
    QML_FILES   ${QML_FILES}
    SOURCES     ${VMS_FILES}
    RESOURCES   ${IMG_FILES} ${TQM_FILES}
    DEPENDENCIES  ${QT_LIBRARIES}
)

target_link_libraries(${TARGET_NAME} PRIVATE
    ${QT_LIBRARIES}
)

set_target_properties(${TARGET_NAME} PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

include(GNUInstallDirs)
install(TARGETS ${TARGET_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)



