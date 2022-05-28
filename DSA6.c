#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int info ;
    struct node *next ;
}nodetype ;
// printing the largest elments  stored in the nodes
/*nodetype* largest(nodetype *head){
    nodetype *temp = NULL ;
    int value , large = 0  ;
    temp = head ;
    while(temp != NULL){
        value = temp->info ;
        if(value > large){
            large = value;
        }
        temp = temp->next ;
    }
    printf("\nlargest element in the list is %d\t",large);
    return head ;
}*/

/*int count1000(nodetype *head){
    nodetype *temp = NULL ;
    int value , count = 0 ;
    temp = head ;
    while(temp != NULL){
        value = temp->info ;
        if(value > 10000){
            count++ ;
        }
        temp = temp->next ;
}
  return count ;
    //printf("\ntotal nodes having information stored wich is greater than 10000 is %d\t",count);
}*/


// search the element from the singly linked list and if found delete all nodes comes after that
nodetype* found(nodetype *head){
    nodetype *temp = NULL , *temp2 = NULL ,*p = NULL ;
    int num ;
    printf("enter the number that you want to search:\t");
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
        while(temp2->next != NULL){
             p = temp2 ;
            temp2 = temp2->next ;
            free(p);
        }
    }
    return head ;
}

int main(){
 nodetype *head = NULL , *newnode = NULL ,*temp = NULL ;
 int data , choice , count = 0;
 while(1){
     newnode = (nodetype*)malloc(sizeof(nodetype));
     if(newnode == NULL){
         printf("memory is not allocated\n");
     }
     else{
         printf("enter the data:\n");
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
     printf("enter your choice:\n");
     scanf("%d",&choice);
     if(choice != 1)
     break ;
 } 
   printf("printing the elements:\n");
   temp = head ;
   while(temp != NULL){
       printf("%d\t",temp->info);
       temp = temp->next ;
   }
   // find the largest
  // head = largest(head);

   /*count = count1000(head);
   printf("\ntotal nodes having information stored wich is greater than 10000 is %d\t",count);*/
    
   head = found(head);
   printf("\nprinting the elements:\n");
   temp = head ;
   while(temp != NULL){
       printf("%d\t",temp->info);
       temp = temp->next ;
   }

   return 0 ;
}