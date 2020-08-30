#include<iostream>
#include<vector>
//#include<iterator>
//#include<algorithm>
//#include<numeric>


using namespace std;

bool f(int x,int y){ return x>y;}
/*void vecdemo(){
vector<int> a{1,2,10,34,5};
	for(auto it=a.begin();it<a.end();++it)
	cout<<*it<<endl;
	vector<int>::iterator low,up;
    low=lower_bound(a.begin(),a.end(),10);
	up=upper_bound(a.begin(),a.end(),10);
	cout<<up-low<<endl;
	sort(a.begin(),a.end());
	
	for(auto it=a.begin();it<a.end();++it)
	cout<<*it<<endl;
	sort(a.begin(),a.end(),f);
	for(auto it=a.begin();it<a.end();++it)
	cout<<*it<<endl;
	bool res=binary_search(a.begin(),a.end(),15);
	a.push_back(233);
	for(auto it=a.begin();it<a.end();++it)
	cout<<*it<<endl;	
}*/
int main(){
	vector<double> x(10);
	for (int j=1;j<=10;j++) x[j][j]=j+2;
	//sort(x.begin(),x.end());
	for(auto i=x.begin();i!=x.end();++i) cout<<*i<<"  ";
	cout<<"\n";
//	x.insert(x.begin()+1,4.0);
    x.erase(x.begin()+1);
	//x.at(3)=.9098987;
	//sort(x.begin(),x.end());
	for(auto i=x.begin();i!=x.end();++i) cout<<*i<<"  ";
	cout<<"\n";
	return 0;
}
