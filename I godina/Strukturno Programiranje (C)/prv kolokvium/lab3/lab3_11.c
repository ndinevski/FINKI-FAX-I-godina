/*
Да се напише програма во која од стандарден влез се чита мобилен број во следниот формат 
XXYYYZZZ (пр. 71298486). Програмата треба да го испечати во формат XXX/YYY-ZZZ 
(пр. 071/298-486). Дополнително, треба да го испечати и името на иницијалниот оператор:

070/071/072 - T-Mobile,
075/076/077/078 - А1.
079 - Lycamobile
*/
#include <stdio.h>

int main(){
    int phone;
    scanf("%d", &phone);
    printf("0%d/%03d-%03d", phone/1000000, (phone/1000)%1000, phone%1000);
    switch(phone/1000000){
        case 70:
        case 71:
        case 72:
            printf(" T-mobile");
            break;
        case 79:
            printf(" LycaMobile");
            break;
        default:
            printf(" A1");
    }
    return 0;
}