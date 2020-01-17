#include <iostream>
#include <cstring>
#include <string>
#include "md5.h"

using namespace std;

int main() {

	string HASH = "WT9A81ixE0ygG7v8y7ijG/";
	string password = "ztpwms";
	string salt = "4fTghp6q";
	string magic = "$1$";
	string str;
	
	string alt_sum = MD5(str.c_str(password + salt + password));
	string int_sum = MD5(str.c_str(password + magic + salt + alt_sum.substr(0, 6) + password[0] + '\0' + '\0'));
	/*
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
	*/
	cout << magic + salt + "$";
	
	string crypt64 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	//cout << "Intermediate sum: " << int_sum << endl;
	//string final = int_sum[11] + int_sum[4] + int_sum[10] + int_sum[5] + int_sum[3] + int_sum[9] + int_sum[15] + int_sum[2] + int_sum[8] + int_sum[14] + int_sum[1] + int_sum[7] + int_sum[13] + int_sum[0] + int_sum[6] + int_sum[12];

	return 0;
}
