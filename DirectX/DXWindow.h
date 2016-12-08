#pragma once
#include <windows.h>
#include <d3dcompiler.h>
#include <directxmath.h>
#include "resource.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

class DXWindow
{
public:

	DXWindow(HINSTANCE hInstance, int nCmdShow);
	
	~DXWindow();

	HWND getHandle();

private:
	HINSTANCE               m_hInst = nullptr;
	HWND                    m_hWnd = nullptr;

	HRESULT InitWindow(HINSTANCE hInstance, int nCmdShow, WNDPROC wndProc=WndProc);



};

