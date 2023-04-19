#include <stdio.h>

int fatorial(int n);

int main(){
  int numero = 5;
    
  int f;
  
  f = fatorial(numero);
  
  printf("Fatorial de %d = %d", numero, f);
  
  return 0;
}


int fatorial(int n){
  int vfat;
  
  if ( n <= 1 )
    return (1);
  else{
    vfat = n * fatorial(n - 1);
    return (vfat);
  }
}