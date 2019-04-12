#include<stdio.h>
#include"Head.h"



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
    char message[] = "SJSFMPCRM WG O USBWIG. PIH WT MCI XIRUS O TWGV PM WHG OPWZWHM HC QZWAP O HFSS, WH KWZZ ZWJS WHG KVCZS ZWTS PSZWSJWBU HVOH WH WG GHIDWR. - OZPSFH SWBGHSWB";
    const int KEY = 14;

    /*printf("Message to encrypt is : %s\n", message);
    
    encryption(message, index, KEY);*/
   
    printf("Message to decrypt is : %s\n", message);
    
    decryption(message, index, KEY);
    
    printf("Decrypted message is : %s\n", message);
     
    return 0;

}

