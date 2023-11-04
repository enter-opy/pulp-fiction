/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

#define SLOTONE_ID "slot1"
#define SLOTONE_NAME "Slot1"

#define SLOTTWO_ID "slot2"
#define SLOTTWO_NAME "Slot2"

#define SLOTTHREE_ID "slot3"
#define SLOTTHREE_NAME "Slot3"

#define SLOTFOUR_ID "slot4"
#define SLOTFOUR_NAME "Slot4"

#define CDEPTH1_ID "chorusdepth1"
#define CDEPTH1_NAME "Depth"

#define CVOICES1_ID "chorusvoices1"
#define CVOICES1_NAME "Voices"

#define CDEPTH2_ID "chorusdepth2"
#define CDEPTH2_NAME "Depth"

#define CVOICES2_ID "chorusvoices2"
#define CVOICES2_NAME "Voices"

#define CDEPTH3_ID "chorusdepth3"
#define CDEPTH3_NAME "Depth"

#define CVOICES3_ID "chorusvoices3"
#define CVOICES3_NAME "Voices"

#define CDEPTH4_ID "chorusdepth4"
#define CDEPTH4_NAME "Depth"

#define CVOICES4_ID "chorusvoices4"
#define CVOICES4_NAME "Voices"

#define TIME1_ID "time1"
#define TIME1_NAME "Time"

#define FEEDBACK1_ID "feedback1"
#define FEEDBACK1_NAME "Feedback"

#define TIME2_ID "time2"
#define TIME2_NAME "Time"

#define FEEDBACK2_ID "feedback2"
#define FEEDBACK2_NAME "Feedback"

#define TIME3_ID "time3"
#define TIME3_NAME "Time"

#define FEEDBACK3_ID "feedback3"
#define FEEDBACK3_NAME "Feedback"

#define TIME4_ID "time4"
#define TIME4_NAME "Time"

#define FEEDBACK4_ID "feedback4"
#define FEEDBACK4_NAME "Feedback"

#define FDEPTH1_ID "flangerdepth1"
#define FDEPTH1_NAME "Depth"

#define FRATE1_ID "flangerrate1"
#define FRATE1_NAME "Rate"

#define FDEPTH2_ID "flangerdepth2"
#define FDEPTH2_NAME "Depth"

#define FRATE2_ID "flangerrate2"
#define FRATE2_NAME "Rate"

#define FDEPTH3_ID "flangerdepth3"
#define FDEPTH3_NAME "Depth"

#define FRATE3_ID "flangerrate3"
#define FRATE3_NAME "Rate"

#define FDEPTH4_ID "flangerdepth4"
#define FDEPTH4_NAME "Depth"

#define FRATE4_ID "flangerrate4"
#define FRATE4_NAME "Rate"

#define VDEPTH1_ID "vibratodepth1"
#define VDEPTH1_NAME "Depth"

#define VRATE1_ID "vibratorate1"
#define VRATE1_NAME "Rate"

#define VDEPTH2_ID "vibratodepth2"
#define VDEPTH2_NAME "Depth"

#define VRATE2_ID "vibratorate2"
#define VRATE2_NAME "Rate"

#define VDEPTH3_ID "vibratodepth3"
#define VDEPTH3_NAME "Depth"

#define VRATE3_ID "vibratorate3"
#define VRATE3_NAME "Rate"

#define VDEPTH4_ID "vibratodepth4"
#define VDEPTH4_NAME "Depth"

#define VRATE4_ID "vibratorate4"
#define VRATE4_NAME "Rate"

#define CMIX1_ID "chorusmix1"
#define CMIX1_NAME "Mix"

#define CMIX2_ID "chorusmix2"
#define CMIX2_NAME "Mix"

#define CMIX3_ID "chorusmix3"
#define CMIX3_NAME "Mix"

#define CMIX4_ID "chorusmix4"
#define CMIX4_NAME "Mix"

#define DMIX1_ID "delaymix1"
#define DMIX1_NAME "Mix"

#define DMIX2_ID "delaymix2"
#define DMIX2_NAME "Mix"

#define DMIX3_ID "delaymix3"
#define DMIX3_NAME "Mix"

#define DMIX4_ID "delaymix4"
#define DMIX4_NAME "Mix"

#define FMIX1_ID "flangermix1"
#define FMIX1_NAME "Mix"

#define FMIX2_ID "flangermix2"
#define FMIX2_NAME "Mix"

#define FMIX3_ID "flangermix3"
#define FMIX3_NAME "Mix"

#define FMIX4_ID "flangermix4"
#define FMIX4_NAME "Mix"

#define VMIX1_ID "vibratomix1"
#define VMIX1_NAME "Mix"

#define VMIX2_ID "vibratomix2"
#define VMIX2_NAME "Mix"

#define VMIX3_ID "vibratomix3"
#define VMIX3_NAME "Mix"

#define VMIX4_ID "vibratomix4"
#define VMIX4_NAME "Mix"

