#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
  if(argc != 2){
    printf(2, "tiempo de sueño\n");
    exit();
  }
  int tiempo= atoi(argv[1]);
  printf(2, "segundos durmiendo\n", tiempo);
  sleep(tiempo*200);
  exit();
}