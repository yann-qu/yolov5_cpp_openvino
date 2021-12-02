cmake_minimum_required(VERSION 3.5)
project(detect_test)
set(CMAKE_CXX_STANDARD 11)

#查找必要的依赖包
find_package(OpenCV REQUIRED)
find_package(InferenceEngine)
find_package(ngraph REQUIRED)



# 编译detector.so
add_library (detector SHARED ${CMAKE_CURRENT_SOURCE_DIR}/detector.cpp)

target_link_libraries(detector
        ${OpenCV_LIBS}
        ${InferenceEngine_LIBRARIES}
        ${ngraph_LIBRARIES}
)

add_executable(detect_test main.cpp)

target_link_libraries(detect_test
        ${OpenCV_LIBS}
        detector
)