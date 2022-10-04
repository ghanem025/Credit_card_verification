#include <iostream>
#include <string>
using namespace std;
using std::cout;
using std::cin;

int main(){
	string card_num;
	int total;
	cout << "Enter your card number";
	cin >> card_num; // enter card number
	cout << card_num << '\n';
	for (int i=0;i<card_num.size();i++){ // look through each number
		
		if (i % 2 != 0){ // if the number is not even add it to the total
			cout << card_num[i];
			int total = card_num[i] * 2;
			if (total >= 10){
				int num1 = total % 10;
				int num2 = total / 10
				cout << num1;
				cout << num2; 
				
			}
			cout << total;
			cout << '\n';
		}
		else if (i%2 == 0){
			cout << card_num[i]
			int total = card_num[i] * 1;
			
		}
	}
	cout << "Testing out";
}
