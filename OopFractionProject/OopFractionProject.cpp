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
    
};



int main()
{
    Fraction f1(4, 5);
    Fraction f2(7, 11);
    Fraction f3(3, 8);

    /*cout << f1.ToString() << " + " << f2.ToString() << " = ";
    f1.Add(f2);
    cout << f1.ToString() << "\n";*/

    cout << f1.Plus(f2).Minus(f3).ToString();

}
