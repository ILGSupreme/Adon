#include <xmlstaticfuncs.h>
#include <iostream>
#include <cstdio>

int main()
{
	const char* filename = "xmltestfile.xml";
	Adon::EditorObjects::XML::XMLData data;
	int eerr = Adon::EditorObjects::XML::XMLStaticFuncs::LoadObjectsFromFile(filename,data);
	printf("Reading results is %d \n", eerr);
	return 1;
}
