#pragma once
#ifdef FLEXSIM_ENGINE_COMPILE
#include "BasicClasses.h"
#include "BasicMacros.h"
#include "Platform.h"
#include "DataTypes.h"
#include "SimpleDataType.h"
#include <string>
#else
#include "FlexsimDefs.h"
#endif

class TableView;

namespace FlexSim {

class BundleViewDataSource;

struct TableCell
{
	TableCell() : row(0), col(0) {}
	TableCell(long long row, long long col) : row(row), col(col) {}
	long long row;
	long long col;
	bool operator==(const TableCell& otherCell) const { return row == otherCell.row && col == otherCell.col; };
	struct Hash
	{
		size_t operator ()(const TableCell& cell) const { return (size_t)(cell.row ^ cell.col); }
	};
};

struct TableDimensions
{
	TableDimensions() : numCols(0), numRows(0) {}
	TableDimensions(size_t numRows, size_t numCols) : numRows(numRows), numCols(numCols) {}
	size_t numRows;
	size_t numCols;
};

class TableViewDataSource : public SimpleDataType
{
protected:
	treenode focus;
	treenode viewNode;
	TableView* tableView;
	bool isDataEntryTable;
	bool isAccountingFormat;
public:
	void* operator new (size_t size)
	{
		void* p = flexsimmalloc(size);
		if (!p) throw 0;
		return p;
	}
		void operator delete (void* p)
	{
			flexsimfree(p);
	}
	TableViewDataSource(TableView* tableView);
	engine_export TableViewDataSource(TreeNode* tableView);
	virtual ~TableViewDataSource() {}
	engine_export virtual void onOpen() { }
	virtual void setFocus(treenode vFocus) { focus = vFocus; }
	engine_export virtual void onStartPaint(treenode focus);
	engine_export virtual TableDimensions getDimensions() = 0;
	engine_export virtual treenode getCellNode(TableCell cell) { return 0; }

	/**
	* \defgroup CellText Getting/Setting Cell Text
	* @{
	* When you implement a data source, there are two main ways you can get cell text. The "faster" way
	* is to implement your own overloads of getCellTextAndFormat(), getCellText(), and getCellTextRequiredBufferSize()
	* These are faster c-style commands that allow you full flexibility as to how to format the text that
	* is displayed. However, they're a little more cumbersome because you have to define multiple overloads
	* and use c-style string functions.
	*
	* The second method is to simply overload getCellValue(). The default implementations of the getCellText...
	* methods above actually just call getCellValue(), and then do the proper processing. Note that this is slower
	* but if you just want to get it working and don't really care about render speed, use getCellValue().
	*/

	/// <summary>	Gets cell text and format. </summary>
	/// <remarks>	Anthony.johnson, 2/27/2015. </remarks>
	/// <param name="cellNode">  	The cell node. </param>
	/// <param name="cell">		 	The cell. </param>
	/// <param name="destBuffer">	[in,out] If non-null, buffer for destination data. </param>
	/// <param name="bufferSize">	Size of the buffer. </param>
	/// <param name="precision"> 	The precision. </param>
	/// <param name="uFormat">   	[in,out] Describes the format to use. </param>
	/// <param name="dc">		 	The device-context. </param>
	/// <param name="clipRect">  	[in,out] The clip rectangle. </param>
	engine_export virtual void getCellTextAndFormat(treenode cellNode, TableCell cell, char* destBuffer, size_t bufferSize,
		int precision, unsigned int& uFormat, DeviceContext dc, WindowRect& clipRect)
	{
		return getCellText(cellNode, cell, destBuffer, bufferSize, precision);
	}


	/// <summary>	Gets cell text. </summary>
	/// <remarks>	Anthony.johnson, 2/27/2015. </remarks>
	/// <param name="cellNode">  	The cell node. </param>
	/// <param name="cell">		 	The cell. </param>
	/// <param name="destBuffer">	[in,out] If non-null, buffer for destination data. </param>
	/// <param name="bufferSize">	Size of the buffer. </param>
	/// <param name="precision"> 	The precision. </param>
	engine_export virtual void getCellText(treenode cellNode, TableCell cell, char* destBuffer, size_t bufferSize, int precision, bool editing = false);

	/// <summary>	Gets cell text required buffer size. </summary>
	/// <remarks>	Anthony.johnson, 2/27/2015. </remarks>
	/// <param name="cellNode">	The cell node. </param>
	/// <param name="cell">	   	The cell. </param>
	/// <returns>	The cell text required buffer size. </returns>
	engine_export virtual size_t getCellTextRequiredBufferSize(treenode cellNode, TableCell cell, int precision, bool editing = false);

