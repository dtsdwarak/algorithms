# include <iostream>
# include <algorithm>

using namespace std;

struct node{
	int data;
	node* next;
};

node* head=NULL;

void insert(int data){
	node* temp = new node;
	temp->data=data;
	temp->next=NULL;
	node*i=NULL;
	if(!head){
		head=temp;
		return;
	}
	for(i=head;i->next!=NULL;i=i->next);
	i->next=temp;
}

void reverse(){
	node *temp=NULL, *nextnode=NULL;
	while(head){
		nextnode=head->next;
		head->next=temp;
		temp=head;
		head=nextnode;
	}
	head=temp;
}

void display(){
	for(node*i=head;i!=NULL;i=i->next)
		cout<<i->data<<"-->";
	cout<<"NULL";
}

int main(){
	int ch=1,ch2;
	while(ch>0){
		cout<<"1. insert";
		cout<<"\n2. reverse";
		cout<<"\n3. display";
		cin>>ch2;
		switch(ch2){
			case 1: cout<<"Enter data :";	
					int data;
					cin>>data;
					insert(data);
					break;
			case 2: reverse();
					break;
			case 3: display();
					break;
		}
		cout<<"continue? (1/0) :";
		cin>>ch;
	}
	return 0;
}
