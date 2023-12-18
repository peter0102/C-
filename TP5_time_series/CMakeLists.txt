cmake_minimum_required(VERSION 3.27)
project(TP5_time_series C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(TP5_time_series
        TimeSeriesGenerator.h
        TimeSeriesGenerator.h
        GaussianGenerator.cpp
        GaussianGenerator.h)
