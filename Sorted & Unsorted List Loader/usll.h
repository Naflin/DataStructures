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
};
