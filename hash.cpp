#include <iostream>

using namespace std;

struct node
{
	string name = "";
	string phone = "";
	node* next = nullptr;
};

class HashHamed
{
	int size;
	node* Node;

public:
	HashHamed(const int length)
	{
		this->size = length;
		Node = new node[size];
	}

	void chainNode(const int index, const string name, const string phone)
	{
		node* temp1 = Node[index].next;		// points to next pointer of the node
		node* temp2 = &Node[index];			// points to the node
		while (temp1 != nullptr)			// while we are not at the end of the nodes			
		{
			temp2 = temp1;	
			temp1 = temp1->next;
		}
		// we are at the tail now
		temp1 = new node;					// create new node
		temp1->name = name;					// fill all fields
		temp1->phone = phone;
		temp1->next = nullptr;
		temp2->next = temp1;				// connect last node to the newly build node
	}

	void insert_data(string name, string phone)
	{
		int index = runHash(name);
		if (this->Node[index].name != "")
		{
			chainNode(index, name, phone);
		}
		else
		{
			this->Node[index].name = name;
			this->Node[index].phone = phone;
		}
	}

	// simple hash algorithm
	int runHash(const string name)
	{
		return (int)name.length();
	}

	void display_hash()
	{
		for (int i = 0; i < size; i++)
		{
			cout << i << ": ";
			cout << Node[i].name.c_str() << " " << Node[i].phone.c_str() << endl;
			while (Node[i].next != nullptr)
			{
				cout << "     " << Node[i].next->name.c_str() << " ";
				cout << Node[i].next->phone.c_str() << endl;
				Node[i].next = Node[i].next->next;
			}

		}
	}
};

int main(int argc, const char * argv[])
{

	HashHamed h1(10);
	h1.insert_data("Hamed", "503");
	h1.insert_data("Shayan", "347");
	h1.insert_data("Sarah", "830");
	h1.insert_data("Marga", "+63");
	h1.insert_data("abi", "+98913");
	h1.insert_data("Rami", "971");
	h1.insert_data("Mike", "5037844423");

	h1.display_hash();

}