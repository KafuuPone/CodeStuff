#include <stdio.h>
#define N 2 //number of decimals to display

//Basic input-output
void input_mat(float* mat, int row, int col);
void print_mat(const float* mat, int row, int col);
//Determine leftmost non-zero col and row
int left_nonz_col(const float* mat, int row, int col, int toprow);
int left_nonz_row(const float* mat, int row, int col, int toprow);
//Elementary operations
void swaprow(float* mat, int row, int col, int n_row1, int n_row2);
void linecomb(float* mat, int row, int col, float k, int n_row_k, int n_row);
//Basic Gaussian operation for one row
void basic_gauss(float* mat, int row, int col, int toprow);
//Gaussian elimination
void gauss(float* mat, int row, int col);
//Check if no solutions
bool sol_check(const float* mat, int row, int col);
//Convert to reduced form
void reduce(float* mat, int row, int col);
//Interpret as output
void interpret(const float* mat, int row, int col);

int main(void)
{
    int n_var, n_eqn;
    printf("Number of variables: "); scanf("%d", &n_var);
    printf("Number of equations: "); scanf("%d", &n_eqn);

    float aug[(n_eqn+1)*(n_var+2)]; //0 indexed row and col are not used, replaced with 0
    input_mat(aug, n_eqn+1, n_var+2);

    //Testing
    printf("Input: \n");
    print_mat(aug, n_eqn+1, n_var+2);

    printf("Gaussian elimination: \n");
    gauss(aug, n_eqn+1, n_var+2);
    print_mat(aug, n_eqn+1, n_var+2);

    //Check if there are solutions
    if(sol_check(aug, n_eqn+1, n_var+2)) {
        printf("Reduced form: \n");
        reduce(aug, n_eqn+1, n_var+2);
        print_mat(aug, n_eqn+1, n_var+2);

        printf("Solutions: \n");
        interpret(aug, n_eqn+1, n_var+2);
    }
    else
        printf("There are no solutions.");

    return 0;
}

//row = total num of rows, col = total num of cols, including the 0s
void input_mat(float* mat, int row, int col)
{
    int i, j;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            if(i==0 || j==0)
                *(mat+i*col+j) = 0;
            else
            {
                printf("%c%d = ", 'a'+j-1, i);
                scanf("%f", mat+i*col+j);
            }
        }
        printf("\n");
    }
}

//Print whole matrix with n decimal places
void print_mat(const float* mat, int row, int col)
{
    int i, j;
    for(i=1; i<row; i++)
    {
        for(j=1; j<col; j++)
            printf("%.*f ", N, *(mat+i*col+j));
        printf("\n");
    }
    printf("\n");
}

int left_nonz_col(const float* mat, int row, int col, int toprow)
{
    int i, j;
    for(j=1; j<col; j++)
        for(i=toprow; i<row; i++)
            if(*(mat+i*col+j)!=0)
                return j;
    return 0;
}

int left_nonz_row(const float* mat, int row, int col, int toprow)
{
    int i, j;
    for(j=1; j<col; j++)
        for(i=toprow; i<row; i++)
            if(*(mat+i*col+j)!=0)
                return i;
    return 0;
}

void swaprow(float* mat, int row, int col, int n_row1, int n_row2)
{
    int i;
    float row1[col], row2[col];
    for(i=0; i<col; i++)
    {
        row1[i] = *(mat+n_row1*col+i);
        row2[i] = *(mat+n_row2*col+i);
    }
    for(i=0; i<col; i++)
    {
        *(mat+n_row1*col+i) = row2[i];
        *(mat+n_row2*col+i) = row1[i];
    }
}

//n_row <- n_row+k*n_row_k
void linecomb(float* mat, int row, int col, float k, int n_row_k, int n_row)
{
    int i;
    for(i=0; i<col; i++)
        *(mat+n_row*col+i) += k*(*(mat+n_row_k*col+i));
}

