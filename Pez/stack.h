#include <climits>
using namespace std;

typedef struct data
{
	char flavor;
};
 
struct node
{
	int key;
 	data d;
 	node *next;
};
  
class Stack
{
	private:
 		int qty;
 		int max;
 		node *top;
 	public:
 		Stack();
 		Stack(int);
 		int getQty();
 		bool push(int, data);
 		bool pop(int &, data &);
 		bool peek(int &, data &);
 		bool makeEmpty();
 		bool isFull();
 		bool isEmpty();
 		~Stack();
};
 
Stack::Stack()
{
	qty = 0;
 	max = INT_MAX;
 	top = 0;
}
 
Stack::Stack(int m)
{
 	qty = 0;
 	if(m < 1)
 		max = 17;
 	else
 		max = m;
}

int Stack::getQty()
{
	return qty;
} 

bool Stack::isFull()
{
 	if(qty == max)
 		return true;
 	return false;
}
 
bool Stack::isEmpty()
{
	if(top == 0)
		return true;
	return false;
}

bool Stack::push(int k, data _d)
{
	if(isFull())
		return false;
	
	node *temp = new node;
	temp->key = k;
	temp->d = _d;
	temp->next = top;
	top = temp;
	qty++;
	return true;
}

bool Stack::pop(int &k, data &_d)
{
	if(isEmpty())
		return false;
	
	node *temp = top;
	k = top->key;
	_d = top->d;
	top = top->next;
	delete temp;
	qty--;
	return true;
}

bool Stack::peek(int & k, data & _d)
{
	if(isEmpty())
		return false;
	
	k = top->key;
	_d = top->d;
	return true;
}

bool Stack::makeEmpty()
{
	for(node *temp = top; temp != 0; temp = top)
	{
		top = temp->next;
		delete temp;
	}
	
	qty = 0;
	return true;
}

Stack::~Stack()
{
	makeEmpty();
}

//int main()
//{
//	Stack s;
//	data d;
//	data test;
//	int number;
//	
//	d.pages = 99;
//	s.push(15, d);
//	
//	d.pages = 35;
//	s.push(39, d);
//	
//	d.pages = 1852;
//	s.push(2000, d);
//	s.peek(number, test);
//	cout << number << " | " << test.pages << endl;
//	
//	s.pop(number, test);
//	
//	cout << number << " | " << test.pages << endl;
//	
//	s.pop(number, test);
//	cout << number << " | " << test.pages << endl;
//	
//	s.pop(number, test);
//	cout << number << " | " << test.pages << endl;
//	
//	int q = s.getQty();
//	cout << q << endl;
//	
//	return 0;
//}















