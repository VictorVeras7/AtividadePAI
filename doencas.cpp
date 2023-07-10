#include"doencas.h"

using namespace std;

    
   diagnostico::diagnostico ()
      {
       // cout << "Informe sim ou não";
        int resposta = -1;
        //if(resposta == 1) {
          //  return true;
       // } else {
         //   return false;
        //}
        
      }

   diagnostico::diagnostico (int resp)
      {
        Resposta = resp;
      }

   int diagnostico::obterResposta()
   {
    return Resposta;
   }
