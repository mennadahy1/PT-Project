#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition () 
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 
}

CellPosition::CellPosition (int v, int h)
{ 
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition (int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v) 
{
	if (v >= 0 && v <= 8) {

		vCell = v;
		return true;
	}

	///fixed code


	return false; ///fixed code
}

bool CellPosition::SetHCell(int h) 
{
	if (h >= 0 && h <= 10) {
		hCell = h;
		return true;
}


	///fixed code


	return false; // fixed code
}

int CellPosition::VCell() const 
{
	return vCell;
}

int CellPosition::HCell() const 
{
	return hCell;
}

bool CellPosition::IsValidCell() const 
{
	if (vCell >= 0 && vCell <= 8 && hCell >= 0 && hCell <= 10) {
		return true;
	}
	//fixed code
	return false; // fixed code
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition& cellPosition)
{
	int v = cellPosition.VCell();
	int h = cellPosition.HCell();
	if (v < 0 || v>8 || h < 0 || h>10) {
		return -1;
	}
	int number = 1;
	for (int r = 8; r > v; r--) {
		number += 11;

	}
	number += h;

	return number;
}
//fixed code 

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{

	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;

	if (cellNum >= 1 && cellNum <= 99)
	{
		int r = 8;
		int c = 0;

		for (int i = 1; i < cellNum; i++)
		{
			c++;

			if (c == 11)
			{
				c = 0;
				r--;
			}
		}

		position.SetVCell(r);
		position.SetHCell(c);
	}



	// fixed code


	return position;
}

void CellPosition::AddCellNum (int addedNum)
{
	
	int number= GetCellNum();
	number  += addedNum;

	CellPosition p = GetCellPositionFromNum(number);

	vCell = p.VCell();
	hCell = p.HCell();
	// fixed code

}