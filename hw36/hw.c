/* hw.c
 * MIDN GEORGE PRIELIPP
 * Uses a linked list to mess with structs in C*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Node_t 
{
  char data[128]; // size chosen based off of "tips"
  struct Node_t* next;
};
typedef struct Node_t Node;


int get_data(char* word);
void add2front(char* word, Node** root);
void print_if_match(char letter, Node* root);
void free_ll(Node* root);

int main()
{
  printf("Enter the words followed by END:\n");

  Node* root = NULL;

  // read in the list
  char* word;
  while(get_data(word))
  {
    add2front(word, &root);
  }

  // get the user's letter
  printf("What letter? ");
  scanf("\n");
  char l;
  scanf("%c", &l);

  // print the matches
  print_if_match(l, root);

  // free memory
  free_ll(root);

  return 0;
}

int get_data(char* word)
{
  scanf("%s", word);
  if(!strcmp(word, "END"))
  {
    return 0;
  }
  scanf(" ");
  return 1;
}

void add2front(char* word, Node** root)
{
  Node* new = (Node*)malloc(sizeof(Node));
  strcpy(new->data, word); 
  new->next = NULL;

  if(*root != NULL)
    new->next = *root;

  *root = new;
}

void print_if_match(char letter, Node* root)
{
  if(root == NULL)
    return;

  if(root->data[0] == letter)
    printf("%s\n", root->data);

  print_if_match(letter, root->next);
}

void free_ll(Node* root)
{
  if(root == NULL)
    return;

  free_ll(root->next);
  free(root);
}
