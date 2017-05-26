#include <iostream>
#include <fstream>
using namespace std;

struct node
{
	node *left;
	node *right;
	int num;
};

class bll
{
	private:
		node *tt;
		int qty;
		int max;
		bool p_add(node *, int);
		void p_display(ostream &, node *);
		void p_empty(node *);
		bool p_find(node *, int);
		bool p_delete(node *, int);
	public:
		bll();
		bll(int);
		bool isFull();
		bool isEmpty();
		bool addItem(int);
		bool deleteItem(int);
		bool findItem(int);
		int getQty();
		bool makeEmpty();
		void display(ostream &);
		~bll();
};

bll::bll()
{
	max = 10000;
	qty = 0;
}

bll::bll(int m)
{
	if(m <= 10000 && m > 0)
		max = m;
	else
		max = 10000;
	qty = 0;
}

bll::~bll()
{
	makeEmpty();
}

bool bll::isFull()
{
	if(qty >= max)
		return true;
	return false;
}

bool bll::isEmpty()
{
	if(qty == 0)
		return true;
	return false;
}

bool bll::addItem(int val)
{
	if(isFull())
		return false;
	if(isEmpty())
	{
		tt = new node;
		tt->left = tt->right = NULL;
		tt->num = val;
		qty = 1;
		return true;
	}	
	return p_add(tt, val);
}


bool bll::p_add(node *curr, int val)
{
	if(curr->num == val)
		return false;
	if(val < curr->num)
	{
		if(curr->left != NULL)
			return p_add(curr->left, val);
		else
		{
			curr->left = new node;
			curr->left->left = curr->left->right = NULL;
			curr->left->num = val;
			qty++;
			return true;
		}
	}
	if(curr->right != NULL)
		return p_add(curr->right, val);
	else
	{
		curr->right = new node;
		curr->right->left = curr->right->right = NULL;
		curr->right->num = val;
		qty++;
		return true;
	}
}

void bll::display(ostream &out)
{
	if(tt != NULL)
		p_display(out,tt);
}

void bll::p_display(ostream &out, node *curr)
{
	if(curr->left != NULL)
		p_display(out, curr->left);
	
	out << curr->num << "\n";
	
	if(curr->right != NULL)
		p_display(out, curr->right);
}

bool bll::makeEmpty()
{
	if(isEmpty())
		return false;
	if(tt != NULL)
		p_empty(tt);
	qty = 0;
	tt = NULL;
	return true;
}

void bll::p_empty(node *curr)
{
	if(curr->left != NULL)
		p_empty(curr->left);
	if(curr->right != NULL)
		p_empty(curr->right);
	delete curr;
}

bool bll::findItem(int val)
{
	if(tt != NULL)
		return p_find(tt, val);
	return false;
}

bool bll::p_find(node * curr, int val)
{
	if(curr->num == val)
		return true;
	if(val < curr->num && curr->left != NULL)
		return p_find(curr->left, val);
	if(curr->num < val && curr->right != NULL)
		return p_find(curr->right, val);
	return false;
}

bool bll::deleteItem(int num)
{
	if(isEmpty())
		return false;
	if(tt->num == num)
	{
		node *curr;
		node *temp = tt;
		if(tt->left != NULL)
		{
			tt = tt->left;
			for(curr = tt; curr->right != NULL; curr = curr->right);
				curr->right = temp->right;
		}
		else
		{
			tt = tt->right;
		}
		
		delete temp;
		qty--;
		return true;
	}
	return p_delete(tt, num);
}

bool bll::p_delete(node *curr, int num)
{
	node *temp, *scan;
	if(num < curr->num)
	{
		if(curr->left == NULL)
			return false;
		if(curr->left->num == num)
		{
			temp = curr->left;
			if(temp->right != NULL)
			{
				curr->left = temp->right;
				for(scan = curr->left; scan->left != NULL; scan = scan->left);
					scan->left = temp->left;
			}
			else
			{
				curr->left = temp->left;
			}
			delete temp;
			qty--;
			return true;
		}
		return p_delete(curr->left, num);
	}
	else
	{
		if(curr->right == NULL)
			return false;
		if(curr->right->num == num)
		{
			temp = curr->right;
			if(temp->left != NULL)
			{
				curr->right = temp->left;
				for(scan = curr->right; scan->right != NULL; scan = scan->right);
				scan->right = temp->right;
			}
			else
				curr->right = temp->right;
			delete temp;
			qty--;
			return true;
		}
		return p_delete(curr->right, num);
	}
	cout << "\n\nyou screwed up\n\n";
}





