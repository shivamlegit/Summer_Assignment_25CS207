#include<stdio.h>
int main() 
{
    char str[100],rev[100];
    int i,j=0;
    printf("Input a string == ");
    fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] != '\0';i++) 
    {
        if (str[i]=='\n') 
        {
            str[i]='\0';
            break;
        }
    }

    while(str[i-1]!='\0') {
        i--;
    }

    for (i=i-1;i>=0;i--) {
        rev[j]=str[i];
        j++;
    }
    rev[j]='\0';
        printf("Reverse of the string is == %s\n", rev);

    return 0;
}