#ifndef CAMERAORTHO_H
#define CAMERAORTHO_H
#include <Util/Cam/camera.h>
#include <Util/Cam/cameraset.h>

class CameraOrtho : public Camera
{
public:
    CameraOrtho();
    void configCam(int cam =0);
    void configScreen(int w = 1,int h = 1);

    int axysDolly;
    int axysTrack;
    int axysPedestal;

    void track(float x);
    void pedestal(float y);
    void dolly(float z);
    //void pan(float angle);
//    void tilt(float angle);

    void mouseMove();
};

#endif // CAMERAORTHO_H
