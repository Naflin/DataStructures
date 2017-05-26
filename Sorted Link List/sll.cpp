#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};

class sll
{
	private:
		node *first;
		int qty, max;
		
	public:
		sll();
		sll(int);
		bool addItem(int);
		bool deleteItem(int);
		bool isFull();
		bool isEmpty();
		bool makeEmpty();
		int getQty();
		node * getNext();
		~sll();
		
		void display();//only for testing
};

sll::sll()
{
	qty = 0;
	first = 0;
	max = 2000;
}

sll::sll(int m)
{
	qty = 0;
	first = 0;
	if(m < 1)
		max = 2000;
	else
		max = m;
}

bool sll::addItem(int d)
{
	if(isFull())
		return false;
	
	node *temp = new node;
	temp->data = d;
	
	if(isEmpty() || first->data > d)
	{
		temp->next = first;
		first = temp;
		qty++;
		return true;
	}
	else
	{
		for(node *scan = first; scan != NULL; scan = scan->next)
		{
			if(scan->data == d)
				return false;
			if(scan -> next == NULL || scan->next->data > d)
			{
				temp->next = scan->next;
				scan->next = temp;
				qty++;
				return true;
			}
		}
	}
	
	return false;
}

bool sll::deleteItem(int d)
{
	if(isEmpty())
		return true;
		
	node *scan = first;
	if(scan->data == d)
	{
		first = first->next;
		delete scan;
		qty--;
		return true;
	}
	
	for(; scan != NULL; scan = scan->next)
	{
		if(scan->next->data == d)
		{
			node *temp = scan->next;
			scan->next = temp->next;
			delete temp;
			qty--;
			return true;
		}
	}
	return false;
}

void sll::display()
{
	for(node *curr = first; curr != 0; curr = curr->next)
		cout << curr->data<<" ";
}

bool sll::isFull()
{
	if(qty == max)
		return true;
	return false;
}

bool sll::isEmpty()
{
	if(qty == 0)
		return true;
	return false;
}

int sll::getQty()
{
	return qty;
}

bool sll::makeEmpty()
{
	for(node *temp = first; temp != 0; temp = first)
	{
		first = first->next;
		delete temp;
	}
	qty = 0;
	return true;
}

node * sll::getNext()
{
	static node *curr = first;
	node * temp = curr;
	
	if(curr == NULL)
	{
		temp = curr = first;
		return temp;
	}
	
	curr = curr->next;
	return temp;
}

sll::~sll()
{
	makeEmpty();
}

int main()
{
	sll list;
	int item = 0;
	
	for(int i = 0; i < 3; i++)
	{
		cout << "\n\nEnter number: ";
		cin >> item;
		
		list.addItem(item);
		list.display();
	}
	
	

//	cout << "Is Empty: " << list.isEmpty() << endl;
//	list.addItem(5);
//	cout << "Is Empty: " << list.isEmpty() << endl;
//	list.addItem(5);
//	list.addItem(1);
//	list.addItem(12);
//	list.addItem(551);
//	list.display();
//	list.makeEmpty();
//	cout << "\nIs Empty: " << list.isEmpty() << endl;
//	list.addItem(1);
//	list.addItem(15);
//	list.addItem(350);
//	list.addItem(555);
//	list.display();
//	cout << "\n\n\n";
//	list.deleteItem(15);
//	list.display();
//	list.deleteItem(350);
//	list.addItem(82);
//	cout << "\n\n";
//	list.display();
	
	return 0;
}










