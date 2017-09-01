#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
	int data;
	struct node *next;
};
struct node *insert(struct node *,int );
struct node *delete(struct node *);
void search(struct node * ,int );
void print(struct node *);
int main()
{
	int value;
	struct node *head;
	head = NULL;
	char str[20];
	scanf("%s",str);
	while(strcmp(str,"exit")!=0){
		if(strcmp(str,"insert")==0){
			scanf("%d",&value);
			head = insert(head,value);
		}else if(strcmp(str,"delete")==0){
			head = delete(head);
		}else if(strcmp(str,"print")==0){
			print(head);
		}else if(strcmp(str,"search")==0){
			scanf("%d",&value);
			search(head,value);
		}
		scanf("%s",str);
	}
	return 0;
}
struct node *insert(struct node *head,int value){
	if(head == NULL){
		head = (struct node *)malloc(sizeof(struct node ));
		head->data = value;
		head->next=NULL;
		return head;
	}
	struct node *tmp;
	tmp = (struct node*)malloc(sizeof(struct node ));
	tmp->data = value;
	tmp->next = head;
	head = tmp;
	return head;
}
struct node *delete(struct node *head){
	if(head == NULL){
		return head;
	}	
	head = head->next;
	return head;
}
void print(struct node *head){
	while(head!=NULL){
		printf("%d ",head->data);
		head = head->next;
	}
	printf("\n");
}
void search(struct node *head,int value){
	if(head==NULL){
		printf("empty list\n");
	}
	int flag=0;
	while(head!=NULL && head->next!=NULL){
		if(head->data==value){
			flag = 1;
			break;
		}
	}
	if(flag==0){
		printf("value not found\n");
	}else{
		printf("value found\n");
	}
}

	
