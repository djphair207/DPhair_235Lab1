#ifndef TODOLIST_H
#define TODOLIST_H

#include "TodoListInterface.h"

class TodoList : public TodoListInterface {
protected:
  string *array;
public:
  TodoList() {      //CONSTRUCTOR
    array = new string[0];
  }
  
//Insert the functions


};

#endif