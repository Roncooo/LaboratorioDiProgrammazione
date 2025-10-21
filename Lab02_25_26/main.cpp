#include <iostream>
#include <stdexcept>

#include "Rational.hpp"

int main(void)
{
    std::cout << "=== TEST COSTRUTTORI ===" << std::endl;

    std::cout << "Costruttore di default" << std::endl;
    Rational n1{};
    // Stampo con l'operatore e accedo anche manualmente ai campi per controllare cosa sta succedendo
    std::cout << "n1=" << n1 << "\tnum=" << n1.get_num() << "\tden=" << n1.get_den() << "\tvalue=" << n1.to_double() << std::endl;

    std::cout << "Costruttore con un intero" << std::endl;
    Rational n2{5};
    std::cout << "n2=" << n2 << "\tnum=" << n2.get_num() << "\tden=" << n2.get_den() << "\tvalue=" << n2.to_double() << std::endl;

    std::cout << "Costruttore con num e den" << std::endl;
    Rational n3{5, 6};
    std::cout << "n3=" << n3 << "\tnum=" << n3.get_num() << "\tden=" << n3.get_den() << "\tvalue=" << n3.to_double() << std::endl;

    std::cout << "Test semplificazione: creo il rational 8/36" << std::endl;
    Rational n4{8, 36};
    std::cout << "n4=" << n4 << "\tnum=" << n4.get_num() << "\tden=" << n4.get_den() << "\tvalue=" << n4.to_double() << std::endl;

    std::cout << "Costruttore con denominatore 0" << std::endl;
    try
    {
        Rational n5{5, 0};
        std::cout << "n5=" << n5 << "\tnum=" << n5.get_num() << "\tden=" << n5.get_den() << "\tvalue=" << n5.to_double() << "\n";
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "E' stata giustamente lanciata l'eccezione: " << e.what() << std::endl;
    }

    std::cout << "\n=== OPERATORI TRA RATIONALS ===" << std::endl;

    std::cout << "Assegnamento n1=n3: ";
    n1 = n3;
    std::cout << "n1=" << n1 << std::endl;

    std::cout << "n3 + n4 = " << n3 << " + " << n4 << " = " << n3 + n4 << std::endl;
    std::cout << "n3 - n4 = " << n3 << " - " << n4 << " = " << n3 - n4 << std::endl;
    std::cout << "n3 * n4 = " << n3 << " * " << n4 << " = " << n3 * n4 << std::endl;
    std::cout << "n3 / n4 = " << n3 << " / " << n4 << " = " << n3 / n4 << std::endl;
    std::cout << "Divisione per 0" << std::endl;
    try
    {
        Rational n5 = n3 / 0;
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "E' stata giustamente lanciata l'eccezione: " << e.what() << std::endl;
    }

    std::cout << "\n=== CONFRONTI TRA RATIONALS ===" << std::endl;
    std::cout << "n1 == n2: " << (n1 == n2) << std::endl; // false
    std::cout << "n1 == n3: " << (n1 == n3) << std::endl; // true
    std::cout << "n1 > n2: " << (n1 > n2) << std::endl;
    std::cout << "n1 < n2: " << (n1 < n2) << std::endl;

    std::cout << "\n=== OPERATORI CON INTERI ===" << std::endl;
    std::cout << "Assegnamento n3=5: ";
    n3 = 5;
    std::cout << "n3=" << n3 << std::endl;
    std::cout << "n1 + 3 = " << n1 << " + " << 3 << " = " << n1 + 3 << std::endl;
    std::cout << "n1 - 3 = " << n1 << " - " << 3 << " = " << n1 - 3 << std::endl;
    std::cout << "n1 * 3 = " << n1 << " * " << 3 << " = " << n1 * 3 << std::endl;
    std::cout << "n1 / 3 = " << n1 << " / " << 3 << " = " << n1 / 3 << std::endl;
    std::cout << "3 + n1 = " << 3 << " + " << n1 << " = " << 3 + n1 << std::endl;
    std::cout << "3 - n1 = " << 3 << " - " << n1 << " = " << 3 - n1 << std::endl;
    std::cout << "3 * n1 = " << 3 << " * " << n1 << " = " << 3 * n1 << std::endl;
    std::cout << "3 / n1 = " << 3 << " / " << n1 << " = " << 3 / n1 << std::endl;

    std::cout << "\n=== CONFRONTI CON INTERI ===" << std::endl;
    std::cout << "n3 == 5: " << (n3 == 5) << std::endl;
    std::cout << "n1 > 3: " << (n1 > 3) << std::endl;
    std::cout << "n1 < 3: " << (n1 < 3) << std::endl;
    std::cout << "5 == n3: " << (5 == n3) << std::endl;
    std::cout << "3 > n1: " << (3 > n1) << std::endl;
    std::cout << "3 < n1: " << (3 < n1) << std::endl;

}