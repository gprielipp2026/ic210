/* takes a file full of ints and sorts them into files even/odd */

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char fn[128];

  printf("Filename? ");
  scanf("%s", fn);

  FILE* file = fopen(fn, "r");

  if(file == NULL)
  {
    printf("File does not exist\n");
    return 1;
  }

  FILE* odd = fopen("odd.txt", "w");
  FILE* even = fopen("even.txt", "w");

  int num;
  while(fscanf(file, " %d ", &num) == 1)
  {
    if(num % 2 == 0)
    {
      fprintf(even, "%d ", num);
    }
    else
    {
      fprintf(odd, "%d ", num);
    }
  }

  fprintf(even, "\n");
  fprintf(odd, "\n");

  fclose(file);
  fclose(odd);
  fclose(even);


  return 0;
}
