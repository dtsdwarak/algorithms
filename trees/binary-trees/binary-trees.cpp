// Implementation Of BINARY TREE OPERATION (insertion & Deletion)

#include<conio.h>
#include<stdio.h>
#include<malloc.h>
#include<process.h>

struct node
{
 struct node *llink;
 struct node *rlink;
 int data;
};

void main()
{
 struct node *head,*t;
 int s,d;
 struct node* finsert();
 struct node* delenode(struct node*,int);
 void insert(struct node *);
 void inorder(struct node *);
 clrscr();
 head=NULL;
 do
 {
  printf("
1-Insertion");
  printf("
2-Deletion");
  printf("
3-Inorder");
  printf("
4-Exit");
  printf("
Enter Choice:");
  scanf("%d",&s);
  switch(s)
  {
   case 1://insertion
     if(head==NULL)
      {
	head=finsert();
      }
     else
	insert(head);
     break;

   case 2://Deletion
     if(head==NULL)
       printf("Binary Tree Empty.......");
     else
     {
       printf("Enter Data to delete:");
       scanf("%d",&d);
       if(head->llink==NULL && head->rlink==NULL && head->data==d)
        {
          t=head;
          head=NULL;
          free(t);
        }
       else
	  head = delenode(head,d);
     }
     break;

   case 3://to display
     printf("
IN-ORDER:");
     if(head==NULL)
      printf("
Binary Tree Empty....");
     else
      inorder(head);
     break;

   case 4://exit
     exit(0);
  }
 }while(s<5 ||s>0);
 getch();
}

struct node* finsert()
{
 struct node * head;
 head=(struct node*)malloc(sizeof(struct node));
 printf("
Enter Data:");
 scanf("%d",&head->data);
 head->llink=NULL;
 head->rlink=NULL;
 return head;
}

void insert(struct node *head)
{
 struct node *t,*n;
 t=head;
 n=(struct node *)malloc(sizeof(struct node));
 printf("
Enter Data:");
 scanf("%d",&n->data);
 n->llink=NULL;
 n->rlink=NULL;
 while(t->llink!=NULL || t->rlink!=NULL)
 {
  if(t->llink!=NULL)
    if(n->data < t->data)
      t=t->llink;
  if(t->rlink!=NULL)
    if(n->data>=t->data)
      t=t->rlink;
  if((t->llink==NULL) && (n->data < t->data) && (n->data < t->rlink->data))
    break;
  if((t->rlink==NULL) && (n->data >= t->data) && (n->data > t->llink->data))
    break;
 }
 if((n->data < t->data) && (t->llink==NULL))
  t->llink=n;
 if((n->data > t->data) && (t->rlink==NULL))
  t->rlink=n;
}

void inorder(struct node * head)
{
 if(head!=NULL)
 {
  inorder(head->llink);
  printf("%d	",head->data);
  inorder(head->rlink);
 }
}

struct node * delenode(struct node *head,int d)
{
 int f=0,f1=0;
 struct node *p,*t,*t1,*x;
 t=head;

 //to search found or not
 while(t!=NULL)
 {
  if(t->data==d)
  {
   f=1;
   x=t;
   break;
  }
  if(t->data > d)
  {
   p=t;
   t=t->llink;
  }
  else if(t->data <= d)
  {
   p=t;
   t=t->rlink;
  }
 }
 if(f==0)
  {
    printf("
Given element not found.......");
    return head;
  }

 //Deleted node has no child
 if(x->llink==NULL && x->rlink==NULL)
 {
  if(p->rlink==x)
    p->rlink=NULL;
  else
    p->llink=NULL;
  free(x);
  return head;
 }

 //deleted node has 2 children
 if(x->llink!=NULL && x->rlink!=NULL)
 {
  p=x;
  t1=x->rlink;
  while(t1->llink!=NULL)
  {
    p=t1; f1=1;
    t1=t1->llink;
  }
  if(t1->llink==NULL && t1->rlink==NULL)
  {
   x->data=t1->data;
   if(f1==1)
     p->llink=t1->llink;
   if(f1==0)
     x->rlink=t1->rlink;
   free(t1);
   return head;
  }
  if(t1->rlink!=NULL)
  {
   x->data=t1->data;
   if(f1==1)
     p->llink=t1->rlink;
   if(f1==0)
     p->rlink=t1->rlink;
   free(t1);
   return head;
  }
 }

 //Deleted node has oniy right child
 if(x->llink==NULL && x->rlink!=NULL && x->data!=head->data)
 {
  if(p->llink==x)
   p->llink=x->rlink;
  else
   p->rlink=x->rlink;
  free(x);
  return head;
 }

 //Deleted node has oniy left child
 if(x->llink!=NULL && x->rlink==NULL && x->data!=head->data)
 {
  if(p->llink==x)
   p->llink=x->llink;
  else
   p->rlink=x->llink;
  free(x);
  return head;
 }
 if(x->llink!=NULL && x->rlink==NULL && x->data==head->data)
 {
  head=x->llink;
  free(p);
  return head;
 }
 if(x->llink==NULL && x->rlink!=NULL && x->data==head->data)
 {
  head=x->rlink;
  free(p);
  return head;
 }
}