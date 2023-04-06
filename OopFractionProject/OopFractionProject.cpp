#include <iostream>
#include <string>

using namespace std;

class Fraction
{
    int numerator;
    int denominator;
public:
    Fraction(int numerator, int denominator) 
        : numerator{ numerator } 
    {
        if (denominator != 0)
            this->denominator = denominator;
    }
    Fraction() : Fraction(0, 1) {}

    void SetNumerator(int numerator) { this->numerator = numerator; }
    int GetNumerator() { return numerator; }
    void SetDenominator(int denominator) 
    {
        if (denominator != 0) this->denominator = denominator;
    }
    int GetDenominator() { return denominator; }

    string ToString()
    {
        return "[" + to_string(numerator) + "/" + to_string(denominator) + "]";
    }

    void Add(Fraction f)
    {
        this->numerator = this->numerator * f.denominator + f.numerator * this->denominator;
        this->denominator *= f.denominator;
    }

    Fraction Plus(Fraction f)
    {
        Fraction result;
        result.numerator = this->numerator * f.denominator + f.numerator * this->denominator;
        result.denominator = this->denominator * f.denominator;
        return result;
    }

    Fraction Minus(Fraction f)
    {
        Fraction result;
        result.numerator = this->numerator * f.denominator - f.numerator * this->denominator;
        result.denominator = this->denominator * f.denominator;
        return result;
    }

    bool Less(Fraction f)
    {
        return this->numerator* f.denominator < f.numerator * this->denominator;
    }

    friend Fraction operator+(Fraction f1, Fraction f2);
    
    friend Fraction operator+(Fraction f, int number);
    friend Fraction operator+(int number, Fraction f);

    friend bool operator<(Fraction f1, Fraction f2);
    friend bool operator>(Fraction f1, Fraction f2);

    friend bool operator==(Fraction f1, Fraction f2);

    Fraction operator-()
    {
        return Fraction(-this->numerator, this->denominator);
    }

    Fraction operator++()
    {
        *this = *this + 1;
        return *this;
    }

    Fraction operator++(int)
    {
        Fraction result = *this;
        ++*this;
        return result;
    }
    
};

Fraction operator+(Fraction f1, Fraction f2)
{
    Fraction result;
    result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;
    return result;
}

Fraction operator+(Fraction f, int number)
{
    return f + Fraction(number, 1);
}

Fraction operator+(int number, Fraction f)
{
    return f + Fraction(number, 1);
}

bool operator<(Fraction f1, Fraction f2)
{
    return f1.numerator* f2.denominator < f2.numerator* f1.denominator;
}

bool operator>(Fraction f1, Fraction f2)
{
    return !(f1 < f2);
}

bool operator==(Fraction f1, Fraction f2)
{
    return f1.numerator * f2.denominator == f2.numerator * f1.denominator;
}





int main()
{
    Fraction f1(4, 5);
    Fraction f2(7, 11);
    Fraction f3(3, 8);

    /*cout << f1.ToString() << " + " << f2.ToString() << " = ";
    f1.Add(f2);
    cout << f1.ToString() << "\n";*/

    cout << f1.Plus(f2).Minus(f3).ToString() << "\n";

    Fraction f4 = f1 + f2;

    int n = 5;

    Fraction f5 = -f1;

    cout << boolalpha << (f1 > f2);
    
    cout << f3.ToString() << "\n";
    ++f3;
    cout << f3.ToString() << "\n";
}
