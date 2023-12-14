/***********************************************************************************************************************************************
** Program: driver.cpp
** Author: Mujtaba Aljabery
** Date: 08/15/2021
** Description: This file commbines the Node and Linked_List class to create an application that allows users to make Linked Lists and sort them. 
** Input: Numbers and characters
** Output: Linked Lists that are sorted. 
**************************************************************************************************************************************************/


#include "linked_list.h"
#include <iostream> 
#include <fstream> 
#include <string> 
#include <string.h> 
#include <stdlib.h> 
using std::string; 


/***************************************************************************************************************************************************************** 
** Function: int main()
** Description:  This function handles the interface and the operation of the enitre program.
** Parameters: none
** Pre-Conditions: The program starts, and it asks the users to add numbers and when to stop.
** Post-Conditions: Once the list is created, it will split it in ascending and descending format, and give them the option to redo it. Otherwise, it will quit. 
*********************************************************************************************************************************************************************/
int main()
{
  Linked_List list; //one way of error handling is make n a string and error check to see if it's a proper number, and use stoi to convert it!
  string c; 
  char choice;
  char option; 
  bool check; 
  do{
  do
  {
    do
    {
      std::cout << "Please add a valid number: " << std::endl;
      std::cin >> c;
      check = false; 
      for(int x = 0; x < c.length(); x++){ 
        if( c[x] > 57 || c[x] < 48){
            check = true; 
        }
        if(c[x] == 45 && x == 0){ 
          check = false; 
        }
      }
    } while(check);

  unsigned int n = stoi(c, nullptr);

    std::cout << "Would you like to add another number?: " << std::endl;
    std::cin >> choice;
    list.push_back(n);
  } while (choice == 'y' || choice == 'Y');

std::cout << "Would you like your list to be assorted in ascending or descending order? Type a for ascending and type d for descending: " << std::endl; 
std::cin >> option; 
if(option == 'a' || option == 'A'){ 
list.sort_ascending(list.reference_node()); 
}
else if(option == 'd' || option == 'D'){
list.sort_descending(list.reference_node()); 
}
  list.print(); 
  list.prime(); 
  list.clear(); 

    std::cout << "Would you like to redo the operation? Enter y for yes and n for no: " << std::endl;
    std::cin >> choice;
  } while(choice == 'y' || choice == 'Y');

   std::cout << "Have a great day!" << std::endl; 
   return 0; 
}

//Here's some code from when I utilized push_front() and insert()
  // for(int x = 0; x < 5; x++){
  //     list.push_front(x);
  //     list.push_back(x);
   // list.insert(5, 2);
  // }
  // list.print_memory();
  // list.print();
  //}