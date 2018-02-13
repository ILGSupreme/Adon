#include "helloworld.h"
#include <iostream>

using namespace tinyxml2;

tinyxml2::XMLError Adon::Adem::LoadObjectsFromFile(const char* filename)
{
	XMLDocument xmlDoc;
	XMLError err = xmlDoc.LoadFile(filename);

	switch (err)
	{
	case tinyxml2::XML_SUCCESS:
		printf("SUCCESS \n");
		break;
	case tinyxml2::XML_NO_ATTRIBUTE:
		printf("NO ATTRIBUTES \n");
		err = tinyxml2::XML_NO_ATTRIBUTE;
		break;
	case tinyxml2::XML_WRONG_ATTRIBUTE_TYPE:
		printf("WRONG ATTRIBUTE \n");
		err = tinyxml2::XML_WRONG_ATTRIBUTE_TYPE;
		break;
	case tinyxml2::XML_ERROR_FILE_NOT_FOUND:
		break;
	case tinyxml2::XML_ERROR_FILE_COULD_NOT_BE_OPENED:
		break;
	case tinyxml2::XML_ERROR_FILE_READ_ERROR:
		break;
	case tinyxml2::UNUSED_XML_ERROR_ELEMENT_MISMATCH:
		break;
	case tinyxml2::XML_ERROR_PARSING_ELEMENT:
		break;
	case tinyxml2::XML_ERROR_PARSING_ATTRIBUTE:
		break;
	case tinyxml2::UNUSED_XML_ERROR_IDENTIFYING_TAG:
		break;
	case tinyxml2::XML_ERROR_PARSING_TEXT:
		break;
	case tinyxml2::XML_ERROR_PARSING_CDATA:
		break;
	case tinyxml2::XML_ERROR_PARSING_COMMENT:
		break;
	case tinyxml2::XML_ERROR_PARSING_DECLARATION:
		break;
	case tinyxml2::XML_ERROR_PARSING_UNKNOWN:
		break;
	case tinyxml2::XML_ERROR_EMPTY_DOCUMENT:
		break;
	case tinyxml2::XML_ERROR_MISMATCHED_ELEMENT:
		break;
	case tinyxml2::XML_ERROR_PARSING:
		break;
	case tinyxml2::XML_CAN_NOT_CONVERT_TEXT:
		break;
	case tinyxml2::XML_NO_TEXT_NODE:
		break;
	case tinyxml2::XML_ERROR_COUNT:
		break;
	default:
		break;
	}

	return err;
}