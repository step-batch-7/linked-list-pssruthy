#include <stdio.h>
#include "list.h"

void print_menu(void);
void print_status(Status);

void print_menu(void){
  printf("\nMain Menu\n");
  printf("---------\n");
  
  printf("(a) add a number to the end of the list\n");
  printf("(b) add a number to the start of the list\n");
  printf("(c) insert a number at a given position in the list\n");
  printf("(d) add a unique item on the list at the end(if it already exists, do not insert)\n");
  printf("(l) display the list of numbers\n");
  printf("(m) exit\n\n");

  printf("Please enter the alphabet of the operation you would like to perform : ");
}

void print_status(Status status){
  if (status == Success) printf("DONE\n");
  else printf("NOT DONE\n");
}

int main(void)
{
  char user_option;
  int number, position;
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
      print_status(status);
      break;

    case 'b' :
      printf("Enter a number to add at the start of the list\n");
      scanf("%d", &number);
      status = add_to_start(pList, number);
      print_status(status);
      break;

    case 'c' :
      printf("Enter the position to insert : ");
      scanf("%d", &position);
      printf("Enter a number to insert : ");
      scanf("%d", &number);
      status = insert_at(pList, number, position);
      if(status == Success) printf("DONE\n");
      else printf("THE POSITION IS INVALID\n");
      break;

    case 'd' :
      printf("Enter a unique number to insert : ");
      scanf("%d",&number);
      status = add_unique(pList, number);
      if(status == Success) printf("DONE\n");
      else printf("THE NUMBER IS ALREADY PRESENT IN THE LIST\n");
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