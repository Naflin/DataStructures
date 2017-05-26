//TODO LIST
//separate header files

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "stack.h"
using namespace std;

int main()
{
	srand(time(0));
	Stack stack;
	int k = 0;
	int choice = 0;
	char flavors[] = {'C','G','L','S','O','R'};
	char flavorNames[12];
	data pez;
		
	do {
		cout << "\n====================================\n"
			 << "1) Load Candy\n"
			 << "2) Take a Candy\n"
			 << "3) Look at Candy\n"
			 << "4) Dump Candies\n" 
			 << "5) Throw Away Pez Dispensor\n"
			 << "Pick a number from the menu: ";
		
		cin >> choice;
		
		cout << "\n====================================\n\n";
		
		switch(choice)
		{
			case 1: 
					if(stack.isEmpty())
					{
						for(int i = 0; i < 12; i++)
						{
							pez.flavor = flavors[rand() % 6];
							cout << i << " " << pez.flavor 
								 << stack.getQty()<< endl;
							stack.push(i, pez);
						}
						cout << "Candies loaded. Enjoy!\n";
					}
					else
						cout << "Can't load candies. " 
							 << "There are still some left in the dispensor\n";
					break;
			case 2: 
					if(!stack.isEmpty())
					{
						stack.pop(k, pez);
						switch(pez.flavor)
						{
							case 'C': cout << "You popped a cherry candy!\n";
									  break;
							case 'G': cout << "You popped a grape candy!\n";
									  break;
							case 'L': cout << "You popped a lemon candy!\n";
									  break;
							case 'S': cout << "You popped a strawberry candy!\n";
									  break;
							case 'O': cout << "You popped an orange candy!\n";
								      break;
							case 'R': cout << "You popped a raspberry candy!\n";
									  break;
							default : cout << "You popped a mystery candy?\n";
									  break;
						}
					}
					else
					{
						cout << "You have " << stack.getQty() << " candies...\n";
					}
					break;
			case 3:
					if(!stack.isEmpty())
					{
						stack.peek(k, pez);
						switch(pez.flavor)
						{
							case 'C': cout << "Next candy is cherry.\n";
									  break;
							case 'G': cout << "Next candy is grape.\n";
									  break;
							case 'L': cout << "Next candy is lemon.\n";
									  break;
							case 'S': cout << "Next candy is strawberry.\n";
									  break;
							case 'O': cout << "Next candy is orange.\n";
								      break;
							case 'R': cout << "Next candy is raspberry.\n";
									  break;
							default : cout << "Next candy is a mystery?\n";
									  break;
						}
					}
					else
					{
						cout << "You have " << stack.getQty() << " candies...\n";
					}
					break;
			case 4: 
					if(!stack.isEmpty())
					{
						stack.makeEmpty();
						cout << "Dumped all candies.\n";
					}
					else
						cout << "You don't have any candies to dump.\n";
					break;
			case 5:
					cout << "\nPez dispenser thrown away.\n\n";
					break;
			default: cout << "That is not an option.\n";
					 break;
		}		
		
	} while(choice != 5);
	
	return 0;
}

