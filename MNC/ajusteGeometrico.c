void ajusteExponencial(int n, double tabela[][MAX], double *a, double *b, double yAjustado[], double *coefDet) {
   double a0, a1;
   for (int j = 0; j < n; j++)
      tabela[LIN_Y][j] = log(tabela[LIN_Y][j]);

   ajusteReta(n, tabela, &a0, &a1, yAjustado, &(*coefDet));
   // printf("a0: %lf\na1: %lf\n", a0, a1);
   *a = pow(M_E, a0);
   *b = pow(M_E, a1);
}

