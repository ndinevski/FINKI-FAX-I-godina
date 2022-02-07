/*
Од стандарден влез се чита еден природен број n, по што се читаат n цели броеви. 
Да се најде најголемата разлика помеѓу два броја, од вака внесените броеви.
*/
#include <stdio.h>
#include <math.h>

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    int gap=abs(arr[0]-arr[1]);
    for(int i=0;i<n-1;i++){
        for(int j=1;j<n-i;j++){
            if(abs(arr[i]-arr[i+j])>gap){
                gap=abs(arr[i]-arr[i+j]);
            }
        }
    }
    printf("Najgolema razlika: %d", gap);
    return 0;
}