/***************************************************************************************************
** Program: node.cpp
** Author: Mujtaba Aljabery
** Date: 08/15/2021
** Description: This file defines the Node constructor, and prepares it for application usage. 
** Input: none. 
** Output: none.
*******************************************************************************************************************/

#include "node.h"

/*************************************************************************************************************************** 
** Function: Node(); 
** Description: This is the constructor of the Node class.  
** Parameters: none. 
** Pre-Conditions: A node is established. 
** Post-Conditions: It sets its value to zero, and its next and previous nodes to being nullptr. 
*********************************************************************************************************************************/
Node::Node(){ 
    val = 0; 
    next = nullptr; 
    previous = nullptr; 
}