#include <iostream>
#include <cmath>

using namespace std;

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