#ifndef VARIABLE
#define VARIABLE
/*int menu(int choice){
    
    switch(choice){
        case 1: printf("You have chosen to encrypt a message using a rotation cypher!\n");
                break;
        case 2: printf("You have chosen to decrypt a message encrypted by a rotational cypher with a known KEY!\n");
                break;
        case 3: printf("You have chosen to encrypt a message with a substition cypher\n");
                break;
        default: printf("INVALID INPUT...PLEASE TRY AGAIN\n");
                break;
    }
}*/

char encryption(char* message, int index, const int KEY){
    
    for(index = 0; message[index] != 0; index++) { // takes each char in the string 'message' and assigns it a new ASCII value
        
        if((message[index] > 64 || message[index] < 91 )){  //checks for ASCII values which are not letters. i.e punctuation characters, etc.   x x 
            
            message[index] = (((message[index] - 65) + KEY) % 26) + 65;  
            /* sets each letter in message to an ASCII value between 0-25 by minusing 65 as a = 65
               adds the cipher key value to assign it a new ASCII value
               takes the modulus of 26 to prevent characters being encrypted into characters which are not letters
               adds 65 back to value to re-assign it an ASCII value which is a character                 
            */
        }
      
    }
    return message[index];// returns the new encrypted message in the string 'message'
}

char decryption(char* message, int index, const int KEY){
    
    for(index = 0; message[index] != 0; index++) { // cycles through each character in the string message
        
        if((message[index] > 64 && message[index] < 91)){  //checks for ASCII values which are not letters
            
            message[index] = (((message[index] - 65) - KEY + 26) % 26) + 65;  
            /*  modulus of negative values doesn't behave properly in che
                by adding 26 to the result the correct modulus can be calculated
                Otherwise operates the same an encryption formula except the KEY value is minused
            */
        } 
           
    }
    return message[index];// returns the decrypted message in the string 'message'
}
#endif