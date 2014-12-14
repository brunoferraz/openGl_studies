#ifndef CAMERAORTHO_H
#define CAMERAORTHO_H
#include <Util/Cam/camera.h>

class CameraOrtho : public Camera
{
public:
    CameraOrtho();
    void configCam();
    void configScreen(int w, int h);

    void track(float x);
    void pedestal(float y);
    void dolly(float z);
    void pan(float angle);
    void tilt(float angle);
};

#endif // CAMERAORTHO_H
