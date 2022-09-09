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
		//cout << "In constructor" << endl;
		ifstream fin("TODOList.txt");
		string line;
		if(fin.is_open()) {
			while(getline(fin,line)) {		
				tasks.push_back(line);
			}
			fin.close();
		}
  }

	virtual ~TodoList() {		//DESTRUCTOR
		//cout << "In destructor" << endl;
		ofstream fout;
		fout.open("TODOList.txt", ofstream::out | ofstream::trunc);
		for(int i = 0; i < tasks.size(); i++) {
			fout << tasks[i] << endl;
		}
		fout.close();
	}

  virtual void add(string _duedate, string _task) {	//ADD FUNC
		//cout << "In add" << endl;
		tasks.push_back(_duedate + " - " + _task);
	}

  virtual int remove(string _task) {	//REMOVE FUNC
		//cout << "In remove" << endl;
		int tasksRemoved = 0;
		for(int i = 0; i < tasks.size(); i++){
			//cout << currentTask << endl;
			if(tasks.at(i).find(_task) != string::npos){
				tasks.erase(tasks.begin() + i);
				tasksRemoved++;
			}
		}
		if(tasksRemoved == 0){
			cout << "No task with that name." << endl;
			return 1;
		}
		return 0;
	}

  virtual void printTodoList(){							//PRINT FULL LIST FUNC
		//cout << "In printList" << endl;
		for(int i = 0; i < tasks.size(); i++) {
			cout << tasks.at(i) << endl;
		}
	}
    
  virtual void printDaysTasks(string _date) {		//PRINT DAY LIST FUNC
		//cout << "In printDayList" << endl;
		int tasksPrinted = 0;
		for(int i = 0; i < tasks.size(); i++){
			if(tasks.at(i).find(_date) != string::npos){
				cout << tasks.at(i) << endl;
				tasksPrinted++;
			}
		}
		if(tasksPrinted == 0){
			cout << "No tasks on that day." << endl;
		}
	}

};

#endif
	