	/// <summary>	Gets a cell value. </summary>
	/// <remarks>	You only need to implement this if you decide not to implement the getCellText... methods, or if you want copying to not throw exceptions </remarks>
	/// <param name="cell">	The cell. </param>
	/// <returns>	The cell value. </returns>
	engine_export virtual Variant getCellValue(treenode cellNode, TableCell cell) { return cellNode->value; }

	/// <summary>	Sets cell value. </summary>
	/// <remarks>	This is only called by the apply() method, so if you override the apply() method,
	/// 			you don't need to implement this method.</remarks>
	/// <param name="cell">			 	The cell. </param>
	/// <param name="cellText">		 	The cell text. </param>
	engine_export virtual void setCellValue(TableCell cell, const char* cellText) {}

	/// <summary>	Sets cell value. </summary>
	/// <remarks>	This is called by the On Paste if getCellNode() returns a nullptr.</remarks>
	/// <param name="cell">			 	The cell. </param>
	/// <param name="value">		 	The new cell value. </param>
	engine_export virtual void setCellValue(TableCell cell, const Variant& value) {}

	/// <summary>	Copy's the table structure. </summary>
	/// <remarks>	This is used by the Table View's On Copy.</remarks>
	/// <param name="minCell">			The starting cell to copy. </param>
	/// <param name="maxCell">		 	The ending cell to copy. </param>
	/// <param name="nodeBuffer">		The node to copy the structure into. </param>
	engine_export virtual bool copyTableStructure(TableCell minCell, TableCell maxCell, TreeNode* nodeBuffer) { return false; }

	/// <summary>	Copy's the table structure. </summary>
	/// <remarks>	This is used by the Table View's On Paste.</remarks>
	/// <param name="minCell">			The starting cell to paste to. </param>
	/// <param name="nodeBuffer">		The node data to paste. </param>
	engine_export virtual bool pasteTableStructure(TableCell minCell, TreeNode* nodeBuffer) { return false; }

	/// <summary>	Notification when the table selection changed. </summary>
	/// <remarks>	This is used by the Table View's On Paste.</remarks>
	engine_export virtual void selectionDidChange() { }

	/// <summary>	Used to update the status bar. </summary>
	engine_export virtual std::string getStatusBarText(TableCell rangeStart, TableCell rangeEnd);

	/**
	* @}
	*/
	virtual bool isReadOnly(TableCell cell) { return false; }

	static const int ASSERT_DATA_TYPE_AUTO = -1;
	/// <summary>	Applies the text from the window control(s) to the data in the tree/object. </summary>
	/// <remarks>	It is up to the data source to retrieve the text from the control. If the cell's row or 
	/// 			column are 0, then the text will be stored in tableView->control's window text. Otherwise
	/// 			the text will be stored in tableView->datacontrol's window text (I know, it's whacky,
	/// 			but for now that's the way it is). If you want to be simpler, don't override apply, but 
	/// 			instead override setCellValue().</remarks>
	/// <param name="cellNode">		 	The cell node. If getCellNode() returns 0, then this will be 0, so you
	/// 								just </param>
	/// <param name="cell">			 	The cell. </param>
	/// <param name="assertDataType">	Type of the assert data. </param>
	/// <returns>	An int. </returns>
	engine_export virtual int apply(treenode cellNode, TableCell cell, int assertDataType);
	int apply(TableCell cell, int assertDataType) { return apply(getCellNode(cell), cell, assertDataType); }
	engine_export virtual bool isOneDimensional();
	engine_export virtual bool shouldDrawRowHeaders();
	virtual bool shouldDrawColHeaders() { return true; }
	virtual BundleViewDataSource* toBundle() { return 0; }

	/// <summary>	Deletes the range of cell's data. </summary>
	/// <remarks>	This is called when the Delete key is pressed.</remarks>
	/// <param name="startRow">	The start row of the selected range. </param>
	/// <param name="endrow">	The end row of the selected range. </param>
	/// <param name="startCol"> The start column of the selected range. </param>
	/// <param name="endCol">	The end column of the selected range. </param>
	engine_export virtual void onDeleteCellText(size_t startRow, size_t endRow, size_t startCol, size_t endCol);

	engine_export void displayTooltip(char* text, int milliseconds = 1000);
	engine_export void removeTooltip();
#ifdef _WINDOWS
	engine_export static VOID CALLBACK killTooltip(HWND, UINT, UINT_PTR, DWORD);
#endif

	void setTableView(TableView* tableView);
	static bool nodeHasArrayData(TreeNode* target);
	static bool nodeHasMapData(TreeNode* target);
};

}