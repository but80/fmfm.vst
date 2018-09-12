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

#include "VoiceComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
VoiceComponent::VoiceComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (sliderALG = new SlowSlider ("ALG"));
    sliderALG->setTooltip (TRANS("ALG (Algorhythm)"));
    sliderALG->setRange (0, 15, 1);
    sliderALG->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    sliderALG->setTextBoxStyle (Slider::TextBoxBelow, true, 80, 20);
    sliderALG->addListener (this);

    sliderALG->setBounds (0, 16, 80, 104);

    addAndMakeVisible (labelALG = new Label ("ALG",
                                             TRANS("ALG")));
    labelALG->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    labelALG->setJustificationType (Justification::centredBottom);
    labelALG->setEditable (false, false, false);
    labelALG->setColour (TextEditor::textColourId, Colours::black);
    labelALG->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    labelALG->setBounds (0, 0, 80, 16);

    addAndMakeVisible (sliderLFO = new SlowSlider ("LFO"));
    sliderLFO->setTooltip (TRANS("LFO"));
    sliderLFO->setRange (0, 3, 1);
    sliderLFO->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    sliderLFO->setTextBoxStyle (Slider::TextBoxBelow, true, 80, 20);
    sliderLFO->addListener (this);

    sliderLFO->setBounds (0, 144, 80, 104);

    addAndMakeVisible (labelLFO = new Label ("LFO",
                                             TRANS("LFO")));
    labelLFO->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    labelLFO->setJustificationType (Justification::centredBottom);
    labelLFO->setEditable (false, false, false);
    labelLFO->setColour (TextEditor::textColourId, Colours::black);
    labelLFO->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    labelLFO->setBounds (0, 128, 80, 16);

    addAndMakeVisible (sliderPAN = new SlowSlider ("PAN"));
    sliderPAN->setTooltip (TRANS("PAN"));
    sliderPAN->setRange (0, 31, 1);
    sliderPAN->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    sliderPAN->setTextBoxStyle (Slider::TextBoxBelow, true, 80, 20);
    sliderPAN->addListener (this);

    sliderPAN->setBounds (0, 272, 80, 104);

    addAndMakeVisible (labelPAN = new Label ("PAN",
                                             TRANS("PAN")));
    labelPAN->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    labelPAN->setJustificationType (Justification::centredBottom);
    labelPAN->setEditable (false, false, false);
    labelPAN->setColour (TextEditor::textColourId, Colours::black);
    labelPAN->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    labelPAN->setBounds (0, 256, 80, 16);

    addAndMakeVisible (sliderBO = new SlowSlider ("BO"));
    sliderBO->setTooltip (TRANS("BO (Basic Octave)"));
    sliderBO->setRange (0, 3, 1);
    sliderBO->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    sliderBO->setTextBoxStyle (Slider::TextBoxBelow, true, 80, 20);
    sliderBO->addListener (this);

    sliderBO->setBounds (0, 400, 80, 104);

    addAndMakeVisible (labelBO = new Label ("BO",
                                            TRANS("BO")));
    labelBO->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    labelBO->setJustificationType (Justification::centredBottom);
    labelBO->setEditable (false, false, false);
    labelBO->setColour (TextEditor::textColourId, Colours::black);
    labelBO->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    labelBO->setBounds (0, 384, 80, 16);

    addAndMakeVisible (sliderBO2 = new SlowSlider ("BO"));
    sliderBO2->setTooltip (TRANS("BO (Basic Octave)"));
    sliderBO2->setRange (0, 3, 1);
    sliderBO2->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    sliderBO2->setTextBoxStyle (Slider::TextBoxBelow, true, 80, 20);
    sliderBO2->addListener (this);

    sliderBO2->setBounds (0, 400, 80, 104);

    addAndMakeVisible (labelBO2 = new Label ("BO",
                                             TRANS("BO")));
    labelBO2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    labelBO2->setJustificationType (Justification::centredBottom);
    labelBO2->setEditable (false, false, false);
    labelBO2->setColour (TextEditor::textColourId, Colours::black);
    labelBO2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    labelBO2->setBounds (0, 384, 80, 16);

    addAndMakeVisible (operator1 = new OperatorComponent());
    operator1->setBounds (120, 0, 680, 128);

    addAndMakeVisible (operator2 = new OperatorComponent());
    operator2->setBounds (120, 128, 680, 128);

    addAndMakeVisible (operator3 = new OperatorComponent());
    operator3->setBounds (120, 256, 680, 128);

    addAndMakeVisible (operator4 = new OperatorComponent());
    operator4->setBounds (120, 384, 680, 128);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (800, 512);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

