# include <iostream>
# include <climits>
# define QUEUE_SIZE 4

using namespace std;

int arr[QUEUE_SIZE];
int front=-1, rear=-1;

void enqueue(int e) {
  if (front == rear+1 || (front == 0 && rear == QUEUE_SIZE-1)) {
    cout<<"Queue full";
    return;
  }
  
  if (front == -1) {
    front = rear = 0;
  }
  else if (rear == QUEUE_SIZE-1) {
    rear= 0;
  }
  else 
    rear++;
    
  arr[rear] = e;
  cout<<"\n Value enqueued = "<<e;
}

int dequeue() {
  
  if(front == -1) {
    cout<<"Queue empty";
    return INT_MIN;
  }
  
  int val = arr[front];
  
  if (front == rear) {
    front = rear = -1;
  }
  else if (front == QUEUE_SIZE - 1) {
    front = 0;
  }
  else 
    front++;
  
  cout<<"\n Value dequeued = "<<val;
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
              break;
      case 2: dequeue();
              break;
      case 3: exit(1);
    }
  }
  
}
