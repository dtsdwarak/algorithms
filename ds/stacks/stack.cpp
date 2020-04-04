# include <iostream>

# define STACK_SIZE 10

using namespace std;

int arr[STACK_SIZE];
int top = -1;

void push (int element) {
  
  if (top == STACK_SIZE) {
      cout<<"Stack full\n";
      return;
  }
  arr[++top] = element;
  cout<<"Element pushed\n"; 
}

int pop() {
  
  if (top < 0) {
    cout<<"Stack empty";
    return -1;
  }
  int value = arr[top--];
  cout<<"Element popped "<<value<<"\n";
  return value;
}

int main() {
  
 int option;
 int element;
 
 while(1) {
  cout<<"\n 1. Push \n 2. Pop  \n 3. Quit? \n\n Enter option : ";
  cin>>option;
  switch(option) {
    case 1: 
             cout<<"Enter element to push : ";
             cin >> element;
             push(element);
             break;
    case 2: pop();
             break;
    case 3: exit(1);
   }
 }
 
}
 
