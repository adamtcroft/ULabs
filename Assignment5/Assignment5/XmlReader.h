#pragma once
#include <sstream>
#include "Element.h"

namespace Xml
{
	class Reader : public IXmlReader
	{
	public:
		Reader() = delete;

		Reader(const Reader& other) = delete;
		Reader(Reader&& other) = delete;

		Reader& operator=(const Reader& other) = delete;
		Reader& operator=(Reader&& other) = delete;

		~Reader() = default;

		static HElement loadXml(std::stringstream& xmlStream);
	};
}

