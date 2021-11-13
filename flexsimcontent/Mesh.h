#pragma once

#include "BasicClasses.h"
#include "SimpleDataType.h"

#include <vector>

#ifdef FLEXSIM_FGL
#include "glew.h"
#else
typedef int GLint;
typedef unsigned int GLuint;
typedef unsigned int GLenum;
#define GL_UNSIGNED_SHORT 0x1403
#endif

#ifdef FLEXSIM_ENGINE_COMPILE
	#ifdef FLEXSIM_TREEWIN
		#include "vft.h"
	#endif
	#include "nowide/fstream.hpp"
	#include "GLM.h"
#endif

#if __has_include("3rdParty/jsoncpp/json/json.h")
	#include "3rdParty/jsoncpp/json/json.h"
#else
namespace Json {
	class Value;
}
#endif

namespace FlexSim {



/// <summary>	A class encapsulating data and functionality for drawing geometry in OpenGL.</summary>
/// <remarks>	The mesh class, and its accompanying mesh api in flexscript, replace the old immediate-mode
/// 			OpenGL rendering using glBegin() and glEnd(). To use the mesh class you initialize the mesh
/// 			with Mesh::init() (or the mesh() command in flexscript), defining what data you are
/// 			going to provide with each vertex, such as normals, texture coordinates, etc. Then you fill 
/// 			the mesh with vertex data, either by adding vertices one at a time with 
/// 			Mesh::addVertex() and Mesh::setVertexAttrib() (using the meshaddvertex() and meshsetvertexattrib()
/// 			commands in flexscript), or by copying a full set of vertex data in
/// 			with Mesh::defineVertexAttribs() </remarks>
class Mesh : public SimpleDataType
{
public:
	Mesh()
	{
		holder = 0;
		// initialize the per mesh color attribs' alpha to 1
		perMeshAmbient[3] = perMeshDiffuse[3] = perMeshSpecular[3] = perMeshEmissive[3] = 1.0f;
	}
	~Mesh() {cleanup(true);}
	engine_export Mesh(const Mesh& other);

protected:
	Mesh(int flags)
	{
		this->flags = flags;
		holder = 0;
		// initialize the per mesh color attribs' alpha to 1
		perMeshAmbient[3] = perMeshDiffuse[3] = perMeshSpecular[3] = perMeshEmissive[3] = 1.0f;
	}
	// -15 stored using a single precision bias of 127
	static const unsigned int  HALF_FLOAT_MIN_BIASED_EXP_AS_SINGLE_FP_EXP = 0x38000000;
	// max exponent value in single precision that will be converted
	// to Inf or Nan when stored as a half-float
	static const unsigned int  HALF_FLOAT_MAX_BIASED_EXP_AS_SINGLE_FP_EXP = 0x47800000;
	// 255 is the max exponent biased value
	static const unsigned int  FLOAT_MAX_BIASED_EXP = (0xFF << 23);
	static const unsigned int  HALF_FLOAT_MAX_BIASED_EXP = (0x1F << 10);
	typedef unsigned short    hfloat;
	static hfloat convertFloatToHFloat(float *f);
	static float convertHFloatToFloat(hfloat hf);

	typedef void (*CopyCallback)(void* copyPoint, float* inVerts, int componentsPerVertex, int numVerts, int vertByteStride);
	static void copyHFloatAttribs(void* copyPoint, float* inVerts, int componentsPerVertex, int numVerts, int vertByteStride);
	static void copyFloatAttribs(void* copyPoint, float* inVerts, int componentsPerVertex, int numVerts, int vertByteStride);
	static void copyUnsignedByteAttribsStraight(void* copyTo, float* inVerts, int componentsPerVert, int numVerts, int vertByteStride);
	static void copyUnsignedByteAttribsNormalized(void* copyTo, float* inVerts, int componentsPerVert, int numVerts, int vertByteStride);
	static void copySignedByteAttribsStraight(void* copyTo, float* inVerts, int componentsPerVert, int numVerts, int vertByteStride);
	static void copySignedByteAttribsNormalized(void* copyTo, float* inVerts, int componentsPerVert, int numVerts, int vertByteStride);
	static void copyColorAttribs(void* copyTo, float* inVerts, int componentsPerVert, int numVerts, int vertByteStride);
	static void copyUnsignedShortAttribsStraight(void* copyTo, float* inVerts, int componentsPerVert, int numVerts, int vertByteStride);
	static void copyUnsignedShortAttribsNormalized(void* copyTo, float* inVerts, int componentsPerVert, int numVerts, int vertByteStride);
	static void copySignedShortAttribsStraight(void* copyTo, float* inVerts, int componentsPerVert, int numVerts, int vertByteStride);
	static void copySignedShortAttribsNormalized(void* copyTo, float* inVerts, int componentsPerVert, int numVerts, int vertByteStride);
	
