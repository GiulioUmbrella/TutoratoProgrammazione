#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int max);
int word_count(char s[], int len);

int main()
{
    
    int wl;
    int len;

    char line[MAXLINE];
    while((len = get_line(line,MAXLINE)) > 0){
        wl = word_count(line, len);
        printf("%d\n",wl);
    }
       
    return 0;
}





int word_count(char s[], int len)
{
    int i,c,nw,state;

    nw = 0;
    i = 0;
    state = 0;
    
    while(i < len-1)
    {
        c = s[i];
        
        if(c == ' ')
            state = 0;
        else if(state == 0){
            state = 1;
            nw++;
        }

        i++;
    }

    return nw;

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