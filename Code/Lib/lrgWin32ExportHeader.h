/*=============================================================================

  : PHAS0100 Assignment 1 Linear Regression

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef lrgWin32ExportHeader_h
#define lrgWin32ExportHeader_h

/**
* \file lrgWin32ExportHeader.h
* \brief Header to sort Windows dllexport/dllimport.
*/

#if (defined(_WIN32) || defined(WIN32)) && !defined(_STATIC)
  #ifdef _WINDOWS_EXPORT
    #define _WINEXPORT __declspec(dllexport)
  #else
    #define _WINEXPORT __declspec(dllimport)
  #endif  /* _WINEXPORT */
#else
/* linux/mac needs nothing */
  #define _WINEXPORT
#endif

#endif
