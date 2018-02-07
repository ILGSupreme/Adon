#include "helloworld.h"
#include <xercesc\util\PlatformUtils.hpp>

using namespace xercesc;

int testlib()
{
	try {
		XMLPlatformUtils::Initialize();
	}
	catch (const XMLException& toCatch) {
		// Do your failure processing here
		return 1;
	}

	// Do your actual work with Xerces-C++ here.

	XMLPlatformUtils::Terminate();
	return 1;
}