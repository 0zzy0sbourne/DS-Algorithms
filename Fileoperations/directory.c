#include <stdio.h>
#include <dirent.h> 
#include <string.h> 
void list_files_recursively(const char* basepath); 
void list_files(const char *path); 
int main(){
    char path[100];
    printf("enter the path: "); 
    scanf("%s", path); 

   //  list_files(path);  
    list_files_recursively(path); 
    return 0; 
} 
void list_files_recursively(const char* basepath){
    struct dirent *dp; 
    DIR* dir = opendir(basepath); 
    char path[1000]; 
    if(!dir) {
        // printf("directory could not opened"); 
        return ; 
    }
    while((dp = readdir(dir)) != NULL){
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            printf("%s\n", dp->d_name);

            // Construct new path from our base path
            strcpy(path, basepath);
            strcat(path, "/");
            strcat(path, dp->d_name);

            list_files_recursively(path);
        }
    }
    closedir(dir); 
}  
void list_files(const char *path){
    struct dirent *dp; 
    DIR* dir = opendir(path); 
    if(!dir){
        printf("could not open dir."); 
        return ; 
    }  
    while((dp = readdir(dir)) != NULL){
        printf("%s\n", dp->d_name); 
    } 
    closedir(dir); 
}