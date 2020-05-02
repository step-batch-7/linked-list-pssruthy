#include <stdio.h>
#include "list.h"

void print_menu(void);

void print_menu(void){
  printf("\nMain Menu\n");
  printf("---------\n");
  
  printf("(a) add a number to the end of the list\n");
  printf("(l) display the list of numbers\n");
  printf("(m) exit\n\n");

  printf("Please enter the alphabet of the operation you would like to perform : \n");
}

int main(void)
{
  char user_option;
  int number;
  Status status;
  List_ptr pList = create_list();


print_menu();
    scanf(" %c", &user_option);

  while (user_option !='m')
  {
    switch (user_option)
    {
    case 'a':
      printf("Enter a number to add at the end of the list\n");
      scanf("%d", &number);
      status = add_to_end(pList, number);
      if (status)
      {
        printf("Number inserted successfully\n");
      }else
      {
        printf("Insertion failed\n");
      }      
      break;

    case 'l' :
      printf("List of numbers : \n");
      display(pList);
      break;

    default :
      printf("\nPlease enter a valid option \n");
    }
    print_menu();
    scanf(" %c", &user_option);
  }
  return 0;
}