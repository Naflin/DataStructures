/********************************************************************
	Program:	BlueNathanQueen.cpp
	Author: 	Nathan Blue
	Assignment: Eight Queens
	Date: 		4/4/17
	Purpose:	Solve the Eight Queens problem using
				recursion.
********************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

const int ROW=8, COL=8;

bool qt(char b[][COL], int, int, int);
bool badMove(char b[][COL], int r, int c);
void displayBoard(char b[][COL]);

int main()
{
	char board[ROW][COL];
	int r = 0, c = 0;
	
	for(int i = 0; i < ROW; i++)
		for(int j = 0; j < COL; j++)
			board[i][j] = '+';
	
	cout << "Choose position of first Queen.";
	do {
		cout << "\nRow: ";
		cin >> r;
		if(r > ROW || r < 0)
			cout << "\n\nNot a valid row number!\n\n";
		
	} while(r > ROW || r < 0);
	
	do {	
		cout << "\nColumn: ";
		cin >> c;
		if(c > COL || c < 0)
			cout << "\n\nNot a valid column number!\n\n";
	} while(c > COL || c < 0);
	
	if(qt(board, r, c, 1))
	{
		cout << "\n\n=====Final Solution!=====\n\n";
		displayBoard(board);
	}
	else
		cout << "\nNo solution found.";
	
	return 0;
}
///////////////////////////////////////////////////////////////////////////
void displayBoard(char b[][COL])
{
	cout << endl << "===========================";
	for(int r=0; r < ROW; r++)
	{
		cout << endl;
		for(int c=0; c < COL; c++)
			cout << right << setw(3) << b[r][c];
	}
}
////////////////////////////////////////////////////////////////////////////
bool qt(char b[][COL], int r, int c, int move)
{
	if(c > 7)
		c = 0;
	if(badMove(b, r, c))
		return false;
	else
	{
		b[r][c] = 'Q';
		displayBoard(b);
		if(move == COL)
			return true;
	}
		
	for(int pos = 0; pos < ROW; pos++)
	{
		if(qt(b, pos, c+1, move+1))
			return true;
	}
	
	b[r][c] = '+';
	return false;
}
/////////////////////////////////////////////////////////////////////////
bool badMove(char b[][COL], int r, int c)
{
	for(int i = 0; i < ROW; i++)
	{
		if(b[i][c] == 'Q')
			return true;
		
		if(b[r][i] == 'Q')
			return true;
		
		if(r+i >= 0 && r+i < ROW && c+i >= 0 && c+i < COL)
			if(b[r+i][c+i] == 'Q')
				return true;
				
		if(r-i >= 0 && r-i < ROW && c+i >= 0 && c+i < COL)
			if(b[r-i][c+i] == 'Q')
				return true;
			
		if(r+i >= 0 && r+i < ROW && c-i >= 0 && c-i < COL)
			if(b[r+i][c-i] == 'Q')
				return true;
			
		if(r-i >= 0 && r-i < ROW && c-i >= 0 && c-i < COL)
			if(b[r-i][c-i] == 'Q')
				return true;
	}
	
	return false;
}



