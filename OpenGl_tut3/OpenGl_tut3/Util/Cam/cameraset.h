#ifndef CAMERASET_H
#define CAMERASET_H

#include <Util/Cam/camera.h>

class CameraSet
{
public:
    CameraSet();

    static Camera currentCamera;
};

#endif // CAMERASET_H
