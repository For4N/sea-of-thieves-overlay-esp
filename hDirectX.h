#ifndef HDIRECTX_H
#define HDIRECTX_H

#include <iostream>
#include <windows.h>
#include <d3dx9.h>
#include <dwmapi.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "dwmapi.lib")

// cDirectX
int DirectXInit(HWND hWnd);
int Render();
extern ID3DXLine* p_Line;

// cDrawings
int DrawString(char* String, int x, int y, int r, int g, int b, ID3DXFont* ifont);
void FillRGB(float x, float y, float w, float h, int r, int g, int b, int a);
void DrawBox(float x, float y, float width, float height, float px, int r, int g, int b, int a);

// cMain
void SetWindowToTarget();
extern int Width;
extern int Height;
extern HWND tWnd;
#endif