#include<iostream>
using namespace std;
int main()
{
	string msg;
	int i;
	cin >> msg;
	for(i=0;i<msg.size();i++){
		if(msg[i]=='1'){
			cout << "-";
		}else if(msg[i]=='0'){
			cout << '+';
		}
	}
	cout << endl;
	return 0;
}
