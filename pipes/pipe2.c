#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int num = 0;
  int p= 0;
  scanf("%d\n",&p);
  fprintf(stderr, "%d\n",p);

  while(1){
    scanf("%d\n",&num);//noten que leo de stdout
    if(num == -1){
      break;
    }
    if(num % p != 0){
    printf("%d\n",num);
	
    }
  }
  fprintf(stderr, "completado\n");
}