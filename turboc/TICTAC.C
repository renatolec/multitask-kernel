#include <stdio.h>
#include <system.h>

PTR_DESC dtic, dtac, dmain;

void far tic(){
     while(1){
              printf("tic-");
              transfer(dtic, dtac);
     }
}

void far tac(){
     while(1){
              printf("tac ");
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
}
