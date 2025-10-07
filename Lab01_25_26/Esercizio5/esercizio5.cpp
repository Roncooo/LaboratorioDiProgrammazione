
#include <iostream>
#include <vector>
#include <string>
#include <climits> // per INT_MAX

// Funzione dell'esercizio 3
void print(const std::string& label, const std::vector<int>& vec) {
    std::cout << label << ": ";
    for (const int& num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Funzione dell'esercizio 4
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

int find_max_int_with_fibonacci(int fib_length = 50) {
    std::vector<int> fib_sequence;
    int x = 1, y = 2;
    fibonacci(x, y, fib_sequence, fib_length);
    print("Fibonacci sequence", fib_sequence);
    for (int i=0; i<fib_sequence.size(); i++) {
        // la somma di due interi positivi da un intero negativo: c'è stato un overflow
        if (fib_sequence[i] < 0) {
            return fib_sequence[i-1];
        }
    }
    // non è stato trovato nessun overflow, potresti provare con un valore più alto per fib_length
    return -1;
}

int main() {
    int max_int_fibonacci = find_max_int_with_fibonacci();
    std::cout << "The maximum integer found with the fibonacci sequence is: " << max_int_fibonacci << std::endl;
    std::cout << "The actual maximum integer is: " << INT_MAX << std::endl;
    return 0;
}

