#include <iostream>
#include <string>

#include "TodoList.h"

using namespace std;

int main(int arg1, char *arg2[]) {
  //cout << "Hello World!" << endl;
  TodoList myList;
  //cout << "arg1 = " << arg1 << endl;
	//int length = sizeof(*arg2);
	//for(int i = 0; i < length; i++){
	//	cout << "arg2["<<i<<"] = " << arg2[i] << endl;
	//}
  
	myList.add(arg2[2],arg2[3]);
	myList.remove(arg2[1]);
	myList.printTodoList();
	myList.printDaysTasks(arg2[1]);

  //ifstream fin(TDList.txt);
  

  return 0;
}