# CheckSum_Manager
- This is a C++ Class that can be used for calculating and checking a checksum value of a data packet.
- It can be used for checking the data errors that were be sent or saved or something else.
- I hope to be used in your projects. I will be happy to develop it or maybe add some useful features. finally, We will have a complete class.

- Its functions are as follows:
1. void Calculate_Checksum(uint8_t* Packet, uint32_t Packet_Length, uint8_t Checksum_Length)
2. bool Check_Checksum(uint8_t* Packet, uint32_t Packet_Length, uint8_t Checksum_Length)

- Input Parameters:
1. Packet: It is a pointer of a packet.
2. Packet_Length: It is the length of packet according to Byte. Be careful, you should enter the total length. (Data + Checksum_Length)
3. Checksum_Length: It is the length of checksum according to Byte. It can be 1, 2, 3 and 4.

- In fact, You can add this class to your project and just call the Calculate_Checksum function. It will calculate checksum values and put them at the end of the packet and you don't need to do anythings else.
