#include<iostream>

using namespace std;

template <typename T>

T sqr(T x){
	return x*x;
}

int main(){
	cout<<sqr(5)<<endl;
	cout<<sqr(4.4)<<endl;
	return 0;
}
