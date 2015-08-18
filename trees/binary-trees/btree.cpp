/*
Normal Tree implementation. Level Order Traversal used.
*/

# include <iostream>
# include <queue>
# include <climits>
# include <algorithm>

using namespace std;

struct book {
	int data;
	book* left;
	book* right;
};

typedef book* Book;
void display(Book head);

int max_element(Book head){
	if(!head){
		return INT_MIN;
	}
	else
		return max(head->data,max(max_element(head->left),max_element(head->right)));
}

//Same procedure without recursion

int max_element(Book head,int val){
	queue<Book> q;
	if(!head){
		return INT_MIN;
	}
	int maxval=INT_MIN;
	q.push(head);
	
	while(!q.empty()){
		if(maxval<q.front()->data)
			maxval=q.front()->data;
		if(q.front()->left)
			q.push(q.front()->left);
		if(q.front()->right)
			q.push(q.front()->right);
		q.pop();
	}
	return maxval;
}

void mirror(Book& head){
	if(!head)
		return;
	mirror(head->left);
	mirror(head->right);
	swap(head->left,head->right);
}

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

void root_to_leaf(Book head, queue<Book> q){
	if(!head->left && !head->right){
		while(!q.empty()){
			cout<<q.front()->data<<" ";
			q.pop();
		}
		cout<<head->data;
		cout<<"\n";
		return;
	}
	q.push(head);
	if(head->left)
		root_to_leaf(head->left,q);
	if(head->right)
		root_to_leaf(head->right,q);
} 

int find_ancestor(Book head, int a, int b){
	if(!head)
		return 0;
	
	if(head->data==a||head->data==b)
		return 1;
		
	int val1=find_ancestor(head->left,a,b), val2=find_ancestor(head->right,a,b);
	if(val1 && val2)
		cout<<"\n Common Ancestor = "<<head->data;
	else
		return (val1 || val2);
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
		cout<<"\n 1. Insert\n 2. Delete\n 3. Display\n 4. Max Element\n 5. Print all paths\n 6. Mirror\n 7. Find Ancestor\n 8. Exit";
		cout<<"\n\n Enter choice : ";
		cin>>ch;
		queue<Book> q;
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
			case 4: cout<<"\n Max element is = "<<max_element(top,0);
					break;
			case 5:	root_to_leaf(top, q);
					break;
			case 6: mirror(top);
					break;
			case 7:	int x,y;
					cout<<"\n Enter number 1: ";
					cin>>x;
					cout<<"\n Enter number 2: ";
					cin>>y;
					find_ancestor(top,x,y);
					break;
			case 8: return 0;
			default: cout<<"Wrong choice"; 
		}
		cout<<"\n Do you want to continue? (y/n) : ";
		cin>>choice;
	}
	while(choice=='y'||choice=='Y');
}
