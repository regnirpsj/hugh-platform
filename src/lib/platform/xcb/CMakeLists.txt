# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2016 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

find_package(XCB COMPONENTS xcb-util)

if(NOT XCB_FOUND)
  message(WARNING "Optional XCB support not enabled")
  return()
endif()

cma_print_current_directory()

find_package(Boost ${BOOST_MINIMUM_VERSION} REQUIRED)
find_package(HUGH                           REQUIRED COMPONENTS support)

include_directories(SYSTEM ${Boost_INCLUDE_DIR})
include_directories(SYSTEM ${XCB_INCLUDE_DIRS})
include_directories(SYSTEM ${HUGH_INCLUDE_DIRS})

set(SRC)

list(APPEND SRC io.cpp)

list(APPEND SRC window/context.cpp)
list(APPEND SRC window/input.cpp)
list(APPEND SRC window/update.cpp)

add_definitions(${XCB_DEFINITIONS})
#add_definitions(-DHUGH_ALL_TRACE)

set(LIBS)
list(APPEND LIBS hugh_platform)
list(APPEND LIBS ${HUGH_LIBRARIES})
list(APPEND LIBS ${XCB_LIBRARIES})

set(LIB ${LIB}_xcb)

cma_setup_library(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS} INCDIR hugh/platform/xcb)

add_subdirectory(test EXCLUDE_FROM_ALL)

add_dependencies(hugh_platform_all ${LIB})
