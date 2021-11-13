#pragma once

#include "ObjectDataType.h"

namespace FlexSim
{

class ColorPalette : public ObjectDataType
{
protected:
	TreeNode* colorNodes;
	double mode;

	// not bound
	typedef std::unordered_map<Variant, Color, Variant::Hash, Variant::KeyEqual> VarColorMap;
	typedef std::unordered_map<double, Color> NodeColorMap;
	typedef std::unordered_map<Variant, int, Variant::Hash, Variant::KeyEqual> VarRankMap;
	typedef std::unordered_map<double, int> NodeRankMap;

	bool mapsBuilt = false;
	VarColorMap varColorMap;
	NodeColorMap nodeColorMap;
	VarRankMap varRankMap;
	NodeRankMap nodeRankMap;
	std::vector<NodeRef> unusedColorNodes;
	std::map<double, Color> gradientMap;

	void buildMaps();
	
public:
	enum ColorMode {
		Default = 0,
		UseGradient = 1,
	};
	engine_export void setMode(double newMode);
	engine_export Color getColorForValue(const Variant& value);
	engine_export int getRankForValue(const Variant& value);

	engine_export TreeNode* addNewColor();
	engine_export TreeNode* addColor(const Color& color, const Variant& value = Variant());
	engine_export TreeNode* getColorNode(int rank);
	engine_export int size();
	__declspec(property(get = size)) int length;

	engine_export Color getColor(TreeNode* colorNode);
	engine_export Variant getValue(TreeNode* colorNode);
	engine_export int isUsed(TreeNode* colorNode);

	engine_export void refresh();
	
	engine_export void setValue(TreeNode* colorNode, const Variant& value);
	engine_export void clearValue(TreeNode* colorNode);
	engine_export void setColor(TreeNode* colorNode, const Color& color);
	engine_export void updateColor(TreeNode* colorNode);
	engine_export void remove(TreeNode* colorNode);

	engine_export virtual void bindVariables() override;
	engine_export static ColorPalette* getGlobal(const char* paletteName);
};

}