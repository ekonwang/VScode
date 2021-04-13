/* 
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */ 
#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);

/* 
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded. 
 */
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, ii, jj, x1, x2, x3, x4, x5, x6, x7, x8;
    
    // optimized for N == 32 && M == 32
    if(M == 32 && N == 32)
    {
        for(ii = 0; ii < N; ii += 8) {
            for(jj = 0; jj < M; jj += 8) {

                for(i = ii; i < (ii + 8); ++i)
				{
					x1 = A[i][j];
					x2 = A[i][j+1];
					x3 = A[i][j+2];
					x4 = A[i][j+3];
					x5 = A[i][j+4];
					x6 = A[i][j+5];
					x7 = A[i][j+6];			
					x8 = A[i][j+7];
					B[j][i] = x1;
					B[j+1][i] = x2;
					B[j+2][i] = x3;
					B[j+3][i] = x4;
					B[j+4][i] = x5;
					B[j+5][i] = x6;
					B[j+6][i] = x7;
					B[j+7][i] = x8;
				}
                
            }
        }
    }

    //optimized for N == 64 && M == 64
    
    
    else if (M == 64 && N == 64)
	{
		for (ii = 0; ii < N; ii += 8)
			for (jj = 0; jj < M; jj += 8)
			{
				for (i = ii; i < ii + 4; ++i)
				{
					x1 = A[i][j]; x2 = A[i][j+1]; x3 = A[i][j+2]; x4 = A[i][j+3];
					x5 = A[i][j+4]; x6 = A[i][j+5]; x7 = A[i][j+6]; x8 = A[i][j+7];
					
					B[j][i] = x1; B[j+1][i] = x2; B[j+2][i] = x3; B[j+3][i] = x4;
					B[j][i+4] = x5; B[j+1][i+4] = x6; B[j+2][i+4] = x7; B[j+3][i+4] = x8;
				}
				for (j = jj; j < jj + 4; ++j)
				{
					x1 = A[i+4][j]; x2 = A[i+5][j]; x3 = A[i+6][j]; x4 = A[i+7][j];
					x5 = B[j][i+4]; x6 = B[j][i+5]; x7 = B[j][i+6]; x8 = B[j][i+7];
					
					B[j][i+4] = x1; B[j][i+5] = x2; B[j][i+6] = x3; B[j][i+7] = x4;
					B[j+4][i] = x5; B[j+4][i+1] = x6; B[j+4][i+2] = x7; B[j+4][i+3] = x8;
				}
				for (i = ii + 4; i < ii + 8; ++i)
				{
					x1 = A[i][j+4]; x2 = A[i][j+5]; x3 = A[i][j+6]; x4 = A[i][j+7];
					B[j+4][i] = x1; B[j+5][i] = x2; B[j+6][i] = x3; B[j+7][i] = x4;
				}
			}
	}
    
    // optimized for N == 67 && M == 61
    else if(M == 61 && N == 67) 
    {
		for (j = 0; j < M / 8 * 8; j += 8)
			for (i = 0; i < N / 8 * 8; ++i)
			{
				x1 = A[i][j];
				x2 = A[i][j+1];
				x3 = A[i][j+2];
				x4 = A[i][j+3];
				x5 = A[i][j+4];
				x6 = A[i][j+5];
				x7 = A[i][j+6];
				x8 = A[i][j+7];
				B[j][i] = x1;
				B[j+1][i] = x2;
				B[j+2][i] = x3;
				B[j+3][i] = x4;
				B[j+4][i] = x5;
				B[j+5][i] = x6;
				B[j+6][i] = x7;
				B[j+7][i] = x8;
			}
		for (i = N / 8 * 8; i < N; ++i)
			for (j = M / 8 * 8; j < M; ++j)
			{
				x1 = A[i][j];
				B[j][i] = x1;
			}
		for (i = 0; i < N; ++i)
			for (j = M / 8 * 8; j < M; ++j)
			{
				x1 = A[i][j];
				B[j][i] = x1;
			}
		for (i = N / 8 * 8; i < N; ++i)
			for (j = 0; j < M; ++j)
			{
				x1 = A[i][j];
				B[j][i] = x1;
			}
    }

}

/* 
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started. 
 */ 

/* 
 * trans - A simple baseline transpose function, not optimized for the cache.
 */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }    

}

/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc); 

    /* Register any additional transpose functions */
    registerTransFunction(trans, trans_desc); 

}

/* 
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; ++j) {
            if (A[i][j] != B[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

