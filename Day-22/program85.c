#include <stdio.h>

int main() {
    char str[100];
    int i,j,flag=0;
    printf("Input a string== ");
    fgets(str,sizeof(str),stdin);

    for(i=0;str[i]!='\0';i++)
     {
        if (str[i]=='\n') 
        {
            str[i]='\0';
            break;
        }
    }

    for(j=0;str[j]!='\0';j++);

    j=j-1;

    for(i=0;i<j;i++,j--) {
        if (str[i]!=str[j]) {
            flag=1;
            break;
        }
    }

    if (flag == 0)
        printf("String is palindrome\n");
    else
        printf("String is not palindrome\n");

    return 0;
}