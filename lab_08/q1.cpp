#include <iostream>
using namespace std;

class Complex
{
    private:
        double real;
        double imag;

    public:
        Complex()
        {
            real = 0;
            imag = 0;
        }

        Complex(double r, double i)
        {
            real = r;
            imag = i;
        }

        Complex operator+(const Complex &other)
        {
            return Complex(real + other.real, imag + other.imag);
        }

        Complex operator-(const Complex &other)
        {
            return Complex(real - other.real, imag - other.imag);
        }

        Complex operator*(const Complex &other)
        {
            return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
        }

        Complex operator/(const Complex &other)
        {
            double denom = other.real * other.real + other.imag * other.imag;
            return Complex((real * other.real + imag * other.imag) / denom, (imag * other.real - real * other.imag) / denom);
        }

        friend double magnitude(const Complex &c);

        friend ostream &operator<<(ostream &out, const Complex &c)
        {
            out << "(" << c.real << " + " << c.imag << "i)" << endl;
            return out;
        }
};

double absolute(double x)
{
    if (x < 0)
    {
        return -x;
    }
    return x;
}

double sqrt_approx(double x)
{
    double guess = x / 2;
    double epsilon = 0.00001;
    while (absolute(guess * guess - x) > epsilon)
    {
        guess = (guess + x / guess) / 2;
    }
    return guess;
}

double magnitude(const Complex &c)
{
    return sqrt_approx(c.real * c.real + c.imag * c.imag);
}

int main()
{
    Complex a(3, 4);
    Complex b(1, 2);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    Complex sum = a + b;
    cout << "a + b = " << sum << endl;

    Complex diff = a - b;
    cout << "a - b = " << diff << endl;

    Complex prod = a * b;
    cout << "a * b = " << prod << endl;

    Complex quot = a / b;
    cout << "a / b = " << quot << endl;

    cout << "magnitude of a = " << magnitude(a) << endl;
    cout << "magnitude of b = " << magnitude(b) << endl;

    return 0;
}
