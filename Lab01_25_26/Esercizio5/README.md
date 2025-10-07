# Esercizio 5

Per compilare ed eseguire:

```bash
g++ esercizio5.cpp -o esercizio5
./esercizio5
```

## Spiegazione

Per trovare il massimo valore rappresentabile da un intero in C++, possiamo sfruttare gli errori di overflow. In C++ gli interi sono memorizzati in complemento a due, una codifica che consente di rappresentare anche i numeri negativi. Se sommando due interi positivi otteniamo un numero negativo, significa che si è verificato un overflow: la somma ha superato la capacità del tipo e i bit si sono "riavvolti". L'ultimo numero valido ottenuto dalla sequenza di Fibonacci prima dell'overflow rappresenta quindi un'approssimazione del massimo intero memorizzabile.
