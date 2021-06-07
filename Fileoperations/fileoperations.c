#include <stdio.h>
#include <stdlib.h> // atof -> converts string to double
#include <string.h> 
#define LINESIZE 256 
#define WORDSIZE 20 
#define SENTENCESIZE 100
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
void get_word(FILE*, char*, int, int, int); // fileptr and word number 
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
void get_word(FILE* fileptr, char* filename, int para_num, int sentence_num, int word_num){
    fileptr = fopen(filename, "r" ); 
    int word_counter = 1, sentence_counter=1, para_counter=1;  
    char get;
    if(!fileptr) notOpened();  
    else{ // file is opened
        char paragraph[LINESIZE]; //  not declaring them as a malloc cuz we can not pass string literal to strtok() function   
        char sentence[SENTENCESIZE];
    //     char* word = (char*)malloc(sizeof(char)*WORDSIZE); 
        while((get = fgetc(fileptr)) != EOF){
            if(get == word_delimeter) word_counter++; 
            if(get == sentence_delimeter) sentence_counter++;
            if(get ==  paragraph_delimeter) para_counter++;
            if(para_counter == para_num){ // get the line of that paragraph
                fscanf(fileptr, "%s", paragraph);
                char *ptr = paragraph; 
                char* tok;
                printf("sentence of this paragraph that we want: \n");  
                while((tok = strtok(ptr, &sentence_delimeter)) != NULL){
                    if(sentence_counter == sentence_num) { // get the sentence to our dynamic sentence array and break the while loop. 
                      sentence =  tok; 
                      printf("%s.\n", tok);
                      ptr = NULL;
                      break; 
                    }  
                    sentence_counter++; 
                    ptr = NULL ; 
                }
                ptr = sentence; 
                printf("word of this paragraph that we want: "); 
      
                
                
                
            }
        }
    }
}
void get_sentence(FILE* fileptr, int para_num, int sentence_num){

}
void get_paragraph(FILE* fileptr, int para_num){

} 
void open_file_to_read(FILE* fileptr, char* name){
    char choice;
    int para_num, word_num, sentence_num; 

    // fileptr = fopen(name, "r");
    printf("Read whole text: (Press t) / Read a line: (Press l): / Read a word (press w): "); 
    scanf("%c", &choice);     
    // choice = getchar(); // i can add this getchar to grab the ENTER after previous scanf 
    switch(choice){
        case 't': 
            read_whole_text(fileptr, name);
            break; 
        case 'l': // get a line number for this 
            printf("Enter the line number you wanna read: "); 
            scanf("%d", &sentence_num ); 
            read_a_line(fileptr, sentence_num, name );  
            break;
        case 'w': 
            printf("enter the paragraph number, sentence number and word number respectively: "); 
            scanf("%d %d %d", &para_num, &sentence_num, &word_num); 
            get_word(fileptr, name, para_num, sentence_num, word_num);  
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