#include <iostream>
#include <string>
#include <cmath>

using std::cout;
using std::endl;
using std::string;

string convert(int i, int syst){ 
	string ch;
	int n;
	char symbols[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	do {
		n = i % syst;
		i = (i - n) / syst;
		ch = symbols[n] + ch;
	} while (i > 0);
	return ch;
}

int devert(string s, int syst){
	int sum = 0;
	char symbols[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < (int) s.length(); i++)
	{
		for (int j = 0; j < (int) sizeof(symbols); j++)
		{
			if (s[i] == symbols[j])
			{
				sum = sum + j * pow(syst, (s.length()-1) - i); 
				break;
			}
		}	
	}
	
	return sum;
}

int main()
{
	int a = 45;
	string b = convert(a, 2);
	cout << b << endl << devert(b, 2) << endl;
	cout << convert(100, 16) << endl << devert("21312", 4);
}
