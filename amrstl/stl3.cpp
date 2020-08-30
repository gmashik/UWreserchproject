#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<numeric>
#include<fstream>
using namespace std;
double f(double x){
	return exp(-100*pow((x-.5),2));
}
int main(){
	ofstream out;
	ofstream out1;
	ofstream out2;
	ofstream out3;
	ofstream out4;
	out.open("out.dat");
	out1.open("out1.dat");
	out2.open("out2.dat");
	out3.open("out3.dat");
	out4.open("out4.dat");
	vector<double> u(200),x(200),xp(200);
	int i,j,n{100},ri1,ri2;
	double vel{1},dx,dt,t,tfin{.5};
	dx=1.0/n;
	dt=dx/(2.0*vel);
	double cfl=vel*(dt/dx);
	cout<<cfl<<" "<<dt<<endl;
	for(i=0;i<=100;i++){
		x[i]=0+i*dx;
		u[i]=f(x[i]);
		out<<x[i]<<"  "<<u[i]<<endl;
	}
	xp=x;
	t=0;
	j=0;
	while(t<tfin){
		u[n+2]=u[n+1];
		ri1=0;
		ri2=0;		
		//time integration and refinement interval identifying
		for( i=1;i<=n+1;i++){
		u[i]=u[i]-(cfl/2.0)*(u[i+1]-u[i-1]);
		if(u[i]>=.4 && ri1==0){
		ri1=i;
		ri2=i;
		}
        if(abs(u[i])>=.4 && i>ri2) ri2++;
		} 
		for(i=0;i<abs(ri2-ri1);i++){
		double p=x[ri1+i]+dx/2.0;
			xp.insert(xp.begin()+ri1+2*i+1,p);
		}
	 
		if(j==5){    
		     cout<<xp.size()<<endl;   
			for(i=0;i<=n+abs(ri2-ri1);i++) cout<<xp[i]<<"\n";                    
			for(i=0;i<=n;i++) out1<<x[i]<<" "<<u[i]<<"\n";   
        }
		t=t+dt;
		j++;
		xp=x;
	
    }
	return 0;
}
