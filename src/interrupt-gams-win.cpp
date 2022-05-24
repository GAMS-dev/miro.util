#ifdef _WIN32
#include <windows.h>

using namespace std;
#include <string>
#include <sstream>
#endif

#include "cpp11.hpp"
using namespace cpp11;

[[cpp11::register]]
int windowsInterruptGAMS(int pid)
{
#ifdef _WIN32
    COPYDATASTRUCT cds;
    const char* msgText = "GAMS Message Interrupt";

    std::string windowName = "___GAMSMSGWINDOW___";
    windowName += std::to_string(pid);
    HWND receiver = FindWindowA(NULL, windowName.c_str());
    if (!receiver) { return 0; }

    cds.dwData = (ULONG_PTR) 1;
    cds.lpData = (PVOID) msgText;
    cds.cbData = (DWORD) (strlen(msgText) + 1);

    SendMessageA(receiver, WM_COPYDATA, 0, (LPARAM)(LPVOID)&cds);
    return 1;
#endif
    return 0;
}
