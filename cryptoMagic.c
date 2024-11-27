#include <stdlib.h>
#include <stdio.h>
#include <string.h>

outChar();
inChar();
fileIO();
encrypt();
decrypt();

//implement character indexing as a raw counter per line upto 255 (125 char) ? or, use a pointer to get the address of specific character and process by adress.
int lineIndex;

int main(int argc, char *argv[]) {

    //hexadecimal adressing? you are just setting the old array pointer to a new location? redundant or clean?
    char[50] fileName = argv[0]; //arbitrary 49 character filename limit 
    char flag = argv[1];

    FILE* fileTarget; 

    fileTarget = fopen(argv[0], r);

    switch(flag){ //or switch argv[0]
        case 'D':
            decrypt(fileName, fileTarget);
            break;
        case 'E': //<-- fall down to default encrypt case // or set case '' as default encrypt, and all other cases are errors
        default: //<-- default case will always be encrypt
        encrypt(fileName, fileTarget); 
            break;
    }
}

int modiferFlag(char mod[]){ //is this function needed? just implement as if branch since newlines are ignored and constant

    if(inChar == 9)
        mod[2] = 'TT';

    if(inChar)
}

////formatting(FILE* file){ 
/*
^^ THIS IS NOW getline()
output / input mechanism, call encrypt/decrypt line by line
use fputs("file", ptr (line pointer))
file input separation scheme
*/

fileIO(char[] filename, FILE* fileptr) { ////binary read or text read?
//TEXT READ

    ////FILE* fileptr; 
    //dont need ^^, already passed as param

    char line[120]; //replace 125 with max line size preset.

    ////fileptr = fopen("fileName", "mode"); //"r+" mode set pointer at [0] of file
    //redundant, already passed as pararm, instead, open new file as write

    FILE* fileout;

    fileout = fopen("fileName", w); 

    if(fileptr == NULL){
        printf("Error while opening file.");
    }

    if(fgets(str, 120, ptr) != NULL) {
        getline();
        ////puts(str);
    }

    fclose(fileptr);

    return 0?;
    //fgets code here if needed, otherwise call formatting in formating function
}

encrypt(char inChar){
    if(inChar == '\\'){
        modiferFlag(char);
    }

    switch(modFlag){
        case 0: 

        case 1:
            outChar[2] = 'TT';
            break;
        case 2:
            outChar[4] = "\r\n" || "\n" || "\r";
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
    //for(everyline, line <= newline count, line++){
        getLine(); 
        //
    }
    

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

    //PSUEDOCODE

    /*
    import string, stdlib, and stdio.

    main(argc, argv[]){
        FROM CL ARGUMENTS, FLAG AND FILENAME

        initiate file pointer 

        open and read at file pointer 
        
        
        //

        initiate outputfile as 

        fopen("filename.crp/txt") <-- do this in output fn

        or pass file pointer to each, would be easier to access. (add filename, and pointer?)

        if(flag is decrypt)
            decrypt(filename);

        else if(flag is encrypt)
            encrypt("filename");
    }

    decrypt(string filename. file){
        
        fopen(file.crp, read);

        if file NOT crp, return error msg

        fnew(file.txt, write)

        str search for ("\") modifier flag

        if("\t"), repeat do regular modification

        else if("\n, \r\n, \r"){
            KEEP data,
            exit line

            fappend(fileout.txt, append)
            goto next line and loop

        }

        when done,

        fclose(fileout.txt)

        message
    }

    encrypt(string filename, file){
        
        reverse of decrypt, same process.
        
        fileinputopen(file.any, read)
        fopen (new) (filename.crp, w+)

        file is written to with crp extension
    }

    getline(filename?, file pointer index at new line) { 
        new line string = fgets(from end of prev line, to new end line);

        return line string;
    }


    */
    