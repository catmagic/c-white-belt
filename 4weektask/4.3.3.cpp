#include <iostream>
#include <numeric>
using namespace std;

class Rational {
    public:
        Rational() {
        num=0;
        den=1;
        // Реализуйте конструктор по умолчанию
    }

    Rational(int numerator, int denominator) {
        // Реализуйте конструктор
        num=numerator;
        den=denominator;
        int GCD=gcd(num,den);
        num/=GCD;
        den/=GCD;
        if(den<0)
        {
            num*=-1;
            den*=-1;
        }
    }

    int Numerator() const {
        // Реализуйте этот метод
        return num;
    }

    int Denominator() const {
        // Реализуйте этот метод
        return den;
    }
    Rational operator +(Rational left)
    {
        long long int den = lcm(left.Denominator(),this->Denominator());
        long long int num =this->Numerator()*den/this->Denominator()+left.Numerator()*den/left.Denominator();
        return Rational(num,den);
    }
    Rational operator -(Rational left)
    {
        long long int den = lcm(left.Denominator(),this->Denominator());
        long long int num =this->Numerator()*den/this->Denominator()-left.Numerator()*den/left.Denominator();
        return Rational(num,den);
    }
    Rational operator *(Rational left)
    {
        long long int den = left.Denominator()*this->Denominator();
        long long int num =this->Numerator()*left.Numerator();
        return Rational(num,den);
    }
    Rational operator /(Rational left)
    {
        long long int den = left.Numerator()*this->Denominator();
        long long int num =this->Numerator()*left.Denominator();
        return Rational(num,den);
    }

    bool operator ==(Rational left)const
    {
        return this->Denominator()==left.Denominator()&&this->Numerator()==left.Numerator();
    }
private:
    int num,den;
    // Добавьте поля
};

// Реализуйте для класса Rational операторы ==, + и -

/*int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}*/
