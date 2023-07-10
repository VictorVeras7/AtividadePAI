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