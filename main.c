#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "node.h"
#include "stack.h"
int main(int argc, char **argv){
  
  int i,N,j;
  NodePtr *top;
  //top=NULL;
  Stack s;
  s.top=NULL;
  s.size=0;
  char check;
  /*push(&top,5);
  printf("%d\n", pop(&top));
  push(&top,6);
  push(&top,7);
  printf("%d\n", pop(&top));
  printf("%d\n", pop(&top));
  */
  //printf("Checking the parentheses in argv arguments\n");
  if(argc == 1) {
    printf("There is no input!\n");
    return 0;
  }
  for(i=1;i<argc;i++){
  int flag=0;
    for(j=0;j<strlen(argv[i]);j++){
      /* Use stack to help with the parentheses*/
      switch(argv[i][j]){
        case '{' : push(&s, argv[i][j]); break;
        case '[' : push(&s, argv[i][j]); break;
        case '}' : check=pop(&s); if(check!='{') flag=1; break;
        case ']' : check=pop(&s); if(check!='[') flag=1; break;
        default : printf("Incorrect input!"); break;
      }
    }
    if(s.size==0 && flag==0) 
        printf("argv %d: Correct\n",i);
      else if(s.size>0 && flag==0) {
        printf("argv %d: Incorrect: too many open parenthesis\n",i);
        pop_all(&s);
        }
      else if(s.size==0 && check=='E')
        printf("argv %d: Incorrect: too many closed parenthesis\n",i);
      else
        printf("argv %d: Incorrect: mismatch\n",i);
  }
   return 0;
}
