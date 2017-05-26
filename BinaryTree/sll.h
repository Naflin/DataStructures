class sll
{
	private:
		llnode *first, *curr;
		int qty, max;
		
	public:
		sll();
		sll(int);
		bool addItem(int);
		bool deleteItem(int);
		bool findItem(int);
		bool isFull();
		bool isEmpty();
		bool makeEmpty();
		int getQty();
		llnode * getNext();
		~sll();
};



