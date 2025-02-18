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
  if(position < 0 | position > pList->count) return Failure;
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
  for (int count = 0; count < pList->count; count++)
  {
    if(p_walk->value == value) return Failure;  
    p_walk = p_walk->next;
  }
  return add_to_end(pList, value);
}

Status remove_from_start(List_ptr pList){
  Node_ptr head = pList->head;
  if (pList->count == 0) return Failure;
  if (pList->count == 1) pList->head = pList->last = NULL;
  else pList->head = head->next;

  free(head);
  pList->count--;
  return Success;
}

Status remove_from_end(List_ptr pList){
  Node_ptr last = pList->last;
  Node_ptr p_walk =  pList->head;
  if (pList->count == 0) return Failure;
  if (pList->count == 1) pList->last = pList->head = NULL;
  else {
    for (int count = 1; count < pList->count - 1; count++)
    {
      p_walk = p_walk->next;
    }
    p_walk->next = NULL;  
    pList->last = p_walk;
  }
  free(last);
  pList->count--;
  return Success;
}

Status remove_at(List_ptr pList, int position){
  if (position < 0 | position >= pList->count) return Failure;
  if (position == 0 )
  {
    remove_from_start(pList);
    return Success;
  }
  if (position == pList->count - 1 )
  {
    remove_from_end(pList);
    return Success;
  }
  
  Node_ptr p_walk = pList->head;
  for (int count = 0; count < position - 1; count++)
  {
    p_walk = p_walk->next;
  }
  Node_ptr node_to_remove = p_walk->next;
  p_walk->next = node_to_remove->next;
  pList->count--;
  free(node_to_remove);
  return Success;
}

Status remove_first_occurrence(List_ptr pList, int value){
  Node_ptr p_walk = pList->head;
  int position = 0;
  while (p_walk != NULL)
  {
    if (p_walk->value == value )
    {
      return remove_at(pList, position);
    }
    position++;
    p_walk = p_walk->next;
  }
  return Failure;
}

Status remove_all_occurrences(List_ptr pList, int value){
  Node_ptr p_walk = pList->head;
  int position = 0;
  Status status = Failure;
  while (p_walk != NULL)
  {
    if (p_walk->value == value )
    {
      remove_at(pList, position);
      status = Success;
    }else
    {
      position++;     
    }  
    p_walk = p_walk->next;
  }
  return status;
}

Status clear_list(List_ptr pList){
  Node_ptr p_walk = pList->head;
  while (p_walk != NULL)
  {
    remove_from_start(pList);
    p_walk = p_walk->next;
  }
  return Success;
}

Status is_number_exist(List_ptr pList, int number){
  Node_ptr p_walk = pList->head;
  while (p_walk != NULL)
  {
    if (p_walk->value == number)
    {
      return Success;
    }
    p_walk = p_walk->next;
  }
  
  return Failure;
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

void destroy_list(List_ptr pList){
  clear_list(pList);
  free(pList);
}
