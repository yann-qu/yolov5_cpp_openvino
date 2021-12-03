cmake_minimum_required(VERSION 3.5)
project(detect_test)
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(Detector)


add_executable(detect_test main.cpp)

target_link_libraries(detect_test
        ${OpenCV_LIBS}
        Detector_lib
)