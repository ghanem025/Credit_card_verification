#include <iostream>
#include <string>
using namespace std;
using std::cout;
using std::cin;

string cardType(int n){
	switch(n){
		case 3:
			return "Amex";
		case 4:
			return "Visa";
		case 5:
			return "Mastercard";
		default:
			return "is not a Visa/mastercard or Amex";
	}
}

int main(){
	string card_num;
	int total = 0;
	cout << "Enter your card number: ";
	cin >> card_num; // enter card number
	
	for (int i=0;i<card_num.size();i++){ // look through each number
		
		if (i % 2 == 0 || i==0){ // if the number is not even add it to the total
			int product = (card_num[i] - '0') * 2;
			if (product >=10){
				string number = to_string(product);	
				int add = (number[0] - '0') + (number[1] - '0');
				total += add;
			}
			else{
				total += product;
			}	
		}
		else if (i%2 != 0){
			int product = (card_num[i] - '0') * 1;
			total += product;
		}
	}
	if (total %10 ==0){
		cout << "The credit card is valid\n";
		cout << "This is a card " << cardType((card_num[0] - '0')) << " card";
	}
	else{
		cout << "The credit card is not valid\n";
	}
}
