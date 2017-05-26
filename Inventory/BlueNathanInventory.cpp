/********************************************************************
	Program:	BlueNathanInventory.cpp
	Author: 	Nathan Blue
	Assignment: Inventory Program
	Date: 		3/22/17
	Purpose:	Create an inventory program that uses the
				doubly linked list.
								
********************************************************************/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <limits>
#include "node.h"
#include "dll.h"
using namespace std;

bool checkQuantity(int);
bool checkRecord(int);
bool checkCost(double);
void inputQuantity(int &, bool message = true);
void inputRecord(int &, bool message = true);
void inputCost(double &, bool message = true);
void displayData(data, int);

int main()
{
	dll list;
	data item;
	int * tempArray;
	int choice; 
	int fileSize = 0;
	int begin = 0, end = -1; 
	int index = 0; 
	int key = 0; 
	int inc = 0; 
	int record = 0;
	int hrecord = 0;
	double highest;
	char answer = ' ';
	char character;
	char c;
	char fileName[35];
	bool reading = false; 
	bool canLoop = true;
	bool found = false;
	bool complete = false;
	bool fileOpen = false;
	
	ofstream outfile;
	ifstream file;
	
	cout << "Welcome to your database!\n";
	
	do {
		cout << "Please enter the name of your inventory file (inventory.txt): ";
		
		cin >> fileName;
		
		file.open(fileName);
		
		if(file.fail())
		{
			fileOpen = false;
			cout << "\nFile doesn't exist\n";
		}
		else
			fileOpen = true;
		
	} while(!fileOpen);
	
	while(file.good())
	{
		character = file.get();
		if(character != -1)
			fileSize++;
	}
	
	file.close();
	
	char * array = new char[fileSize+1];
	file.open(fileName);
	
	for(int i = 0; i < fileSize; i++)
		array[i] = file.get();
	
	array[fileSize] = '\0';
	file.close();
	
	for(int i = 0; i <= fileSize; i++)
	{
		c = array[i];
		switch(c)
		{
			case '\n':
			case -1:
			case 0: 
			case ';':
					 if(reading)
					 {
					 	end = i;
					 	char * tempString = new char[(end - begin)+1];
					 	inc = 0;
					 	for(int j = begin; j < end; j++)
					 	{
					 		tempString[inc] = array[j];				 		
					 		if(index == 1 && inc < 34)
					 			item.toolname[inc] = array[j];
					 		inc++;
					 	}
					 	tempString[end-begin] = '\0';
					 	if(index == 1 && inc >= 34)
					 		item.toolname[34] = '\0';
					 	else if(index == 1)
					 		item.toolname[inc] = '\0';
					 	
					 	switch(index)
					 	{
					 		case 0: key = atoi(tempString);
					 				index++;
					 			 	break;
					 		case 1: index++;
							 		break;
					 		case 2: item.quantity = atoi(tempString);
					 				index++;
					 				break;
					 		case 3: item.cost = atof(tempString);
					 				index = 0;
					 				break;
					 	}
					 						 	
					 	reading = false;
					 	delete[] tempString;
					 }
					 
					 if(c != ';')
					 	list.add(item,key);
					 	
		 			 break;
		 	default:
		 		if(!reading)
		 		{
		 			begin = i;
		 			reading = true;
		 		}	 	
		}
	}
		
	delete[] array;
		
	do {
		do {
		
		cout << "\n\n============ Database ============\n"
			 << "(1) Add new record\n"
			 << "(2) Delete record (by part-record number)\n"
			 << "(3) Modify record\n"
			 << "(4) List all records by Quantity\n"
			 << "(5) List all records by COST\n"
			 << "(6) List all records by Part-Record Number\n"
			 << "(7) Quit and SAVE (save your list back to the file)\n"
			 << "Choice: ";
		
		
			cin >> choice;
			if(choice && choice > 0 && choice < 10000000)
 				canLoop = false;
		 	else
		 	{
		 		cout << "\n\tThis is not a valid choice. Try again\n";
		 		cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		} while(canLoop);
			
		switch(choice)
		{
			case 1 : inputRecord(record);
					
					 cout << "\nEnter tool name: ";
					 if(!cin.getline(item.toolname, 34))								 					 					 
					 {
					 	cin.clear();
					 	cin.ignore(numeric_limits<streamsize>::max(), '\n');	
					 }
					 
					 inputQuantity(item.quantity);
					 inputCost(item.cost);
					 
					 if(list.add(item, record))
					 	cout << "\n\tRecord added!";
					 else
					 	cout << "\n\tA record already exists with that number.";
					 
					 break;
			case 2 : cout << "\nChoose inventory number to delete: ";
					 	
					 inputRecord(record, false);
						 
					 if(list.deleteItem(record))
					 	cout << "\n\tRecord deleted!";
					 else
					 	cout << "\n\tThis record number doesn't exist.";
					 break;
			case 3 : cout << "Choose a record number to modify: ";
			
					 inputRecord(record, false);
					 
					 if(list.view(item,record))
					 {
						displayData(item, record);
						hrecord = record;
						
						cout << "Edit inventory number? (Y/N): ";
						cin >> answer;
						cin.ignore();
						
						if(answer && (answer == 'y' || answer == 'Y'))								 
							inputRecord(record);
					    
					    cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					    
					    cout << "Edit tool name? (Y/N): ";
						cin >> answer;
					    cin.ignore();
					    
					    if(answer && (answer == 'y' || answer == 'Y'))
					    {
					    	cout << "\nEnter tool name: ";
						  	if(!cin.getline(item.toolname, 34))								 					 					 
							{
								cin.clear();
							 	cin.ignore(numeric_limits<streamsize>::max(),'\n');
							}
					    }
					    
					    cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					    
					    cout << "Edit quantity? (Y/N): ";
						cin >> answer;
					    
					    if(answer && (answer == 'y' || answer == 'Y'))
					 		inputQuantity(item.quantity);
					 	
					 	cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					 	
						cout << "Edit cost? (Y/N): ";
						cin >> answer;	
					 	
					 	if(answer && (answer == 'y' || answer == 'Y'))
							inputCost(item.cost);
							
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						
						if(list.deleteItem(hrecord))
						 	if(list.add(item,record))
						 		cout << "\nRecord modified!";
						 	else
						 		cout << "\nCould not modify record.";
						else
						 	cout << "\nCould not modify record.";
						}
					 else
						cout << "\nRecord doesn't exist!";
					 
				 	 break;
			case 4 : tempArray = new int[list.getQty()];
					 canLoop = true;
					 complete = false;
					 highest = 0;
					 hrecord = 0;
					 
					 for(int i = 0; i < list.getQty(); i++)
					 	tempArray[i] = 0;

					 while(canLoop)
					 { 
						if(list.getNext(item, record))
						{
							if(item.quantity > highest)
							{
								for(int i = 0; i < list.getQty(); i++)
								{
									if(tempArray[i] == record)
										found = true;
								}
								if(!found)
								{
									highest = item.quantity;
									hrecord = record;
								}
								found = false;
							}
						}
						else
						{
							complete = true;
							for(int i = 0; i < list.getQty(); i++)
				 			{
								if(tempArray[i] == 0)
								{
									tempArray[i] = hrecord;
									highest = 0;
									hrecord = 0;
									complete = false;
									break;
								}
							}
						}
						
						if(complete)
						{
							canLoop = false;
							
							for(int q = 0; q < list.getQty(); q++)
							{
								record = tempArray[q];
								if(list.view(item,record))
									displayData(item, record);
							}		
						}
					 }
					 
					 delete[] tempArray;
					 					 					 
					 break;
			case 5 : tempArray = new int[list.getQty()];
					 canLoop = true;
					 complete = false;
					 highest = 0;
					 hrecord = 0;
					 
					 for(int i = 0; i < list.getQty(); i++)
					 	tempArray[i] = 0;

					 while(canLoop)
					 { 
						if(list.getNext(item, record))
						{
							if(item.cost > highest)
							{
								for(int i = 0; i < list.getQty(); i++)
								{
									if(tempArray[i] == record)
										found = true;
								}
								if(!found)
								{
									highest = item.cost;
									hrecord = record;
								}
								found = false;
							}
						}
						else
						{
							complete = true;
							for(int i = 0; i < list.getQty(); i++)
				 			{
								if(tempArray[i] == 0)
								{
									tempArray[i] = hrecord;
									highest = 0;
									hrecord = 0;
									complete = false;
									break;
								}
							}
						}
						
						if(complete)
						{
							canLoop = false;
							
							for(int q = 0; q < list.getQty(); q++)
							{
								record = tempArray[q];
								if(list.view(item,record))
									displayData(item, record);
							}		
						}
					 }
					 
					 delete[] tempArray;
				 	 break;
			case 6 : while(list.getNext(item, record))
					 	displayData(item, record);
					 break;
			case 7 : cout << "Saving...";
					 outfile.open(fileName);
					 
					 while(list.getNext(item, record))
					 {
						outfile << record << ";" 
								<< item.toolname << ";" 
								<< item.quantity << ";" 
								<< item.cost << "\n";		 
					 }
					 
					 outfile.close();
					 
					 cout << "\nDone.  Bye!\n";
					 
					 break;
			default : cout << "\n\tThis is not a valid choice. Try again\n";
					  break;
		}	
		
	} while(choice != 7);
	
	return 0;
}

bool checkQuantity(int c)
{
 	if(c && c > 0 && c < 10000000)
 		return true;
 	else
 	{
 		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return false;
	}
	return false;
}

bool checkRecord(int c)
{
 	if(c && c > 0 && c < 10000000)
 		return true;
 	else
 	{
 		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return false;
 	}
	return false;
}

bool checkCost(double c)
{
 	if(c && c >= 0.01 && c < 10000000.00)
		return true;
 	else
 	{
 		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return false;
	}
	return false;
}

void inputQuantity(int &q, bool message)
{
	bool isOk = false;
	while(!isOk)
	{
		if(message)
	 		cout << "\nEnter quantity number: ";
		cin >> q;
		if(checkQuantity(q))
			isOk = true;
		else
	 		cout << "\n\tThe quantity must be "
	 			 << "between the range: "
	 			 << "0 and 9999999\n";
	 	message = true;
	}
}

void inputRecord(int &r, bool message)
{
	bool isOk = false;
	while(!isOk)
	 {
	 	if(message)
	 		cout << "\nEnter inventory number: ";
		cin >> r;
		if(checkRecord(r))
			isOk = true;
		else
	 		cout << "\n\tThe inventory number must be "
	 			 << "between the range: "
	 			 << "0 and 9999999\n";
	 	message = true;
	 }
	 cin.ignore();
}

void inputCost(double &c, bool message)
{
	bool isOk = false;
	while(!isOk)
	 {
	 	if(message)
	 		cout << "\nEnter the cost: ";
		cin >> c;
		if(checkCost(c))
			isOk = true;
		else
	 		cout << "\n\tThe cost must be "
	 			 << "between the range: "
	 			 << "0.01 and 9999999.99\n";
	 	message = true;
	 }
}

void displayData(data d, int part)
{
	cout << "\n\nPart-Record Number: " << part 
		 << "\nToolname: " << d.toolname 
	 	 << "\nQuantity: " << d.quantity 
	 	 << "\nCost: " << d.cost << endl;
}
