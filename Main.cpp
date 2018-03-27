#include <iostream>
#include <string>
#include "Inter.cpp"
#include "TokenParser.cpp"

int main(){
	char buffer[1001];
	std::cin.getline(buffer, 1001);
	Inter(TokenParser(buffer));
	return 0;
}
