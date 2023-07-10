#include<iostream>
#include<cstddef>
#include"arvore.h"

using namespace std;

  ArvoreDec::ArvoreDec() //construtor
{
raiz = NULL;
}

  ArvoreDec::~ArvoreDec() //destrutor
  {

  }

  void ArvoreDec::deletarA(No* Noatual)
  {}

  No* ArvoreDec::obterRaiz()
  {
    return raiz;
  }

  bool ArvoreDec::estavazio()
  {
    return (raiz == NULL);
  }

  bool ArvoreDec::estacheio()
  {
    try {
        No* temp = new No;
        delete temp;
        return false;
    }catch(bad_alloc exception) {
        return true;
    }
  }

  void ArvoreDec::inserir(diagnostico diagnostico)
  {
    if(estacheio()) {
      cout << "Nao ha espaço para novos sintomas\n";
      cout << "Não foi possivel inserir novo sintoma\n";

    } else {
      No*Novosintoma = new No;
      Novosintoma->diagnostico = diagnostico;
      Novosintoma->Sim =NULL;
      Novosintoma->Nao =NULL;
      if(raiz==NULL) {
        raiz = Novosintoma;
      } else{
        No* temp = raiz;
        while(temp != NULL) {
          if(diagnostico.obterResposta() < temp->diagnostico.obterResposta()) {
            if(temp->Nao ==NULL) {
              temp->Nao = Novosintoma;
              break;
          } else {
              temp = temp->Nao;
            }
          } else {
            if(temp->Sim == NULL){
              temp->Sim = Novosintoma;
              break;
           } else {
            temp = temp->Sim;
           } 
          }
        }
      }
    }
  }

  void ArvoreDec::remover(diagnostico diagnostico)
  {
    removerbusca(diagnostico, raiz);
  }

  void ArvoreDec::removerbusca(diagnostico diagnostico, No*& noatual) {
     if(diagnostico.obterResposta() <= noatual->diagnostico.obterResposta()) {
        removerbusca(diagnostico, noatual->Nao);
  } else if(diagnostico.obterResposta() > noatual->diagnostico.obterResposta()) {
         removerbusca(diagnostico, noatual->Sim);  
  } else {
         deletarNo(noatual);
     } }
  void ArvoreDec::deletarNo(No*& noatual)  {
    No* temp = noatual;
    if(noatual->Nao == NULL) {
     noatual = noatual->Sim; 
      delete temp;
    } else if(noatual->Sim ==NULL) {
      noatual = noatual->Nao;
      delete temp;
    } else {
        diagnostico outrosint;
        proxsint(outrosint, noatual);
        noatual->diagnostico = outrosint;
        removerbusca(outrosint, noatual->Sim);
    }
  } 
  void ArvoreDec::proxsint(diagnostico& outrosint, No* temp) {
    temp = temp->Sim;
    while(temp->Nao != NULL) {
      temp = temp->Nao;
    } outrosint = temp->diagnostico;
  }

  void ArvoreDec::buscar(diagnostico& diagnostico, bool busca)
  {
    busca = false;
    No* checar = raiz;
    while (checar != NULL) {
      if(diagnostico.obterResposta() <= checar->diagnostico.obterResposta()) {
         checar = checar->Nao;
      } else if(diagnostico.obterResposta() >= checar->diagnostico.obterResposta()) {
         checar = checar->Sim;  
      } else {
        busca = true;
        diagnostico = checar->diagnostico;
        break;
      }
    }
  }

  //pre ordem 
  void ArvoreDec::imprimirpreo(No* Noatual)
  {}

  //ordem
  void ArvoreDec::imprimiremo(No* Noatual)
  {}

  //pos ordem 
  void ArvoreDec::imprimirposo(No* Noatual)
  {}
