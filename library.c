#include <stdio.h>
#include <stdlib.h>
#include "library.h"
#include <string.h>
#include <time.h>

int locate (char word[100]){
  int num = word[0];
  if (num >= 97 && num <= 122) {
    return num % 97;
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
  int i = locate(name);
  return find_song(data[i], name, artist);
}

void print_song(struct song_node *data[27], char artist[100]){
  struct song_node *begin = search_artist(data, artist);
  while (begin != NULL && strcmp(begin->artist, artist) == 0){
  printf("%s: %s\n", begin->artist,begin->name);
    begin = begin->next;
  }
  printf("\n");
}

int locate_letter (char letter){
  if (letter >= 97 && letter <= 122) {
    return letter % 97;
  } else {
    return 26;
  }
}
//needs debugging
void print_letter(struct song_node *data[27], char letter){
  int i = locate_letter(letter);
  print_list(data[i]);
}

//needs debugging
void shuffle(struct song_node *data[27]){
  int i;
  for (i = 0; i < 5; i++){
    srand ( time(NULL) );
    int index = rand() % 27;
    while (data[index] == NULL){
      index = (index + 1) % 27;
    }
    struct song_node *random = random_song(data[index]);
    printf("%s: %s\n", random->artist,random->name);
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
