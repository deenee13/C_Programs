static bool PLRU[sets][n-1];
void function updatePLRU (int set, int way)
{
  int a = 0;
  int i = 0;
  int k =0;
  for(i=0;i< log2(n); i++)
  {
    PLRU[set][a] = w[i];
    if(w[i] == 0)
    {
      a++;
    }
    else
    {
      a = a + 2;
    }
  }
}
