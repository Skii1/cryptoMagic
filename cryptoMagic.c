#include <stdlib.h>
#include <file.h>
#include <stdio.h>

//STRING

#include <string.h>

outChar();
inChar();
fileIO();
encrypt();
decrypt();

//implement character indexing as a raw counter per line upto 255? or, use a pointer to get the address of specific character and process by adress.
int lineIndex;

int main(char[] filename, str? filename, char flag) {

    fopen(filename);


    switch(flag){
        case 'D':
            decrypt();
            break;
        case 'E':
            encrypt();
            break;
        default:
            encrypt();
            break;
    }

//get input with command switch 
//call file IO funcition with switches and variables
//
}

int modiferFlag(char char?){

    if(inChar == 9)
        outChar[2] = 'TT';

    if(inChar)
}

formattting(){

//file input separation scheme

}

fileIO(){}

encrypt(char inChar){
    if(inChar == '<'){
        modiferFlag(char);
    }

    switch(modFlag){
        case 0: 

        case 1:
            outChar[2] = 'TT';
            break;
        case 2:
            outChar[4] = '<CR>';
            break;
        default:
            printf("..");

    }
    //do these steps based on a special character flag instead?
    if(inChar == 9)
        outChar == 'T' * 2;
    
    else if(CRFlag == true) //carriage return flag for inChar
        char newChar[4] = "<CR>";

    else{
        char outChar[4] = inChar - 16;

        if(outChar < 32)
            outChar = (outChar - 32) + 144;

        char writeBuf = outChar;

        writeBuf *= 2;

        //to hex?

    }
}

decrypt(){
    //per line 
    for(int i == 0, i < 256, i++){
        //get char = char 2hexChar

        if(inChar == 'TT')
            outStr = "<tab>";

            char rawVal;

            rawVal = (outChar[0] * 16) + (outChar[1] * 16);

            outChar += 16;

            if(outChar > 127)
                outChar = (outChar - 144) + 32;

                //<-- this is the decrypted char buffer, write to out file by line
        }
    }