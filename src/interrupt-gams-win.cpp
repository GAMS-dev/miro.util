#include <Rcpp.h>
#ifdef __MINGW32__
// Taken from http://tolstoy.newcastle.edu.au/R/e2/devel/06/11/1242.html
// Undefine the Realloc macro, which is defined by both R and by Windows stuff
#undef Realloc
// Also need to undefine the Free macro
#undef Free

#include <windows.h>

using namespace std;
#include <string>
#include <sstream>
// workaround to make std::to_string work from:
// https://stackoverflow.com/questions/12975341/to-string-is-not-a-member-of-std-says-g-mingw
namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}
#endif
using namespace Rcpp;

// [[Rcpp::export]]
int windowsInterruptGAMS(int pid)
{
#ifdef __MINGW32__
    //IntPtr receiver;
    COPYDATASTRUCT cds;
    const char* msgText = "GAMS Message Interrupt";

    std::string windowName = "___GAMSMSGWINDOW___";
    windowName += patch::to_string(pid);
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
