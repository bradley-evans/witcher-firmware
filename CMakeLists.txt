set(IDF_PATH $ENV{IDF_PATH})

cmake_minimum_required(VERSION 3.5)
include($ENV{IDF_PATH}/tools/cmake/project.cmake)

# Components
set(EXTRA_COMPONENT_DIRS ${CMAKE_SOURCE_DIR}/components/arduino)

project(witcher_firmware)
