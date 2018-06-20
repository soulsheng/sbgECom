#include "sbgEComCmdFeatures.h"
#include <streamBuffer/sbgStreamBuffer.h>

//----------------------------------------------------------------------//
//- Features commands	                                               -//
//----------------------------------------------------------------------//

/*!
 *	Retrieve the device and embedded GPS receiver features.
 *	\param[in]	pHandle						A valid sbgECom handle.
 *	\param[in]	pFeatures					A pointer to a structure to hold features.
 *	\return									SBG_NO_ERROR if the command has been executed successfully.
 */
SbgErrorCode sbgEComCmdGetFeatures(SbgEComHandle *pHandle, SbgEComFeatures *pFeatures)
{
	SbgErrorCode		errorCode = SBG_NO_ERROR;
	uint32				trial;
	uint16				receivedCmd;
	uint32				receivedSize;
	uint8				receivedBuffer[SBG_ECOM_MAX_BUFFER_SIZE];
	SbgStreamBuffer		inputStream;
	SbgEComCmdId		cmd;

	//
	// Test that the input pointers are valid
	//
	if ((pHandle) && (pFeatures))
	{
		//
		// Send the command three times
		//
		for (trial = 0; trial < 3; trial++)
		{
			//
			// Build command
			//
			cmd = SBG_ECOM_BUILD_ID(SBG_ECOM_CLASS_LOG_CMD_0, SBG_ECOM_CMD_FEATURES);

			//
			// Send the command only since this is a no-payload command
			//
			errorCode = sbgEComProtocolSend(&pHandle->protocolHandle, cmd, NULL, 0);

			//
			// Make sure that the command has been sent
			//
			if (errorCode == SBG_NO_ERROR)
			{
				//
				// Try to read the device answer for 500 ms
				//
				errorCode = sbgEComReceiveAnyCmd(pHandle, &receivedCmd, receivedBuffer, &receivedSize, sizeof(receivedBuffer), SBG_ECOM_DEFAULT_CMD_TIME_OUT);

				//
				// Test if we have received a SBG_ECOM_CMD_GPS_FEATURES command
				//
				if ((errorCode == SBG_NO_ERROR) && (receivedCmd == cmd))
				{
					//
					// Initialize stream buffer to read parameters
					//
					sbgStreamBufferInitForRead(&inputStream, receivedBuffer, receivedSize);

					//
					// Read parameters
					//
					pFeatures->sensorFeaturesMask	=  sbgStreamBufferReadUint32LE(&inputStream);
					pFeatures->gnssType				= (SbgEComGnssType)sbgStreamBufferReadUint8LE(&inputStream);
					pFeatures->gnssUpdateRate		= sbgStreamBufferReadUint8LE(&inputStream);
					pFeatures->gnssSignalsMask		= sbgStreamBufferReadUint32LE(&inputStream);
					pFeatures->gnssFeaturesMask		= sbgStreamBufferReadUint32LE(&inputStream);
					sbgStreamBufferReadBuffer(&inputStream, pFeatures->gnssProductCode, 32*sizeof(char));
					sbgStreamBufferReadBuffer(&inputStream, pFeatures->gnssSerialNumber, 32*sizeof(char));

					//
					// The command has been executed successfully so return
					//
					break;
				}
			}
			else
			{
				//
				// We have a write error so exit the try loop
				//
				break;
			}
		}
	}
	else
	{
		//
		// Null pointer
		//
		errorCode = SBG_NULL_POINTER;
	}

	return errorCode;
}