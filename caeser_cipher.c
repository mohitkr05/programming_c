/* A basic program to generated an encrypted text from a given plain text using the caeser shift cipher */


#include <stdio.h>
#include <math.h>
#include <string.h>

char caeser_cipher(char plain_char, int key) {
  char cipher_char;
  if (key > 25) {
    key = key - 26;
  }
  cipher_char = (int) plain_char + key;
  return cipher_char;
}

int main () {
  char plain_string[100];
  char encrypted_string[100];
  int shift_count;
  int i;
  printf("\nPlease enter the plain text that has to be encrypted: \n");
  fgets(plain_string,sizeof(plain_string), stdin);

  //printf("%s",plain_string);
  printf("\nPlease enter the shift count:");
  scanf("%d", &shift_count);

  for (i=0;i <strlen(plain_string);i++ ) {

    encrypted_string[i] =  caeser_cipher(plain_string[i],shift_count);

  }

  printf("The encrypted string is : \n%s \n " , encrypted_string);

}
