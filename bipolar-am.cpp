#include<iostream>
using namespace std;
int main()
{
	int i;
	string msg;
	cin >> msg;
	char last = '+';
	for(i=0;i<msg.size();i++){
		if(msg[i]=='0'){
			cout << '0' ;
		}else if(msg[i]=='1'){
			if(last == '+'){
				last ='-';
				cout << last;
			}else if(last == '-'){
				last = '+';
				cout << last;
			}
		}
	}
	return 0;
}
