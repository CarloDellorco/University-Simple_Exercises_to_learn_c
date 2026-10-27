#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define DIM 100
#define ABC 26 //numero di lettere nell'alfabeto

int anagramm( char stringa1[DIM], char stringa2[DIM]);

int anagramm(char stringa1[], char stringa2[]){
  int i, j, t, len1, len2;
  char alfabeto[ABC]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  int maschera1[ABC]={0}; 
  int maschera2[ABC]={0};

  len1 = strlen(stringa1);
  len2 = strlen(stringa2);

  while (i<ABC) {
    for(j=0; j<len1; j++){
      if (isalpha(stringa1[j])) {
        if (isupper(stringa1[j])) {
          stringa1[j]+=32;
        }
        if (stringa1[j]==alfabeto[i]) {
          maschera1[i]++;
        }
      }
    }
    ++i;
  }
//we do the same thing for the second string
i=0;
while (i<ABC) {
  for (t = 0; t < len2; t++) {
    if (isalpha(stringa2[t])) {
      if (isupper(stringa2[t])) {
        stringa2[t]+=32;
      }
      if (stringa2[t]==alfabeto[i]) {
        maschera2[i]++;
      }
    }
  }
  ++i;
}

for ( i = 0; i < ABC; i++) {
  if (maschera1[i]!=maschera2[i]) {
    return 0;
  } else {
    return 1;
  }
}
}


int main(){
  char stringa1[DIM];
  char stringa2[DIM];

  printf("check weather 2 sentences are anagrams:\n");
  printf("first sentence:\n");
  fgets(stringa1, DIM-1, stdin); //prendiamo la prima frase
  fflush(stdin);
  printf("second sentence:\n");
  fgets(stringa2, DIM-1, stdin); //prendiamo la seconda frase
  if (anagramm (stringa1, stringa2)==1) {
    printf("the sentences are anagrams.\n");
  } else {
    printf("the sentences are not anagrams.\n");
  }
}

