#include <iostream>

using namespace std;

class Matrix2x2
{
    private:
        int a11;
        int a12;
        int a21;
        int a22;

    public:
        Matrix2x2()
        {
            a11 = 0;
            a12 = 0;
            a21 = 0;
            a22 = 0;
        }

        Matrix2x2(int MatA1, int MatA2, int MATB1, int MATB2)
        {
            a11 = MatA1;
            a12 = MatA2;
            a21 = MATB1;
            a22 = MATB2;
        }

        Matrix2x2 operator+(const Matrix2x2 &other)
        {
            return Matrix2x2(a11 + other.a11, a12 + other.a12, a21 + other.a21, a22 + other.a22);
        }

        Matrix2x2 operator-(const Matrix2x2 &other)
        {
            return Matrix2x2(a11 - other.a11, a12 - other.a12, a21 - other.a21, a22 - other.a22);
        }

        Matrix2x2 operator*(const Matrix2x2 &other)
        {
            return Matrix2x2(
                a11 * other.a11 + a12 * other.a21,
                a11 * other.a12 + a12 * other.a22,
                a21 * other.a11 + a22 * other.a21,
                a21 * other.a12 + a22 * other.a22);
        }

        friend int determinant(const Matrix2x2 &m);

        friend class MatrixHelper;

        friend ostream &operator<<(ostream &out, const Matrix2x2 &m)
        {
            out << m.a11 << " " << m.a12 << endl;
            out << m.a21 << " " << m.a22 << endl;
            return out;
        }
};

int determinant(const Matrix2x2 &m)
{
    return m.a11 * m.a22 - m.a12 * m.a21;
}

class MatrixHelper
{
    public:
        void updateElement(Matrix2x2 &m, int row, int col, int value)
        {
            if (row == 1 && col == 1)
            {
                m.a11 = value;
            }
            else if (row == 1 && col == 2)
            {
                m.a12 = value;
            }
            else if (row == 2 && col == 1)
            {
                m.a21 = value;
            }
            else if (row == 2 && col == 2)
            {
                m.a22 = value;
            }
        }
};

int main()
{
    Matrix2x2 MatA(1, 2, 3, 4);
    Matrix2x2 MATB(5, 6, 7, 8);

    cout << "Matrix 1:" << endl;
    cout << MatA;
    cout << endl;

    cout << "Matrix 2:" << endl;
    cout << MATB;
    cout << endl;

    Matrix2x2 sum = MatA + MATB;
    cout << "Sum:" << endl;
    cout << sum;
    cout << endl;
    
    Matrix2x2 diff = MatA - MATB;
    cout << "Difference:" << endl;
    cout << diff;
    cout << endl;
    
    Matrix2x2 prod = MatA * MATB;
    cout << "Product:" << endl;
    cout << prod;
    cout << endl;
    
    cout << "Determinant of Matrix A: " << determinant(MatA) << endl;
    cout << endl;
    
    MatrixHelper helper;
    helper.updateElement(MatA, 1, 1, 10);
    cout << endl;
    
    cout << "Matrix B after update:" << endl;
    cout << MatA;
    cout << endl;

    return 0;
}
