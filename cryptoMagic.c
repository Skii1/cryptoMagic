#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int encryptChar(char inChar, char* output);
void encrypt(char* sourceFileName);

char decryptChar(char** input);
void decrypt(char* sourceFileName);

char* changeExtension(char* fileName, bool isDecrypting);
//implement character indexing as a raw counter per line upto 255 (125 char) ? or, use a pointer to get the address of specific character and process by adress.
int lineIndex;

int main(int argc, char *argv[]) {

    switch(argc){
        case 2: 
            encrypt(argv[1]); 
            break;
        case 3:
            if(strcmp(argv[1], "-D") == 0){
                decrypt(argv[2]);
            }    

            else if(strcmp(argv[1], "-E") == 0){
                encrypt(argv[2]);
            }
            break;
        default: 
            printf("Invalid arguments.");
    }
    
}

char* changeExtension(char* fileName, bool isDecrypting){
    int length = strlen(fileName);
    int lastDot = length; //lastDot is the index of the last dot in the file name, or, the null terminator if no dot is present.

    for(int i = 0; i < length; i++){
        if(fileName[i] == '.'){
            lastDot = i; 
        }
    }

    char* newFileName = malloc(lastDot + 5);

    for(int i = 0; i < lastDot; i++){
        newFileName[i] = fileName[i];
    }
    if(isDecrypting){
        sprintf(newFileName + lastDot, ".txt");
    }

    else{
        sprintf(newFileName + lastDot, ".crp");
    }

    return newFileName;
}

void encrypt(char* sourceFileName){
    FILE* fileSrc= fopen(sourceFileName, "r");

    if (fileSrc == NULL) {
        printf("Error opening file.");
    }

    char plainText[121] = "";
    char cipherText[255] = "";
    int plainTextIndex = 0;
    int cipherTextIndex = 0;
    bool stillReading = true;
    while(stillReading){

        for(plainTextIndex = 0; plainTextIndex < 120; plainTextIndex++){

            cipherText[cipherTextIndex] = 0;
            int ch = getc(fileSrc);

            if(ch == EOF){
                stillReading = false;
                break;
            }

            if(ch == '\n'){
                int bytesWritten = sprintf(&(cipherText[cipherTextIndex]), "\n");
                cipherTextIndex += bytesWritten;
                break;
            }

            int encrypted = ch - 16;

            if(encrypted < 32){
                encrypted = (encrypted - 32) + 144;
            }

            int bytesWritten = sprintf(&(cipherText[cipherTextIndex]), "%02X", encrypted);
            cipherTextIndex += bytesWritten;
            
        }

        printf("%s", cipherText);
    }

    fclose(fileSrc);
}

void decrypt(char* sourceFileName){
    FILE* fileSrc = fopen(sourceFileName, "r");

    if (fileSrc == NULL) {
        printf("Error opening file.");
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fileSrc)) != -1) {
        //printf("Retrieved line of length %zu :\n", read);
        //printf("%s", line);
        char* output = malloc(strlen(line));
        char* ptr = line;
        char* outputPtr = output;
        while(*ptr != 0){
            char decrypted = decryptChar(&ptr);
            if(decrypted != 0){
                *outputPtr = decrypted;
                *outputPtr += 1;

            }
        }

        printf("%s", output);
        free(output);
    }

    free(line);

    fclose(fileSrc);
}

int encryptChar(char inChar, char* output){

    if(inChar == '\t'){
        return sprintf(output, "TT");
    }

    else if(inChar == '\n'){
        return sprintf(output, "\n");
    }

    else if(inChar == '\r'){
        return sprintf(output, "");
    }

    else{
        int encrypted = inChar - 16;

        if(encrypted < 32){
            encrypted = (encrypted - 32) + 144;
        }

        return sprintf(output, "%02X", encrypted);
    }
}

char decryptChar(char** input){
    if((*input)[0] == '\n'){ 
        *input += 1;
        return '\n';
    }

    else if((*input)[0] == '\r'){
        return 0;
    }

    else{
        char hex[3]; 
        hex[0] = (*input)[0];
        hex[1] = (*input)[1];
        hex[2] = 0;
        *input += 2;

        int decrypted = strtol(hex, NULL, 16);

        decrypted = decrypted + 16;

        if(decrypted > 127){
                decrypted = (decrypted - 144) + 32;
        }
        return decrypted;

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
    