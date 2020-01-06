#include<stdio.h>
#include<string.h>
void strlen_function (char str[]);
void withoutstrlen_function(char str[]);

void withoutstrlen_function(char str[])
{
  unsigned int i = 0 ;
  while(str[i] != '\0')
  {
    i++;
  }
  printf("%d is the length of string\n", i);
}

void strlen_function (char str[])
{
  unsigned  int i = 0;
  i = (unsigned int)strlen(str);
  printf("length of string  is ; %d\n",i);
}


int main ()
{
  char str[25];
  printf("enter the string:");
  scanf("%[^\n]",str);
  for(int i = 0; i<25; i++)
  {
    printf("%c\n",str[i]);
  }
  strlen_function (str);
  withoutstrlen_function (str);

  return(0);

}
