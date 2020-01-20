#include <iostream>
#include <cstring>
#include <string>
#include "md5.h"

using namespace std;

std::string HexToString(std::string hex) {
	
	string temp = "";

	return temp;
}

int main() {
	string HASH = "Rh3y.sliHc04vdTkuHgN.1"; //"WT9A81ixE0ygG7v8y7ijG/";
	string password = "ztpwms";
	string salt = "hfT7jp2q"; //"4fTghp6q";
	string magic = "$1$";

	//string temp = MD5(password).hexdigest();
	//cout << "temp: " << temp << endl;
	
	unsigned char* alt_sum = MD5(password + salt + password).digest;
	//string digest = MD5(password + salt + password).hexdigest();
	//cout << "digest: " << digest << endl;
	
	string temp = "";
	for(unsigned int i = 0; i < 6; i++) {
		temp.push_back(alt_sum[i]);
	}

	unsigned char* int_sum = MD5(password + magic + salt + temp  + password[0] + '\0' + '\0').digest;
	//string intermediate = MD5(password + magic + salt + temp + password[0] + '\0' + '\0').hexdigest();
	//cout << "intermediate: " << intermediate << endl;

	for(unsigned int j = 0; j < 1000; j++) {
		
		string interm = "";

		for(unsigned int k = 0; k < 16; k++) {
			interm.push_back(int_sum[k]);
		}

		string str = "";

		if(j % 2 == 0) {
			str += interm;
		}
		if(j % 2 == 1) {
			str += password;
		}
		if(!(j % 3 == 0)) {
			str += salt;
		}
		if(!(j % 7 == 0)) {
			str += password;
		}
		if(j % 2 == 0) {
			str += password;
		}
		if(j % 2 == 1) {
			str += interm;
		}

		int_sum = MD5(str).digest;
	}
	
	cout << magic + salt + "$";

	string crypt64 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	unsigned char final[16];
	final[0] = int_sum[11];
	final[1] = int_sum[4];
	final[2] = int_sum[10];
	final[3] = int_sum[5];
	final[4] = int_sum[3];
	final[5] = int_sum[9];
	final[6] = int_sum[15];
	final[7] = int_sum[2];
	final[8] = int_sum[8];
	final[9] = int_sum[14];
	final[10] = int_sum[1];
	final[11] = int_sum[7];
	final[12] = int_sum[13];
	final[13] = int_sum[0];
	final[14] = int_sum[6];
	final[15] = int_sum[12];	

	unsigned long long a = (0 | final[13] << 16) | (final[14] << 8) | final[15];
	unsigned long long b = (0 | final[10] << 16) | (final[11] << 8) | final[12];
	unsigned long long c = (0 | final[7] << 16) | (final[8] << 8) | final[9];
	unsigned long long d = (0 | final[4] << 16) | (final[5] << 8) | final[6];
	unsigned long long e = (0 | final[1] << 16) | (final[2] << 8) | final[3];
	unsigned long long f = 0 | final[0];
	string result = "";
	int x = 0;

	while(a != 0) {
		x = a & 0x3F;
		result += crypt64[x];
		a = a >> 6;
	}

	while(b != 0) {
		x = b & 0x3F;
		result += crypt64[x];
		b = b >> 6;
	}

	while(c != 0) {
		x = c & 0x3F;
		result += crypt64[x];
		c = c >> 6;
	}

	while(d != 0) {
		x = d & 0x3F;
		result += crypt64[x];
		d = d >> 6;
	}

	while(e != 0) {
		x = e & 0x3F;
		result += crypt64[x];
		e = e >> 6;
	}

	while(f != 0) {
		x = f & 0x3F;
		result += crypt64[x];
		f = f >> 6;
	}

	cout << result << endl;

	if(result == HASH) {
		cout << "Congrats! You've found the password!" << endl;
		cout << "Your password is: " << password << endl;
	}
	
	return 0;
}
