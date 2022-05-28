#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int info ;
    struct node *next ;
}nodetype ;
// creating a singly linked list and split it two parts from the user given position

void split(nodetype *head){
    nodetype *temp = NULL , *a = NULL , *b = NULL ;
    int pos , i = 1 ;
    printf("\nenter the position:\n");
    scanf("%d",&pos);
    temp = head ;
    while(i <= pos-1){
        temp = temp->next ;
        i++ ;
    }
    a = temp->next ;
    b = a ;
    temp->next = NULL ;
    temp = head ;
    printf("\nprinting first list:\n");
    while(temp != NULL){
        printf("%d\t",temp->info);
        temp = temp->next ;
    }

    printf("\nprinting the next list:\n");
    while( b != NULL){
        printf("%d\t",b->info);
        b = b->next ;
    }
}
int main(){
   nodetype *head =NULL , *newnode = NULL , *temp = NULL ;
   int data , choice ;
   while(1){
    newnode = (nodetype*)malloc(sizeof(nodetype));
    if(newnode == NULL){
        printf("memory not allocated\n");
    }
    else {
        printf("enter the data:\n");
        scanf("%d",&data);
        newnode->info = data ;
        newnode->next = NULL ;
        if(head == NULL){
            head = temp = newnode ;
        }
        else{
            temp->next = newnode ;
            temp = newnode ; 
        }
    }
    printf("enter your choice:\n");
    scanf("%d",&choice);
    if(choice != 1)
    break ;
   }
   printf("printing the data:\n");
   temp = head ;
   while(temp != NULL){
       printf("%d\t",temp->info);
       temp = temp->next ;
   }
   // splitting
   split(head);
   return 0 ;
}