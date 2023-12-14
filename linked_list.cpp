/******************************************************
** Program: linked_list.cpp
** Author: Mujtaba Aljabery
** Date: 08/15/2021
** Description: This file defines the functions declared in the Linked_List header file. 
** Input: none. 
** Output: A list with nodes, sorted in both ascended and descended formats.
******************************************************/

#include "linked_list.h"
#include <stdlib.h>
using std::string;

/*************************************************************************************************************************** 
** Function: Linked_List()
** Description: This is the constructor of the Linked_List class. 
** Parameters: none. 
** Pre-Conditions: A list is created. 
** Post-Conditions: The constructor initializes the list to originally have a length of 0, and the head and tail node to be nullptr.   
*********************************************************************************************************************************/
Linked_List::Linked_List()
{
    length = 0;
    head = nullptr;
    tail = nullptr;
}

/*************************************************************************************************************************** 
** Function: ~Linked_List()
** Description: This is the destructor of the Linked_List class.  
** Parameters: none. 
** Pre-Conditions: The user chooses to end the application. 
** Post-Conditions: The destructor will be called and clear the memory from the Linked list. 
*********************************************************************************************************************************/
Linked_List::~Linked_List()
{
    Node *current = tail;
    Node *temp = current;
    while (current != nullptr)
    {
        temp = current->next;
        delete current;
        current = temp;
    }
    head = nullptr;
    tail = nullptr;
    length = 0;
}

/*************************************************************************************************************************** 
** Function: unsigned int get_length()
** Description: This function gets the length of a list. 
** Parameters: none. 
** Pre-Conditions: It is called as such: list->get_length(); . 
** Post-Conditions: This will grab the length of the list.
*********************************************************************************************************************************/
unsigned int Linked_List::get_length()
{
    return length;
}

/*************************************************************************************************************************** 
** Function: Node *get_head()
** Description:  This is a getter function for the Node *head value.
** Parameters: none. 
** Pre-Conditions: It is called in a function.
** Post-Conditions: It will get the tail value and have it accessible. 
*********************************************************************************************************************************/
Node *Linked_List::get_head()
{
    return head;
}

/*************************************************************************************************************************** 
** Function: void set_head()
** Description: This is a setter function for the Node *head value.  
** Parameters: Node* hi
** Pre-Conditions: It is called in a function. 
** Post-Conditions: It will get the tail value and have it accessible. 
*********************************************************************************************************************************/
void Linked_List::set_head(Node *hi)
{
    head = hi;
}
/*************************************************************************************************************************** 
** Function: Node *get_tail()
** Description: This is a getter function for the Node *tail value. 
** Parameters: none.
** Pre-Conditions: It's called in a function and used by a list.
** Post-Conditions: It will set the head to what the user wants inside its parameters.
*********************************************************************************************************************************/
Node *Linked_List::get_tail() const
{
    return tail;
}

/*************************************************************************************************************************** 
** Function: Node *reference_node()
** Description: This function is a getter function that gets the pointer of the tail of the Linked list.
** Parameters: none.
** Pre-Conditions: It's called in a function and used by a list in a sorting function.
** Post-Conditions: The sort function will use the tail and start going through the list to sort as needed. 
*********************************************************************************************************************************/
Node **Linked_List::reference_node()
{
    return &tail;
}

/*************************************************************************************************************************** 
** Function: void set_tail()
** Description: This is a setter function for the Node *tail value. 
** Parameters: Node* bye
** Pre-Conditions: It's called in a function and used by a list. 
** Post-Conditions: It will set the head to what the user wants inside its parameters. 
*********************************************************************************************************************************/
void Linked_List::set_tail(Node *bye)
{
    tail = bye;
}

/*************************************************************************************************************************** 
** Function: void print_memory()
** Description: This function prints the memory of each node. 
** Parameters: none
** Pre-Conditions: The function is called.
** Post-Conditions: It will print the current node, the node next to it, and the node previous to it. 
*********************************************************************************************************************************/
void Linked_List::print_memory()
{
    Node *current = tail;
    while (current != nullptr)
    {
        std::cout << "Current: " << current << " | "
                  << "Next: " << current->next << " | "
                  << "Previous: " << current->previous << std::endl;
        current = current->next;
    }
}

