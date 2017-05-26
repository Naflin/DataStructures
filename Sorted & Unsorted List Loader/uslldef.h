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
		return false;
		
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

node * usll::getNext()
{
	static node *curr = first;
	node * temp = curr;
	
	if(curr == NULL)
		temp = curr = first;
	
	curr = curr->next;
	return temp;
}

usll::~usll()
{
	makeEmpty();
}
