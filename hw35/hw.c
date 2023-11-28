/* hw.c
 * MIDN GEORGE PRIELIPP
 * Takes a list input and allows the user to modify the list 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const size_t CMDLEN = 5; // 4 characters and \0

void get_array(int* arraylen, int** array);
void print_array(int arraylen, int* array);
int get_cmd(char** cmd);
void cmd_swap(int* array); // get the two ints to swap
void swap(int* a, int* b);

int main()
{
  // get the array
  int len, *array;
  get_array(&len, &array);

  // for user input
  char* cmd = (char*)malloc(sizeof(char)*CMDLEN);;

  while(get_cmd(&cmd) && strcmp(cmd, "quit") != 0)
  {
    if(!strcmp(cmd, "show"))
    {
      print_array(len, array);
    }
    else if(!strcmp(cmd, "swap"))
    {
      cmd_swap(array);
    }
  }

  // free memory
  free(cmd);
  free(array);

  return 0;
}

void get_array(int* arraylen, int** array)
{
  scanf("N = %d ", arraylen);
  *array = (int*)malloc(sizeof(int)*(*arraylen));

  for(int i = 0; i < *arraylen; i++)
  {
    scanf("%d", &(*array)[i]);
    if(i != *arraylen - 1)
      scanf(" ");
  }
}

void print_array(int arraylen, int* array)
{
  for(int i = 0; i < arraylen; i++)
  {
    printf("[%d] ", i);
    for(int j = 0; j < array[i]; j++)
    {
      printf("*");
    }
    printf("\n");
  }
}

int get_cmd(char** cmd)
{
  printf("cmd: ");
  scanf("%s", *cmd);
  return 1;
}

void cmd_swap(int* array)
{
  // get the two indices
  int ia, ib;
  scanf(" %d %d", &ia, &ib);

  swap(&array[ia], &array[ib]);
}

void swap(int* a, int* b)
{
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

