#include "XmlReader.h"

Xml::HElement Xml::Reader::loadXml(std::stringstream& xmlStream)
{
	std::string xmlStr = xmlStream.str();
	HElement hElement = std::make_shared<Element>();

	hElement->createFromXml(xmlStr);

	return hElement;
}
