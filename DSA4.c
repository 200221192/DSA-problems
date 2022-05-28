#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int info ;
    struct node *next ;
}nodetype ;

// creating a circular linked list and perform operation of insertion and deletion with differen cases
nodetype* beg(nodetype *tail){
 nodetype *newnode = NULL ;
 int data ;
 newnode = (nodetype*)malloc(sizeof(nodetype));
 if(newnode == NULL){
     printf("memory is not allocated\n");
 }
 else {
     printf("\nenter the data:\n");
     scanf("%d",&data);
     newnode->info = data ;
     newnode->next = NULL ;
     if(tail == NULL){
         tail=newnode ;
         tail->next = newnode ;
     }
     else{
           newnode->next = tail->next ;
           tail->next = newnode ;
         }
 }
    return tail ;
}

nodetype* end(nodetype *tail){
nodetype *newnode = NULL ;
int data ;
 newnode = (nodetype*)malloc(sizeof(nodetype));
 if(newnode == NULL){
     printf("memory is not allocated\n");
 }
 else {
     printf("\nenter the data:\n");
     scanf("%d",&data);
     newnode->info = data ;
     newnode->next = NULL ;
     if(tail == NULL){
         tail=newnode ;
         tail->next = newnode ;
     }
     else{
          newnode->next = tail->next ;
           tail->next = newnode ;
           tail = newnode ;
     }
    return tail ;
}
}

nodetype* position(nodetype *tail , int count ){
    nodetype *newnode = NULL , *temp = NULL ;
    int data , pos , i = 1 ;
    printf("\nenter the position:\n");
    scanf("%d",&pos);
    if(pos > count || pos < 0 ){
        printf("position is not valid\n");
    }

    newnode = (nodetype*)malloc(sizeof(nodetype));
    if(newnode == NULL){
        printf("memory is not allocated\n");
    }
    else {
        printf("enter the data\n");
        scanf("%d",&data);
        newnode->info = data ;
        newnode->next = NULL ;
        if(tail==NULL){
            tail = newnode;
            tail->next = newnode ;
        } 
        temp = tail->next ;
        while(i < pos-1){
           temp = temp->next ;
           i++ ;
        }
        newnode->next = temp->next ;
        temp->next = newnode ;
        temp = newnode ;
    }
    return tail ;
}

nodetype* delbeg(nodetype *tail ){
    nodetype *temp = NULL ;
    temp = tail->next ;
    tail->next = tail->next->next ;
    free(temp);
    return tail;
}

nodetype* delend(nodetype *tail){
    nodetype *temp = NULL , *current = NULL;
    temp = tail->next ;
    while(temp->next != tail->next){
        current = temp ;
        temp = temp->next ;
    }
    current->next = tail->next ;
    tail = current ;
    free(temp);
    return tail ;
}

nodetype* delpos(nodetype *tail){
    nodetype *temp = NULL , *current = NULL ;
    int pos , i = 1 ;
    temp = tail->next ;
    printf("enter the position:\n");
    scanf("%d",&pos);
    while(i < pos-1){
        temp = temp->next ;
        i++ ;
    }
    current = temp->next ;
     temp->next = current->next ;
    free(current);
    return tail ;
}

// main 
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
         newnode->next = newnode  ;
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
     

     // insert a new node at the beginning
     tail = beg(tail);
     printf("\nprintign the elments:\n");
     temp = tail->next ;
     do{
     printf("%d\t",temp->info);
     temp = temp->next ;
     }while(temp != tail->next );

     // insert at the end
     tail=end(tail);
     printf("\nprintign the elments:\n");
     temp = tail->next ;
     do{
     printf("%d\t",temp->info);
     temp = temp->next ;
     count++ ;
     }while(temp != tail->next );
     printf("\ntotal no of node after inserting new node at front and end is %d:\t",count);

     // insert node at position 
     tail = position(tail , count);
     printf("\nprinting the elments:\n");
     temp = tail->next ;
     do{
     printf("%d\t",temp->info);
     temp = temp->next ;
     }while(temp != tail->next );

     // delete from beginning
     tail = delbeg(tail);
     printf("\nprinting the elments:\n");
     temp = tail->next ;
     do{
     printf("%d\t",temp->info);
     temp = temp->next ;
     }while(temp != tail->next );

    // delete from the end
    tail = delend(tail);
    printf("\nprinting the elments:\n");
     temp = tail->next ;
     do{
     printf("%d\t",temp->info);
     temp = temp->next ;
     }while(temp != tail->next );


    // delete from the position 
    tail = delpos(tail);
    printf("\nprinting the elments:\n");
     temp = tail->next ;
     do{
     printf("%d\t",temp->info);
     temp = temp->next ;
     }while(temp != tail->next );

     return 0 ;
}