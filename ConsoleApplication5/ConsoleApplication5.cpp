#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator; 
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    void reduce() {
        int gcdValue = gcd(numerator, denominator);
        numerator /= gcdValue;
        denominator /= gcdValue;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction() : numerator(0), denominator(1) {}
    Fraction(int num, int denom) : numerator(num), denominator(denom) {
        if (denom == 0) {
            std::cerr << "Denominator cannot be zero. Setting to 1 by default." << std::endl;
            denominator = 1;
        }
        reduce();
    }
    int getNumerator() {
        return numerator;
    }
    int getDenominator() {
        return denominator;
    }
    void setNumerator(int num) {
        numerator = num;
        reduce();
    }
    void setDenominator(int denom) {
        if (denom == 0) {
            std::cerr << "Denominator cannot be zero. No changes made." << std::endl;
        }
        else {
            denominator = denom;
            reduce();
        }
    }
    void setFraction(int num, int denom) {
        if (denom == 0) {
            std::cerr << "Denominator cannot be zero. Setting to 1 by default." << std::endl;
            denominator = 1;
        }
        else {
            numerator = num;
            denominator = denom;
            reduce();
        }
    }
    void print() {
        std::cout << numerator << "/" << denominator << std::endl;
    }
    Fraction add(const Fraction& other) {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }
    Fraction subtract(const Fraction& other) {
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }
};

int main() {
    Fraction frac1(3, 4);
    Fraction frac2(5, 6);
    Fraction result = frac1.add(frac2);
    result.print(); 
    result = frac1.subtract(frac2);
    result.print(); 
}
