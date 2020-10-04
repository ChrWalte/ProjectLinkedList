#include "node.h"

//Constructor:
node::node::node(const double data, node* next, node* prev)
{
	//Set the data, next, and prev values for the node:
	this->data = data;
	this->next = next;
	this->prev = prev;
}