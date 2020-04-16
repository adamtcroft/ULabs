#pragma once

#include "XmlInterfaces.h"
#include "Element.h"
#include "XmlReader.h"

namespace Xml
{
	class ElementFactory
	{
	public:
		static HElement createElement(const std::string& name);
	};
}
