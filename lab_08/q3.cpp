#include <iostream>
using namespace std;

class Vector2D
{
    private:
        double x;
        double y;

    public:
        Vector2D()
        {
            x = 0;
            y = 0;
        }

        Vector2D(double xVal, double yVal)
        {
            x = xVal;
            y = yVal;
        }

        Vector2D operator+(const Vector2D &other)
        {
            return Vector2D(x + other.x, y + other.y);
        }

        Vector2D operator-(const Vector2D &other)
        {
            return Vector2D(x - other.x, y - other.y);
        }

        Vector2D operator*(double scalar)
        {
            return Vector2D(x * scalar, y * scalar);
        }

        friend double dotProduct(const Vector2D &a, const Vector2D &b);

        friend ostream &operator<<(ostream &out, const Vector2D &v)
        {
            out << "(" << v.x << ", " << v.y << ")";
            return out;
        }
};

double dotProduct(const Vector2D &a, const Vector2D &b)
{
    return a.x * b.x + a.y * b.y;
}

int main()
{
    Vector2D v1(3, 4);
    Vector2D v2(1, 2);

    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;

    Vector2D sum = v1 + v2;
    cout << "v1 + v2 = " << sum << endl;

    Vector2D diff = v1 - v2;
    cout << "v1 - v2 = " << diff << endl;

    Vector2D scaled = v1 * 2;
    cout << "v1 * 2 = " << scaled << endl;

    double dot = dotProduct(v1, v2);
    cout << "DOT PRODUCT = " << dot << endl;

    return 0;
}
