#pragma once
#include <Windows.h>
#include <string>
#include <limits>
using namespace std;
namespace GameUtils
{
	void WaitMs(int ms);
	void ClearScreen();
	void PrintW(const wstring& w);
	wstring ReadWLine();
	bool ReadInt(const char* prompt, int& out);
}

//int main()
//{
//    // 출력 코드페이지는 크게 중요하지 않지만, 다른 출력과 혼용 시를 대비해 설정해둘 수 있음
//    // (우리는 WriteConsoleW로 찍기 때문에 코드페이지 의존이 낮습니다.)
//    SetConsoleOutputCP(CP_UTF8);
//
//    PrintW(L"한글 출력 테스트\n");
//    PrintW(L"한글을 입력해보세요: ");
//
//    std::wstring input = ReadWLine();
//
//    PrintW(L"\n입력한 내용: ");
//    PrintW(input);
//    PrintW(L"\n");
//
//    return 0;
//}