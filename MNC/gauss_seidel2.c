#include <stdio.h>

/*!
  \brief Método de Gauss-Seidel
  \param SL Ponteiro para o sistema linear
  \param x ponteiro para o vetor solução. Ao iniciar função contém
            valor inicial
  \param tTotal tempo gasto pelo método
  \return código de erro. Um nr positivo indica sucesso e o nr
          de iterações realizadas. Um nr. negativo indica um erro:
          -1 (não converge) -2 (sem solução)
  */
int gaussSeidel(SistLinear_t *SL, real_t *x, double *tTotal)
{

    double sum, aux, diff;
    real_t oldX[SL->n];

    // Preenche o vetor oldX de zeros
    for (int k = 0; k < SL->n; k++)
        oldX[k] = 0.0f;

    int iter = 0;
    *tTotal = timestamp();

    do
    {
        for (int k = 0; k < SL->n; k++)
        {
            aux = SL->A[k][k];
            sum = SL->b[k];

            for (int j = 0; j < SL->n; j++)
            {
                if (k != j)
                    if (j < k)
                        sum -= SL->A[k][j] * x[j];
                    else
                        sum -= SL->A[k][j] * oldX[j];
            }

            x[k] = sum / aux;
        }

        diff = maxDiff(oldX, x, SL->n);

        // Passa x para oldX
        for (int k = 0; k < SL->n; k++)
            oldX[k] = x[k];

        iter++;
    } while ((iter < MAXIT) && (diff > SL->erro));

    *tTotal = timestamp() - *tTotal;

    if ((iter == 50) && (!diagonalDominante(SL)))
        return -1; // Nao converge

    for (int i = 0; i < SL->n; i++)
        if ((isinf(x[i])) || (isnan(x[i])))
            return -2; // Sistema impossivel
    return iter;
}