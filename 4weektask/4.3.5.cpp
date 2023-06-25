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
/*int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}*/
