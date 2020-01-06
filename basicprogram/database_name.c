#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void writename_file (char str[], FILE *fptr);
void concat_string (char str1[], char str2[], char str3[], char str4[]);




void concat_string (char str1[], char str2[], char str3[], char str4[])
{
  FILE *fptr = NULL;
  char *ptr1;
  unsigned int i = 0;
  unsigned int j = 0;
  unsigned int k = 0;
  unsigned int l = 0;
  unsigned int m = 0;
  unsigned int num = 0;
  num = (unsigned int)strlen(str4);
  printf("lenght of name string is %d\n",num);
  ptr1 = (char*) malloc((num+12) * sizeof(char));
  if(ptr1 == NULL)
  {
     printf("Error");
     exit(-1);
  }
  while(str1[i] != '\0')
  {
    ptr1[k] = str1[i];
    i++;
    k++;

  }
  while(str2[j] != '\0')
  {
    ptr1[k] = str2[j];
    j++;
    k++;
  }
  while (str3[l] != '\0')
  {
    ptr1[k] = str3[l];
    l++;
    k++;
  }
  while(str4[m] != '\0')
  {
    ptr1[k] = str4[m];
    m++;
    k++;
  }
  printf("concatenated string is %s",ptr1);
  writename_file (ptr1,  fptr);
}






void writename_file (char str[], FILE *fptr)
{
  fptr = fopen("/Users/deepen/Desktop/database,txt", "a+");
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
  FILE *fptr = NULL;
  unsigned int num = 0;
  char arr_name[255];
  char arr_date[3];
  char arr_month[3];
  char arr_year[5];
  printf("Press 1 to make a new entry\nPress 2 to retrieve an entry\npress 3 to delete an entry\n");
  scanf("%d",&num);
  if( num == 1)
{
  printf("Enter the NAME to enter: \n");
  fgets(arr_name ,255,stdin);
    if (fgets(arr_name, 255, stdin) == NULL)
      {
        printf("error 1");
        exit(1);
      }
   printf("Enter the Date of Birth: \n");
   scanf("%s",arr_date);
   printf("Enter the Month of Birth: \n");
   scanf("%s",arr_month);
   printf("Enter the Year of Birth: \n");
   scanf("%s",arr_year);
   concat_string ( arr_date, arr_month, arr_year, arr_name);
}
  if(num == 2)
   {
    char buffer[255];
    char arrretrieve_name[255];
    printf("Enter the name to Retrieve:\n");
    fgets(arrretrieve_name ,255,stdin);

   if (fgets(arrretrieve_name, 255, stdin) == NULL)
     {
       printf("error 1");
       exit(1);
     }


  fptr = fopen("/Users/deepen/Desktop/database,txt", "r+");
   if(fptr == NULL)
      {
         printf("Unable to create file.\n");
         exit(1);
      }
      printf("File has opened successfully\n");
      while(fgets(buffer,255,fptr) != NULL)
      {
          if(fgets(buffer,255,fptr) == arrretrieve_name)
          {
            printf("%s\n",buffer);
          }
      }

  fclose(fptr);
  printf("file has been closed successfully\n");
 }
}
