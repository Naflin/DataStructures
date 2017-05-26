/********************************************************************
	Program:	BlueNathanFF.cpp
	Author: 	Nathan Blue
	Assignment: Program #1
	Date: 		2/7/17
	Purpose:	Generate the farey sequence and save it
				to a file.
********************************************************************/
#include <iostream>
#include <fstream>
using namespace std;

void build_farey(int *&, int);
void display_farey(int *, int);
void write_farey(int *, int);
int * shift(int *, int, int, int);
void init(int *, int);
int getSize(int *);

int main()
{
	int order;
	int *array = new int[5];
	
	init(array, 5);
	
	cout << "Choose the Farey Sequence order: ";
    cin >> order;
	
	cout << "\nORD.\tFRACTIONS\n";

	for(int i = 1; i <= order; i++)
	{
		build_farey(array, i);
		
		display_farey(array, i);
		write_farey(array, i);
	}
    
    delete[] array;
    array = NULL;
	
	return 0;
}

void build_farey(int *& array, int order)
{
	int * tempArray;
	int size = getSize(array);
	int location = size - 1;
	
	int numer = 0;
	int denom = 0;
	
	for(int i = 0; i < order - 1; i++)
	{
		for(int j = 0; j < (size / 2) - 1; j++)
		{
			denom = array[location] + array[location - 2];
			numer = array[location - 1] + array[location - 3];
			
			if(denom <= order)
			{
				tempArray = shift(array, location, numer, denom);
				delete[] array;
				array = tempArray;
				tempArray = NULL;
			}
			location -= 2;
		}
		size = getSize(array);
		location = size - 1;
	}
	
}

void display_farey(int * a, int order)
{
	int size = getSize(a);
	
	cout << "\n\t";
	
	for(int i = 0; a[i] != -1; i++)
	{
		if(i % 2 == 0)
			cout << " " << a[i] << " ";
	}
		
	cout << endl << order << "\t";
	
	for(int i = 0; a[i] != -1; i++)
	{
		if(i % 2 == 0)
			cout << "--";
		else
			cout << ((a[i+1] == -1) ? "" : ",");
	}
	
	cout << "\n\t";
	
	for(int i = 0; a[i] != -1; i++)
	{
		if(i % 2 == 1)
			cout << " " << a[i] << " ";
	}
	
	cout << "\n\n";
}

void write_farey(int * a, int order)
{
	int size = getSize(a);
	
	ofstream file;
	
	file.open("farey.txt", ios::app);
	
	file << "\n\t";
	
	for(int i = 0; a[i] != -1; i++)
	{
		if(i % 2 == 0)
			file << " " << a[i] << " ";
	}
		
	file << endl << order << "\t";
	
	for(int i = 0; a[i] != -1; i++)
	{
		if(i % 2 == 0)
			file << "--";
		else
			file << ((a[i+1] == -1) ? "" : ",");
	}
	
	file << "\n\t";
	
	for(int i = 0; a[i] != -1; i++)
	{
		if(i % 2 == 1)
			file << " " << a[i] << " ";
	}
	
	file << "\n";
	
	file.close();
}

int * shift(int * array, int location, int numer, int denom)
{
	int size = getSize(array);
	int *newArray = new int[size+3];
	bool locationReached = false;
	int count = 2;
	
	if(location > size - 1)
		location = size - 1;
	else if(location < 2)
		location = 3;
	else if(location % 2 == 0)
		location++;
	
	newArray[size+2] = -1;
	
	for(int u = 0; u < size; u++)
		newArray[u] = array[u] + 1;
	
	for(int i = size - 1; i >= 0; i--)
	{
		if(i == location)
			locationReached = true;
		
		if(!locationReached)
			newArray[i+2] = array[i];
		else if(locationReached && count != 0)
		{
			newArray[i+2] = array[i];
			
			if(count == 1)
				newArray[i] = numer;
			else
				newArray[i] = denom;
			count--;
		}
		else
			newArray[i] = array[i];
	}
	
	return newArray;
}

int getSize(int * array)
{
	int size = 0;
	
	for(int i = 0; array[i] != -1; i++)
		size++;
	
	return size;
}

void init(int * a, int size)
{
	for(int i = 0; i < size; i++)
	{		
		if(i == size - 1)
			a[i] = -1;
		else if(i == 0)
			a[i] = 0;
		else
			a[i] = 1;
	}
}




