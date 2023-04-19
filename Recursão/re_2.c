#include <stdio.h>

int soma(int i){
  if (i<10)
    return i+soma(i+1);
  else
    return 0;
}

int main(){
  printf("A soma foi %d\n", soma(1));
  return 0;
}