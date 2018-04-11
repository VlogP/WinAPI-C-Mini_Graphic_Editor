#include <windows.h>
#include"BaseHeader.h"
#pragma once
class Rectangle_Graphic :public Base_Graphic
{
private:
	int coordinate_x2, coordinate_y2;
public:
	Rectangle_Graphic(HWND hWnD, HDC hdC, HBITMAP bmp, int x1, int y1, int x2, int y2, COLORREF ColorP, COLORREF ColorB) : Base_Graphic(hWnD, hdC, bmp, x1, y1, ColorP, ColorB), coordinate_x2(x2), coordinate_y2(y2)
	{}
	virtual	void show() override
	{
		
		Brush = CreateSolidBrush(ColorBrush);
		Pen = CreatePen(PS_SOLID, 1, ColorPen);
		SelectObject(hdC, Brush);
		SelectObject(hdC, Pen);
	
		SelectObject(hdC, BMP);
		Rectangle(hdC, coordinate_x, coordinate_y, coordinate_x2, coordinate_y2);
		
		DeleteObject(Brush);
		DeleteObject(Pen);
	}
protected:
	static void Buf_Show(HDC hdC1,HWND hWnD, int x1, int y1, int x2, int y2, COLORREF ColorPenBuf,COLORREF ColorPenBrush)
	{
		HBRUSH Brush;
		HPEN Pen;
	
		Brush = CreateSolidBrush(ColorPenBrush);
		Pen = CreatePen(PS_SOLID, 1, ColorPenBuf);
		SelectObject(hdC1, Brush);
		SelectObject(hdC1, Pen);
	
		Rectangle(hdC1, x1, y2, x2, y2);
		
		DeleteObject(Brush);
		DeleteObject(Pen);
	}
};
class Circle_Graphic :public Base_Graphic
{
	int coordinate_x2, coordinate_y2;
public:
	Circle_Graphic(HWND hWnD, HDC hdC, HBITMAP bmp, int x1, int y1,int x2,int y2, COLORREF ColorP, COLORREF ColorB) : Base_Graphic(hWnD, hdC, bmp, x1, y1, ColorP, ColorB), coordinate_x2(x2), coordinate_y2(y2)
	{}
	virtual	void show() override
	{
		Base_Graphic::show();
		Brush = CreateSolidBrush(ColorBrush);
		Pen = CreatePen(PS_SOLID, 1, ColorPen);
		SelectObject(hdC, Brush);
		SelectObject(hdC, Pen);
		SelectObject(hdC, BMP);
		Ellipse(hdC, coordinate_x, coordinate_y, coordinate_x2, coordinate_y2);
		//ReleaseDC(hWnD, hdC);
		DeleteObject(Brush);
		DeleteObject(Pen);
	}
protected:
	void Buf_Show() 
	{
		Base_Graphic::show();

	}

};
class Ellipse_Graphic :public Base_Graphic
{
private:
	int coordinate_x2, coordinate_y2;
public:
	Ellipse_Graphic(HWND hWnD, HDC hdC, HBITMAP bmp, int x1, int y1, int x2, int y2, COLORREF ColorP, COLORREF ColorB) : Base_Graphic(hWnD, hdC, bmp, x1, y1, ColorP, ColorB), coordinate_x2(x2), coordinate_y2(y2)
	{}
	virtual	void show() override
	{
		Base_Graphic::show();
		Brush = CreateSolidBrush(ColorBrush);
		Pen = CreatePen(PS_SOLID, 1, ColorPen);
		SelectObject(hdC, Brush);
		SelectObject(hdC, Pen);
		SelectObject(hdC, BMP);
		Ellipse(hdC, coordinate_x, coordinate_y, coordinate_x2, coordinate_y2);
		//ReleaseDC(hWnD, hdC);
		DeleteObject(Brush);
		DeleteObject(Pen);

	}
};
