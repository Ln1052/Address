#ifndef ADDRESS_MANAGER_H
#define ADDRESS_MANAGER_H

#include "Address.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Address Manager data structure
class Address_Manager{
private:
	int num;
	Address_Link *addr_link;

public:
	Address_Manager();
	Address_Manager(Address_Manager &addr_man);
	Address_Manager& operator=(Address_Manager &addr_man);

	int GetNum();
	Address_Link* GetAddressLink();
	void Add_Address(Address &addr);
	void Search_Address(int type, string &value, vector<Address> &addr_list);
	void Remove_Address(int type, int &count, string &value);

	void Clear();
	void Manipulate();

	~Address_Manager();

};

#endif