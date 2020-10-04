#pragma once

//Namespace for Node:
namespace node
{
	//Class for Node:
	class node
	{
	public:
		//Constructor:
		node(double data, node* next, node* prev);

		//Data that the node will hold:
		double data;

		//The next node in the list:
		node* next;

		//The prev node in the list:
		node* prev;
	};
};
