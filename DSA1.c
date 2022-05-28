#include<stdio.h>
#include<stdlib.h>
// creating a singly linked list and perform insertion and deletion with different cases
typedef struct node{
    int data ;
    struct node *next ;
}nodetype ;
// at beginning
nodetype* beg(nodetype *head){
    nodetype *newnode = NULL , *temp = NULL;
    int data ;
    newnode = (nodetype*)malloc(sizeof(nodetype));
     if( newnode == NULL){
            printf("no memory is allocated\n");
        }
        else 
        {
            printf("\n enter the data you want to insert:\n");
            scanf("%d",&data);
            if(head == NULL)
            {
                head =temp= newnode ;
            }
            else{
            newnode->data = data ;
            newnode->next = head ;
            head = newnode ;
        }
        return head ;
}
}

// at end 
nodetype* end(nodetype *head){
    nodetype *newnode = NULL , *temp = NULL ;
    int data ;
    newnode = (nodetype*)malloc(sizeof(nodetype));
    if(newnode == NULL){
        printf("memory not alloctaed\n");
    }
    else {
        printf("\n enter the data:\n");
        scanf("%d",&data);
        newnode->data = data ;
        newnode->next = NULL ;
        temp = head ;
        if(head == NULL){
            head = temp = newnode ;
        }
        else{
        while(temp->next!= NULL){
            temp = temp->next ;
        }
        temp->next = newnode ;
        temp = newnode ;
        }
    }
    return head ;
}

// at the given position
nodetype* position(nodetype *head){
nodetype *newnode = NULL , *temp = NULL ;
int data , pos , i = 1 ;
printf("\nenter the position agter which you want to insert node :\n");
scanf("%d",&pos);
newnode = (nodetype*)malloc(sizeof(nodetype));
if(newnode == NULL){
    printf("memory not allocated\n");
}
else{
    printf("\nenter the data of the newnode:\n");
    scanf("%d",&data);
    newnode->data = data ;
    newnode->next = NULL ;
    temp = head ;
    while(i < pos){
     temp = temp->next;
     i++ ;
    }
    newnode->next = temp->next ;
    temp->next = newnode ;
    temp = newnode ;
}
return head ;
}

// deletion from the beginning
nodetype* delbeg(nodetype *head)
{
    nodetype *temp = NULL ;
    temp = head ;
    head = head->next ;
    free(temp);
    return head ;
}

// deletion from the last 
nodetype* delend(nodetype *head){
    nodetype *temp = NULL , *current = NULL ;
    temp = head ;
    while(temp->next != NULL){
        current = temp ;
        temp = temp->next ;
    }
    free(temp);
    current->next = NULL ;
    return head ;
}

// delete from specified position
nodetype* delpos(nodetype *head){
    nodetype *temp = NULL , *current = NULL ;
    int pos , i = 1 ;
    printf("enter the position from which you want to delete the node :");
    scanf("%d",&pos);
    temp = head ;
    while(i < pos )
    {
        current = temp ;
        temp = temp->next ;
        i++ ;
    }
    current->next = temp->next ;
    free(temp);
    return head ;
}

// main function
int main(){
    nodetype *head = NULL , *newnode = NULL , *temp = NULL ;
    int ch , choice , data ;
    while(1){
        newnode = (nodetype*)malloc(sizeof(nodetype));
        if( newnode == NULL){
            printf("no memory is allocated\n");
           // exit(0);
        }
        else 
        {
            printf("enter the data you want to insert:\n");
            scanf("%d",&data);
            newnode->data = data ;
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
    while(temp != NULL)
    {
        printf("%d\t",temp->data);
        temp = temp->next ;
    }
    // inserting node at the beginning 
    head = beg(head);

    printf("\n printing the elements after inserting node at the beginning:\n");
    temp = head ;
    while(temp != NULL)
    {
        printf("%d\t",temp->data);
        temp = temp->next ;
    }
    // inserting node at the end 
    head = end(head);
    printf("\n printing the elements after inserting node at the end:\n");
    temp = head ;
    while(temp != NULL)
    {
        printf("%d\t",temp->data);
        temp = temp->next ;
    }
    // inserting node at a position
    head = position(head);
    printf("\n printing the elements after inserting node agter the given position:\n");
    temp = head ;
    while(temp != NULL)
    {
        printf("%d\t",temp->data);
        temp = temp->next ;
    }

    // deletion fromn the beginning 
    head = delbeg(head);
    printf("\n\nprinting the elements after deleting the first node:\n");
    temp = head ;
    while(temp != NULL)
    {
        printf("%d\t",temp->data);
        temp = temp->next ;
    }

    // detetion from the end 
    head = delend(head);
    printf("\n\nprinting the elements after deleting the last node:\n");
    temp = head ;
    while(temp != NULL)
    {
        printf("%d\t",temp->data);
        temp = temp->next ;
    }

    // deletion from specified position
    head = delpos(head);
     printf("\n\nprinting the elements after deleting the node from specified position:\n");
    temp = head ;
    while(temp != NULL)
    {
        printf("%d\t",temp->data);
        temp = temp->next ;
    }

    return 0 ;
}