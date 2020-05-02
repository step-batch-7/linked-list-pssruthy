#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List_ptr create_list(void){
  List_ptr pList = malloc(sizeof(List));
  pList->head = NULL;
  pList->last = NULL;
  pList->count = 0;
  return pList;
}

Node_ptr create_Node(int value){
  Node_ptr node = malloc(sizeof(Node));
  node->value = value;
  node->next = NULL;
  return node;
}

Status add_to_end(List_ptr pList, int value){
  Node_ptr new_node = create_Node(value);
  if(pList->head == NULL){
    pList->head = new_node;
  }else
  {
    pList->last->next = new_node;
  }
  pList->last = new_node;
  pList->count++;
  return Success;
}

void display(List_ptr pList){
  Node_ptr p_walk = pList->head;
  int count = 0;
  while (count != pList->count)
  {
    printf("%d  ", p_walk->value);
    p_walk = p_walk->next;
    count++;
  }
}
