#include <xmlreader.h>
#include <iostream>
#include <cstdio>

int main()
{
	//std::std::cout << "TEST" << '\n';
	//const char* argument1 = args[1];
	//printf("%s",argument1);
	//std::cout << args[1]<< std::endl;
	const char* filename = "xmltestfile.xml";
	//memcpy(filename, args[1],sizeof(32));
	int eerr = Adon::EntityManager::XMLReader::LoadObjectsFromFile(filename);
	printf("%d hej \n", eerr);
	return 1;
}
