#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int info ;
    struct node *next ;
}nodetype;
// creating a linked list and reversing it 
nodetype* reverse(nodetype *head){
    nodetype *current = NULL , *nextnode = NULL , *prev = NULL ;
    nextnode = current = head ;
    while(nextnode != NULL){
       nextnode = nextnode->next ;
        current->next = prev ;
        prev = current ;
        current = nextnode ;
        //nextnode = nextnode->next ;
    }
    head = prev ;
    return head ;
}
int main()
{
 nodetype *head = NULL , *newnode = NULL , *temp = NULL ;
 int data , choice ;
 while(1){
     newnode = (nodetype*)malloc(sizeof(nodetype));
     if(newnode == NULL){
         printf("no memory is allocted\n");
     }
     else{
     printf("\nenter the data\n");
     scanf("%d",&data);
     newnode->info = data ;
     newnode->next = NULL ;
     if(head == NULL){
         head = temp = newnode ;
     }
     else {
         temp->next = newnode ;
         temp = newnode ;
     }
     }
     printf("enter your choice\n");
     scanf("%d",&choice);
     if(choice != 1 )
     break ;
 }
    printf("printing the elements:\n");
    temp = head ;
    while(temp != NULL)
    {
        printf("%d\t",temp->info);
        temp = temp->next ;
    }
    // reversing the string
    head  = reverse(head);
    printf("printing the elements after reersing:\n");
    temp = head ;
    while(temp != NULL)
    {
        printf("%d\t",temp->info);
        temp = temp->next ;
    }
    return 0 ;
}