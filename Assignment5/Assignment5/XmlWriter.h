#pragma once
#include "Element.h"
#include <iostream>
#include <algorithm>
#include <string>

namespace Xml
{
	class Writer
	{
	public:
		Writer() = delete;
		Writer(const Writer& other) = delete;
		Writer(Writer&& other) = delete;
		Writer& operator=(const Writer& other) = delete;
		Writer& operator=(Writer&& other) = delete;
		~Writer() = delete;

		static void writeXml(Xml::HElement& element, std::ostream& os);

	private:
		static void writeElement(const HElement& element, std::ostream& os);
		static void writeAttributes(const HElement& element, std::ostream& os);
	};
}

