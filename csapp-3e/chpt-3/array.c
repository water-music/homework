/* gcc -O1 -S array.c */
#define M 15
#define NC(n) 4 * n + 1
#define NR(n) 3 * n

void transpose(long A[M][M])
{
    long i, j;
    for (i = 0; i < M; i++)
        for (j = 0; j < i; j++)
        {
            long t = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = t;
        }
}

long sum_col(long n, long A[NR(n)][NC(n)], long j)
{
    long i;
    long result = 0;
    for (i = 0; i < NR(n); i++)
    {
        result += A[i][j];
    }
    return result;
}