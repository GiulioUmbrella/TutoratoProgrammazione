#include <stdio.h>
#include <string.h>

#define MAXLINE 5000                            /* max lines to be sorted*/

char *lines_ptr[MAXLINE];                        /* array of pointers to pointer*/

int  read_lines(char *lines_ptr[], int nlines);  /* get all the line */
void write_lines(char *lines_ptr[], int nlines); /* print the line */
void sort_lines(char *lines_ptr[], int left, int right);   /* sort the ponters */
int  get_line(char s[], int lim);
char *alloc(int n);
void afree(char *p);
void str_cpy(char *s, char *t);
void sort_lines(char *v[], int left, int right);
void swap(char *v[],int i, int j);

int main()
{
    /* Sort  */
    int nlines;
    if ((nlines = read_lines(lines_ptr, MAXLINE)) >= 0){
        sort_lines(lines_ptr, 0, nlines-1);
        write_lines(lines_ptr,nlines);
    }

    return 0;

}

void sort_lines(char *v[], int left, int right)
{
    int i, last;

    if(left >= right)
        return;

    swap(v, left, (left+right)/2);
    last = left;
    for(i = left+1; i <= right; i++)
        if(strcmp(v[i], v[left]) <0 )
            swap(v,++last,i);
    swap(v, left, last);
    sort_lines(v,left, last-1);
    sort_lines(v,last+1,right);

}

void swap(char *v[],int i, int j)
{
    char *temp;
    
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* readlines */
#define MAXLEN 1000                              /* Max length of any input line*/
// int get_line(char *, int);                        /* get single line */
// char *alloc(int);                                /* buffer for all the lines*/

/* read input lines from standard input
   - allocates lines in alloc memory
   - produce a side effect for array of pointers
   - return number of lines
*/
int read_lines(char *lines_ptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    while( (len = get_line(line, MAXLEN)) > 0)               /* carry on until you have line*/
        if(nlines >= maxlines || (p = alloc(len)) == NULL  ) /* check memory and max lines number*/
            return -1;                                       /* signal an error */
        else {
            line[len - 1] = '\0';                            /* replace new line with end of string */ 
            str_cpy(p, line);                                 /* copy string in buffer */  
            lines_ptr[nlines++] = p;                         /* get pointer */
        }
        
    return nlines;

}

/* writelines */
void write_lines(char *lines_ptr[], int nlines)
{
    int i;

    for(i = 0; i < nlines; i++)
        printf("%s\n", *(lines_ptr + i));
}

/* strcpy: copy t to s;*/
void str_cpy(char *s, char *t)
{
    while(( *s++= *t++) != '\0')
        ;
}



#define ALLOCSIZE 10000                          /* total storage*/

static char allocbuf[ALLOCSIZE];                 /* set aside memory */
static char *allocp = allocbuf;                  /* intial pointer */

/* prepare a space for n byte and return pointer to the region*/
char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n){     /* check room */
        allocp += n;                             /* update pointer*/
        return allocp - n;                       /* return pointer to data*/ 
    }
    else                                         /* not enough room */
        return 0;
    

}


/* free storage  */
void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE);
}




/* Getline */
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
