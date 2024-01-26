#include <stdio.h>
#define M_ROW 5
#define M_COL 4

int shortest_path_length(const char* maze, int s_row, int s_col);
void print_maze(const char* maze);
void print_maze_num(const int* maze);
void copy_maze(const int* maze1, int* maze2);

int main(void)
{
    const char maze[M_ROW][M_COL] =
    {{'.', '#', '.', '#'},
    {'.', '#', '#', '.'},
    {'.', '.', '.', 'G'},
    {'.', '#', '.', '.'},
    {'.', '.', '.', '#'}};

    printf("%d", shortest_path_length(maze, 0, 2)); //Start coord using 0-index

    return 0;
}

int shortest_path_length(const char* maze, int s_row, int s_col)
{
    int maze_num[M_ROW][M_COL];

    //Initialize number for maze
    int i, j;
    for(i=0; i<M_ROW; i++)
        for(j=0; j<M_COL; j++)
        {
            switch(*(maze+i*M_COL+j))
            {
            case '.':
                maze_num[i][j] = -1;
                break;
            case 'G':
                maze_num[i][j] = 0;
                break;
            case '#':
                maze_num[i][j] = -2;
                break;
            }
        }

    //Setup number for maze
    int maze_num_temp[M_ROW][M_COL];
    copy_maze(maze_num, maze_num_temp);
    int cont = 1;
    while(cont)
    {
        cont = 0;
        for(i=0; i<M_ROW; i++)
            for(j=0; j<M_COL; j++)
            {
                if(maze_num[i][j]==-1)
                {
                    if(i!=0 && maze_num[i-1][j]>=0)
                    {
                        maze_num_temp[i][j] = maze_num[i-1][j]+1;
                        cont = 1;
                    }
                    else if(i!=M_ROW-1 && maze_num[i+1][j]>=0)
                    {
                        maze_num_temp[i][j] = maze_num[i+1][j]+1;
                        cont = 1;
                    }
                    else if(j!=0 && maze_num[i][j-1]>=0)
                    {
                        maze_num_temp[i][j] = maze_num[i][j-1]+1;
                        cont = 1;
                    }
                    else if(j!=M_COL-1 && maze_num[i][j+1]>=0)
                    {
                        maze_num_temp[i][j] = maze_num[i][j+1]+1;
                        cont = 1;
                    }
                }
            }
        copy_maze(maze_num_temp, maze_num);
    }

    //Output ans: Can't reach = -1, Obstacle chosen = -2, else = number of steps
    return maze_num[s_row][s_col];
}

void print_maze(const char* maze)
{
    int i, j;
    for(i=0; i<M_ROW; i++)
    {
        for(j=0; j<M_COL; j++)
            printf("%c ", *(maze+i*M_COL+j));
        printf("\n");
    }
    printf("\n");
}

void print_maze_num(const int* maze)
{
    int i, j;
    for(i=0; i<M_ROW; i++)
    {
        for(j=0; j<M_COL; j++)
            printf("%d ", *(maze+i*M_COL+j));
        printf("\n");
    }
    printf("\n");
}

void copy_maze(const int* maze1, int* maze2)
{
    int i, j;
    for(i=0; i<M_ROW; i++)
        for(j=0; j<M_COL; j++)
            *(maze2+i*M_COL+j) = *(maze1+i*M_COL+j);
}
