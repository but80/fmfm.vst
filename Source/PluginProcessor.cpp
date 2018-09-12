/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <dlfcn.h>

void* fmfm;
long long (*FMFMInit)(double sampleRate, char* voicePath);
void (*FMFMFlushMIDIMessages)(long long until);
void (*FMFMNoteOn)(long long timestamp, long long ch, long long note, long long velocity);
void (*FMFMNoteOff)(long long timestamp, long long ch, long long note);
void (*FMFMControlChange)(long long timestamp, long long ch, long long cc, long long value);
void (*FMFMProgramChange)(long long timestamp, long long ch, long long value);
void (*FMFMPitchBend)(long long timestamp, long long ch, long long l, long long h);
typedef struct {
	double r0;
	double r1;
} FMFMNext_return;
FMFMNext_return (*FMFMNext)();

static char voicePath[1024];

//==============================================================================
FmfmAudioProcessor::FmfmAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
    static const char* voicePathRel = "/go/src/gopkg.in/but80/fmfm.core.v1/voice";
    static const char* modulePathRel = "/go/src/gopkg.in/but80/fmfm.core.v1/build/fmfm-module/fmfm.so";
    char modulePath[1024];

    char* gopath = getenv("GOPATH");
    printf("GOPATH = %s\n", gopath);

    char* home = getenv("HOME");
    printf("HOME = %s\n", home);
    strcpy(voicePath, home);
    strcat(voicePath, voicePathRel);
    printf("voicePath = %s\n", voicePath);
    strcpy(modulePath, home);
    strcat(modulePath, modulePathRel);
    printf("modulePath = %s\n", modulePath);

    fmfm = dlopen(modulePath, RTLD_LAZY);
    if (!fmfm) {
        printf("failed to load fmfm.so: %s\n", dlerror());
    } else {
        char* err;

        FMFMInit = (long long (*)(double sampleRate, char* voicePath))dlsym(fmfm, "FMFMInit");
        if ((err = dlerror()) != NULL) printf("failed to dlsym FMFMInit: %s\n", err);

        FMFMFlushMIDIMessages = (void (*)(long long until))dlsym(fmfm, "FMFMFlushMIDIMessages");
        if ((err = dlerror()) != NULL) printf("failed to dlsym FMFMFlushMIDIMessages: %s\n", err);

        FMFMNoteOn = (void (*)(long long timestamp, long long ch, long long note, long long velocity))dlsym(fmfm, "FMFMNoteOn");
        if ((err = dlerror()) != NULL) printf("failed to dlsym FMFMNoteOn: %s\n", err);

        FMFMNoteOff = (void (*)(long long timestamp, long long ch, long long note))dlsym(fmfm, "FMFMNoteOff");
        if ((err = dlerror()) != NULL) printf("failed to dlsym FMFMNoteOff: %s\n", err);

        FMFMControlChange = (void (*)(long long timestamp, long long ch, long long cc, long long value))dlsym(fmfm, "FMFMControlChange");
        if ((err = dlerror()) != NULL) printf("failed to dlsym FMFMControlChange: %s\n", err);

        FMFMProgramChange = (void (*)(long long timestamp, long long ch, long long value))dlsym(fmfm, "FMFMProgramChange");
        if ((err = dlerror()) != NULL) printf("failed to dlsym FMFMProgramChange: %s\n", err);

        FMFMPitchBend = (void (*)(long long timestamp, long long ch, long long l, long long h))dlsym(fmfm, "FMFMPitchBend");
        if ((err = dlerror()) != NULL) printf("failed to dlsym FMFMPitchBend: %s\n", err);

        FMFMNext = (FMFMNext_return (*)())dlsym(fmfm, "FMFMNext");
        if ((err = dlerror()) != NULL) printf("failed to dlsym FMFMNext: %s\n", err);
    }
}

FmfmAudioProcessor::~FmfmAudioProcessor()
{
}

//==============================================================================
const String FmfmAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool FmfmAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool FmfmAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool FmfmAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double FmfmAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int FmfmAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int FmfmAudioProcessor::getCurrentProgram()
{
    return 0;
}

void FmfmAudioProcessor::setCurrentProgram (int index)
{
}

const String FmfmAudioProcessor::getProgramName (int index)
{
    return {};
}

void FmfmAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void FmfmAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void FmfmAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool FmfmAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

// static int debugCounter = 0;

void FmfmAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    // int totalNumInputChannels  = getTotalNumInputChannels();
    // int totalNumOutputChannels = getTotalNumOutputChannels();
    float* outL = buffer.getWritePointer(0);
    float* outR = buffer.getWritePointer(1);
    int samples = buffer.getNumSamples();
    double sampleRate = getSampleRate();

    if (FMFMInit(sampleRate, voicePath)) {
        printf("fmFM initialized @ %f Hz, voice = %s\n", sampleRate, voicePath);
    }

    MidiBuffer::Iterator itr(midiMessages);
    MidiMessage midiMsg(0);
    int midiPos;
    while (itr.getNextEvent(midiMsg, midiPos)) {
        if (midiMsg.isNoteOn()) {
            // printf("FMFMNoteOn(0, %d, %d)\n", midiMsg.getNoteNumber(), midiMsg.getVelocity());
            FMFMNoteOn(0, 0, midiMsg.getNoteNumber(), midiMsg.getVelocity());
        } else {
            // printf("FMFMNoteOff(0, %d)\n", midiMsg.getNoteNumber());
            FMFMNoteOff(0, 0, midiMsg.getNoteNumber());
        }
	}
    FMFMFlushMIDIMessages(1);

    for (int i = 0; i < samples; i++) {
        FMFMNext_return next = FMFMNext();
        outL[i] = float(next.r0);
        outR[i] = float(next.r1);
        // if (i == 0 && ++debugCounter % 100 == 0) {
        //     printf("FMFMNext %f\n", float(next.r0));
        // }
    }
}

//==============================================================================
bool FmfmAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* FmfmAudioProcessor::createEditor()
{
    return new FmfmAudioProcessorEditor (*this);
}

//==============================================================================
void FmfmAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void FmfmAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new FmfmAudioProcessor();
}
