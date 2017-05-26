/********************************************************************
	Program:	BlueNathanFractal.cpp
	Author: 	Nathan Blue
	Assignment: #5 - Recursion - A Fractal Pattern
	Date: 		4/4/17
	Purpose:	Build a fractal pattern using recursion.
********************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

void pattern(int, int);
bool powOf2(int);

int main()
{
	int power = 0;
	char c = ' ';
	
	cout << "======Asterisk Fractals======\n";
	
	do{
		do {
			cout << "\nEnter in a power of 2: ";
			cin >> power;
			
			if(!powOf2(power))
				cout << "\nThis is not a power of 2. Try again.\n";
		} while(!powOf2(power));
		
		pattern(power,0);
		
		cout << "\n\nTry again? (Y/n): ";
		cin >> c;
		
	} while(c == 'Y' || c == 'y');
	
	return 0;
}

void pattern(int n, int i)
{
	double exp = log(n)/log(2.0);
	if(exp < 0)
		return;
	pattern(pow(2.0, exp - 1), i);
	for(int k = 0; k < i; k++) cout << " ";
	for(int k = 0; k < n; k++) cout << "* ";
	cout << endl;
	pattern(pow(2.0, exp - 1), n + i);	
}

bool powOf2(int n)
{
	return (n>0 && ((n & (n-1)) == 0));
}





