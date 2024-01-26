#include <stdio.h>

void solve(void);
void scangrid(char grid[8][8]);
int fullrow(const char grid[8][8], char);

int main()
{
    int t, i;
    scanf("%d", &t);
    getchar();
    for(i=0; i<t; i++)
        solve();
    return 0;
}

void solve()
{
    char grid[8][8];
    getchar();
    scangrid(grid);
    if(fullrow(grid, 'R'))
        printf("R\n");
    else
        printf("B\n");
}

void scangrid(char grid[8][8])
{
    int i, j;
    for(i=0; i<8; i++)
    {
        for(j=0; j<8; j++)
            scanf("%c", &grid[i][j]);
        getchar();
    }
}

int fullrow(const char grid[8][8], char c)
{
    int i, j;
    for(i=0; i<8; i++)
    {
        int output = 1;
        for(j=0; j<8; j++)
            if(grid[i][j] != c)
                output = 0;
        if(output)
            return 1;
    }
    return 0;
}
