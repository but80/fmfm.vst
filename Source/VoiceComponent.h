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

#include "OperatorComponent.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class VoiceComponent  : public Component,
                        public Slider::Listener
{
public:
    //==============================================================================
    VoiceComponent ();
    ~VoiceComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> sliderALG;
    ScopedPointer<Label> labelALG;
    ScopedPointer<Slider> sliderLFO;
    ScopedPointer<Label> labelLFO;
    ScopedPointer<Slider> sliderPAN;
    ScopedPointer<Label> labelPAN;
    ScopedPointer<Slider> sliderBO;
    ScopedPointer<Label> labelBO;
    ScopedPointer<OperatorComponent> operator1;
    ScopedPointer<OperatorComponent> operator2;
    ScopedPointer<OperatorComponent> operator3;
    ScopedPointer<OperatorComponent> operator4;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VoiceComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
