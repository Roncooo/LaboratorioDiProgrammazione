# Esercizio 2

## Compilazione e comando `size`

Come indicato nella consegna, compilare con 

```bash
g++ -c esercizio2.cpp 
```

e per analizzare le dimensioni dei vari segmenti, usare il comando 

```bash
size esercizio2.o
```

## Ripasso

Il comando `size` restituisce una tabella con le dimensioni (in byte) dei segmenti `text`, `data` e `bss`, oltre a `dec` (somma di `text` + `data` + `bss` in decimale), `hex` (come `dec` ma in esadecimale) e il nome del file oggetto. 

- Il segmento `text` contiene il codice eseguibile, cioè tutte le istruzioni macchina generate dal compilatore.
- Il segmento `data` contiene le variabili globali o statiche inizializzate a un valore diverso da zero: queste variabili sono presenti in memoria per tutta l'esecuzione del programma.
- Il segmento `bss` contiene le variabili globali o statiche non inizializzate (che vengono automaticamente inizializzate a zero) o inizializzate a zero.
- Le variabili locali automatiche sono allocate nello stack a runtime e quindi non occupano spazio nel file oggetto.

## Risultati 

Di seguito sono riportati i risultati del comando size per i cinque casi considerati:

| Variabile intera                 | data | bss |
| -------------------------------- | ---- | --- |
| locale automatica                | 0    | 0   |
| locale statica inizializzata     | 4    | 0   |
| locale statica non inizializzata | 0    | 4   |
| globale inizializzata            | 4    | 0   |
| globale non inizializzata        | 0    | 4   |

## Domande aperte

a) Una variabile locale automatica non compare in nessuna sezione del file oggetto perché è allocata nello stack a runtime. 

b) Si chiama "automatica" perché la sua durata è automatica, cioè viene creata quando si entra nel blocco/funzione e distrutta quando si esce.

c) Lo spazio riservato per le variabili statiche o globali non inizializzate è il BSS. Questo segmento viene inizializzato a 0 all'avvio del programma e quindi tutte le variabili statiche o globali non inizializzate sono automaticamente inizializzate a 0. Lo stesso discorso **non** vale per le variabili locali automatiche non inizializzate. Queste ultime infatti sono allocate nello stack e contengono valori "garbage" in quanto non c'è l'azzeramento automatico.

d) Lo scope è lo spazio di codice dove è possibile accedere ad una data variabile. Per le tre variabili locali lo scope coincide con la funzione `main`. Per le due variabili globali lo scope è appunto "globale", questo significa che le variabili sono visibili in tutto il file, anche da altre funzioni. Se una variabile globale viene dichiarata con `extern` è visibile anche in altri files. È importante distinguere il concetto di scope con il concetto di **durata** di una variabile, ovvero l'arco temporale nel quale la variabile esiste in memoria. La variabile locale automatica ha durata solamente fino alla fine della funzione mentre le variabili statiche o globali (sia inizializzate che non) hanno durata pari a tutta l'esecuzione del programma.
