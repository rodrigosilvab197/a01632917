#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char** argv){
    if(argc!=2)
        return -1;
    char *file = argv[1];
    char *pwd = getcwd(NULL, 0);
    char path1[strlen(file)+strlen(pwd)+2];
    sprintf(path1, "%s/%s", pwd, file);
    unlink(path1);
}