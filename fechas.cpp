//Laboratorio fechas
#include <iostream>
#include <math.h>

using namespace std;

int day,month,year;
int day_0=1,month_0=1,year_0=2001;
int i,res;
int counter_days=0;

//LLAMA FUNCIONES AUXILIARES
bool is_leap_year(int year);
int get_days_in_month(int month);
string get_days_name(int week_day);

//FUNCION PRINCIPAL
int main()
{
	cout<<"Ingrese la fecha a operar'"<<endl;
	cout<<"Ingrese al anio aaaa"<<endl;
	cin>>year;
	if(year<1)
	{cout<<"El anio 0 no existe"<<endl;exit;}
	
	cout<<"Ingrese al mes mm"<<endl;
	cin>>month;
	if(month<1 || month >12)
	{cout<<"El mes debe ser un entero entre 1 y 12"<<endl;exit;}
	
	cout<<"Ingrese al dia dd"<<endl;
	cin>>day;
	if(day<1 || day >31)
	{cout<<"El dia debe ser un entero entre 1 y 31"<<endl;exit;}
		
	if(year-year_0>=0)
	{
		//CALCULO DE DIAS EN DIFERENCIA DE A�OS
		for(i=year_0;i<year;i++)
		{
			if(is_leap_year(i))
			{
				counter_days +=366;
			}
			else
			{
				counter_days +=365;
			}
		}
		
		//CALCULO DE DIAS EN DIFERENCIA DE MESES
		for(i=1;i<month;i++)
		{
			counter_days += get_days_in_month(i);
		}
		
		//CALCULO DE DIAS EN DIFERENCIA DE DIAS
		counter_days += day;
		res = counter_days % 7;
	}
	else
	{
		//CALCULO DE DIAS EN DIFERENCIA DE A�OS
		for(i=year_0-1;i>year;i--)
		{
			if(is_leap_year(i))
			{
				counter_days +=366;
			}
			else
			{
				counter_days +=365;
			}
		}
		
		//CALCULO DE DIAS EN DIFERENCIA DE MESES	
		for(i=12;i>month;i--)
		{
			counter_days += get_days_in_month(i);
		}
			
		//CALCULO DE DIAS EN DIFERENCIA DE DIAS
		counter_days += get_days_in_month(month)-day;
		res = 7-(counter_days % 7);
	}
	
	cout<<"El conteo total de dias con respecto a la fecha 0 es "<<counter_days<<endl;
	
	cout<<"La dada fecha es "<<year<<"-"<<month<<"-"<<day<<endl;
	cout<<"El dia de la semana es "<<get_days_name(res)<<endl;
	
	system("pause");
	return 0;
}

//FUNCIONES AUXILIARES
bool is_leap_year(int year=0)
{
	if(year%4==0)
	{
		if(year%100==0)
		{
			if(year%400==0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}


int get_days_in_month(int month)
{
		switch (month)  
		{
	        case 4:
	        case 6:
	        case 9:
	        case 11:
				//cout<<"sumando 30 en mes "<<i<<endl;
				return 30;
			case 2:  
				if(is_leap_year(year))
				{
					//cout<<"sumando 29 en mes "<<i<<endl;
					return 29;
				}
				else
				{
					//cout<<"sumando 28 en mes "<<i<<endl;
					return 28;
				}
	            break;
	        case 1:
	        case 3:
	        case 5:
	        case 7:
	        case 8:
	        case 10:
	        case 12:
				//cout<<"sumando 31 en mes "<<i<<endl;
				return 31;
	        default:
				cout<<"error en el calculo de meses"<<endl;
	            return false;
	        	
		}
}


string get_days_name(int week_day)
{
		switch (week_day)  
		{
	        case 0:
				return "Domingo";
	            break;
	        case 1:
				return "Lunes";
	            break;
			case 2:  
				return "Martes";
	            break;
	        case 3:
				return "Miercoles";
	            break;
	        case 4:
				return "Jueves";
	            break;
	        case 5:
				return "Viernes";
	            break;
	        case 6:
				return "Sabado";
	            break;
	        case 7:
				return "Domingo";
	            break;
	        default:
				cout<<"Error al obtener el nombre del dia"<<endl;
	            return false;
	        	
		}
}


