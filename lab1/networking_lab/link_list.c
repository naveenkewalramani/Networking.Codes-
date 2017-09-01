#include<stdio.h>
#include<stdlib.h>
struct node {
		int data;
		struct node *next;
};
int search(struct node *head,int x,int *count){
		struct node *temp=head;	
		while(temp!=NULL){
			*count++;
			if(temp->data==x)
				return 1;
			else 
				temp=temp->next;
		}
		return 0;
}
			
struct node *delete(struct node *head,int x){
	struct node *temp=head;
	if(temp==NULL){
		printf("there is no element in list to delete \n");	
		return head;
	}
	else if(temp!=NULL&& temp->data==x){
		head=temp->next;
		free(temp);
		return head;
	}
	else {
		while(temp->next->data!=x)
			temp=temp->next;
		struct node *temp1=temp->next;
		temp->next=temp1->next;
		free(temp1);
		return head;
	}
}
		 
struct node *insert_big(struct node *head,int x){
		struct node * temp=(struct node *)malloc(sizeof(struct node));
		temp->data=x;
		temp->next=NULL;
		temp->next=head;
		head=temp;
	//	free(temp);
		return head;
}
struct node *insert(struct node *head,int x)
{
	struct node *temp=head;
	struct node *temp1=(struct node *)malloc(sizeof(struct node));
                temp1->data=x;
                temp1->next=NULL;
	if(head==NULL){
		head=temp1;
		return head;
		}
	else {
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=temp1;
	//	free(temp1);
	return head;
	}
}
void display(struct node *head)
{
	struct node *temp=head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	//free(temp);
	return ;
}
			
int main()
{
	struct node *head=NULL;
	printf("enter how many no. u want in your list\n");
	int n;
	scanf("%d",&n);
	printf("enter the numbers\n");
	int i=0,x;
	for(i=0;i<n;i++){
		scanf("%d",&x);
		head=insert(head,x);
	}
	printf("link list after insertion\n");
	display(head);
	printf("\n");
	printf("if u want to insert at beginning enter 1 else 0\n");
	scanf("%d",&x);
	if(x==1){
		printf("enter what u want to insert\n");
		int u;
		scanf("%d",&u);
		head=insert_big(head,u);
	}
	display(head);
	printf("\n");
	printf("enter the key which u want to delete\n");
	scanf("%d",&x);
	head=delete(head,x);
	printf("here is the  list after deletion");
	display(head);
	printf("\n");	
	printf("enter the element which  u want to search\n");
	scanf("%d",&x);
	int count=0;
	int y=search(head,x,&count);
	if(y==1)
		printf("exist  %d\n",count);
	else 
		printf("not exist");
	return 0;
}

