#include "adem.h"
#include <iostream>

int main(int argc,char *args[])
{
	printf(args[1]);
	std::cout << args[1]<< std::endl;
	char* filename = args[1];
	//memcpy(filename, args[1],sizeof(32));
	int eerr = Adon::Adem::LoadObjectsFromFile(filename);
	return eerr;
}