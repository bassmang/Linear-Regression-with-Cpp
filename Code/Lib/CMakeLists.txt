#/*============================================================================
#
#  : PHAS0100 Assignment 1 Linear Regression
#
#  Copyright (c) University College London (UCL). All rights reserved.
#
#  This software is distributed WITHOUT ANY WARRANTY; without even
#  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
#  PURPOSE.
#
#  See LICENSE.txt in the top level directory for details.
#
#============================================================================*/

set(_LIBRARY_NAME )

set(_LIBRARY_SRCS
  lrgBasicTypes.cpp
  lrgMyFunctions.cpp
  lrgException.cpp
)

set(_LIBRARY_HDRS
  lrgExceptionMacro.h
)

add_library(${_LIBRARY_NAME} ${_LIBRARY_HDRS} ${_LIBRARY_SRCS})

if(BUILD_SHARED_LIBS)
  if(WIN32)
    add_definitions(-D_WINDOWS_EXPORT)
  endif(WIN32)
endif(BUILD_SHARED_LIBS)

target_link_libraries(${_LIBRARY_NAME} PRIVATE ${ALL_THIRD_PARTY_LIBRARIES})

