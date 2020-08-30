#include<iostream>
#include<vector>
using namespace std;

#include <vector>
#include<iterator>
#include<algorithm>
#include <iostream>
#include<vector>
using namespace std;

int main()
{
   vector<double>s;
s.push_back(11);
s.push_back(22);
s.push_back(33);
s.push_back(55);
for (auto it = s.begin(); it!=s.end(); it++) {
    cout << *it << endl;
}

}

