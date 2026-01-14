#include <stdio.h>
#include <ctype.h>
#define MAX_LENGTH 101 //maximum string length will be 100 + 1 for '\0'


int getLength(char s[]);
int is_equal(char s1[], char s2[]);
void str_copy(char dest[], char source[]);
void str_reverse(char s[]);
int is_palindrome(char s[]);
void capitalize_word(char *str);
void swap(char *a, char *b);

 

int main(void) {

  char s1[MAX_LENGTH];
  char s2[MAX_LENGTH];
  char x;


  printf("Enter a string: ");
  scanf("%[^\n]s", s1);

  while((x=getchar() != '\n') && x != EOF); //loop to discard \n from last input and not to skip the next input

  printf("Enter another string: ");
  scanf("%[^\n]s", s2);


  printf("\nThe length of your first string is %d\n", getLength(s1));
  printf("The length of your second string is %d\n", getLength(s2));

  if(is_equal(s1, s2)==1)
  {
    printf("You entered two equal strings.\n");
  }
  else
  {
    printf("Your strings are different.\n");
  }

  if(is_palindrome(s1)) //make sure you do not change the string
  {
      printf("%s is a palindrome string\n", s1);
  }
  else
  {
      printf("%s is not a palindrome string\n", s1);

  }

  capitalize_word(s1);
  printf("Capitalized s1 is %s ", s1);


  return 0;
}

int getLength(char s[]){
    int count = 0;
    for(int i = 0; s[i] != '\0';i++){
        count++;
    }
    return count;
}

int is_equal(char s1[], char s2[]){
    for(int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++){
        if(s1[i] != s2[i])
            return 0;
    }

    return 1;
}

void str_copy(char dest[], char source[]){
    int i = 0;
    while(source[i] != '\0'){
        dest[i] = source[i];
        i++;
    }
    dest[i] = '\0';
}

void str_reverse(char s[]){
    int i = getLength(s);
    for(int j = 0; j < i/2; j++){
        swap(&s[j], &s[i-j-1]);
    }
}

void swap(char *a, char *b){

    char temp = *a;
    *a = *b;
    *b = temp;

}

int is_palindrome(char s[]){
    char temp[MAX_LENGTH];
    str_copy(temp, s);
    str_reverse(temp);
    return is_equal(temp, s);
}

void capitalize_word(char *str){

    for(int i = 0; str[i] != '\0'; i++){
        if(i == 0){
            str[i] = toupper(str[i]);
        }else if(str[i - 1] == ' '){
            str[i] = toupper(str[i]);
        }else{
            str[i] = tolower(str[i]);
        }
    }
}