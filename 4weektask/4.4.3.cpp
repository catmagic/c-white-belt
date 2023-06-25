#include <iostream>
#include <numeric>
#include<sstream>
#include<set>
#include<map>
#include<vector>
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
        if(denominator==0)
        {
            throw invalid_argument("");
        }
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
        if(den==0)
        {
            throw domain_error("");
        }
        long long int num =this->Numerator()*left.Denominator();
        return Rational(num,den);
    }

    bool operator ==(Rational left)const
    {
        return this->Denominator()==left.Denominator()&&this->Numerator()==left.Numerator();
    }
     bool operator <(Rational left)const
    {
        long long int den = lcm(left.Denominator(),this->Denominator());
        return this->Numerator()*den/this->Denominator()<left.Numerator()*den/left.Denominator();;
    }
private:
    int num,den;
    // Добавьте поля
};
istream& operator>>(istream &input,Rational &left)
{
    int num,den;
    char c;
    if(input>>num>>c>>den)
    {
        left=Rational(num,den);
    }
    return input;
}
ostream& operator<<(ostream &output,const Rational &left)
{

    output<<left.Numerator()<<'/'<<left.Denominator();
    return output;
}
int main() {
    try {

        Rational r,l;
        char op;
        cin>>r>>op>>l;
        if(op=='+')
        {
            cout<<r+l;
        }
        if(op=='-')
        {
            cout<<r-l;
        }
        if(op=='*')
        {
            cout<<r*l;
        }
        if(op=='/')
        {
            cout<<r/l;
        }
    } catch (invalid_argument&) {
        cout<<"Invalid argument";
    }
     catch (domain_error&) {
         cout<<"Division by zero";
    }



    return 0;
}

