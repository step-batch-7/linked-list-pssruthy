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

Status add_to_start(List_ptr pList, int value){
  Node_ptr new_node = create_Node(value);
  if(pList->head == NULL){
    pList->head = new_node;
    pList->last = new_node;
  }else
  {
    new_node->next = pList->head;
    pList->head = new_node;
  }
  pList->count++;
  return Success;
}

Status insert_at(List_ptr pList, int value, int position){
  if(position < 0 & position > pList->count) return Failure;
  if (position == 0)
  {
    add_to_start(pList, value);
    return Success;
  } 
  if (position == pList->count)
  {
    add_to_end(pList, value);
    return Success;
  }
  Node_ptr new_node = create_Node(value);
  Node_ptr previous_node = pList->head;
  for (int count = 1; count < position; count++)
  {
   previous_node = previous_node->next;
  }
  new_node->next = previous_node->next;
  previous_node->next = new_node;
  pList->count++;
  return Success;
}

Status add_unique(List_ptr pList, int value){
  Node_ptr p_walk = pList->head;
  for (int count = 1; count < pList->count; count++)
  {
    if(p_walk->value == value) return Failure;  
    p_walk = p_walk->next;
  }
  return add_to_end(pList, value);
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
