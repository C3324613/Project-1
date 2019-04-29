#ifndef VARIABLE
#define VARIABLE


/* Inputs: user's message in the string 'message[1024]', the key which is entererd by the user through scanf and stored in the variable 'KEY'
 * Return Value: This function returns no data type and so is void. The function alters the string message within the function
 * What it does: The function 'RotEncrypt', encrypts the users message using the rotational encryption method
 * Limitations: limited to a message of length 1024 characaters
 */

void RotEncrypt(char* message, int KEY){
    
    int index = 0; // initialises the variable index and sets it to 0
    
    for(index = 0; message[index] != 0; index++) { // cycles through each string element of the string 'message' until the end of the message is reached
        
        if((message[index] > 64 && message[index] < 91 )){  //checks for ASCII values which are not letters. i.e punctuation characters, etc. 
            
            message[index] = (((message[index] - 65) + KEY) % 26) + 65;  
            /* sets each letter in message to an ASCII value between 0-25 by minusing 65 as a = 65
               adds the cipher key value to assign it a new ASCII value
               takes the modulus of 26 to prevent characters being encrypted into characters which are not letters
               adds 65 back to value to re-assign it an ASCII value which is a character                 
            */
        }
      
    }
    
}

/* Inputs: user's message in the string 'message[1024]', the key which is entererd by the user through scanf and stored in the variable 'KEY'.
 * Return Value: This function returns no data type and so is void. The function alters the string message within the function
 * What it does: The function 'RotDecrypt', decrypts the users message using the rotational decryption method
 * Limitations: limited to a message of length 1024 characaters
 */

void RotDecrypt(char* message, int KEY){
    
    int index = 0;// initialises the variable index and sets it to 0
    
    for(index = 0; message[index] != 0; index++) { // cycles through each character/ string element in the string 'message'
        
        if((message[index] > 64 && message[index] < 91)){  //checks for ASCII values which are not letters. i.e punctuation characters, etc.
            
            message[index] = (((message[index] - 65) - KEY + 26) % 26) + 65;  
            /*  modulus of negative values doesn't behave properly in che
                by adding 26 to the result the correct modulus can be calculated
                Otherwise operates the same the encryption formula except the KEY value is minused
            */
        } 
           
    }
    
}
/*
 * 
 * 
 * 
 * 
 */

void RotAttack(char* message){
    
    int KEY = 0;
    int index = 0, index1 = 0, index2 = 0;
    //char messageCheck[1024];
    
    for(index = 0; message[index] != 0; index ++){
         
         //messageCheck[index] = message[index];
    }
    
    for(index = 0; message[index] != 0; index++){
        
        index1 = index++;
        index2 = index + 2;
        printf("test2\n\n");
        
        if(message[index] == 32 && message[index2] == 32){
            
            KEY = message[index1] - 65;
            
            printf("test\n\n");
            printf("key is : %d\n\n", KEY);
            
            goto KEYFound;          
        }
    }
    
    KEYFound:{
        
        //do nothing
    }
    
    for(index = 0; message[index] != 0; index++) { // cycles through each character/ string element in the string 'message'
        
        if((message[index] > 64 && message[index] < 91)){  //checks for ASCII values which are not letters. i.e punctuation characters, etc.
            
            message[index] = (((message[index] - 65) - KEY + 26) % 26) + 65;  
            /*  modulus of negative values doesn't behave properly in che
                by adding 26 to the result the correct modulus can be calculated
                Otherwise operates the same the encryption formula except the KEY value is minused
            */
        } 
           
    }
    
    
}

/* Inputs: user's message in the string 'message[1024]', the key which is entererd by the user through scanf into the string 'SubKEY'.
 * Return Value: This function returns no data type and so is void. The function alters the string message within the function
 * What it does: The function 'SubEncrypt', encrypts the users message using the substitution encryption method
 * Limitations: limited to a message of length 1024 characaters
 */

