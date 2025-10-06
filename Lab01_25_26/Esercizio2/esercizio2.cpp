#include <iostream>

// int g_init = 10;   // d) globale inizializzata -> data
// int g_noinit;      // e) globale non inizializzata -> bss

int main() {
    int automatic = 5;         // a) locale automatica -> né data né bss
    // static int s_init = 42; // b) locale statica inizializzata -> data
    // static int s_noinit;    // c) locale statica non inizializzata -> bss
    
    return 0;
}