VoiceComponent::~VoiceComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    sliderALG = nullptr;
    labelALG = nullptr;
    sliderLFO = nullptr;
    labelLFO = nullptr;
    sliderPAN = nullptr;
    labelPAN = nullptr;
    sliderBO = nullptr;
    labelBO = nullptr;
    sliderBO2 = nullptr;
    labelBO2 = nullptr;
    operator1 = nullptr;
    operator2 = nullptr;
    operator3 = nullptr;
    operator4 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void VoiceComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void VoiceComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void VoiceComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == sliderALG)
    {
        //[UserSliderCode_sliderALG] -- add your slider handling code here..
        printf("ALG = %d\n", int(sliderThatWasMoved->getValue()));
        //[/UserSliderCode_sliderALG]
    }
    else if (sliderThatWasMoved == sliderLFO)
    {
        //[UserSliderCode_sliderLFO] -- add your slider handling code here..
        printf("LFO = %d\n", int(sliderThatWasMoved->getValue()));
        //[/UserSliderCode_sliderLFO]
    }
    else if (sliderThatWasMoved == sliderPAN)
    {
        //[UserSliderCode_sliderPAN] -- add your slider handling code here..
        printf("PAN = %d\n", int(sliderThatWasMoved->getValue()));
        //[/UserSliderCode_sliderPAN]
    }
    else if (sliderThatWasMoved == sliderBO)
    {
        //[UserSliderCode_sliderBO] -- add your slider handling code here..
        printf("BO = %d\n", int(sliderThatWasMoved->getValue()));
        //[/UserSliderCode_sliderBO]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="VoiceComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="800" initialHeight="512">
  <BACKGROUND backgroundColour="ff323e44"/>
  <SLIDER name="ALG" id="f6bcbeef4cdcde84" memberName="sliderALG" virtualName=""
          explicitFocusOrder="0" pos="0 16 80 104" tooltip="ALG (Algorhythm)"
          min="0.00000000000000000000" max="15.00000000000000000000" int="1.00000000000000000000"
          style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <LABEL name="ALG" id="332ddc6c0d5b0572" memberName="labelALG" virtualName=""
         explicitFocusOrder="0" pos="0 0 80 16" edTextCol="ff000000" edBkgCol="0"
         labelText="ALG" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="0" justification="20"/>
  <SLIDER name="LFO" id="3b88e5441bf47812" memberName="sliderLFO" virtualName=""
          explicitFocusOrder="0" pos="0 144 80 104" tooltip="LFO" min="0.00000000000000000000"
          max="3.00000000000000000000" int="1.00000000000000000000" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.00000000000000000000" needsCallback="1"/>
  <LABEL name="LFO" id="31e9c9fc4c814d7b" memberName="labelLFO" virtualName=""
         explicitFocusOrder="0" pos="0 128 80 16" edTextCol="ff000000"
         edBkgCol="0" labelText="LFO" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="0" justification="20"/>
  <SLIDER name="PAN" id="203acbd2c713c24f" memberName="sliderPAN" virtualName=""
          explicitFocusOrder="0" pos="0 272 80 104" tooltip="PAN" min="0.00000000000000000000"
          max="31.00000000000000000000" int="1.00000000000000000000" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.00000000000000000000" needsCallback="1"/>
  <LABEL name="PAN" id="67c1e2e71cc3229f" memberName="labelPAN" virtualName=""
         explicitFocusOrder="0" pos="0 256 80 16" edTextCol="ff000000"
         edBkgCol="0" labelText="PAN" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="0" justification="20"/>
  <SLIDER name="BO" id="a05652be9c7a3d04" memberName="sliderBO" virtualName=""
          explicitFocusOrder="0" pos="0 400 80 104" tooltip="BO (Basic Octave)"
          min="0.00000000000000000000" max="3.00000000000000000000" int="1.00000000000000000000"
          style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <LABEL name="BO" id="22d8840da18bb490" memberName="labelBO" virtualName=""
         explicitFocusOrder="0" pos="0 384 80 16" edTextCol="ff000000"
         edBkgCol="0" labelText="BO" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="0" justification="20"/>
  <SLIDER name="BO" id="f2f80a4113bc13e8" memberName="sliderBO2" virtualName=""
          explicitFocusOrder="0" pos="0 400 80 104" tooltip="BO (Basic Octave)"
          min="0.00000000000000000000" max="3.00000000000000000000" int="1.00000000000000000000"
          style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <LABEL name="BO" id="68bd2675a1bab1c1" memberName="labelBO2" virtualName=""
         explicitFocusOrder="0" pos="0 384 80 16" edTextCol="ff000000"
         edBkgCol="0" labelText="BO" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="0" justification="20"/>
  <JUCERCOMP name="Operator 1" id="da753d7c24b1e550" memberName="operator1"
             virtualName="" explicitFocusOrder="0" pos="120 0 680 128" sourceFile="OperatorComponent.cpp"
             constructorParams=""/>
  <JUCERCOMP name="Operator 2" id="51f042d6365d21a6" memberName="operator2"
             virtualName="" explicitFocusOrder="0" pos="120 128 680 128" sourceFile="OperatorComponent.cpp"
             constructorParams=""/>
  <JUCERCOMP name="Operator 3" id="bc856ef97eee21c9" memberName="operator3"
             virtualName="" explicitFocusOrder="0" pos="120 256 680 128" sourceFile="OperatorComponent.cpp"
             constructorParams=""/>
  <JUCERCOMP name="Operator 4" id="8a380946dcbd5306" memberName="operator4"
             virtualName="" explicitFocusOrder="0" pos="120 384 680 128" sourceFile="OperatorComponent.cpp"
             constructorParams=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
