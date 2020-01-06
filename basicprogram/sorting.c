#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void print_arr(unsigned int num, unsigned int arr[]);
void  userinput (unsigned int num,unsigned int arr[]);
void ascending_order(unsigned int num,unsigned int arr[]);
void descending_order(unsigned int num,unsigned int arr[]);
bool compare_string(char arr1[], char arr2[], unsigned int num);
void user_string (char arr[]);
bool check_numbers(unsigned int a, unsigned int b, int asc_des);
void order(unsigned int num,unsigned int arr[], int asc_desc);





#define LESS_THAN     (13425)
#define GREATER_THAN  (25346365)

bool compare_string(char arr1[], char arr2[], unsigned int num)
{
  unsigned int i = 0;
  for(i = 0; i<num; i++)
  {
    if(arr1[i] != arr2[i])
    {
      return(false);
    }
  }
  return(true);
}

void user_string (char arr[])
{
  printf("enter the order:");
  scanf("%s",arr);
}

bool check_numbers(unsigned int a, unsigned int b, int asc_des)
{
  if(asc_des == LESS_THAN)
  {
    return(a<b);
  }

  if(asc_des == GREATER_THAN)
  {
    return(a>b);
  }
  return false;
}

void order(unsigned int num,unsigned int arr[], int asc_desc)
{
  unsigned int i = 0;
  unsigned int temp = 0;
  unsigned int j =0 ;
  for(i=0; i<num; i++)
  {
    for(j=i+1; j<num; j++)
      {
        if(check_numbers(arr[i], arr[j], asc_desc))
        {
          temp = arr[i];
          arr[i] = arr[j];
          arr[j] = temp;
        }
      }
  }
}

void print_arr(unsigned int num, unsigned int arr[])
{
  unsigned int i =0;
  printf("elements of array are printing...%d  \n",num);
  for(i=0; i<num; i++)
  {
    printf("arr[%d] %d: \n",i,arr[i]);
  }
}

void  userinput (unsigned int num,unsigned int arr[])
{
  unsigned int i = 0 ;
  printf("Enter the elements of the array:\n");
  for (i = 0; i < num; i++)
  {
    scanf("%d", &arr[i]);
  }

}



int main()
{
  bool cmp = false;
  unsigned int *ptr;
  unsigned int num =0;
  char ustr [4] = {0};
  char exp_asc[4] = "asc";
  char exp_dsc[4] = "dsc";
  clock_t start_t;
  clock_t end_t;
  clock_t total_t;
  printf("Enter the size of the arrays:");
  scanf("%d", &num);
//  printf("DEBUG: userinput %d\n",num);
  ptr = (unsigned int*) malloc(num * sizeof(unsigned int));
  if(ptr == NULL)
   {
       printf("Error! memory not allocated.");
       return (0);
   }

  userinput(num, ptr);
  print_arr(num, ptr);

  user_string(ustr);
  cmp = compare_string(exp_asc,ustr,3);
  if(cmp == true)
  {
    printf("asc\n");
    start_t = clock();
    order(num,ptr,GREATER_THAN);
    end_t = clock();
    total_t = (unsigned)(end_t - start_t)*1000;
    printf("total time taken by function : %lu milliseconds\n",total_t);
  }
  else
  {
    printf("error\n");

    cmp = compare_string(exp_dsc,ustr,3);
    if(cmp == true)
    {
      printf("dsc \n");
      start_t = clock();
      order(num,ptr,LESS_THAN);
      end_t = clock();
      total_t = (unsigned)(end_t - start_t)*1000;
      printf("total time taken by function : %lu\n",total_t);
    }
    else
    {
      printf("ERROR user entered a junk");
      free(ptr);
      return(-1);
    }
  }
  print_arr(num,ptr);
  free(ptr);
}
