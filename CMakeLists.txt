cmake_minimum_required(VERSION 3.10)
project(inventory)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_executable(inventory)
target_sources(inventory PRIVATE
	projectz/projectz/addItem.cpp
	projectz/projectz/filterView.cpp
	projectz/projectz/removeItem.cpp
	projectz/projectz/alertMessage.cpp
	projectz/projectz/projectz.cpp
	projectz/projectz/viewItem.cpp
	projectz/projectz/class.h
)