//==============================================================================
/**
*/
class PulpfictionAudioProcessor  : public juce::AudioProcessor
                            #if JucePlugin_Enable_ARA
                             , public juce::AudioProcessorARAExtension
                            #endif
{
public:
    //==============================================================================
    PulpfictionAudioProcessor();
    ~PulpfictionAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    float getValue(char*);

    void chorusOne(juce::AudioBuffer<float>&);
    void chorusTwo(juce::AudioBuffer<float>&);
    void chorusThree(juce::AudioBuffer<float>&);
    void chorusFour(juce::AudioBuffer<float>&);

    void delayOne(juce::AudioBuffer<float>&);
    void delayTwo(juce::AudioBuffer<float>&);
    void delayThree(juce::AudioBuffer<float>&);
    void delayFour(juce::AudioBuffer<float>&);

    void flangerOne(juce::AudioBuffer<float>&);
    void flangerTwo(juce::AudioBuffer<float>&);
    void flangerThree(juce::AudioBuffer<float>&);
    void flangerFour(juce::AudioBuffer<float>&);

    void vibratoOne(juce::AudioBuffer<float>&);
    void vibratoTwo(juce::AudioBuffer<float>&);
    void vibratoThree(juce::AudioBuffer<float>&);
    void vibratoFour(juce::AudioBuffer<float>&);

    AudioProcessorValueTreeState treeState;

private:
    AudioSampleBuffer chorusBufferOneVoice1;
    AudioSampleBuffer chorusBufferOneVoice2;
    AudioSampleBuffer chorusBufferOneVoice3;

    AudioSampleBuffer chorusBufferTwoVoice1;
    AudioSampleBuffer chorusBufferTwoVoice2;
    AudioSampleBuffer chorusBufferTwoVoice3;

    AudioSampleBuffer chorusBufferThreeVoice1;
    AudioSampleBuffer chorusBufferThreeVoice2;
    AudioSampleBuffer chorusBufferThreeVoice3;

    AudioSampleBuffer chorusBufferFourVoice1;
    AudioSampleBuffer chorusBufferFourVoice2;
    AudioSampleBuffer chorusBufferFourVoice3;

    AudioSampleBuffer delayBufferOne;
    AudioSampleBuffer delayBufferTwo;
    AudioSampleBuffer delayBufferThree;
    AudioSampleBuffer delayBufferFour;

    AudioSampleBuffer flangerBufferOne;
    AudioSampleBuffer flangerBufferTwo;
    AudioSampleBuffer flangerBufferThree;
    AudioSampleBuffer flangerBufferFour;

    AudioSampleBuffer vibratoBufferOne;
    AudioSampleBuffer vibratoBufferTwo;
    AudioSampleBuffer vibratoBufferThree;
    AudioSampleBuffer vibratoBufferFour;

    int slotOne;
    int slotTwo;
    int slotThree;
    int slotFour;

    int cpw1v1[2];
    int cpw1v2[2];
    int cpw1v3[2];

    int cpw2v1[2];
    int cpw2v2[2];
    int cpw2v3[2];

    int cpw3v1[2];
    int cpw3v2[2];
    int cpw3v3[2];

    int cpw4v1[2];
    int cpw4v2[2];
    int cpw4v3[2];

    float cph1[2];
    float cph2[2];
    float cph3[2];
    float cph4[2];

    int dpr1[2], dpw1[2];
    int dpr2[2], dpw2[2];
    int dpr3[2], dpw3[2];
    int dpr4[2], dpw4[2];

    int fpw1[2];
    float fph1[2];
    int fpw2[2];
    float fph2[2];
    int fpw3[2];
    float fph3[2];
    int fpw4[2];
    float fph4[2];

    int vpw1[2];
    float vph1[2];
    int vpw2[2];
    float vph2[2];
    int vpw3[2];
    float vph3[2];
    int vpw4[2];
    float vph4[2];

    float chorusOneDepth;
    float chorusOneVoices;
    float chorusTwoDepth;
    float chorusTwoVoices;
    float chorusThreeDepth;
    float chorusThreeVoices;
    float chorusFourDepth;
    float chorusFourVoices;

    float delayOneTime;
    float delayOneFeedback;
    float delayTwoTime;
    float delayTwoFeedback;
    float delayThreeTime;
    float delayThreeFeedback;
    float delayFourTime;
    float delayFourFeedback;

    float flangerOneDepth;
    float flangerOneRate;
    float flangerTwoDepth;
    float flangerTwoRate;
    float flangerThreeDepth;
    float flangerThreeRate;
    float flangerFourDepth;
    float flangerFourRate;

    float vibratoOneDepth;
    float vibratoOneRate;
    float vibratoTwoDepth;
    float vibratoTwoRate;
    float vibratoThreeDepth;
    float vibratoThreeRate;
    float vibratoFourDepth;
    float vibratoFourRate;

    float chorusOneMix;
    float chorusTwoMix;
    float chorusThreeMix;
    float chorusFourMix;

    float delayOneMix;
    float delayTwoMix;
    float delayThreeMix;
    float delayFourMix;

    float flangerOneMix;
    float flangerTwoMix;
    float flangerThreeMix;
    float flangerFourMix;

    float vibratoOneMix;
    float vibratoTwoMix;
    float vibratoThreeMix;
    float vibratoFourMix;

    AudioPlayHead* playHead;
    AudioPlayHead::CurrentPositionInfo currentPositionInfo;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PulpfictionAudioProcessor)
};
