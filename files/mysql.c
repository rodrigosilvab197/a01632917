#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct s{
    char firstName[20];
    char lastName[20];
    int prisionerId;
    char semester;
} Student;

int writeStudent(int argc, char **argv){
    int i;
    char * fileName = argv[1];
    int fd = open(fileName, O_WRONLY|O_CREAT, 0666);
    for(i = 0; i < 5; i++){
        Student myStudent;
        sprintf(myStudent.firstName, "juanito_%d", i);
        sprintf(myStudent.lastName, "perez_%d", i);
        myStudent.prisionerId = i*11;
        myStudent.semester = i + 1;
        write(fd, &myStudent, sizeof(Student));
    }
    close(fd);
    return 0;
}

int readStudent(int argc, char **argv){
    char * fileName = argv[1];
    int fd = open(fileName, O_RDONLY);
    Student myStudent;
    int element = atoi(argv[2]);
    lseek(fd, element*sizeof(Student), SEEK_SET);
    read(fd, &myStudent, sizeof(Student));
    close(fd);
    printf("Name: %s %s\n", myStudent.firstName, myStudent.lastName);
    printf("Id: %d\n", myStudent.prisionerId);
    printf("Semester: %d\n", myStudent.semester);
    return 0;
}

int main(int argc, char **argv){
    int i;
    char * fileName = argv[1];
    char * searchLastName = argv[2];
    char * newLastName = argv[3];
    int fd = open(fileName, O_RDONLY);    
    int pos = -1;
    for(i = 0; i < 5; i++){
        Student myStudent;
        read(fd, &myStudent, sizeof(Student));
        if(!strcmp(myStudent.lastName, searchLastName)){
            pos = i;
            break;
        }
    }
    close(fd);

    if(pos==-1){
        printf("No encontrado");
        return 0;
    }
    Student trash;
    int maxSize = sizeof(trash.lastName);
    char trLName[maxSize];
    strncpy(trLName, newLastName, maxSize);
    fd = open(fileName, O_WRONLY);
    lseek(fd, pos * sizeof(Student) + sizeof(trash.firstName), SEEK_SET);
    write(fd, trLName, maxSize);
    close(fd);
    return 0;
}