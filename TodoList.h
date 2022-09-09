#ifndef TODOLIST_H
#define TODOLIST_H

#include "TodoListInterface.h"

class TodoList : public TodoListInterface {
protected:
  string *array;
public:
  TodoList() {      //CONSTRUCTOR
    array = new string[0];
		// This also needs to be able to read in what is in the file
  }
	
  
//Insert the functions


};

#endif