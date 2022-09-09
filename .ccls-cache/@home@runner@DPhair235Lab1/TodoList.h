#ifndef TODOLIST_H
#define TODOLIST_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "TodoListInterface.h"

using namespace std;

class TodoList : public TodoListInterface {
protected:
  vector<string> tasks;
public:
  TodoList() {      //CONSTRUCTOR
		cout << "In constructor" << endl;
		ifstream fin("TODOList.txt");
		string line;
		if(fin.is_open()) {
			while(getline(fin,line)) {		
				cout << line << endl;
				tasks.push_back(line);
			}
			fin.close();
		}
		else{
			cout << "File did not open" << endl;
		}
  }

	virtual ~TodoList() {		//DESTRUCTOR
		cout << "In destructor" << endl;
		ofstream fout;
		fout.open("TODOList.txt", ofstream::out | ofstream::trunc);
		
		for(int i = 0; i < tasks.size(); i++) {
			cout << tasks[i] << endl;
			fout << tasks[i] << endl;
		}
		
		fout.close();
		
	}

    /*
    *   Adds an item to the todo list with the data specified by the string "_duedate" and the task specified by "_task"
    */
  virtual void add(string _duedate, string _task) {
		cout << "In add" << endl;
		 tasks.push_back(_duedate + " " + _task);
	}

    /*
    *   Removes an item from the todo list with the specified task name
    *
    *   Returns 1 if it removes an item, 0 otherwise
    */
  virtual int remove(string _task) {
		cout << "In remove" << endl;
		return 0;
	}

    /*
    *   Prints out the full todo list to the console
    */
  virtual void printTodoList(){
		cout << "In printList" << endl;
	}
    
    /*
    *   Prints out all items of a todo list with a particular due date (specified by _duedate)
    */
  virtual void printDaysTasks(string _date) {
		cout << "In printDayList" << endl;
	}
};

#endif
	