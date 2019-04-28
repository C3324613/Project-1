#include<stdio.h>
#include"Head.h"

/* CIPHER PROGRAM
 * This program encrypts and decrypts any message using rotational and substitution ciphering methods.
 *  It can be run using the terminal in che and entering all user input through the terminal via stdin 
 *  and the scanf function.
 *  The program will correct all lower case letters entered anywhere through the program to capitals.
 *  The program can be navigated via a basic menu system which requires a user's input through the terminal
 *  by entering the corresponding number with the menu item. Entering a number not available will result in
 *  an error message and a new number can easily be inputted. However, if a letter or any special character 
 *  is inputted the program will break. 
 *  after the encryption/ decryption has been performed the user will be met with a second menu, where they
 *  they can continue or exit the program. If they choose to continue the previous message will still be stored
 *  in the string 'message'.
 */

void RotEncrypt(char* message, int KEY);// function prototype for Rotational encryption cipher
void RotDecrypt(char* message, int KEY);// function prototype for Rotatioanl decryption cipher
char RotAttack(int index, char* message, char* freq, int KEY);// function prototype for 
void SubEncrypt(char* message, char* SubKEY);
void SubDecrypt(char* message, char* SDKEY);

int main(){
    
    int Repeat = 0;// variable used to determine if program will repeat
    int choice = 0;// used to store users choice in the main emenu
    int index = 0; // used to cycle through each letter in strings within main
    int i = 0; // used as second index counter to cycle through the substitution cipher key and generate a decryption key
    int counter = 0; // a counter variable used to generate the decryption key for sub cipher
    int n = 65; // This variable is also used to generate the decryption key for sub cipher
    int KEY = 0;// key for rotation cipher, changes tih user input
    //char freq[26];
    char ROTKEY[] =      "11111111111111111111111111"; // key string for rotational cipher, only used to display info to user
    char ALPHABET[] =      "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // used to generate the decrytpion string 'SDKEY' for substitution
    char SubKEY[] = "11111111111111111111111111"; // substitution cipher encryption key placeholder
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
    printf("Choose a ciphering method by entering a number from the options below...\n\n");// promps the user to select from the below menu
   
    printf("||CIPHERING METHODS||\n\n");// the following is what the user will see as a menu
    printf("[1] Rotational cipher encryption\n\n");
    printf("[2] Rotational cipher decryption with key\n\n");
    printf("[3] Substitution cipher encryption\n\n");
    printf("[4] Substitution cipher decryption with key\n\n");
   
    Invalid:{
        
        //do nothing
    }  
    
    scanf("%d", &choice);// takes the user's input from the menu
    
   
    switch(choice){/* the switch case controls the entire program and acts as the menu system
                     if 1 is inputted by the user than the first case is true and so the following 
                     code is executed, being the first item of the menu list. */
       
        case 1: printf("You chose Rotational cipher Encryption\n\n");
                printf("Please enter a KEY to encrypt with between 0 and 26...\n\n");
                scanf("%d", &KEY);//takes user's input from stdin and stores it in the variable KEY
                
                KEY = KEY % 26;// ensures that the key will always be a number between and including 0-26.
                    
                for (index = 0; ALPHABET[index] !=0; index++){// FOR loop that cycles through each string element of ALPHABET
    
                    ROTKEY[index] = ((ALPHABET[index] - 65 + KEY) % 26) + 65;/* populates ALPHABET string with the encryption key
                }                                                               which will later be shown to user. */

                printf("--%s--\n", ALPHABET);//prints ALPHABET string to display it to the user
                printf("--||||||||||||||||||||||||||--\n");// used to show user what each letter will be encrypted to
                printf("--%s--\n\n", ROTKEY);// Prints the encryption key string ROTKEY to user 
                printf("The KEY has been set to %d\n\n", KEY);//prints the KEY value to the user
                printf("Message to encrypt is      : %s\n", message);// prints the message the user inputted/ previously stored message in the string 'message'
                RotEncrypt(message, KEY);// calls the function RotEncrypt
                printf("Encrypted message is       : %s\n\n", message);// //prints the now encrypted message to the user
            
                break;
                
        case 2: printf("You chose Rotational cipher decryption with a known key\n\n");
                printf("Please enter a KEY to decrypt with between 0 and 26...\n\n");
                scanf("%d", &KEY);//takes user's input from stdin and stores it in the variable KEY
                
                KEY = KEY % 26;// ensures that the key will always be a number between and including 0-26.
                
                for (index = 0; ALPHABET[index] !=0; index++){ // FOR loop that cycles through each string element of ALPHABET
    
                    ROTKEY[index] = ((ALPHABET[index] - 65 - KEY + 26) % 26) + 65;/* populates ALPHABET string with the encryption key
                                                                                     which will later be shown to user. */
                }

                printf("--%s--\n", ROTKEY);// prints the encryption/ decryption key string ROTKEY to user
                printf("--||||||||||||||||||||||||||--\n");// used to show user what each letter of the alphabet will be decrypted to
                printf("--%s--\n\n", ALPHABET);// prints the string ALPHABET to the user
                printf("The KEY has been set to %d\n\n", KEY);// prints the KEY value to the user
                printf("Message to decrypt is      : %s\n", message); // prints the user's message that will be decrypted to the user
                RotDecrypt(message, KEY);// calls the RotDecrypt function
                printf("decrypted message is       : %s\n\n", message);// prints the now decrypted message to the user
                
                break;
                
        case 3: printf("You chose Substitution cipher encryption\n\n");
                printf("Please assign each letter of the alphabet a new letter starting from A-Z\n\n");
                scanf("%s", SubKEY);// takes user's input from stdin and stores it in the string 'SubKEY'
                
                for(index = 0; SubKEY[index] != 0; index++){// FOR loop that cycles through each element of the string SubKEY
       
                    if(SubKEY[index] >= 97 && SubKEY[index] <= 122){
           
                    SubKEY[index] -= 32;
                    }/*the above code checks for lowercase letters and changes them to uppercase
                       It does this by checking for ASCII values that match lowercase characters
                       and then minusing 32 from to convert to uppercase */
                }
                
                printf("--%s--\n", ALPHABET);//Prints the string ALPHABET to the user
                printf("--||||||||||||||||||||||||||--\n");// used to show the user what each letter of the alphabet will be encrypted to
                printf("--%s--\n\n", SubKEY);// prints the string SubKEY to the user
                printf("The KEY has been set to %s\n\n", SubKEY);// prints the string SubKEY to the user
                printf("Message to encrypt is      : %s\n", message);// prints the message the user entered from the string 'message'
                SubEncrypt(message, SubKEY);// calls the function SubEncrypt
                printf("encrypted message is       : %s\n\n", message);// prints the now encrypted message 
                
                break;
                
        case 4: printf("You chose Substitution cipher decryption with a known key\n\n");
                printf("Please enter the string of letters/ KEY used to encrypt the message you want to decrypt\n\n");
                printf("The program will auto-generate a decryption key based on your encryption key\n\n");
                scanf("%s", SubKEY);//takes the user's input from stdin and stores it in the string SubKEY
                printf("Generating...\n\n");
                
                for(index = 0; SubKEY[index] != 0; index++){
       
                    if(SubKEY[index] >= 97 && SubKEY[index] <= 122){
           
                       SubKEY[index] -= 32;
                    }/*the above code checks for lowercase letters and changes them to uppercase
                       It does this by checking for ASCII values that match lowercase characters
                       and then minusing 32 from to convert to uppercase */
                }
                
                while( counter <= 26){ /* WHILE loop that executes 26 times in order to generate a decryption key
                                          for substitution cipher  */
			
	               for(index = 0; SubKEY[index] != 0; index++){ //FOR loop which cycles through each element of the string SubKEY
						
	                   if ((SubKEY[index]) == n){// if the ASCII value of SubKEY at index = n then the code beneath will execute
					
					       SDKEY[i] = ALPHABET[index];/* SDKEY at index (starting at 0) is assigned the ASCII value of ALPHABET 
					                                     at the index value determined by the above if statment. */
        				   printf("KEY : %s\n\n", SDKEY);	// prints the the string 'SDKEY' to the user to show it changing/ generating
		              }	
			
	               }
			
		          counter++;// increments the loop variable 'counter' by 1 until it reaches 26, where the loop will break
                  n++;// increments the value of 'n' by 1, starting at 65-97, which corresponds to the ASCII values A-Z
		          i++;// increments the value of 'i' by 1 to set up the above code to alter the NEXT array element
		          index = 0;// re-initilises 'index' to 0 in order to re-cycle through the string SubKEY to fidn the next matching ASCII value
                }
                
                printf("--%s--\n", SubKEY);// prints the string SubKEY for the user
                printf("--||||||||||||||||||||||||||--\n");// used to show what each letter in the encryption key will become
                printf("--%s--\n\n", SDKEY);// prints the string SDKEY for the user
                printf("The KEY has been set to %s\n\n", SDKEY);// prints the string SDKEY for the user
                printf("Message to decrypt is      : %s\n", message);// prints the message the user enetred earlier which will be encyrpted
                SubDecrypt(message, SDKEY);// calls the function SubDecrypt
                printf("Decrypted message is       : %s\n\n", message);// prints the now decrypted message to the user
                
                break;
                
        default: printf("INVALID CHOICE...PLEASE TRY AGAIN...\n\n");// prints an error message to the user
        
                goto Invalid;// tells the compiler to jump up to the label 'Invalid'
           
   }
   
    printf("[1] Go back to Menu\n\n");// the following is an exit menu which is displayed to the user
    printf("[0] Exit the program\n\n");
    
    scanf("%d", &Repeat);// takes user's input from stdin and stores it int he variable 'Repeat'
    
    
    if(Repeat == 1){// if Repeat = 1 the following code will execute
        
        goto MenuRepeat;// code jumps to the label MenuRepeat as per the user's selection
        
    }
    
    else{// if the above condition is not met the following code executes
        
       printf("END OF PROGRAM\n"); // prints an exit message for the user
    }
    

    return 0;// returns 0 to main and program exits/ finishes
      
    }
}