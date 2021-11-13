#pragma once

// COPYRIGHT 2021   F L E X S I M   C O R P O R A T I O N .  ALL RIGHTS RESERVED.

#include "BasicMacros.h"
#include "BasicClasses.h"

// Need to undef min and max for Clang
#pragma push_macro("min")
#pragma push_macro("max")
#undef min
#undef max
#include <string>
#pragma pop_macro("min")
#pragma pop_macro("max")

namespace FlexSim 
{

class ByteBlock
{ 
  //DATA MEMBERS ARE MANUALLY ALIGNED (NO PADDING)
public:
	char *block;                // (4 or 8 bytes)
private:
	unsigned int blockSize;     // (4 bytes)
	unsigned int parity;      //  (4 bytes)
	static const int LOCAL_BLOCK_SIZE = 24;
	char localBlock[LOCAL_BLOCK_SIZE]; // (24 bytes)


	inline bool setSizeInline(size_t);

	void nullTerminate() { block[blockSize - 1] = 0; }
public:
	ByteBlock() : parity((unsigned int)(size_t)this), blockSize(1)
	{
		block = localBlock;
		localBlock[0] = 0;
	}
	// copy constructor
	ByteBlock(const ByteBlock& other) : parity((unsigned int)(size_t)this), blockSize(0), block(localBlock)
	{
		write(other.block, other.blockSize, false);
	}
	ByteBlock(ByteBlock&& other) : parity((unsigned int)(size_t)this), blockSize(other.blockSize), block(other.block)
	{
		if (other.block == other.localBlock)
			write(other.block, other.blockSize, false);
		else {
			blockSize = other.blockSize;
			block = other.block;
			other.block = other.localBlock;
			other.blockSize = LOCAL_BLOCK_SIZE;
		}
	}
	~ByteBlock()
	{
		if (!checkParity()) return;
		parity = 0;
		if (block && block != localBlock) 
			flexsimfree(block);
	}
	engine_export void write(const char *source);
	engine_export void write(const char *source, size_t intsize, bool nullterminate);
	engine_export bool setSize(size_t);
	engine_export unsigned int getSize() const;
	engine_export char *getBuffer();
	engine_export const char *getBuffer() const;
	engine_export void append(const char *source);
	engine_export void append(const char *source, size_t intsize, int nullterminate);
	ByteBlock& operator =(const char * c)
		{ write(c); return *this; }
	ByteBlock& operator =(const std::string& c)
		{ write(c.c_str(), c.length() + 1, true); return *this; }
	ByteBlock& operator +=(const char * c)
		{ append(c); return *this; }
	ByteBlock& operator +=(const std::string& c)
		{ append(c.c_str(), c.length(), true); return *this; }
	ByteBlock& operator=(const ByteBlock& copyfrom)
		{ write(copyfrom.block, copyfrom.blockSize, 0); return *this; }
	operator char*()
		{return getBuffer();}
	inline bool checkParity(){return parity==(unsigned int)(size_t)this;}//true if valid

	engine_export bool operator == (const ByteBlock& other) const;
	bool operator != (const ByteBlock& other) const { return !operator ==(other); }

	#ifdef FLEXSIM_ENGINE_COMPILE
		void* operator new(size_t size);
		void operator delete(void* p);
  
		void write(const char *source, size_t intsize);
		void read(char *dest, size_t intsize);
 
		size_t getSaveSize();
		bool save(std::ostream& stream);
		bool load(std::istream& stream);
		bool save(char*& destination);
		bool load(const char*& source);


		bool saveXML(std::ostream& doc, const char* elementName, bool isNameBB = false);
		bool loadXML(std::istream& doc);

		void replaceSubString(ptrdiff_t preposition, size_t position, char *substitute);
		bool searchSubString(char *pattern, char *substitute, bool rep); // return true when not at end; set substringcursor when done

		bool parserSearchSubString(char *pattern, char *substitute, int rep); // return true when not at end; set substringcursor when done
		bool parserSearchSubStringNotWholeWord(char *pattern, char *substitute, bool rep); // return true when not at end; set substringcursor when done


		static size_t subStringCursor; // position  in block
		void showErrorMsg(const char* msg);
	#endif
};
}

















// COPYRIGHT 2006   F L E X S I M   C O R P O R A T I O N .  ALL RIGHTS RESERVED.














