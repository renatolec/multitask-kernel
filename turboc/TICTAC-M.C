#include <stdio.h>
#include <system.h>

PTR_DESC dtic, dtac, dmain;
int contador = 0;


void far tic(){
     while(contador < 100){
              printf("tic-");
              transfer(dtic, dtac);
     }
     transfer(dtic, dmain);
}

void far tac(){
     while(1){
              printf("tac ");
              contador++;
              transfer(dtac, dtic);
     }
}

void main(){
     dtic = cria_desc();
     dtac = cria_desc();
     dmain = cria_desc();

     newprocess(tic, dtic);
     newprocess(tac, dtac);

     transfer(dmain, dtic);
}