#include <iostream>
#include <algorithm>
using namespace std;

bool reverse_order(const int& first, const int& second){
	return first<second;
}

template < class T>
void print(const vector<T>& vec){
	for(const auto& cell : vec)
		cout<< cell << " ";
	cout<<endl;
}

int main(){
	vector<int> ivec={4,3,2,8,2,1,1,9,8,6,0,7,1};
	print<int>(ivec);
	sort(ivec.begin(), ivec.end());
	print<int>(ivec);
	sort(ivec.begin(), ivec.end(), reverse_order);
	print<int>(ivec);
	cout<<"Lambda:\n";
	sort(ivec.begin(), ivec.end(),
			[](const int& first, const int& second){ return first>second;}
			);
	print<int>(ivec);
}