/*************************************************************************************************************************** 
** Function: void print()
** Description: This function will print the entire list and the nodes that compose it. 
** Parameters: none. 
** Pre-Conditions: The function is called. 
** Post-Conditions: It will print the list, from the head node to the tail node. 
*********************************************************************************************************************************/
void Linked_List::print()
{
    Node *current = tail;
    while (current != nullptr)
    {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

/*************************************************************************************************************************** 
** Function: void clear()
** Description: This function clears up the list and nodes inside.  
** Parameters: none. 
** Pre-Conditions: The function is called.
** Post-Conditions: It will clear up the entire list and delete the nodes inside, making it essential for the redo operation. 
*********************************************************************************************************************************/
void Linked_List::clear()
{
    Node *current = tail;
    Node *temp = current;
    while (current != nullptr)
    {
        temp = current->next;
        delete current;
        current = temp;
    }
    head = nullptr;
    tail = nullptr;
    length = 0;
}

/*************************************************************************************************************************** 
** Function: unsigned int push_front()
** Description: this function will insert a ndoe in the list, but to the front. 
** Parameters: int front
** Pre-Conditions: the function is called. 
** Post-Conditions:  It will insert a value and push it ahead of what was inserted previously.  
*********************************************************************************************************************************/
unsigned int Linked_List::push_front(int front)
{
    Node *current = new Node;
    current->val = front;
    current->next = nullptr;
    if (length <= 0)
    {
        tail = current;
    }
    else
    {
        current->previous = head;
        head->next = current;
    }
    length++;
    head = current;
    return length;
}

/*************************************************************************************************************************** 
** Function: unsigned int push_back()
** Description: This function will insert a node in the list, but to the back. 
** Parameters: int back 
** Pre-Conditions: The function is called. 
** Post-Conditions: It will insert a value and push it behind what was inserted previously. 
*********************************************************************************************************************************/
unsigned int Linked_List::push_back(int back)
{ //same as push_front, just reversed (TAKE A LOOK AT THE DRAWING WHEN REDOING!)
    Node *current = new Node;
    current->val = back;
    current->previous = nullptr;
    if (length <= 0)
    {
        head = current;
    }
    else
    {
        current->next = tail;
        tail->previous = current;
    }
    length++;
    tail = current;
    return length;
}

/*************************************************************************************************************************** 
** Function: unsigned int insert()
** Description: This function allows the user to insert a value at any index that's added to the parameter. 
** Parameters:int value, unsigned int index 
** Pre-Conditions: The user writes in insert(5,2)
** Post-Conditions: This will add the value 5 to the second index of the list.
*********************************************************************************************************************************/
unsigned int Linked_List::insert(int value, unsigned int index)
{
    Node *current = tail;
    unsigned int count = 1;
    while (count < index)
    {
        current = current->next;
        count++;
    }
    Node *temp = new Node;
    temp->val = value;
    temp->next = current->next;
    temp->previous = current;
    current->next = temp;
    current = temp->next;
    current->previous = temp;
    if (index == 0)
    {
        tail = temp;
    }
    if (index == length - 1)
    {
        head = temp;
    }
    length++;
    return length;
}

/******************************************************************************************************************************************************* 
** Function: void prime()
** Description: This function finds the prime numnbers in a list, and identifies them. 
** Parameters: none. 
** Pre-Conditions: The user has created a list with nodes. 
** Post-Conditions: If the number isn't a product of two smaller natural numbers, it will add them to a counter and identify how many are in the list. 
*******************************************************************************************************************************************************/
void Linked_List::prime()
{ //this prime function was inspired by what was done at programiz.com and their explanation of how to identify a prime number
    int count;
    Node *current = tail;
    while (current != nullptr)
    {
        bool check = true;
        if (current->val <= 0)
        {
            current = current->next;
            continue;
        }
        for (int i = 2; i <= current->val / 2; i++)
        {
            if (current->val % i == 0)
            {
                check = false;
                break;
            }
        }
        if (check == true)
        {
            count++;
        }
        current = current->next;
    }
    std::cout << "There are " << count << " Prime number(s) in your list." << std::endl;
}

/*************************************************************************************************************************** 
** Function: Node* ascend_merge()
** Description: This function will merge the lists that are split and have them sorted in ascending order. 
** Parameters: Node* temp1, Node* temp2 
** Pre-Conditions: The function is called. 
** Post-Conditions: It will merge the split lists back into one, and continues the sorting process until it is in ascending order. 
*********************************************************************************************************************************/
Node *Linked_List::ascend_merge(Node *temp1, Node *temp2)
{
    Node *final = nullptr;      //Baeldung.com helped visualize an idea of how to create this merge function
    if (temp1 == nullptr)
    {                           //A GeeksforGeeks example painted an idea of how to approach it
        return temp2;
    }
    if (temp2 == nullptr)
    {
        return temp1;
    }
    if (temp1->val <= temp2->val)
    {
        final = temp1;
        final->next = ascend_merge(temp1->next, temp2);
    }
    else
    {
        final = temp2;
        final->next = ascend_merge(temp1, temp2->next);
    }
    return (final);
}

/*************************************************************************************************************************** 
** Function: Node* descend_merge()
** Description: This function will merge the lists that are split and have them sorted in descending order. 
** Parameters: Node* temp1, Node* temp2 
** Pre-Conditions: The function is called. 
** Post-Conditions: It will merge the split lists back into one, and continues the sorting process until it is in descending order. 
*********************************************************************************************************************************/
Node *Linked_List::descend_merge(Node *temp1, Node *temp2)
{
    Node *final = nullptr;

    if (temp1 == nullptr)
    {
        return temp2;
    }
    if (temp2 == nullptr)
    {
        return temp1;
    }
    if (temp1->val >= temp2->val)
    {
        final = temp1;
        final->next = descend_merge(temp1->next, temp2);
    }
    else
    {
        final = temp2;
        final->next = descend_merge(temp1, temp2->next);
    }
    return (final);
}

/************************************************************************************************************************************************************************** 
** Function: Linked_List split_list()
** Description:  this function will split the list in half. 
** Parameters: this function will split the list in half, which will be used for sorting. 
** Pre-Conditions: The function is called. 
** Post-Conditions: It will first find the middle, and proceed to split the list from there. 
***************************************************************************************************************************************************************************/
void Linked_List::split_list(Node *current, Node **front, Node **back)
{

    Node *turtle = current;       //The rabbit and turtle idea was inspired from my COE tutors Kyle and Jia, in which we
    Node *rabbit = current->next; //talked about how we could find the middle point by having one Pointer go twice the distance of another one, like the Rabbit and turtle race!
    while (rabbit != nullptr)
    {
        rabbit = rabbit->next;
        if (rabbit != nullptr)
        {
            turtle = turtle->next; //By definition, when the rabbit reaches nullptr, Turtle should be at the middle point!
            rabbit = rabbit->next; //
        }
    }
    *front = current;
    *back = turtle->next;
    turtle->next = nullptr; //Once the middle point has been obtained, we split it by making the turtle->next = nullptr
}

/********************************************************************************************************************************************************************* 
** Function: void sort_ascending()
** Description: This functions sorts the list in order from least to greatest. 
** Parameters: none 
** Pre-Conditions: The function is called. 
** Post-Conditions: It will merge sort the list in ascending order.
*************************************************************************************************************************************************************/
void Linked_List::sort_ascending(Node **ref)
{
    Node *tail = *ref;                           //Similary to the merge functions, Baeldung.com and GeeksforGeeks helped out with creating this function 
    Node *part1;
    Node *part2;

    if ((tail == nullptr) || (tail->next == nullptr))
    {
        return;
    }
    split_list(tail, &part1, &part2);
    sort_ascending(&part1);
    sort_ascending(&part2);
    *ref = ascend_merge(part1, part2);
}

/*************************************************************************************************************************** 
** Function: void sort_descending()
** Description: This functions sorts the list in order from greatest to least. 
** Parameters: none. 
** Pre-Conditions: The function is called. 
** Post-Conditions: It will merge sort the list in descending order.
*********************************************************************************************************************************/
void Linked_List::sort_descending(Node **ref)
{
    Node *tail = *ref;
    Node *part1;
    Node *part2;

    if ((tail == nullptr) || (tail->next == nullptr))
    {
        return;
    }
    split_list(tail, &part1, &part2);
    sort_descending(&part1);
    sort_descending(&part2);

    *ref = descend_merge(part1, part2);
}

//This below was when I attempted to make the entire merge application make usage of the entire list rather than the nodes.
//I wasn't able to implement it properly, and it lead to some issues.

// Linked_List Linked_List::merge(Linked_List a, Linked_List b){

//     Node *front = a.get_tail();
//     Node *back = b.get_tail();
//     front->val;
//     back->val;
//     a.print();
//     b.print();
//     //Linked_List temp;
//     Linked_List temp; //
//     while(front != nullptr && back != nullptr){
//         std::cout << "hi" <<  std::endl;
//         if(front->val < back->val){
//             temp.push_back(front->val);
//             front = front->next;
//         }
//         else{
//             temp.push_back(back->val);
//             back = back->next;
//         }
//     }
//     while(front != nullptr){
//         temp.push_back(front->val);
//         front = front->next;
//     }
//     while(back != nullptr){
//         temp.push_back(back->val);
//         back = back->next;
//     }
//     return temp;
// }