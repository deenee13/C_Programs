#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void read_file (char str[], FILE *fptr);
void write_file (char str[], unsigned int num, FILE *fptr);

void write_file (char str[], unsigned int num, FILE *fptr)
{
  fptr = fopen("/Users/deepen/Desktop/deep.txt", "r");
  if(fptr == NULL)
  {
      printf("Unable to create file.\n");
      exit(1);
  }
  printf("File has opened successfully\n");
  printf("The text from file is:\n");
  while(fgets(str,(int)num,fptr) != NULL)
  {
    printf("%s\n",str);
  }
  fclose(fptr);
}

void read_file (char str[], FILE *fptr)
{
  fptr = fopen("/Users/deepen/Desktop/deep.txt", "w");
  if(fptr == NULL)
  {
      printf("Unable to create file.\n");
      exit(1);
  }
  fputs(str,fptr);
  fclose(fptr);
  printf("file creates and saved successfully:\n");

}

int main ()
{
  char *str;
  unsigned int num;
  FILE *fptr = NULL;
  printf("entert the length of the string:");
  scanf("%d",&num);
  str = (char*) malloc((num+1) * sizeof(char));
  if(str == NULL)
  {
     printf("Error");
     return(-1);
  }

  fgets(str, (int)num, stdin);

  printf("Enter the string to write:\n ");

  if (fgets(str, (int)num, stdin) == NULL)
  {
    printf("error ");
    return(1);
  }
  read_file(str,fptr);
  write_file (str,num,fptr);
  free(str);

}
