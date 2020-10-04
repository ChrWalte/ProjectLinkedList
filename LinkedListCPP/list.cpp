#include "list.h"

//Constructor:
list::list::list()
{
	//Set both head and tail to null:
	head_ = nullptr;
	tail_ = nullptr;
}

//Destructor:
list::list::~list()
{
	//Set current_node to head:
	auto* current_node = head_;

	//Set the next node to null:
	node::node* next_node = nullptr;

	//Continue until the current_node is null:
	while (current_node != nullptr)
	{
		//Set the next nope to the current_nodes next:
		next_node = current_node->next;

		//Delete the current_node:
		delete current_node;

		//Set the current node to the next node:
		current_node = next_node;
	}
}

//Insert into list:
node::node* list::list::insert(const int index, const double data)
{
	//If index less than 0, return null;
	if (index < 0)
		return nullptr;

	//Set the current_index to 1:
	int current_index = 1;

	//Set the current_node to head:
	auto* current_node = head_;

	//Continue until current_node is null and the current_index is less than the provided index:
	while (current_node && current_index < index)
	{
		//Set the current_node to the next node:
		current_node = current_node->next;

		//Add one to the index:
		current_index++;
	}

	//return null if the index is greater than 0 but the current_node is null, meaning the provided index is greater than the length of the list:
	if (index > 0 && current_node == nullptr)
		return nullptr;

	//Create a new node with the provided data:
	auto* new_node = new node::node(data, nullptr, nullptr);

	if (index == 0)
	{
		//Set the new_nodes next to the head:
		new_node->next = head_;

		//Set the head to the new_node:
		head_ = new_node;
	}
	else
	{
		//Set the new_node next to the current_node next:
		new_node->next = current_node->next;

		//Set the new_node prev to the current_node:
		new_node->prev = current_node;

		//current_node next to the new_node:
		current_node->next = new_node;
	}

	// return the new_node:
	return new_node;
}

//Insert into list:
node::node* list::list::insert_start(double data)
{
	//Insert a new node at the start of the list:
	return insert(0, data);
}

//Insert into list:
node::node* list::list::insert_end(double data)
{
	//Insert a new node at the end of the list:
	return insert(get_count(), data);
}

//Displays the entire list and then the total amount of nodes.
void list::list::display_list() const
{
	//Set the current_head to the head
	auto* current_node = head_;

	//Current index:
	int index = 0;

	//Do until the current_node is null
	while (current_node)
	{
		//Print to screen:
		std::cout << current_node->data << "->";

		//Set the current_node to the next node:
		current_node = current_node->next;

		//Add one to the index:
		index++;
	}

	//Display the number of nodes in the list:
	std::cout << "\nNumber of nodes in list: " << index << ".\n";
}

//Returns the number of elements in the list:
int list::list::get_count() const
{
	//Set the current_node to the head of the list:
	auto* current_node = head_;

	//current node count in the list:
	int node_count = 0;

	//Do until the current_node is null
	while (current_node)
	{
		//Add one to the node_count:
		node_count++;

		//Set the current node to the next node:
		current_node = current_node->next;
	}

	//Return node_count:
	return node_count;
}

//Find the node with the given data:
int list::list::find_node(const double data) const
{
	//Set the current_node to the head:
	auto* current_node = head_;

	//Current index in the list:
	int index = 0;

	//Do until the current_node is null and the next node is null:
	while (current_node && current_node->next != nullptr)
	{
		//if the current_nodes data is equal to the provided data, return the current index:
		if (current_node->data == data)
			return index;

		//Add one to the index:
		index++;

		//Set the current_node to the next node:
		current_node = current_node->next;
	}

	//Return -1 when not found:
	return -1;
}

//Delete node with the given data:
int list::list::delete_node(const double data)
{
	//Get the index of the provided data:
	int node_index = find_node(data);

	//Return the index of the node after deleting it:
	return delete_node(node_index);
}

//Delete node at the given index:
int list::list::delete_node(int index)
{
	//Set the last_node to null:
	node::node* last_node = nullptr;

	//Set the current_node to the head:
	auto* current_node = head_;

	//Current index inside the list:
	int current_index = 0;

	//Do until the current_node is null and the current index does not equal the provided index:
	while (current_node && current_index != index)
	{
		//Add one to the current_index:
		current_index++;

		//Set the last node to the current_node:
		last_node = current_node;

		//Set the current node to the next node:
		current_node = current_node->next;
	}

	//If the current_node is not null:
	if (current_node)
	{
		//If the last_node is not null, set the last_node next to the current_node next:
		if (last_node)
			last_node->next = current_node->next;
		else //Set the head to the current_node next;
			head_ = current_node->next;

		//Delete the current_node:
		delete current_node;

		//Return the current_node:
		return current_index;
	}

	//Return -1 indicating that the node was not found:
	return -1;
}

//Get the node with the min data:
node::node* list::list::get_next(node::node* given_node)
{
	//Return the next node from the provided given_node:
	return given_node->next;
}

//Get the node with the max data:
node::node* list::list::get_prev(node::node* given_node)
{
	//Return the prev node from the provided given_node:
	return given_node->prev;
}

//Returns the next node from the given node:
node::node* list::list::get_min() const
{
	//Set the current_node to the head of the list:
	auto* current_node = head_;

	//Set the min_node to the head of the list:
	auto* min_node = head_;

	//Do until the current_node is null:
	while (current_node)
	{
		//If the current_nodes data is less that the min_nodes data, set the min_node to the current_node:
		if (current_node->data < min_node->data)
			min_node = current_node;

		//Set the current_node to the next node:
		current_node = current_node->next;
	}

	//Return the min_node:
	return min_node;
}

//Returns the prev node from the given node:
node::node* list::list::get_max() const
{
	//Set the current_node to the head of the list:
	auto* current_node = head_;

	//Set the max_node to the head of the list:
	auto* max_node = head_;

	//Do until the current_node is null:
	while (current_node)
	{
		//If the current_nodes data is greater that the max_nodes data, set the max_node to the current_node:
		if (current_node->data > max_node->data)
			max_node = current_node;

		//Set the current_node to the next node:
		current_node = current_node->next;
	}

	//Return the max_node:
	return max_node;
}