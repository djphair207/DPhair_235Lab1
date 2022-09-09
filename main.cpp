#include <iostream>
#include <string>

#include "TodoList.h"

using namespace std;

int main(int arg1, char *arg2[]) {
  TodoList myList;
	string command = arg2[1];
	
  if(command == "add"){
		myList.add(arg2[2],arg2[3]);
	}
	else if(command == "remove"){
		myList.remove(arg2[2]);
	}
	else if(command == "printList"){
		myList.printTodoList();
	}	
	else if(command == "printDay"){
		myList.printDaysTasks(arg2[2]);
	}
	
  return 0;
}