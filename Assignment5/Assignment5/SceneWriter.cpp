#include "SceneWriter.h"

namespace Framework
{
	Xml::HElement SceneWriter::writeScene(const Scene& scene)
	{
		Xml::HElement root(Xml::ElementFactory::createElement("Scene"));
		root->setAttribute("width", std::to_string(scene.getWidth()));
		root->setAttribute("height", std::to_string(scene.getHeight()));

		Scene::LayerIterator iLayer;
		for (iLayer = scene.begin(); iLayer != scene.end(); ++iLayer)
		{
			const Layer& layer = *iLayer;
			Xml::HElement layerElement(root->appendChild("Layer"));
			layerElement->setAttribute("alias", layer.getAlias());

			Layer::PlacedGraphicIterator iPlacedGraphic;
			for (iPlacedGraphic = layer.begin(); iPlacedGraphic != layer.end(); ++iPlacedGraphic)
			{
				const PlacedGraphic& placedGraphic = *iPlacedGraphic;
				Xml::HElement placedGraphicElement(layerElement->appendChild("PlacedGraphic"));
				const auto& placementPoint = placedGraphic.getPlacementPoint();
				placedGraphicElement->setAttribute("x", std::to_string(placementPoint.getX()));
				placedGraphicElement->setAttribute("y", std::to_string(placementPoint.getY()));

				Xml::HElement vectorGraphicElement(placedGraphicElement->appendChild("VectorGraphic"));
				const auto& vectorGraphic = placedGraphic.getGraphic();
				vectorGraphicElement->setAttribute("closed", Parse::boolToString(vectorGraphic.isClosed()));

				for (int i = 0; i < vectorGraphic.getPointCount(); ++i)
				{
					VG::Point p = vectorGraphic.getPoint(i);
					Xml::HElement pointElement(vectorGraphicElement->appendChild("Point"));
					pointElement->setAttribute("x", std::to_string(p.getX()));
					pointElement->setAttribute("y", std::to_string(p.getY()));
				}
			}

		}
		return root;
	}
}
