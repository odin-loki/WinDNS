// DnsScan.cpp : This file contains the 'DnsScan' function implementations.
//

#include "DnsScan.h"
#include "IPConverter.h"

using namespace std;

//Make DNS Error object and better Errors.
void TestDNS()
{
	string temp = "166.62.30.151";
	PDNS_RECORD record = NULL;

	record = (PDNS_RECORD)LocalAlloc(LPTR, sizeof(PDNS_RECORD));

	DNS_STATUS status = DnsQuery_A(PCSTR(temp.c_str()), DNS_TYPE_A, DNS_QUERY_STANDARD, NULL, &record, NULL);
	cout << "DNS Record name is " << record->pName << endl;
}

PDNS_RECORD DNSResolveQuery(string name)
{
	PDNS_RECORD record;
	//status = DnsQueryConfig();

	DNS_STATUS status = DnsQuery_W(PCWSTR(name.c_str()), DNS_TYPE_ALL, DNS_QUERY_STANDARD, NULL, &record, NULL);
	
	if (status != DNS_RCODE_NOERROR)
	{	//Consider Assertions? Sick of the program not continuing after a null value.
		throw exception("DNS Query not found.");
	}
	return record;
}

uint64_t GetDNSRecordSize(PDNS_RECORD record)
{
	uint64_t size = 0;
	while (record != NULL)
	{
		size += sizeof(record);
		record = record->pNext;
	}
	return size;
}

//Not Resolving DNS name.

void ResolveGetSizeAndCompareToLargest(int32_t ipNum, PDNS_RECORD* largest, uint64_t* largestSize)
{
	string temp = ConvertIp4NumtoString(ipNum);
	PDNS_RECORD record = DNSResolveQuery(temp);
	uint64_t currentSize = GetDNSRecordSize(record);

	if (currentSize > * largestSize)
	{
		*largestSize = currentSize;
		*largest = record;
	}
	DnsFree(record, DNS_FREE_TYPE::DnsFreeFlat);
}

//Make Timer that writes value every 10 minutes.
//Make Synchronised Progress bar.
//Split into 8 Smaller Ranges and run in:

///Find Worlds Largest DNS Record.
PDNS_RECORD FindLargestDNSRecord(void)
{
	PDNS_RECORD largest = NULL;
	uint64_t largestSize = 0;

	//#pragma loop(hint_parallel(8))
//	for (size_t i = 0; i <= INT32_MAX; i++)
//	{
//		ResolveGetSizeAndCompareToLargest(i, largest, largestSize);
//		cout << '\r' << to_string(i / INT32_MAX * 100) << "% Done. " << ConvertIpNumtoString(i + 7) << " IP's parsed.";
//	}

	for (size_t i = 0; i <= INT32_MAX; i++)
	{
		ResolveGetSizeAndCompareToLargest(i, &largest, &largestSize);
		cout << '\r' << to_string(i / INT32_MAX * 100) << "% Done. " << ConvertIp4NumtoString(i) << " IP's parsed.";
	}

	//parallel_for(size_t(0), (size_t)INT32_MAX, [&](size_t i)
	//	{
	//		ResolveGetSizeAndCompareToLargest(i, &largest, &largestSize);
	//		//cout << '\r' << to_string(i / INT32_MAX * 100) << "% Done. " << ConvertIpNumtoString(i) << " IP's parsed.";
	//		cout << to_string(i / INT32_MAX * 100) << "% Done. " << ConvertIpNumtoString(i) << " IP's parsed." << endl;
	//	});


	return largest;
}

void FindLargestDNSRecordUI()
{
	cout << "Finding the Worlds Largest DNS Record:" << endl;
	PDNS_RECORD record = FindLargestDNSRecord();
	cout << "The worlds largest DNS Record was: " << record->pName << endl;
}
