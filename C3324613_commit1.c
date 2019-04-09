#include<stdio.h>

char encryption(char* message, int index, const int KEY);
char decryption(char* message, int index, const int KEY);


int main(){
    
    int index = 0;
    char message[] = "cat's and dog's";
    const int KEY = 2;
    
    printf("Message to encrypt is : %s\n", message);
    
    encryption(message, index, KEY);
    
    printf("Encyrpted message is : %s\n", message);
    
    decryption(message, index, KEY);
    
    printf("Decrypted message is : %s\n", message);
    
    
    
    
    
    return 0;

}

char encryption(char* message, int index, const int KEY){
    
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
    return message[index];
}

char decryption(char* message, int index, const int KEY){
    
    for(index = 0; message[index] != 0; index++) { // takes each char in the string 'message' and assigns it a new ASCII value
        
        if((message[index] > 64 && message[index] < 91) || (message[index] > 96 && message[index] < 123)){  //checks for ASCII values which are not letters
            
            message[index] = ((message[index] - 65) - KEY) % 26 + 65;  
            /* sets each letter in message to an ASCII value between 0-25 by minusing 65 as A = 65
               adds the cipher key value to assign it a new ASCII value
               takes the modulus of 26 to prevent characters being encrypted into characters which are not letters
               adds 65 back to value to re-assign it an ASCII value which is a character                 
            */
           }
           
        else{ }
           
    }
    return message[index];
}