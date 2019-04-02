#include <stdio.h>

int main()
{
  
  const int KEY = 2; // cipher key is equal to 15, written as KEY to show const
  char message[] = "encrypt"; // this is the string that will be encrypted and later decrypted
 
    printf("Cipher key is equal to %d\n", KEY); // print cipher key is equal to 15
  
    printf("Message to encrypt is: %s\n", message); // print message before encryption to show user
    

return 0;
}
