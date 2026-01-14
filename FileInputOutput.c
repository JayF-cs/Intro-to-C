#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXFILENAME 20

void checkVowel(int *n, char ch);


int main(){
    
    char ch;
    int cTotal = 0;
    int vTotal = 0;
    int dTotal = 0;
    int *p = &vTotal;
    FILE *ifp, *ofp;

    char inFile[MAXFILENAME];
    char outFile[MAXFILENAME];
    scanf("%s", inFile);
    inFile[strcspn(inFile,"\n")] = '\0';
    scanf("%s", outFile);
    outFile[strcspn(outFile,"\n")] = '\0';


    ifp = fopen(inFile,"r");
    ofp = fopen((outFile), "w");
    if(!ifp){
            printf("Error opening file.\n");
            return 1;
    }

    if(!ofp){
        printf("Error opening file.\n");
        return 1;
    }

    ch = fgetc(ifp);
    while(ch != EOF){
        if(ch != '\n')
            cTotal++;
        checkVowel(p, ch);
        if(isdigit(ch)){
            dTotal++;
        }
        printf("%c",ch);
        fputc(toupper(ch),ofp);
        ch = fgetc(ifp);
    }

    printf("\nNumber of characters: %d\n",cTotal);
    printf("Number of vowels: %d\n",vTotal);
    printf("Number of digits: %d", dTotal);

    fclose(ifp);
    fclose(ofp);


    
    return 0;
}

void checkVowel(int *n, char ch){

    if(tolower(ch) == 'a'|| tolower(ch) == 'e' || tolower(ch) == 'i'|| tolower(ch) == 'o'|| tolower(ch) == 'u'){
        (*n)++;
    }

    return;
    
}
