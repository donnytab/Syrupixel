#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

static bool bRunDaemon = true;

int StartDaemon()
{
    int iFd;
    int iRet = fork();
    switch (iRet) {
        case -1:
            // log err
            return iRet;
        case 0:
            break;
        default:
            exit(0);
    }

    // create new session
    iRet = setsid();
    if (iRet == -1) {
        // log err
        return iRet;
    }

    // double fork
    iRet = fork();
    switch (iRet) {
        case -1:
            // log err
            return iRet;
        case 0:
            break;
        default:
            exit(0);
    }

    umask(0);
    chdir("/");

    while (bRunDaemon) {
        sleep(5);
    }

    return iRet;
}

int main(int argc, char* argv[])
{
    // handle input params

    int iRet;

    iRet = StartDaemon();
    if (iRet) {
        // log err
    }

    return iRet;
}
