////////////////////////////////////////////
/*
Funções para alocar o espaço para leitura
*/
//aloca dicionário
void alocaDic(char ***dic, int n); //Aloca espaço para todo o dicionário

//aloca palavra no dicionário
void alocaDicWord(char ***dic, int t, int i);

//Desaloca o dicionário
void desalocDic(char **dic, int n);

//Desaloca o espaço usado para palavra do texto
void desalocTxt(char *txt);
