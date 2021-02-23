#include <iosteram>
#include <string>

void XOR(std::string &text, std::string key){
	for (unsigned int i = 0; i < text.size(); ++i)
		text[i] ^= key[i % key.size()]; 
}


int main() // nice, func needs 2 lines, but tests need > 30
 {
	std::string a; // text
	getline(std::cin, a);
	std::string b; //key
	getline(std::cin, b);

	std::cout << "\nrequested:\n in  [inline]:  ";
	for (int x : a)
		printf("%.2X", x);

	std::cout << "\n in   [split]:  ";
	for (int x : a)
		printf("%.2X ", x);

	XOR(a, b);
	
	std::cout << "\nencrypted:\n out [inline]:  ";
	for (int x : a)
		printf("%.2X", x);

	std::cout << "\n out  [split]:  ";
	for (int x : a)
		printf("%.2X ", x);
	
	XOR(a, b);

	std::cout << "\ndecrypted:\n ret [inline]:  ";
	for (int x : a)
		printf("%.2X", x);

	std::cout << "\n ret  [split]:  ";
	for (int x : a)
		printf("%.2X ", x);

	std::cout << "\nmain text was:\n" << a << '\n';
		
}
