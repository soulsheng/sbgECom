/*!
 *	\file		sbgECanIds.h
 *  \author		SBG Systems (Maxime Renaudet)
 *	\date		10 October 2014
 *
 *	\brief		Defines all sbgECom commands identifiers.
 *
 *	\section CodeCopyright Copyright Notice 
 *	Copyright (C) 2007-2013, SBG Systems SAS. All rights reserved.
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

/*!
 *	\mainpage SBG Systems Enhanced Communication library documentation
 *	Welcome to the sbgECom library documentation.<br>
 *	This documentation describes all functions implemented in the sbgECom library.
 */

#ifndef __SBG_ECAN_IDS_H__
#define __SBG_ECAN_IDS_H__

//----------------------------------------------------------------------//
//- Definition of all messages id for sbgECan                          -//
//----------------------------------------------------------------------//

/*!
 * Enum containing the list of messages that can be output on the can interface.
 */
typedef enum _SbgECanMessageId
{
	//
	// Output Messages
	//
	SBG_ECAN_MSG_STATUS_01				= 0x100,
	SBG_ECAN_MSG_STATUS_02				= 0x101,
	SBG_ECAN_MSG_STATUS_03				= 0x102,
	SBG_ECAN_MSG_UTC_0					= 0x110,
	SBG_ECAN_MSG_UTC_1					= 0x111,
	SBG_ECAN_MSG_IMU_INFO				= 0x120,
	SBG_ECAN_MSG_IMU_ACCEL				= 0x121,
	SBG_ECAN_MSG_IMU_GYRO				= 0x122,
	SBG_ECAN_MSG_IMU_DELTA_VEL			= 0x123,
	SBG_ECAN_MSG_IMU_DELTA_ANGLE		= 0x124,
	SBG_ECAN_MSG_EKF_INFO				= 0x130,
	SBG_ECAN_MSG_EKF_QUAT				= 0x131,
	SBG_ECAN_MSG_EKF_EULER				= 0x132,
	SBG_ECAN_MSG_EKF_ORIENTATION_ACC	= 0x133,
	SBG_ECAN_MSG_EKF_POS				= 0x134,
	SBG_ECAN_MSG_EKF_ALTITUDE			= 0x135,
	SBG_ECAN_MSG_EKF_POS_ACC			= 0x136,
	SBG_ECAN_MSG_EKF_VEL				= 0x137,
	SBG_ECAN_MSG_EKF_VEL_ACC			= 0x138,
	SBG_ECAN_MSG_SHIP_MOTION_INFO		= 0x140,
	SBG_ECAN_MSG_SHIP_MOTION_0_0		= 0x141,
	SBG_ECAN_MSG_SHIP_MOTION_0_1		= 0x145,
	SBG_ECAN_MSG_SHIP_MOTION_0_2		= 0x149,
	SBG_ECAN_MSG_MAG_0					= 0x150,
	SBG_ECAN_MSG_MAG_1					= 0x151,
	SBG_ECAN_MSG_MAG_2					= 0x152,
	SBG_ECAN_MSG_ODO_INFO				= 0x160,
	SBG_ECAN_MSG_ODO_VEL				= 0x161,
	SBG_ECAN_MSG_PRESSURE_INFO			= 0x162,
	SBG_ECAN_MSG_PRESSURE_ALTITUDE		= 0x163,
	SBG_ECAN_MSG_GPS1_VEL_INFO			= 0x170,
	SBG_ECAN_MSG_GPS1_VEL				= 0x171,
	SBG_ECAN_MSG_GPS1_VEL_ACC			= 0x172,
	SBG_ECAN_MSG_GPS1_VEL_COURSE		= 0x173,
	SBG_ECAN_MSG_GPS1_POS_INFO			= 0x174,
	SBG_ECAN_MSG_GPS1_POS				= 0x175,
	SBG_ECAN_MSG_GPS1_POS_ALT			= 0x176,
	SBG_ECAN_MSG_GPS1_POS_ACC			= 0x177,
	SBG_ECAN_MSG_GPS1_HDT_INFO			= 0x178,
	SBG_ECAN_MSG_GPS1_HDT				= 0x179,
	SBG_ECAN_MSG_EVENT_INFO_A			= 0x200,
	SBG_ECAN_MSG_EVENT_TIME_A			= 0x201,
	SBG_ECAN_MSG_EVENT_INFO_B			= 0x202,
	SBG_ECAN_MSG_EVENT_TIME_B			= 0x203,
	SBG_ECAN_MSG_EVENT_INFO_C			= 0x204,
	SBG_ECAN_MSG_EVENT_TIME_C			= 0x205,
	SBG_ECAN_MSG_EVENT_INFO_D			= 0x206,
	SBG_ECAN_MSG_EVENT_TIME_D			= 0x207
} SbgECanMessageId;


#endif	/* __SBG_ECOM_CMDS_H__ */
