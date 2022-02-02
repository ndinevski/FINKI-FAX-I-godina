#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void reverseWord(char s[], int begin, int end)
{
    char tmp;
    while(begin<end)
    {
        tmp=s[begin];
        s[begin]=s[end];
        s[end]=tmp;
        begin++;
        end--;
    }
}
int main()
{
    char s[100];
    gets(s);
    int begin, end;
    begin=0;
    end=0;
    while(s[end])
    {
        for(end=begin; s[end] && s[end]!=' ' ;end++);
        reverseWord(s, begin, end-1);
        begin=end+1;
    }
    puts(s);
    return 0;
}