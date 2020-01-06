#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void uppercasespacedot_conversion(char str1[]);







void uppercasespacedot_conversion(char str1[])
{
  unsigned int i = 0;
  while (str1[i] != '\0')
  {
    if(str1[i] >= 'a'&& str1[i] <= 'z')
    {
      str1[i]=str1[i]-32;
    }
    if(str1[i] == ' ')
    {
     str1[i] = str1[i] +  63;
    }
    if(str1[i] == '.')
    {
     str1[i] = str1[i] +  49;
    }
    else
    {
      printf("ERROR\n");

    }

    i++;
  }
}




int main()
{
  unsigned int num;
  char *str;

  printf("Enter the  length of string: ");
  scanf("%d",&num);
  str = (char*) malloc((num+1) * sizeof(char));

  if(str == NULL)
  {
     printf("Error");
     return(-1);
  }

printf("enter the string:");

  fgets(str,(int) num, stdin);
  if (fgets(str,(int) num, stdin) == NULL)
  {
    printf("error 1");
    exit(1);
  }
  uppercasespacedot_conversion(str);


  printf("Modified String is: %s/n",str);
  free(str);
  return 0;
}
