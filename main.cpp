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
  float b,c,a;
  No* proximo;

  No(float elemento1, float elemento2, float elemento3)
  {
  this->b=elemento1;
  this->c=elemento2;
  this->a=elemento3;
  this->proximo=NULL;
  }
  
  
  float obterValor() //impressao da lista
  {
  cout<<b<<" - "<<c<<" - "<<a<<endl;
  return b;
  }
  

  void definirProximo(No* end)
  {
    proximo=end;
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

  Lista(float num1, float num2, float num3)
  {
    inicio = new No(num1,num2,num3);
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
    cout<<"ELEMENTOS DA LISTA: "<<endl;
    No* i=inicio;
    if(seVazia())
    {
      cout<<"Lista sem elementos!"<<endl;
    }
    else
    {
      while(i)
      {
        i->obterValor();
        i = i->obterProximo();
      }
      cout<<endl;
    }
  }

 void insereNoFim(float v1, float v2, float v3)
  {
    No* novo = new No(v1,v2,v3);

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
/*
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
 */
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

Lista tT;
tT.insereNoFim(cateto1,cateto2,Hipotenusa(cateto1,cateto2));    
tT.imprimirElementos();


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