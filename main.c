#include<stdio.h>
#include<math.h>

typedef struct ponto
{
  float coordX, coordY; 

}Ponto;

void registraPonto(Ponto *p);
int verificaTipoTriangulo(Ponto *p);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int main(){

    int resultado;
    Ponto v[3];

    registraPonto(&v[0]);
    registraPonto(&v[1]);
    registraPonto(&v[2]);

    resultado = verificaTipoTriangulo(v);

    if (resultado == 1)
        printf("Triangulo Isoceles");
    
    if (resultado == 2)
        printf("Triangulo Equilatero");
    
    if (resultado == 3)
        printf("Triangulo Escaleno");


}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void registraPonto(Ponto *p){
    printf("\nDigite o ponto X:  ");
    scanf("%f", &p->coordX);

    printf("Digite o ponto Y:  ");
    scanf("%f", &p->coordY);
}

int verificaTipoTriangulo(Ponto *p){
   int d01, d02, d12;

   d01 = sqrt((pow((p[0].coordX - p[1].coordX), 2)) + pow((p[0].coordY - p[1].coordY), 2));
   d02 = sqrt((pow((p[0].coordX - p[2].coordX), 2)) + pow((p[0].coordY - p[2].coordY), 2));
   d12 = sqrt((pow((p[1].coordX - p[2].coordX), 2)) + pow((p[1].coordY - p[2].coordY), 2));

   /*ISOCELES*/
   if (d01 == d02 || d01 == d12 || d02 == d12)
        return 1;
   
   /*EQUILATERO*/
   if (d01 == d02 && d01 == d12)
        return 2;

   /*ESCALENO*/
   if(d01 != d02 && d01 != d12 && d02 != d12)
        return 3;
}