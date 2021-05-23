cmake_minimum_required(VERSION 3.10)

project(bastion-timer)

include_directories(include)
FILE(GLOB BASTION_SOURCE src/*.c)
add_executable(bastion-timer ${BASTION_SOURCE})
target_link_libraries(bastion-timer
	pthread)