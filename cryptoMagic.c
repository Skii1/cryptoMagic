#include <stdlib.h>
#include <stdio.h>
#include <string.h>

outChar();
inChar();
fileIO();
encrypt();
decrypt();

//implement character indexing as a raw counter per line upto 255? or, use a pointer to get the address of specific character and process by adress.
int lineIndex;

int main(int argc, char *argv[]) {

    char* fileName = argv[0];
    char* flag = argv[1];

    FILE* fileTarget; 

    if(flag == 'E')
        file_point = fopen(filename, "w");
    else if(flag == 'D')
        file_point = fopen(filename, "r");

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

//get input with command switch : WIP, IMPLEMENTED
//call file IO funcition with switches and variables, WIP, IMPLEMENTED
//

}

int modiferFlag(char mod[]){

    if(inChar == 9)
        mod[2] = 'TT';

    if(inChar)
}

formatting(FILE* file){
//output / input mechanism, call encrypt/decrypt line by line
//use fputs("file", ptr (line pointer))

//file input separation scheme



}

fileIO(){ //binary read or text read?
    FILE* fileptr;
    char line[125]; //replace 125 with max line size preset.

    fileptr = fopen("fileName", "mode"); //"r+" mode set pointer at [0] of file

    if(fileptr == NULL){
        printf("Error while opening file.");
    }

    if(fgets(str, 125, ptr) != NULL) {

        puts(str);
    }

    fclose(fileptr);

    return 0?;
    //fgets code here if needed, otherwise call formatting in formating function
}

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

        //replace outChar with string defenition?
        //this will define the int value as 'T' * 2, cannot be concatenated into a string unless explicitly defined.
        //use buffer string, strcmp, others using string library.

        outChar == 'T' * 2;
    
    else if(CRFlag == true) //carriage return flag for inChar
        char newChar[4] = "<CR>"; //dont explictly use

    //general character encryption formula
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

        if(inChar == 'TT') //very large???
            str outStr = "<tab>";

            char rawVal;

            rawVal = (outChar[0] * 16) + (outChar[1] * 16);

            outChar += 16;

            if(outChar > 127)
                outChar = (outChar - 144) + 32;

                //<-- this is the decrypted char buffer, write to out file by line
        }
    }