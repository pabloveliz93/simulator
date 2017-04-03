#include <iostream>
#include <cmath>
using namespace std;

int normal(int sueldo,int edad,float acum,int apv,float interes,int edad_jubilacion)
{	
	for (int i = edad; i < edad_jubilacion; ++i)
	{
		acum=acum+(sueldo*12)*0.1+apv;
		acum=acum*(1+interes);
                sueldo=sueldo*1.001;
	}
	
	return acum/240;
}

int inversa(int jubilacion_estimada,int sueldo,int edad,float acum,float interes,int edad_jubilacion){
	
	for (int i = 0; i < sueldo; ++i)
	{
		
		if (jubilacion_estimada == normal(sueldo,edad,acum,i,interes,edad_jubilacion) || abs(jubilacion_estimada-normal(sueldo,edad,acum,i,interes,edad_jubilacion)) <=100)
		{
			return i;
		}
		
	}
}

int main(int argc, char const *argv[])
{
	while(true){
		cout<<"Bienvenido a el simulador de Jubilacion \"Con platita guardadita nos llenamos la pansita\""<<endl;
		cout<<"Desea saber el monto de su jubilacion (1) o calcular el apv necesario para su pension ideal(2)"<<endl;
		cout<<"ingrese la opcion (1) o (2): "<<endl;
		int choice;
		cin>>choice;
		int jubilacion_estimada,sueldo,edad,apv,edad_jubilacion;
		float interes,acum;
		if (choice==1)
		{
			cout<<"Por favor ingrese:"<<endl;
			cout<<"Sueldo"<<endl<<"Edad"<<endl<<"Monto acumulado hasta la fecha(si tiene)"<<endl<<"Ahorro Provicional voluntario"<<endl<<"interes"<<endl<<"Edad Jubilacion";
			cout<<"Por favor ingrese cada una de las variables separadas por un espacio"<<endl;		
			cin>>sueldo>>edad>>acum>>apv>>interes>>edad_jubilacion;
			cout<<"El monto de su jubilacion mensual estimada es de "<<normal(sueldo,edad,acum,apv,interes,edad_jubilacion)<<endl;
			cout<<"Desea hacer otro calculo? (1) = Si (0) = No"<<endl;
			cin>>choice;
			if (!choice)
			{
				break;
			}
		}
		else if(choice==2){
			cout<<"Por favor ingrese:"<<endl;
			cout<<"jubilacion estimada"<<endl<<"Sueldo"<<endl<<"Edad"<<endl<<"Monto acumulado hasta la fecha(si tiene)"<<endl<<"Interes"<<endl<<"Edad Jubilacion";
			cin>>jubilacion_estimada>>sueldo>>edad>>acum>>interes>>edad_jubilacion;
			cout<<"El ahorro previcional voluntario que usted deberia depositar mensualmente es de: "<<inversa(jubilacion_estimada,sueldo,edad,acum,interes,edad_jubilacion)<<endl;
			cout<<"Desea hacer otro calculo? (1) = Si (0) = No"<<endl;
			cin>>choice;
			if (!choice)
			{
				break;
			}
		}
		else {cout<<"Not in my watch, try again"<<endl;}
	}
	return 0;
}