	struct AttribCopier {
		int componentsPerVertex;
		int bytesPerComponent;
		CopyCallback copier;
		void* copyPoint;
	};
	struct CustomVertexAttrib {
		std::string name;
		GLint attribLocation;
		unsigned char attribOffset;
		int componentsPerVertex;
		GLenum type;
		bool isNormalized;
		void bind(TreeNode* x);
		void bindVertexAttribArray(char* basePoint, int totalByteStride);
		void unbindVertexAttribArray();
	};
	int getComponentsPerVertex(int attribId);
	void fillVertexCopier(const CustomVertexAttrib& attrib, AttribCopier& copier);
	AttribCopier getVertexCopier(int attribId);
	AttribCopier getMeshCopier(int attribId);

	typedef void (*ReadCallback)(void* readPoint, float* outVert);
	ReadCallback getReader(unsigned int attribId);
	static void readColorVertex(void* readPoint, float* outVert);
	static void readFloatVertex(void* readPoint, float* outVert);
	virtual const char* getClassFactory() {return "Mesh";}

	size_t cacheId = 0;

	std::vector<CustomVertexAttrib*>* customVertexAttribs = nullptr;

	GLint lastShaderProgram = 0;
	void cleanupCustomVertexAttribs();

#ifdef FLEXSIM_ENGINE_COMPILE
public:
	typedef void (Mesh::*_drawCallback)(int drawMode, int vertOffset, int vertCount, int vertStride);
	static _drawCallback drawCallback;
	static std::ofstream renderFile;

	static int currentRenderMode;
	static void startCustomRenderMode(int renderMode, const char* filePath = 0);
	static void endCustomRenderMode();

	struct CachedMesh {
		Mesh* theMesh = nullptr;
		IndexedMesh* drawMeshInstanced = nullptr;
		glm::mat4 shapeModelToWorldMatrix;
		int drawMode = 0;
		int offset = 0;
		int count = 0;
		int imageIndex = 0;
		glm::vec4 color;
	};
	static std::vector<std::unique_ptr<CachedMesh>> customMeshSceneCache;
	static glm::mat4 eyeToWorldTransformation;
	static void exportCachedMeshes(Json::Value& value);

protected:
	void drawRenderMode(int drawMode, int vertOffset, int vertCount, int vertStride);

	void drawPOVExportMode(int drawMode, int vertOffset, int vertCount, int vertStride);
	void printPOVMeshData();
	void printPOVVertexData();

	void drawCyclesExportMode(int drawMode, int vertOffset, int vertCount, int vertStride);
	void printCyclesVertexData(int drawMode);

	void drawOptiXMode(int drawMode, int vertOffset, int vertCount, int vertStride);

	void drawCacheMode(int drawMode, int vertOffset, int vertCount, int vertStride);

	void assertBufferSize(unsigned char*& buffer, unsigned int& maxSize, unsigned int sizeNeeded, int vertByteStride, bool growExactly);
#endif

public:
	/// <summary>	The per mesh flags. See Mesh::init()</summary>
	unsigned int perMeshAttribs = 0;
	/// <summary>	The per vertex flags. See Mesh::init()</summary>
	unsigned int perVertexAttribs = 0;
	/// <summary>	Miscellaneous flags. See Mesh::init()</summary>
	unsigned int flags = 0;

	// The number of vertices in this mesh
	int numVerts = 0;

protected:
	/// <summary>	The originally saved perVertexAttribs</summary>
	unsigned int originalPerVertexAttribs = 0;
// stock vertex attributes are id'd with the high-order 2 bytes
#define MESH_STOCK_ATTRIB_MASK 0xffff0000
// custom vertex attributes are id'd with the low-order 2 bytes (to-do: implement custom vertex attribs once we get to that point)
#define MESH_CUSTOM_ATTRIB_MASK 0x0000ffff

#define MESH_POSITION               0x0
#define MESH_TEX_COORD1             0x0010000
#define MESH_TEX_COORD2             0x0020000
#define MESH_TEX_COORD3             0x0040000
#define MESH_NORMAL                 0x0080000
#define MESH_AMBIENT                0x0100000
#define MESH_DIFFUSE                0x0200000
#define MESH_DIFFUSE4               0x0400000
#define MESH_AMBIENT_AND_DIFFUSE    0x0800000
#define MESH_AMBIENT_AND_DIFFUSE4   0x1000000
// the following are per-mesh-only attributes
#define MESH_SPECULAR               0x2000000
#define MESH_SHININESS              0x4000000
#define MESH_EMISSION               0x8000000

#define MESH_PER_VERTEX_COLOR_ATTRIBS (MESH_DIFFUSE | MESH_DIFFUSE4 | MESH_AMBIENT_AND_DIFFUSE | MESH_AMBIENT_AND_DIFFUSE4)

#define MESH_COLOR_ATTRIBS (MESH_AMBIENT | MESH_DIFFUSE | MESH_DIFFUSE4 | MESH_AMBIENT_AND_DIFFUSE \
				| MESH_AMBIENT_AND_DIFFUSE4 | MESH_SPECULAR | MESH_SHININESS | MESH_EMISSION)

#define MESH_STATIC_DRAW 0x1
#define MESH_DYNAMIC_DRAW 0x2
#define MESH_INDEXED 0x4
#define MESH_FORCE_CLEANUP 0x8
#define MESH_NO_POSITION 0x10
#define MESH_FORCE_CLEANUP_FULL 0x20

// MESH_IN_MEMORY: (not implemented, just an idea at this point) means the mesh is not bound to the tree, 
// which means it can delete its buffers once copied into the open gl objects
#define MESH_IN_MEMORY 0x40

