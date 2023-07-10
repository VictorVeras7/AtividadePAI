#include <iostream>
#include"doencas.h"

using namespace std;


   diagnostico::diagnostico ()
      {
       // cout << "Informe sim ou não";
        int resposta;
        //if(resposta == 1) {
          //  return true;
       // } else {
         //   return false;
        //}

      }

   diagnostico::diagnostico (int resposta)
      {
        Resposta = resposta;
      }

   int diagnostico::obterResposta()
   {
    return Resposta;
   }