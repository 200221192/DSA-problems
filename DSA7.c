#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int info ;
    struct node *next , *prev ;
}nodetype ;
// search the element from the doubly linked list and if found delete all nodes comes after that
nodetype* found(nodetype *head){
    nodetype *temp = NULL , *temp2 = NULL , *p = NULL ;
    int num ;
    printf("enter the data:\n");
    scanf("%d",&num);
    temp = head ;
   while((temp->info) != num && temp->next != NULL){
      temp = temp->next;
    }
    if((temp->info) != num && temp->next == NULL){
        printf("KEY NOT FOUND!");
    }
    else{
        temp2 = temp->next ;
        temp->next = NULL ;
         while(temp2 != NULL){
             p = temp2 ;
             temp2 = temp2->next ;
             free(p);
         }
}
 return head ;
}
int main(){
    nodetype *head = NULL , *newnode = NULL , *temp = NULL ;
    int data , choice ;
    while(1){
        newnode = (nodetype*)malloc(sizeof(nodetype));
        if(newnode == NULL){
            printf("no memory is allocated\n");
        }
        else {
            printf("enter the data\n");
            scanf("%d",&data);
            newnode->info = data ;
            newnode->next = NULL ;
            newnode->prev = NULL ;
            if(head == NULL){
                head = temp = newnode ;
            }
            else {
                temp->next = newnode ;
                newnode->prev = temp ;
                temp = newnode ;
            }
        }
            printf("enter your choice:\n");
            scanf("%d",&choice);
            if(choice != 1)
            break ;
    }
        printf("printing the elements:\n");
        temp = head ;
        while(temp!= NULL)
        {
            printf("%d\t",temp->info);
            temp = temp->next ;
        }


        head = found(head);
        printf("printing the elements:\n");
        temp = head ;
        while(temp!= NULL)
        {
            printf("%d\t",temp->info);
            temp = temp->next ;
        }
        return 0 ;
}