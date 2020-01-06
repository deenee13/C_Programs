#include <stdio.h>
#include <stdlib.h>

void  userinput (unsigned int input,unsigned int arr[]);
unsigned int sum_array(unsigned int num_elements, unsigned int arr[]);
void print_arr(unsigned int num_elements, unsigned int arr[]);

void  userinput (unsigned int input,unsigned int arr[])
{
  unsigned int i = 0 ;
  printf("Enter the elements of the array:\n");
  for (i = 0; i < input; i++)
  {
    scanf("%d", &arr[i]);
  }

}

void print_arr(unsigned int num_elements, unsigned int arr[])
{
  printf("Printing Array ... :\n");
  for(unsigned int i = 0; i < num_elements; i++)
  {
    printf("arr[i], %d\n", arr[i]);
  }
}

unsigned int sum_array(unsigned int num_elements, unsigned int arr[])
{
  unsigned int sum = 0;
  unsigned int i = 0;
  for (i=0; i<num_elements; i++)
  {
    sum = sum + arr[i];
  }
  return (sum);
}

int main()
{
  unsigned int *ptr;
  unsigned int size =0;
  printf("Enter the size of the arrays:\n");
  scanf("%d", &size);
  ptr = (unsigned int*) malloc(size * sizeof(unsigned int));
  if(ptr == NULL)
   {
       printf("Error! memory not allocated.");
       return (0);
   }

  userinput(size, ptr);
  print_arr(size, ptr);
  unsigned int sum = sum_array(size,ptr);
  printf("sum is unsigned :%u\n", sum);
  printf("sum is signed :%u\n", sum);

//  unsigned int u_int_var = 0;
  //signed int int_var = 0;
  //printf("%d %d %u %d\n",u_int_var, int_var, u_int_var, int_var);

  //int_var = -1;
  //u_int_var = (unsigned int) int_var;

//  printf("%d %d `%u %u`\n",u_int_var, int_var, u_int_var, int_var);
  free(ptr);
}
