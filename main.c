#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "library.h"

int main(){
  printf("====================================\n\n");
  printf("LINKED LIST TESTS\n\n");
  printf("====================================\n");

  printf("Testing print_list\n\n");
  struct song_node * list = NULL;
  printf("Printing empty list.\n");
  print_list(list);
  printf("\n");

  printf("Adding songs and artists out of order:\n");
  list = insert_front(list, "Let It Go (Frozen)", "Idina Menzel");
  list = insert_order(list, "I'll Make a Man Out of You (Mulan)", "Donny Osmond");
  list = insert_front(list, "A Spoon Full of Sugar (Mary Poppins)", "Julie Andrews");
  print_list(list);
  printf("\n");
  printf("Freeing unordered list:\n");
  list = free_list(list);
  printf("\n");
  printf("Printing list:\n");
  print_list(list);
  printf("\n");

  printf("Adding songs and artists in order: \n");
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
  print_list(list);
  printf("====================================\n");

  printf("Testing print_song_node\n\n");
  printf("Printing [Brad Kane - A Whole New World (Aladdin)]\n");
  print_song_node(list);
  printf("\n");
  printf("Printing [Cliff Edwards - When You Wish Upon A Star (Pinocchio)]\n");
  print_song_node(list->next->next);
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
  printf("Finding [Cliff Edwards - When You Wish Upon A Star (Pinocchio)]:\n");
  print_list(find_song(list, "When You Wish Upon A Star (Pinocchio)", "Cliff Edwards"));
  printf("\n\n");
  printf("Finding [Taylor Swift - Blank Space]:\n");
  print_list(find_song(list, "Blank Space", "Taylor Swift"));
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
  list = remove_node(list, "Bibbidi Bobbidi Boo (Cinderella)", "Verna Felton");
  printf("\n");
  printf("Removing node not in the list.\n");
  list = remove_node(list, "Blank Space", "Taylor Swift");
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
  add_song(table, "What's This? (The Nightmare Before Christmas)", "Danny Elfman");
  add_song(table, "Be Our Guest (Beauty and the Beast)", "Jerry Orbach");
  add_song(table, "Can You Feel The Love Tonight? (The Lion King)", "Joseph Williams");
  add_song(table, "Colors of the Wind (Pocahontas)", "Judy Kuhn");
  add_song(table, "Go The Distance (Hercules)", "Roger Bart");
  add_song(table, "You've Got A Friend in Me (Toy Story)", "Randy Newman");
  add_song(table, "Where Are You (Moana)", "Christopher Jackson");

  printf("Testing print_lib\n\n");
  print_lib(table);
  printf("====================================\n");

  printf("Testing search_artist\n\n");
  printf("Searching for Jodi Benson:\n");
  print_list(search_artist(table, "Jodi Benson"));
  printf("\n");
  printf("Searching for Taylor Swift:\n");
  print_list(search_artist(table, "Taylor Swift"));
  printf("====================================\n");

  printf("Testing search_song\n\n");
  printf("Searching for [Brad Kane - A Whole New World (Aladdin)]:\n");
  print_list(search_song(table, "A Whole New World (Aladdin)", "Brad Kane"));
  printf("\n");
  printf("Searching for [Taylor Swift - Blank Space]:\n");
  print_list(search_song(table, "Blank Space", "Taylor Swift"));
  printf("====================================\n");

  printf("Testing print_song\n\n");
  printf("Printing all songs by Julie Andrews:\n");
  print_song(table, "Julie Andrews");
  printf("\n");
  printf("Printing all songs by Lea Salonga:\n");
  print_song(table, "Lea Salonga");
  printf("\n");
  printf("Printing all songs by Taylor Swift:\n");
  print_song(table, "Taylor Swift");
  printf("====================================\n");

  printf("Testing print_letter\n\n");
  printf("B List:\n");
  print_letter(table, 'B');
  printf("\n");
  printf("O List:\n");
  print_letter(table, 'O');
  printf("====================================\n");

  printf("Testing print_artist\n\n");
  printf("Printing songs by Julie Andrews:\n");
  print_artist(table, "Julie Andrews");
  printf("\n");
  printf("Printing songs by Taylor Swift:\n");
  print_artist(table, "Taylor Swift");
  printf("====================================\n");

  printf("Testing shuffle\n\n");
  shuffle(table);
  printf("====================================\n");

  printf("Testing delete_song\n\n");
  delete_song(table, "A Spoon Full of Sugar (Mary Poppins)", "Julie Andrews");
  print_lib(table);
  printf("====================================\n");

  printf("Testing clear_lib\n");
  clear_lib(table);
  print_lib(table);
}
