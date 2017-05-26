/********************************************************************
	Program:	node.h
	Author: 	Nathan Blue
	Assignment: Inventory Program
	Date: 		3/22/17
	Purpose:	The node and struct for the doublely linked list
								
********************************************************************/

typedef struct data
{
	char toolname[35];
	int quantity;
	double cost;
};

struct node
{
	node *prev;
	data d;
	int key;
	node *next;
};
