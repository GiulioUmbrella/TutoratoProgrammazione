---
title: Tutorato 01 Programmazione
author: Giulio Umbrella
geometry: margin=2cm
toc: true
numbersections: true
output:
  pdf_document:
    highlight: zenburn 
---

# Sort

Lo scopo di questo programma e' costruire un programma sort per ordine in modo lessicografico un testo in input. Per farlo sviluppiamo i seguenti punti:

1. **Gestione memoria**: un esempio di come gestire la memoria
2. **Funzione alloc**: struttura dati elementare per conservare stringhe di lunghezza diversa
3. **Funzione sort**:  ordiniamo le stringhe del punto precedente tramite puntatori a puntatori

# Gestione memoria

## Interpretazione della memoria

Per prima cosa analizziamo il seguente programma:

```c
#include <stdio.h>

int main()
{
    int i [2];
    i[0] = 1819633991;
    i[1] = 28521;
    
    char *s = &i;

    printf("Ciao %s\n",s);
    printf("%c\n",s[0]);

}
```

Abbiamo un *array* con due interi e un puntatore di tipo stringa indirizzato all'array e infine una stampa. Il comportamento e' anomalo, salviamo dei valori in memoria come interi ma poi vi accediamo come una stringa.   

Se proviamo ad eseguire il programma otteniamo il seguente output:

```bash
Ciao Giulio
```
Quindi dei valori numeri - apparentemente casuali - vengono in realta' interpretati come una stringa. Per capire cosa succede dobbiamo studiare i valori che sono salvati in memoria e capire che **non** si tratta di valori scelti a caso. 

Possiamo partire dalle seguenti considerazioni: 

- La stringa viene stampata correttamente, quindi un byte deve essere zero
- La stringa Giulio e' composta da 6 caratteri, quindi ci sono 6 byte diversi da zero
- L'array *i* e' composto da 2 interi, ciascuno dei quali e' composto da 4 byte, per un totale di 8 byte
- Un numero intero e' in realta' un insieme di 0 e 1
- I char occupano un byte in memoria

Per prima cosa vediamo come sono sono i valori in binario dei due numeri 
- 1819633991 = 01101100011101010110100101000111
- 28521 = 110111101101001

Ciascun indirizzo punta ad un byte, quindi per sempliticita' spachettiamo tutti i byte in una tabella:

| **Address** | **Byte** | **Hex** | **Ascii** |
|-------------|----------|---------|-----------|
|      s      | 01000111 |    47   |     G     |
|     s+1     | 01000111 |    69   |     i     |
|     s+2     | 01110101 |    75   |     u     |
|     s+3     | 01101100 |    6C   |     l     |
|     s+4     | 01101001 |    69   |     i     |
|     s+5     | 01101111 |    6F   |     o     |
|     s+6     | 00000000 |    00   |    Null   |
|     s+7     | 00000000 |    00   |    Null   |

Ora abbiamo un quadro completo

Abbiamo visto come interpretare i valori in memoria. Come possiamo fare il processo inverso? Ossia a partire da un array di caratteri come otteniamo l'equivalente valore intero. Prendiamo come esempio il seguente programma:

```c
int main()
{
    char part1[] = {'G','i','u','l','\0'};
    int *p1 = &part1;

    char part2[] = {'i','o','\0','\0','\0'};
    int *p2 = &part2;

    printf("%d\n",*p1);
    printf("%d\n",*p2);
}
```

Il procedimento e' l'opposto. Salviamo dei valori in memoria come char e assegnamento un puntatore di tipo *int* per dare una interpretazione diversa. 

| La memoria e' blob contiguo di byte. La cosa importante e' l'intepretazione che ne viene data attraverso i puntatori. 

## Utilizzo della memoria

Analizziamo il senguente programma:

```c
int main()
{
    int i [3];
    i[0] = 1868654947;
    i[1] = 1852796160;
    i[2] = 28516;

    char *s = &i;
    char *word1 = s;
    char *word2 = s + 5;

    printf("%s\n",word1);
    printf("%s\n",word2); 
}
```

L'output e' il seguente:

```bash
ciao
mondo
```

La meccanica e' la stessa dell'esempio precedente, solo che adesso stiamo inserendo dei null byte all'interno. In questo modo possiamo utilizzare la memoria per salvare diverse stringhe, ci basta sapere l'indirizzo di memoria del primo char. 

Vediamo come ricavare i valori interi:

```c
int main()
{
    char part1[] = {'c','i','a','o','\0'};
    char part2[] = {'\0','m','o','n','\0'};
    char part3[] = {'d','o','\0','\0','\0'};
    int *p1 = &part1;
    int *p2 = &part2;
    int *p3 = &part3;

    printf("%d\n",*p1);
    printf("%d\n",*p2);
    printf("%d\n",*p3);
}
```

# Alloc

Adesso possiamo scrivere una struttura dati simili

# Grep