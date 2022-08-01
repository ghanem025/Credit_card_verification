#include <iostream>
#include <string>
using namespace std;
using std::cout;
using std::cin;

int main(){
	string card_num;
	int total;
	cout << "Enter your card number";
	cin >> card_num;
	cout << card_num << '\n';
	for (int i=0;i<card_num.size();i++){
		if (i % 2 != 0){
			cout << card_num[i];
			int total = card_num[i] * 2;
			cout << total;
			cout << '\n';
		}
		//for (int j=0;j<i;i++){
		//	
		//}
		//cout << card_num[i] << '\n';
	}
}
