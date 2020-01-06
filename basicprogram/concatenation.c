#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//void strcat_function (char str1[],char str2 []);
void withoutstrcat_function (char str1[],char str2 []);

void withoutstrcat_function (char str1[],char str2 [])
{
  unsigned int i = 0;
  unsigned int j = 0;
  while(str1[i] != '\0')
  {
    i++;

  }
  while(str2[j] != '\0')
  {
    str1[i] = str2[j];
    j++;
    i++;
  }


  printf("concatenated string withour using function is: %s \n",str1);


}


/*void strcat_function (char str1[],char str2 [])
{
  strcat(str1,str2);
  printf("concatenated string: %s\n",str1);
}*/


int main ()
{
  char *ptr1;
  char *ptr2;
  unsigned int num1 = 0;
  unsigned int num2 = 0;

  printf("enter the length of string1: \n");
  scanf("%d",&num1);
  num1++;
  ptr1 = (char*) malloc((num1) * sizeof(char));
  if(ptr1 == NULL)
  {
     printf("Error");
     return(-1);
  }

  printf("enter the length of string2: \n");


  scanf("%d",&num2);
  num2++;

  ptr2 = (char*) malloc((num2) * sizeof(char));

  if(ptr2 == NULL)
  {
     printf("Error");
     return(-1);
  }


  printf("enter the string1 : \n");


  fgets(ptr1,(int)num1, stdin);

  if (fgets(ptr1,(int) num1, stdin) == NULL)
  {
    printf("error 1");
    exit(1);
  }

  printf("enter the string2 : \n");
  fgets(ptr2,(int)num2, stdin);

  if (fgets(ptr2,(int)num2, stdin) == NULL)
  {
    printf("error 1");
    exit(1);
  }

  //strcat_function(ptr1,ptr2);
  withoutstrcat_function(ptr1,ptr2);


  free(ptr1);
  free(ptr2);

  return (0);
}
