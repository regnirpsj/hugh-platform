# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2016 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

cma_print_current_directory()

find_package(Boost ${BOOST_MINIMUM_VERSION} REQUIRED COMPONENTS system unit_test_framework)

include_directories(SYSTEM ${Boost_INLCUDE_DIR})
include_directories(       ${CMAKE_CURRENT_SOURCE_DIR})

set(SRC)
LIST(APPEND SRC application.cpp)
LIST(APPEND SRC command_line.cpp)
LIST(APPEND SRC manager.cpp)
LIST(APPEND SRC rect.cpp)
LIST(APPEND SRC window.cpp)

set(LIBS)
list(APPEND LIBS ${LIB})
list(APPEND LIBS ${Boost_LIBRARIES})

cma_setup_test(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})

add_dependencies(test_hugh_platform_all test_${LIB})
