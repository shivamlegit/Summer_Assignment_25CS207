#include<stdio.h>
int main()
 {
    char str[200];
    int i,count=0;
    printf("write a sentence: ");
    fgets(str, sizeof(str), stdin);

    for(i=0;str[i]!='\0'; i++) {
        if (str[i]=='\n') {
            str[i]='\0';
            break;
        }
    }

    for (i=0;str[i]!='\0';i++)
     {
        if (str[i]==' ') {
            count++;
        }
    }

    if (str[0]!='\0') {
        count++;
    }

    printf("Number of words are = %d\n", count);

    return 0;
}