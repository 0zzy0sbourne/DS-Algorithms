#include <stdio.h>
#include <stdlib.h> // atof -> converts string to double
#include <string.h> 
#define LINESIZE 256 
#define WORDSIZE 20 
char paragraph_delimeter = '\n';
char sentence_delimeter = '.';
char word_delimeter = ' '; 
struct word{
    char* data; 
}; 
struct sentence{
    struct word* data;   
    int word_count; 
}; 
struct paragraph{
    struct sentence* data; 
    int sentence_count; 
}; 
struct document{
    struct paragraph* data; 
    int paragraph_count; 
}; 
void open_file(FILE*, char*); 
int isOpened(FILE*); // print if it is opened and also get the mode
int insert_word_end(FILE*, char*);
void open_file_to_read(FILE*, char*);
void open_file_to_write(FILE*, char*);  
void notOpened();
void read_whole_text(FILE*, char*); 
void read_a_line(FILE*, int, char*);
void get_word(FILE*, char*, int, int); // fileptr and word number 
void get_sentence(FILE*, int, int); // opens file, iterates through (u can use FSEEK )
void get_paragraph(FILE*, int); 
int main(int argc, char* argv[]){
   char choice; 
   //  char* filename = "text.txt"; 
    char* filename = argv[1]; // pass the file name as argument to main()
    FILE* fileptr = NULL; 
    // open_file_to_write(fileptr, filename);
    printf("To read the file: (Press r) / To write to to the file: (Press w): / (o to exit) ");
    scanf("%c", &choice); getchar(); 
    switch(choice){
        case 'r':
            open_file_to_read(fileptr, filename); 
            break;
        case 'w': 
            open_file_to_write(fileptr, filename); 
            break; 
        case 'o':
            return 0; 
            break;
    }
     

}
void get_word(FILE* fileptr, char* filename, int line_num, int word_num){
    fileptr = fopen(filename, "r" ); 
    int word_counter=1, line_counter=1; 
    if(!fileptr) notOpened();  
    else{ // file is opened
        char word[WORDSIZE]; //  not declaring them as a malloc cuz we can not pass string literal to strtok() function   
        char line[LINESIZE];
    //     char* word = (char*)malloc(sizeof(char)*WORDSIZE); 
        char* wordptr = word; 
        while((fgets(line, LINESIZE, fileptr)) != NULL){
            if(line_counter == line_num){ 
                for (wordptr = strtok(line," "); wordptr != NULL; wordptr = strtok(NULL, " "))
                {
                    
                    if(word_counter == word_num){
                        strcpy(word, wordptr); 
                        puts(word); 
                    }
                    word_counter++; 
                }
            }
            line_counter++;
         
        }
    }
}
void get_sentence(FILE* fileptr, int para_num, int sentence_num){

}
void get_paragraph(FILE* fileptr, int para_num){

} 
void open_file_to_read(FILE* fileptr, char* name){
    char choice;
    int word_num; 
    int line_num; 

    // fileptr = fopen(name, "r");
    printf("Read whole text: (Press t) / Read a line: (Press l): / Read a word from a line(press w): "); 
    scanf("%c", &choice);     
    // choice = getchar(); // i can add this getchar to grab the ENTER after previous scanf 
    switch(choice){
        case 't': 
            read_whole_text(fileptr, name);
            break; 
        case 'l': // get a line number for this 
            printf("Enter the line number you wanna read: "); 
            scanf("%d", &line_num ); 
            read_a_line(fileptr, line_num,  name );  
            break;
        case 'w': 
            printf("enter the line number and word number respectively: "); 
            scanf("%d %d", &line_num,  &word_num); 
            get_word(fileptr, name, line_num, word_num);  
            break;  
    }
     
}
void read_whole_text(FILE* fileptr, char* filename ){
    // file is opened already, just read
    fileptr = fopen(filename, "r");
     
    char* line = (char*)malloc(sizeof(char)*LINESIZE);
    while(fgets(line, LINESIZE, fileptr )){
        printf("%s", line);
    }
    
    fclose(fileptr); 
    return; 
}
void read_a_line(FILE* fileptr, int line_num, char* filename){
    // open the file inside this and close in this
    char* line = (char*)malloc(LINESIZE*sizeof(char)); 
    fileptr = fopen(filename, "r"); 
    int linecounter = 0 ;
    int found = 0;  
    while(fgets(line, LINESIZE, fileptr)){
        if(linecounter+1 == line_num){
            printf("%s\n", line);
            found = 1; 
        }
        linecounter++; 
    }
    if(!found) printf("There are not that much lines\n"); 
    fclose(fileptr); 
    return;
} 
void open_file_to_write(FILE* fileptr, char* filename){
    char* str = (char*)malloc(100 * (sizeof(char)));
     
    fileptr = fopen(filename, "a");
    // check if the file is opened successfully 

    if(fileptr){
        char choice=' '; 
        printf("do you want to create a new paragraph for this?: (y/n"); 
        scanf("%c", &choice);
        if(choice == 'y'){ 
            fputs("\n", fileptr); 
        }
        printf("enter the string you wanna append to file: "); 
        scanf("%s", str); 
        fputs(str, fileptr);
        printf("Written to the file successfully! \n");  
       free(str);
       str = NULL;
       fclose(fileptr);   
        return; 
    
    if(isOpened(fileptr)) return ; 
    else{notOpened(); return;}

}
}

int isOpened(FILE* fileptr){
    if(fileptr){ // file is opened 
        return 1;
    }
    else {
        return 0; 
    }
}
int insert_word_end(FILE* fileptr, char* word){
    
    return 0; 
}
void notOpened(){
    puts("File could not be opened! \n"); 
}
