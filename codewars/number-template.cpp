#include <iostream>
#include <string>

using std::string;

string prettify(string old){
	string phone = "+x (xxx) xxx-xx-xx";
	for (int i = 0, j = 0; i < (int)phone.length(); i++)
	{
		if(phone[i] == 'x'){
			if(j >= (int)old.length())
				break;
			phone[i] = old[j]; 
			j++;
		}
	}
	
	return phone;
}

int main(){
	string phone = "79113546682";
	phone = prettify(phone);
	std::cout << phone << "\n";
	return 0;
}
