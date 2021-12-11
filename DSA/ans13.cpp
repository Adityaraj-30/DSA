/*Ques 13. Write a program to implement:
(i) Diagonal Matrix using one-dimensional array.
(ii) Lower Triangular Matrix using one-dimensional array
(iii) Upper Triangular Matrix using one-dimensional array
(iv) Symmetric Matrix using one-dimensional array.
Ans:
*/
#include <iostream>

using namespace std;

bool checkSymmetric(int **m, int size) // Function to check if relation is symmetric or not
{
    int B[size][size];
    for (int r = 0; r < size; r++)
        for (int c = 0; c < size; c++)
            B[r][c] = m[c][r];
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (m[i][j] != B[i][j])
                return false;
    return true;
}

int main()
{
    cout << "------Enter the Size of the Square Matrix------>\n";
    int n;
    cin >> n;
    int **mat1 = new int *[n];
    for (int i = 0; i < n; ++i)
        mat1[i] = new int[n];
    cout << "\n------Enter elements of Square Matrix------\n" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat1[i][j];
        }
    }

    char ch = 'y';
    while (ch == 'y')
    {
        cout << "\n------Enter the choice------ \n1.Diagonal Matrix \n2.Upper Traingle\n3.Lower Traingle\n4.Symmetric\n \n"; 
                int o;
        cin >> o;
        if (o == 1)
        {
            int mat[n];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i == j)
                    {
                        mat[i] = mat1[i][j];
                    }
                }
            }

            cout << "\n------1-D Diagonal array------\n" << endl;
            for (int i = 0; i < n; i++)
            {
                cout << mat[i] << " ";
            }

            cout << "\n------Displaying the Matrix------\n" << endl;
            for (int i = 0; i < n; i++) // To Print Diagonal Matrix
            {
                for (int j = 0; j < n; j++)
                {
                    if (i == j)
                    {
                        cout << mat[i] << " ";
                    }
                    else
                    {
                        cout << "0 ";
                    }
                }
                cout << endl;
            }
        }
        else if (o == 2)
        {
            int mat[n * (n + 1) / 2]; // To Print Upper Traingluar Matrix
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i <= j)
                    {
                        mat[(j + 1) * j / 2 + i] = mat1[i][j];
                    }
                }
            }
            cout << "\n------1-D Upper traingle array------ \n" << endl;
            for (int j = 0; j < n * (n + 1) / 2; j++)
            {
                cout << mat[j] << " ";
            }
            cout << endl;
        }
        else if (o == 3)
        {
            int mat[n * (n + 1) / 2]; // to Print lower Trainagular Matrix
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i >= j)
                    {
                        mat[(i + 1) * (i) / 2 + (j)] = mat1[i][j];
                    }
                }
            }
            cout << "\n------1-D Lower traingle array------\n" << endl;
            for (int j = 0; j < n * (n + 1) / 2; j++)
            {
                cout << mat[j] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "\n------Check for symmetric matrix.------\n";
            if (checkSymmetric(mat1, n))
                cout << "\n\n------Matrix is symmetric------\n";
            else
                cout << "\n------Matrix is not symmetric------\n";
        }
        cout << "\n---Enter Y for Continue:---> ";
        cin >> ch;
    }
}
