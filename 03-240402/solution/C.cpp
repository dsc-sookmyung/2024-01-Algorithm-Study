#include <stdio.h>
#include <stdlib.h>

int **arr;
int res[3] = { 0, };

void recursive(int size, int x, int y)
{
    int i, j;
    int cur = arr[x][y];
    int is_box = 1;

    for (i=x;i<x+size;i++)
    {
        for (j=y;j<y+size;j++)
        {
            if (arr[i][j] != cur)
            {
                is_box = 0;
                break;
            }
        }
        if (! is_box)
            break;
    }
    if (is_box)
        res[cur+1]++;
    else
    {
        for (i=0;i<3;i++)
        {
            for (j=0;j<3;j++)
                recursive(size/3, x + i * size/3, y + j * size/3);
        }
    }
}

int main(void)
{
    int n, i, j;

    scanf("%d", &n);
    arr = (int **)malloc(sizeof(int *) * n);
    for (i=0;i<n;i++)
    {
        arr[i] = (int *)malloc(sizeof(int) * n);
        for (j=0;j<n;j++)
            scanf("%d", &arr[i][j]);
    }
    recursive(n, 0, 0);
    printf("%d\n%d\n%d\n", res[0], res[1], res[2]);
    for (i=0;i<n;i++)
        free(arr[i]);
    free(arr);
    return 0;
}
