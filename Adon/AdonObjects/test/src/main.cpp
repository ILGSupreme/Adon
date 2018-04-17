#include <adonobjects/xml.h>
#include <adonobjects/container.h>
#include <adonobjects/model.h>
#include <adonobjects/script.h>
#include <adonobjects/xmlmanager.h>
#include <adonobjects/filemanager.h>
#include <exception/exception.h>
#include <iostream>
#include <cstdio>

using namespace Adon::AdonObjects;
using namespace Adon::Exception;

int main()
{
	Managers::Filemanager fileman;
	Managers::XMLManager manager;
	manager.ParseFile("xmltestfile.xml","THUTGAT");
	manager.ParseDoc(*manager.documents.back().get());
	return 1;
}
