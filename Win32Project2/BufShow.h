#include"GeometricLinesHeader.h"
#include"GeometricObjectHeader.h"
#include"BaseHeader.h"
#include<windows.h>
#include<math.h>
#pragma once
class Geometrical_Buffer: public Rectangle_Graphic, public Circle_Graphic, public Ellipse_Graphic, public Triangle_Graphic, public Line_Graphic,public Base_Graphic
{
public:
	static void Bufshow(int Number, HDC hdc,HWND hWnD, int x1, int y1, int x2, int y2, COLORREF ColorPenBuf, COLORREF ColorPenBrush)
	{
		if(Number==0)
			
			{
			
			HPEN pen = CreatePen(PS_SOLID, 1, ColorPenBuf);
			HBRUSH	Brush = CreateSolidBrush(ColorPenBrush);
			SelectObject(hdc, Brush);
			SelectObject(hdc, pen);
			Rectangle(hdc, x1, y1, x2, y2);
			ReleaseDC(hWnD, hdc);
			DeleteObject(pen);
		
			}
		if (Number == 1)
			{
				HPEN pen = CreatePen(PS_SOLID, 1, ColorPenBuf);
				SelectObject(hdc, pen);
				MoveToEx(hdc, x1, y1, NULL);
				LineTo(hdc, x2, y2);
				ReleaseDC(hWnD, hdc);
				DeleteObject(pen);
				
			}
			if(Number==2)
			{
				HBRUSH Brush = CreateSolidBrush(ColorPenBrush);
				HPEN Pen = CreatePen(PS_SOLID, 1, ColorPenBuf);
				SelectObject(hdc, Brush);
				SelectObject(hdc, Pen);
				Ellipse(hdc, x1, y1, x2, y2);
				ReleaseDC(hWnD, hdc);
				DeleteObject(Brush);
				DeleteObject(Pen);
				
			}
			if (Number == 3)
			{
				int BUFX1, BUFX2, BUFY1, BUFY2;

				HBRUSH	Brush = CreateSolidBrush(ColorPenBrush);
				HPEN Pen = CreatePen(PS_SOLID, 1, ColorPenBuf);
				SelectObject(hdc, Brush);
				SelectObject(hdc, Pen);
				BUFX1 = abs(x1 - x2);
				if (abs(x1 - x2) == abs(y2 - y1)) { Ellipse(hdc, x1, y1, x2, y2); }
				if (abs(x1 - x2) > abs(y2 - y1)) {
					BUFX1 = (y2 - y1);
					Ellipse(hdc, x1, y1, x1 + BUFX1, y1 + BUFX1);
				}
				if (abs(x1 - x2) < abs(y2 - y1))
				{
					BUFX1 = (x2 - x1);
					Ellipse(hdc, x1, y1, x1 + BUFX1, y1 + BUFX1);
				}
				//Ellipse(hdc, x1, y1, x2, y2);
				ReleaseDC(hWnD, hdc);
				DeleteObject(Brush);
				DeleteObject(Pen);
				
			}
		
	}
	
	static Base_Graphic* Get_elementUPP(int Choise, HWND hWnD, HDC hdC,HBITMAP bmp, int x1, int y1, int x2, int y2, COLORREF ColorPenBuf, COLORREF ColorPenBrush)
	{
		if (Choise == 0) { return new Rectangle_Graphic(hWnD, hdC, bmp, x1, y1, x2, y2, ColorPenBuf, ColorPenBrush);}
		if (Choise == 1)
		{
			return new Line_Graphic(hWnD, hdC, bmp, x1, y1, x2, y2, ColorPenBuf);

			
		}
		if (Choise == 2){return new Ellipse_Graphic(hWnD, hdC, bmp, x1, y1, x2, y2, ColorPenBuf, ColorPenBrush);}
		if (Choise == 3)
		{
			if (abs(x1 - x2) == abs(y2 - y1)) { return new Circle_Graphic(hWnD, hdC, bmp, x1, y1, x2, y2, ColorPenBuf, ColorPenBrush); }
			if (abs(x1 - x2) > abs(y2 - y1)) {
				int BUFX1 = (y2 - y1);
				return new Circle_Graphic(hWnD, hdC, bmp, x1, y1, x1 + BUFX1, y1 + BUFX1, ColorPenBuf, ColorPenBrush);
			}
			if (abs(x1 - x2) < abs(y2 - y1))
			{
				int BUFX1 = (x2 - x1);
				return new Circle_Graphic(hWnD, hdC, bmp, x1, y1, x1 + BUFX1, y1 + BUFX1, ColorPenBuf, ColorPenBrush);
			}
			
		}
	  
	}
};