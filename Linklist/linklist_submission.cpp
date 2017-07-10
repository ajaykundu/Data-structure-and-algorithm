#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct node
{
	int data;
  struct node* next;
};

typedef struct node node;

node* createnewnode(int data,node* next=NULL){
	
	node* newnode=(node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->next=next;
  return newnode;
	
}



void print(node* head)
{
	node* ptr=head;
	while(ptr!= NULL )
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	cout<<endl;
}

int length(node* head)
{
	node* ptr=head;
	int count=0;
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->next;
	}
	return count;
}

void addfront(node **headref,int data){
	node* newnode=createnewnode(data,NULL);
	newnode->next=*headref;
	*headref=newnode;
	
}

void addend(node **headref,int data)
{
	node* newnode=createnewnode(data,NULL);
	node* ptr=*headref;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=newnode;
}



void removefront(node **headref)
{
	*headref=(*headref)->next;
}

void removeEnd(node **headref)
{
	int lengthl=length(*headref);
	node* ptr=*headref;
	for(int i=0;i<lengthl-2;i++)
	{
		ptr=ptr->next;
	}
	ptr->next=NULL;
}


void removeend2(node* &head)
{
  if(head==NULL)
    return;
  if(head->next==NULL)
  {
    head=NULL;
    return;
  }
  while(head->next->next!=NULL)
  {
    head=head->next;
  }
  head->next=NULL;
}


node* Reverse(node *head)
{
  // Complete this method
    node* current=head;
    node* prev=NULL;
    node* nextt;
    
    while(current!=NULL)
        {
          nextt=current->next;
        current->next=prev;
        prev=current;
        current=nextt;
    }
    
    return prev; 
}

node* ReverseRec(node* head,node* prev=NULL)
{     
         if(head->next==NULL)
         {
         	head->next=prev;
         	return head;
         }

     node* temp=head->next;
     head->next=prev;
     prev=head;
     return ReverseRec(temp,prev);
}

void deletebyvalue(node* head,int data)
{
	node* prev=NULL;
    node* ptr=head;
   
	while(ptr->next!=NULL)
	{
		if(ptr->data==data)
		{
		
		prev->next=ptr->next;
			prev=ptr;
		ptr=ptr->next;
		
		}
		else
		{
			prev=ptr;
			ptr=ptr->next;
		}
	}
}

void replacevalue(node* head,int data,int newdata)
{
	node* ptr=head;
	while(ptr->next!=NULL)
	{
		if(ptr->data==data)
		{
			ptr->data=newdata;
		}
		ptr=ptr->next;
	}
}



// node* RemoveDuplicates(node *head)
// {
//   // This is a "method-only" submission. 
//   // You only need to complete this method. 
//     if(head==NULL)
//         {
//         return head;
//     }
    
//     node* final=NULL;

//     while(head!=NULL)
//     {
//     	if(head->data==(head->next)->data)
//     	{
//     		addend(&final,head->data,(head->next))
//     	}
//     }
    
    
// }


void rotateLeft(node* &head,int k)
{
	if(head==NULL)
	{
  return;
	}

	node* prev=NULL;
	node* current=head;
	while(k--)
	{
		prev=current;
		current=current->next;
	}
	while(current->next != NULL)
	{
		current=current->next;
	}
    current->next=head;
    head=prev->next;
    prev->next=NULL;
}

node* sumLinkList(node* l1,node* l2)
{
	node* head=NULL;
	int carry=0;  int sum=0;

	while(l1!=NULL || l2!=NULL || carry!=0)
	{
		sum=carry;
		if(l1!=NULL)
		{
			sum=sum+l1->data;
			l1=l1->next;

		}
		if(l2!= NULL)
		{
			sum=sum+l2->data;
			l2=l2->next;
		}
		if(head==NULL)
		{
			head=createnewnode(sum%10,NULL);
		}
		else
		{
			addend(&head,sum%10);
		}
     //cout<<carry<<" "<<sum<<endl;
		if(sum>9)
		{
			carry=1;
		}
		else
		{
			carry=0;
		}
     sum=0;


	}
	return head;
}



void rightrotation(node* &head,int k)
{
	if(head==NULL)
		return;

	node* slow=head;
	node* fast=head;

	while(k--)
	{
		fast=fast->next;
	}
  while(fast->next !=NULL)
  {
  	fast=fast->next;
  	slow=slow->next;
  }
  fast->next=head;
  head=slow->next;
  slow->next=NULL;
}

// node* createnewnode(int val)
//     {
//     node* newnode=(Node *)malloc(sizeof(Node));
//     newnode->data=val;
//     newnode->next=NULL;
//     return newnode;
// }

void addelement(node ** headref,int val)
    {
           if(*headref==NULL)
               {
               node* newnode=createnewnode(val,NULL);
               *headref=newnode;
               return;
           }
        addelement(&(*headref)->next,val);
    
}

