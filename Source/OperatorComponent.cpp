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

//[Headers] You can add your own extra header files here...
#include "SlowSlider.h"
//[/Headers]

#include "OperatorComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
OperatorComponent::OperatorComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (sliderMulti = new SlowSlider ("Multi"));
    sliderMulti->setTooltip (TRANS("Multi (Multiplier)"));
    sliderMulti->setRange (0, 15, 1);
    sliderMulti->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    sliderMulti->setTextBoxStyle (Slider::TextBoxBelow, true, 80, 20);
    sliderMulti->addListener (this);

    sliderMulti->setBounds (0, 0, 80, 104);

    addAndMakeVisible (sliderDT = new SlowSlider ("DT"));
    sliderDT->setTooltip (TRANS("DT (Detune)"));
    sliderDT->setRange (0, 7, 1);
    sliderDT->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    sliderDT->setTextBoxStyle (Slider::TextBoxBelow, true, 80, 20);
    sliderDT->addListener (this);

    sliderDT->setBounds (80, 0, 80, 104);

    addAndMakeVisible (sliderWS = new SlowSlider ("WS"));
    sliderWS->setTooltip (TRANS("WS (Waveshape)"));
    sliderWS->setRange (0, 31, 1);
    sliderWS->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    sliderWS->setTextBoxStyle (Slider::TextBoxBelow, true, 80, 20);
    sliderWS->addListener (this);

    sliderWS->setBounds (160, 0, 80, 104);

    addAndMakeVisible (sliderFB = new SlowSlider ("FB"));
    sliderFB->setTooltip (TRANS("FB (Feedback)"));
    sliderFB->setRange (0, 7, 1);
    sliderFB->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    sliderFB->setTextBoxStyle (Slider::TextBoxBelow, true, 80, 20);
    sliderFB->addListener (this);

    sliderFB->setBounds (400, 0, 80, 104);

    addAndMakeVisible (sliderTL = new SlowSlider ("TL"));
    sliderTL->setTooltip (TRANS("TL (Total Level)"));
    sliderTL->setRange (0, 63, 1);
    sliderTL->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    sliderTL->setTextBoxStyle (Slider::TextBoxBelow, true, 80, 20);
    sliderTL->addListener (this);

    sliderTL->setBounds (240, 0, 80, 104);

    addAndMakeVisible (sliderKSL = new SlowSlider ("KSL"));
    sliderKSL->setTooltip (TRANS("KSL (Key Scaling Level)"));
    sliderKSL->setRange (0, 3, 1);
    sliderKSL->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    sliderKSL->setTextBoxStyle (Slider::TextBoxBelow, true, 80, 20);
    sliderKSL->addListener (this);

    sliderKSL->setBounds (320, 0, 80, 104);

    addAndMakeVisible (toggleKSR = new ToggleButton ("KSR"));
    toggleKSR->setTooltip (TRANS("KSR (Key Scaling Rate)"));
    toggleKSR->addListener (this);

    toggleKSR->setBounds (488, 40, 80, 32);

    addAndMakeVisible (toggleXOF = new ToggleButton ("XOF"));
    toggleXOF->setTooltip (TRANS("XOF (Ignore Keyoff)"));
    toggleXOF->addListener (this);

    toggleXOF->setBounds (488, 8, 80, 32);

    addAndMakeVisible (toggleSUS = new ToggleButton ("SUS"));
    toggleSUS->setTooltip (TRANS("SUS (Keep Sustain Rate)"));
    toggleSUS->addListener (this);

    toggleSUS->setBounds (488, 72, 80, 32);

    addAndMakeVisible (toggleEAM = new ToggleButton ("EAM"));
    toggleEAM->setTooltip (TRANS("EAM (Enable Amplitude Modulation)"));
    toggleEAM->addListener (this);

    toggleEAM->setBounds (576, 40, 80, 32);

    addAndMakeVisible (toggleEVB = new ToggleButton ("EVB"));
    toggleEVB->setTooltip (TRANS("EVB (Enable Vibrato)"));
    toggleEVB->addListener (this);

    toggleEVB->setBounds (576, 72, 80, 32);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (680, 104);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

