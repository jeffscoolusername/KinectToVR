// KinectlessProcess.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <KinectToVR.h>
#include <KinectHandlerBase.h>

#include <easylogging++.h>

// Logging Definitions
INITIALIZE_EASYLOGGINGPP
#define ELPP_FEATURE_CRASH_LOG

//This process is intended to be run in situations without a kinect
// i.e. at time of writing, the SteamVRBridge driver for PSMoves is broke
// and I just want to use the moves as trackers, so the process will be run without the kinect

class FakeKinect : public KinectHandlerBase{
public:
    FakeKinect() {
        initialised = true;
    }
    ~FakeKinect() {

    }
};
int main(int argc, char* argv[])
{
    START_EASYLOGGINGPP(argc, argv);
    FakeKinect kinect;

    processLoop(kinect);

    return 0;
}

#ifdef _WIN32
// This disables the console window from appearing on windows only if the Project Settings->Linker->System->SubSystem is set to Windows (rather than Console).
int WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCMDShow)
{
    FakeKinect kinect;

    processLoop(kinect);

    return 0;
}
#endif