node* MergeLists(node *headA, node* headB)
{
  // This is a "method-only" submission. 
   // You only need to complete this method 
       if(headA==NULL && headB==NULL)
       	return NULL;
       else if(headA==NULL)
       	return headB;
       else if(headB==NULL)
       	return headA;
   node* head=NULL;

   if(headA->data <= headB->data)
   {
   	     head=headA;
   	     headA=headA->next;
   	     head->next=NULL;
   }else {
   	head=headB;
   	headB=headB->next;
   	head->next=NULL;
   }

   print(head);

   node* returnHead=head;

    while(headA!=NULL || headB!=NULL)
    {

    	if(headA!=NULL && headB!=NULL)
    	{
            if(headA->data <= headB->data)
            {
            	node* newnode=createnewnode(headA->data);
            	head->next=newnode;
            	headA=headA->next;
            	head=head->next;
            }
            else
            {
            	node* newnode=createnewnode(headB->data);
            	head->next=newnode;
            	headB=headB->next;
            	head=head->next;
            }
    	}
    	else if(headA!=NULL)
    	{
    		head->next=headA;
    		headA=NULL;
    	}
    	else if(headB!=NULL)
    	{
    		head->next=headB;
    		headB=NULL;
    	}
    }
   return returnHead;
       
}


node* mergeSort(node* head)
{
	if(head->next->next==NULL)
	{
         if(head->data > head->next->data)
         {
         int temp=head->data;
         head->data=head->next->data;
         head->next->data=temp;
     }
         return head;
	}

	node* slowptr=head;
	node* fastptr=head;

	while(fastptr->next!=NULL)
	{
		slowptr=slowptr->next;
		fastptr=fastptr->next;
		if(fastptr->next==NULL){
            break;
		};
		fastptr=fastptr->next;

	}
       node*  l2=mergeSort(slowptr->next); 
	slowptr->next=NULL;
	node* l1=mergeSort(head);
    return MergeLists(l1,l2);

}

node* MergeLists1(node *headA, node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method 
    node* result=NULL;
    if(headA==NULL)
        return headB;
    if(headB==NULL)
        return headA;
    
    if(headA->data <= headB->data)
        {
        result=headA;
        result->next=MergeLists1(headA->next,headB);
    }
    else{
        result=headB;
        result->next=MergeLists1(headA,headB->next);
    }
    return result;
    
    
}

void enqueue(node* &head,node* &tail,int data)
{
  node* newnode=createnewnode(data);
  if(head==NULL && tail==NULL)
  {
     head=newnode;
     tail=newnode;
     return;
  }
  
  tail->next=newnode;
  tail=tail->next;

}

void dequeue(node* &head,node* &tail)
{
  if(head==NULL)
  {
    cout<<"queue is empty."<<endl;
    return;
  }
  node* delnode=head;
  head=head->next;
  if(head==NULL)
    tail=NULL;
  delete delnode;
}

int front(node* head)
{
  if(head==NULL)
  {  
    cout<<"queue is empty."<<endl;
    return -1;
}
   return head->data;
}

node* concate(node* first,node* second)
{
     node* head=NULL;
     node* current=NULL;
      
      if(first==NULL && second==NULL)
      {
        return NULL;
      }

     if(first!=NULL)
      {
            node* newnode=createnewnode(first->data);
            head=newnode;
            current=head;
            first=first->next;

            while(first!=NULL)
            {
                  node* newnode=createnewnode(first->data);
                  current->next=newnode;
                  current=current->next;
                  first=first->next;
            }
      }
     if(current!=NULL)
     {
         while(second!=NULL)
         {
          //cout<<"hello";
              node* newnode=createnewnode(second->data);

              current->next=newnode;
              current=current->next;
              second=second->next;
         }
     }else
     {
           node* newnode=createnewnode(second->data);
           head=newnode;
           current=head;
           second=second->next;
           while(second!=NULL)
           {
               node* newnode=createnewnode(second->data);
               current->next=newnode;
               current=current->next;
               second=second->next;
           }
     }

     return head;
}



int main(int argc, char** argv)
{
   // node* head=NULL;
   // node* tail=NULL;
   // enqueue(head,tail,5);
   // enqueue(head,tail,6);
   // enqueue(head,tail,7);
   // enqueue(head,tail,8);
   // print(head);
   // dequeue(head,tail);
   // dequeue(head,tail);
   // print(head);
   // cout<<front(head)<<endl;
   // dequeue(head,tail);
   // dequeue(head,tail);
   //  dequeue(head,tail);
   // print(head);


   node* list1=NULL;
   node* list2=NULL;
   node* conlist=NULL;

   addfront(&list1,4);
   addfront(&list1,3);
   addfront(&list1,2);
   addfront(&list1,1);

   addfront(&list2,5);
   addfront(&list2,6);
   addfront(&list2,7);
   addfront(&list2,8);

   conlist=concate(list1,list2);
   print(conlist);

}