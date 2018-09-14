/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.3.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class OperatorComponent  : public Component,
                           public Slider::Listener,
                           public Button::Listener
{
public:
    //==============================================================================
    OperatorComponent ();
    ~OperatorComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> sliderMulti;
    ScopedPointer<Slider> sliderDT;
    ScopedPointer<Slider> sliderWS;
    ScopedPointer<Slider> sliderFB;
    ScopedPointer<Slider> sliderTL;
    ScopedPointer<Slider> sliderKSL;
    ScopedPointer<ToggleButton> toggleKSR;
    ScopedPointer<ToggleButton> toggleXOF;
    ScopedPointer<ToggleButton> toggleSUS;
    ScopedPointer<ToggleButton> toggleEAM;
    ScopedPointer<ToggleButton> toggleEVB;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OperatorComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
