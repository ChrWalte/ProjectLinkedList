#pragma once

//Internal:
#include "node.h"

//External
#include <iostream>

//Namespace for List:
namespace list
{
	//Class for List:
	class list
	{
	public:
		//Constructor:
		list(void);

		//Destructor:
		~list(void);

		//Insert into list:
		node::node* insert(int index, double data);
		node::node* insert_start(double data);
		node::node* insert_end(double data);

		//Display entire list:
		void display_list(void) const;

		//Check if the list is empty:
		bool is_empty() const { return head_ == nullptr; }

		//Returns the number of elements in the list:
		int get_count() const;

		//Find the node with the given data:
		int find_node(double data) const;

		//Delete node with the given data:
		int delete_node(double data);

		//Delete node at the given index:
		int delete_node(int index);

		//Get the node with the min data:
		node::node* get_min() const;

		//Get the node with the max data:
		node::node* get_max() const;

		//Returns the next node from the given node:
		static node::node* get_next(node::node* given_node);

		//Returns the prev node from the given node:
		static node::node* get_prev(node::node* given_node);

	private:
		//Start of the list:
		node::node* head_;

		//End of the list:
		node::node* tail_;
	};
};