	/// <summary>	The number of bytes contained in one vertex (vertex data is
	/// 			interleaved) </summary>
	int vertByteStride = 0;

	/// <summary>	The number of floats from the start of a vertex that represents
	/// 			the start of the texture coordinate. </summary>
	unsigned char texCoordOffset;
	/// <summary>	The number of bytes from the start of a vertex that represents the
	/// 			start of the normal. </summary>
	unsigned char normalOffset;
	/// <summary>	The number of bytes from the start of a vertex that represents the start of the
	/// 			diffuse color. </summary>
	unsigned char colorOffset;

	static const int STATIC_BLOCK_SIZE = 92;
	union {
		struct {
			float perMeshTexCoord[3];
			float perMeshNormal[3];
			float perMeshAmbient[4];
			float perMeshDiffuse[4];
			float perMeshSpecular[4];
			float perMeshEmissive[4];
			float perMeshShininess[1];
		};
		unsigned char allStatics[STATIC_BLOCK_SIZE];
	};

	/// <summary>	The OpenGL id of the vertex buffer object. </summary>
	unsigned int vbo = 0;
	/// <summary>	The OpenGL id of the vertex array object. </summary>
	unsigned int vao = 0;
	/// <summary>	The maximum allocated space for the vertex buffer. </summary>
	unsigned int maxBufferSize = 0;
	/// <summary>	The buffer of vertex data. </summary>
	unsigned char* vertBuffer = nullptr;
	/// <summary>	true if the vertex/mesh data has has been changed since the last draw. 
	/// 			The mesh will apply the new data to the VBO on the next draw() call. 
	/// 			Do not set this to true directly; use setDirty(). </summary>
	bool isDirty = true;
	bool isDirtyOptiX;

	static unsigned int setColorMaterial;

	/// <summary>	Prepares the mesh for drawing </summary>
	/// <remarks>	Called from one of two places. 1. if vertex array objects are
	/// 			available, then it will
	/// 			   be called just after defining the vertex buffers, meaning just once until the
	/// 			   vertices are redefined again.
	/// 			2. if vertex array objects aren't available, then it will
	/// 			   be called as part of each draw
	/// 			prepareDraw() essentially enables all the client states for what is needed, and
	/// 			binds to the proper buffers. </remarks>
	/// <param name="stride">	The stride.</param>
	void prepareDraw(unsigned int& vao, int offset = 0, int stride = 0);
	void applyAttribs();
	void resetAttribs();
	bool checkForShaderChange();
	void cleanupDraw(unsigned int& vao);
	/// <summary>	defineGLObjects(): defines the vertex array object. Call this one, and it will
	/// 			call defineVBO. </summary>
	/// <remarks>	 </remarks>
	void defineGLObjects();
	/// <summary>	defineVBO(): defines the vertex buffer object. IndexedMesh will override this to
	/// 			additionally define the index buffer. </summary>
	/// <remarks>	. </remarks>
	void defineVBO();

public:
	engine_export virtual void bind();
	engine_export void cleanup(bool deleteGLObjects = false);

