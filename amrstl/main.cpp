#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<numeric>
#include<fstream>
#include "header.h"
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
	ofstream out5;
	ofstream out6;
	out.open("out.dat");
	out1.open("out1.dat");
	out2.open("out2.dat");
	out3.open("out3.dat");
	out4.open("out4.dat");
	out5.open("out5.dat");
	out6.open("out6.dat");
	vector<double> u(200),x(200),xp(200),up(200),um(200),xt(200);
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
	up=u;
	um=u;
	xp=x;
	t=0;
	j=0;
	while(t<tfin){
		u[n+2]=u[n+1];
		ri1=0;
		ri2=0;		
		//time integration and refinement interval identifying start
		for( i=1;i<=n+1;i++){
		u[i]=u[i]-(cfl/2.0)*(u[i+1]-u[i-1]);
		if(u[i]>=.4 && ri1==0){
		ri1=i;
		ri2=i;
		}
        if(abs(u[i])>0.2 && i>ri2) ri2++;
		} 
		//time integration and refinement interval identifying end---------
		//----------------------------------------------------
		// Refinements and grid buffereing start
		for(i=0;i<=abs(ri2-ri1);i++){
		double p=x[ri1+i]+dx/2.0;
			xp.insert(xp.begin()+ri1+2*i+1,p);
		}
		for(i=0;i<=abs(ri2-ri1);i++){
		double p=lnp(x[ri1+i-1],x[ri1+i],x[ri1+i+1],up[ri1+i-1],up[ri1+i],up[ri1+i+1],xp[ri1+2*i+1]);
			um.insert(um.begin()+ri1+2*i+1,p);
		}
		// Refinements and grid buffereing end----------------
		//----------------------------------------------------
		//time integration in the refined grid start
		for(int k=1;k<=2;k++){
			for(i=ri1;i<=ri1+2*abs(ri2-ri1)+1;i++){
				um[i]=um[i]-(cfl/2.0)*(um[i+1]-um[i-1]);
			}
		}
		//time integration in the refined grid end
		//-----------------------------------------------
		//return refined value in the coarse grid
		for(i=1;i<=abs(ri1-ri2);i++){
			u[ri1+i]=(um[ri1+2*i-1]+um[ri1+2*i]+um[ri1+2*i+1])/3.0;
		}
		//return refined value in the coarse grid
		xt=xp;
		for(i=0;i<=ri1;i+=2){
			xt[i+1]=NULL;
		}
		//Plotting start------------------------------------
		if(j==5){    
			for(i=0;i<=n+abs(ri2-ri1);i++) out4<<xp[i]<<" "<<0<<"\n";                    
			for(i=0;i<=n;i++) out1<<x[i]<<" "<<u[i]<<"\n";   
        }
        if(j==10){    
            for(i=0;i<=n+abs(ri2-ri1);i++) if(xt[i]!=NULL) out5<<xt[i]<<" "<<0<<"\n";               
			for(i=0;i<=n;i++) out2<<x[i]<<" "<<u[i]<<"\n";   
        }if(j==15){    
			for(i=0;i<=n+abs(ri2-ri1);i++) out6<<xp[i]<<" "<<0<<"\n";                    
			for(i=0;i<=n;i++) out3<<x[i]<<" "<<u[i]<<"\n";   
        }
        //plotting end-------------------------------------
		t=t+dt;
		j++;
		xp=x;
		up=u;
		um=u;
	
    }
	return 0;
}
