#include <iostream>
#include <math.h>

double x_min = 0.0;
double x_max= 10.0;
double N = 100000;
double h = (x_max-x_min)/N;

double m=1.;
double g=9.8;
double l=1.;
double k = 1.;

double f_ext=10.;
double fr=10.;

double alpha = g/l;
double beta = fr/m;
double gam=f_ext/(m*l);
double omega=10.;

double derivada(double x, double y, double y_prima);
double derivada_2(double x, double y, double y_prima);

int main()
{	
	double y[int((x_max-x_min)/h)];
	double y_prima[int((x_max-x_min)/h)];
	
	y[0]=M_PI/16.;
	y_prima[0]=0;
	double x = x_min;	
	std::cout << x << " " << y[0] << std::endl;	
	for(int i=1;i<N;i++)
	{	
		double k1,k2,k3,k4 = 0;
		double k1_2,k2_2,k3_2,k4_2 = 0;

		//Runge-kutta para y

		k1 = h * derivada(x,y[i-1],y_prima[i-1]);

		k2 = h*derivada(x+0.5*h,y[i-1]+0.5*k1,y_prima[i-1]);

		k3 = h*derivada(x+0.5*h,y[i-1]+0.5*k2,y_prima[i-1]);

		k4 = h*derivada(x+h, y[i-1]+k3,y_prima[i-1]);

		y[i] = y[i-1] + (1.0/6.0)*(k1+2.0*k2+2.0*k3+k4);	
	
		// Runge-kutta para y'

		k1_2 = h * derivada_2(x, y[i-1], y_prima[i-1]);

		k2_2 = h*derivada_2(x+0.5*h, y[i-1], y_prima[i-1]+0.5*k1);

		k3_2 = h*derivada_2(x+0.5*h, y[i-1], y_prima[i-1]+0.5*k2);

		k4_2 = h*derivada_2(x+h, y[i-1] ,y_prima[i-1]+k3);

		y_prima[i] = y_prima[i-1] + (1.0/6.0)*(k1_2+2.0*k2_2+2.0*k3_2+k4_2);		

		std::cout << x << " " << y[i] << std::endl;
		
		x = x+h;

		
	}
		
	return 0;
}

double derivada(double x, double y, double y_prima)
{
	return y_prima;
}

double derivada_2(double x, double y, double y_prima)
{
	return -alpha*sin(y)-beta*y_prima + gam*cos(omega*x);
}
