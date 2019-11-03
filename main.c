#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void main(){
  printf("Empty list:\n");
  struct node * list = NULL;
  print_list(list);
  printf("Adding songs and artists\n");
  list = insert_front(list, "hello", "Wilbert");
  list = insert_front(list, "helloa", "Hilbert");
  list = insert_front(list, "hellob", "Philbert");
  list = insert_front(list, "hellon", "Wilbert");
  printf("Printing list:\n");
  print_list(list);
/*  printf("Removing 9\n");
  list = remove_node(list, 9);
  print_list(list);
  printf("Removing 4\n");
  list = remove_node(list, 4);
  print_list(list);
  printf("Removing 0\n");
  list = remove_node(list, 0);
  print_list(list);
  printf("Removing -1\n");
  list = remove_node(list, -1);
  print_list(list);
  printf("Freeing list\n");
  list = free_list(list);
  printf("Printing list:\n");
  print_list(list); */
}
