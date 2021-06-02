// Angelo Monte serrat Bonini
// implementação do radix sort

void radix_sort (int a[], int n){
   int baled[10][10], baldeContador[10];
   int i, j, k, r, NOP = 0, divisor = 1, lar, pass;
   lar = get_max (a, n);
   while (lar > 0){
      NOP++;
      lar /= 10;
   }
   for (pass = 0; pass < NOP; pass++){
      for (i = 0; i < 10; i++){
         baldeContador[i] = 0;
      }
      for (i = 0; i < n; i++){
         r = (a[i] / divisor) % 10;
         baled[r][baldeContador[r]] = a[i];
         baldeContador[r] += 1;
      }
      i = 0;
      for (k = 0; k < 10; k++){
         for (j = 0; j < baldeContador[k]; j++){
            a[i] = baled[k][j];
            i++;
         }
      }
      divisor *= 10;
      printf ("After pass %d : ", pass + 1);
      for (i = 0; i < n; i++)
         printf ("%d ", a[i]);
      printf ("\n");
   }
}
