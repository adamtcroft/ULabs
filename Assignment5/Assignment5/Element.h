#pragma once
#include <list>
#include <vector>
#include <map>
#include <cstring>
#include "XmlInterfaces.h"
#include "../tinyxml2-master/tinyxml2.h"

namespace Xml
{
	class Element : public IElement
	{
	public:
		Element();
		explicit Element(const std::string& name);
		Element(const Element& other) = delete;
		Element(Element&& other) = delete;
		Element& operator=(const Element& other) = delete;
		Element& operator=(Element&& other) = delete;
		~Element() = default;

		void createFromXml(std::string& xmlStr) override;
		std::string getName() const noexcept override;

		void setAttribute(const std::string& name, const std::string& value) override;

		std::string getAttribute(const std::string& name) noexcept override;
		AttributeMap getAttributes() const noexcept override;
		HElement appendChild(const std::string& name) noexcept override;

		ElementCollection getChildElements() const noexcept override;


	private:
		Element(tinyxml2::XMLElement* node);
		std::shared_ptr<tinyxml2::XMLDocument> myXMLDocument;
		tinyxml2::XMLElement* myElement;
	};
}