	/// <summary>	Initializes the mesh with the number of vertices needed and various flags. </summary>
	/// <remarks>	Usually you are going to fill a vector or vectors with your vertex data, then
	/// 			once you've filled them, you initialize the mesh with the desired number of vertices,
	/// 			and then copy them in with Mesh::defineVertexAttribs. You can alternatively initialize with
	/// 			0 vertices and add individual vertices with Mesh::addVertex() and 
	/// 			Mesh::setVertexAttrib()</remarks>
	/// <param name="numVerts">		   	The number of vertices in the mesh. </param>
	/// <param name="perVertexAttribs">	(Optional) The per vertex attributes, defining what data will be stored 
	/// 								with each vertex. 
	///									If you define perVertex flags you will need to provide the associated vertex data through 
	///									Mesh::defineVertexAttribs() or Mesh::setVertexAttrib(). Should be a 
	///									bitwise or (|) of zero or more of the following:
	/// 								- MESH_TEX_COORD2 - signifies that you will provide per-vertex texture coordinate data
	///									- MESH_NORMAL - signifies that you will provide per-vertex normal data
	///									- MESH_AMBIENT_AND_DIFFUSE - signifies that you will provide per-vertex 3-component color data. Both ambient and diffuse colors will track the vertex color data.
	///									- MESH_AMBIENT_AND_DIFFUSE4 - signifies that you will provide per-vertex 4-component color data. Both ambient and diffuse colors will track the vertex color data.
	///									- MESH_DIFFUSE - signifies that you will provide per-vertex 3-component color data
	///									- MESH_DIFFUSE4 - signifies that you will provide per-vertex 4-component color data
	/// 								</param>
	/// <param name="flags">		   	(Optional) Miscellaneous flags. </param>
	engine_export virtual void init(unsigned int numVerts, unsigned int perVertexAttribs = 0, unsigned int flags = 0);

	int initVertexAttrib(CustomVertexAttrib& attrib, const char* name, int componentsPerVertex, GLenum type, bool isNormalized);
	/// <summary>	Adds a custom vertex attribute data to a mesh. </summary>
	/// <remarks>	This should be used immediately after calling init() if you want to add custom vertex attributes in 
	///				addition to the default set defined by perVertexFlags. </remarks>
	/// <returns>	The index of the added vertex attrib. </returns>
	/// <param name="name">	Specifies the name of the vertex attribute defined in the shader.</param>
	/// <param name="componentsPerVertex">	Specifies the number of components per generic vertex attribute. Must be 1, 2, 3, or 4.</param>
	/// <param name="type">	Specifies the data type of each component in the array. Symbolic constants GL_BYTE, GL_UNSIGNED_BYTE, GL_SHORT, GL_UNSIGNED_SHORT, GL_FIXED, or GL_FLOAT are accepted.</param>
	/// <param name="isNormalized">	Specifies whether the value should be normalized when converting to a float in the shader. This is ignored if 
	/// 							type is GL_FLOAT. If true, then you should pass normalized float values in when defining vertex data.</param>
	engine_export unsigned int addCustomVertexAttrib(const char* name, int componentsPerVertex, GLenum type, bool isNormalized);

	/// <summary>	Define vertex attributes. </summary>
	/// <remarks>	Copies the given vertex data into the mesh's internal OpenGL-optimized format. This method should be used if you
	/// 			already have an array of data, and have therefore initialized the mesh (Mesh::init()) with a positive number of 
	/// 			vertices.</remarks>
	/// <param name="attribId">	Identifier for the attribute. Should be one of the following:
	/// 							- MESH_POSITION - the vertex position data
	/// 							- MESH_TEX_COORD2 - the vertex texture coordinate data
	///								- MESH_NORMAL - the vertex normal data
	///								- MESH_AMBIENT_AND_DIFFUSE - the vertex 3-component color data
	///								- MESH_AMBIENT_AND_DIFFUSE4 - the vertex 4-component color data  
	///								- MESH_DIFFUSE - the vertex 3-component color data
	///								- MESH_DIFFUSE4 - the vertex 4-component color data</param>
	/// <param name="verts">   	[in] The vertex data. </param>
	engine_export void defineVertexAttribs(unsigned int attribId, float* verts);

	engine_export void clear();
	void setDirty() { isDirty = isDirtyOptiX = true; }

	/// <summary>	Retrieve vertex attributes. </summary>
	/// <remarks>	Copies the vertex data from the mesh's internal OpenGL-optimized format.
	/// 			This method should be used if you want to get an array of vertex data.</remarks>
	/// <param name="attribId">	Identifier for the attribute. Should be one of the following:
	/// 							- MESH_POSITION - the vertex position data
	/// 							- MESH_TEX_COORD2 - the vertex texture coordinate data
	///								- MESH_NORMAL - the vertex normal data
	///								- MESH_AMBIENT_AND_DIFFUSE - the vertex 3-component color data
	///								- MESH_AMBIENT_AND_DIFFUSE4 - the vertex 4-component color data  
	///								- MESH_DIFFUSE - the vertex 3-component color data
	///								- MESH_DIFFUSE4 - the vertex 4-component color data</param>
	/// <param name="outBuffer">   	[in] The output buffer to write the data. </param>
	void getVertexAttribs(unsigned int attribId, float* outBuffer);
	void getCustomVertexAttribs(const char* customAttribName, float* outBuffer);

