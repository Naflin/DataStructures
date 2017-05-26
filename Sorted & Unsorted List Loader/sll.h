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
};



