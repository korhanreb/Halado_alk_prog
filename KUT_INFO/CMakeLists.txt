#cmake_minimum_required (VERSION 2.8.12)

cmake_minimum_required(VERSION 3.0.0)
project(idomeres VERSION 0.1.0)
add_executable (idomeres main.cpp)
add_custom_command( COMMAND idomeres
WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
OUTPUT ${CMAKE_BINARY_DIR}/data.dat
DEPENDS idomeres
COMMENT "Generating data set")
add_custom_target(data ALL DEPENDS ${CMAKE_BINARY_DIR}/data.dat)


find_package (Gnuplot REQUIRED)

GNUPLOT_EXECUTABLE="C:\Program Files\gnuplot\bin\gnuplot.exe"


add_custom_command( COMMAND ${GNUPLOT_EXECUTABLE} ${PROJECT_SOURCE_DIR}/data.plt
WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
OUTPUT ${CMAKE_BINARY_DIR}/data.png
DEPENDS ${PROJECT_SOURCE_DIR}/data.plt data
COMMENT "Generating plot")
add_custom_target(plot ALL DEPENDS ${CMAKE_BINARY_DIR}/data.png)