void basic_gauss(float* mat, int row, int col, int toprow)
{
    int nonz_col = left_nonz_col(mat, row, col, toprow);
    int nonz_row = left_nonz_row(mat, row, col, toprow);
    if(nonz_col!=0 && nonz_col!=col-1)
    {
        swaprow(mat, row, col, toprow, nonz_row);
        float topcoef = *(mat+toprow*col+nonz_col);

        int i;
        for(i=toprow+1; i<row; i++)
        {
            float coef = *(mat+i*col+nonz_col);
            if(coef!=0)
                linecomb(mat, row, col, -coef/topcoef, toprow, i);
        }
    }
}

void gauss(float* mat, int row, int col)
{
    int i;
    for(i=1; i<row; i++)
        basic_gauss(mat, row, col, i);
}

//Check if no solutions
bool sol_check(const float* mat, int row, int col)
{
    bool left_zero, right_zero;
    for(int i=row-1; i>=1; i--) {
        //determining whether left are all zeroes
        left_zero = true;
        for(int j=1; j<col-1; j++)
            if(*(mat+i*col+j)!=0) {
                left_zero = false;
                break;
            }
        //determining whether right is a zero
        if(*(mat+i*col+col-1)==0)
            right_zero = true;
        else
            right_zero = false;
        //determining solution
        if(left_zero==true && right_zero==false)
            return false;
    }
    return true;
}

//Convert to reduced form
void reduce(float* mat, int row, int col)
{
    //removes the rows with all zeroes
    for(int n=row*col-1; n>=0; n--)
        if(*(mat+n)!=0) {
            row = n/col+1;
            break;
        }
    
    //rescale the pivot points
    for(int i=1; i<row; i++) {
        float scale = 1;
        for(int j=1; j<col-1; j++)
            if(*(mat+i*col+j)!=0) {
                scale = *(mat+i*col+j);
                break;
            }
        for(int j=1; j<col; j++)
            *(mat+i*col+j) /= scale;
    }

    //change into zeroes for values top of pivot
    for(int i=row-1; i>=1; i--) {
        //determine pivot col
        int pivot_col = 0;
        for(int j=1; j<col-1; j++)
            if(*(mat+i*col+j)!=0) {
                pivot_col = j;
                break;
            }
        //rows above doing operation
        for(int op_i=1; op_i<i; op_i++)
            linecomb(mat, row, col, -*(mat+op_i*col+pivot_col), i, op_i);
    }
}

//Interpret as output
void interpret(const float* mat, int row, int col)
{
    //removes the rows with all zeroes
    for(int n=row*col-1; n>=0; n--)
        if(*(mat+n)!=0) {
            row = n/col+1;
            break;
        }
    //determine number of free variables
    int var_num = col-2;
    int free_num = var_num-(row-1); //numof var - num of pivots
    //array of the index of free variables (if free, value 0 at its index, else the row num)
    int free_var[var_num+1] = {0}; //first index ignore
    for(int i=row-1; i>=1; i--) {
        //determine pivot col
        for(int j=1; j<col-1; j++)
            if(*(mat+i*col+j)!=0) {
                free_var[j] = i;
                break;
            }
    }
    //index number of free variable
    int free_var_i[var_num+1] = {0};
    int k_i = 0;
    for(int i=1; i<=var_num; i++)
        if(free_var[i]==0) {
            k_i++;
            free_var_i[i] = k_i;
        }

    //output all variables
    for(int n=1; n<=var_num; n++) {
        printf("x%d = ", n);
        //free variable
        if(free_var[n]==0)
            printf("k%d", free_var_i[n]);
        //not free variable
        else{
            int piv_row = free_var[n];
            printf("%.*f ", N, *(mat+piv_row*col+(col-1)));
            for(int i=1; i<=var_num; i++)
                if(free_var[i]==0) {
                    //for every free variable index i
                    float coef = *(mat+piv_row*col+i);
                    if(coef!=0) {
                        if(coef > 0)
                            printf("- %.*fk%d ", N, coef, free_var_i[i]);
                        else
                            printf("+ %.*fk%d ", N, -coef, free_var_i[i]);
                    }
                }
        }
        printf("\n");
    }
    //additional statement
    if(free_num > 0) {
        printf("where ");
        for(int i=1; i<free_num; i++)
            printf("k%d, ", i);
        printf("k%d can be any number", free_num);
        if(free_num == 1)
            printf(".");
        else
            printf("s.");
    }
}