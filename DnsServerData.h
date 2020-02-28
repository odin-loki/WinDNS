// DnsServerData.h : This file contains the 'DnsServerData' function prototypes and libs.
//

#pragma once

#include <string>
#include <vector>
#include <array>

using namespace std;

///IPV4 root DNS Namespace servers. https://www.iana.org/domains/root/servers
class RootDNS_ip4
{
public:
	RootDNS_ip4();
	~RootDNS_ip4();

	const array<string, 13> GetData(void);
private:
	array<string, 13> rootDNS_ip4;
};

///IPV6 root DNS Namespace servers. https://www.iana.org/domains/root/servers
class RootDNS_ip6
{
public:
	RootDNS_ip6();
	~RootDNS_ip6();

	const array<string, 13> GetData(void);
private:
	array<string, 13> rootDNS_ip6;
};

///IPV4 Public DNS Namespace servers. https://public-dns.info/nameservers-all.txt
class PublicDNS_ip4
{
public:
	PublicDNS_ip4();
	~PublicDNS_ip4();

	const array<string, 19606> GetData(void);
private:
	array<string, 19606> publicDNS_ip4;
};

///IPV6 Public DNS Namespace servers. https://public-dns.info/nameservers-all.txt
class PublicDNS_ip6
{
public:
	PublicDNS_ip6();
	~PublicDNS_ip6();

	const array<string, 186> GetData(void);
private:
	array<string, 186> publicDNS_ip6;
};
