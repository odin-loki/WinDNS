// IPConverter.cpp : This file contains the 'IPConverter' function implementation.
//

#include "IPConverter.h"

///Convert 32 bit ip4 number to string.
string ConvertIp4NumtoString(const uint32_t ip)
{
	const char dot = '.';
	const uint8_t mask = 0xff;
	return to_string((ip >> 24)& mask) + dot + to_string((ip >> 16)& mask) + dot + to_string((ip >> 8)& mask) + dot + to_string(ip & mask);
}

///Convert an ip4 string to 4 index array of 32 bit numbers.
array<uint32_t, 4> ConvertIp4Stringto4Numbers(const string ip)
{
	array<uint32_t, 4> tempArr;
	for (size_t i = 0, j = 0, last = 0; i < 4; i++)
	{
		while (ip[j] != '.')
		{
			++j;
		}
		tempArr[i] = stoul(ip.substr(last, j));
		last = j;
	}
	return tempArr;
}

///Convert ip4 string to 32 bit ip4 Number.
uint32_t ConvertI4pNumtoString(const string ip)
{
	array<uint32_t, 4> tempArr = ConvertIp4Stringto4Numbers(ip);
	return (tempArr[0] << 24) | (tempArr[1] << 16) | (tempArr[2] << 8) | tempArr[3];
}

///Convert a ipv6 string to 8 index of 16 bit numbers.
//array<uint16_t, 8> ConvertIp6Stringto8Numbers(const string ip)
//{
//	array<uint16_t, 8> tempArr;
//
//}

///Convert two nibles to a 8 bit Number.
//uint8_t ConvertTwoNibbles(string nibble)
//{
//
//}

///Convert four nibbles to a 16 bit Number.
//uint16_t ConvertFourNibbles(string nibble)
//{
//
//}
