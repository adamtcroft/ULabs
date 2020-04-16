#include "XmlFactories.h"

using namespace Xml;

HElement ElementFactory::createElement(const std::string& name)
{
	HElement hElem = std::make_shared<Element>(name);
	return std::move(hElem);
}
