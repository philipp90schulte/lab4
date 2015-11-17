#include <iostream>
#include <cmath>

using namespace std;


void print(double* p, const int N, const double dx,
           const double xmin)
{
   for(int i=0; i<N; i++)
       cout << i*dx + xmin << "\t" << p[i] << endl;
}

void fillArray(double* p, const int N, const double dx,
           const double xmin) {
	double x;
        for (int i = 0; i <= N-1; i++) {
                x = xmin + i * dx;
                p[i] = exp(-1 * (x * x));
        }
}

void derivative(double* p, const int N, const double dx) {
	double l = 0;
	double z = l; 
	p[0] = 0;
	p[N-1] = 0;
	for (int i = 1; i <= N-2; i++) {
		z = p[i];
		p[i] = (p[i+1] - l)/(2 * dx);
		l = z;
	}
}


int main(){
  const int N = 1000;
  double p[N];
  double* pp = p;
  const double xmax = 15;
  const double xmin = -15;
  const double dx = (xmax-xmin)/(N-1);

  // call to function which fills array p here
	fillArray(pp, N, dx, xmin);
	//cout << "Ausgabe Ursprungsarray." << endl;
	//print(pp, N, dx, xmin);
  // call to functio which calculates the derivative
	derivative(pp, N, dx);
	//cout << "Berechnete Ableitung." << endl;
  	print(p,N,dx,xmin);

  return 0;
}
