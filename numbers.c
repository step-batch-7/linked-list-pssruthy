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
  printf("(d) add a unique item on the list at the end\n");
  printf("(e) remove a number from the beginning of the list\n");
  printf("(f) remove a number from the end of the list\n");
  printf("(g) remove a number from a given position in the list\n");
  printf("(h) remove first occurrence of a number\n");
  printf("(i) remove all occurrences of a number\n");
  printf("(j) clear the whole list\n");
  printf("(k) check if a number exists in the list\n");
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

    case 'e' :
      status = remove_from_start(pList);
      print_status(status);
      break;

    case 'f' :
      status = remove_from_end(pList);
      print_status(status);
      break;

    case 'g' :
      printf("Enter the position to remove : ");
      scanf("%d", &position);
      status = remove_at(pList, position);
      print_status(status);
      break;

    case 'h' :
      printf("Enter a number to remove first occurrence : ");
      scanf("%d", &number);
      status = remove_first_occurrence(pList, number);
      if(status == Success) printf("DONE\n");
      else printf("THE NUMBER IS NOT PRESENT IN THE LIST\n");
      break;

    case 'i' :
      printf("Enter a number to remove all occurrence : ");
      scanf("%d", &number);
      status = remove_all_occurrences(pList, number);
      if(status == Success) printf("DONE\n");
      else printf("THE NUMBER IS NOT PRESENT IN THE LIST\n");
      break;

    case 'j' :
      status = clear_list(pList);
      print_status(status);
      break;

    case 'k' :
      printf("Enter the number to check the existence : ");
      scanf("%d", &number);
      status = is_number_exist(pList, number);
      if(status == Success) printf("NUMBER EXISTS IN THE LIST");
      else printf("NUMBER NOT EXISTS IN THE LIST");
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
  destroy_list(pList);
  return 0;
}