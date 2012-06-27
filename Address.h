#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
#include <string>


using namespace std;

// Address entry data structure
class Address{
private:
	string p_name;
	string p_mob_num;
	string p_addr;

public:
	//Address();
	//Address(Address &addr);
	Address(string name = "", string mob_num = "", string addr = "");

	void SetName(string name);
	void SetMobNum(string mob_num);
	void SetAddr(string addr);

	string GetName();
	string GetMobNum();
	string GetAddr();
	
	~Address();
};

// Linked Address data structure
class Address_Link{
private:
	Address addr;
	Address_Link *next;
public:
	Address_Link();
	Address_Link(Address &address);
	Address_Link(Address_Link &addr_link);
	Address_Link& operator=(Address_Link &addr_link);

	void SetAddr(Address address);
	void SetAddrLink(Address_Link *addr_link);
	Address GetAddr();
	Address_Link* GetAddrLink();

	~Address_Link();
};

#endif