	/// <summary>	Retrieve mesh attributes. </summary>
	/// <remarks>	Copies the mesh data from the mesh's internal OpenGL-optimized format.
	/// 			This method should be used if you want to get per-mesh attribute data.</remarks>
	/// <param name="attribId">	Identifier for the attribute. Should be one of the following:
	///								- MESH_NORMAL - the mesh normal data
	///								- MESH_DIFFUSE - the 3-component color data
	///								- MESH_DIFFUSE4 - the 4-component color data
	///								- MESH_AMBIENT - the ambient data
	///								- MESH_SPECULAR - the specular data
	///								- MESH_EMISSION - the emission data
	///								- MESH_SHININESS - the shininess data</param>
	/// <param name="outBuffer">   	[in] The output buffer to write the data. </param>
	void getMeshAttrib(unsigned int attribId, float* outBuffer);

	/// <summary>	Retrieve vertex indices. </summary>
	/// <remarks>	For a non-indexed mesh, this returns a buffer of 0, 1, 2, 3, etc.
	/// 			For an indexed mesh, this returns the buffer of indices.</remarks>
	engine_export virtual void getVertexIndices(int* outBuffer);

	/// <summary>	Adds a vertex. </summary>
	/// <remarks>	Should be used when you initialize the mesh with 0 vertices, and then add vertex data as you go. </remarks>
	/// <returns>	The index of the added vertex, for use in Mesh::setVertexAttrib(). </returns>
	engine_export int addVertex();

	/// <summary>	Sets the vertex attribute data for a single vertex. </summary>
	/// <remarks>	Should be used when you initialize the mesh with 0 vertices, and then add vertex data as you go with addVertex(). </remarks>
	/// <param name="vertIndex">	Zero-based index of the vertex. Should be the index returned by addVertex() </param>
	/// <param name="attribId"> 	Identifier for the attribute. See Mesh::defineVertexAttribs().</param>
	/// <param name="vert">			[in] A pointer to the vertex data. </param>
	engine_export unsigned int setVertexAttrib(unsigned int vertIndex, unsigned int attribId, float* vert);

	/// <summary>	Define data to be applied once per draw, i.e. just before drawing the mesh each time.</summary>
	/// <remarks>	Anthony.johnson, 8/15/2013. </remarks>
	/// <param name="attribId">	Identifier for the attribute. Should be one of the following:
	///									- MESH_NORMAL - the 3-component normal for the mesh
	/// 								- MESH_AMBIENT_AND_DIFFUSE - the 3-component color for the mesh
	/// 								- MESH_AMBIENT_AND_DIFFUSE4 - the 4-component color for the mesh 
	/// 								- MESH_SPECULAR - the 3-component specular color for the mesh  
	/// 								- MESH_EMISSION - the 3-component emissive color for the mesh  
	/// 								- MESH_SHININESS - the 1-component shininess value for the mesh
	/// 					</param>
	/// <param name="data">	   	[in] A pointer to the data that defines the attribute. If 0, the mesh will turn that per-mesh flag off, 
	/// 						meaning it will take whatever the previous OpenGL state was. </param>
	engine_export void setMeshAttrib(unsigned int attribId, float* data);

	/// <summary>	Draws the mesh. </summary>
	/// <remarks>	 </remarks>
	/// <param name="drawMode">  	The draw mode. A standard OpenGL primitive type such as GL_QUADS, GL_TRIANGLES, GL_LINES, GL_LINE_STRIP, GL_TRIANGLE_STRIP, etc.</param>
	/// <param name="vertOffset">	(Optional) The vertex offset to start at. If not provided, the whole mesh will be drawn.</param>
	/// <param name="vertCount"> 	(Optional) The number of vertices to dray. </param>
	/// <param name="vertStride">	(Optional) The vertex stride, i.e if 2, it will read every other vertex. </param>
	engine_export virtual void draw(int drawMode, int vertOffset = 0, int vertCount = 0, int vertStride = 0);
	engine_export float* getVertexAttrib(unsigned int vertIndex, unsigned int attribId);

	engine_export Mesh& merge(const Mesh& other);
	engine_export void scaleToBounds(const Vec3f& min, const Vec3f& max);
	engine_export void getBounds(Vec3f& min, Vec3f& max) const;

