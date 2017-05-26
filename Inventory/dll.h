/********************************************************************
	Program:	dll.h
	Author: 	Nathan Blue
	Assignment: Inventory Program
	Date: 		3/22/17
	Purpose:	The doubley link list class
									
********************************************************************/

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
		curr->prev = curr->next = NULL;
		return true;
	}
	
	if(k <= curr->key)
	{
		for(; true; curr=curr->prev)
		{
			if(k == curr->key)
				return false;
			if((curr->prev == NULL) || (curr->prev->key < k))
			{
				temp = new node;
				temp->d = d;
				temp->key = k;
				temp->next = curr;
				temp->prev = curr->prev;
				curr->prev = temp;
				if(temp->prev != NULL)
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
				return false;
			if((curr->next == NULL) || (curr->next->key > k))
			{
				temp = new node;
				temp->d = d;
				temp->key = k;
				temp->prev = curr;
				temp->next = curr->next;
				curr->next = temp;
				if(temp->next != NULL)
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
			if(curr->prev == NULL)
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
			if(curr->next == NULL)
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
		if(curr->prev != 0)
			curr = curr->prev;
		else
			curr->prev = 0;
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
	static int poss = 1;
	if(isEmpty())
		return false;
		
	if(poss > qty)
	{
		poss = 1;
		return false;
	}
	
	if((poss == 1) && (curr->prev != 0))
		for(;curr->prev != 0; curr = curr->prev);
	
	k=curr->key;
	d=curr->d;
	if(curr->next != NULL)
		curr=curr->next;
	poss++;
	
	return true;
}
