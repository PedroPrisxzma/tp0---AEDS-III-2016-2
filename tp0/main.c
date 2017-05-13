#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"
#include "leitura.h"

int main(){
  char **dic;
  char *txt;
  txt = malloc(sizeof(char)*16);

  int i, n, m, t;/*n -> num de palavras do dicionário
                  m -> num de palavras do texto
                  t -> tamanho de uma string */

  no *trie;  //Criação da raíz
  trie = iniciaTrie();

//Início da execução principal
  scanf("%d", &n);
  alocaDic(&dic, n);
  for(i = 0;i < n;i++){  //O txt é usado aqui, pois ao inserir uma palavra na
    scanf("%s", txt); //Trie, ela é apagada, logo não queremos
    t = (strlen(txt)+1);//perder o dicionário inserindo com ele.
    alocaDicWord(&dic, t, i);//Aq alocamos o espaço de cada palavra uma a uma no dicionário após lê-las
    strcpy(dic[i], txt);
    InsereTrie(trie, txt);
  }

  scanf("%d", &m);
  for(i = 0;i < m;i++){ //Pesquisa de ocorrências no texto
    scanf("%s", txt);
    PesquisaTrie(trie, txt);
  }

  for(i = 0;i < n;i++){ //Execução da saída
    if(i == (n-1)){
      PesquisaOcor(trie, dic[i], 1);
    }
    else{
      PesquisaOcor(trie, dic[i], 0);
    }
  }
  printf("\n");
//Término da execução principal, a seguir, toda a liberação do espaço usado
  ApagaTrie(trie);
  desalocDic(dic, n);
  desalocTxt(txt);
  return 0;
}
