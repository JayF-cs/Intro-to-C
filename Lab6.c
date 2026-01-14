#include <stdio.h>


void print_triangle(int max);

int main() {

    int max;
    int choice;
    int numTriangle;
    
    while(1){
        printf("Enter max value: ");
        scanf("%d",&max);
        printTriangle(max);
        numTriangle++;
        printf("Enter 0 for exit or any other digit to continue: ");
        scanf("%d", &choice);
        if(!(choice)){
            break;
        }
    }

    printf("Total triangle printed: %d", numTriangle);

return 0;
}

void print_triangle(int max){
    
    for(int i = 1; i <= max; i++){
        int j = 1;
        while(j <= max - i){
            printf(" ");
            j++;
        }
        for(int l = 0;l<=i;l++){
            printf("%d",l);
        }
        for(int k = i-1; k >= 1;k--){
            printf("%d",k);
        }
        printf("\n");
    }
}