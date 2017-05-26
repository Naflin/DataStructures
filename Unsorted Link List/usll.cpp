#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};

class usll
{
	private:
		node *first, *last;
		int qty, max;
		
	public:
		usll();
		usll(int);
		bool addItem(int);
		bool deleteItem(int);
		bool isFull();
		bool isEmpty();
		bool makeEmpty();
		int getQty();
		node * getNext();
		~usll();
		
		void display();//only for testing
};

usll::usll()
{
	qty = 0;
	last = first = 0;
	max = 2000;
}

usll::usll(int m)
{
	qty = 0;
	last = first = 0;
	if(m < 1)
		max = 2000;
	else
		max = m;
}

bool usll::addItem(int d)
{
	if(isFull())
		return false;
	
	node *temp = new node;
	temp->next = 0;
	temp->data = d;
	
	if(isEmpty())
	{
		first = last = temp;
		qty++;
	}
	else
	{
		last->next = temp;
		last = temp;
		qty++;
	}
	return true;
}

bool usll::deleteItem(int d)
{
	if(isEmpty())
		return true;
		
	node *scan = first;
	if(scan->data == d)
	{
		first = first->next;
		delete scan;
		qty--;
		if(qty == 0)
			last = 0;
		return true;
	}
	
	for(; scan != last; scan = scan->next)
	{
		if(scan->next->data == d)
		{
			node *temp = scan->next;
			scan->next = temp->next;
			delete temp;
			qty--;
			if(temp == last)
				last = scan;
			return true;
		}
	}
	return false;
}

void usll::display()
{
	for(node *curr = first; curr != 0; curr = curr->next)
		cout << curr->data<<" ";
}

bool usll::isFull()
{
	if(qty == max)
		return true;
	return false;
}

bool usll::isEmpty()
{
	if(qty == 0)
		return true;
	return false;
}

int usll::getQty()
{
	return qty;
}

bool usll::makeEmpty()
{
	for(node *temp = first; temp != 0; temp = first)
	{
		first = first->next;
		delete temp;
	}
	last = 0;
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

usll::~usll()
{
	makeEmpty();
}

int main()
{
	usll list;

	cout << "Is Empty: " << list.isEmpty() << endl;
	list.addItem(5);
	cout << "Is Empty: " << list.isEmpty() << endl;
	list.addItem(5);
	list.addItem(1);
	list.addItem(12);
	list.addItem(551);
	list.display();
	list.makeEmpty();
	cout << "\nIs Empty: " << list.isEmpty() << endl;
	list.addItem(1);
	list.addItem(15);
	list.addItem(350);
	list.addItem(555);
	list.display();
	cout << "\n\n\n";
	list.deleteItem(15);
	list.display();
	list.deleteItem(350);
	list.addItem(82);
	cout << "\n\n";
	list.display();
	
	return 0;
}










