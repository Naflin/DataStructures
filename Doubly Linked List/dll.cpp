#include <iostream>
#include <fstream>
using namespace std;

typedef struct data
{
	int number;
};

struct node
{
	node *prev;
	data d;
	int key;
	node *next;
};

class dll
{
 	private:
 		int qty;
 		int max;
 		node *curr;
 		
 	public:
 		dll();
 		dll(int);
 		
 	bool add(data, int);
 	bool deleteItem(int);
 	bool view(data&, int&);
 	bool getNext(data &d, int &k);
 	bool isFull();
 	bool isEmpty();
 	int getQty();
 	bool makeEmpty();
 	~dll();
};

dll::dll()
{
	qty = 0;
	max = 100000;
}

dll::dll(int m)
{
	qty = 0;
	if(m < 1)
		max = 100;
	else
		max = m;
}

dll::~dll()
{
	makeEmpty();
}

bool dll::add(data d, int k)
{
	node *temp;
	if(isFull())
		return false;
	
	if(isEmpty())
	{
		curr = new node;
		curr->d = d;
		curr->key = k;
		qty = 1;
		curr->prev = curr->next = 0;
		return true;
	}
	
	if(k <= curr->key)
	{
		for(; true; curr=curr->prev)
		{
			if(k == curr->key)
				return false;
			if((curr->prev == 0) || (curr->prev->key < k))
			{
				temp = new node;
				temp->d = d;
				temp->key = k;
				temp->next = curr;
				temp->prev = curr->prev;
				curr->prev = temp;
				if(temp->prev != 0)
					temp->prev->next = temp;
				qty++;
				return true;
			}
		}
	}
	else
	{
		for(; true; curr=curr->next)
		{
			if(k == curr->key)
			{
				return false;
			}
			if((curr->next == 0) || (curr->next->key > k))
			{
				temp = new node;
				temp->key = k;
				temp->prev = curr;
				temp->next = curr->next;
				curr->next = temp;
				if(temp->next != 0)
					temp->next->prev = temp;
				qty++;
				return true;
			}
		}
	}
}

bool dll::view(data &d, int &k)
{
	if(isEmpty())
		return false;
	
	if(k <= curr->key)	
	{
		for(; true; curr=curr->prev)
		{
			if(curr->key == k)
			{
				d = curr->d;
				return true;
			}
			if(curr->prev == 0)
				return false;
		}
	}
	else
	{
		for(; true; curr=curr->next)
		{
			if(curr->key == k)
			{
				d = curr->d;
				return true;
			}
			if(curr->next == 0)
				return false;
		}
	}
}

bool dll::deleteItem(int k)
{
	if(isEmpty())
		return false;
	
	data d;
	if(!view(d,k))
		return false;
	node *temp = curr;
	if(curr->next == 0)
	{
		curr = curr->prev;
		curr->next = 0;
	}
	else
	{
		curr = curr->next;
		curr->prev = temp->prev;
		if(temp->prev != 0)
			temp->prev->next = curr;
	}
	qty--;
	delete temp;
	return true;
}

bool dll::isFull()
{
	if(qty == max)
		return true;
	return false;
}

bool dll::isEmpty()
{
	if(qty == 0)
		return true;
	return false;	
}

bool dll::makeEmpty()
{
	if(isEmpty())
		return true;
	
	for(;curr->prev != 0; curr = curr->prev);
	for(node *temp = curr; curr != 0; temp = curr)
	{
		curr = curr->next;
		delete temp;
	}
	
	qty = 0;
	return true;
}

int dll::getQty()
{
	return qty;
}

bool dll::getNext(data &d, int &k)
{
	if(isEmpty())
		return false;
	
	return true;
}

//node * sll::getNext()
//{
//	static node *curr = first;
//	node * temp = curr;
//	
//	if(curr == NULL)
//	{
//		temp = curr = first;
//		return temp;
//	}
//	
//	curr = curr->next;
//	return temp;
//}
const int SIZE = 256;

int main()
{
	dll list;
	int choice;
	data t;
	int k = 10;
	data d;
	d.number = 50;
	char line[SIZE];
	char character;
	
	fstream file("inventory.txt");
	
	while()
	{
		
	}
		
	do {
		cout << "============ Database ============\n"
			 << "(1) Add new record\n"
			 << "(2) Delete record (by part-record number)\n"
			 << "(3) Modify record\n"
			 << "(4) List all records by inventory number\n"
			 << "(5) List all records by COST\n"
			 << "(6) Quit and SAVE (save your list back to the file)\n"
			 << "Choice: ";
		
		cin >> choice;
			
		switch(choice)
		{
			case 1 : cout << "1\n";
					 break;
			case 2 : cout << "2\n";
					 break;
			case 3 : cout << "3\n";
				 	 break;
			case 4 : cout << "4\n";
					 break;
			case 5 : cout << "5\n";
				 	 break;
			default : cout << "Default\n";
					 break;
		}	
		
	} while(choice != 6);
	
//	list.add(d, 10);
//	if(list.view(t,k))
//		cout << t.number << " " << k << endl;
//		
//	for(int i = 0; i < 10; i++)
//		list.add(d, i);
//	
//	cout << list.getQty() << endl;
//	
//	list.makeEmpty();
//	
//	cout << list.getQty();
	
	return 0;
}






