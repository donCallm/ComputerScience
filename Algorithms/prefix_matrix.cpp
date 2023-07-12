#include <iostream>
#include <vector>

std::vector<std::vector<int>> prefix_matrix(int x_size, int y_size, const std::vector<std::vector<int>>& matrix)
{
    std::vector<std::vector<int>> prefix_matrix(x_size);

    for (int i = 0; i < y_size; ++i)
        prefix_matrix[i].resize(x_size);

    for (int i = 0; i < y_size; ++i)
    {
        for (int j = 0; j < x_size; ++j)
        {
            if(i == 0)
            {
                if (j == 0) prefix_matrix[i][j] = matrix[i][j]; 
                else prefix_matrix[i][j] = matrix[i][j] + matrix[i][j - 1];
            }
            else
            {
                if (j == 0) prefix_matrix[i][j] = matrix[i][j] + matrix[i - 1][j];
                else prefix_matrix[i][j] = matrix[i][j] + prefix_matrix[i - 1][j] + prefix_matrix[i][j - 1];
            }
        }
    }
    
    return prefix_matrix;
}

void show_prefix_matrix(int x_size, int y_size, const std::vector<std::vector<int>>& prefix_matrix)
{
    std::cout << "Prefix matrix: " << std::endl;
    for (int i = 0; i < y_size; ++i)
    {
        for (int j = 0; j < x_size; ++j)
            std::cout << prefix_matrix[i][j] << " ";
        std::cout << std::endl;
    }
}

int main()
{
    int y_size = 3;
    int x_size = 3;
    std::vector<std::vector<int>> matrix(y_size);

    for (int i = 0; i < y_size; ++i)
        matrix[i].resize(x_size);
    
    for (int i = 0; i < y_size; ++i)
    {
        for (int j = 0; j < x_size; ++j)
        {
            matrix[i][j] = j;
            std::cout << matrix[i][j] << std::endl;
        }
    }
    
    show_prefix_matrix(x_size, y_size, prefix_matrix(x_size, y_size, matrix));

    return 0;
}