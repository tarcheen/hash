
#include <iostream>

using namespace std;

struct node
{
    string name = "Blank";
    string phone = "Blank";
    node* next = nullptr;
};

class HashHamed
{
    int size;
    node* Node;
    
public:
    HashHamed(int length)
    {
        this->size = length;
        Node = new node[size];
    }
    
    void chainNode(int index, string name, string phone)
    {
        node* temp = this->Node[index].next;
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        // at this point we are at the tail of the chain
        temp->next = new node;
        temp->next->name = name;
        temp->next->phone = phone;
        temp->next->next = nullptr;
    }
    
    void insert_data(string name, string phone)
    {
        int index = runHash(name);
        if(this->Node[index].name != "Blank")
        {
            cout<<"Collision"<<endl;
            chainNode(index, name, phone);
        }
        else
            Node[index].name = name;
            Node[index].phone = phone;
    }
    
    int runHash(string name)
    {
        return (int)name.length();
    }
    
    void display_hash()
    {
        for(int i = 0; i < size; i++)
        {
            cout<<i<<": ";
            cout<<Node[i].name<<" "<<Node[i].phone<<endl;
            while (Node[i].next != nullptr)
            {
                cout<<"     "<<Node[i].next->name<< " ";
                cout<<Node[i].next->phone<<endl;
                Node[i].next = Node[i].next->next;
            }
            
        }
    }
};

int main(int argc, const char * argv[])
{
    cout<<"hello world"<<endl;
    
    HashHamed h1(10);
    h1.insert_data("Hamed", "503");
    h1.insert_data("Shaya", "347");
    h1.insert_data("Sarah", "830");
    h1.display_hash();
    
}
