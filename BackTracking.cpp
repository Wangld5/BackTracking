#include<iostream>
#include<vector>
using namespace std;
int count=0;
vector<int> bestMatch;
int T, n;
int all[100];
void BackTracking(int rest, int position){
	if(rest==0) return;//check wether it's full
	if(position==n) return;//check wether it's end
	BackTracking(rest, position+1);
	if(all[position]>rest) return;//check wehter the goods is heavier than rest
	bestMatch.push_back(all[position]);
	if(rest==all[position]){//fit the condition
		count++;
		cout<<"the "<<count<<"th solution"<<endl;
		for(int i=0;i<bestMatch.size();i++){
			cout<<bestMatch[i]<<" ";
		}
		cout<<endl;
	}
	BackTracking(rest-all[position], position+1);//go to the next rest
	bestMatch.pop_back();//pop the last goods
}
int main(){
	cout<<"please input the capcity of package and quantity of goods"<<endl;
	cin>>T>>n;
	while(cin.fail()){
		cin.clear();
		cin.sync();
		cout<<"please input the int"<<endl;
		cin>>T>>n;
	}
	cout<<"input the goods"<<endl;
	for(int i=0;i<n;i++){
		cin>>all[i];
		while(cin.fail()){
			cin.clear();
			cin.sync();
			cout<<"please input the int"<<endl;
			cin>>T>>n;
		}
	}
	BackTracking(T,0);
}
