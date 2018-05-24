#include <iostream>
#include <stdlib.h>

#include "Windows.h"

using namespace std;

int checkPower()
{
    _SYSTEM_POWER_STATUS status;
    GetSystemPowerStatus(&status);

    if (status.ACLineStatus == 0)
        return 0;
    else
        return 1;

}

void Shutdown()
{
    system("C:\\Windows\\System32\\shutdown /h");
}

void cancelShutdown()
{
    system("C:\\Windows\\System32\\shutdown /a /t 120");
}

int main()
{
    int i = 0;
    while (1){

    if (checkPower()==0)
        {
            Shutdown();
            break;
        }
    }

    while (i<=40){

    if (checkPower()==1)
        {
            cancelShutdown();
            break;
        }
        i++;
    }
    return 0;
}
