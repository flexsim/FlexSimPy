#pragma once

#include "DataTypes.h"
#include "Mesh.h"

#if defined FLEXSIM_FGL
#include "glew.h"
#else
#define GL_TRIANGLES 0x0004
#endif

struct FT_FaceRec_;
typedef struct FT_FaceRec_*  FT_Face;

namespace FlexSim {

class TextMesh : public IndexedMesh
{
	typedef VecGeneric<int, 2> Vec2i;
	class SharedGlyphTexture;
	struct CharacterTexCoords {
		CharacterTexCoords(SharedGlyphTexture* tex) : glyphTexture(tex) {}
		CharacterTexCoords() : glyphTexture(nullptr) {}
		SharedGlyphTexture* glyphTexture;
		int baselineY;
		/// <summary>	The location, in pixels, of the bottom left of the target character. </summary>
		Vec2i location;
		/// <summary>	The size, in pixels, of the target character. </summary>
		Vec2i size;
		/// <summary>	The advance, in pixels, of this character, i.e. the 
		/// 			distance to advance after rendering this character, before 
		/// 			rendering the next character. </summary>
		int advance;
		int left;
		engine_export Vec2f __getBottomLeft() const;
		__declspec(property(get = __getBottomLeft)) Vec2f bottomLeft;
		engine_export Vec2f __getBottomRight() const;
		__declspec(property(get = __getBottomRight)) Vec2f bottomRight;
		engine_export Vec2f __getTopRight() const;
		__declspec(property(get = __getTopRight)) Vec2f topRight;
		engine_export Vec2f __getTopLeft() const;
		__declspec(property(get = __getTopLeft)) Vec2f topLeft;
		engine_export Vec2f operator[](int index);
	};

	
	class SharedGlyphTexture {
	public:
		static const int defaultPixelSize = 48;
		engine_export static const char* defaultFontName;
	private:
		static int maxTexSize;
		int addMarkerX = 4;
		int addMarkerY = 4;
		GLuint texID = 0;
		bool isDirty = true;
		std::unique_ptr<unsigned char[]> texture;
		std::unordered_map<char32_t, CharacterTexCoords> coordMap;
		std::string fontName;
		int pixelSize = defaultPixelSize;
		void growTexture(int newWidth, int newHeight);
		FT_Face ftFace = nullptr;
		FT_Face unicodeFTFace = nullptr;
	public:
		void init();
		SharedGlyphTexture() : fontName(defaultFontName) {}
		SharedGlyphTexture(const char* fontName, int pixelSize) : fontName(fontName), pixelSize(pixelSize) {}
		~SharedGlyphTexture();
		/// <summary>	The char ascent, in pixels. This is the "ascender height" of the font.</summary>
		int charAscent = 0;
		/// <summary>	The width of the gl texture, in pixels. </summary>
		int width = 0;
		/// <summary>	The height of the gl texture, in pixels. </summary>
		int height = 0;

		/// <summary>	The baseline-to-baseline distance between lines. </summary>
		int lineHeight = 0;

		CharacterTexCoords getTexCoords(const char32_t character);
		void assertTexCoords(const char32_t character) { getTexCoords(character); }
		void bindTexture();
		float calculateTextWidth(const char* str, float charAscent = 0);
		float calculateTextWidth(const char32_t* str, const char32_t* end, float charAscent = 0);
	};
	typedef std::pair<std::string, int> MapKey;
	struct MapHash {
		size_t operator() (const MapKey& key) const { return std::hash<std::string>()(key.first) ^ std::hash<int>()(key.second); }
	};
	static std::unordered_map<MapKey, std::unique_ptr<SharedGlyphTexture>, MapHash> glyphTextures;

	int lastDrawGlyphTextureWidth;
	int lastDrawGlyphTextureHeight;
	static TextMesh* activeAddingTextMesh;
	void updateTexCoordsToGrownTexture();
	void checkUpdateTexCoordsToGrownTexture()
	{
		if (lastDrawGlyphTextureHeight != glyphTexture->height || lastDrawGlyphTextureWidth != glyphTexture->width)
			updateTexCoordsToGrownTexture();
	}
	int numCharacters;
	SharedGlyphTexture* glyphTexture = nullptr;
	engine_export static SharedGlyphTexture* assertGlyphTexture(int pixelSize, const char* fontName = SharedGlyphTexture::defaultFontName);

	int __getNumVerts() { return numCharacters * 4; }
	__declspec(property(get = __getNumVerts)) int numVerts;

