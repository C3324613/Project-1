#include<stdio.h>
#include"Head.h"

void RotEncrypt(char* message, int KEY);// function prototype for Rotational encryption cipher
void RotDecrypt(char* message, int KEY);// function prototype for Rotatioanl decryption cipher
char RotAttack(int index, char* message, char* freq, int KEY);// function prototype for 
void SubEncrypt(char* message, char* SubKEY);
void SubDecrypt(char* message, char* SDKEY);

int main(){
    
    int Repeat = 0;// variable used to determine if program will repeat
    int choice = 0;// used to select users choice
    int index = 0; // used to
    int i = 0;
    int counter = 0;
    int n = 65;
    int KEY = 0;// key for rotation cipher
    //char freq[26];
    char k[] =      "11111111111111111111111111"; // key string for rotational cipher, only used to display info to user
    char a[] =      "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // used to generate the decrytpion string 'SDKEY' for substitution
    char SubKEY[] = "11111111111111111111111111"; // substitution cipher encryption key
    char SDKEY[] =  "11111111111111111111111111"; // placeholder for auto generated substitution decryption key
    char message[1024]; // string that will store message that will be encrypted/ decrypted

    printf("Please enter any message you would like to use...\n\n");// prompts the user to enter a message they would like to decrypt
    scanf("%[^\n]s", message);// takes the users input via stdin/out and stores it in the string 'message'
   
    for(index = 0; message[index] != 0; index++){
       
        if(message[index] >= 97 && message[index] <= 122){
           
            message[index] -= 32;
        } 
    } /*the above code checks for lowercase letters and changes them to uppercase
        It does this by checking for ASCII values that match lowercase characters
        and then minusing 32 from to convert to uppercase */
       
    MenuRepeat:{
        
        //do nothing
    }
   
    printf("You entered : %s\n\n", message);// prints the users message to the terminal (will appear capitalised always)
    printf("Choose a ciphering method by entering a number from the options below...\n\n");
   
    printf("||CIPHERING METHODS||\n\n");
    printf("[1] Rotational cipher encryption\n\n");
    printf("[2] Rotational cipher decryption with key\n\n");
    printf("[3] Substitution cipher encryption\n\n");
    printf("[4] Substitution cipher decryption with key\n\n");
   
    Invalid:{
        
        //do nothing
    }  
    
    scanf("%d", &choice);
    
   
    switch(choice){
       
        case 1: printf("You chose Rotational cipher Encryption\n\n");
                printf("Please enter a KEY to encrypt with between 0 and 26...\n\n");
                scanf("%d", &KEY);
                
                KEY = KEY % 26;
                    
                for (index = 0; a[index] !=0; index++){
    
                    k[index] = ((a[index] - 65 + KEY) % 26) + 65;
                }

                printf("--%s--\n", a);
                printf("--||||||||||||||||||||||||||--\n");
                printf("--%s--\n\n", k);
                printf("The KEY has been set to %d\n\n", KEY);
                printf("The message you entered earlier will now be encrypted...\n\n");
                printf("Message to encrypt is      : %s\n", message);
                RotEncrypt(message, KEY);
                printf("Encrypted message is       : %s\n", message);
            
                break;
                
        case 2: printf("You chose Rotational cipher decryption with a known key\n\n");
                printf("Please enter a KEY to decrypt with between 0 and 26...\n\n");
                scanf("%d", &KEY);
                
                for (index = 0; a[index] !=0; index++){
    
                    k[index] = ((a[index] - 65 - KEY + 26) % 26) + 65;
                }

                printf("--%s--\n", k);
                printf("--||||||||||||||||||||||||||--\n");
                printf("--%s--\n\n", a);
                printf("The KEY has been set to %d\n\n", KEY);
                printf("The message you entered earlier will now be decrypted...\n\n");
                printf("Message to decrypt is      : %s\n", message);
                RotDecrypt(message, KEY);
                printf("decrypted message is       : %s\n", message);
                
                break;
                
        case 3: printf("You chose Substitution cipher encryption\n\n");
                printf("Please assign each letter of the alphabet a new letter starting from A-Z\n\n");
                scanf("%s", SubKEY);
                
                for(index = 0; SubKEY[index] != 0; index++){
       
                    if(SubKEY[index] >= 97 && SubKEY[index] <= 122){
           
                    SubKEY[index] -= 32;
                    }
                }
                
                while( counter <= 26){
			
	               for(index = 0; SubKEY[index] != 0; index++){
						
	                   if ((SubKEY[index]) == n){
					
					       SDKEY[i] = a[index];	
		               }	
			
	               }
			
		           counter++;
                   n++;
		           i++;
		           index = 0;
                }
                
                printf("--%s--\n", a);
                printf("--||||||||||||||||||||||||||--\n");
                printf("--%s--\n\n", SubKEY);
                printf("The KEY has been set to %s\n\n", SubKEY);
                printf("The message you entered earlier will now be encrypted...\n\n");
                printf("Message to encrypt is      : %s\n", message);
                SubEncrypt(message, SubKEY);
                printf("encrypted message is       : %s\n", message);
                
                break;
                
        case 4: printf("You chose Substitution cipher decryption with a known key\n\n");
                printf("Please enter the string of letters/ KEY used to encrypt the message you want to decrypt\n\n");
                printf("The program will auto-generate a decryption key based on your encryption key\n\n");
                scanf("%s", SubKEY);
                printf("Generating...\n\n");
                
                for(index = 0; SubKEY[index] != 0; index++){
       
                    if(SubKEY[index] >= 97 && SubKEY[index] <= 122){
           
                       SubKEY[index] -= 32;
                    }
                }
                
                while( counter <= 26){
			
	               for(index = 0; SubKEY[index] != 0; index++){
						
	                   if ((SubKEY[index]) == n){
					
					       SDKEY[i] = a[index];
        				   printf("KEY : %s\n", SDKEY);	
		              }	
			
	               }
			
		          counter++;
                  n++;
		          i++;
		          index = 0;
                }
                
                printf("\n");
                printf("--%s--\n", SubKEY);
                printf("--||||||||||||||||||||||||||--\n");
                printf("--%s--\n\n", SDKEY);
                printf("The KEY has been set to %s\n\n", SDKEY);
                printf("The message you entered earlier will now be decrypted...\n\n");
                printf("Message to decrypt is      : %s\n", message);
                SubDecrypt(message, SDKEY);
                printf("Decrypted message is       : %s\n", message);
                
                break;
                
        default: printf("INVALID CHOICE...PLEASE TRY AGAIN...\n\n");
        
                goto Invalid;
           
   }
   
    printf("[1] Go back to Menu\n\n");
    printf("[0] Exit the program\n\n");
    
    scanf("%d", &Repeat);
    
    
    if(Repeat == 1){
        
        goto MenuRepeat;
        
    }
    
    else{
        
       printf("END OF PROGRAM\n"); 
    }
    

    return 0;
      
}
 
     
