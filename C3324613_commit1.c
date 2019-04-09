#include <stdio.h>

int main()
{
  int index; // counter for encrypting and decrypting in FOR loops
  const int KEY = 2; // cipher key is equal to 15, written as KEY to show const
  char message[] = "jacob is bad at programming%^&($#@!"; // this is the string that will be encrypted and later decrypted
 
    printf("Cipher key is equal to %d\n", KEY); // print cipher key is equal to 15
  
    printf("Message to encrypt is : %s\n", message); // print message before encryption to show user
    
    for(index = 0; message[index] != 0; index++) { // takes each char in the string 'message' and assigns it a new ASCII value
        
        if((message[index] > 64 && message[index] < 91) || (message[index] > 96 && message[index] < 123)){  //checks for ASCII values which are not letters
            
            message[index] = ((message[index] - 65) + KEY) % 26 + 65;  
            /* sets each letter in message to an ASCII value between 0-25 by minusing 65 as A = 65
               adds the cipher key value to assign it a new ASCII value
               takes the modulus of 26 to prevent characters being encrypted into characters which are not letters
               adds 65 back to value to re-assign it an ASCII value which is a character                 
            */
           }

           
        else{ }
           
    }
    
    printf("encrypted message is : %s\n", message);// prints to the new encrypted message to the console
    
   

return 0;
}
