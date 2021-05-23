cmake_minimum_required(VERSION 3.10)

project(bastion-timer VERSION 1.0)

include_directories(include)
FILE(GLOB BASTION_SOURCE src/*.c)
add_executable(bastion-timer ${BASTION_SOURCE})
target_link_libraries(bastion-timer
	pthread)

install(TARGETS bastion-timer)

if(WIN32)
set(CPACK_GENERATOR Archive)
elseif(UNIX)
set(CPACK_GENERATOR RPM)
endif()
include(CPack)