#include<stdio.h>
#include<stdlib.h>
// creating a doubly linked list and perform insertion and deletion operation on them with different cases 
typedef struct node{
    int info ;
    struct node *next ;
    struct node *prev ;
}nodetype;

// insertion at beginning
nodetype* beg(nodetype *head){
    nodetype *newnode = NULL , *temp = NULL ;
    int data ;
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
            else{
                newnode->next = head ;
                head->prev = newnode ;
                head = newnode ;
            }
            return head ;
}
}

// inserting the  node at end 
nodetype* end(nodetype *head)
{
    nodetype *newnode = NULL , *temp = NULL ;
    int data ;
    newnode = (nodetype*)malloc(sizeof(nodetype));
    if(newnode == NULL){
            printf("no memory is allocated\n");
        }
     else{
    printf("enter the data:\n");
    scanf("%d",&data);
    newnode->info = data ;
    newnode->next = NULL ;
    newnode->prev = NULL ;
    if(head == NULL){
      head = temp = newnode ;
    }
    else{
        temp = head ;
        while(temp->next != NULL){
            temp = temp->next ;
        }
        temp->next = newnode ;
        newnode->prev = temp ;
        temp = newnode ;
    }
    return head ;
}
}

//insert at position
nodetype* position(nodetype *head)
{
    nodetype *newnode = NULL , *temp = NULL ;
    int data , pos , i = 1  ;
    printf("\nenter the position:\n");
    scanf("%d",&pos);
    newnode = (nodetype*)malloc(sizeof(nodetype));
    if(newnode == NULL){
            printf("no memory is allocated\n");
        }
     else{
    printf("enter the data:\n");
    scanf("%d",&data);
    newnode->info = data ;
    newnode->next = NULL ;
    newnode->prev = NULL ;
    if(head == NULL){
      head = temp = newnode ;
    }
    else{
        temp = head ;
        while(i < pos){
            temp = temp->next ;
            i++ ;
        }
        newnode->next = temp->next ;
        temp->next->prev = newnode ;
        newnode->prev = temp;
        temp->next = newnode ;
    }
}
 return head ;
}

// deletion from beginning
nodetype* delbeg(nodetype *head){
    nodetype *temp = NULL;
    if(head == NULL){
        printf("link is empty");
    }
    else{
    temp = head ;
    head = head->next ;
    head->prev = NULL ;
    free(temp);
    }
    return head;
}

// deletion from end 
nodetype* delend(nodetype *head){
    nodetype *temp = NULL , *current = NULL;
    temp = head ;
    while(temp->next != NULL){
        current = temp ;
        temp = temp->next ;
    }
    current = temp ;
    current = current->prev ;
    current->next = NULL ;
    free(temp);
    return head ;
}

// delete from the position
nodetype* delpos(nodetype *head){
    nodetype *temp = head ;
    int pos , i = 1 ;
    printf("enter the position:\n");
    scanf("%d",&pos);
    if(head == NULL){
        printf("nothing to delete");
    }
    while(i < pos){
        temp = temp->next ;
        i++ ;
    }
    temp->next->prev = temp->prev ;
    temp->prev->next = temp->next ;
    free(temp);
    return head ;
}

//main
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

        // insert at front
        head = beg(head);
        printf("printing the elements after inserting node at beginning:\n");
        temp = head ;
        while(temp!= NULL)
        {
            printf("%d\t",temp->info);
            temp = temp->next ;
        }

        //insert at end 
        head = end(head);
        printf("printing the elements after inserting node at end:\n");
        temp = head ;
        while(temp!= NULL)
        {
            printf("%d\t",temp->info);
            temp = temp->next ;
        }

        // insert at position
        head = position(head);
         printf("printing the elements after inserting node at position:\n");
        temp = head ;
        while(temp!= NULL)
        {
            printf("%d\t",temp->info);
            temp = temp->next ;
        }

        // delete at front 
        head = delbeg(head);
         printf("\nprinting the elements after deleting from front:\n");
        temp = head ;
        while(temp!= NULL)
        {
            printf("%d\t",temp->info);
            temp = temp->next ;
        }

        // deletion from end 
        head = delend(head);
        printf("printing the elements after deleting node from end:\n");
        temp = head ;
        while(temp!= NULL)
        {
            printf("%d\t",temp->info);
            temp = temp->next ;
        }

        // delete from pos 
        head = delpos(head);
         printf("printing the elements after deleting node from position:\n");
        temp = head ;
        while(temp!= NULL)
        {
            printf("%d\t",temp->info);
            temp = temp->next ;
        }

        return 0 ;
}