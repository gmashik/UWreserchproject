#include<iostream>
#include<cmath>
#include "header.h"
using namespace std;

double lnp(double a,double b,double c,double d,double e,double f,double g){		
	int i,n;
	double xa,ya;
	n=3;
	double x[]={a,b,c};
	double y[]={d,e,f};
	xa=g;
	ya=0.0;
	
	for(i=0;i<n;i++){
		double p=1.0;
		for (int j=0;j<n;j++){
			if(i==j) continue;
			p=p*((xa-x[j])/(x[i]-x[j]));
		}
		ya=ya+y[i]*p;
	}
	return ya;
}
