# include <iostream>
#include<climits>

using namespace std;

struct Book {
  int no;
  Book* next;
};

Book* front = NULL; 
Book* rear = NULL;

void enqueue(int val) {
  
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

int dequeue () {
  
  if (front == NULL) {
    cout<<"\b Queue empty";
    return INT_MIN;
  }
  
  int val = front->no;
  Book* dequeue = front;
  
  if (front == rear) 
    front = rear = NULL;
  else
    front = front->next;
    
  delete dequeue;
  return val;
}

int main() {
  
  int choice, val;
  while(1) {
    cout<<"\n\n 1. enqueue \n 2. dequeue \n 3. Quit \n Enter choice: ";
    cin>>choice;
    switch(choice) {
      case 1: cout<<"\n Enter number : ";
               cin>>val;
              enqueue(val);
              cout<<"\n Value enqueued = "<<val;
              break;
      case 2: val = dequeue();
              if (val != INT_MIN) cout<<"\n Value dequeued = "<<val;
              break;
      case 3: exit(1);
    }
  }
  
}