void SubEncrypt(char* message, char* SubKEY){
    
    int n;// initialises the variable n 
    int index = 0;// initialises the vairable index and sets it to 0
    
        for(index = 0; message[index] != 0; index++){// FOR loop that cycles through the string elements in the string 'message'
        
            n = message[index];// sets n to be equal to the value of message at the current index
        
            switch(n){// switch case statement for the value of n, corresponding to the current message[index]/ ASCII value
            
                case 65 : // switch case, where 65 corresponds to the decimal value for the ASCII character 'A'
                        message[index] = SubKEY[0];// sets the current value of message at index to be equal to SubKEY, where index = 0
                        break;
                case 66 :
                        message[index] = SubKEY[1];
                        break;
                case 67 : 
                        message[index] = SubKEY[2];
                        break;
                case 68 : 
                        message[index] = SubKEY[3];
                        break;
                case 69 : 
                        message[index] = SubKEY[4];
                        break;
                case 70 : 
                        message[index] = SubKEY[5];
                        break;
                case 71 : 
                        message[index] = SubKEY[6];
                        break;
                case 72 : 
                        message[index] = SubKEY[7];
                        break;
                case 73 : 
                        message[index] = SubKEY[8];
                        break;
                case 74 : 
                        message[index] = SubKEY[9];
                        break;
                case 75 : 
                        message[index] = SubKEY[10];
                        break;
                case 76 : 
                        message[index] = SubKEY[11];
                        break;
                case 77 : 
                        message[index] = SubKEY[12];
                        break;
                case 78 : 
                        message[index] = SubKEY[13];
                        break;
                case 79 : 
                        message[index] = SubKEY[14];
                        break;
                case 80 : 
                        message[index] = SubKEY[15];
                        break;
                case 81 : 
                        message[index] = SubKEY[16];
                        break;
                case 82 : 
                        message[index] = SubKEY[17];
                        break;
                case 83 : 
                        message[index] = SubKEY[18];
                        break;
                case 84 : 
                        message[index] = SubKEY[19];
                        break;
                case 85 : 
                        message[index] = SubKEY[20];
                        break;
                case 86 : 
                        message[index] = SubKEY[21];
                        break;
                case 87 : 
                        message[index] = SubKEY[22];
                        break;
                case 88 : 
                        message[index] = SubKEY[23];
                        break;
                case 89 : 
                        message[index] = SubKEY[24];
                        break;
                case 90 : 
                        message[index] = SubKEY[25];
                        break;     
                default :// if any ASCII value doesn't fall into the above cases (i.e. special characters, numbers, etc.) they will be ignored
                        break;
            }  
       }  
}

/* Inputs: user's message in the string 'message[1024]', the key which is generated by the user's input into SubKEY through scanf and stored in SDKEY
 * Return Value: This function returns no data type and so is void. The function alters the string message within the function
 * What it does: The function 'SubEncrypt', decrypts the users message using the rotational decryption method
 * Limitations: limited to a message of length 1024 characaters
 */

void SubDecrypt(char* message, char* SDKEY){
    
    int n;// initialises the variable 'n'
    int index = 0;// initialises the variable index and sets it to 0
    
        for(index = 0; message[index] != 0; index++){// FOR loop which cycles through the string 'message'
        
            n = message[index];// sets n to be equal tothe value of 'message' at the current index
        
            switch(n){// switch case statement 
            
                case 65 : //switch case, when the n is equal to 65 (ASCII value for 'A'), the code beneath will execute
                        message[index] = SDKEY[0];//sets 'message' at the current index to be equal to 'SDKEY' at index equals 0
                        break;
                case 66 :
                        message[index] = SDKEY[1];
                        break;
                case 67 : 
                        message[index] = SDKEY[2];
                        break;
                case 68 : 
                        message[index] = SDKEY[3];
                        break;
                case 69 : 
                        message[index] = SDKEY[4];
                        break;
                case 70 : 
                        message[index] = SDKEY[5];
                        break;
                case 71 : 
                        message[index] = SDKEY[6];
                        break;
                case 72 : 
                        message[index] = SDKEY[7];
                        break;
                case 73 : 
                        message[index] = SDKEY[8];
                        break;
                case 74 : 
                        message[index] = SDKEY[9];
                        break;
                case 75 : 
                        message[index] = SDKEY[10];
                        break;
                case 76 : 
                        message[index] = SDKEY[11];
                        break;
                case 77 : 
                        message[index] = SDKEY[12];
                        break;
                case 78 : 
                        message[index] = SDKEY[13];
                        break;
                case 79 : 
                        message[index] = SDKEY[14];
                        break;
                case 80 : 
                        message[index] = SDKEY[15];
                        break;
                case 81 : 
                        message[index] = SDKEY[16];
                        break;
                case 82 : 
                        message[index] = SDKEY[17];
                        break;
                case 83 : 
                        message[index] = SDKEY[18];
                        break;
                case 84 : 
                        message[index] = SDKEY[19];
                        break;
                case 85 : 
                        message[index] = SDKEY[20];
                        break;
                case 86 : 
                        message[index] = SDKEY[21];
                        break;
                case 87 : 
                        message[index] = SDKEY[22];
                        break;
                case 88 : 
                        message[index] = SDKEY[23];
                        break;
                case 89 : 
                        message[index] = SDKEY[24];
                        break;
                case 90 : 
                        message[index] = SDKEY[25];
                        break;     
                default : // if any ASCII value doesn't fall into the above cases (i.e. special characters, numbers, etc.) they will be ignored
                        break;
            }  
       }
}

#endif