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
//[/Headers]

#include "RootComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
RootComponent::RootComponent (FmfmAudioProcessor& p)
    : processor(p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (voiceComponent = new VoiceComponent());
    voiceComponent->setBounds (0, 56, 800, 456);

    addAndMakeVisible (bankLSBCombo = new ComboBox ("Bank LSB"));
    bankLSBCombo->setTooltip (TRANS("Bank LSB"));
    bankLSBCombo->setEditableText (false);
    bankLSBCombo->setJustificationType (Justification::centredLeft);
    bankLSBCombo->setTextWhenNothingSelected (String());
    bankLSBCombo->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    bankLSBCombo->addListener (this);

    bankLSBCombo->setBounds (80, 8, 64, 24);

    addAndMakeVisible (bankMSBCombo = new ComboBox ("Bank MSB"));
    bankMSBCombo->setTooltip (TRANS("Bank MSB"));
    bankMSBCombo->setEditableText (false);
    bankMSBCombo->setJustificationType (Justification::centredLeft);
    bankMSBCombo->setTextWhenNothingSelected (String());
    bankMSBCombo->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    bankMSBCombo->addListener (this);

    bankMSBCombo->setBounds (8, 8, 64, 24);

    addAndMakeVisible (pcCombo = new ComboBox ("PC"));
    pcCombo->setTooltip (TRANS("PC (Program Change)"));
    pcCombo->setEditableText (false);
    pcCombo->setJustificationType (Justification::centredLeft);
    pcCombo->setTextWhenNothingSelected (String());
    pcCombo->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    pcCombo->addListener (this);

    pcCombo->setBounds (152, 8, 320, 24);

    addAndMakeVisible (reloadButton = new TextButton ("reload"));
    reloadButton->setTooltip (TRANS("Reload"));
    reloadButton->setButtonText (TRANS("Reload"));
    reloadButton->addListener (this);

    reloadButton->setBounds (728, 8, 54, 24);

    addAndMakeVisible (drumNoteCombo = new ComboBox ("Drum Note"));
    drumNoteCombo->setTooltip (TRANS("Drum Note"));
    drumNoteCombo->setEditableText (false);
    drumNoteCombo->setJustificationType (Justification::centredLeft);
    drumNoteCombo->setTextWhenNothingSelected (String());
    drumNoteCombo->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    drumNoteCombo->addListener (this);

    drumNoteCombo->setBounds (480, 8, 112, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (800, 512);


    //[Constructor] You can add your own custom stuff here..
    bankMSBCombo->onChange = [this] { updateLSBCombo(); };
    bankLSBCombo->onChange = [this] { updatePCCombo(); };
    pcCombo->onChange = [this] { updateDrumNoteCombo(); };
    drumNoteCombo->onChange = [this] { updateVoiceComponent(); };
    updateMSBCombo();
    //[/Constructor]
}

RootComponent::~RootComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    voiceComponent = nullptr;
    bankLSBCombo = nullptr;
    bankMSBCombo = nullptr;
    pcCombo = nullptr;
    reloadButton = nullptr;
    drumNoteCombo = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void RootComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void RootComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void RootComponent::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == bankLSBCombo)
    {
        //[UserComboBoxCode_bankLSBCombo] -- add your combo box handling code here..
        //[/UserComboBoxCode_bankLSBCombo]
    }
    else if (comboBoxThatHasChanged == bankMSBCombo)
    {
        //[UserComboBoxCode_bankMSBCombo] -- add your combo box handling code here..
        //[/UserComboBoxCode_bankMSBCombo]
    }
    else if (comboBoxThatHasChanged == pcCombo)
    {
        //[UserComboBoxCode_pcCombo] -- add your combo box handling code here..
        //[/UserComboBoxCode_pcCombo]
    }
    else if (comboBoxThatHasChanged == drumNoteCombo)
    {
        //[UserComboBoxCode_drumNoteCombo] -- add your combo box handling code here..
        //[/UserComboBoxCode_drumNoteCombo]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void RootComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == reloadButton)
    {
        //[UserButtonCode_reloadButton] -- add your button handler code here..

        updateMSBCombo();

        //[/UserButtonCode_reloadButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void RootComponent::updateMSBCombo ()
{
    bankMSBCombo->clear(dontSendNotification);
    long long msbList[128];
    auto msbListLen = processor.listBankMSB(msbList);
    if (0 < msbListLen) {
        for (int i=0; i < msbListLen; i++) {
            auto msb = int(msbList[i]);
            char msbstr[255];
            sprintf(msbstr, "%3d", msb);
            bankMSBCombo->addItem(msbstr, i+1);
        }
        bankMSBCombo->setSelectedId (1);
    }
}

void RootComponent::updateLSBCombo ()
{
    auto msb = bankMSBCombo->getText().getIntValue();
    bankLSBCombo->clear(dontSendNotification);
    long long lsbList[128];
    auto lsbListLen = processor.listBankLSB(lsbList, msb);
    if (0 < lsbListLen) {
        for (int i=0; i < lsbListLen; i++) {
            auto lsb = int(lsbList[i]);
            char lsbstr[255];
            sprintf(lsbstr, "%3d", lsb);
            bankLSBCombo->addItem(lsbstr, i+1);
        }
        bankLSBCombo->setSelectedId (1);
    }
}

void RootComponent::updatePCCombo ()
{
    auto msb = bankMSBCombo->getText().getIntValue();
    auto lsb = bankLSBCombo->getText().getIntValue();
    pcCombo->clear(dontSendNotification);
    long long pcList[128];
    auto pcListLen = processor.listPC(pcList, msb, lsb);
    if (0 < pcListLen) {
        for (int i=0; i < pcListLen; i++) {
            auto pc = int(pcList[i]);
            char pcstr[255];
            sprintf(pcstr, "%3d", pc);
            pcCombo->addItem(pcstr, i+1);
        }
        pcCombo->setSelectedId (1);
    }
}

void RootComponent::updateDrumNoteCombo ()
{
    auto msb = bankMSBCombo->getText().getIntValue();
    auto lsb = bankLSBCombo->getText().getIntValue();
    auto pc = pcCombo->getText().getIntValue();
    drumNoteCombo->clear(dontSendNotification);
    long long drumNoteList[128];
    auto drumNoteListLen = processor.listDrumNote(drumNoteList, msb, lsb, pc);
    if (0 < drumNoteListLen) {
        for (int i=0; i < drumNoteListLen; i++) {
            auto drumNote = int(drumNoteList[i]);
            char drumNoteStr[255];
            sprintf(drumNoteStr, "%3d", drumNote);
            drumNoteCombo->addItem(drumNoteStr, i+1);
        }
        drumNoteCombo->setSelectedId (1);
    }
}

void RootComponent::updateVoiceComponent ()
{
    auto msb = bankMSBCombo->getText().getIntValue();
    auto lsb = bankLSBCombo->getText().getIntValue();
    auto pc = pcCombo->getText().getIntValue();
    auto drumNote = drumNoteCombo->getText().getIntValue();
    unsigned char buf[4096];
    auto n = processor.getVoice(buf, msb, lsb, pc, drumNote);
    for (int i=0; i<n; i++) {
        if (i%16==0) printf("\n%04x:", i);
        printf(" %02x", buf[i]);
    }
    printf("\n");
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="RootComponent" componentName=""
                 parentClasses="public Component" constructorParams="FmfmAudioProcessor&amp; p"
                 variableInitialisers="processor(p)" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="800"
                 initialHeight="512">
  <BACKGROUND backgroundColour="ff323e44"/>
  <JUCERCOMP name="" id="444f5f92a7b4bebf" memberName="voiceComponent" virtualName=""
             explicitFocusOrder="0" pos="0 56 800 456" sourceFile="VoiceComponent.cpp"
             constructorParams=""/>
  <COMBOBOX name="Bank LSB" id="ca5cc2527dda09bd" memberName="bankLSBCombo"
            virtualName="" explicitFocusOrder="0" pos="80 8 64 24" tooltip="Bank LSB"
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="Bank MSB" id="d5ed1b3232013e8c" memberName="bankMSBCombo"
            virtualName="" explicitFocusOrder="0" pos="8 8 64 24" tooltip="Bank MSB"
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="PC" id="88f1d8b760ac5f57" memberName="pcCombo" virtualName=""
            explicitFocusOrder="0" pos="152 8 320 24" tooltip="PC (Program Change)"
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <TEXTBUTTON name="reload" id="3f1d935dbdf08f58" memberName="reloadButton"
              virtualName="" explicitFocusOrder="0" pos="728 8 54 24" tooltip="Reload"
              buttonText="Reload" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <COMBOBOX name="Drum Note" id="12a572abdb9f0115" memberName="drumNoteCombo"
            virtualName="" explicitFocusOrder="0" pos="480 8 112 24" tooltip="Drum Note"
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
