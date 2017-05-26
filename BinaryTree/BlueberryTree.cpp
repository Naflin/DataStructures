/********************************************************************
	Program:	BlueberryTree.cpp
	Author: 	Nathan Blue
	Assignment: #6 Binary Trees
	Date: 		4/18/17
	Purpose:	Create a driver program that merges two txt files
				containing integers and keep track of errors
				using binary trees.
				
********************************************************************/
#include "bll.h"
#include "node.h"
#include "usll.h"
#include "uslldef.h"
#include "sll.h"
#include "slldef.h"

int main()
{
	usll list;
	usll errorList;
	sll sortedList;
	bll tree;
	ifstream inFile;
	ofstream outFile;
	int num;
	
	cout << "Merging data1.txt and data2.txt\n";
	
	inFile.open("data1.txt");
	if(inFile.is_open())
	{
		while(inFile >> num)
			list.addItem(num);
	}
	else
	{
		cout << "\ndata1.txt cannot open...\n";
	}
	inFile.close();
	
	inFile.open("data2.txt");
	if(inFile.is_open())
	{
		while(inFile >> num)
			list.addItem(num);
	}
	else
	{
		cout << "\ndata2.txt cannot open...\n";
	}
	inFile.close();
	
	for(int i = 0; i < list.getQty(); i++)
	{
		num = list.getNext()->data;
		if(!tree.addItem(num) || errorList.findItem(num))
		{
			errorList.addItem(num);	
			sortedList.addItem(num);
		}
	}
	
	for(int i = 0; i < errorList.getQty(); i++)
	{
		int n = errorList.getNext()->data;
		if(tree.findItem(n))
		{
			tree.deleteItem(n);
			errorList.addItem(n);
			sortedList.addItem(n);
		}
	}
	
	cout << "\n\nMerged: \n";
	tree.display(cout);
	
	outFile.open("merged.txt");
	tree.display(outFile);
	outFile.close();
	
	cout << "\n\nErrors: ";
	
	outFile.open("errors.txt");
	for(int i = 0; i < sortedList.getQty(); i++)
	{
		int n1 = sortedList.getNext()->data;
		for(int i = 0; i < errorList.getQty(); i++)
		{
			int n2 = errorList.getNext()->data;
			if(n1 == n2)
			{
				cout << n2 << " ";
				outFile << n2 << endl;	
			}
		}	
	}
	outFile.close();
	
	cout << "\n\nCheck merged.txt for final results\n"
		 << "Check errors.txt for conflicts\n";
	
	return 0;
}
