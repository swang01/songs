#include <stdio.h>
#include <stdlib.h>
#include "library.h"
#include <string.h>
#include <time.h>

int locate (char word[100]){
  int num = word[0];
  if (num >= 65 && num <= 90) {
    return num % 65;
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
  int i = locate(artist);
  data[i] = insert_order(data[i], name, artist);
}

struct song_node * search_artist (struct song_node *data[27], char artist[100]){
  int i = locate(artist);
  return first_artist(data[i], artist);
}

struct song_node * search_song(struct song_node *data[27], char name[100], char artist[100]){
  int i = locate(artist);
  return find_song(data[i], name, artist);
}

void print_song(struct song_node *data[27], char artist[100]){
  struct song_node *begin = search_artist(data, artist);
  while (begin != NULL && strcmp(begin->artist, artist) == 0){
    print_song_node(begin);
    begin = begin->next;
  }
}

int locate_letter (char letter){
  if (letter >= 65 && letter <= 90) {
    return letter % 65;
  } else {
    return 26;
  }
}

void print_letter(struct song_node *data[27], char letter){
  int i = locate_letter(letter);
  print_list(data[i]);
}

void shuffle(struct song_node *data[27]){
  int i = 0;
  while (i < 3){
    int index = rand() % 27;
    if (data[index] != NULL){
      print_song_node(random_song(data[index]));
      i++;
    }
  }
}

void print_artist(struct song_node *data[27], char artist[100]){
  int i = locate(artist);
  struct song_node *current = data[i];
  int counter = 0;
  while (current != NULL){
    if (strcmp(current->artist, artist) == 0){
      counter += 1;
      print_song_node(current);
    }
    current = current->next;
  }
  if (counter == 0){
    printf("Artist not found.\n");
  }
}

void delete_song(struct song_node *data[27], char name[100], char artist[100]){
  int i = locate(artist);
  data[i] = remove_node(data[i],name,artist);
}

void clear_lib (struct song_node *data[27]){
   for (int i = 0; i < 27; i++) {
     data[i] = free_list(data[i]);
   }
   printf("Library cleared.\n");
 }
