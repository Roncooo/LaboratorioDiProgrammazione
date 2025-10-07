
#include <iostream>
#include <vector>

void call_counter(void) {
    static int counter;
    counter++;
    std::cout << "Call number: " << counter << std::endl;
}

int main() {
    for (int i=0; i<10; i++) {
        call_counter();
    }
    return 0;
}

