# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2016 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

cma_print_current_directory()

find_package(Boost ${BOOST_MINIMUM_VERSION} REQUIRED COMPONENTS program_options)
find_package(GLM   ${GLM_MINIMUM_VERSION}   REQUIRED)
find_package(HUGH                           REQUIRED COMPONENTS field support)

include_directories(SYSTEM ${Boost_INCLUDE_DIR})
include_directories(SYSTEM ${GLM_INCLUDE_DIR})
include_directories(SYSTEM ${HUGH_INCLUDE_DIRS})
include_directories(       ${CMAKE_CURRENT_SOURCE_DIR})

set(SRC)
list(APPEND SRC "application/base.cpp")
list(APPEND SRC "application/command_line.cpp")
list(APPEND SRC "application/multi_instance.cpp")
list(APPEND SRC "application/single_instance.cpp")
list(APPEND SRC "window/base.cpp")
list(APPEND SRC "window/interactive.cpp")
list(APPEND SRC "window/manager.cpp")
list(APPEND SRC "window/rect.cpp")
list(APPEND SRC "window/simple.cpp")

#add_definitions("-DHUGH_ALL_TRACE")

set(LIBS)
list(APPEND LIBS ${HUGH_LIBRARIES})
list(APPEND LIBS ${Boost_LIBRARIES})

set(LIB "hugh_platform")

cma_setup_library(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS} INCDIR "hugh/platform")
cma_setup_export(${LIB})

add_custom_target(${LIB}_all)
add_custom_target(test_${LIB}_all)

add_subdirectory(test EXCLUDE_FROM_ALL)
add_subdirectory(posix)
add_subdirectory(xcb)
