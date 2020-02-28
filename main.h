// main.h : This file contains the 'main' function prototypes and libs.
//

//Pragmas
#pragma once
#pragma comment(lib, "Ws2_32.lib")


//Macros
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#define _WINSOCK_DEPRECATED_NO_WARNINGS

//Streams
#include <iostream>

//Types
#include <vector>
#include <string>
#include <cstdarg>

//OS Libs
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <ws2ipdef.h>
#include <Mstcpip.h>

//Parralell Libs
#include <ppl.h>

//Function Protoypes

///Initialise Winsock.
WSADATA InitWinsock();

///Initialise a Socket with Error Check.
SOCKET InitSocket(uint32_t af, uint32_t type, uint32_t protocol);

///Port Family, Port, IP Address, Zero
sockaddr_in InitIP4_SockAddress(uint32_t port, uint32_t address);

///Port Family, Port, FlowInfo, IP Address, Scope.
sockaddr_in6 InitIP6_SockAddress(uint32_t port, uint32_t address);

///Generate Complete IPV4 Range from 32 bit Number.
//vector<string> GenCompleteIp4Range(void);

