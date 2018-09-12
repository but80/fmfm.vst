/*
  ==============================================================================

    SlowSlider.cpp
    Created: 11 Sep 2018 5:08:08pm
    Author:  ken

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "SlowSlider.h"

//==============================================================================
SlowSlider::SlowSlider() : Slider()
{
}

SlowSlider::SlowSlider(const String& componentName) : Slider(componentName)
{
}

SlowSlider::SlowSlider(SliderStyle style, TextEntryBoxPosition textBoxPosition) : Slider(style, textBoxPosition)
{
}

SlowSlider::~SlowSlider()
{
}

double SlowSlider::snapValue (double attemptedValue, DragMode dragMode) {
    return attemptedValue;
}

void SlowSlider::mouseWheelMove (const MouseEvent& e, const MouseWheelDetails& wheel)
{
    // printf("mouseWheelMove %s%s%s%s\n", e.source.isMouse()?" isMouse":"", e.source.isTouch()?" isTouch":"", wheel.isSmooth?" isSmooth":"", wheel.isInertial?" isInertial":"");

    if (!wheel.isSmooth) {
        Slider::mouseWheelMove (e, wheel);
        return;
    }

    float sensitivity = 20.0;
    auto range = pow(getMaximum() - getMinimum() + 8.0, .25);
    cx += wheel.deltaX * sensitivity / range;
    cy += wheel.deltaY * sensitivity / range;
    float step = 1.0;
    float eps = .1;
    float dx = .0;
    float dy = .0;
    while (step <= cx) {
        dx += eps;
        cx -= step;
    }
    while (cx <= -step) {
        dx -= eps;
        cx += step;
    }
    while (step <= cy) {
        dy += eps;
        cy -= step;
    }
    while (cy <= -step) {
        dy -= eps;
        cy += step;
    }
    // printf("%f, %f -> %f, %f -> %f, %f\n", wheel.deltaX, wheel.deltaY, cx, cy, dx, dy);
    if (dx != .0 || dy != .0) {
        MouseWheelDetails w;
        w.deltaX = dx;
        w.deltaY = dy;
        w.isReversed = wheel.isReversed;
        w.isSmooth = wheel.isSmooth;
        w.isInertial = wheel.isInertial;
        Slider::mouseWheelMove (e, w);
    }
}
