#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int info ;
    struct node *next ;
}nodetype ;
// creating a circular linked list and reverse it 

nodetype* reverse(nodetype *tail){
    nodetype *prev = NULL , *current = NULL , *nextnode = NULL ;
    current = tail->next ;
    nextnode = current->next ;
    while(current != tail){
        prev = current ;
        current = nextnode ;
        nextnode = nextnode->next ;
        current->next = prev ;
    }
    nextnode->next = tail ;
    tail = nextnode ;

    return tail;
}
int main(){
 nodetype *tail = NULL , *newnode = NULL , *temp = NULL ;
 int data , choice ,count = 0 ;
 while(1){
     newnode = (nodetype*)malloc(sizeof(nodetype));
     if(newnode == NULL){
         printf("memory is not allocated");
     }
     else {
         printf("enter the data:\n");
         scanf("%d",&data);
         newnode->info = data ;
         newnode->next = NULL  ;
         if(tail == NULL){
             tail=newnode ;
             tail->next = newnode ;
         }
         else {
             newnode->next = tail->next ;
             tail->next = newnode ;
             tail = newnode ;
         }
     }
     printf("enter your choice:\n");
     scanf("%d",&choice);
     if(choice != 1 )
     break ;
 }
     printf("\nprintign the elments:\n");
     temp = tail->next ;
     do{
     printf("%d\t",temp->info);
     temp = temp->next ;
     }while(temp != tail->next );

     tail = reverse(tail);
     printf("\nprintign the elments:\n");
     temp = tail->next ;
     do{
     printf("%d\t",temp->info);
     temp = temp->next ;
     }while(temp != tail->next );
     
     return 0 ;
}