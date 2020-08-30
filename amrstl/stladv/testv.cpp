#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<cmath>
using namespace std;
double f(){
	return 212;
}
int main(){
	vector<double> s(9);
	int i;
	for (i=0;i<=8;i++){
		s[i]=i;
	}
	for (i=0;i<=8;i++){
		
		cout<<"s["<<i<<"] = "<<s[i]<<endl;
	}
    
      s.insert(s.begin()+2,34);
      
//	s[3]=NULL;
//	s[4]=NULL;
//	i=0;
	//s[3]=f();
/*	while(i<s.size()){
		if(s[i]==NULL) s.erase(s.begin()+i);
		i++;
	}*/
	//	it++;
//	}

    cout<<s.size()<<"--------------------------\n";
  // s[3]=NULL;
	for (i=0;i<s.size();i++){
		cout<<"s["<<i<<"] = "<<s[i]<<endl;
	}
	return 0;
}
