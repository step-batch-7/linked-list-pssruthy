#include <stdlib.h>
#include "list.h"

List_ptr create_list(void){
  List_ptr pList = malloc(sizeof(List));
  pList->head = NULL;
  pList->last = NULL;
  pList->count = 0;
  return pList;
}
