#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXSTRINGS 100
#define MAXLENGTH 51

void convert_to_lower(char str[]);

void selection_sort(char arr[][MAXLENGTH], int n);

int main(){

    int input;
    char strings[MAXSTRINGS][MAXLENGTH];
    char search[MAXLENGTH];
    int found = 0;

    printf("Enter how many names: ");
    scanf("%d", &input);
    while (getchar() != '\n' && getchar() != EOF);

    for(int i =0; i < input; i++){

        printf("Name %d: ", i + 1);

        fgets(strings[i], MAXLENGTH, stdin);

        strings[i][strcspn(strings[i], "\n")] = '\0';

        convert_to_lower(strings[i]);
    }

    selection_sort(strings, input);

    printf("Sorted Names:\n");
    for(int i = 0; i < input; i++){
        printf("%s\n", strings[i]);
    }


    while(1){
        
        printf("\nEnter search string: ");
        fgets(search,MAXLENGTH,stdin);
        search[strcspn(search, "\n")] = '\0';
        convert_to_lower(search);

        if(strcmp(search,"exit") == 0){
            printf("bye!");
        }

        for(int i = 0; i < input; i++){
            if(strstr(strings[i],search) != NULL){
                printf("%s\n",strings[i]);
                found++;
            }
        }

        if(!found)
            printf("not found\n");

    }

    return 0;
}

void convert_to_lower(char str[]){
    for(int i = 0; str[i] != '\0'; i++){
        str[i] = tolower(str[i]);
    }
}

void selection_sort(char arr[][MAXLENGTH], int n){
    int i, j, minIndex;
    char temp[MAXLENGTH];

    for(int i = 0; i < n - 1; i++){
        minIndex = i;
        for(int j = i + 1; j < n; j++){
            if(strcmp(arr[j],minIndex) < 0){
                minIndex = j;
            }
        }

        strcpy(temp, arr[i]);
        strcpy(arr[i], arr[minIndex]);
        strcpy(arr[minIndex], temp);

    }

}