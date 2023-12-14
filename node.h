/******************************************************
** Program: node.h
** Author: Mujtaba Aljabery
** Date: 08/15/2021
** Description: This file defines the Node class as well as its functions. 
** Input: none. 
** Output: none. 
******************************************************/


#ifndef NODE_H
#define NODE_H

#include <iostream> 

class Node {
public:
   int val;    // the value that this node stores
   Node *next; // a pointer to the next node in the list
   Node *previous; //a pointer to the previous node in the list

   // you can add constructors or other functionality if you find it useful or necessary

   Node(); 
   Node(int current) : val(current) {}; 

}; 

#endif 