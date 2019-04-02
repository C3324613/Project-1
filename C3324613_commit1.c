#include <stdio.h>

int main()
{
  int index; // counter for encrypting and decrypting in for loops
  const int KEY = 2; // cipher key is equal to 15, written as KEY to show const
  char message[] = "encrypt"; // this is the string that will be encrypted and later decrypted
 
    printf("Cipher key is equal to %d\n", KEY); // print cipher key is equal to 15
  
    printf("Message to encrypt is: %s\n", message); // print message before encryption to show user
    
    for(index = 0; message[index] != 0; index++) { // takes each char in the string 'message' and assigns it a new ASCII value
        
        message[index] = message[index] - KEY;    //e becomes c as 101 - 2 = 99
    
    }
    
    printf("encrypted message is %s\n", message);// prints to the new encrypted message to the console
    
    for(index = 0; message[index] != 0; index++) { // decrypts the encrypted message back to its original form

        message[index] = message[index] + KEY;
    }
   
    printf("decrypted message is %s\n", message); // prints the decrypted message to the console

return 0;
}
