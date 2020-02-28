// IPConverter.h : This file contains the 'IPConverter' function prototypes and libs.
//

#pragma once

#include <string>
#include <array>
//#include <sstream>

using namespace std;

///Convert 32 bit ip4 number to string.
string ConvertIp4NumtoString(const uint32_t ip);

///Convert an ip4 string to 4 index array of 32 bit numbers.
array<uint32_t, 4> ConvertIp4Stringto4Numbers(const string ip);

///Convert ip4 string to 32 bit ip4 Number.
uint32_t ConvertI4pNumtoString(const string ip);

///Convert a ipv6 string to 8 index of 16 bit numbers.
array<uint16_t, 8> ConvertIp6Stringto8Numbers(const string ip);
