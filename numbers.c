#include <stdio.h>
#include "list.h"

void print_menu(void);

void print_menu(void){
  printf("\nMain Menu\n");
  printf("---------\n");
  
  printf("(m) exit\n");
}
int main(void)
{
  char user_option;
  List_ptr pList = create_list();
  print_menu();
  scanf("%c", &user_option);
  while (user_option != 'm')
  {
    print_menu();
    scanf("%c", &user_option);
  }
  
  return 0;
}