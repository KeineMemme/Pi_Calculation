#include<stdio.h>
#include<conio.h>
#include<math.h>

//Continued fraction
//http://en.wikipedia.org/wiki/Continued_fraction
double continued_fraction_pi(double c, double n, double max) {
	c = c + 2.0*(n-1.0);
	if(n == max) {
		return c + n*n;
	}
	else {
		return c+(n*n/continued_fraction_pi(c,n+1.0,max));
	}
}

//Leibniz formula for PI:
//http://en.wikipedia.org/wiki/Leibniz_formula_for_%CF%80
double leibniz_calc_pi(int max) {
	double sum = 0;
	int i;
	for(i = 0; i < max; i++) {
		sum += pow(-1,(double)i)/(2.0*i+1.0);
	}
	return sum * 4.0;
}



int main(void) {

	printf("%lf\n",4.0/continued_fraction_pi(1.0,1.0,100.0));
	printf("%lf",leibniz_calc_pi(1000000));
	getch();
	return 0;
}