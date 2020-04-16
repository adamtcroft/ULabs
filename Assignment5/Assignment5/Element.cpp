#include "Element.h"
#include <iostream>

namespace Xml
{
	Element::Element() :
		myXMLDocument{ std::make_shared <tinyxml2::XMLDocument>() },
		myElement{ myXMLDocument->RootElement() }
	{
	}

	Element::Element(const std::string& name) :
		myXMLDocument{ std::make_shared <tinyxml2::XMLDocument>() },
		myElement{ myXMLDocument->RootElement() }
	{
		myElement = myXMLDocument->NewElement(name.c_str());
		myElement->SetName(name.c_str());
	}

	Element::Element(tinyxml2::XMLElement* node) :
		myXMLDocument{ nullptr },
		myElement{ node }
	{
	}

	void Element::createFromXml(std::string& xmlStr)
	{
		if (myXMLDocument->Parse(xmlStr.c_str()) != tinyxml2::XML_SUCCESS)
		{
			throw std::runtime_error("Error Parsing XML Stream");
		}

		myElement = myXMLDocument->RootElement();
	}

	std::string Element::getName() const noexcept
	{
		return std::move(std::string(myElement->Name()));
	}

	std::string Element::getAttribute(const std::string& name) noexcept
	{
		auto result = myElement->Attribute(name.c_str());
		return (result == nullptr) ? "" : result;
	}

	AttributeMap Element::getAttributes() const noexcept
	{
		AttributeMap attributes;

		auto attribute = myElement->FirstAttribute();

		while (attribute != nullptr)
		{
			attributes.emplace(attribute->Name(), attribute->Value());
			attribute = attribute->Next();
		}

		return std::move(attributes);
	}

	void Element::setAttribute(const std::string& name, const std::string& value)
	{
		myElement->SetAttribute(name.c_str(), value.c_str());
	}

	ElementCollection Element::getChildElements() const noexcept
	{
		ElementCollection elements;

		if (!myElement->NoChildren())
		{
			auto node = myElement->FirstChildElement();
			while (node != nullptr)
			{
				auto element = new Element(node);
				elements.emplace_back(element);
				node = node->NextSiblingElement();
			}
		}

		return std::move(elements);
	}

	HElement Element::appendChild(const std::string& name) noexcept
	{
		auto newElem{ new Element(myElement->GetDocument()->NewElement(name.c_str())) };

		myElement->InsertEndChild(newElem->myElement);

		HElement hElem{ dynamic_cast<IElement*>(newElem) };
		return std::move(hElem);
	}
}
