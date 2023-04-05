---
title: Tutorato 01 Programmazione
author: Giulio Umbrella
geometry: margin=2cm
---

# Reverse

L'obbiettivo e' creare un programma `reverse_text` che prenda in input un testo e esegua il reverse di ciascuna riga.

1. Creare una funzione `reverse_line` che dato un array di char ne inverta la posizione
2. Creare una funzione `get_line` che dato un testo in input estragga una singola riga
3. Creare una programma `reverse_text` che combine le due funzioni

# Reverse line

La funzione `reverse_line` prende in input un array di char di caratteri e ne produce l'inverso; ad esempio dato in input 'CIAO' produce 'OAIC'.  

Per prima cosa vediamo come modellare il problema, poi forniamo una soluzione

## Pseudo codice

Per modellare un array di *n* char possiamo pensare ad un vettore di n elementi con indici che vanno da 0 (primo elemento) a n-1 (ultimo elemento)

Dati due indici i e j, sappiamo che dobbiamo invertire gli **elementi** dell'array a in quella posizione, indichiamo questa operazione con a[i] <-> a[j].

Gli indici i e j **non** possono essere scelti a caso; per invertire il vettore i e j devono avere la stessa distanza da destra e sinistra. Da questa osservazione notiamo che:

- Il valore iniziale di i e' 0 mentre j e' n-1 
- Alla fine di ogni aumentiamo i di 1 e decrementiamo j di 1

Infine, dobbiamo pensare ad una condizione di stop. Intuitivamente, sappiamo che dobbiamo proseguire fino alla meta' dell'array. Possiamo considerare due casi separati array di lunghezza pari e dispari:

- Se l'array e' di lunghezza dispari quando i e j hanno lo stesso valore, siamo arrivati all'elemento centrale e ci possiamo fermare.
- Se invece l'array e' pari, superata la meta' il valore di i superera' il valore di j.

Quindi possiamo la condizione di stop si realizza quando i >= j. In altre parole, rimaniamo all'interno del loop fino a che i < j.

Possiamo formalizzare il problema con il seguente **pseudo codice**; un linguaggio ad alto livello che formalizza il problema nei suoi passaggi fondamentali.

```
1. i <- 0
2. j <- n-1
3. while i < j
4.     a[i] <-> a[i]
5.     i <- i+1
6.     j <- j-1
```

Le righe 1. e 2. rappresentano la nostra condizione iniziale; la riga 3. la condizine di permanenza nel ciclo (quando viene violata invochiamo lo stop); mentre le righe 4.-6. l'operazione che performiano ad ogni iterazione.  

## Implementazione 

Adesso ossiamo implementare la funzione:

```c 
void reverse_line(char s[], int lim)
{

}
``` 


# Get line


# Reverse text

# Standard input

# Esercizi aggiuntivi

1. Scrivere una funzione line_count che dato un file di testo conta il numero di righe
2. Scrivere una funzione line_length che data una stringa di testo conta il numero di caratteri
3. 
