cmake_minimum_required(VERSION 3.15)
include(FetchContent)

project(
    AnykaDoorbell
    VERSION 1.0
    DESCRIPTION "Custom firmware for Anyka 3760D doorbell"
    LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

set(LV_CONF_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src/lv_conf.h)

# --------------------------------------------------------------------------------
# 🔽 Fetch LVGL
# --------------------------------------------------------------------------------
FetchContent_Declare(
    lvgl
    GIT_REPOSITORY https://github.com/lvgl/lvgl.git
    GIT_TAG v7.11.0
    SOURCE_DIR ${CMAKE_BINARY_DIR}/_deps/lvgl
)
FetchContent_MakeAvailable(lvgl)

FetchContent_Declare(
    lv_drivers
    GIT_REPOSITORY https://github.com/lvgl/lv_drivers.git
    GIT_TAG v7.11.0
)
FetchContent_MakeAvailable(lv_drivers)

FetchContent_Declare(
    lv_examples
    GIT_REPOSITORY https://github.com/lvgl/lv_examples.git
    GIT_TAG v7.11.0
)
FetchContent_MakeAvailable(lv_examples)

# --------------------------------------------------------------------------------
# 📁 Collect all source files
# --------------------------------------------------------------------------------
file(GLOB_RECURSE PROJECT_SOURCES
    src/*.cpp
    src/*.c
)

file(GLOB_RECURSE LVGL_CORE_SOURCES
    ${lvgl_SOURCE_DIR}/src/*.c
)

file(GLOB_RECURSE LVGL_DRIVER_SOURCES
    ${lv_drivers_SOURCE_DIR}/*.c
)

file(GLOB_RECURSE LVGL_EXAMPLES_SOURCES
    ${lv_examples_SOURCE_DIR}/*.c
)

# --------------------------------------------------------------------------------
# 🔧 Define executable
# --------------------------------------------------------------------------------
add_executable(ak_doorbell
    ${PROJECT_SOURCES}
    ${LVGL_CORE_SOURCES}
    ${LVGL_DRIVER_SOURCES}
    ${LVGL_EXAMPLES_SOURCES}
)

# --------------------------------------------------------------------------------
# 📦 Include directories
# --------------------------------------------------------------------------------
target_include_directories(ak_doorbell PRIVATE
    src                  # contains lv_conf.h
    ${lvgl_SOURCE_DIR}/src
    ${lvgl_SOURCE_DIR}/..
    ${lv_drivers_SOURCE_DIR}
    ${lv_examples_SOURCE_DIR}
)

# --------------------------------------------------------------------------------
# ✅ Compile definitions
# --------------------------------------------------------------------------------
target_compile_definitions(ak_doorbell PRIVATE
    LV_CONF_INCLUDE_SIMPLE=1
)


