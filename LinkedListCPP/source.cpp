#include "list.h"

//Main method for the program:
int main()
{
	//A new list:
	auto linked_list = list::list();

	//Display an empty list:
	std::cout << "Displaying Empty List:\n";
	linked_list.display_list();

	//Insert into the list at the end:
	for (int i = 0; i < 10; i++)
		linked_list.insert_end(i);

	//Insert some more data:
	linked_list.insert_start(150);
	linked_list.insert(5, 250);
	linked_list.insert(9, 350);
	linked_list.insert_start(-1000);

	//Display the list again:
	std::cout << "Displaying List With 14 Items:\n";
	linked_list.display_list();

	//Delete the node with the given values:
	linked_list.delete_node(150);
	linked_list.delete_node(350);

	//Display list again:
	std::cout << "Displaying List With 12 Items:\n";
	linked_list.display_list();

	//If the data is found at 4, display a message:
	if (linked_list.find_node(250) == 4)
		std::cout << "Node with data of 250 found in correct location.\n";

	//Delete node:
	linked_list.delete_node(250);

	//If the data is not found, display a message:
	if (linked_list.find_node(250) == -1)
		std::cout << "Node with data of 250 not found.\n";

	//Display the min and max node values:
	std::cout << "Get min node: " << linked_list.get_min()->data << std::endl;
	std::cout << "Get max node: " << linked_list.get_max()->data << std::endl;

	//Delete the node with data = -1000
	linked_list.delete_node(-1000);

	//If the node is still in the list, display the message:
	if (linked_list.find_node(-1000) == -1)
		std::cout << "Node with data of -1000 not found.\n";

	//Display the min and max node values:
	std::cout << "Get min node: " << linked_list.get_min()->data << std::endl;
	std::cout << "Get max node: " << linked_list.get_max()->data << std::endl;

	//insert a new node:
	auto* new_node = linked_list.insert(5, 404);

	//Display the node list:
	linked_list.display_list();

	//Display the prev data, the current data, and the next data of the new_node:
	std::cout << new_node->prev->data << std::endl;
	std::cout << new_node->data << std::endl;
	std::cout << new_node->next->data << std::endl;
}