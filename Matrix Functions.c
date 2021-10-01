#include <stdio.h>
#include <stdlib.h>

void input(int **matrix, int n) {
    printf("Enter elements of %dx%d matrix : \n", n, n);
    for(int i = 0; i < n; i++) {
        matrix[i] = malloc(sizeof(int*) * n);
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void function(int **matrix, int n) {
    int non_zero_elements = 0;
    int sum_above_leading_diagonal = 0;
    int diag_product = 1;

    printf("\n\nc. Elements below minor diagonal : \n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            
            if(matrix[i][j] != 0)
                non_zero_elements++;

            if(j > i)
                sum_above_leading_diagonal += matrix[i][j];

            if(i == j || (i + j) == (n-1)) {
                diag_product *= matrix[i][j];
            }

            if((i + j) >= n)
                printf("%d ", matrix[i][j]);
            else
                printf("_ ");

        }
        printf("\n");
    }


    printf("\na. No. of non-zero elements : %d.", non_zero_elements);
    printf("\nb. Sum of the elements above the leading diagonal : %d.", sum_above_leading_diagonal);
    printf("\nd. Product of the diagonal elements : %d.", diag_product);
    printf("\n");
}

int main()
{
    int n;
    printf("Enter value of n : ");
    scanf("%d", &n);
    int **matrix = malloc(sizeof(int**) * n);
    input(matrix, n);
    function(matrix, n);
}
