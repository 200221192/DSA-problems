#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int info ;
    struct node *next ;
}nodetype;
nodetype* insert(nodetype *head){
    nodetype *newnode = NULL , *temp = NULL ;
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
return head ;
}
void display(nodetype *head){
    nodetype *temp = head ;
    printf("printing the lements of the list:\n");
    while(temp != NULL){
        printf("%d\t",temp->info);
        temp = temp->next ;
    }
}

void find(nodetype *head1 , nodetype *head2){
    nodetype *temp1 = head1 , *temp2 = head2 ;
    while(temp2 != NULL){
        while(temp1 != NULL){
        if((temp1->info ) == temp2->info){
            printf("\nsimilar element is %d",temp1->info);
        }
        temp1 = temp1->next ;
        }
        temp2 = temp2->next ;
    }
}
int main(){
    nodetype *head1 = NULL , *head2 = NULL  ;
    int choice , opt ;
    while(1){
        printf("enter your option:\n");
        scanf("%d",&opt);
        switch(opt){
            case 1:
            printf("creating the first linked list\n");
            head1 = insert(head1);
            break ;
            case 2 :
            printf("creating the second linked list\n");
            head2 = insert(head2);
            break;
            case 3 :
            display(head1);
            break ;
            case 4:
            display(head2);
            break;
            case 5:
            find(head1 , head2);
            break ;
        }
        printf("enter your choice:\n");
        scanf("%d",&choice);
        if(choice != 1)
        break ;
    }
    return 0 ;
}