/*
  ==============================================================================

    SlowSlider.h
    Created: 11 Sep 2018 5:08:08pm
    Author:  ken

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class SlowSlider : public Slider
{
public:
    SlowSlider();
    explicit SlowSlider (const String& componentName);
    SlowSlider (SliderStyle style, TextEntryBoxPosition textBoxPosition);
    ~SlowSlider();
    double snapValue (double attemptedValue, DragMode dragMode);
    void mouseWheelMove (const MouseEvent& e, const MouseWheelDetails& wheel);

private:
    float cx = .0;
    float cy = .0;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SlowSlider)
};
