#include <iostream>
#include <string>
using namespace std;
using std::cout;
using std::cin;

int main(){
	string card_num;
	cout << "Enter your card number";
	cin >> card_num;
	cout << card_num << '\n';
	if (card_num[0] == '4'){
		cout << "This is a Visa card \n";
	}
	for (int i=0;i<card_num.size();i++){

		cout << card_num[i] << '\n';
	}
}
