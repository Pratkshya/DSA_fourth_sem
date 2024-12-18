#include <iostream>
using namespace std;

int stack[5], n = 5, top = -1; //initialise the stack with size 5, and top pointer by -1

void push(int x){
  if(top == n-1){ //checks when top == 4(TOS)
    cout<<"Stack is FUll!"<< endl;
  }
  else{
    top++;  //increment the top pointer by 1 to push the element inside stack
    stack[top] = x; //pushes the element into the stack pointed by the top pointer
  }
}

void pop(){
  if(top == -1){
    cout<<"Stack is EMPTY";
  }
  else{
    cout<<"The popped element is: " <<stack[top] <<endl;
    top--;
  }
}
void display(){
  if(top>= 0){
    cout<< "Stack Element/s are" <<endl;
    for(int i =  top; i>=0; i--){ //if top = 4, initialises i = 4, runs till i<=0, after each loop i--
      cout<< stack[i] << endl; //prints the stack elements
    }
  }
  else{
    cout<<"Stack is EMPTY!" <<endl;
  }
}
int main(){
  int choice,value;
   do{
    cout<<"1.PUSH\n2.POP\n3.DISPLAY\n4.Exit" <<endl;
    cout <<" Enter your choice:";

    switch(choice){
      case 1:
         cout << "Enter the value you want to PUSH: ";
         cin >> value;
         push(value);
         break;
      case 2:
         pop();
         break;
      case 3:
         display();
         break;
      case 4:
         cout << "Exiting program..." <<endl;
         return 0;
         break;
      default:
         cout<< "Invalid choice! Try Again." <<endl;   
    }
   }
   while( choice != 4);
  return 0;
}