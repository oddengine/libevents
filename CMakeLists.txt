cmake_minimum_required(VERSION 3.0)

if (POLICY CMP0054)
    cmake_policy(SET CMP0054 NEW)
endif()
if (POLICY CMP0057)
    cmake_policy(SET CMP0057 NEW)
endif()

# package information
set(PACKAGE_NAME      "libstud")
set(PACKAGE_VERSION   "0.1.00")
set(PACKAGE_STRING    "${PACKAGE_NAME} ${PACKAGE_VERSION}")
set(PACKAGE_TARNAME   "${PACKAGE_NAME}-${PACKAGE_VERSION}")

option(UT "ut" OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall")
add_definitions("-DBRPC_WITH_GLOG")

project(${PACKAGE_NAME} CXX C)

set(CMAKE_CXX_STANDARD 14)
set(TOP_DIR "${CMAKE_CURRENT_SOURCE_DIR}")

# dependent static libs
include_directories(/usr/local/include ${TOP_DIR}/src)
link_directories(/usr/local/lib)

set(EVENTS 
        ${TOP_DIR}/src/base/error.cc 
        ${TOP_DIR}/src/events/events.cc 
        ${TOP_DIR}/src/events/event.cc 
        ${TOP_DIR}/src/events/errorevent.cc 
        ${TOP_DIR}/src/events/eventdispatcher.cc 
)

set(SOURCES 
        ${EVENTS} 
        ${TOP_DIR}/tests/events/dummyeventdispatcher.cc 
        ${TOP_DIR}/src/main.cc 
)

add_executable(${PACKAGE_NAME} ${SOURCES})

set(LIBRARIES)

target_link_libraries(${PACKAGE_NAME} ${LIBRARIES})

if (UT)
    message(STATUS "Configuring tests")
    add_subdirectory(tests)
endif (UT)
