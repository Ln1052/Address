#include "Address_Manager.h"

//constructor 
Address_Manager::Address_Manager()
{
	num = 0;
	addr_link = NULL;

	////Load the file address.txt
	//fstream file("address.txt", ios::in);// Open the file

	//while(1)
	//{
	//	if(file)
	//	{
	//		Address_Link *temp_addr = new Address_Link();
	//		Address addr;
	//		file.read((char*)&addr, sizeof(addr));
	//		temp_addr->SetAddr(addr);
	//		//temp_addr->SetAddrLink(NULL);
	//		
	//		if(addr_link == NULL)
	//		{
	//			addr_link = temp_addr;
	//			num ++;
	//		}
	//		else
	//		{
	//			Address_Link *addr_index = addr_link;
	//			//get the latest "address"
	//			while(addr_index->GetAddrLink() != NULL)
	//				addr_index = addr_index->GetAddrLink();

	//			addr_index->SetAddrLink(temp_addr);
	//			num ++;
	//		}
	//	}
	//	else 
	//		break;
	//}

	//file.close(); // Close the file
}

//copy constructor
Address_Manager::Address_Manager(Address_Manager &addr_man)
{
	num = addr_man.GetNum();
	if(addr_man.GetAddressLink() != NULL)
	{
		Address_Link *temp_addr = addr_man.GetAddressLink();
		Address_Link *temp_addr_index = addr_link;

		while(temp_addr != NULL)
		{
			Address_Link *temp_addr_new = new Address_Link();
			temp_addr_new->SetAddr(temp_addr->GetAddr());
			temp_addr_new->SetAddrLink(NULL);
			
			//temp_addr_new point to the last member
			if(addr_link == NULL)
				temp_addr_index = addr_link = temp_addr_new;
			else
			{
				temp_addr_index->SetAddrLink(temp_addr_new);
				temp_addr_index = temp_addr_index->GetAddrLink();
			}

			temp_addr = temp_addr->GetAddrLink();
		}
	}
}

Address_Manager& Address_Manager::operator=(Address_Manager &addr_man)
{
	num = addr_man.GetNum();
	if(addr_link != NULL)
	{
		delete addr_link;
		addr_link = NULL;
	}

	if(addr_man.GetAddressLink() != NULL)
	{
		Address_Link *temp_addr = addr_man.GetAddressLink();
		Address_Link *temp_addr_index = addr_link;

		while(temp_addr != NULL)
		{
			Address_Link *temp_addr_new = new Address_Link();
			temp_addr_new->SetAddr(temp_addr->GetAddr());
			temp_addr_new->SetAddrLink(NULL);
			
			//temp_addr_new point to the last member
			if(addr_link == NULL)
				temp_addr_index = addr_link = temp_addr_new;
			else
			{
				temp_addr_index->SetAddrLink(temp_addr_new);
				temp_addr_index = temp_addr_index->GetAddrLink();
			}

			temp_addr = temp_addr->GetAddrLink();
		}
	}

	return *this;
}

int Address_Manager::GetNum()
{
	return num;
}

Address_Link* Address_Manager::GetAddressLink()
{
	return addr_link;
}

void Address_Manager::Add_Address(Address &addr)
{
	Address_Link *temp_addr = new Address_Link();
	temp_addr->SetAddr(addr);

	Address_Link *addr_index = addr_link;
	
	if(addr_link == NULL)
	{
		addr_link = temp_addr;
		return;
	}
	 //get the point of the last member
	while(addr_index->GetAddrLink() != NULL)
	{
		addr_index = addr_index->GetAddrLink();
	}

	addr_index->SetAddrLink(temp_addr);
}

//search by name(type==1), mobile number(type==2), home address(type==3)
void Address_Manager::Search_Address(int type, string &value, vector<Address> &addr_list)
{
	//addr_list.clear();

	if(num == 0)
		return;

	Address_Link *addr_index = addr_link;

	for(; addr_index != NULL; addr_index = addr_index->GetAddrLink())
	{
		Address temp_addr = addr_index->GetAddr();

		switch(type)
		{
			case 1:
				if(value == temp_addr.GetName())
					addr_list.push_back(temp_addr);
				break;
			case 2:
				if(value == temp_addr.GetMobNum())
					addr_list.push_back(temp_addr);
				break;
			case 3:
				if(value == temp_addr.GetAddr())
					addr_list.push_back(temp_addr);
				break;
			default:
				break;
		}
	}
}

