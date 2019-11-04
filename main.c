#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int main(){
  printf("LINKED LIST TESTS\n");
  printf("====================================\n");

  printf("Testing print_list\n\n");
  struct song_node * list = NULL;
  printf("Printing empty list.\n");
  print_list(list);
  printf("\n");

  printf("Adding songs and artists out of order.\n");
  list = insert_front(list, "Let It Go (Frozen)", "Idina Menzel");
  list = insert_order(list, "I'll Make a Man Out of You (Mulan)", "Donny Osmond");
  list = insert_front(list, "A Spoon Full of Sugar (Mary Poppins)", "Julie Andrews");
  printf("Printing list:\n");
  print_list(list);
  printf("Freeing unordered list.\n");
  list = free_list(list);
  printf("Printing list:\n");
  print_list(list);
  printf("\n");

  printf("Adding songs and artists in order.\n");
  list = insert_order(list, "A Spoon Full of Sugar (Mary Poppins)", "Julie Andrews");
  list = insert_order(list, "Reflection (Mulan)", "Lea Salonga");
  list = insert_order(list, "Let It Go (Frozen)", "Idina Menzel");
  list = insert_order(list, "Bibbidi Bobbidi Boo (Cinderella)", "Verna Felton");
  list = insert_order(list, "Supercalifragilisticexpialidocious (Mary Poppins)", "Julie Andrews");
  list = insert_order(list, "When You Wish Upon A Star (Pinocchio)", "Cliff Edwards");
  list = insert_order(list, "I'll Make a Man Out of You (Mulan)", "Donny Osmond");
  list = insert_order(list, "Part of Your World (The Little Mermaid)", "Jodi Benson");
  list = insert_order(list, "One Jump Ahead (Aladdin)", "Brad Kane");
  list = insert_order(list, "A Whole New World (Aladdin)", "Brad Kane");
  printf("List of songs:\n");
  print_list(list);
  printf("====================================\n");

  printf("Testing songcmp (helper function)\n\n");
  printf("Comparing [Brad Kane - A Whole New World (Aladdin)] to [Idina Menzel - Let It Go (Frozen)]\n");
  printf("[Expected]: -1\n");
  printf("[songcmp]: ");
  printf("%d\n", songcmp(list, "Let it Go (Frozen)", "Idina Menzel"));
  printf("\n");
  printf("Comparing [Idina Menzel - Let It Go (Frozen)] to [Idina Menzel - Let It Go (Frozen)]\n");
  printf("[Expected]: 0\n");
  printf("[songcmp]: ");
  printf("%d\n", songcmp(list->next->next->next->next->next->next->next, "Let It Go (Frozen)", "Idina Menzel"));
  printf("\n");
  printf("Comparing [Verna Felton - Bibbidi Bobbidi Boo (Cinderella)] to [Idina Menzel - Let It Go (Frozen)]\n");
  printf("[Expected]: 1\n");
  printf("[songcmp]: ");
  printf("%d\n", songcmp(list->next->next->next->next->next->next, "Let it Go (Frozen)", "Idina Menzel"));
  printf("====================================\n");

  printf("Testing find_song\n\n");
  printf("Finding [Cliff Edwards - When You Wish Upon A Star (Pinocchio)]\n");
  printf("Printing list:\n");
  print_list(find_song(list, "When You Wish Upon A Star (Pinocchio)", "Cliff Edwards"));
  printf("\n\n");
  printf("Finding [Josh Gad - In Summer (Frozen)]\n");
  printf("Printing list:\n");
  print_list(find_song(list, "In Summer (Frozen)", "Josh Gad"));
  printf("====================================\n");

  printf("Testing first_artist\n\n");
  printf("Finding first song of Brad Kane.\n");
  printf("Printing list:\n");
  print_list(first_artist(list, "Brad Kane"));
  printf("\n");
  printf("Finding first song of Taylor Swift.\n");
  printf("Printing list:\n");
  print_list(first_artist(list, "Taylor Swift"));
  printf("====================================\n");

  printf("Testing random_song\n\n");
  printf("Printing list:\n");
  print_list(random_song(list));
  printf("====================================\n");

  printf("Testing remove_node\n\n");
  printf("Removing node from beginning.\n");
  list = remove_node(list, "A Whole New World (Aladdin)", "Brad Kane");
  printf("\n");
  printf("Removing node from middle.\n");
  list = remove_node(list, "A Spoon Full of Sugar (Mary Poppins)", "Julie Andrews");
  printf("\n");
  printf("Removing node at the end.\n");
  list = remove_node(list, "Bibbidi Bobbidi Bo (Cinderella)", "Verna Felton");
  printf("\n");
  printf("Printing list:\n");
  print_list(list);
  printf("====================================\n");

  printf("Testing free_list\n\n");
  printf("Freeing list.\n");
  list = free_list(list);
  printf("Printing list after free_list:\n");
  print_list(list);
  printf("====================================\n\n");

  printf("MUSIC LIBRARY TESTS\n\n");
  printf("====================================\n");

  struct song_node * table[27];
  for (int i = 0; i < 27; i++) {
    table[i] = NULL;
  }

  add_song(table, "A Spoon Full of Sugar (Mary Poppins)", "Julie Andrews");
  add_song(table, "Reflection (Mulan)", "Lea Salonga");
  add_song(table, "Let It Go (Frozen)", "Idina Menzel");
  add_song(table, "Bibbidi Bobbidi Boo (Cinderella)", "Verna Felton");
  add_song(table, "Supercalifragilisticexpialidocious (Mary Poppins)", "Julie Andrews");
  add_song(table, "When You Wish Upon A Star (Pinocchio)", "Cliff Edwards");
  add_song(table, "I'll Make a Man Out of You (Mulan)", "Donny Osmond");
  add_song(table, "Part of Your World (The Little Mermaid)", "Jodi Benson");
  add_song(table, "One Jump Ahead (Aladdin)", "Brad Kane");
  add_song(table, "A Whole New World (Aladdin)", "Brad Kane");
  print_lib(table);
}
