cmake_minimum_required(VERSION 3.5)
project(Detector_lib)
set(CMAKE_CXX_STANDARD 11)

#查找必要的依赖包
find_package(OpenCV REQUIRED)
find_package(InferenceEngine)
find_package(ngraph REQUIRED)


# 编译detector.so
add_library (Detector_lib Detector.cpp)

target_link_libraries(Detector_lib
        ${OpenCV_LIBS}
        ${InferenceEngine_LIBRARIES}
        ${ngraph_LIBRARIES})