#include  <stdio.h>
#include <stdlib.h>
void user_input ( unsigned int r1,  unsigned int c1, unsigned int *arr);
void print_array ( unsigned int r1,  unsigned int c1, unsigned int *arr);
void sum_array(unsigned int *arr, unsigned int *arr1, unsigned int r1, unsigned int c1, unsigned int *res);


void sum_array(unsigned int *arr, unsigned int *arr1, unsigned int r1, unsigned int c1, unsigned int *res)
{
  unsigned int i = 0;
  unsigned int j = 0;
  for (i=0; i<r1; i++)
  {
    for (j=0; j<c1; j++)
    {
      *((res)+(i*c1)+j) =  *((arr)+(i*c1)+j) + *((arr1)+(i*c1)+j);
    }
  }

}





void print_array ( unsigned int r1,  unsigned int c1, unsigned int *arr)
{
  unsigned int i = 0;
  unsigned int j = 0;
  for (i = 0; i<r1; i++)
  {
    for (j = 0; j<c1; j++)
    {
        printf(" %d ", *((arr)+(i*c1)+j));
    }
    printf("\n");
  }
}



void user_input ( unsigned int r1, unsigned int c1, unsigned int *arr)
{
  unsigned int i = 0;
  unsigned int j = 0;
  unsigned int mul = 0;
  mul = r1*c1;
  printf("Enter the %d elements in the array: \n",mul);
  for (i=0; i<r1; i++)
  {

    for (j=0; j<c1; j++)
     {
        scanf("%d",((arr)+(i*c1)+j));
     }
  }
 }



int main ()
{
 unsigned int *mat1 ;
 unsigned int *mat2 ;
 unsigned int *res ;
 unsigned int mul = 0;
 unsigned int row1 = 0;
 unsigned int col1 = 0;
 unsigned int mul1 = 0;
 unsigned int row2 = 0;
 unsigned int col2 = 0;



  printf("enter the number of rows in matrice1: \n");
  scanf("%d",&row1);
  printf("enter the number of columns in matrice1: \n ");
  scanf("%d", &col1);
  mul = row1*col1;
  mat1 = (unsigned int *) malloc( mul* sizeof(unsigned int*));
  if(mat1 == NULL)
   {
       printf("Error! memory not allocated.");
       return (0);
   }

  user_input(row1, col1, mat1);
  printf("Matrix 1 : \n");

  print_array (row1, col1, mat1);

  printf("enter the number of rows in matrice2: \n");
  scanf("%d",&row2);

  printf("enter the number of columns in matrice2: \n ");
  scanf("%d", &col2);

  mul1 = row2*col2;

  mat2 = (unsigned int *) malloc( mul1* sizeof(unsigned int*));
  if(mat2 == NULL)
   {
       printf("Error! memory not allocated.");
       return (0);
   }
   user_input(row2, col2, mat2);
   printf("Matrix 2 : \n");
   print_array (row2, col2, mat2);
   res = (unsigned int *) malloc( mul* sizeof(unsigned int*));
   if(mat1 == NULL)
    {
      printf("Error! memory not allocated.");
      return (0);
    }
    sum_array (mat1,mat2,row1,col1,res);
    printf("sum of the two matrices are : \n");
    print_array (row2, col2, res);


   free(mat1);
   free(mat2);
   free(res);
   return (0);

}
