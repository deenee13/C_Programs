#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 void  frequency_character(char str[],char str1[]);



 void  frequency_character(char str[],char str1[])
 {
   unsigned int k = 0 ;
   unsigned int j =0;
   unsigned int i = 0;
   while (str[i] != '\0')
   {
     if(str[i] == str1[k])
     {
       j++;
     }
     i++;
   }
   printf("frequency of %s is %d\n",str1,j);
 }

int main()
{
  char str1[2] ;
  char *ptr;
  unsigned int num = 0;
  printf("enter the lenght of the string:\n" );
  scanf("%d",&num );

  ptr = (char*) malloc((num+1) * sizeof(char));

  if(ptr == NULL)
  {
    printf("Memory not allocated\n");
    return(-1);
  }

  printf("enter the string:");

  fgets(ptr,(int) num, stdin);

  if( fgets(ptr,(int) num, stdin)== NULL)
  {
    printf("ERROR\n");
    return(-1);
  }
  printf("enter the charcter to find the frequency of:\n" );
  scanf("%s", str1 );
  frequency_character(ptr,str1);
  free(ptr);
  return(0);
  }
