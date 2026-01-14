#include <stdio.h>
#include <ctype.h>
#define MAXCHAR 50

void getData(char arr[], int *n, int counters[26]);
void displayStat(int *c, int total_char);
void reverse(char a[], int size);
void char_swap(char *x, char *y);
void displayArr(char *a, int size);

int main(void) {
    
    //Declare arrays and variables
    int counters[26];
    char myArr[MAXCHAR]; //MAXCHAR was hash defined to 50
    int i, total_char;

    //Fill the counter array with zeros
    for(i=0; i<26; i++)
        counters[i] = 0;
    
    //Call get data functions
    getData(myArr, &total_char, counters);
    
    //Display array
    displayArr(myArr, total_char);

    //Display the stats
    displayStat(counters, total_char);

    //Reverse array in place
    reverse(myArr, total_char);
    printf("Array reversed.\n");

    //Display array again
    displayArr(myArr, total_char);

    return 0;
}

void getData(char arr[], int *total_chars, int counters[26]){

    //Prompt and take user input
    printf("How many characters? : ");
    scanf("%d", total_chars);

    //Clear newline character
    int x;
    while(((x = getchar())!='\n') && x!= EOF);

    //Take character input
    for(int i = 0; i < *total_chars; i++){
        printf("Enter character %d: ",i + 1);
        scanf("%c",&arr[i]);
            int y;
            //Clear the newline character
            while(((y = getchar())!='\n') && x!= EOF);
        
        //Make sure its a letter and if its capital lowercase it
        if (arr[i] >= 'a' && arr[i] <= 'z') {
                counters[arr[i] - 'a']++;
            } else if (arr[i] >= 'A' && arr[i] <= 'Z') {
                arr[i] = tolower(arr[i]); 
                counters[arr[i] - 'a']++;
            }
    }

}

void displayStat(int *c, int total_char){

    //Iterate through stat array and display
    for(int i = 0; i < 26; i++){
        printf("%c\t%d\t%.2lf\n",'a'+i,c[i],100.0 * c[i] / total_char);
    }
}

void char_swap(char *x, char *y) {
    //Swap in place
    char temp = *x;
    *x = *y;
    *y = temp;
}

void displayArr(char *a, int size) {

    //Iterate through and display array
    printf("The char array: ");
    for(int i = 0; i < size; i++) {
        printf("%c ", a[i]);
    }
    printf("\n");   
}

void reverse(char a[], int size){

    //Iterate through first half of array and swap values of with other half
    for(int i = 0; i < size/2; i++){
        char_swap(&a[i],&a[size - i -1]);
    }
}