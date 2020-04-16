#pragma once
#include <list>
#include <string>
#include "PlacedGraphic.h"
#include "DrawingInterfaces.h"

namespace Framework
{
	class Layer
	{
	private:
		using PlacedGraphicCollection = std::list<PlacedGraphic>;
		PlacedGraphicCollection graphics;
		std::string alias;

	public:
		using PlacedGraphicIterator = PlacedGraphicCollection::const_iterator;
		Layer() = delete;
		explicit Layer(std::string const& initialAlias);
		Layer(const Layer& other) = default;
		Layer(Layer&& other) = default;
		Layer& operator=(const Layer& other) = default;
		Layer& operator=(Layer&& other) = default;
		~Layer() = default;

		template<class C> void pushBack(C&& placedGraphic)
		{
			graphics.push_back(std::forward<C>(placedGraphic));
		}
		void remove(const PlacedGraphic& pg);

		PlacedGraphicIterator begin() const;
		PlacedGraphicIterator end() const;

		void draw(BitmapGraphics::HCanvas& canvas);

		PlacedGraphic const& getGraphic(const int& index);

		void setAlias(const std::string& referenceAlias);
		std::string const& getAlias() const;

		bool operator==(const Layer& rhs) const;
		bool operator!=(const Layer& rhs) const;
	};
}
