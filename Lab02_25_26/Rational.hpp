#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iostream>

class Rational
{
public:
    // ========== COSTRUTTORE ==========
    Rational(int numerator = 0, int denominator = 1);

    // ========== GETTERS ==========
    int get_num() const { return num; }
    int get_den() const { return den; }
    double to_double() const { return double(num) / double(den); }

    // ========== OPERAZIONI TRA DUE RATIONAL ==========
    Rational& operator=(const Rational &rational);
    Rational operator+(const Rational &rational) const; // somma
    Rational operator-(const Rational &rational) const; // sottrazione
    Rational operator*(const Rational &rational) const; // moltiplicazione
    Rational operator/(const Rational &rational) const; // divisione

    Rational operator-() const; // operatore unario - (non richiesto)

    // ========== CONFRONTI TRA DUE RATIONAL ==========
    bool operator==(const Rational &rational) const; // equality
    bool operator>(const Rational &rational) const;  // greater than
    bool operator<(const Rational &rational) const;  // less than

private:
    int num = 0;
    int den = 1;

    /**
     * @brief Riduce la frazione ai minimi termini
     * Esempio: 2/4 diventa 1/2.
     * Da notare che è una funzione privata d'istanza non const in quanto agisce 
     * direttamente sull'oggetto sul quale viene invocata.
     */
    void simplify();

    /**
     * @brief Calcolo del massimo comune divisore (Greatest Common Divisor).
     * Richiede che a e b siano positivi, usa l'algoritmo di Euclide.
     */
    static int gcd(int a, int b);
};

// ========== OPERATORE << ==========
std::ostream &operator<<(std::ostream &os, const Rational &rational);

// ========== OPERAZIONI TRA INT E RATIONAL ==========
Rational operator+(int integer, const Rational &rational);
Rational operator-(int integer, const Rational &rational);
Rational operator*(int integer, const Rational &rational);
Rational operator/(int integer, const Rational &rational);

// ========== CONFRONTI TRA INT E RATIONAL ==========
bool operator==(int integer, const Rational &rational);
bool operator>(int integer, const Rational &rational);
bool operator<(int integer, const Rational &rational);

#endif // RATIONAL_HPP
