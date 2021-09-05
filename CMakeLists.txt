cmake_minimum_required(VERSION 3.19)
project(dbscan)

set(CMAKE_CXX_STANDARD 14)
# xtenror
find_package(xtensor REQUIRED)
find_package(xtensor-blas REQUIRED)

add_executable(dbscan main.cpp DataPoint.h DataPoint.cpp ClusterAnalysis.cpp ClusterAnalysis.h)
target_include_directories(dbscan PRIVATE  ${xtensor_INCLUDE_DIRS} ${xblas_INCLUDE_DIRS})
target_link_libraries(dbscan xtensor xtensor-blas)