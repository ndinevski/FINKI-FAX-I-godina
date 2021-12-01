#include <stdio.h>

int main(){
    int money,fiveThousands,oneThousands,fiveHundreds,oneHundreds,fifties,
    tens,fives,twos,ones;
    scanf("%d", &money);
    fiveThousands=money/5000;
    oneThousands=(money - (fiveThousands*5000))/1000;
    fiveHundreds=(money - (fiveThousands*5000 + oneThousands*1000))/500;
    oneHundreds=(money-(fiveThousands*5000+oneThousands*1000+fiveHundreds*500))/100;
    fifties=(money-(fiveThousands*5000+oneThousands*1000+
            fiveHundreds*500+oneHundreds*100))/50;
    tens=(money-(fiveThousands*5000+oneThousands*1000+
            fiveHundreds*500+oneHundreds*100+fifties*50))/10;
    fives=(money-(fiveThousands*5000+oneThousands*1000+
            fiveHundreds*500+oneHundreds*100+fifties*50+tens*10))/5;
    twos=(money-(fiveThousands*5000+oneThousands*1000+
            fiveHundreds*500+oneHundreds*100+fifties*50+tens*10+fives*5))/2;
    ones=(money-(fiveThousands*5000+oneThousands*1000+
            fiveHundreds*500+oneHundreds*100+fifties*50+tens*10+fives*5+twos*2))/1;
    printf("%d*5000\n%d*1000\n%d*500\n%d*100\n%d*50\n%d*10\n%d*5\n%d*2\n%d*1",
            fiveThousands,oneThousands,fiveHundreds,oneHundreds,fifties,tens,
            fives,twos,ones);
    return 0;
}