#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int info ;
    struct node *next ;
    int pos ;
}nodetype;
nodetype* insert(nodetype *tail){
  nodetype *newnode = NULL ;
  int data ;
  static int pos = 0 ;
  newnode = (nodetype*)malloc(sizeof(nodetype));
  if(newnode == NULL){
      printf("memory is not allocated\n");
  }
  else {
      printf("enter the data:\n");
      scanf("%d",&data);
      newnode->info = data ;
      newnode->next = NULL ;
     (newnode->pos) = ++pos ; ;
      if(tail == NULL){
          tail = newnode ;
          tail->next = newnode ;
      }
      else {
          newnode->next = tail->next ;
          tail->next = newnode ;
          tail = newnode ;
      }
  }
  return tail ;
}

void display(nodetype *tail){
    nodetype *temp = NULL ;
    temp = tail->next ;
    printf("printing the linked list:\n");
    do{
        printf("%d\t",temp->info);
        temp = temp->next ;
    }while(temp != tail->next);
}
void taskprocess(nodetype **tail){
    int time  , count = 0 ;
    nodetype *p = *tail ;
    printf("enter the time limit:\n");
    scanf("%d",&time);
    while(p != NULL){
    nodetype *f = p->next ;
    f->info = f->info - time ;
    count++ ;
    if((f->info) <= 0){
        printf("%d is deleted at after %d attemp",f->pos , count);
        delete(&p);
    }
    else{
        p = p->next ;
    }
    }
}
void delete(nodetype **p ){
    nodetype *q = *p , *r = NULL ;
    if(q->next == q){
        free(q);
        *p = NULL ;
        return ;
    }
    r = q->next ;
    q->next = r->next ;
    free(r);
    *p = r ;
}
int main(){
       nodetype *tail = NULL ;
       int data , choice , opt ;
       while(1){
           printf("1.INSERT\n 2.TASK PROCESS\n 3.delete node\n 4.display\n");
           printf("\nenter the option:\n");
           scanf("%d",&opt);
           switch(opt)
           {
               case 1:
               tail = insert(tail);
               break ;
               case 2 :
               display(tail);
               break;
              case 3 :
               taskprocess(&tail);
               break ;
               default :
               printf("unvalid choice:\n");
           }
           printf("\nenter your choice:\n");
           scanf("%d",&choice);
           if(choice != 1)
           break ;
       }
       return 0 ;
}