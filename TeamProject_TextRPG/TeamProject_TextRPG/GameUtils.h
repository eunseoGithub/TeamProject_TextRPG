#pragma once
#include <Windows.h>
#include <string>
#include <limits>
using namespace std;

enum Color
{
	BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	BROWN,
	LIGHTGRAY,
	DARKGRAY,
	LIGHTBLUE,
	LIGHTGREEN,
	LIGHTCYAN,
	LIGHTRED,
	LIGHTMAGENTA,
	YELLOW,
	WHITE
};

namespace GameUtils
{
	void WaitMs(int ms);
	void ClearScreen();
	void PrintW(const wstring& w);
	wstring ReadWLine();
	bool ReadInt(const char* prompt, int& out);
	void Textcolor(int foreground, int background);
}
extern Color gColor;