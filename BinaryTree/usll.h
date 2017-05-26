class usll
{
	private:
		llnode *first, *last, *curr;
		int qty, max;
		
	public:
		usll();
		usll(int);
		bool addItem(int);
		bool deleteItem(int);
		bool findItem(int);
		bool isFull();
		bool isEmpty();
		bool makeEmpty();
		int getQty();
		llnode * getNext();
		~usll();
};
