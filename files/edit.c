#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int writeChanges(char *word, char *newWord, char *pattern, int fd, int wordSize){
    if(strcmp(word, pattern)){
        write(fd, word, wordSize);
        write(fd, " ", 1);
    }
    else{
        write(fd, newWord, strlen(newWord));
        write(fd, " ", 1);
    }
    return 0;
}

int main(int argc, char **argv){
    char *pattern = argv[1];
    char *newWord = argv[2];
    char *fileName = argv[3];

    char current;
    char word[100];
    int wordSize = 0;

    int fd = open(fileName, O_RDONLY);
    int fd2 = open("temp.txt", O_WRONLY|O_CREAT,0666);

    while(read(fd,&current,1)){
        if(current != ' ') {
            word[wordSize++] = current;
        } else {
            word[wordSize] = '\0';
            writeChanges(word, newWord, pattern, fd2, wordSize);
            wordSize = 0;
            
        }
    }
    close(fd);
    word[wordSize] = '\0';
    writeChanges(word, newWord, pattern, fd2, wordSize);

    close(fd);
    close(fd2);

    unlink(fileName);
    link("temp.txt", fileName);
    unlink("temp.txt");

    return 0;
}