/*
Normal Tree implementation. Level Order Traversal used.
*/

# include <iostream>
# include <queue>

using namespace std;

struct book {
	int data;
	book* left;
	book* right;
};

typedef book* Book;
void display(Book head);

void insert(Book& head, int num){
	if(!head){
		head=new book;
		head->left=head->right=NULL;
		head->data=num;
		return;
	}
	queue<Book> q;
	q.push(head);
	
	Book temp = new book;
	if(!temp){
		cout<<"No memory";
		return;
	}	
	
	//Settings values to the newly created temp
	temp->right=temp->left=NULL;
	temp->data=num;
	
	while(!q.empty()){
		if(q.front()->left==NULL || q.front()->right==NULL){
			if(q.front()->left==NULL)
				q.front()->left=temp; 
			else
				q.front()->right=temp;
			return;
		}
		else{
			if(q.front()->left)
				q.push(q.front()->left);
			if(q.front()->right)
				q.push(q.front()->right);
			q.pop();
		}
	}
}


void delete_tree(Book& head){
	if(head==NULL)
		return;
	delete_tree(head->left);
	delete_tree(head->right);
	delete(head);
}

void del(Book& head, int number){
	if(!head){
		cout<<"Tree empty";
		return;
	}
	Book root=NULL;
		
	queue<Book> q;
	q.push(head);
	while(!q.empty()){
		if(q.front()->data!=number)
			insert(root,q.front()->data);
		if(q.front()->left)
			q.push(q.front()->left);
		if(q.front()->right)
			q.push(q.front()->right);
		q.pop();
	}
	delete_tree(head);

	cout<<"\n Current tree\n";
	display(root);

	head=root;
}


void display(Book head){
	int val=1, count=0;
	if(!head){
		cout<<"Tree Empty";
		return;
	}
	queue<Book> q;
	q.push(head);
	while(!q.empty()){
		cout<<q.front()->data<<" ";
		if(q.front()->left)
			q.push(q.front()->left);
		if(q.front()->right)
			q.push(q.front()->right);
		q.pop();
		count++;
		if(count==val){
			cout<<"\n";
			val*=2;
			count=0;
		}
	}	
}

main(){
	Book top = NULL;
	int ch,num;
	char choice;
	do{
		cout<<"\n 1. Insert\n 2. Delete\n 3. Display\n 4. Exit";
		cout<<"\n\n Enter choice : ";
		cin>>ch;
		switch(ch){
			case 1: cout<<"\n Enter number : ";
					cin>>num;
					insert(top,num);
					break;
			case 2: cout<<"\n Enter number : ";
					cin>>num;
					del(top,num);
					break;
			case 3: display(top);
					break;
			case 4: return 0;
			default: cout<<"Wrong choice"; 
		}
		cout<<"\n Do you want to continue? (y/n) : ";
		cin>>choice;
	}
	while(choice=='y'||choice=='Y');
}