	engine_export virtual void exportMeshJson(Json::Value& value);
protected:
	template <class MeshType = Mesh>
	class TemplatedAutoRebuildingMesh
	{
	public:
		TemplatedAutoRebuildingMesh(std::function<void(MeshType&)> rebuildCallback)
			: rebuild(rebuildCallback) {}
		void setDirty() { isDirty = true; }
	private:
		bool isDirty = true;
		std::function<void(MeshType&)> rebuild;
	public:
		MeshType mesh;
		void checkRebuild() {
			while (isDirty) {
				isDirty = false;
				rebuild(mesh);
			}
		}
		void draw(int drawMode, int vertOffset, int vertCount = 0, int vertStride = 0)
		{
			checkRebuild();
			mesh.draw(drawMode, vertOffset, vertCount, vertStride);
		}
		void draw(int drawMode)
		{
			checkRebuild();
			mesh.draw(drawMode);
		}
	};

public:
	typedef TemplatedAutoRebuildingMesh<Mesh> AutoRebuildingMesh;
	virtual IndexedMesh* toIndexedMesh() { return nullptr; }
	virtual InstancedMesh* toInstancedMesh() { return nullptr; }
	virtual TextMesh* toTextMesh() { return nullptr; }
private:

	struct PickRange {
		int drawMode;
		int startIndex;
		int numVerts;
	};
#ifndef FLEXSIM_TREEWIN
	using MappableVFT = int;
#endif
	typedef std::unordered_map<MappableVFT, PickRange> PickRangeMap;
	static PickRangeMap::iterator curPickRange;
	std::shared_ptr<PickRangeMap> pickRanges;
	engine_export PickRangeMap::iterator addPickRangePrivate(int drawMode, int startIndex, int numVerts, treenode focus, int what, treenode secondaryFocus, int detectdrag);
public:
	engine_export void addPickRange(int drawMode, int startIndex, int numVerts, treenode focus, int what, treenode secondaryFocus, int detectdrag)
	{
		addPickRangePrivate(drawMode, startIndex, numVerts, focus, what, secondaryFocus, detectdrag);
	}
	engine_export void beginPickRange(int drawMode, treenode focus, int what, treenode secondaryFocus, int detectdrag);
	engine_export void endPickRange();
	engine_export void drawPickRanges(treenode view);
	engine_export PickRange findPickRange(treenode focus, int what, treenode secondaryFocus);


	/// <summary>Override the mesh's default set of vertex attributes</summary>
	  /// <remarks>This is used if you want to temporarily change the set of enabled per-vertex attributes that 
	  /// are used when drawing the mesh. The most useful example is if you want to draw the mesh in a "highlighted" 
	  /// mode by overriding the color vertex data with a single color you define with fglColor(). To do this,  
	  /// call mesh.overrideAttribs(MESH_POSITION), meaning in subsequent draw() calls, you want it to only use the 
	  /// MESH_POSITION vertex data, not any color vertex data, etc. so you can call fglColor() to set a color for the entire 
	  /// mesh.</remarks>
	  /// <param name="perVertexAttribs">[in] a bit mask defining the new set of vertex attributes to use. This should 
	  /// define fewer attributes than the set of vertex attributes stored in the mesh.</param>
	engine_export void overrideAttribs(unsigned int perVertexAttribs);

	/// <summary>Revert to the mesh's default set of vertex attributes</summary>
	  /// <remarks>Call this after calling overrideAttribs(), to reset the mesh back to its defaults.</remarks>
	engine_export void revertAttribs();
};

class IndexedMesh : public Mesh
{
	friend class InstancedMesh;
	friend class IndexedMesh;
public:
	IndexedMesh() : Mesh(MESH_INDEXED), numIndices(0), maxNumIndices(0), intIndexBuffer(0), indexVBO(0), elementSize(sizeof(unsigned short)), storageType(GL_UNSIGNED_SHORT){}
	engine_export IndexedMesh(const Mesh& other);
	~IndexedMesh()  {cleanupIndexBuffer(true);}
	engine_export IndexedMesh(const IndexedMesh& other);

	virtual const char* getClassFactory() override {return "IndexedMesh";}
	engine_export virtual void bind() override;

	virtual void init(unsigned int numVerts, unsigned int perVertexAttribs = 0, unsigned int flags = 0) override
	{
		Mesh::init(numVerts, perVertexAttribs, flags); 
		numIndices = 0;
	}

	/// <summary>	Define the index buffer for an indexed mesh. </summary>
	/// <remarks>	 </remarks>
	/// <param name="num">   	Number of indices in the buffer. </param>
	/// <param name="buffer">	[in] The index buffer. </param>
	engine_export void defineIndexBuffer(int num, unsigned int * buffer);
	engine_export void defineIndexBuffer(int num, int* buffer) { defineIndexBuffer(num, (unsigned int*)buffer); }


	engine_export void clear();

	/// <summary>	Retrieve vertex indices. </summary>
	/// <remarks>	For a non-indexed mesh, this returns a buffer of 0, 1, 2, 3, etc.
	/// 			For an indexed mesh, this returns the buffer of indices.</remarks>
	engine_export virtual void getVertexIndices(int* outBuffer) override;

