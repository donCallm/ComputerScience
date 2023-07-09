#include <iostream>

using namespace std;

int** prefix_matrix(int x_size, int y_size, int** matrix)
{
    int** prefix_matrix = new int*[y_size];

    for (int i = 0; i < y_size; ++i)
        prefix_matrix[i] = new int[x_size];

    for (int i = 0; i < y_size; ++i)
    {
        for (int j = 0; j < x_size; ++j)
        {
            if(i == 0)
            {
                if (j == 0)
                    continue;
                prefix_matrix[i][j] += prefix_matrix[i][j - 1];
            }
            else
            {
                if (j == 0)
                    prefix_matrix[i][j] += prefix_matrix[i - 1][j];
                else
                {
                    prefix_matrix[i][j] += prefix_matrix[i - 1][j];
                    prefix_matrix[i][j] += prefix_matrix[i][j - 1];
                }
            }
        }
    }
    
    return prefix_matrix;
}

void show_prefix_matrix(int x_size, int y_size, int** prefix_matrix)
{
    cout << "Prefix matrix: " << endl;
    for (int i = 0; i < y_size; ++i)
    {
        for (int j = 0; j < x_size; ++j)
            cout << prefix_matrix[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int y_size = 3;
    int x_size = 3;
    int** matrix = new int*[y_size];

    for (int i = 0; i < y_size; ++i)
        matrix[i] = new int[x_size];
    
    for (int i = 0; i < y_size; ++i)
        for (int j = 0; j < x_size; ++j)
            matrix[i][j] = j;
    
    show_prefix_matrix(x_size, y_size, prefix_matrix(x_size, y_size, matrix));

    return 0;
}