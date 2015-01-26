#include "viewmanager.h"

ViewManager::ViewManager()
{

    list.push_back(new ViewPort());
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
