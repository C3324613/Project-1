#ifndef VARIABLE
#define VARIABLE

void RotEncrypt(char* message, const int KEY){
    
    int index = 0;
    
    for(index = 0; message[index] != 0; index++) { // takes each char in the string 'message' and assigns it a new ASCII value
        
        if((message[index] > 64 && message[index] < 91 )){  //checks for ASCII values which are not letters. i.e punctuation characters, etc.   x x 
            
            message[index] = (((message[index] - 65) + KEY) % 26) + 65;  
            /* sets each letter in message to an ASCII value between 0-25 by minusing 65 as a = 65
               adds the cipher key value to assign it a new ASCII value
               takes the modulus of 26 to prevent characters being encrypted into characters which are not letters
               adds 65 back to value to re-assign it an ASCII value which is a character                 
            */
        }
      
    }
    
}

void RotDecrypt(char* message, const int KEY){
    
    int index = 0;
    
    for(index = 0; message[index] != 0; index++) { // cycles through each character in the string message
        
        if((message[index] > 64 && message[index] < 91)){  //checks for ASCII values which are not letters
            
            message[index] = (((message[index] - 65) - KEY + 26) % 26) + 65;  
            /*  modulus of negative values doesn't behave properly in che
                by adding 26 to the result the correct modulus can be calculated
                Otherwise operates the same an encryption formula except the KEY value is minused
            */
        } 
           
    }
    
}

char RotAttack(int index, char* message,char* freq, const int KEY){
    
    int count = 0;
    int letter = 0;
    int freqindex = 0;
    
    
    for(index = 0; message[index] != 0; index++){
        
        letter = message[index];
        
        for(index = 0; message[index] != 0; index++){
            
            if(message[index] == letter){
                
                count++;
            }
            
        
        
        }
        
        freq[freqindex] = count;
        freqindex++;
    
    }
    
    return freq[freqindex];
}

void SubEncrypt(char* message, char* SubKEY){
    
    int n;
    int index = 0;
    
        for(index = 0; message[index] != 0; index++){
        
            n = message[index];
        
            switch(n){
            
                case 65 : 
                        message[index] = SubKEY[0];
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
                default :
                        break;
            }  
       }  
}

void SubDecrypt(char* message, char* SDKEY){
    
    int n;
    int index = 0;
    
        for(index = 0; message[index] != 0; index++){
        
            n = message[index];
        
            switch(n){
            
                case 65 : 
                        message[index] = SDKEY[0];
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
                default :
                        break;
            }  
       }
}

#endif