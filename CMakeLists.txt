cmake_minimum_required(VERSION 3.15)
include(FetchContent)

project(AnykaDoorbell)

project(
	AnykaDoorbell
	VERSION 1.0
	DESCRIPTION "Custom firmware for Anyka 3760D doorbell"
	LANGUAGES CXX)

add_executable(ak_doorbell main.cpp)

FetchContent_Declare(
	lvgl
	GIT_REPOSITORY https://github.com/lvgl/lvgl.git
	GIT_TAG v7.11.0
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

target_link_libraries(ak_doorbell PRIVATE lvgl::lvgl lvgl::drivers lvgl::examples)
