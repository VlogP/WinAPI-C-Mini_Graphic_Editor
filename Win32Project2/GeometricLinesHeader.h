#include <windows.h>
#include"BaseHeader.h"
#pragma once
class Line_Graphic :public Base_Graphic
{
private:
	int coordinate_x2, coordinate_y2;
public:
	Line_Graphic(HWND hWnD, HDC hdC, HBITMAP bmp, int x1, int y1, int x2, int y2, COLORREF ColorP) : Base_Graphic(hWnD, hdC, bmp, x1, y1, ColorP), coordinate_x2(x2), coordinate_y2(y2)
	{}
 virtual void show() override
	{
		Base_Graphic::show();
		Pen = CreatePen(PS_SOLID, 1, ColorPen);
		SelectObject(hdC, Pen);
		SelectObject(hdC, BMP);
		MoveToEx(hdC, coordinate_x, coordinate_y, NULL);
		LineTo(hdC, coordinate_x2, coordinate_y2);
		ReleaseDC(hWnD, hdC);
		DeleteObject(Pen);
	}
protected:
	static void Buf_Show(HDC hdC,HWND hWnD, int x1, int y1, int x2, int y2, COLORREF ColorPenBuf, COLORREF ColorPenBrush)
	{
	
		HPEN Pen = CreatePen(PS_SOLID, 1, ColorPenBuf);
		SelectObject(hdC, Pen);
		MoveToEx(hdC, x1, y1, NULL);
		LineTo(hdC, x2, y2);
		ReleaseDC(hWnD, hdC);
		DeleteObject(Pen);
	}

};

class Triangle_Graphic :public Base_Graphic
{
public:
	Triangle_Graphic(HWND hWnD, HDC hdC, HBITMAP bmp, int x1, int y1, COLORREF ColorP, COLORREF ColorB) : Base_Graphic(hWnD,hdC, bmp, x1, y1, ColorP, ColorB)
	{}
	virtual void show() override
	{
		Base_Graphic::show();
		Pen = CreatePen(PS_SOLID, 10, ColorPen);
		Brush = CreateSolidBrush(ColorBrush);
		SelectObject(hdC, Pen);
		SelectObject(hdC, Brush);
		SelectObject(hdC, BMP);
		MoveToEx(hdC, coordinate_x - 300, coordinate_y, NULL);
		LineTo(hdC, coordinate_x, coordinate_y - 300);
		LineTo(hdC, coordinate_x + 300, coordinate_y);
		LineTo(hdC, coordinate_x - 300, coordinate_y);
		ExtFloodFill(hdC, coordinate_x - 140, coordinate_y - 50, ColorPen, FLOODFILLBORDER);
		ReleaseDC(hWnD, hdC);
		DeleteObject(Pen);
		DeleteObject(Brush);

	}
};
