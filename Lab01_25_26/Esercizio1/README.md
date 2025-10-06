# Esercizio 1

Il comando di compilazione (come visto a lezione) è il seguente

```bash
g++ hello_world.cpp -o hello_world
```

dove:
 - `hello_world.cpp` è il file sorgente
 - `hello_world` è il nome che sto scegliendo per l'eseguibile

È bene ricordare che `g++` linka automaticamente la libreria standard e quindi non è necessario utilizzare il flag `-l`. 
Se invece usassimo `gcc` allora il comando di compilazione sarebbe 
```bash
gcc hello_world.cpp -o hello_world -lstdc++
```

Dopo aver compilato, è possibile lanciare l'eseguibile con `./hello_world`.
