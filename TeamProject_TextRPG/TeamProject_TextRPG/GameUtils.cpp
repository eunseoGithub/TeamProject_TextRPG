#include "GameUtils.h"
#include <thread>
#include <chrono>
#include <cstdlib>
#include <iostream>
namespace GameUtils
{
	void WaitMs(int ms) {
		std::this_thread::sleep_for(std::chrono::milliseconds(ms));
	}

	void ClearScreen()
	{
		system("cls");
	}
    void PrintW(const wstring& w)
    {
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        DWORD written = 0;

        if (hOut == INVALID_HANDLE_VALUE) return;

        WriteConsoleW(hOut, w.c_str(), static_cast<DWORD>(w.size()), &written, nullptr);
    }

    // 콘솔에서 UTF-16 문자열을 안전하게 입력 (Enter까지 포함해서 들어오므로 개행 제거)
    wstring ReadWLine()
    {
        HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
        if (hIn == INVALID_HANDLE_VALUE) return L"";

        wchar_t buffer[1024];
        DWORD read = 0;

        if (!ReadConsoleW(hIn, buffer, 1024, &read, nullptr))
            return L"";

        wstring w(buffer, read);

        // \r\n 제거
        while (!w.empty() && (w.back() == L'\r' || w.back() == L'\n'))
            w.pop_back();

        return w;
    }
    bool ReadInt(const char* prompt, int& out)
    {
        while (true)
        {
            if (prompt)
                cout << prompt;
            if (cin >> out)
            {
                cin.ignore(10000, '\n');
                return true;
            }

            cin.clear();
            cin.ignore(10000, '\n');
            cout << "숫자로 입력해주세요.\n";
        }
        return false;
    }
   
}