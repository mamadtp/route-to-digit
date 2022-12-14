// Node.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "binaryTree.h"
#include <stack>
#include <queue> 
#include <string>

using namespace std;


int main()
{


	bool DebugMode = false;

	Node* goal = new Node();
	stack<string> resultAct;

	cout << "Hello man type your number:";
	cin >> goal->value;


	queue<Node> frontier;
	BinaryTree* explored = new BinaryTree();
	Node* intial_state= new Node;
	intial_state->value = 4;
	intial_state->parent = NULL;
	intial_state->act = -1;

	frontier.push(*intial_state);
	explored->Insert(intial_state);

	while (true)
	{
		if (frontier.size() == 0)
			break;
		Node l = frontier.front();


		if (DebugMode)
			cout << l.value;


		if (l.value == goal->value)
		{
			Node* temp = &l;
			while (temp != NULL)
			{
				if (temp->act == 0)
					resultAct.push("Double");
				else if (temp->act == 1)
					resultAct.push("Sqrt");
				else if (temp->act == 2)
					resultAct.push("Floor");
				temp = temp->parent;
			}
			for (int i = 0; i < resultAct.size(); i++)
				cout << resultAct.top();
			cout << "The number of Node in explored:" + explored->count;
			cout << "Time in Milliseconds:";
			break;
		}

		// *2 -> 0
		// sqrt() -> 1
		// floor() -> 2

		Node* dbl= new Node;
		dbl->value = l.value * 2;
		dbl->parent = &l;
		dbl->act = 0;

		if (!explored->Search(dbl))
		{
			frontier.push(*dbl);
			explored->Insert(dbl);
		}

		Node* sqrt= new Node;
		sqrt->value = sqrtf(l.value);
		sqrt->parent = &l;
		sqrt->act = 1;

		if (!explored->Search(sqrt))
		{
			frontier.push(*sqrt);
			explored->Insert(sqrt);
		}

		Node* floor= new Node;
		floor->value = floorf(l.value);
		floor->parent = &l;
		floor->act = 0;

		if (!explored->Search(floor))
		{
			frontier.push(*floor);
			explored->Insert(floor);
		}


	}
	system("PAUSE");
	return 0;
}


