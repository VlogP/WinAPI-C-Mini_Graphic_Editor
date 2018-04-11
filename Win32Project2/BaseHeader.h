#include <windows.h>
#pragma once
class Base_Graphic
{
protected:
	int coordinate_x, coordinate_y;
	COLORREF ColorPen, ColorBrush;
	HDC hdC;
	HWND hWnD;
	HBRUSH Brush;
	HPEN Pen;
	HBITMAP BMP;
public:
	Base_Graphic() :coordinate_x(0), coordinate_y(0), ColorPen(RGB(0, 0, 0)), ColorBrush(RGB(0, 0, 0))
	{}
	Base_Graphic(HWND HWnD, HDC hdc, HBITMAP bmp, int x, int y, COLORREF ColorP) :hWnD(HWnD), coordinate_x(x), coordinate_y(y), ColorPen(ColorP),hdC(hdc),BMP(bmp)
	{}
	Base_Graphic(HWND HWnD, HDC hdc, HBITMAP bmp, int x, int y, COLORREF ColorP, COLORREF ColorB) :hWnD(HWnD), coordinate_x(x), coordinate_y(y), ColorPen(ColorP), ColorBrush(ColorB), hdC(hdc),BMP(bmp)
	{}
	virtual	void show() = 0{}
};
class Geometrical_list
{
private:
	int Number_Of_Elements = 0;
	Base_Graphic* list[1000];
public:
	void ShowList()
	{
		for (int i = 0; i < Number_Of_Elements; i++)
		{
			list[i]->show();

		}
	}
	void getElement(Base_Graphic* Element)
	{
		list[Number_Of_Elements] = Element;
		Number_Of_Elements++;
	}
	void Free_Elements()
	{
		for (int i = 0; i < Number_Of_Elements; i++)
		{
			delete list[i];
			list[i] = NULL;
		}

		Number_Of_Elements = 0;
	}
	
};

