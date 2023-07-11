#ifndef ARVORE_H
#define ARVORE_H

#include"doencas.h"

struct No {
    diagnostico diagnostico;
    No* Sim;
    No* Nao;

};

class ArvoreDec{
  private:
  No* raiz;

  public:
  ArvoreDec();
  ~ArvoreDec();
  void lerSintomasArq(std::string file)
  void deletarA(No* Noatual);
  No* obterRaiz();
  bool estavazio();
  bool estacheio();
  void inserir(diagnostico diagnostico);
  void remover(diagnostico diagnostico);
  void removerbusca(diagnostico diagnostico, No*& noatual);
  void deletarNo(No*& noatual);
  void proxsint(diagnostico& outrosint, No* temp);
  void buscar(diagnostico& diagnostico, bool busca);
  //pre ordem 
  void imprimirpreo(No* Noatual);
  //ordem
  void imprimiremo(No* Noatual);
  //pos ordem 
  void imprimirposo(No* Noatual);
};

#endif