OperatorComponent::~OperatorComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    sliderMulti = nullptr;
    sliderDT = nullptr;
    sliderWS = nullptr;
    sliderFB = nullptr;
    sliderTL = nullptr;
    sliderKSL = nullptr;
    toggleKSR = nullptr;
    toggleXOF = nullptr;
    toggleSUS = nullptr;
    toggleEAM = nullptr;
    toggleEVB = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void OperatorComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void OperatorComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void OperatorComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == sliderMulti)
    {
        //[UserSliderCode_sliderMulti] -- add your slider handling code here..
        //[/UserSliderCode_sliderMulti]
    }
    else if (sliderThatWasMoved == sliderDT)
    {
        //[UserSliderCode_sliderDT] -- add your slider handling code here..
        //[/UserSliderCode_sliderDT]
    }
    else if (sliderThatWasMoved == sliderWS)
    {
        //[UserSliderCode_sliderWS] -- add your slider handling code here..
        //[/UserSliderCode_sliderWS]
    }
    else if (sliderThatWasMoved == sliderFB)
    {
        //[UserSliderCode_sliderFB] -- add your slider handling code here..
        //[/UserSliderCode_sliderFB]
    }
    else if (sliderThatWasMoved == sliderTL)
    {
        //[UserSliderCode_sliderTL] -- add your slider handling code here..
        //[/UserSliderCode_sliderTL]
    }
    else if (sliderThatWasMoved == sliderKSL)
    {
        //[UserSliderCode_sliderKSL] -- add your slider handling code here..
        //[/UserSliderCode_sliderKSL]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void OperatorComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == toggleKSR)
    {
        //[UserButtonCode_toggleKSR] -- add your button handler code here..
        //[/UserButtonCode_toggleKSR]
    }
    else if (buttonThatWasClicked == toggleXOF)
    {
        //[UserButtonCode_toggleXOF] -- add your button handler code here..
        //[/UserButtonCode_toggleXOF]
    }
    else if (buttonThatWasClicked == toggleSUS)
    {
        //[UserButtonCode_toggleSUS] -- add your button handler code here..
        //[/UserButtonCode_toggleSUS]
    }
    else if (buttonThatWasClicked == toggleEAM)
    {
        //[UserButtonCode_toggleEAM] -- add your button handler code here..
        //[/UserButtonCode_toggleEAM]
    }
    else if (buttonThatWasClicked == toggleEVB)
    {
        //[UserButtonCode_toggleEVB] -- add your button handler code here..
        //[/UserButtonCode_toggleEVB]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="OperatorComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="680" initialHeight="104">
  <BACKGROUND backgroundColour="ff323e44"/>
  <SLIDER name="Multi" id="a05652be9c7a3d04" memberName="sliderMulti" virtualName=""
          explicitFocusOrder="0" pos="0 0 80 104" tooltip="Multi (Multiplier)"
          min="0.00000000000000000000" max="15.00000000000000000000" int="1.00000000000000000000"
          style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <SLIDER name="DT" id="429dbb6772b62ee7" memberName="sliderDT" virtualName=""
          explicitFocusOrder="0" pos="80 0 80 104" tooltip="DT (Detune)"
          min="0.00000000000000000000" max="7.00000000000000000000" int="1.00000000000000000000"
          style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <SLIDER name="WS" id="1c26170dced738b3" memberName="sliderWS" virtualName=""
          explicitFocusOrder="0" pos="160 0 80 104" tooltip="WS (Waveshape)"
          min="0.00000000000000000000" max="31.00000000000000000000" int="1.00000000000000000000"
          style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <SLIDER name="FB" id="fea8f5a795433b83" memberName="sliderFB" virtualName=""
          explicitFocusOrder="0" pos="400 0 80 104" tooltip="FB (Feedback)"
          min="0.00000000000000000000" max="7.00000000000000000000" int="1.00000000000000000000"
          style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <SLIDER name="TL" id="20c33b9b64806bed" memberName="sliderTL" virtualName=""
          explicitFocusOrder="0" pos="240 0 80 104" tooltip="TL (Total Level)"
          min="0.00000000000000000000" max="63.00000000000000000000" int="1.00000000000000000000"
          style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <SLIDER name="KSL" id="647b332745587f9f" memberName="sliderKSL" virtualName=""
          explicitFocusOrder="0" pos="320 0 80 104" tooltip="KSL (Key Scaling Level)"
          min="0.00000000000000000000" max="3.00000000000000000000" int="1.00000000000000000000"
          style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <TOGGLEBUTTON name="KSR" id="5ab7d7f7fadb9aa5" memberName="toggleKSR" virtualName=""
                explicitFocusOrder="0" pos="488 40 80 32" tooltip="KSR (Key Scaling Rate)"
                buttonText="KSR" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="XOF" id="8b4cbfc38aedc256" memberName="toggleXOF" virtualName=""
                explicitFocusOrder="0" pos="488 8 80 32" tooltip="XOF (Ignore Keyoff)"
                buttonText="XOF" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="SUS" id="c32ffba77e72bdbb" memberName="toggleSUS" virtualName=""
                explicitFocusOrder="0" pos="488 72 80 32" tooltip="SUS (Keep Sustain Rate)"
                buttonText="SUS" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="EAM" id="35c6822a161d3ba1" memberName="toggleEAM" virtualName=""
                explicitFocusOrder="0" pos="576 40 80 32" tooltip="EAM (Enable Amplitude Modulation)"
                buttonText="EAM" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="EVB" id="df48298a16b33f6c" memberName="toggleEVB" virtualName=""
                explicitFocusOrder="0" pos="576 72 80 32" tooltip="EVB (Enable Vibrato)"
                buttonText="EVB" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
