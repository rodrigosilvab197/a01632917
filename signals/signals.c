#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int infinito = 1;
int flag2 = 1;

void signalHandler(int signalNumber){
    printf("signal received %d\n", signalNumber);
    infinito = 0;
}

int main(){
    int pid;
    signal(10, signalHandler);
    pid = fork();
    if(pid == 0){
        printf("hijo\n");
        while(infinito || flag2){if(!infinito){flag2=0;}}
        printf("Ya sali!\n");
    }
    else{
        printf("padre\n");
        sleep(1);
        kill(pid, 10);
        for(;;);
    }
}