	static char32_t* convertString(const char* str, char32_t*& end);
	static bool consumeSpace(const char32_t*& character, Vec3f& curCharPoint, Vec3f& curLineLeft, const Vec3f& rightUnit, float* totalWidth = nullptr);
	bool consumeNewLine(const char32_t*& character, Vec3f& curCharPoint, Vec3f& curLineLeft,
			const Vec3f& upLineHeight, const Vec3f& rightUnit);
	bool isWordBoundary(char32_t character);


public:
	TextMesh() { glyphTexture = assertGlyphTexture(SharedGlyphTexture::defaultPixelSize); }
	TextMesh(int pixelSize) { glyphTexture = assertGlyphTexture(pixelSize); }
	TextMesh(int pixelSize, const char* fontName) { glyphTexture = assertGlyphTexture(pixelSize, fontName); }
	enum Alignment : int {
		Left = 0,
		Right = 1,
		Center = 2,
		Top = 3, 
		Bottom = 4
	};
	struct DrawSettings {
		Alignment horAlign;
		Alignment vertAlign;
		bool wrap;
		bool scaleToFit;
		DrawSettings(Alignment horAlign, Alignment vertAlign, bool wrap, bool scaleToFit)
			: horAlign(horAlign), vertAlign(vertAlign), wrap(wrap), scaleToFit(scaleToFit) {}
	};
	engine_export void init(int perVertexAttribs);
	engine_export void clear();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Adds a raw text to be rendered. </summary>
	///
	/// <remarks>	Anthony Johnson, 9/17/2019. </remarks>
	///
	/// <param name="str">		  	The text to render. </param>
	/// <param name="baseline">   	The baseline. This is the 3D point to be the origin
	/// 							of the added text, positioned at the base line of the 
	/// 							rendering text. </param>
	/// <param name="charAdvance">	The character advance vector. This should be the same 
	/// 							magnitude as charAscent, orthogonal to that vector, 
	/// 							in the direction that the text advances (i.e. to the 
	/// 							"right").</param>
	/// <param name="charAscent"> 	The character ascent. This is the vector telling what 
	/// 							is "up" for rendering the text. The magnitude of the 
	/// 							vector corresponds with the font face's "ascent" metric,
	/// 							i.e. the distance from the base line to the maximum 
	/// 							rendered height of any character in the font.</param>
	/// <param name="color">	  	[in,out] (Optional) If non-null, the color to render the 
	/// 							text in. </param>
	//////////////////////////////////////////////////////////////////////////////////////////////
	engine_export void addText(const char* str, const Vec3f& baseline, const Vec3f& charAdvance, const Vec3f& charAscent, Vec4f* color = nullptr);
	engine_export void addText(const char32_t* start, const char32_t* end, const Vec3f& baseline, const Vec3f& charAdvance, const Vec3f& charAscent, Vec4f* color = nullptr, double maxWidth = FLT_MAX);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Adds a text to be rendered, additionally specifying a bounding box within 
	/// 			which the text should be rendered/clipped. </summary>
	///
	/// <remarks>	Anthony Johnson, 9/17/2019. </remarks>
	///
	/// <param name="str">		   	The text to be rendered. </param>
	/// <param name="bbBottomLeft">	The position representing the bottom left corner of 
	/// 							the bounding box. </param>
	/// <param name="bbSize">	   	The x and y size of the bounding box. </param>
	/// <param name="charAdvance"> 	The character advance vector. See the other 
	/// 							addText() overload above.</param>
	/// <param name="charAscent">  	The character ascent vector. See the addText() overload above. </param>
	/// <param name="settings">	   	Options for controlling how the text is rendered within 
	/// 							the bounding box. </param>
	/// <param name="color">	   	[in,out] (Optional) If non-null, the color to render the
	/// 							text in. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	engine_export void addText(const char* str, const Vec3f& bbBottomLeft, const Vec2f& bbSize, 
		const Vec3f& charAdvance, const Vec3f& charAscent, const DrawSettings& settings, Vec4f* color = nullptr);
	engine_export void addText(const char32_t* str, const char32_t* end, Vec3f bottomLeft, Vec2f bbSize, 
		Vec3f charAdvance, Vec3f charAscent, const DrawSettings& settings, Vec4f* color = nullptr);
	engine_export void bindTexture();
	engine_export void bindAndDraw() { bindTexture(); draw(GL_TRIANGLES); }
	virtual TextMesh* toTextMesh() override { return this; }

	// static overloads
	engine_export static float calculateTextWidth(const char* str, float charAscent, int pixelSize, const char* fontName = SharedGlyphTexture::defaultFontName)
	{
		return assertGlyphTexture(pixelSize, fontName)->calculateTextWidth(str, charAscent);
	}
	engine_export static float calculateTextWidth(const char32_t* str, const char32_t* end, float charAscent, int pixelSize, const char* fontName = SharedGlyphTexture::defaultFontName)
	{
		return assertGlyphTexture(pixelSize, fontName)->calculateTextWidth(str, end, charAscent);
	}


	// non-static overloads
	engine_export float calculateTextWidth(const char* str, float charAscent = 0)
	{
		return glyphTexture->calculateTextWidth(str, charAscent);
	}
	engine_export float calculateTextWidth(const char32_t* str, const char32_t* end, float charAscent = 0)
	{
		return glyphTexture->calculateTextWidth(str, end, charAscent);
	}

	int __getCharAscent() { return glyphTexture->charAscent; }
	/// <summary>	Gets the character ascent of the mesh's font, in pixels. This is the 
	/// 			distance from the base line to the top of the highest character </summary>
	__declspec(property(get = __getCharAscent)) int charAscent;

	int __getLineHeight() { return glyphTexture->lineHeight; }
	/// <summary>	Gets the line height of the mesh's font, in pixels. This is the 
	/// 			baseline-to-baseline distance.</summary>
	__declspec(property(get = __getLineHeight)) int lineHeight;

	template<class MeshType>
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
		void checkRebuild()
		{
			while (isDirty) {
				isDirty = false;
				rebuild(mesh);
			}
		}
		void draw()
		{
			checkRebuild();
			mesh.draw(GL_TRIANGLES);
		}
		void bindAndDraw()
		{
			checkRebuild();
			mesh.bindAndDraw();
		}
	};
	typedef TemplatedAutoRebuildingMesh<TextMesh> AutoRebuildingMesh;
};
}