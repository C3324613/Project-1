#include<stdio.h>


char encryption(char* message, int index, const int KEY);
char decryption(char* message, int index, const int KEY);
//int menu(int choice);


int main(){
    
    
    /*printf("Welcome to my encryption and decryption program...\n\n");
    printf("Please select from the following menu...\n\n");
    printf("___________________________________\n");
    printf("             M E N U               \n");
    printf("------------------------------------\n\n");
    printf("-1- Encrypt a message using a rotating cypher...\n");
    printf("-2- Decrypt a message encrypted by a rotating cypher with a known key...\n");
    printf("-3- Encrypt a message using a substituion cypher...\n\n");
    printf("___________________________________\n\n");
    printf("waiting for user input...\n\n\n");*/
    
    int index = 0;
    char message[] = "TVU TVAOTH: AOL KHAH IYVBNOA AV BZ IF AOL IVAOHU ZWPLZ WPUWVPUAZ AOL LEHJA SVJHAPVU VM AOL LTWLYVY'Z ULD IHAASL ZAHAPVU. DL HSZV RUVD AOHA AOL DLHWVU ZFZALTZ VM AOPZ KLHAO ZAHY HYL UVA FLA VWLYHAPVUHS. DPAO AOL PTWLYPHS MSLLA ZWYLHK AOYVBNOVBA AOL NHSHEF PU H CHPU LMMVYA AV LUNHNL BZ, PA PZ YLSHAPCLSF BUWYVALJALK. IBA TVZA PTWVYAHUA VM HSS, DL'CL SLHYULK AOHA AOL LTWLYVY OPTZLSM PZ WLYZVUHSSF VCLYZLLPUN AOL MPUHS ZAHNLZ VM AOL JVUZAYBJAPVU VM AOPZ KLHAO ZAHY. THUF IVAOHUZ KPLK AV IYPUN BZ AOPZ PUMVYTHAPVU.";
    const int KEY = 19;
    
    
    
    printf("Encyrpted message is : %s\n", message);
    
    decryption(message, index, KEY);
    
    printf("Decrypted message is : %s\n", message);
     
    return 0;

}

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
        
        if((message[index] > 64 || message[index] < 91 )){  //checks for ASCII values which are not letters
            
            message[index] = ((message[index] - 65) - KEY) % 26 + 65;  
            /* sets each letter in message to an ASCII value between 0-25 by minusing 65 as a = 65
               adds the cipher key value to assign it a new ASCII value
               takes the modulus of 26 to prevent characters being encrypted into characters which are not letters
               adds 65 back to value to re-assign it an ASCII value which is a character                 
            */
       }

           
    }
    return message[index];
}

char decryption(char* message, int index, const int KEY){
    
    for(index = 0; message[index] != 0; index++) { // cycles through each character in the string message
        
        if((message[index] > 64 && message[index] < 91)){  //checks for ASCII values which are not letters
            
            message[index] = (((message[index] - 65) + KEY) % 26) + 65;  
            /*                 
            */
           }
           
        else{ }
           
    }
    return message[index];
}