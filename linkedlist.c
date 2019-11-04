#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <string.h>
#include <time.h>

void print_list(struct song_node * front){
  printf("Printing list:\n");
  if (front == NULL){
    printf("[ ]\n");
  }
  while (front != NULL){
    printf("%s - %s\n",front->artist, front->name);
    front = front->next;
  }
}

struct song_node * insert_front(struct song_node * front, char name[100], char artist[100]){
  struct song_node * new;
  new = malloc(sizeof(struct song_node));
  strcpy(new->name, name);
  strcpy(new->artist, artist);
  new->next = front;
  front = new;
  return front;
}

struct song_node * free_list(struct song_node * head){
  struct song_node * previous;
  while (head != NULL){
    previous = head;
    head = head->next;
    printf("Freeing node: %s - %s\n", previous->artist, previous->name);
    free(previous);
  }
  return head;
}

int songcmp (struct song_node *song, char title[100], char artist[100]) {
  if (strcmp(song->artist, artist) == 0) {
    if (strcmp(song->name, title) == 0){
      return 0;
    } if (strcmp(song->name, title) > 0){
      return 1;
    } else {
      return -1;
    };
  } else {
     if (strcmp(song->artist, artist) > 0){
       return 1;
     } else{
       return -1;
     };
  }
}

struct song_node * remove_node(struct song_node *front, char name[100], char artist[100]){
  if (front == NULL) {
    printf("List is empty.\n");
    return front;
  }

  struct song_node * current;
  current = front;
  if (songcmp(current,name,artist) == 0){
    front = front->next;
    printf("Removing node: %s - %s\n", current->artist, current->name);
    free(current);
    return front;
  }
  current = front->next;
  struct song_node * previous = front;
  while (current != NULL){
    if (songcmp(current,name,artist) == 0){
      previous->next = current-> next;
      printf("Removing node: %s - %s\n", current->artist, current->name);
      free(current);
      return front;
    }
    previous = current;
    current = current->next;
  }
  return front;
}

struct song_node * find_song(struct song_node *front, char name[100], char artist[100]) {
  if (front == NULL){
    printf("List is empty.\n");
    return front;
  }

  while (front != NULL){
    if(songcmp(front, name, artist) == 0){
      return front;
    }
    front = front->next;
  }
  printf("Song not found.\n");
  return NULL;
}

struct song_node * first_artist (struct song_node *front, char artist[100]){
  if (front == NULL){
    printf("List is empty.\n");
    return front;
  }

  while (front != NULL){
    if (strcmp(front->artist, artist) == 0){
      return front;
    }
    front = front->next;
  }
  printf("Artist not found.\n");
  return NULL;
}

struct song_node * random_song (struct song_node *front) {
  struct song_node *head = front;
  int size = 0;
  while (head != NULL) {
    size += 1;
    head = head->next;
  }

  srand( time(NULL) );
  int i = rand() % size;
  for (int p = 0; p < i; p++) {
    front = front->next;
  }
  return front;
}

struct song_node * insert_order(struct song_node *front, char name[100], char artist[100]) {
  if (front == NULL){
    return insert_front(front, name, artist);
  }

  struct song_node *new;
  new = (struct song_node *)malloc(sizeof(struct song_node));
  strcpy(new->name, name);
  strcpy(new->artist, artist);
  struct song_node *current = front;
  struct song_node *after = front->next;
  struct song_node *previous;

  while (current != NULL) {
    int i = songcmp(current, name, artist);
    if (i < 0) {
      previous = current;
      current = after;
      if (after != NULL) {
        after = after->next;
      }
    } else {
      if (current == front) {
        return insert_front(current, name, artist);
      } else {
        previous->next = insert_front(current, name, artist);
        return front;
      }
    }
  } {
    previous->next = insert_front(current, name, artist);
    return front;
  }
  return front;
}
