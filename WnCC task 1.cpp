#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
using namespace std;
struct event{
	string name;
	int start_time;
	int duration;
};
bool sortData(event a,event b){
	return a.start_time > b.start_time;
}
int MaxAttended(vector<event> dataBase){
	if(dataBase.size()==0)	return 0;
	//ans1 stores answer if first one is attended
	//ans2 stores answer if first one is not attended
	event curr = dataBase[dataBase.size()-1];
	dataBase.pop_back();
	int ans2 = MaxAttended(dataBase);
	int new_start_time = curr.start_time + curr.duration;
	int i=dataBase.size()-1;
	for(;i>=0;i--){
		if(dataBase[i].start_time >= new_start_time)	break;
		dataBase.pop_back();
	}
	int ans1 = 1 + MaxAttended(dataBase);
	return max(ans1,ans2);
}
int main(){
	ifstream fin;
	fin.open("Schedule.txt");
	string curr;
	fin>>curr;
	vector<event> DataBase;
	while(!fin.eof()){
		event now;
		now.name = curr;
		fin>>now.start_time;
		fin>>now.duration;
		fin>>curr;
		DataBase.push_back(now);
	}
	sort(DataBase.begin(),DataBase.end(),sortData);
	cout<<MaxAttended(DataBase);
}