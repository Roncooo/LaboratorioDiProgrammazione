#include <iostream>
#include <stdexcept>

#include "Rational.hpp"

// ========== COSTRUTTORE ==========

// Da notare che i valori di default restano solo nel file hpp.
Rational::Rational(int numerator, int denominator)
    : num{numerator}, den{denominator}
{
    if (denominator == 0)
        throw std::invalid_argument("Denominator cannot be 0");
    this->simplify();
}

// ========== OPERAZIONI TRA DUE RATIONAL ==========

// Operatore di assegnazione
Rational& Rational::operator=(const Rational& rational)
{
    // Evita l'autoassegnamento
    if (this != &rational) {
        this->num = rational.num;
        this->den = rational.den;
    }
    // Ritorna il riferimento per permettere la concatenazione
    return *this;
}

// Rational+Rational
Rational Rational::operator+(const Rational &rational) const
{
    int new_num = rational.den * (this->num) + rational.num * (this->den);
    int new_den = rational.den * (this->den);
    return Rational{new_num, new_den};
}

// Rational-Rational
// Da notare che questo operatore binario è necessario anche se esiste l'operatore
// unario operator-(). L'operazione r1-r2 usa l'operatore binario mentre r1+(-r2)
// usa l'operatore unario e poi la somma.
Rational Rational::operator-(const Rational &rational) const
{
    int new_num = rational.den * (this->num) - rational.num * (this->den);
    int new_den = rational.den * (this->den);

    return Rational{new_num, new_den};

    // Implementazioni alternative
    // return *this+(-rat); // usando l'operatore unario e la somma
    // return *this+(rat*-1);
}

// Rational*Rational
Rational Rational::operator*(const Rational &rational) const
{
    int new_num = rational.num * (this->num);
    int new_den = rational.den * (this->den);
    return Rational{new_num, new_den};
}

// Rational/Rational
Rational Rational::operator/(const Rational &rational) const
{
    if (rational == 0)
        throw std::invalid_argument("Invalid division by 0");
    int new_num = rational.den * (this->num);
    int new_den = rational.num * (this->den);
    return Rational{new_num, new_den};
}

// non richiesto, operatore unario -Rational
Rational Rational::operator-() const
{
    return operator*(-1);
}

// ========== CONFRONTI TRA DUE RATIONAL ==========

// Rational==Rational
bool Rational::operator==(const Rational &rational) const
{
    return this->num == rational.num && this->den == rational.den;
}

// Rational>Rational
bool Rational::operator>(const Rational &rational) const
{
    return this->to_double() > rational.to_double();
}

// Rational<Rational
bool Rational::operator<(const Rational &rational) const
{
    return this->to_double() < rational.to_double();
}

// ========== OPERATORE << ==========

std::ostream &operator<<(std::ostream &os, const Rational &rational)
{
    // evito di stampare "/1"
    if (rational.get_den() == 1)
        return os << rational.get_num();
    else
        return os << rational.get_num() << "/" << rational.get_den();
}

// ========== OPERAZIONI TRA INT E RATIONAL ==========

// int+Rational
Rational operator+(int integer, const Rational &rational) { return rational + integer; }

// int-Rational
Rational operator-(int integer, const Rational &rational) { return -(rational - integer); }

// int*Rational
Rational operator*(int integer, const Rational &rational) { return rational * integer; }

// int/Rational
Rational operator/(int integer, const Rational &rational)
{
    if (rational == 0)
        throw std::invalid_argument("Invalid division by 0");
    // fare integer/rat è come fare integer*(den/num)
    return integer * (Rational{rational.get_den(), rational.get_num()});
}

// ========== CONFRONTI TRA INT E RATIONAL ==========

// int==Rational
bool operator==(int integer, const Rational &rational) { return rational == integer; }

// int>Rational
bool operator>(int integer, const Rational &rational) { return rational < integer; }

// int<Rational
bool operator<(int integer, const Rational &rational) { return rational > integer; }

// Helper function per semplificare le frazioni
void Rational::simplify()
{
    // Gestione del segno: il denominatore deve essere positivo
    if (den < 0)
    {
        den = -den;
        num = -num;
    }

    // Se il numeratore è zero, non serve semplificare
    if (num == 0)
    {
        den = 1;
        return;
    }

    int a = abs(num);
    int b = den;
    int mcd = gcd(a, b);

    num /= mcd;
    den /= mcd;
}

int Rational::gcd(int a, int b)
{
    if (a < 0)
        throw std::invalid_argument("'a' must be non-negative");
    if (b < 0)
        throw std::invalid_argument("'b' must be non-negative");

    if (a <= b)
    {
        // swap
        int temp = b;
        b = a;
        a = temp;
    }

    // Ora sicuramente b<a, applico l'algoritmo di Euclide
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
