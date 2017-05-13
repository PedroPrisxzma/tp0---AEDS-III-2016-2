#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leitura.h"

/////////////////////////////////////////////////////////////
/* Protótipo:void alocaDic(char ***dic, int n)             //
// Função: Tem como função alocar o dicionário a ser usado //
// Entrada: Um ponteiro para "matriz" de strings/char e um //
//          inteiro, indicando o número de linhas/palavras //
//          diferentes que estarão na "matriz"             //
// Saída: Não há, função do tipo void                      */
/////////////////////////////////////////////////////////////

void alocaDic(char ***dic, int n){
  *dic = (char**) malloc(sizeof(char*)*n);
}

/////////////////////////////////////////////////////////////
/* Protótipo:void alocaDicWord(char ***dic, int t, int i)  //
// Função: Tem como função alocar cada palavra do          //
//         dicionário a ser usado                          //
// Entrada: Um ponteiro para "matriz" de strings/char e    //
//         dois inteiros, um contendo o tamanho a ser      //
//         alocado para palavra e outro a posição da       //
//         palavra no dicionário                           //
// Saída: Não há, função do tipo void                      */
/////////////////////////////////////////////////////////////

void alocaDicWord(char ***dic, int t, int i){
  (*dic)[i] = (char*) malloc(sizeof(char)*t);
}

/////////////////////////////////////////////////////////////
/* Protótipo:void desalocDic(char ***dic, int n)           //
// Função: Tem como função desalocar o dicionário a ser    //
//         usado                                           //
// Entrada: Uma "matriz" de strings/char e um inteiro,     //
//          indicando o número de linhas/palavras          //
//          diferentes que estão na "matriz"               //
// Saída: Não há, função do tipo void                      */
/////////////////////////////////////////////////////////////

void desalocDic(char **dic, int n){
  int i;
  for(i = 0;i < n;i++){
    free(dic[i]);
  }
  free(dic);
}

/////////////////////////////////////////////////////////////
/* Protótipo:void desalocTxt(char *txt)                   //
// Função: Tem como função desalocar um string usado      //
// Entrada: Um string                                     //
// Saída: Não há, função do tipo void                     */
/////////////////////////////////////////////////////////////

void desalocTxt(char *txt){
  free(txt);
}
