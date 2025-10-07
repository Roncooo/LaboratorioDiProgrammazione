#include <iostream>
#include <vector>

// Funzione che stampa gli elementi di un vector con una label
// label e vec sono const reference perché non vogliamo modificarli
void print(const std::string& label, const std::vector<int>& vec) {
    std::cout << label << ": ";
    // range-based for loop: itera su tutti gli elementi di vec senza usare gli indici
    for (const int& num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    // creo il vector con la lista di inizializzazione
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    print("My numbers", numbers);
    return 0;
}
