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
		return false;
		
	node *scan = first;
	if(scan->data == d)
	{
		first = first->next;
		delete scan;
		qty--;
		return true;
	}
	
	for(; scan->next != NULL; scan = scan->next)
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
		temp = curr = first;
		
	curr = curr->next;
	return temp;
}

sll::~sll()
{
	makeEmpty();
}
