#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int info ;
    struct node *next ;
}nodetype;
// print and find the middle node of the singly linked list
void middle(nodetype *head, int count){
    nodetype *temp = NULL ;
    temp = head ;
    int middle ,middle1 , middle2, pos = 1 , pos1 = 1 , pos2 = 1;
    printf("\nno of nodes = %d",count);
    if(count % 2 != 0){
    middle = (count / 2 ) ;
    while(middle != 0){
        temp = temp->next ;
        middle-- ;
        pos++ ;
    }
    printf("\nmiddle node is lies at %d position and having information %d",pos , temp->info);
    }
    else if(count % 2 == 0 ){
        middle1 = (count / 2) - 1 ;
        middle2 = (count / 2) ;
    temp = head ;
    while(middle1 != 0){
        temp = temp->next ;
        middle1-- ;
        pos1++ ;
    }
     printf("\nmiddle1 node is lies at %d position and having information %d",pos1 , temp->info);
    temp = head ;
    while(middle2 != 0){
        temp = temp->next ;
        middle2-- ;
        pos2++ ;
    }
    printf("\nmiddle2 node is lies at %d position and having information %d",pos2 , temp->info);
     }
}
int main()
{
 nodetype *head = NULL , *newnode = NULL , *temp = NULL ;
 int data , choice , count = 0  ;
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
        count++ ;
        temp = temp->next ;
    }
    // finding middle node of linked list
    middle(head , count);
    return 0 ;

}