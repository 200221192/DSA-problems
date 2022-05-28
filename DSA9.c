#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int info ;
    struct node *next ;
}nodetype ;
// stack using linked list and print it in reverse order
nodetype* push(nodetype *top){
    nodetype *newnode = NULL ;
    int data ;
    newnode = (nodetype*)malloc(sizeof(nodetype));
    if(newnode == NULL){
        printf("memory not allocated");
    }
    else{
    printf("enter the data:\n");
    scanf("%d",&data);
    newnode->info = data ;
    newnode->next = top ;
    top = newnode ;
    }
    return top ;
}
nodetype* pop(nodetype *top){
  if(top == NULL){
      printf("nothing to delete\n");
  }
  else {
  printf("popped element is %d\t",top->info);
  top = top->next ;
  }
   return top ;
}

void display(nodetype *top){
    nodetype *temp = NULL ;
    temp = top ;
    printf("printing stack:\n");
    while(temp != NULL){
        printf("%d\t",temp->info);
        temp = temp->next ;
    }
}

void peek(nodetype *top){
    printf("peeked element is %d :\t",top->info);
}

void reverse(nodetype *top){
    printf("printing element in reverse order:\n");
    if(top == NULL){
        return ;
    }
    else{
        reverse(top->next);
        printf("%d\t",top->info);
    }
}
int main(){
   nodetype *top = NULL ;
   int data , choice , option ;
   while(1){
       printf("1.PUSH\n 2.POP\n 3.DISPLAY\n 4.PEEK\n");
       printf("enter your option:\n");
       scanf("%d",&option);
       switch(option)
       {
           case 1 :
           top = push(top);
           break ;
           case 2 :
           top = pop(top);
           break ;
           case 3:
           display(top);
           break ;
           case 4 :
           peek(top);
           break ;
           case 5 :
           reverse(top);
           break ;
           default:
           printf("invalid choice\n");
       }
       printf("enter your choice:\n");
       scanf("%d",&choice);
       if(choice != 1 )
       break ;
   }
   return 0 ;
}