void Address_Manager::Remove_Address(int type, int &count, string &value)
{
	count = 0;

	if(num == 0)
	{
		std::cout << "No member of Address" << std::endl;
		return;
	}

	Address_Link *temp_addr = addr_link;
	Address_Link *temp_addr_next = temp_addr->GetAddrLink();

	// Do not consider the head member
	while(temp_addr_next != NULL)
	{
		switch(type)
		{
			case 1:
				if(value == temp_addr_next->GetAddr().GetName())
				{
					temp_addr->SetAddrLink(temp_addr_next->GetAddrLink());
					delete temp_addr_next;
					temp_addr_next = temp_addr->GetAddrLink();
					count ++;
				}
				else
				{
					temp_addr = temp_addr->GetAddrLink();
					temp_addr_next = temp_addr_next->GetAddrLink();
				}
				break;
			case 2:
				if(value == temp_addr_next->GetAddr().GetMobNum())
				{
					temp_addr->SetAddrLink(temp_addr_next->GetAddrLink());
					delete temp_addr_next;
					temp_addr_next = temp_addr->GetAddrLink();
					count ++;
				}
				else
				{
					temp_addr = temp_addr->GetAddrLink();
					temp_addr_next = temp_addr_next->GetAddrLink();
				}
				break;
			case 3:
				if(value == temp_addr_next->GetAddr().GetAddr())
				{
					temp_addr->SetAddrLink(temp_addr_next->GetAddrLink());
					delete temp_addr_next;
					temp_addr_next = temp_addr->GetAddrLink();
					count ++;
				}
				else
				{
					temp_addr = temp_addr->GetAddrLink();
					temp_addr_next = temp_addr_next->GetAddrLink();
				}
			default:
				break;
		}
	}

	// consider the head member
	switch(type)
	{
	case 1:
		if(value == addr_link->GetAddr().GetName())
		{
			Address_Link *addr_link_head = addr_link;
			addr_link = addr_link->GetAddrLink();
			addr_link_head->SetAddrLink(NULL);
			delete addr_link_head;
			count ++;
		}
		break;
	case 2:
		if(value == addr_link->GetAddr().GetMobNum())
		{
			Address_Link *addr_link_head = addr_link;
			addr_link = addr_link->GetAddrLink();
			addr_link_head->SetAddrLink(NULL);
			delete addr_link_head;
			count ++;
		}
	case 3:
		if(value == addr_link->GetAddr().GetAddr())
		{
			Address_Link *addr_link_head = addr_link;
			addr_link = addr_link->GetAddrLink();
			addr_link_head->SetAddrLink(NULL);
			delete addr_link_head;
			count ++;
		}
	default:
		break;
	}
}

void Address_Manager::Clear()
{
	num = 0;
	if(addr_link != NULL)
		delete addr_link;
	addr_link = NULL;
}

void Address_Manager::Manipulate()
{
	string command;
	
	string name;
	string mobile;
	string addr;

	Address temp_addr;

	cout << "Please input the command: " << endl;
	while (cin >> command && command != "!quit")
	{
		cout << endl;
		if(command == "add" || command == "ADD")
		{
			cout << "name: ";
			cin >> name;
			cout << endl << "mobile: ";
			cin >> mobile;
			cout << endl << "address: ";
			cin >> addr;

			temp_addr.SetName(name);
			temp_addr.SetMobNum(mobile);
			temp_addr.SetAddr(addr);

			Add_Address(temp_addr);
			cout << "address entry added" << endl;

			continue;
		}

		else if(command == "search" || command == "SEARCH")
			{
				vector<Address> temp_addr_list;
				string type;

				cout << "by(name|mobile|address): " ;
				cin >> type;
				if(type == "name")
				{
					cout << endl << "name: " ;
					cin >> name;
					Search_Address(1, name, temp_addr_list);
				}
				else if(type == "mobile")
				{
					cout << endl << "mobile: ";
					cin >> mobile;
					Search_Address(2, mobile, temp_addr_list);
				}
				else if(type == "address")
				{
					cout << endl << "address: ";
					cin >> addr;
					Search_Address(3, addr, temp_addr_list);
				}

				for(unsigned i= 0; i< temp_addr_list.size(); i++)
				{
					cout << endl;
					cout << "search result " << i+1 << " :" << endl;
					cout << "name: " << temp_addr_list[i].GetName() << endl;
					cout << "mobile: " << temp_addr_list[i].GetMobNum() << endl;
					cout << "address: " << temp_addr_list[i].GetAddr() << endl;
				}

				continue;
			}
		else if(command == "delete" || command == "DELETE")
		{
			int count = 0;
			string type;

			cout << "by(name|mobile|address): " ;
			cin >> type;

			if(type == "name")
			{
				cout << endl << "name: ";
				cin >> name;
				Remove_Address(1, count, name);
			}
			else if(type == "mobile")
			{
				cout << endl << "mobile: ";
				cin >> mobile;
				Remove_Address(2, count, mobile);
			}
			else if(type == "address")
			{
				cout << endl << "address: ";
				cin >> addr;
				Remove_Address(3, count, addr);
			}
			cout << count << " address entries deleted" << endl;

			continue;
		}
		//help command or invalid command, display the help message
		else
		{
			cout << "Help message: " << endl;
			cout << "You could use these commands(add, search, remove, !help) \
					to manipulate the address message" << endl;
			cout << "and the command !quit to exit" << endl;
		}
	}
}

//destructor, write the message of address into the file
Address_Manager::~Address_Manager()
{
	Address_Link *addr_index = addr_link;

	fstream file("address.txt", ios::out|ios::trunc);
	if(!file)
		cout << "Open the file address.txt wrongly when try to write message" << endl;
	
	while(addr_index != NULL)
	{
		file.write((char*)&(addr_index->GetAddr()), sizeof(Address));
		addr_index = addr_index->GetAddrLink();
	}
	
	file.close();
        
        addr_index = NULL;
	if(addr_link != NULL)
		delete addr_link;
}
