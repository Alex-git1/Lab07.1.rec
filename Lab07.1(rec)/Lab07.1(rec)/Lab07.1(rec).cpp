#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** Z, const int rowCount, const int colCount, const int Low, const int High, int i = 0, int j = 0);
void Print(int** Z, const int rowCount, const int colCount, int i = 0, int j = 0);
void SortColumns(int** Z, const int rowCount, const int colCount, int i0 = 0, int i1 = 0);
void SwapColumns(int** Z, const int row1, const int row2, const int colCount, int j = 0);
void Calc(int** Z, const int rowCount, const int colCount, int& S, int& k, int i = 0, int j = 0);

int main()
{
    srand((unsigned)time(NULL));
    int Low = 4;
    int High = 45;
    int rowCount = 9; 
    int colCount = 7; 
    int** Z = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        Z[i] = new int[colCount];

    Create(Z, rowCount, colCount, Low, High);
    Print(Z, rowCount, colCount);
    SortColumns(Z, rowCount, colCount);
    Print(Z, rowCount, colCount);

    int S = 0;
    int k = 0;
    Calc(Z, rowCount, colCount, S, k);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    Print(Z, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] Z[i];
    delete[] Z;

    return 0;
}

void Create(int** Z, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
    if (i < rowCount) {
        if (j < colCount) {
            Z[i][j] = Low + rand() % (High - Low + 1);
            Create(Z, rowCount, colCount, Low, High, i, j + 1);
        }
        else {
            Create(Z, rowCount, colCount, Low, High, i + 1, 0);
        }
    }
}

void Print(int** Z, const int rowCount, const int colCount, int i, int j)
{
    if (i < rowCount) {
        if (j < colCount) {
            cout << setw(4) << Z[i][j];
            Print(Z, rowCount, colCount, i, j + 1);
        }
        else {
            cout << endl;
            Print(Z, rowCount, colCount, i + 1, 0);
        }
    }
    else if (i == rowCount && j == 0) {
        cout << endl;
    }
}

void SortColumns(int** Z, const int rowCount, const int colCount, int i0, int i1)
{
    if (i0 < colCount - 1) {
        if (i1 < colCount - i0 - 1) {
            if ((Z[0][i1] < Z[0][i1 + 1]) 
                || (Z[0][i1] == Z[0][i1 + 1] && Z[1][i1] > Z[1][i1 + 1]) 
                || (Z[0][i1] == Z[0][i1 + 1] && Z[1][i1] == Z[1][i1 + 1] && Z[2][i1] < Z[2][i1 + 1])) { 
                SwapColumns(Z, i1, i1 + 1, rowCount);
            }
            SortColumns(Z, rowCount, colCount, i0, i1 + 1);
        }
        else {
            SortColumns(Z, rowCount, colCount, i0 + 1, 0);
        }
    }
}

void SwapColumns(int** Z, const int col1, const int col2, const int rowCount, int i)
{
    if (i < rowCount) {
        int tmp = Z[i][col1];
        Z[i][col1] = Z[i][col2];
        Z[i][col2] = tmp;
        SwapColumns(Z, col1, col2, rowCount, i + 1);
    }
}

void Calc(int** Z, const int rowCount, const int colCount, int& S, int& k, int i, int j)
{
    if (i < rowCount) {
        if (j < colCount) {
            if (Z[i][j] % 2 == 0 && !(i % 2 != 0 || j % 2 != 0)) {
                S += Z[i][j];
                k++;
                Z[i][j] = 0;
            }
            Calc(Z, rowCount, colCount, S, k, i, j + 1);
        }
        else {
            Calc(Z, rowCount, colCount, S, k, i + 1, 0);
        }
    }
}
