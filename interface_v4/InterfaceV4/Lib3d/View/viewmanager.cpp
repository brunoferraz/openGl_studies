#include "viewmanager.h"
#include <View/viewportortotop.h>
#include <View/viewportortoleft.h>

ViewManager::ViewManager()
{

    list.push_back(new ViewPort());
    list.push_back(new ViewPortOrtoTop());
    list.push_back(new ViewPortOrtoLeft());
    list.push_back(new ViewPortOrto());
    setSize(1,1);
    setViewPort(0);
}

void ViewManager::setSize(int w, int h)
{
    width   = float(w);
    height  = float(h);
    ratio   = width/ height;
}

void ViewManager::setViewPort(int const i)
{
    currentView = list.at(i);
    currentView->config(this->width, this->height);
}

Eigen::Vector3f ViewManager::getTranslateFromScreen(float x, float y)
{
    return currentView->getTranslateFromScreen(x, y);
}
