
#ifndef stack_h
#define stack_h
#include "node.h"
typedef struct {
	NodePtr top;
	int size;
}Stack;

typedef Stack * StackPtr;
void push(StackPtr s, char value){
	Node *new_node=(NodePtr)malloc(sizeof(Node));
	if(new_node){
		new_node->data=value;
		new_node->nextPtr=s->top;
	  // Left missing for homework
    s->top=new_node;
    s->size++;
	}
}
char pop(StackPtr s){
  if(s->top){
    NodePtr t=s->top;
    char value;
	  t=s->top;
	  value=t->data;
	  // Left missing for homework
    s->top=t->nextPtr;
    s->size--;
	  free (t);
  	return value;
  }
  else return 'E';
}
void pop_all(StackPtr s){
  //printf("Starting pop_all function...\n");
  while(s->size>0) //s->top
    {
     pop(s);
    }
  //printf("pop_all completed with s->size = %d\n\n",s->size);
}
#endif
