struct song_node {char name[100]; char artist[100]; struct song_node *next; };

void print_list(struct song_node * head);
struct song_node * insert_front(struct song_node * head, char name[100], char artist[100]);
struct song_node * free_list(struct song_node * head);
int songcmp (struct song_node *front, char title[100], char artist[100]);
struct song_node * remove_node(struct song_node *front, char name[100], char artist[100]);
struct song_node * find_song(struct song_node *front, char name[100], char artist[100]);
struct song_node * first_artist (struct song_node *front, char artist[100]);
struct song_node * random_song (struct song_node *front);
struct song_node * insert_order(struct song_node *front, char *name, char *artist);
