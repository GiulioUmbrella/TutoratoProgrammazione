#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void reverse_line(char s[], int len);

int main()
{
    int len;
    char line[MAXLINE];
    
    while( (len = get_line(line, MAXLINE)) > 0){
        reverse_line(line, len);
        printf("%s",line);
    }
    
    return 0;
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

void reverse_line(char s[], int len){
    
    // Dichiarazione variabili
    int i,j,tmp;

    // Inizializzo variabili
    i = 0;
    j = len - 1;

    // Non includere nuova riga
    if(s[j] == '\n')
        j--;
    
    while(i < j){
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;    
    }

}






/* */
// void reverse_line(char s[], int len){
    
//     int i,j,tmp;
    
//     for(i = 0, j = len - 2  ; i < j; i++, j--){
//         tmp = s[i];
//         s[i] = s[j];
//         s[j] = tmp;
//     }

// }

/* */
// int get_line(char s[], int lim)
// {
//     int c,i;

//     for(i = 0; i < lim -1 && (c = getchar())!= EOF && c!= '\n'; i++)
//         s[i] = c;

//     if(c == '\n'){
//         s[i] = c;
//         i++;
//     }

//     s[i] = '\0';
//     return i;
// }