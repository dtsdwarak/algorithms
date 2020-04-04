# include <iostream>

using namespace std;

struct Book {
  Book* previous;
};

Book* top = NULL;

void push() {
  
  Book* book = new Book;
  
  if (book == NULL) {
    cout<<"Stack full";
    return;
  }
  book->previous = top;
  top = book;
  cout<<"New element added to stack";
}

void pop() {

  if (top == NULL) {
    cout<<"Stack empty";
    return;
  }

  Book* toDelete = top;
  top = top->previous;
  delete toDelete;
  cout<<"Element deleted";
}

int main() {
  
  while(1) {
   
   int option;
   cout<<"\n1. Push\n 2. Pop \n 3. Quit\n Enter option -";
   cin>>option;
   switch(option) {
    
    case 1: push();
            break;
    case 2: pop();
            break;
    case 3: exit(1);
   }
   
  }
}

