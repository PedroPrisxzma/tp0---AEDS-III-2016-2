////////////////////////////////////////////////////////
//Nodulo
typedef struct no{
  char atual;
  struct no *filho;
  struct no *esq;
  int count_word;
  int is_word;
}no;

//Cria nos e inicializa árvore trie quando \0 for a entrada
no *CriaFilho(char caracter);

//Inicia a trie
no *iniciaTrie();

//Insere novo caracter na trie
void InsereTrie(no *trie, char *palavra);

//Checa se há repetição na inserção
int repeat(no *trie, char *palavra);

//Pesquisa uma palavra na trie
void PesquisaTrie(no *trie, char *palavra);

//Confere as ocorrências de cada palavra
void PesquisaOcor(no *trie, char *palavra, int indica);

//Apaga a árvore
void ApagaTrie(no *trie);
