#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int max);
int str_index(char source[], char pattern[]);

char pattern[] = "bau";

int main()
{
    char line[MAXLINE];
    int found = 0;

    while(get_line(line,MAXLINE) > 0)
        if(str_index(line,pattern) >= 0){
            printf("%s", line);
            found++;
        }
    return found;
}




/* strindxe: return index of ptrn in string, -1 if none*/
int str_index(char str[], char ptr[])
{
    int i, j, k;

    i = 0;
    while(str[i] != '\0' ){

        j = i;
        k = 0;
        while(ptr[k] != '\0' && str[j] == ptr[k]){
            j++;
            k++;
        }

        if(k > 0 && ptr[k] == '\0')
            return i;

        i++;
    }

    // Un valore impossibile in un array
    return -1;

}

int get_line(char s[], int lim){

    int c, i;

    i = 0;
    while(i < lim -1){
        c = getchar();

        if(c == EOF){
            break;
        }
        else if (c == '\n'){
            s[i] = c;
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