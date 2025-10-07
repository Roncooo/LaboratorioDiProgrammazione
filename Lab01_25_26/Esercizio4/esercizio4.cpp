
#include <iostream>
#include <vector>
#include <string>

// Funzione dell'esercizio 3 per stampare un vettore con una label
void print(const std::string& label, const std::vector<int>& vec) {
    std::cout << label << ": ";
    for (const int& num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Funzione che scrive in vec i primi n numeri della sequenza di Fibonacci, partendo da x e y
// vec viene sovrascritto in quanto è passato per reference
void fibonacci(int x, int y, std::vector<int>& vec, int n) {
    // controllo sui valori di input
    if (x < 0) {
        throw std::invalid_argument("x must be non-negative");
    }
    if (y <= 0) {
        throw std::invalid_argument("y must be greater than 0");
    }
    if (n < 2) {
        throw std::invalid_argument("n must be at least 2");
    }

    // pulisco il vector prima di usarla
    vec.clear();

    // inserisco i primi due numeri della sequenza
    vec.push_back(x);
    vec.push_back(y);

    // calcolo iterativamente i rimanenti numeri della sequenza
    for (int i = 2; i < n; i++) {
        int next = vec[i - 1] + vec[i - 2];
        vec.push_back(next);
    }
}

int main() {
    std::vector<int> fib_sequence; // definizione del vettore (vuoto con il costruttore di default)
    int x = 1, y = 2, n = 10;
    fibonacci(x, y, fib_sequence, n);
    print("Fibonacci sequence", fib_sequence);
    return 0;
}

