/******************************************************
** Program: linked_list.h
** Author: Mujtaba Aljabery
** Date: 08/15/2021
** Description:  This file defines the Linked_List class as well as its functions. 
** Input: none 
** Output: none 
******************************************************/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"
#include <iostream> 
#include <string>
using std::string; 

class Linked_List {         
private:
   unsigned int length; // the number of nodes contained in the list
   Node *head; // a pointer to the first node in the list
   Node *tail; //a pointer to the last node in the list 
   // anything else you need...
public:

    Linked_List(); //This is the constructor

    ~Linked_List(); //This is the destructor

   unsigned int get_length();
   // note: there is no set_length(unsigned int) (the reasoning should be intuitive)

   Node* get_head(); //This is a getter function for the head variable

   void set_head(Node*); //This is a setter function for the head variable

   Node* get_tail() const; //This is a getter function for the tail variable

   Node** reference_node(); //This calls in a Node by reference that will be used for the sorting algorithms

   void set_tail(Node*);  //This is a setter for the the tail variable

   void print_memory(); //This function was made for testing purposes, it prints the memory of a node in the List, as well as the one in front and behind

   void print(); // output a list of all integers contained within the list

   void clear(); // delete the entire list (remove all nodes and reset length to 0)

   unsigned int push_front(int); // insert a new value at the front of the list (returns the new length of the list)

   unsigned int push_back(int); // insert a new value at the back of the list (returns the new length of the list)

   unsigned int insert(int val, unsigned int index); // insert a new value in the list at the specified index (returns the new length of the list)

   void split_list(Node*, Node**, Node**); //This will split the user list into half

   Node* ascend_merge(Node*, Node*); //Sorts the user input nodes in ascending order

   Node* descend_merge(Node*, Node*); //sorts the user input nodes in descending order 

   void sort_ascending(Node**); // sort the nodes in ascending order. You must implement the recursive Merge Sort algorithm

   // Note: it's okay if sort_ascending() calls a recursive private function to perform the sorting.

   void sort_descending(Node**); // sort the nodes in descending order

   void prime();  

   // you can add extra member variables or functions as desired
}; 

#endif