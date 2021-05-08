# include <iostream>

# define QUEUE_SIZE 10

using namespace std;

int arr[QUEUE_SIZE];

int front=-1, rear=-1;

void enqueue(int& element) {
  
  if(rear >= QUEUE_SIZE) {
    cout<<"Queue full";
    return;
  }

  if (front == -1 && rear == -1)  
    front = rear = 0;
  else
    rear++;
    
  arr[rear] = element;
  cout<<"Element "<<element<<" put in queue";
}

int dequeue() {
  
  if (front>rear || front == -1) {
    cout<<"Queue empty";
    return -1;
  }
  
  int val = arr[front];
  
  if (front == 0 && rear == 0)
    front = rear = -1;
  else
    front++;
  
  cout<<"Dequeue-ing element "<<val;
  return val;
}


int main() {

  while(1) {
    cout<<"\n 1. Enqueue \n 2. Dequeue \n 3. Quit \n Choose option : \n";
    int option;
    cin>>option;
    switch(option) {
      case 1: int element;
              cout<<"Enter value : ";
              cin>>element;
              enqueue(element);
              break;
      case 2: dequeue();
              break;
      case 3: exit(1);
    }
   
 } 
}
