# Esercizio 6

Per compilare ed eseguire:

```bash
g++ esercizio6.cpp -o esercizio6
./esercizio6
```

## Spiegazione

La variabile `counter` della funzione `call_counter` è locale **statica**, il che significa che il suo **scope** è limitato alla funzione, ma la sua **durata di memorizzazione** coincide con quella del programma. Questo permette di incrementarla per contare le diverse chiamate della funzione.  
Poiché `counter` non è inizializzata esplicitamente, viene salvata nel segmento BSS e automaticamente inizializzata a 0 dal compilatore. Se fosse inizializzata a un valore diverso da 0, verrebbe salvata nel segmento data e l'inizializzazione verrebbe eseguita solo la prima volta che la funzione viene chiamata. Il funzionamento rimarrebbe lo stesso.
