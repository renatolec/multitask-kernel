#include <stdio.h>
#include <system.h>

PTR_DESC da, db, descalador, dmain;

void far a(){
     while(1)
             printf("A");
}

void far b(){
     while(1)
             printf("B");
}

void far escalador(){
     p_est->p_origem = descalador;
     p_est->p_destino = da;
     p_est->num_vetor = 8;

     while(1){
              iotransfer();
              disable();
              if(p_est->p_destino == da)
                  p_est->p_destino = db;
              else
                  p_est->p_destino = da;
              enable();
     }
}

void main (){
     da = cria_desc();
     db = cria_desc();
     descalador = cria_desc();
     dmain = cria_desc();

     newprocess(a, da);
     newprocess(b, db);
     newprocess(escalador, descalador);

     transfer(dmain, descalador);
}