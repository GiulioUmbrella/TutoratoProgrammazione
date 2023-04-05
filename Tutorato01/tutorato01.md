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
INPUT: array s di n elementi
OUTPUT: array s con elementi in posizione nverita
1. i <- 0
2. j <- n-1
3. while i < j
4.     a[i] <-> a[i]
5.     i <- i+1
6.     j <- j-1
```

Le righe 1. e 2. rappresentano la nostra condizione iniziale; la riga 3. la condizine di permanenza nel ciclo (quando viene violata invochiamo lo stop); mentre le righe 4.-6. l'operazione che performiano ad ogni iterazione.  

## Implementazione 

Adesso possiamo implementare la funzione:

```c 
void reverse_line(char s[], int len){
    
    int i,j,tmp;

    i = 0;
    j = len - 1;

    if(s[j] == '\n')
        j--;
    
    while(i < j){
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;    
    }

    return 0;
}
``` 

Dato un array s, la funzione reverse_line realizza l'inverso *in place*, ossia modifica gli elementi dell'array di input senza creare un nuovo array.   

Per eseguire lo scambio usiamo una variabile `tmp` per salvare il valore di `s[i]` prima di modificarlo.

Notiamo che stiamo aggiungendo un controllo sull'ultimo char dell'array; ne rappresenta una nuova riga decrementiamo il valore di j per preservare la formattazione per riga.

# Get line

Ora possiamo preseguire con la funzione per ottenere la funzione per ottenere una singola riga di testo. Dobbiamo chiarire tre punti: 

1. Come ottenere caratteri in input
2. Capire quando inizia una nuova riga di testo
3. Implementare una funzione per ottenere righe

**NB** vedremo piu' avanti come dare un input al programma; per il momento supponiamo di avere un testo input formato da piu' righe. 

## Caratteri in input

Per ottenere dei caratteri dallo standard input, possiamo usare la funzione `getchar` che prende caratteri dallo standard input. Per l'operazione inversa invece usiamo `putchar`

```c
#include <stdio.h>
int main()
{
    int c;

    c = getchar();
    while( c!= EOF){
        putchar(c);
        c = getchar();
    }
}

```

Notiamo che la condizione di permanenza del ciclo dipende dalla differenza con il valore `EOF`. Si tratta di un valore restituito da C quando arriva alla fine del file. Ricordiamo che un file di testo corrisponde ad un certo numero di caratteri salvati in memoria; quando ho scorso tutti i caratteri, C segnala la cosa restituendo `EOF`.

Scriviamo una versione piu' compatta della funzione nel seguente modo:

```c
#include <stdio.h>
int main()
{
    int c;

    while( (c = getchar()) != EOF)
        putchar(c);
}

```

Con l'espressione `(c = getchar()) != EOF` eseguiamo **due** operazioni:

1. Assegniamo il valore da getchar() in c
2. Il valore assegnato a c viene confrontato con EOF

**NB**: per salvare dei valori di tipo **char** utilizziamo una variabile di tipo **intero**; nei prossimi tutorati capiremo perche' questo tipo di operazioni e' lecito. 


## Nuova riga

Ora che sappiamo come ottenere caratteri dobbiamo capire come spezzare il flusso in input in righe Supponiamo di avere un file con il seguente testo formato da 4 righe.

```
ciao 
sono un 
testo di 
4 righe
```

In realta' il testo viene salvato in **memoria** nel seguente modo:

```
ciao\nsono un\ntesto di\n4 righe
```
Ossia esiste un carattere speciale `\n` che rappresenta la nuova riga. 

Quindi possiamo mettere insieme quanto visto fino ad esso per implementare la funzione. Scorriamo l'input con `getchar` e salviamo i caratteri in un array. Appena incontriamo un carattere di tipo `\n` interrompiamo la procedura. 

## Implementazione

```c
int get_line(char s[], int lim){

    int c, i;

    i = 0;
    while(i < lim -1){
        c = getchar();

        if(c == EOF){
            break;
        }
        else if (c == '\n'){
            s[i] = '\n';
            i++;
            break; 
        } else {
            s[i] = c;
        }
            i++;    
    }

    s[i] = '\0';
    return i; 

}
```

# Reverse text




# Standard input

# Esercizi aggiuntivi

1. Scrivere una funzione line_count che dato un file di testo conta il numero di righe
2. Scrivere una funzione line_length che data una stringa di testo conta il numero di caratteri
3. 
