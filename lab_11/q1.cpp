#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class DimensionMismatch : public exception
{
    private:
        string message;

    public:
    DimensionMismatch(int r1, int c1, int r2, int c2)
    {
        message = "DimensionMismatch Exception! Matrices must have same dimensions (" +
                    to_string(r1) + "x" + to_string(c1) + " vs " + to_string(r2) + "x" + to_string(c2) + ")";
    }

    string what()
    {
        return message;
    }
};

template <typename T>
class Matrix
{
    private:
        int rows, cols;
        T** elements;

    public:
        Matrix(int r, int c, T arr[][3]) : rows(r), cols(c)
        {
            elements = new T*[rows];
            for (int i = 0; i < rows; ++i)
            {
                elements[i] = new T[cols];
                for (int j = 0; j < cols; ++j)
                {
                    elements[i][j] = arr[i][j];
                }
            }
        }

        Matrix(int r, int c) : rows(r), cols(c)
        {
            elements = new T*[rows];
            for (int i = 0; i < rows; ++i)
            {
                elements[i] = new T[cols]();
            }
        }

        ~Matrix()
        {
            for (int i = 0; i < rows; ++i)
            {
                delete[] elements[i];
            }
            delete[] elements;
        }

        Matrix<T> operator+(const Matrix<T>& other)
        {
            if (rows != other.rows || cols != other.cols)
            {
                throw DimensionMismatch(rows, cols, other.rows, other.cols);
            }

            Matrix<T> result(rows, cols);
            for (int i = 0; i < rows; ++i)
            {
                for (int j = 0; j < cols; ++j)
                {
                    result.elements[i][j] = this->elements[i][j] + other.elements[i][j];
                }
            }
            return result;
        }

        void displayMatrix() const
        {
            for (int i = 0; i < rows; ++i)
            {
                for (int j = 0; j < cols; ++j)
                {
                    cout << elements[i][j] << " ";
                }
                cout << endl;
            }
        }
};

int main()
{
    int matA[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int matB[3][3] = {{7, 8, 9}, {10, 11, 12}, {13, 14, 15}};

    try
    {
        Matrix<int> A(2, 3, matA);
        Matrix<int> B(3, 3, matB);

        Matrix<int> C = A + B;
        C.displayMatrix();
    }
    catch (DimensionMismatch& e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
