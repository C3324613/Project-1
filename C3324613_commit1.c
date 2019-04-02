#include <stdio.h>

int main()
{
  int index; // counter for encrypting and decrypting in for loops
  const int KEY = 2; // cipher key is equal to 15, written as KEY to show const
  char message[] = "encrypt "; // this is the string that will be encrypted and later decrypted
 
    printf("Cipher key is equal to %d\n", KEY); // print cipher key is equal to 15
  
    printf("Message to encrypt is: %s\n", message); // print message before encryption to show user
    
    for(index = 0; message[index] != 0; index++){
        message[index] = message[index] - KEY;
    
    }
    printf("encrypted message is %s\n", message);
    
    for(index = 0; message[index] != 0; index++){
        message[index] = message[index] + KEY;
    }
   
    printf("decrypted message is %s\n", message);

return 0;
}
