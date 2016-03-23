# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2016 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

cma_print_current_directory()

find_package(Boost ${BOOST_MINIMUM_VERSION} REQUIRED COMPONENTS thread)
find_package(HUGH                           REQUIRED COMPONENTS field support)

include_directories(SYSTEM ${Boost_INCLUDE_DIR})
include_directories(SYSTEM ${HUGH_INCLUDE_DIRS})

set(SRC)
list(APPEND SRC "application/base.cpp")

set(LIBS)
list(APPEND LIBS hugh_platform)
list(APPEND LIBS ${HUGH_LIBRARIES})

set(LIB "${LIB}_posix")

cma_setup_library(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS}  INCDIR "hugh/platform/posix")

add_subdirectory(test EXCLUDE_FROM_ALL)

add_dependencies(hugh_platform_all ${LIB})
