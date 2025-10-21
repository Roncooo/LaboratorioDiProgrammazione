# Discussione

1. What are the two parts of a class?
   
   Interfaccia e implementazione, solitamente divise rispettivamente in file `.h` (o `.hpp`) e `.cpp`.

2. What is the difference between the interface and the implementation in a class?

   L’interfaccia dichiara cosa fa la classe, cioè quali funzioni e variabili (pubbliche o private) esistono.
   L’implementazione invece definisce come la classe svolge le sue operazioni, cioè contiene il codice effettivo di ogni funzione.

3. Why is a constructor used for the `Date` type instead of an `init_day()` function?
   
   Il costruttore garantisce che ogni oggetto `Date` sia creato in uno **stato valido** fin dall'inizio. 
   Se non definissimo il costruttore di `Date`, ogni oggetto di quella classe nascerebbe con i valori di default `day=0, month=0, year=0` (data non valida). Con una funzione `init_day()` si correrebbe il rischio che chi usa la classe si dimentichi di chiamarla, lasciando l’oggetto in uno stato incoerente.
   Il costruttore evita proprio questo problema, assicurando l’invariante della classe già alla creazione.

4. What is an invariant? Give examples.
   
   È una condizione che deve essere sempre vera per un oggetto valido, ad esempio per `Date` deve sempre essere vero 1<=month<=12 oppure per `Rational` il denominatore deve essere diverso da 0.

5. When should functions be put in the class definition, and when should they be defined outside the class? Why?
   
   Grammaticalmente qualsiasi funzione può essere definita all'interno dell'header, questo però non significa che sia una buona pratica!
   È consigliabile separare interfaccia e implementazione, in modo che l'header sia leggibile e descriva cosa fa la classe e come usarla. 
   Le funzioni molto brevi come getter, setter o operatori elementari possono essere definite nell'header, e saranno quindi considerate `inline` dal compilatore (cioè potenzialmente copiate e incollate "in linea" senza una vera chiamata con record di attivazione).
   Se la funzione è lunga o ha una logica complessa, meglio metterla nel file `.cpp`.

# Esercizio ```Rational```

## Istruzioni di compilazione

```bash
g++ Rational.cpp main.cpp -o main
./main
```

## Note

### Costruttori

Il costruttore che `Rational(int num=0, int den=1)` è sufficiente per considerare tutti i casi richiesti dalla consegna. Infatti se viene chiamato passando 0 parametri, questo si comporta esattamente come se fosse un costruttore di default `Rational()` inizializzando numeratore a 0 e denominatore a 1. Se invece viene chiamato passando un solo intero, usa quell'intero per il primo parametro (numeratore) e imposta di default il denominatore a 1 come. Quest'ultima casistica è particolarmente rilevante in quanto permette al compilatore di convertire qualsiasi intero in un oggetto `Rational` (conversione implicita). 
Sarebbe corretto, anche se ridondante, definire tutti e tre i costruttori così:
```
Rational();
Rational(int num);
Rational(int num, int den);
```
Tuttavia, se li definissimo con gli argomenti di default
```
Rational();
Rational(int num=0);
Rational(int num=0, int den=1);
```
si otterrebbe un errore di ambiguità in compilazione.
Ad esempio, la chiamata `Rational r{}` potrebbe essere soddisfatta da tutti e tre i costruttori, quindi il compilatore non saprebbe quale scegliere e segnala errore.

### Operatori

L'operatore di assignment definito manualmente si comporta esattamente come quello di default (e quindi non è necessario definirlo) in quanto Rational contiene solo tipi built in e per questi viene di default fatta una **copia membro a membro**.

Gli operatori aritmetici e di confronto tra due Rational accettano una `const reference`, quindi dichiarano di non modificare il secondo operando. Ricorda che `rational1+rational2` è esattamente equivalente a `rational1.operator+(rational2)`.

Gli operatori definiti come funzioni d'istanza sono `const` e quindi non modificano l'oggetto su cui vengono chiamati (ovvero il primo operando). L'unica eccezione è l'assegnamento che deve sovrascrivere il primo operando.

Implementando gli operatori aritmetici e di confronto tra due Rational abbiamo automaticamente implementato anche quelli Rational~intero in quanto, grazie al costruttore, qualsiasi intero può essere trasformato in Rational. Quindi ad esempio:
```
Rational r1{1,2};
Rational r2 = r1 + 3;
```
l'intero 3 viene convertito in Rational dal costruttore e poi viene chiamato l'operatore Rational+Rational.

Gli operatori che coinvolgono un intero come primo operando devono invece essere funzioni esterne (**helper function**), poiché il primo elemento non è un oggetto Rational e quindi non può invocare un metodo membro. In altre parole, se il primo operando è un intero non funziona il trucchetto della conversione con il costruttore. Lo stesso discorso vale per l'operatore `<<` che agisce su un `std::ostream`. Ricorda che le keyword friend e static vanno indicate solo nella dichiarazione all’interno della classe (header); l’implementazione o l’inizializzazione vera e propria si fa nel .cpp senza ripetere la keyword.

In questo caso la classe fornisce i getter pubblici, quindi chiunque può leggere lo stato dell'oggetto. Se così non fosse, `std::ostream` potrebbe essere definita come **funzione friend**: funzione esterna ma con accesso completo ai membri privati. 

### Come si scrive il `.cpp`

Il file `.cpp` che contiene le definizioni relative ad una classe (dichiarata in un file `.h` o `.hpp`), deve **includere** il file che contiene la dichiarazione, ad esempio `#include "Rational.h"`.

Nel file `.cpp` non ci sono sezioni `private` e `public`.

Per definire nel `.cpp` una funzione della classe `Rational` si deve usare l'operatore di scope (`::`). Quindi se nell'header c'è `static int gcd(int a, int b)`, nell'implementazione scriveremo `int Rational::gcd(int a, int b)`. Se la funzione è esterna (helper function), non ci va `Rational::`.

Le keyword `friend` e `static` vanno indicate solo nella dichiarazione (header), nel `.cpp` non vanno ripetute.

### Occhio ai retaggi di Java!!!

In c++ non si mette `public` prima di ogni funzione ma si divide l'header in zone di codice (`public`, `private`, `protected`).

In c++ `new` si usa solo per l'**allocazione dinamica** della memoria, cioè quando vogliamo creare oggetti sullo heap, e ritorna un puntatore. Nella maggior parte dei casi, e in particolare nell'esercizio su Rational, non serve. Ricorda anche che ciò che viene creato con `new` va deallocato esplicitamente con `delete` in quanto in c++ non c'è il garbage collector come in Java.
