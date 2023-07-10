#include <iostream>
using namespace std;

class diagnostico {
private: 
int Resposta;

//sim(1) nao(0)
public:
   diagnostico ();
   diagnostico (int Resposta); 
   int obterResposta();
};