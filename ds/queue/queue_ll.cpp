# include <iostream>
#include<climits>

using namespace std;

struct Book {
  int no;
  Book* next;
};

Book* front = NULL; 
Book* rear = NULL;

void push(int val) {
  
  Book* book = new Book;
  if (book == NULL) {
     cout<<"\n Queue full";
     return;
  }
  
  book->no = val;
  book->next = NULL;

  if (rear == NULL)
    front = rear = book;
  else {
    rear->next = book;
    rear = book;
  }
  
}

int pop () {
  
  if (front == NULL) {
    cout<<"\b Queue empty";
    return INT_MIN;
  }
  
  int val = front->no;
  Book* pop = front;
  
  if (front == rear) 
    front = rear = NULL;
  else
    front = front->next;
    
  delete pop;
  return val;
}

int main() {
  
  int choice, val;
  while(1) {
    cout<<"\n\n 1. Push \n 2. Pop \n 3. Quit \n Enter choice: ";
    cin>>choice;
    switch(choice) {
      case 1: cout<<"\n Enter number : ";
               cin>>val;
              push(val);
              cout<<"\n Value pushed = "<<val;
              break;
      case 2: val = pop();
              if (val != INT_MIN) cout<<"\n Value popped = "<<val;
              break;
      case 3: exit(1);
    }
  }
  
}
