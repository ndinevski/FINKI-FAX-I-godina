/*
Да се напише функцијата matematickaOperacija (int a, int b, char operation, int rezultat) која што нема да враќа резултат. Целта на функцијата е врз основа на аргументот operation да изврши 
определена математичка операција, и резултатот од истата да го смести во rezultat. Возможни вредности за operation се: + - * / %
*/
#include<stdio.h>
#include<string.h>

void matematickaOperacija (int a, int b, char operation, int *rezultat){
    switch(operation){
        case '+':
            *rezultat = a+b;
            break;
        case '-':
            *rezultat = a-b;
            break;
        case '/':
            *rezultat = a/b;
            break;
        case '*':
            *rezultat = a*b;
            break;
        case '%':
            *rezultat = a%b;
            break;
    }
}

int main () {
    
    int a,b,rezultat;
    
    scanf("%d %d", &a, &b);
    
    char * operacii = "+-*/%";
    
    int i;
    for (i=0;i<strlen(operacii);i++) {
        matematickaOperacija(a,b,operacii[i],&rezultat);
        printf("%d %c %d -> %d\n", a, operacii[i], b, rezultat);
    }
    
	return 0;
}