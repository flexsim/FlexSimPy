#pragma once

#include "ObjectDataType.h"
#include "Mesh.h"

#define LIGHT_TYPE_DIRECTIONAL 0
#define LIGHT_TYPE_POINT 1
#define LIGHT_TYPE_AREA 2

namespace FlexSim
{

class Light : public ObjectDataType
{
public:
	engine_export virtual void bindVariables() override;
	engine_export double onDraw(TreeNode* view);

	double enabled;
	double type;
	double range;
	double intensity;
	double castShadows;
	double radius; // used by point lights to generate soft rtx shadows
	double angle; // used by directional lights to generate soft rtx shadows

private:
	static bool meshesInitialized;
	static Mesh pointMesh;
	static Mesh gimbalMesh;
	static Mesh circleMesh;
	static Mesh rectangleMesh;
	static Mesh directionMesh;

	static void initializeMeshes();
};

}