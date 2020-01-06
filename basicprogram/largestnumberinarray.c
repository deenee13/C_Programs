#include <stdio.h>
#include <stdlib.h>

void user_input (unsigned int num,unsigned int arr[]);
void print_array (unsigned int num, unsigned int arr[]);
unsigned int largest_number(unsigned int num, unsigned int arr[]);





unsigned int largest_number(unsigned int num, unsigned int arr[])
{
  unsigned int largest = 0;
  unsigned int i = 0;
  for (i=0; i<num; i++)
  {
    printf("i=%d arr[i]=%d arr[i+1]=%d\n",i,arr[i],arr[i+1]);
    if(arr[i] >= arr[i+1])
    {
      arr[i+1] = arr[i];
    }
  }
  printf("%d is the largest element in array\n",arr[i] );
  largest = arr[i];
  return (largest);
}


unsigned int smallest_number(unsigned int num, unsigned int arr[])
{
  unsigned int i = 0;
  unsigned int smallest_num = arr[0];

  for (i=1; i<num; i++)
  {
    printf("i=%d : Comparing %d < %d\n",i,arr[i], smallest_num);
    if(arr[i] < smallest_num)
    {
      printf("Found new King %d\n",arr[i]);
      smallest_num = arr[i];
    }
  }
  printf("%d is the smallest element in array\n",smallest_num );
  return (smallest_num);
}

void  user_input (unsigned int num ,unsigned int arr[])
{
  unsigned int i = 0;
  for(i=0 ; i<num ; i++)
  {
    scanf("%d", &arr[i]);
  }
}


void print_array (unsigned int num, unsigned int arr[])
{
  unsigned int i = 0;
  for (i=0 ; i<num ; i++)
  {
    printf(" arr[%d]: %d \n",i,arr[i]);
  }
}

int main ()
{
  unsigned int num = 0;
  unsigned int *ptr;
  printf("Enter the number of elements in array:");
  scanf("%d\n", &num );
  ptr = (unsigned int*) malloc(num * sizeof(unsigned int));
  if(ptr == NULL)
   {
       printf("Error! memory not allocated.");
       return (0);
   }
   user_input(num, ptr);
   print_array(num, ptr);
   //largest_number(num,ptr);
   smallest_number(num,ptr);
   free(ptr);
   return (0);
}
