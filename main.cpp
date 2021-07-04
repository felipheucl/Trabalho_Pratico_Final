#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int matricula[51], investimentos[51], posts[51], matr, id, postsmatricula;
ifstream leitura;
ofstream gravar;
string nome, sobrenome, TotalPosts;

int Arquivando(){
    gravar.open("banco_de_dados.txt",ios::app);
    gravar<<postsmatricula<<"\n";
    gravar<<TotalPosts<<"\n";
    gravar<<nome<<" "<<sobrenome<<"\n";
    gravar<<id;
    gravar.close();
    return 0;
}

int ArqVet() {
    leitura.open("banco_de_dados.txt", ios::app);
    leitura>>matricula[0];
    matr=matricula[0];
    for (int i=1; i<51; i++) {
        leitura>>matricula[i];
        leitura>>investimentos[i];
        leitura>>posts[i];
    }
    leitura.close();
    return 0;
}

struct tTriangulos
{
        tTriangulos (float l1, float l2, float l3): lado1(l1), lado2(l2), lado3(l3)
        {
        }

        public:
        float lado1, lado2, lado3;
  
        friend ostream& operator<<(ostream& os, const tTriangulos& tT)
        {
        os << "Medidas dos lados: " << tT.lado1 << ", " << tT.lado2 << ", " << tT.lado3 << endl;
        return os;
        }
};

float Hipotenusa(float num1, float num2)
{
       float r;
       r=sqrt(num1*num1 + num2*num2);
       return r;

}

// ************************
class No
{
  public:
  float valor;
  No* proximo;

  No(int elemento)
  {
    this->valor=elemento;
    this->proximo=NULL;
  }

  void definirProximo(No* end)
  {
    proximo=end;
  }

  int obterValor()
  {
    return valor;
  }

  No* obterProximo()
  {
    return proximo;
  }
};

class Lista
{
  public:
  No* inicio;
  No* fim;

  Lista()
  {
    inicio = NULL;
    fim=NULL;
  }

  Lista(int num)
  {
    inicio = new No(num);
    fim = inicio;
  }

  virtual ~Lista()
  {
    delete inicio;
  }

  bool seVazia()
  {
    return (inicio == NULL);
  }

  void imprimirElementos()
  {
    cout<<"ELEMENTOS DA LISTA"<<endl;
    No* i=inicio;
    if(seVazia())
    {
      cout<<"Lista sem elementos!"<<endl;
    }
    else
    {
      while(i)
      {
        cout<< i->obterValor()<<endl;
        i = i->obterProximo();
      }
      cout<<endl;
    }
  }

  void insereNoInicio(int valor)
  {
    No* novo = new No(valor);

    if(seVazia())
    {
      inicio= novo;
      fim=novo;
    }
    else
    {
      novo -> definirProximo(inicio);
      inicio = novo;
    }
  }

  void insereNoFim(int valor)
  {
    No* novo = new No(valor);

    if(seVazia())
    {
      inicio = novo;
      fim = novo;
    }
    else
    {
      fim -> definirProximo(novo);
      fim = novo;
    }
  }

  int tamanhoLista()
  { 
    if(seVazia())
    {
      return 0;
    }
    No* i = inicio;
    int tamanho = 0;

    do
    {
      i = i->obterProximo();
      tamanho++;
    }while(i);

    return tamanho;
  }

  bool existeElemento(int valor)
  {
    No* i = inicio;
    while(i)
    {
      if(i->obterValor()==valor)
      {
        return true;
      }else
      {
        i = i->obterProximo();
      }
    }
    return false;
  }

  void removerDaLista()
  {
    if(!seVazia())
    {
      if(inicio->obterProximo() == NULL)
      {
        inicio = NULL;
      }else if(inicio->obterProximo()->obterProximo()==NULL)
      {
        inicio->definirProximo(NULL);
      }else
      {
        No* anteriorDoAnterior = inicio;
        No* anterior = inicio->obterProximo();
        No* elo = inicio->obterProximo()->obterProximo();

        while(elo)
        {
          No* auxiliar = anterior;
          anterior = elo;
          anteriorDoAnterior = auxiliar;
          elo= elo->obterProximo();
        }

        delete anteriorDoAnterior->obterProximo();
        anteriorDoAnterior->definirProximo(NULL);
        fim=anteriorDoAnterior;
      }
    }
  }

};

// ************************

int main() {

float cateto1, cateto2;

cout<<endl<<endl<<"TRABALHO PRÁTICO - Utilização de lista e arquivos"<<endl<<endl;

cout<<"Digite o valor do 1º cateto:"<<endl;
cin>>cateto1;
cout<<"Digite o valor do 2º cateto:"<<endl;
cin>>cateto2;    

tTriangulos Triangulo=tTriangulos(cateto1,cateto2,Hipotenusa(cateto1,cateto2));
cout<<endl<<Triangulo<<endl;    
    


}    
/*
cout<<"      CALCULADORA MALUCA"<<endl<<endl;
cout<<"adicao        - aperte 'a'"<<endl;
cout<<"subtracao     - aperte 's'"<<endl;
cout<<"multiplicacao - aperte 'm'"<<endl;
cout<<"divisao       - aperte 'd'"<<endl<<endl;
cin>>escolha;
cout<<"Insira o Primeiro numero"<<endl;
cin>>num1;
cout<<"Insira o Segundo numero"<<endl;
cin>>num2;

switch (escolha)
    {
        case 'a':
        {
            resposta=(num1+num2);
            break;
        }
        case 's':
        {
            resposta=(num1-num2);
            break;
        }
        case 'm':
        {
            resposta=(num1*num2);
            break;
        }
        case 'd':
        {
            resposta=(num1/num2);
            break;
        }
        default:
        {cout<<"opcao invalida";
        }
    }

    cout<<"O resultado da operacao e "<<resposta;
}
*/