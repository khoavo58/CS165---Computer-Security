#include <iostream>
#include <string>

using namespace std;

int main() {

	string HASH = "WT9A81ixE0ygG7v8y7ijG/"
	string password = "";
	string salt = "4fTghp6q";
	string magic = "$1$";
	
	string alt_sum = md5(password + salt + password);
	string int_sum = md5(password + magic + salt + alt_sum.substr(0, 6) + password[0] + \0 + \0);
	
	for(unsigned int i = 0; i < 1000; i++) {
		
		string temp = "";
		
		if(i % 2 == 0) {
			temp += int_sum;
		}
		if(i % 2 == 1) {
			temp += password;
		}
		if(!(i % 3 == 0)) {
			temp += salt;
		}
		if(!(i % 7 == 0)) {
			temp += password;
		}
		if(i % 2 == 0) {
			temp += password;
		}
		if(i % 2 == 1) {
			temp += int_sum;
		}
		
		int_sum = md5(temp);
	}
	
	cout << magic << salt << "$";
	
	return 0;
}
