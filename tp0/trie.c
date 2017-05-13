#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"


/////////////////////////////////////////////////////////////
/* Protótipo: no *CriaFilho(char *caracter)                //
// Função: Tem como função criar um no filhos              //
// Entrada: Um ponteiro para caracter                      //
// Saída: retorna um vetor para o novo no criado           */
/////////////////////////////////////////////////////////////

no *CriaFilho(char caracter){
  no *novo = malloc(sizeof(no));
  novo->atual = caracter;
  novo->filho = NULL;
  novo->esq = NULL;
  novo->count_word = 0;
  novo->is_word = 0;
  return novo;
}

/////////////////////////////////////////////////////////////
/* Protótipo: no *iniciaTrie()                              //
// Função: Tem como função iniciar a raiz da trie          //
// Entrada: Um ponteiro para caracter                      //
// Saída: retorna um vetor para a nova raiz/no criada      */
/////////////////////////////////////////////////////////////

no *iniciaTrie(){
  no *raiz = malloc(sizeof(no));
  raiz->atual = '\0';
  raiz->filho = NULL;
  raiz->esq = NULL;
  raiz->count_word = 0;
  raiz->is_word = 0;
  return raiz;
}

/////////////////////////////////////////////////////////////
/* Protótipo:void InsereTrie(no *trie, char *palavra)      //
// Função: Tem como função inserir uma nova palavra na trie//
// Entrada: Dois ponteiros, um para árvore trie e outro    //
//          para palavra que se deseja inserir             //
// Saída: Não há, função do tipo void                      */
/////////////////////////////////////////////////////////////

void InsereTrie(no *trie, char *palavra){
  if(trie->atual == palavra[0]){
    if(palavra[1] == '\0'){
      trie->is_word = 1;
    }
    else{
      if(trie->filho == NULL){
        trie->filho = CriaFilho(palavra[1]);
      }
      palavra++;
      InsereTrie(trie->filho, palavra);
    }
  }
  else{
    if(trie->esq == NULL){
      trie->esq = CriaFilho(palavra[0]);
    }
    InsereTrie(trie->esq, palavra);
  }
}

/////////////////////////////////////////////////////////////
/* Protótipo:void PesquisaTrie(no *trie, char *palavra)    //
// Função: Tem como função pesquisar uma palavra na trie   //
// Entrada: Dois ponteiros, um para árvore trie e outro    //
//          para palavra que se deseja inserir             //
// Saída: Não há, função do tipo void                      */
/////////////////////////////////////////////////////////////

void PesquisaTrie(no *trie, char *palavra){
  if(trie->atual == palavra[0]){
    if(palavra[1] == '\0'){
      if(trie->is_word == 1){
        trie->count_word++;
      }
    }
    else{
      if(trie->filho != NULL){
        palavra++;
        PesquisaTrie(trie->filho, palavra);
      }
    }
  }
  else{
    if(trie->esq != NULL){
      PesquisaTrie(trie->esq, palavra);
    }
  }
}
////////////////////////////////////////////////////////////////////
/* Protótipo:int PesquisaOcor(no *trie, char *palavra, int indica)//
// Função: Tem como função pesquisar quantas vezes uma            //
//         palavra na trie foi lida no texto                      //
// Entrada: Dois ponteiros, um para árvore trie e outro           //
//          para palavra que se deseja inserir e um inteiro,      //
//          indicando o tipo de impressão, diferenciado caso seja //
//          a última palavra                                      //
// Saída: Um inteiro, o número de ocorrência de uma palavra       //
//        do dicionário no texto                                  */
////////////////////////////////////////////////////////////////////


void PesquisaOcor(no *trie, char *palavra, int indica){
  if(trie->atual == palavra[0]){
    if(palavra[1] == '\0'){
      if(trie->is_word == 1){
        if(indica == 1){
          printf("%d", trie->count_word);
        }
        else{
          printf("%d ",trie->count_word);
        }
      }
    }
    else{
      if(trie->filho != NULL){
        palavra++;
        PesquisaOcor(trie->filho, palavra, indica);
      }
    }
  }
  else{
    if(trie->esq != NULL){
      PesquisaOcor(trie->esq, palavra, indica);
    }
  }
}

/////////////////////////////////////////////////////////////
/* Protótipo:void ApagaTrie(no *trie)                      //
// Função: Tem como função apagar a árvore criada          //
// Entrada: Um único ponteiro para raiz da árvore que se   //
//          deseja apagar                                  //
// Saída: Não há, função do tipo void                      */
/////////////////////////////////////////////////////////////

void ApagaTrie(no *trie){
  if(trie->filho != NULL){
    ApagaTrie(trie->filho);
  }
  if(trie->esq != NULL){
    ApagaTrie(trie->esq);
  }
  free(trie);
}
