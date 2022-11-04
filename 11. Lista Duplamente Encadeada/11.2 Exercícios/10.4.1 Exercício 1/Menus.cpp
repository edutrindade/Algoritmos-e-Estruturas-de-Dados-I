#include <iostream>

using namespace std;

void Menu();
void MenuRemocao();
void MenuPesquisa();
void CabecalhoCadastro();
void CabecalhoRemocaoPorCodigo();
void CabecalhoPesquisaPorCodigo();
void CabecalhoPesquisaPorTitulo();
void CabecalhoListagemCompleta(); 

void Menu() {    
     cout<<"  \n        ����������������������������������������������������������������";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        �                     TRABALHOS ACADÊMICOS                     �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        ����������������������������������������������������������������";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 1 - INCLUIR NOVO TRABALHO                                    �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 2 - REMOVER UM TRABALHO                                      �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 3 - NAVEGAR PELOS TRABALHOS                                  �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 4 - PESQUISAR UM TRABALHO                                    �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 5 - LISTAR TODOS OS TRABALHOS                                �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 6 - SAIR                                                     �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        ����������������������������������������������������������������\n\n";
}

void MenuRemocao() {    
     cout<<"  \n        ����������������������������������������������������������������";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        �                       EXCLUIR TRABALHO                       �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        ����������������������������������������������������������������";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 1 - PRIMEIRO DA LISTA                                        �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 2 - ÚLTIMO DA LISTA                                          �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 3 - POR CÓDIGO                                               �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 4 - VOLTAR                                                   �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        ����������������������������������������������������������������\n\n";
}

void MenuPesquisa() {    
     cout<<"  \n        ����������������������������������������������������������������";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        �                      PESQUISAR TRABALHO                      �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        ����������������������������������������������������������������";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 1 - POR CÓDIGO                                               �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 2 - POR TÍTULO                                               �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 3 - VOLTAR                                                   �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        ����������������������������������������������������������������\n\n";
}

void CabecalhoCadastro() {    
     cout<<"  \n        ����������������������������������������������������������������";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        �                     CADASTRO DE TRABALHO                     �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        ����������������������������������������������������������������";
}

void CabecalhoListagemCompleta() {
     cout<<"  \n        ����������������������������������������������������������������";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        �                    TRABALHOS CADASTRADOS                     �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        ����������������������������������������������������������������\n\n";
}

void CabecalhoRemocaoPorCodigo() {
     cout<<"  \n        ����������������������������������������������������������������";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        �                    EXCLUSÃO DE TRABALHO                      �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        ����������������������������������������������������������������\n";
}

void CabecalhoPesquisaPorCodigo() {
     cout<<"  \n        ����������������������������������������������������������������";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        �                    PESQUISA POR CÓDIGO                       �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        ����������������������������������������������������������������";
}

void CabecalhoPesquisaPorTitulo() {
     cout<<"  \n        ����������������������������������������������������������������";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        �                    PESQUISA POR TÍTULO                       �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        ����������������������������������������������������������������";
}