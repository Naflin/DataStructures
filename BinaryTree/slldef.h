sll::sll()
{
	qty = 0;
	first = curr = 0;
	max = 2000;
}

sll::sll(int m)
{
	qty = 0;
	first = curr = 0;
	if(m < 1)
		max = 2000;
	else
		max = m;
}

bool sll::addItem(int d)
{
	if(isFull())
		return false;
	
	llnode *temp = new llnode;
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
		for(llnode *scan = first; scan != NULL; scan = scan->next)
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
		
	llnode *scan = first;
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
			llnode *temp = scan->next;
			scan->next = temp->next;
			delete temp;
			qty--;
			return true;
		}
	}
	return false;
}

bool sll::findItem(int num)
{
	bool found = false;
	int val = 0;
	for(int i = 0; i < qty; i++)
	{
		val = getNext()->data;
		if(val == num)
			found = true;
	}
	return found;
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
	for(llnode *temp = first; temp != 0; temp = first)
	{
		first = first->next;
		delete temp;
	}
	qty = 0;
	return true;
}

llnode * sll::getNext()
{
	llnode * temp = curr;
	
	if(curr == 0)
		temp = curr = first;
	
	curr = curr->next;
	return temp;
}

sll::~sll()
{
	makeEmpty();
}
