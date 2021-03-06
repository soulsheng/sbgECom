/*!
 *	\file		sbgDefines.h
 *  \author		SBG Systems (Raphael Siryani)
 *	\date		17 March 2015
 *
 *	\brief		Header file that contains all common definitions.
 *
 *	\section CodeCopyright Copyright Notice 
 *	Copyright (C) 2007-2015, SBG Systems SAS. All rights reserved.
 *	
 *	This source code is intended for use only by SBG Systems SAS and
 *	those that have explicit written permission to use it from
 *	SBG Systems SAS.
 *	
 *	THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
 *	KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 *	IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
 *	PARTICULAR PURPOSE.
 */
#ifndef __SBG_DEFINES_H__
#define __SBG_DEFINES_H__

//----------------------------------------------------------------------//
//- Global definitions                                                 -//
//----------------------------------------------------------------------//
#ifndef DISABLE
	#define DISABLE	(0)
#endif

#ifndef ENABLE
	#define ENABLE	(1)
#endif

#ifndef FALSE
	#define FALSE	(0)
#endif

#ifndef TRUE
	#define TRUE	(1)
#endif

#ifndef NULL
	#define NULL	(0)
#endif

#ifndef SBG_INVALID_HANDLE
	#define SBG_INVALID_HANDLE	(0x00000000u)
#endif

#ifndef SBG_NOT_FOUND
	#define SBG_NOT_FOUND		(0xFFFFFFFFu)
#endif

#ifndef SBG_UNDEFINED
	#define SBG_UNDEFINED		(0xFFFFFFFFu)
#endif

#ifdef __cplusplus
	#define SBG_DELETE(p)		if (p){delete (p); (p) = NULL;}
	#define SBG_DELETE_ARRAY(p)	if (p){delete[] (p); (p) = NULL;}
	#define SBG_FREE(p)			if (p){free(p); (p) = NULL;}
	#define SBG_FREE_ARRAY(p)	if (p){free(p); (p) = NULL;}
#else
	#define SBG_DELETE			if (p){free(p); (p) = NULL;}
	#define SBG_DELETE_ARRAY	if (p){free(p); (p) = NULL;}
	#define SBG_FREE(p)			if (p){free(p); (p) = NULL;}
	#define SBG_FREE_ARRAY(p)	if (p){free(p); (p) = NULL;}
#endif

//----------------------------------------------------------------------//
//- Compiller definitions                                              -//
//----------------------------------------------------------------------//

/*!
 *	Macro used to abstract the compiler specific inline keyword.
 */
#ifndef SBG_INLINE
	#if defined (WIN32) || defined (WIN64)
		#define SBG_INLINE			__inline
	#else
		#define SBG_INLINE          static inline
	#endif
#endif

/*!
 *	Macro used to avoid compiler warning when a variable is not used.
 */
#ifndef SBG_UNUSED_PARAMETER
	#define SBG_UNUSED_PARAMETER(x)		(void)x
#endif

//----------------------------------------------------------------------//
//- Deprecation definitions				                               -//
//----------------------------------------------------------------------//

/*!
 *	Macro used to indicate that a function is deprecated.
 */
#ifdef __GNUC__
	#define SBG_DEPRECATED(func) func __attribute__ ((deprecated))
#elif defined(_MSC_VER)
	#define SBG_DEPRECATED(func) __declspec(deprecated) func
#else
	//#warning "WARNING: You need to implement SBG_DEPRECATED for this compiler"
	#define SBG_DEPRECATED(func) func
#endif

/*!
 *	Macro used to indicate that a macro is deprecated.
 */
#ifdef __GNUC__
	#define SBG_DEPRECATED_MACRO(func) __pragma(deprecated(func))
#elif defined(_MSC_VER)
#define SBG_DEPRECATED_MACRO(func) __pragma(deprecated(func))
#else
	//#warning "WARNING: You need to implement SBG_DEPRECATED_MACRO for this compiler"
	#define SBG_DEPRECATED_MACRO(func) func
#endif

//----------------------------------------------------------------------//
//  Ethernet definitions                                                //
//----------------------------------------------------------------------//

/*!
 *	Build an IP V4 address in the form a.b.c.d
 *	\param[in]	a				First 8 bits IP address.
 *	\param[in]	b				Second 8 bits IP address.
 *	\param[in]	c				Third 8 bits IP address.
 *	\param[in]	d				Last 8 bits IP address.
 *	\return						An initialized IP address object.
 */
#define SBG_IP_ADDR(a, b, c, d) (((a&0xFF) << 24) | ((b&0xFF) << 16) | ((c&0xFF) << 8) | (d&0xFF))

//----------------------------------------------------------------------//
//- Basic maths definitions                                            -//
//----------------------------------------------------------------------//
#ifndef SBG_PI
	#define SBG_PI 3.14159265358979323846
#endif

#ifndef SBG_PI_F
	#define SBG_PI_F 3.14159265358979323846f
#endif

/*!
 *	Convert an angle from radians to degrees using double precision.
 *	\param[in]	angle				The angle to convert in radians.
 *	\return							The converted angle in degrees.
 */
SBG_INLINE double sbgRadToDegD(double angle)
{
	return angle * 180.0 / SBG_PI;
}

/*!
 *	Convert an angle from degrees to radians using double precision.
 *	\param[in]	angle				The angle to convert in degrees.
 *	\return							The converted angle in radians.
 */
SBG_INLINE double sbgDegToRadD(double angle)
{
	return angle * SBG_PI / 180.0;
}

/*!
 *	Convert an angle from radians to degrees using single (float) precision.
 *	\param[in]	angle				The angle to convert in radians.
 *	\return							The converted angle in degrees.
 */
SBG_INLINE float sbgRadToDegF(float angle)
{
	return angle * 180.0f / SBG_PI_F;
}

/*!
 *	Convert an angle from degrees to radians using single (float) precision.
 *	\param[in]	angle				The angle to convert in degrees.
 *	\return							The converted angle in radians.
 */
SBG_INLINE float sbgDegToRadF(float angle)
{
	return angle * SBG_PI_F / 180.0f;
}

#endif	/* __SBG_DEFINES_H__ */
