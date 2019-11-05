#include "header.h"

int locate (char word[100]);
void print_lib (struct song_node *data[27]);
void add_song (struct song_node *data[27], char artist[100], char name[100]);
struct song_node * search_artist (struct song_node *data[27], char artist[100]);
struct song_node * search_song(struct song_node *data[27], char name[100], char artist[100]);
void print_song(struct song_node *data[27], char artist[100]);
int locate_letter (char letter);
void print_letter(struct song_node *data[27], char letter);
void shuffle(struct song_node *data[27]);
void delete_song(struct song_node *data[27], char name[100], char artist[100]);
void clear_lib (struct song_node *data[27]);
