#include <stdio.h>
#include <stdlib.h>
#include "library.h"
#include <string.h>
#include <time.h>

int find_letter (char word[100]){
  int num = word[0];
  if (num >= 65 && num <= 90) {
    return num - 65;
  } else {
    return 26;
  }
}

void print_lib (struct song_node *data[27]){
  for (int i = 0; i < 27; i++) {
    if (data[i] != NULL) {
      if (i < 26) {
        printf("%c List\n", 65+i);
        print_list(data[i]);
      } else {
        printf("Symbols List\n");
        print_list(data[i]);
      }
    }
  }
}

void add_song (struct song_node *data[27], char name[100], char artist[100]){
  int i = find_letter(artist);
  data[i] = insert_order(data[i], name, artist);
}
