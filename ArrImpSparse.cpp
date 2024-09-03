#include <iostream>
using namespace std;

struct SparseMatrix 
{
    int row, col, value;
};

int main() 
{
    int m = 4, n = 5;
    int matrix[m][n] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    int nonZeroCount = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                nonZeroCount++;
            }
        }
    }

    SparseMatrix sparse[nonZeroCount];
    int index = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) 
        {
            if (matrix[i][j] != 0) 
            {
                sparse[index].row = i;
                sparse[index].col = j;
                sparse[index].value = matrix[i][j];
                index++;
            }
        }
    }
    cout << "Row\tColumn\tValue\n";
    for (int i = 0; i < nonZeroCount; i++) 
    {
        cout << sparse[i].row << "\t" << sparse[i].col << "\t" << sparse[i].value << endl;
    }

    return 0;
}
