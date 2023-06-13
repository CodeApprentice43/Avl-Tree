/*
Nafis Mortuza
Professor Mckay
CS 232
Project-1*/


#include"avltree.h"
#include<iostream>
using namespace std;

int main()
{
	AvlTree<int>mytree;
	for (int i = 1; i <= 15; i++)
	{
		//in case you want to test the tree out with random values
		/*int val = rand() % 100;
		mytree.insert(val);
		cout << "The tree after inserting:" << val << ':' << endl;*/
		mytree.insert(i);
		cout << "The tree after inserting:" << i << ':' << endl;
		cout << endl;
		mytree.graph(cout);
		cout << '\n';
		cout << '\n';
		cout << '\n';
	}
	cout << '\n';

	
	
}