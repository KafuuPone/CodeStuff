#include <stdio.h>

void solve(int n);
double* pt_arr(double* arr, int n, int i, int j);
void copymatr(double* arr2d_1, double* arr2d_2, int n);
void submatrix(double* arr_ori, double* subm, int ori_n, int p, int q);
double determinant(double* arr, int n);
void replace_matrix(double* ori_mat, double* const_mat, double* result, int n, int a);

int main(void)
{
    int n;
    printf("Input number of variables: ");
    scanf("%d", &n);

    if(n<=10 && n>0)
        solve(n);
    else
        printf("\nYour input number is not valid or too large to compute.\n");

    return 0;
}

void solve(int n)
{
    printf("\n");

    /*Declare 2 matrices*/
    double arr[n][n], arr_const[n];

    /*Input*/
    int i, j;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            printf("%c%d = ", '`'+i, j);
            scanf("%lf", &arr[i-1][j-1]);
        }
        printf("%c%d = ", '`'+i, n+1);
        scanf("%lf", &arr_const[i-1]);
        printf("\n");
    }

    /*Real solving*/
    double det=determinant(arr, n);
    if(det!=0)
    {
        int i;
        for(i=1; i<=n; i++)
        {
            double repl[n][n];
            replace_matrix(arr, arr_const, repl, n, i);
            printf("x%d = %.3lf\n", i, determinant(repl, n)/det);
        }
    }
    else
        printf("There are either no solutions or infinite solutions for the equations.\n");
}

/*Pointer to an element in 2d array*/
double* pt_arr(double* arr, int n, int i, int j)
{
    return arr+i*n+j;
}

/*Copies 1st matrix to 2nd matrix*/
void copymatr(double* arr2d_1, double* arr2d_2, int n)
{
    int i, j;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            *pt_arr(arr2d_2, n, i, j) = *pt_arr(arr2d_1, n, i, j);
}

/*Note: dimension of subm is 1 less than arr_ori*/
void submatrix(double* arr_ori, double* subm, int ori_n, int p, int q)
{
    int i, j, i_n=0, j_n;
    for(i=0, i_n=0; i<ori_n; i++)
    {
        if(i==p-1)
            continue; /*Skip specified row*/
        for(j=0, j_n=0; j<ori_n; j++)
        {
            if(j==q-1)
                continue; /*Skip specified column*/
            *pt_arr(subm, ori_n-1, i_n, j_n) = *pt_arr(arr_ori, ori_n, i, j);
            j_n++;
        }
        i_n++;
    }
}

double determinant(double* arr, int n)
{
    double output=0;

    if(n==1)
        output = *arr;
    else
    {
        int i;
        for(i=1; i<=n; i++)
        {
            double subm[n-1][n-1];
            submatrix(arr, subm, n, 1, i);
            if(i%2==0)
                output -= (*pt_arr(arr, n, 0, i-1))*determinant(subm, n-1);
            else
                output += (*pt_arr(arr, n, 0, i-1))*determinant(subm, n-1);
        }
    }

    return output;
}

/*Matrix with ath column replaced*/
void replace_matrix(double* ori_mat, double* const_mat, double* result, int n, int a)
{
    copymatr(ori_mat, result, n);
    int i=0;
    for(i=0; i<n; i++)
        *pt_arr(result, n, i, a-1) = *(const_mat+i);
}
