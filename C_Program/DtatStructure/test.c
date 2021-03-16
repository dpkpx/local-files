#include <stdio.h> 

void update(float *p, float value){
  *p = value;
}

int main(int argc, char *argv[]){  
  float p = 3.0;
  update(&p, 5.0);
  printf("%f\n", p);
}