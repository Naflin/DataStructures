/********************************************************************
	Program:	BlueNathanLL.cpp
	Author: 	Nathan Blue
	Assignment: Program #2
	Date: 		2/16/17
	Purpose:	Create a driver to test the sorted and
				unsorted link lists				
********************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "node.h"
#include "sll.h"
#include "slldef.h"
#include "usll.h"
#include "uslldef.h"
using namespace std;

bool load(sll &, usll &, string);
void display(sll &, usll &);
void deleteItems(sll &, usll &, int);

int main()
{
	sll sortedList;
	usll unsortedList;
	string fileName = "";
	int choice = 0;
	int item = 5;
	
	do {
		cout << "\n===========[Menu]============\n\n"
			 << "1) Load both lists\n\n"
			 << "2) Display both lists and the quantity of elements\n\n"
			 << "3) Delete item from both lists \n\n"
			 << "4) Empty unsorted linked list\n\n"
			 << "5) Empty sorted linked list\n\n"
			 << "6) Exit program\n\n"
			 << "Pick a number from the menu: ";
			
		cin >> choice;
		
		cout << "\n=============================\n";
		
		switch(choice)
		{
			case 1: cout << "\nChoose file to load integers from\n\t\tor\n"
						 << "press enter for default (numbers.dat): ";
					cin.ignore();
					getline(cin,fileName);
					load(sortedList, unsortedList, fileName);
				    break;
			case 2: display(sortedList, unsortedList);
				    break;
			case 3: cout << "\nPick a number to delete: ";
					cin >> item;
					deleteItems(sortedList, unsortedList, item);
				    break;
			case 4: unsortedList.makeEmpty();
					cout << "\n\n\t[EVENT] Unsorted list is now empty.\n\n";
				    break;
			case 5: sortedList.makeEmpty();
					cout << "\n\n\t[EVENT] Sorted list is now empty.\n\n";
				    break;	    
			case 6: cout << "\nGoodbye!\n\n";
				    break;
			default: cout << "\n[ERROR] Please pick an option from the menu."
				          << "\n\n";
					break;
		}
				
	} while(choice != 6);
			
	return 0;
}

bool load(sll &sorted, usll &unsorted, string fileName)
{
	ifstream input;
	int number = 0;
	
	if(fileName == "")
		input.open("numbers.dat");
	else
		input.open(fileName.c_str());
	
	if (!input) 
	{
		cout << "\n\n[ERROR] Can't open input file!\n\n";
		input.close();
		return false;	
	}
	
	while (input >> number)
	{
		sorted.addItem(number);
		unsorted.addItem(number);
	}
	
	input.close();
	
	cout << "\n\n\t[EVENT] Numbers loaded into program" 
		 << " from numbers.dat\n\n";
	
	return true;
}

void display(sll &sorted, usll &unsorted)
{
	cout << "\n\n\t[EVENT] Unsorted | List quantity: " 
		 << unsorted.getQty() << "\n\n\t";
	
	for(int i = 0; i < unsorted.getQty(); i++)
		cout << unsorted.getNext()->data << " ";
		
	cout << "\n\n\t[EVENT] Sorted | List quantity: " 
		 << sorted.getQty() << "\n\n\t";
	
	for(int i = 0; i < sorted.getQty(); i++)
		cout << sorted.getNext()->data << " ";
	
	cout << "\n\n";
}

void deleteItems(sll &sorted, usll &unsorted, int item)
{
	if(sorted.deleteItem(item))
		cout << "\n\t[EVENT] Deleted " << item 
			 << " from the sorted list.\n";
	else
		cout << "\n\t[EVENT] " << item 
			 << " wasn't in the sorted list.\n";
	
	if(unsorted.deleteItem(item))
		cout << "\n\t[EVENT] Deleted " << item 
			 << " from the unsorted list.\n";
	else
		cout << "\n\t[EVENT] " << item 
			 << " wasn't in the unsorted list.\n";
}


















