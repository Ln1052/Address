#include "Address.h"

//Address::Address()
//{
//	p_name = "";
//	p_mob_num = "";
//	p_addr = "";
//}

//Address::Address(Address &addr)
//{
//	p_name = addr.GetName();
//	p_mob_num = addr.GetMobNum();
//	p_addr = addr.GetAddr();
//}

Address::Address(string name, string mob_num, string addr)
{
	p_name = name;
	p_mob_num = mob_num;
	p_addr = addr;
}

void Address::SetName(string name)
{
	p_name = name;
}

void Address::SetMobNum(string mob_num)
{
	p_mob_num = mob_num;
}

void Address::SetAddr(string addr)
{
	p_addr = addr;
}

string Address::GetName()
{
	return p_name;
}

string Address::GetMobNum()
{
	return p_mob_num;
}

string Address::GetAddr()
{
	return p_addr;
}

Address::~Address()
{
}


Address_Link::Address_Link()
{
	next = NULL;
}

Address_Link::Address_Link(Address &address)
{
	addr = address;
	next = NULL;
}

Address_Link::Address_Link(Address_Link &addr_link)
{
	addr = addr_link.GetAddr();
	if(addr_link.GetAddrLink() != NULL)
		next = new Address_Link(*addr_link.GetAddrLink());
	else
		next = NULL;
}

Address_Link& Address_Link::operator=(Address_Link &addr_link)
{
	addr = addr_link.GetAddr();
	if(addr_link.GetAddrLink() != NULL)
		next = new Address_Link(*addr_link.GetAddrLink());
	else
		next = NULL;
	return *this;
}

void Address_Link::SetAddr(Address address)
{
	addr = address;
}

void Address_Link::SetAddrLink(Address_Link *addr_link)
{
	if(next != NULL)
		delete next;
	if(addr_link != NULL)
		//next = new Address_Link(*addr_link);
		next = addr_link;
	else
		next = NULL;
}

Address Address_Link::GetAddr()
{
	return addr;
}

Address_Link* Address_Link::GetAddrLink()
{
	return next;
}

Address_Link::~Address_Link()
{
	if(next != NULL)
		delete next;
}
