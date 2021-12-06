#pragma once
/**
  ******************************************************************************
  * @file    CheckSum_Manager.hpp
  * @author  H.Dastour
  * @brief   Header file of CheckSum_Manager class.
  ******************************************************************************
**/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef CheckSum_Manager_HPP
#define CheckSum_Manager_HPP

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Macros --------------------------------------------------------------------*/
/* Constants -----------------------------------------------------------------*/

/**
  * @brief  CheckSum Manager Class Version 1
  */
namespace CheckSum_Manager_Ver1
{
	/* Types ---------------------------------------------------------------------*/
	/* Class ---------------------------------------------------------------------*/
	class CheckSum_Manager
	{
	public:
		CheckSum_Manager(void);
		~CheckSum_Manager(void);

		void Calculate_Checksum(uint8_t* Packet, uint32_t Packet_Length, uint8_t Checksum_Length);
		bool Check_Checksum(uint8_t* Packet, uint32_t Packet_Length, uint8_t Checksum_Length);

	private:

	};
}

#endif /* CheckSum_Manager_HPP */
/*****************************END OF FILE*****************************/