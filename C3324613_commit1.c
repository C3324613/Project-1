#include <stdio.h>

int main()
{
  
  const int KEY = 15; // cipher key is equal to 15, written as KEY to show const
  char message[25];
  
  printf("Cipher key is equal to %d\n", KEY); // print cipher key is equal to 15

  scanf("%s", message); // take user input as message to be encrypted
  
  printf("Message to encrypt is: %s\n", message); // print message before encryption


  return 0;
}
