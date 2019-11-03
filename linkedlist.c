#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <string.h>

void print_list(struct song_node * head){
  printf("[ ");
  while (head != NULL){
    printf("%s %s | ",head->artist, head->name);
    head = head->next;
  }
  printf("]\n");
}

struct song_node * insert_front(struct song_node * head, char *name, char *artist){
  struct song_node * new;
  new = malloc(sizeof(struct song_node));
  strcpy(new->name, name);
  strcpy(new->artist, artist);
  new->next = head;
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

struct song_node * find_song(struct song_node *n, char *name, char *artist){
  while (n != NULL){
    if((strcmp(n->artist, artist) == 0) && (strcmp(n->name,name)) == 0){
      return n;
    }
    n = n->next;
  }
  return NULL;
}

/*struct song_node * insert_order(struct song_node *n, char *name, char *artist){
  if (n == NULL){
    return insert_front(n, name, artist);
  }
  struct song_node *new;
  struct song_node *current = n;
  struct song_node *after = n->next;
  new = (struct song_node *)malloc(sizeof(struct song_node));
  strcpy(new->name, name);
  strcpy(new->artist, artist);
  while ((after != NULL) && (so){
    if (strcmp(current->artist,artist) > 0){
      if (strcmp(current->name, name) > 0){
        new->next = after;
        current->next = new;
      }
      current = after;
      after = after->next;
    }
    current->next = new;
    return new;
  }
} */
