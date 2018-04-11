#include <windows.h>
#include"BaseHeader.h"
#include"GeometricLinesHeader.h"
#include"GeometricObjectHeader.h"
#include"BufShow.h"
using namespace std;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	BOOL fDraw = FALSE;
	BOOL fDraw1 = FALSE;
	int fDraw2 = 0;
	POINT ptPrevious, ptPrevious1;
	int c1=0, c2=0, c3=0;
	int width = 1;
	int Choise = 0;
	Geometrical_list List;
	HDC hdc2; 
	HBITMAP bmp;

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, PSTR, INT iCmdShow)
{
	HWND                hWnd;
	MSG                 msg;
	WNDCLASS            wndClass;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.lpfnWndProc = WndProc;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hInstance = hInstance;
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hCursor = LoadCursorFromFile(L"XGreenMove.ani");			//LoadCursor(NULL, IDC_ARROW);
	wndClass.hbrBackground = CreateSolidBrush(RGB(240, 248, 255));
	wndClass.lpszMenuName = NULL;
	wndClass.lpszClassName = L"Графика";
	RegisterClass(&wndClass);
	hWnd = CreateWindow(
		L"Графика", L"Графика", WS_VISIBLE | WS_POPUP | WS_MAXIMIZE, CW_USEDEFAULT, CW_USEDEFAULT, 500, 300, HWND_DESKTOP, NULL, hInstance, 0);
	ShowWindow(hWnd, SW_MAXIMIZE);
	UpdateWindow(hWnd);
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message,
	WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	POINT point;
	HBRUSH hBrush;
	HPEN pen;
	Base_Graphic *rect,*elipse,*circle,*Line,*Triangle;
	switch (message)
	{

	case WM_CREATE:
		hdc = GetDC(hWnd);
		hdc2 = CreateCompatibleDC(hdc);
		bmp = CreateCompatibleBitmap(hdc, 1520, 1280);
		
		break;
	case WM_RBUTTONDOWN: 
		hdc = GetDC(hWnd);
		hBrush = CreateSolidBrush(RGB(240, 248, 255));
		pen = CreatePen(PS_NULL, 10, 2);
		SelectObject(hdc, hBrush);
		SelectObject(hdc, pen);
		Rectangle(hdc,0,0, 1480, 1020);
		ReleaseDC(hWnd, hdc);
		DeleteObject(hBrush);
		DeleteObject(pen);
		List.Free_Elements();
	    break;
		
	case WM_LBUTTONDOWN:
		

		if (fDraw2 == FALSE) {
			ptPrevious.x = LOWORD(lParam);
			ptPrevious.y = HIWORD(lParam);
			fDraw2 = TRUE;
			hdc = GetDC(hWnd);
			
		}
	
		break;

	case WM_LBUTTONUP:
		

		fDraw2 = FALSE;
	
		List.getElement(Geometrical_Buffer::Get_elementUPP(Choise, hWnd,hdc2,bmp,ptPrevious.x, ptPrevious.y, LOWORD(lParam), HIWORD(lParam), RGB(0, 0, 0), RGB(255, 255, 255)));
		break;
	case WM_MOUSEMOVE:
		
		if (fDraw2 == TRUE) {
			

			hdc = GetDC(hWnd);
			
			

			hBrush = CreateSolidBrush(RGB(240, 248, 255));
			pen = CreatePen(PS_NULL, 10, 2);
			SelectObject(hdc2, hBrush);
			SelectObject(hdc2, pen);
			SelectObject(hdc2, bmp);
			Rectangle(hdc2, 0, 0, 1400, 2000);
			
			DeleteObject(hBrush);
			DeleteObject(pen);
			
		    List.ShowList();
			
			
			Geometrical_Buffer::Bufshow(Choise, hdc2, hWnd, ptPrevious.x, ptPrevious.y, LOWORD(lParam), HIWORD(lParam), RGB(0, 0, 0), RGB(255, 255, 255));
			BitBlt(hdc, 0, 0, 1480, 1220, hdc2, 0, 0, SRCCOPY);
		
			ReleaseDC(hWnd, hdc);
			
			


		}

		break;
	case WM_MBUTTONDOWN:
		hdc = GetDC(hWnd);
		hBrush = CreateSolidBrush(RGB(c1, c2, c3));
		SelectObject(hdc, hBrush);
		ExtFloodFill(hdc, LOWORD(lParam), HIWORD(lParam), RGB(c1, c2, c3), FLOODFILLBORDER);
		ReleaseDC(hWnd, hdc);
		DeleteObject(hBrush);
		break;
	case WM_KEYDOWN: 
		switch (wParam) {
		case VK_ESCAPE:
		PostQuitMessage(0);
		break;
		case 0x31:
			Choise = 0;
			c1 = 0;
			c2 = 0;
			c3 = 139;
			break;
		case 0x32:
			Choise = 1;
			c1 = 255;
			c2 = 64;
			c3 = 64;
			break;
		case 0x33:
			Choise = 2;
			c1 = 0;
			c2 = 0;
			c3 = 0;
			break;
		case 0x34:
			Choise = 3;
			c1 = 50;
			c2 = 205;
			c3 = 50;
			break;	
		case 0x35:
			c1 = 255;
			c2 = 165;
			c3 = 0;
			break;
		case 0x36:
			fDraw1 = TRUE;
			break;
		case 0x37:
			fDraw1 = FALSE;
			break;

		case	VK_ADD:
			if (width <= 10) {
				width++;
			}
			break;
		case	VK_SUBTRACT:
			if (width >= 1) {
				width--;
			}
			break;

		}break;

	
	
	case WM_DESTROY:
		
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
}