	/// <summary>	Adds an index to the index buffer. </summary>
	/// <remarks>	 If you want to add indices as you go, use this method. </remarks>
	/// <param name="index">	The vertex index, returned by addVertex()</param>
	/// <returns>	The index of the vertex index within the index buffer. </returns>
	engine_export unsigned int addIndex(unsigned int index);

	/// <summary>	Draws the indexed mesh. </summary>
	/// <remarks>	Anthony.johnson, 8/15/2013. </remarks>
	/// <param name="drawMode">	The draw mode. </param>
	/// <param name="vertOffset">	(Optional) The vertex offset to start at. If not provided, the whole mesh will be drawn.</param>
	/// <param name="vertCount"> 	(Optional) The number of vertices to dray. </param>
	/// <param name="vertStride">	(Optional) The vertex stride, i.e if 2, it will read every other vertex. </param>
	engine_export virtual void draw(int drawMode, int vertOffset = 0, int vertCount = 0, int vertStride = 0) override;
	engine_export void cleanupIndexBuffer(bool isDestructor = false);
	engine_export unsigned int vertexForIndex(unsigned int index);

	unsigned int numIndices;

protected:
	/// <summary>	The maximum number of indices possible, given the current allocated buffer size </summary>
	/// <remarks>	Anthony.johnson, 8/15/2013. </remarks>
	unsigned int maxNumIndices;
	union {
		unsigned int * intIndexBuffer;
		unsigned short * shortIndexBuffer;
	};
	unsigned int indexVBO;
	unsigned int elementSize;
	unsigned int storageType;
	void defineVBO();
	void prepareDraw(unsigned int& vao);
	void cleanupDraw(unsigned int& vao);
	/// <summary>	defineGLObjects(): defines the vertex array object. Call this one, and it will
	/// 			call defineVBO. </summary>
	/// <remarks>	 </remarks>
	void defineGLObjects();

	template <class DestType, class SrcType>
	void copyBuffer(int num, DestType* to, SrcType* from, int indexOffset = 0) {
		for (int i = 0; i < num; i++)
			to[i] = (DestType)from[i] + indexOffset;
	}

	void assertStorageType(unsigned int type);
	void assertIndexBufferSize(int numIndices);

#ifdef FLEXSIM_ENGINE_COMPILE
public:
	typedef void (IndexedMesh::*_drawCallback)(int drawMode, int vertOffset, int vertCount, int vertStride);
	static _drawCallback indexedDrawCallback;
	void indexedDrawRenderMode(int drawMode, int vertOffset, int vertCount, int vertStride);
	void indexedDrawPOVExportMode(int drawMode, int vertOffset, int vertCount, int vertStride);
	void indexedDrawCyclesExportMode(int drawMode, int vertOffset, int vertCount, int vertStride);
	void indexedDrawOptiXMode(int drawMode, int vertOffset, int vertCount, int vertStride);
	void indexedDrawCacheMode(int drawMode, int vertOffset, int vertCount, int vertStride);
#endif
public:
	engine_export IndexedMesh& merge(const IndexedMesh& other);
	engine_export virtual void exportMeshJson(Json::Value& value) override;

	typedef Mesh::TemplatedAutoRebuildingMesh<IndexedMesh> AutoRebuildingMesh;
	IndexedMesh* toIndexedMesh() override { return this; }
};

class InstancedMesh : public IndexedMesh
{
public:
	InstancedMesh() : IndexedMesh(), instancedVertBuffer(0), instancedAttribs(0), maxInstancedBufferSize(0), instancedVertByteStride(0) {}
	~InstancedMesh() { cleanupInstancedVerts(); }
	engine_export InstancedMesh(const InstancedMesh& other);
	InstancedMesh(const IndexedMesh& other) : IndexedMesh(other), instancedVertBuffer(0), instancedAttribs(0), maxInstancedBufferSize(0), instancedVertByteStride(0) {}

	virtual void init(unsigned int numVerts, unsigned int perVertexAttribs = 0, unsigned int flags = 0) override
	{
		cleanupInstancedVerts();
		IndexedMesh::init(numVerts, perVertexAttribs, flags);
		numInstancedVerts = 0;
	}
	void clear() { __super::clear(); numInstancedVerts = 0; }

protected:
	struct InstancedVertexAttrib : public Mesh::CustomVertexAttrib {
		GLuint attribDivisor;
		void bind(TreeNode* x);
		void bindVertexAttribArray(char* basePoint, int totalByteStride);
	};
	int lastDrawnIndexVBO = -1;
	std::vector <InstancedVertexAttrib> * instancedAttribs;
	unsigned char* instancedVertBuffer;
	int instancedVertByteStride;
	unsigned int maxInstancedBufferSize;

