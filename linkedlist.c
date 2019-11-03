#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <string.h>

void print_list(struct song_node * head){
  printf("[ ");
  while (head != NULL){
    printf("%d %d ",head->artist, head->name);
    head = head->next;
  }
  printf("]\n");
}

struct song_node * insert_front(struct song_node * head, char *name, char *artist){
  struct song_node * new;
  new = malloc(sizeof(struct song_node));
  new->next = head;
  new->name = calloc(strlen(name), sizeof(char));
  strcpy(new->name, name);
  new->artist = calloc(strlen(artist), sizeof(char));
  strcpy(new->artist, artist);
  return new;
}

struct song_node * free_list(struct song_node * head){
  struct song_node * previous;
  while (head != NULL){
    previous = head;
    head = head->next;
    free(previous);
  }
  return head;
}

struct song_node * remove_node(struct song_node *front, char *name){
  struct song_node * current = front->next;
  struct song_node * previous = front;
  if (front->name == name){
    free(front);
    return current;
  }
  while (current != NULL){
    if (current->name == name){
      previous->next = current-> next;
      free(current);
      return front;
    }
    previous = current;
    current = current->next;
  }
  return front;
}

/*struct node * insert_order(struct node *front, char *name, char *artist){
  struct node * new = front;
  struct node *after = front->next;
  new = (struct node *)malloc(sizeof(struct node));
  new->name= name;
  new->artist = artist;
  while (strcmp(new->name, after->name)<= 0){
    new = new->next;
    after = new->next;
  }
} */
