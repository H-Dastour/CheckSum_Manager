/**
  ******************************************************************************
  * @file    CheckSum_Manager.cpp
  * @author  H.Dastour
  * @brief   CheckSum Manager class.
  *          This file provides firmware functions to manage checksum value of 
  *          an array data.
  ******************************************************************************
**/

/* Includes ------------------------------------------------------------------*/
#include "CheckSum_Manager.hpp"

/**
  * @brief  CheckSum Manager Class Version 1
  */
namespace CheckSum_Manager_Ver1
{
	/* Variables -----------------------------------------------------------------*/

	/* Functions Definitions -----------------------------------------------------*/
	/**
	  * @brief  Constructor function
	  * @param  None
	  * @retval None
	  */
	CheckSum_Manager::CheckSum_Manager(void)
	{
		//Empty
	}

	/**
	  * @brief  Destructor function
	  * @param  None
	  * @retval None
	  */
	CheckSum_Manager::~CheckSum_Manager(void)
	{
		//Empty
	}

	/**
	  * @brief  This function builds the checksum value according to the Packet and puts it on the end of packet itself.
	  * @param  Packet: Data packet in order to calculating its checksum.
	  *			Packet_Length: The length of packet according to Byte.
	  *			Checksum_Length: The checksum length according to Byte. It can be 1, 2, 3, or 4. It's more usual to choose 2 or 4.
	  * @retval None
	  */
	void CheckSum_Manager::Calculate_Checksum(uint8_t* Packet, uint32_t Packet_Length, uint8_t Checksum_Length)
	{
		uint32_t ByteCount = 0;	//Byte Counter
		uint32_t Checksum = 0;	//Save checksum value

		for(ByteCount = 0; ByteCount < (Packet_Length - Checksum_Length); ByteCount++)
		{
			Checksum += Packet[ByteCount];	//Calculate the sum value of all bytes exept checksum values at the end.
		}
		Checksum = ~Checksum;	//1's complement
		
		switch (Checksum_Length)	//Check the checksum length value as byte
		{
		case 1:	//Checksum length is 1 Byte
			Packet[Packet_Length - 1] = (uint8_t)(Checksum & 0x000000FF);	//Put checksum value on the end of packet
			break;

		case 2:	//Checksum length is 2 Byte
			Packet[Packet_Length - 2] = (uint8_t)((Checksum >> 8) & 0x000000FF);	//Put the first byte
			Packet[Packet_Length - 1] = (uint8_t)(Checksum & 0x000000FF);			//Put the second Byte
			break;

		case 3:	//Checksum length is 3 Byte
			Packet[Packet_Length - 3] = (uint8_t)((Checksum >> 16) & 0x000000FF);	//Put the first byte
			Packet[Packet_Length - 2] = (uint8_t)((Checksum >> 8) & 0x000000FF);	//Put the second Byte
			Packet[Packet_Length - 1] = (uint8_t)(Checksum & 0x000000FF);			//Put the third Byte
			break;

		case 4:	//Checksum length is 4 Byte
			Packet[Packet_Length - 4] = (uint8_t)((Checksum >> 32) & 0x000000FF);	//Put the first byte
			Packet[Packet_Length - 3] = (uint8_t)((Checksum >> 16) & 0x000000FF);	//Put the second Byte
			Packet[Packet_Length - 2] = (uint8_t)((Checksum >> 8) & 0x000000FF);	//Put the third Byte
			Packet[Packet_Length - 1] = (uint8_t)(Checksum & 0x000000FF);			//Put the fourth Byte
			break;	
		}
	}

	/**
	  * @brief  This function checks the checksum value of entered packet and return true or false.
	  * @param  Packet: Data packet in order to calculating its checksum.
	  *			Packet_Length: The length of packet according to Byte.
	  *			Checksum_Length: The checksum length according to Byte. It can be 1, 2, 3, or 4. It's more usual to choose 2 or 4.
	  * @retval checksum status
	  */
	bool CheckSum_Manager::Check_Checksum(uint8_t* Packet, uint32_t Packet_Length, uint8_t Checksum_Length)
	{
		uint32_t ByteCount = 0;	//Byte Counter
		uint32_t Checksum = 0;	//Save checksum value

		for (ByteCount = 0; ByteCount < (Packet_Length - Checksum_Length); ByteCount++)
		{
			Checksum += Packet[ByteCount];	//Calculate the sum value of all bytes exept checksum values at the end.
		}
		Checksum = ~Checksum;	//1's complement

		switch (Checksum_Length)	//Check the checksum length value as byte
		{
		case 1:	//Checksum length is 1 Byte
			if (Packet[Packet_Length - 1] == (uint8_t)(Checksum & 0x000000FF))	//Check checksum value on the end of packet
			{
				return true;	//Checksum value is valid
			}
			else
			{
				return false;	//Checksum value is not valid
			}
			break;

		case 2:	//Checksum length is 2 Byte
			if (Packet[Packet_Length - 2] == (uint8_t)((Checksum >> 8) & 0x000000FF))	//Check the first byte
			{
				if (Packet[Packet_Length - 1] == (uint8_t)(Checksum & 0x000000FF))		//Check the second Byte
				{
					return true;	//Checksum value is valid
				}
			}
			return false;	//Checksum value is not valid
			break;

		case 3:	//Checksum length is 3 Byte
			if (Packet[Packet_Length - 3] == (uint8_t)((Checksum >> 16) & 0x000000FF))		//Check the first byte
			{
				if (Packet[Packet_Length - 2] == (uint8_t)((Checksum >> 8) & 0x000000FF))	//Check the second Byte
				{
					if (Packet[Packet_Length - 1] == (uint8_t)(Checksum & 0x000000FF))		//Check the third Byte
					{
						return true;	//Checksum value is valid
					}
				}
			}
			return false;	//Checksum value is not valid
			break;

		case 4:	//Checksum length is 4 Byte
			if (Packet[Packet_Length - 4] == (uint8_t)((Checksum >> 32) & 0x000000FF))			//Check the first byte
			{
				if (Packet[Packet_Length - 3] == (uint8_t)((Checksum >> 16) & 0x000000FF))		//Check the first byte
				{
					if (Packet[Packet_Length - 2] == (uint8_t)((Checksum >> 8) & 0x000000FF))	//Check the second Byte
					{
						if (Packet[Packet_Length - 1] == (uint8_t)(Checksum & 0x000000FF))		//Check the third Byte
						{
							return true;	//Checksum value is valid
						}
					}
				}
			}
			return false;	//Checksum value is not valid
			break;

		default:
			return false;	//Checksum length is not valid
		}
	}
}
/*****************************END OF FILE*****************************/
