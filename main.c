#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

void move_files(char* dst_path) {
    char* curr_path=getcwd(NULL, 0);
    DIR* dp=opendir(curr_path);
    struct dirent* directory;
    while((directory=readdir(dp))!=NULL) {
        if(strcmp(directory->d_name, ".")!=0 && strcmp(directory->d_name, "..")!=0 && strcmp(directory->d_name, ".DS_Store")!=0) {
            struct stat file;
            if(stat(directory->d_name, &file)!=0) {
                perror("stat");
                exit(EXIT_FAILURE);
            }
            if(S_ISDIR(file.st_mode)) {
                if(chdir(directory->d_name)!=0) {
                    fprintf(stderr, "Cannot enter %s. Skipping...\n", directory->d_name);
                }
                else {
                    char new_dirpath[sizeof(dst_path)+sizeof(directory->d_name)+1]="";
                    strcat(new_dirpath, dst_path);
                    strcat(new_dirpath, "/");
                    strcat(new_dirpath, directory->d_name);
                    mkdir(new_dirpath, file.st_mode & 0b0000111111111111);
                    move_files(new_dirpath);
                    chdir("..");
                    rmdir(directory->d_name);
                }
            }
            else {
                FILE* fdata=fopen(directory->d_name, "r");
                char new_filepath[sizeof(dst_path)+sizeof(directory->d_name)+1]="";
                strcat(new_filepath, dst_path);
                strcat(new_filepath, "/");
                strcat(new_filepath, directory->d_name);
                FILE* newfile=fopen(new_filepath, "w");
                int data;
                while((data=fgetc(fdata))!=EOF) {
                    fputc(data, newfile);
                }
                fclose(fdata);
                fclose(newfile);
                remove(directory->d_name);
            }
        }
    }
    free(curr_path);
    closedir(dp);
}

int main(int argc, char** argv) {
    chdir(argv[1]);
    move_files(argv[2]);
}
