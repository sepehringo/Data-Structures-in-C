#include <stdio.h>

void print_array(int *a, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        printf("\n");
        for (int j = 0; j < n; j++)
            printf("%4d", *(a + (i * n) + j));
    }
    printf("\n");
}
int main()
{
    int sparse[][3] = {{6, 6, 8}, {0, 0, 15}, {0, 3, 22}, {0, 5, -15}, {1, 1, 11}, {1, 2, 3}, {2, 3, -6}, {4, 0, 91}, {5, 2, 28}};
    print_array(sparse, 9, 3);

    int* trans = sparse;

    for (int k = 0; k < 3; k++)
        trans[0][k] = sparse[0][k];
    for (int i = 1; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {    if (sparse[i][1] < sparse[i + 1][1])
            {
                trans[i][1] = trans[i + 1][0];
                trans[i][0] = trans[i + 1][1];
                trans[i][2] = trans[i + 1][2];
            }
            else{
                trans[i][1] = trans[i][0];
                trans[i ][0] = trans[i][1];
                trans[i][2] = trans[i][2];
            }
        }
    print_array(trans,9,3);
}