	/// <summary>	Cleans up the instanced attributes. </summary>
	/// <remarks>	</remarks>
	engine_export void cleanupInstancedVerts();
	bool checkForShaderChange();
	void defineGLObjects(IndexedMesh* mesh);
	void defineVBO();
	void prepareDraw(IndexedMesh* mesh);
	void cleanupDraw(IndexedMesh* mesh);
public:
	GLuint instanceVBO = 0;
	int numInstancedVerts;
	/// <summary>	Binds the mesh. </summary>
	/// <remarks>	</remarks>
	engine_export virtual void bind() override;

	/// <summary>	Adds an instanced vertex attribute to the mesh. </summary>
	/// <remarks>	All instanced vertex attributes should be added before 
	/// 			any instanced vertex data is actually defined.</remarks>
	/// <param name="name">				  	Specifies the name of the vertex attribute defined in the
	/// 									shader. </param>
	/// <param name="componentsPerVertex">	Specifies the number of components per generic vertex
	/// 									attribute. Must be 1, 2, 3, or 4. </param>
	/// <param name="type">				  	Specifies the data type of each component in the array.
	/// 									Symbolic constants GL_BYTE, GL_UNSIGNED_BYTE, GL_SHORT,
	/// 									GL_UNSIGNED_SHORT, GL_FIXED, or GL_FLOAT are accepted. </param>
	/// <param name="attribDivisor">	  	The attribute divisor. For more information, see OpenGL documentation
	/// 									for glVertexAttribDivisor(). Usually this will be 1, meaning the
	/// 									vertex attribute will advance once for each instance of vertices in
	/// 									the mesh. </param>
	/// <returns>	The index of the added instanced vertex attrib. </returns>
	engine_export unsigned int addInstancedVertexAttrib(const char* name, int componentsPerVertex, GLenum type, GLuint attribDivisor, bool isNormalized);

	void getInstancedVertexAttribs(const char* name, float* outBuffer);

	engine_export unsigned int addInstancedVertex();
	engine_export void setInstancedVertexAttrib(unsigned int vertIndex, unsigned int attribId, float* data);
	engine_export void defineInstancedVertexAttribs(unsigned int numVerts, unsigned int attribId, float* data);
	engine_export void instancedDrawRenderMode(int drawMode, IndexedMesh* mesh);
#ifdef FLEXSIM_ENGINE_COMPILE
public:
	typedef void (InstancedMesh::*_drawCallback)(int drawMode, IndexedMesh* mesh);
	static _drawCallback instancedDrawCallback;
	void instancedDrawOptiXMode(int drawMode, IndexedMesh* mesh);
	void instancedDrawCacheMode(int drawMode, IndexedMesh* mesh);
#endif
public:
	engine_export void draw(int drawMode) { draw(drawMode, this); }
	engine_export void draw(int drawMode, IndexedMesh* mesh);

	engine_export virtual void exportMeshJson(Json::Value& value) override;

	typedef Mesh::TemplatedAutoRebuildingMesh<InstancedMesh> AutoRebuildingMesh;
	InstancedMesh* toInstancedMesh() override { return this; }
};


#define MESH_PER_VERTEX_ATTRIBS 1
#define MESH_PER_MESH_ATTRIBS 2
#define MESH_FLAGS 3
#define MESH_NR_VERTS 4
#define MESH_GET_INDEX 5

#define MESH_RENDER_MODE_POV 1
#define MESH_RENDER_MODE_CYCLES 2
#define MESH_RENDER_MODE_OPTIX 3
#define MESH_RENDER_MODE_CACHE 4

#ifdef FLEXSIM_ENGINE_COMPILE

visible void mesh(treenode meshnode, unsigned int perVertexAttribs, unsigned int flags);
visible int  meshaddvertex(treenode meshnode);
visible void meshaddcustomvertexattrib(treenode meshnode, const char* name, int componentsPerVertex, GLenum type, bool isNormalized);
void meshaddcustomvertexattrib_flexscript(treenode meshnode, const char* name, int componentsPerVertex, GLenum type, int isNormalized);
visible void meshsetvertexattrib(treenode meshnode, unsigned int vertIndex, unsigned int attribId, float p1, float p2=0, float p3=0, float p4=0);
void meshsetvertexattrib_flexscript(treenode meshnode, unsigned int vertIndex, unsigned int attribId, double p1, double p2, double p3, double p4);
visible void meshsetattrib(treenode meshnode, unsigned int attribId, float p1, float p2 = 0, float p3 = 0, float p4 = 0);
void meshsetattrib_flexscript(treenode meshnode, unsigned int attribId, double p1, double p2, double p3, double p4);
visible void meshdraw(treenode meshnode, int drawMode, int offset, int count, int stride = 0);
visible int meshaddindex(treenode meshnode, unsigned int index);
visible double meshinfo(treenode meshnode, unsigned int type, unsigned int index=0, unsigned int param=0);
#endif

}
