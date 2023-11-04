/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PulpfictionAudioProcessor::PulpfictionAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       ),
    treeState(*this, nullptr, "PARAMETER",
        {
            std::make_unique<AudioParameterInt>(SLOTONE_ID, SLOTONE_NAME, 1, 5, 1),
            std::make_unique<AudioParameterInt>(SLOTTWO_ID, SLOTTWO_NAME, 1, 5, 1),
            std::make_unique<AudioParameterInt>(SLOTTHREE_ID, SLOTTHREE_NAME, 1, 5, 1),
            std::make_unique<AudioParameterInt>(SLOTFOUR_ID, SLOTFOUR_NAME, 1, 5, 1),

            std::make_unique<AudioParameterFloat>(CDEPTH1_ID, CDEPTH1_NAME, 20.0, 30.0, 25.0),
            std::make_unique<AudioParameterInt>(CVOICES1_ID, CVOICES1_NAME, 1, 3, 1),
            std::make_unique<AudioParameterFloat>(CDEPTH2_ID, CDEPTH2_NAME, 20.0, 30.0, 25.0),
            std::make_unique<AudioParameterInt>(CVOICES2_ID, CVOICES2_NAME, 1, 3, 1),
            std::make_unique<AudioParameterFloat>(CDEPTH3_ID, CDEPTH3_NAME, 20.0, 30.0, 25.0),
            std::make_unique<AudioParameterInt>(CVOICES3_ID, CVOICES3_NAME, 1, 3, 1),
            std::make_unique<AudioParameterFloat>(CDEPTH4_ID, CDEPTH4_NAME, 20.0, 30.0, 25.0),
            std::make_unique<AudioParameterInt>(CVOICES4_ID, CVOICES4_NAME, 1, 3, 1),

            std::make_unique<AudioParameterFloat>(TIME1_ID, TIME1_NAME, 0.0, 100.0, 0.0),
            std::make_unique<AudioParameterFloat>(FEEDBACK1_ID, FEEDBACK1_NAME, 0.0, 100.0, 50.0),
            std::make_unique<AudioParameterFloat>(TIME2_ID, TIME2_NAME, 0.0, 100.0, 0.0),
            std::make_unique<AudioParameterFloat>(FEEDBACK2_ID, FEEDBACK2_NAME, 0.0, 100.0, 50.0),
            std::make_unique<AudioParameterFloat>(TIME3_ID, TIME3_NAME, 0.0, 100.0, 0.0),
            std::make_unique<AudioParameterFloat>(FEEDBACK3_ID, FEEDBACK3_NAME, 0.0, 100.0, 50.0),
            std::make_unique<AudioParameterFloat>(TIME4_ID, TIME4_NAME, 0.0, 100.0, 0.0),
            std::make_unique<AudioParameterFloat>(FEEDBACK4_ID, FEEDBACK4_NAME, 0.0, 100.0, 50.0),

            std::make_unique<AudioParameterFloat>(FDEPTH1_ID, FDEPTH1_NAME, 0.0, 10.0, 1.0),
            std::make_unique<AudioParameterFloat>(FRATE1_ID, FRATE1_NAME, 1.0, 10.0, 1.0),
            std::make_unique<AudioParameterFloat>(FDEPTH2_ID, FDEPTH2_NAME, 0.0, 10.0, 1.0),
            std::make_unique<AudioParameterFloat>(FRATE2_ID, FRATE2_NAME, 1.0, 10.0, 1.0),
            std::make_unique<AudioParameterFloat>(FDEPTH3_ID, FDEPTH3_NAME, 0.0, 10.0, 1.0),
            std::make_unique<AudioParameterFloat>(FRATE3_ID, FRATE3_NAME, 1.0, 10.0, 1.0),
            std::make_unique<AudioParameterFloat>(FDEPTH4_ID, FDEPTH4_NAME, 0.0, 10.0, 1.0),
            std::make_unique<AudioParameterFloat>(FRATE4_ID, FRATE4_NAME, 1.0, 10.0, 1.0),

            std::make_unique<AudioParameterFloat>(VDEPTH1_ID, VDEPTH1_NAME, 0.0, 10.0, 1.0),
            std::make_unique<AudioParameterFloat>(VRATE1_ID, VRATE1_NAME, 0.1, 10.0, 0.1),
            std::make_unique<AudioParameterFloat>(VDEPTH2_ID, VDEPTH2_NAME, 0.0, 10.0, 1.0),
            std::make_unique<AudioParameterFloat>(VRATE2_ID, VRATE2_NAME, 0.1, 10.0, 0.1),
            std::make_unique<AudioParameterFloat>(VDEPTH3_ID, VDEPTH3_NAME, 0.0, 10.0, 1.0),
            std::make_unique<AudioParameterFloat>(VRATE3_ID, VRATE3_NAME, 0.1, 10.0, 0.1),
            std::make_unique<AudioParameterFloat>(VDEPTH4_ID, VDEPTH4_NAME, 0.0, 10.0, 1.0),
            std::make_unique<AudioParameterFloat>(VRATE4_ID, VRATE4_NAME, 0.1, 10.0, 0.1),

            std::make_unique<AudioParameterFloat>(CMIX1_ID, CMIX1_NAME, 0.0, 100.0, 100.0),
            std::make_unique<AudioParameterFloat>(CMIX2_ID, CMIX2_NAME, 0.0, 100.0, 100.0),
            std::make_unique<AudioParameterFloat>(CMIX3_ID, CMIX3_NAME, 0.0, 100.0, 100.0),
            std::make_unique<AudioParameterFloat>(CMIX4_ID, CMIX4_NAME, 0.0, 100.0, 100.0),

            std::make_unique<AudioParameterFloat>(DMIX1_ID, DMIX1_NAME, 0.0, 100.0, 100.0),
            std::make_unique<AudioParameterFloat>(DMIX2_ID, DMIX2_NAME, 0.0, 100.0, 100.0),
            std::make_unique<AudioParameterFloat>(DMIX3_ID, DMIX3_NAME, 0.0, 100.0, 100.0),
            std::make_unique<AudioParameterFloat>(DMIX4_ID, DMIX4_NAME, 0.0, 100.0, 100.0),

            std::make_unique<AudioParameterFloat>(FMIX1_ID, FMIX1_NAME, 0.0, 100.0, 100.0),
            std::make_unique<AudioParameterFloat>(FMIX2_ID, FMIX2_NAME, 0.0, 100.0, 100.0),
            std::make_unique<AudioParameterFloat>(FMIX3_ID, FMIX3_NAME, 0.0, 100.0, 100.0),
            std::make_unique<AudioParameterFloat>(FMIX4_ID, FMIX4_NAME, 0.0, 100.0, 100.0)
        }
    ),
    slotOne(1),
    slotTwo(1),
    slotThree(1),
    slotFour(1),

    chorusOneDepth(25.0),
    chorusOneVoices(1),
    chorusTwoDepth(25.0),
    chorusTwoVoices(1),
    chorusThreeDepth(25.0),
    chorusThreeVoices(1),
    chorusFourDepth(25.0),
    chorusFourVoices(1),

    delayOneTime(0.0),
    delayOneFeedback(50.0),
    delayTwoTime(0.0),
    delayTwoFeedback(50.0),
    delayThreeTime(0.0),
    delayThreeFeedback(50.0),
    delayFourTime(0.0),
    delayFourFeedback(50.0),

    flangerOneDepth(1.0),
    flangerOneRate(1.0),
    flangerTwoDepth(1.0),
    flangerTwoRate(1.0),
    flangerThreeDepth(1.0),
    flangerThreeRate(1.0),
    flangerFourDepth(1.0),
    flangerFourRate(1.0),

    vibratoOneDepth(1.0),
    vibratoOneRate(0.1),
    vibratoTwoDepth(1.0),
    vibratoTwoRate(0.1),
    vibratoThreeDepth(1.0),
    vibratoThreeRate(0.1),
    vibratoFourDepth(1.0),
    vibratoFourRate(0.1),

    chorusOneMix(100.0),
    chorusTwoMix(100.0),
    chorusThreeMix(100.0),
    chorusFourMix(100.0),

    delayOneMix(100.0),
    delayTwoMix(100.0),
    delayThreeMix(100.0),
    delayFourMix(100.0),

    flangerOneMix(100.0),
    flangerTwoMix(100.0),
    flangerThreeMix(100.0),
    flangerFourMix(100.0)
#endif
{
    treeState.state = ValueTree("savedParams");
}

PulpfictionAudioProcessor::~PulpfictionAudioProcessor()
{
}

//==============================================================================
const juce::String PulpfictionAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool PulpfictionAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool PulpfictionAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool PulpfictionAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double PulpfictionAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int PulpfictionAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int PulpfictionAudioProcessor::getCurrentProgram()
{
    return 0;
}

void PulpfictionAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String PulpfictionAudioProcessor::getProgramName (int index)
{
    return {};
}

void PulpfictionAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void PulpfictionAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    chorusBufferOneVoice1.setSize(2, 10 * sampleRate);
    chorusBufferOneVoice1.clear();
    chorusBufferOneVoice2.setSize(2, 10 * sampleRate);
    chorusBufferOneVoice2.clear();
    chorusBufferOneVoice3.setSize(2, 10 * sampleRate);
    chorusBufferOneVoice3.clear();

    chorusBufferTwoVoice1.setSize(2, 10 * sampleRate);
    chorusBufferTwoVoice1.clear();
    chorusBufferTwoVoice2.setSize(2, 10 * sampleRate);
    chorusBufferTwoVoice2.clear();
    chorusBufferTwoVoice3.setSize(2, 10 * sampleRate);
    chorusBufferTwoVoice3.clear();

    chorusBufferThreeVoice1.setSize(2, 10 * sampleRate);
    chorusBufferThreeVoice1.clear();
    chorusBufferThreeVoice2.setSize(2, 10 * sampleRate);
    chorusBufferThreeVoice2.clear();
    chorusBufferThreeVoice3.setSize(2, 10 * sampleRate);
    chorusBufferThreeVoice3.clear();

    chorusBufferFourVoice1.setSize(2, 10 * sampleRate);
    chorusBufferFourVoice1.clear();
    chorusBufferFourVoice2.setSize(2, 10 * sampleRate);
    chorusBufferFourVoice2.clear();
    chorusBufferFourVoice3.setSize(2, 10 * sampleRate);
    chorusBufferFourVoice3.clear();

    cpw1v1[0] = 500;
    cpw1v1[1] = 500;
    cpw1v2[0] = 500;
    cpw1v2[1] = 500;
    cpw1v3[0] = 500;
    cpw1v3[1] = 500;

    cpw2v1[0] = 500;
    cpw2v1[1] = 500;
    cpw2v2[0] = 500;
    cpw2v2[1] = 500;
    cpw2v3[0] = 500;
    cpw2v3[1] = 500;

    cpw3v1[0] = 500;
    cpw3v1[1] = 500;
    cpw3v2[0] = 500;
    cpw3v2[1] = 500;
    cpw3v3[0] = 500;
    cpw3v3[1] = 500;

    cpw4v1[0] = 500;
    cpw4v1[1] = 500;
    cpw4v2[0] = 500;
    cpw4v2[1] = 500;
    cpw4v3[0] = 500;
    cpw4v3[1] = 500;

    cph1[0] = 0.0;
    cph1[1] = 0.25;

    cph2[0] = 0.0;
    cph2[1] = 0.25;

    cph3[0] = 0.0;
    cph3[1] = 0.25;

    cph4[0] = 0.0;
    cph4[1] = 0.25;

    delayBufferOne.setSize(2, 10 * sampleRate);
    delayBufferOne.clear();
    delayBufferTwo.setSize(2, 10 * sampleRate);
    delayBufferTwo.clear();
    delayBufferThree.setSize(2, 10 * sampleRate);
    delayBufferThree.clear();
    delayBufferFour.setSize(2, 10 * sampleRate);
    delayBufferFour.clear();

    dpr1[0] = 0;
    dpr1[1] = 0;
    dpr2[0] = 0;
    dpr2[1] = 0;
    dpr3[0] = 0;
    dpr3[1] = 0;
    dpr4[0] = 0;
    dpr4[1] = 0;

    flangerBufferOne.setSize(2, sampleRate);
    flangerBufferOne.clear();
    flangerBufferTwo.setSize(2, sampleRate);
    flangerBufferTwo.clear();
    flangerBufferThree.setSize(2, sampleRate);
    flangerBufferThree.clear();
    flangerBufferFour.setSize(2, sampleRate);
    flangerBufferFour.clear();

    fpw1[0] = 500;
    fpw1[1] = 500;
    fpw2[0] = 500;
    fpw2[1] = 500;
    fpw3[0] = 500;
    fpw3[1] = 500;
    fpw4[0] = 500;
    fpw4[1] = 500;

    fph1[0] = 0.0;
    fph1[1] = 0.0;
    fph2[0] = 0.0;
    fph2[1] = 0.0;
    fph3[0] = 0.0;
    fph3[1] = 0.0;
    fph4[0] = 0.0;
    fph4[1] = 0.0;

    vibratoBufferOne.setSize(2, sampleRate);
    vibratoBufferOne.clear();
    vibratoBufferTwo.setSize(2, sampleRate);
    vibratoBufferTwo.clear();
    vibratoBufferThree.setSize(2, sampleRate);
    vibratoBufferThree.clear();
    vibratoBufferFour.setSize(2, sampleRate);
    vibratoBufferFour.clear();

    vpw1[0] = 5000;
    vpw1[1] = 5000;
    vpw2[0] = 5000;
    vpw2[1] = 5000;
    vpw3[0] = 5000;
    vpw3[1] = 5000;
    vpw4[0] = 5000;
    vpw4[1] = 5000;

    vph1[0] = 0.0;
    vph1[1] = 0.0;
    vph2[0] = 0.0;
    vph2[1] = 0.0;
    vph3[0] = 0.0;
    vph3[1] = 0.0;
    vph4[0] = 0.0;
    vph4[1] = 0.0;
}

void PulpfictionAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool PulpfictionAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
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

float PulpfictionAudioProcessor::getValue(char* token) {
    if (!strcmp(token, "C1D")) {
        return chorusOneDepth;
    }
    else if (!strcmp(token, "C1V")) {
        return chorusOneVoices;
    }

    else if (!strcmp(token, "C2D")) {
        return chorusTwoDepth;
    }
    else if (!strcmp(token, "C2V")) {
        return chorusTwoVoices;
    }

    else if (!strcmp(token, "C3D")) {
        return chorusThreeDepth;
    }
    else if (!strcmp(token, "C3V")) {
        return chorusThreeVoices;
    }

    else if (!strcmp(token, "C4D")) {
        return chorusFourDepth;
    }
    else if (!strcmp(token, "C4V")) {
        return chorusFourVoices;
    }

    else if (!strcmp(token, "D1T")) {
        return delayOneTime;
    }
    else if (!strcmp(token, "D1F")) {
        return delayOneFeedback;
    }

    else if (!strcmp(token, "D2T")) {
        return delayTwoTime;
    }
    else if (!strcmp(token, "D2F")) {
        return delayTwoFeedback;
    }

    else if (!strcmp(token, "D3T")) {
        return delayThreeTime;
    }
    else if (!strcmp(token, "D3F")) {
        return delayThreeFeedback;
    }

    else if (!strcmp(token, "D4T")) {
        return delayFourTime;
    }
    else if (!strcmp(token, "D4F")) {
        return delayFourFeedback;
    }

    else if (!strcmp(token, "F1D")) {
        return flangerOneDepth;
    }
    else if (!strcmp(token, "F1R")) {
        return flangerOneRate;
    }

    else if (!strcmp(token, "F2D")) {
        return flangerTwoDepth;
    }
    else if (!strcmp(token, "F2R")) {
        return flangerOneRate;
    }

    else if (!strcmp(token, "F3D")) {
        return flangerThreeDepth;
    }
    else if (!strcmp(token, "F3R")) {
        return flangerThreeRate;
    }

    else if (!strcmp(token, "F4D")) {
        return flangerFourDepth;
    }
    else if (!strcmp(token, "F4R")) {
        return flangerFourRate;
    }

    else if (!strcmp(token, "V1D")) {
        return vibratoOneDepth;
    }
    else if (!strcmp(token, "V1R")) {
        return vibratoOneRate;
    }

    else if (!strcmp(token, "V2D")) {
        return vibratoTwoDepth;
    }
    else if (!strcmp(token, "V2R")) {
        return vibratoOneRate;
    }

    else if (!strcmp(token, "V3D")) {
        return vibratoThreeDepth;
    }
    else if (!strcmp(token, "V3R")) {
        return vibratoThreeRate;
    }

    else if (!strcmp(token, "V4D")) {
        return vibratoFourDepth;
    }
    else if (!strcmp(token, "V4R")) {
        return vibratoFourRate;
    }

    else if (!strcmp(token, "C1M")) {
        return chorusOneMix;
    }
    else if (!strcmp(token, "C2M")) {
        return chorusTwoMix;
    }
    else if (!strcmp(token, "C3M")) {
        return chorusThreeMix;
    }
    else if (!strcmp(token, "C4M")) {
        return chorusFourMix;
    }

    else if (!strcmp(token, "D1M")) {
        return delayOneMix;
    }
    else if (!strcmp(token, "D2M")) {
        return delayTwoMix;
    }
    else if (!strcmp(token, "D3M")) {
        return delayThreeMix;
    }
    else if (!strcmp(token, "D4M")) {
        return delayFourMix;
    }

    else if (!strcmp(token, "F1M")) {
        return flangerOneMix;
    }
    else if (!strcmp(token, "F2M")) {
        return flangerTwoMix;
    }
    else if (!strcmp(token, "F3M")) {
        return flangerThreeMix;
    }
    else if (!strcmp(token, "F4M")) {
        return flangerFourMix;
    }

    else if (!strcmp(token, "S1")) {
        return slotOne;
    }

    else if (!strcmp(token, "S2")) {
        return slotTwo;
    }

    else if (!strcmp(token, "S3")) {
        return slotThree;
    }

    else if (!strcmp(token, "S4")) {
        return slotFour;
    }
}

void PulpfictionAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear(i, 0, buffer.getNumSamples());

    slotOne = *treeState.getRawParameterValue(SLOTONE_ID);
    slotTwo = *treeState.getRawParameterValue(SLOTTWO_ID);
    slotThree = *treeState.getRawParameterValue(SLOTTHREE_ID);
    slotFour = *treeState.getRawParameterValue(SLOTFOUR_ID);

    switch (slotOne) {
    case 1:
        break;
    case 2:
        chorusOne(buffer);
        break;
    case 3:
        delayOne(buffer);
        break;
    case 4:
        flangerOne(buffer);
        break;
    case 5:
        vibratoOne(buffer);
        break;
    }

    switch (slotTwo) {
    case 1:
        break;
    case 2:
        chorusTwo(buffer);
        break;
    case 3:
        delayTwo(buffer);
        break;
    case 4:
        flangerTwo(buffer);
        break;
    case 5:
        vibratoTwo(buffer);
        break;
    }

    switch (slotThree) {
    case 1:
        break;
    case 2:
        chorusThree(buffer);
        break;
    case 3:
        delayThree(buffer);
        break;
    case 4:
        flangerThree(buffer);
        break;
    case 5:
        vibratoThree(buffer);
        break;
    }

    switch (slotFour) {
    case 1:
        break;
    case 2:
        chorusFour(buffer);
        break;
    case 3:
        delayFour(buffer);
        break;
    case 4:
        flangerFour(buffer);
        break;
    case 5:
        vibratoFour(buffer);
        break;
    }
}

void PulpfictionAudioProcessor::chorusOne(juce::AudioBuffer<float>& buffer) {
    auto totalNumInputChannels = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    const int totalNumSamples = buffer.getNumSamples();
    const int chorusBufferLengthVoice1 = chorusBufferOneVoice1.getNumSamples();
    const int chorusBufferLengthVoice2 = chorusBufferOneVoice2.getNumSamples();
    const int chorusBufferLengthVoice3 = chorusBufferOneVoice3.getNumSamples();

    float sampleRate = getSampleRate();

    float depth = *treeState.getRawParameterValue(CDEPTH1_ID);
    int voices = (int)*treeState.getRawParameterValue(CVOICES1_ID);

    chorusOneDepth = depth;
    chorusOneVoices = (float)voices;

    depth /= 1000.0;

    float mix = *treeState.getRawParameterValue(CMIX1_ID);

    chorusOneMix = mix;

    float wetMix = mix / 100.0;
    float dryMix = 1 - wetMix;

    DBG(voices);

    for (int channel = 0; channel < totalNumInputChannels; ++channel) {
        float* channelData = buffer.getWritePointer(channel);
        float* chorusVoice1Data = chorusBufferOneVoice1.getWritePointer(channel);
        float* chorusVoice2Data = chorusBufferOneVoice2.getWritePointer(channel);
        float* chorusVoice3Data = chorusBufferOneVoice3.getWritePointer(channel);

        for (int sample = 0; sample < totalNumSamples; ++sample) {
            const float in = channelData[sample];

            float interpolatedSample1 = 0.0;
            float interpolatedSample2 = 0.0;
            float interpolatedSample3 = 0.0;

            float phase1 = cph1[channel];
            float phase2 = cph1[channel] + 0.18;
            float phase3 = cph1[channel] + 0.33;

            if (phase2 >= 1.0) phase2 -= 1.0;
            if (phase3 >= 1.0) phase3 -= 1.0;

            float currentDelay1 = depth * (0.5 + 0.5 * sinf(2.0 * float_Pi * phase1));
            float currentDelay2 = depth * (0.5 + 0.5 * sinf(2.0 * float_Pi * phase2));
            float currentDelay3 = depth * (0.5 + 0.5 * sinf(2.0 * float_Pi * phase3));

            float cpr1 = fmodf((float)cpw1v1[channel] - currentDelay1 * sampleRate + (float)chorusBufferLengthVoice1 - 3.0, (float)chorusBufferLengthVoice1);
            float cpr2 = fmodf((float)cpw1v3[channel] - currentDelay2 * sampleRate + (float)chorusBufferLengthVoice2 - 3.0, (float)chorusBufferLengthVoice2);
            float cpr3 = fmodf((float)cpw1v3[channel] - currentDelay3 * sampleRate + (float)chorusBufferLengthVoice3 - 3.0, (float)chorusBufferLengthVoice3);

            float fraction;
            int previousSample, nextSample;

            fraction = cpr1 - floorf(cpr1);
            previousSample = (int)floorf(cpr1);
            nextSample = (previousSample + 1) % chorusBufferLengthVoice1;
            interpolatedSample1 = fraction * chorusVoice1Data[nextSample] + (1.0 - fraction) * chorusVoice1Data[previousSample];

            fraction = cpr2 - floorf(cpr2);
            previousSample = (int)floorf(cpr2);
            nextSample = (previousSample + 1) % chorusBufferLengthVoice2;
            interpolatedSample2 = fraction * chorusVoice2Data[nextSample] + (1.0 - fraction) * chorusVoice2Data[previousSample];

            fraction = cpr3 - floorf(cpr3);
            previousSample = (int)floorf(cpr3);
            nextSample = (previousSample + 1) % chorusBufferLengthVoice3;
            interpolatedSample3 = fraction * chorusVoice3Data[nextSample] + (1.0 - fraction) * chorusVoice3Data[previousSample];

            chorusVoice1Data[cpw1v1[channel]] = in;
            chorusVoice1Data[cpw1v2[channel]] = in;
            chorusVoice1Data[cpw1v3[channel]] = in;

            if (++cpw1v1[channel] >= chorusBufferLengthVoice1) cpw1v1[channel] = 0;
            if (++cpw1v2[channel] >= chorusBufferLengthVoice2) cpw1v2[channel] = 0;
            if (++cpw1v3[channel] >= chorusBufferLengthVoice3) cpw1v3[channel] = 0;

            channelData[sample] = dryMix * in + wetMix * interpolatedSample1;

            if (voices == 2) {
                channelData[sample] += wetMix * interpolatedSample2;
            }

            if (voices == 3) {
                channelData[sample] += wetMix * interpolatedSample2;
                channelData[sample] += wetMix * interpolatedSample3;
            }

            cph1[channel] += 0.5 / sampleRate;

            if (cph1[channel] >= 1.0) cph1[channel] -= 1.0;
        }
    }
}

void PulpfictionAudioProcessor::chorusTwo(juce::AudioBuffer<float>& buffer) {
    auto totalNumInputChannels = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    const int totalNumSamples = buffer.getNumSamples();
    const int chorusBufferLengthVoice1 = chorusBufferTwoVoice1.getNumSamples();
    const int chorusBufferLengthVoice2 = chorusBufferTwoVoice2.getNumSamples();
    const int chorusBufferLengthVoice3 = chorusBufferTwoVoice3.getNumSamples();

    float sampleRate = getSampleRate();

    float depth = *treeState.getRawParameterValue(CDEPTH2_ID);
    int voices = (int)*treeState.getRawParameterValue(CVOICES2_ID);

    chorusTwoDepth = depth;
    chorusTwoVoices = (float)voices;

    depth /= 1000.0;

    float mix = *treeState.getRawParameterValue(CMIX2_ID);

    chorusTwoMix = mix;

    float wetMix = mix / 100.0;
    float dryMix = 1 - wetMix;

    for (int channel = 0; channel < totalNumInputChannels; ++channel) {
        float* channelData = buffer.getWritePointer(channel);
        float* chorusVoice1Data = chorusBufferTwoVoice1.getWritePointer(channel);
        float* chorusVoice2Data = chorusBufferTwoVoice2.getWritePointer(channel);
        float* chorusVoice3Data = chorusBufferTwoVoice3.getWritePointer(channel);

        for (int sample = 0; sample < totalNumSamples; ++sample) {
            const float in = channelData[sample];

            float interpolatedSample1 = 0.0;
            float interpolatedSample2 = 0.0;
            float interpolatedSample3 = 0.0;

            float phase1 = cph2[channel];
            float phase2 = cph2[channel] + 0.18;
            float phase3 = cph2[channel] + 0.33;

            if (phase2 >= 1.0) phase2 -= 1.0;
            if (phase3 >= 1.0) phase3 -= 1.0;

            float currentDelay1 = depth * (0.5 + 0.5 * sinf(2.0 * float_Pi * phase1));
            float currentDelay2 = depth * (0.5 + 0.5 * sinf(2.0 * float_Pi * phase2));
            float currentDelay3 = depth * (0.5 + 0.5 * sinf(2.0 * float_Pi * phase3));

            float cpr1 = fmodf((float)cpw2v1[channel] - currentDelay1 * sampleRate + (float)chorusBufferLengthVoice1 - 3.0, (float)chorusBufferLengthVoice1);
            float cpr2 = fmodf((float)cpw2v3[channel] - currentDelay2 * sampleRate + (float)chorusBufferLengthVoice2 - 3.0, (float)chorusBufferLengthVoice2);
            float cpr3 = fmodf((float)cpw2v3[channel] - currentDelay3 * sampleRate + (float)chorusBufferLengthVoice3 - 3.0, (float)chorusBufferLengthVoice3);

            float fraction;
            int previousSample, nextSample;

            fraction = cpr1 - floorf(cpr1);
            previousSample = (int)floorf(cpr1);
            nextSample = (previousSample + 1) % chorusBufferLengthVoice1;
            interpolatedSample1 = fraction * chorusVoice1Data[nextSample] + (1.0 - fraction) * chorusVoice1Data[previousSample];

            fraction = cpr2 - floorf(cpr2);
            previousSample = (int)floorf(cpr2);
            nextSample = (previousSample + 1) % chorusBufferLengthVoice2;
            interpolatedSample2 = fraction * chorusVoice2Data[nextSample] + (1.0 - fraction) * chorusVoice2Data[previousSample];

            fraction = cpr3 - floorf(cpr3);
            previousSample = (int)floorf(cpr3);
            nextSample = (previousSample + 1) % chorusBufferLengthVoice3;
            interpolatedSample3 = fraction * chorusVoice3Data[nextSample] + (1.0 - fraction) * chorusVoice3Data[previousSample];

            chorusVoice1Data[cpw2v1[channel]] = in;
            chorusVoice1Data[cpw2v2[channel]] = in;
            chorusVoice1Data[cpw2v3[channel]] = in;

            if (++cpw2v1[channel] >= chorusBufferLengthVoice1) cpw2v1[channel] = 0;
            if (++cpw2v2[channel] >= chorusBufferLengthVoice2) cpw2v2[channel] = 0;
            if (++cpw2v3[channel] >= chorusBufferLengthVoice3) cpw2v3[channel] = 0;

            channelData[sample] = dryMix * in + wetMix * interpolatedSample1;

            if (voices == 2) {
                channelData[sample] += wetMix * interpolatedSample2;
            }

            if (voices == 3) {
                channelData[sample] += wetMix * interpolatedSample2;
                channelData[sample] += wetMix * interpolatedSample3;
            }

            cph2[channel] += 0.5 / sampleRate;

            if (cph2[channel] >= 1.0) cph2[channel] -= 1.0;
        }
    }
}

void PulpfictionAudioProcessor::chorusThree(juce::AudioBuffer<float>& buffer) {
    auto totalNumInputChannels = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    const int totalNumSamples = buffer.getNumSamples();
    const int chorusBufferLengthVoice1 = chorusBufferThreeVoice1.getNumSamples();
    const int chorusBufferLengthVoice2 = chorusBufferThreeVoice2.getNumSamples();
    const int chorusBufferLengthVoice3 = chorusBufferThreeVoice3.getNumSamples();

    float sampleRate = getSampleRate();

    float depth = *treeState.getRawParameterValue(CDEPTH3_ID);
    int voices = (int)*treeState.getRawParameterValue(CVOICES3_ID);

    chorusThreeDepth = depth;
    chorusThreeVoices = (float)voices;

    depth /= 1000.0;

    float mix = *treeState.getRawParameterValue(CMIX3_ID);

    chorusThreeMix = mix;

    float wetMix = mix / 100.0;
    float dryMix = 1 - wetMix;

    for (int channel = 0; channel < totalNumInputChannels; ++channel) {
        float* channelData = buffer.getWritePointer(channel);
        float* chorusVoice1Data = chorusBufferThreeVoice1.getWritePointer(channel);
        float* chorusVoice2Data = chorusBufferThreeVoice2.getWritePointer(channel);
        float* chorusVoice3Data = chorusBufferThreeVoice3.getWritePointer(channel);

        for (int sample = 0; sample < totalNumSamples; ++sample) {
            const float in = channelData[sample];

            float interpolatedSample1 = 0.0;
            float interpolatedSample2 = 0.0;
            float interpolatedSample3 = 0.0;

            float phase1 = cph3[channel];
            float phase2 = cph3[channel] + 0.18;
            float phase3 = cph3[channel] + 0.33;

            if (phase2 >= 1.0) phase2 -= 1.0;
            if (phase3 >= 1.0) phase3 -= 1.0;

            float currentDelay1 = depth * (0.5 + 0.5 * sinf(2.0 * float_Pi * phase1));
            float currentDelay2 = depth * (0.5 + 0.5 * sinf(2.0 * float_Pi * phase2));
            float currentDelay3 = depth * (0.5 + 0.5 * sinf(2.0 * float_Pi * phase3));

            float cpr1 = fmodf((float)cpw3v1[channel] - currentDelay1 * sampleRate + (float)chorusBufferLengthVoice1 - 3.0, (float)chorusBufferLengthVoice1);
            float cpr2 = fmodf((float)cpw3v3[channel] - currentDelay2 * sampleRate + (float)chorusBufferLengthVoice2 - 3.0, (float)chorusBufferLengthVoice2);
            float cpr3 = fmodf((float)cpw3v3[channel] - currentDelay3 * sampleRate + (float)chorusBufferLengthVoice3 - 3.0, (float)chorusBufferLengthVoice3);

            float fraction;
            int previousSample, nextSample;

            fraction = cpr1 - floorf(cpr1);
            previousSample = (int)floorf(cpr1);
            nextSample = (previousSample + 1) % chorusBufferLengthVoice1;
            interpolatedSample1 = fraction * chorusVoice1Data[nextSample] + (1.0 - fraction) * chorusVoice1Data[previousSample];

            fraction = cpr2 - floorf(cpr2);
            previousSample = (int)floorf(cpr2);
            nextSample = (previousSample + 1) % chorusBufferLengthVoice2;
            interpolatedSample2 = fraction * chorusVoice2Data[nextSample] + (1.0 - fraction) * chorusVoice2Data[previousSample];

            fraction = cpr3 - floorf(cpr3);
            previousSample = (int)floorf(cpr3);
            nextSample = (previousSample + 1) % chorusBufferLengthVoice3;
            interpolatedSample3 = fraction * chorusVoice3Data[nextSample] + (1.0 - fraction) * chorusVoice3Data[previousSample];

            chorusVoice1Data[cpw3v1[channel]] = in;
            chorusVoice1Data[cpw3v2[channel]] = in;
            chorusVoice1Data[cpw3v3[channel]] = in;

            if (++cpw3v1[channel] >= chorusBufferLengthVoice1) cpw3v1[channel] = 0;
            if (++cpw3v2[channel] >= chorusBufferLengthVoice2) cpw3v2[channel] = 0;
            if (++cpw3v3[channel] >= chorusBufferLengthVoice3) cpw3v3[channel] = 0;

            channelData[sample] = dryMix * in + wetMix * interpolatedSample1;

            if (voices == 2) {
                channelData[sample] += wetMix * interpolatedSample2;
            }

            if (voices == 3) {
                channelData[sample] += wetMix * interpolatedSample2;
                channelData[sample] += wetMix * interpolatedSample3;
            }

            cph3[channel] += 0.5 / sampleRate;

            if (cph3[channel] >= 1.0) cph3[channel] -= 1.0;
        }
    }
}

void PulpfictionAudioProcessor::chorusFour(juce::AudioBuffer<float>& buffer) {
    auto totalNumInputChannels = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    const int totalNumSamples = buffer.getNumSamples();
    const int chorusBufferLengthVoice1 = chorusBufferFourVoice1.getNumSamples();
    const int chorusBufferLengthVoice2 = chorusBufferFourVoice2.getNumSamples();
    const int chorusBufferLengthVoice3 = chorusBufferFourVoice3.getNumSamples();

    float sampleRate = getSampleRate();

    float depth = *treeState.getRawParameterValue(CDEPTH4_ID);
    int voices = (int)*treeState.getRawParameterValue(CVOICES4_ID);

    chorusFourDepth = depth;
    chorusFourVoices = (float)voices;

    depth /= 1000.0;

    float mix = *treeState.getRawParameterValue(CMIX4_ID);

    chorusFourMix = mix;

    float wetMix = mix / 100.0;
    float dryMix = 1 - wetMix;

    for (int channel = 0; channel < totalNumInputChannels; ++channel) {
        float* channelData = buffer.getWritePointer(channel);
        float* chorusVoice1Data = chorusBufferFourVoice1.getWritePointer(channel);
        float* chorusVoice2Data = chorusBufferFourVoice2.getWritePointer(channel);
        float* chorusVoice3Data = chorusBufferFourVoice3.getWritePointer(channel);

        for (int sample = 0; sample < totalNumSamples; ++sample) {
            const float in = channelData[sample];

            float interpolatedSample1 = 0.0;
            float interpolatedSample2 = 0.0;
            float interpolatedSample3 = 0.0;

            float phase1 = cph4[channel];
            float phase2 = cph4[channel] + 0.18;
            float phase3 = cph4[channel] + 0.33;

            if (phase2 >= 1.0) phase2 -= 1.0;
            if (phase3 >= 1.0) phase3 -= 1.0;

            float currentDelay1 = depth * (0.5 + 0.5 * sinf(2.0 * float_Pi * phase1));
            float currentDelay2 = depth * (0.5 + 0.5 * sinf(2.0 * float_Pi * phase2));
            float currentDelay3 = depth * (0.5 + 0.5 * sinf(2.0 * float_Pi * phase3));

            float cpr1 = fmodf((float)cpw4v1[channel] - currentDelay1 * sampleRate + (float)chorusBufferLengthVoice1 - 3.0, (float)chorusBufferLengthVoice1);
            float cpr2 = fmodf((float)cpw4v3[channel] - currentDelay2 * sampleRate + (float)chorusBufferLengthVoice2 - 3.0, (float)chorusBufferLengthVoice2);
            float cpr3 = fmodf((float)cpw4v3[channel] - currentDelay3 * sampleRate + (float)chorusBufferLengthVoice3 - 3.0, (float)chorusBufferLengthVoice3);

            float fraction;
            int previousSample, nextSample;

            fraction = cpr1 - floorf(cpr1);
            previousSample = (int)floorf(cpr1);
            nextSample = (previousSample + 1) % chorusBufferLengthVoice1;
            interpolatedSample1 = fraction * chorusVoice1Data[nextSample] + (1.0 - fraction) * chorusVoice1Data[previousSample];

            fraction = cpr2 - floorf(cpr2);
            previousSample = (int)floorf(cpr2);
            nextSample = (previousSample + 1) % chorusBufferLengthVoice2;
            interpolatedSample2 = fraction * chorusVoice2Data[nextSample] + (1.0 - fraction) * chorusVoice2Data[previousSample];

            fraction = cpr3 - floorf(cpr3);
            previousSample = (int)floorf(cpr3);
            nextSample = (previousSample + 1) % chorusBufferLengthVoice3;
            interpolatedSample3 = fraction * chorusVoice3Data[nextSample] + (1.0 - fraction) * chorusVoice3Data[previousSample];

            chorusVoice1Data[cpw4v1[channel]] = in;
            chorusVoice1Data[cpw4v2[channel]] = in;
            chorusVoice1Data[cpw4v3[channel]] = in;

            if (++cpw4v1[channel] >= chorusBufferLengthVoice1) cpw4v1[channel] = 0;
            if (++cpw4v2[channel] >= chorusBufferLengthVoice2) cpw4v2[channel] = 0;
            if (++cpw4v3[channel] >= chorusBufferLengthVoice3) cpw4v3[channel] = 0;

            channelData[sample] = dryMix * in + wetMix * interpolatedSample1;

            if (voices == 2) {
                channelData[sample] += wetMix * interpolatedSample2;
            }

            if (voices == 3) {
                channelData[sample] += wetMix * interpolatedSample2;
                channelData[sample] += wetMix * interpolatedSample3;
            }

            cph4[channel] += 0.5 / sampleRate;

            if (cph4[channel] >= 1.0) cph4[channel] -= 1.0;
        }
    }
}

void PulpfictionAudioProcessor::delayOne(juce::AudioBuffer<float>& buffer) {
    auto totalNumInputChannels = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    const int totalNumSamples = buffer.getNumSamples();
    const int delayBufferLength = delayBufferOne.getNumSamples();

    float time = *treeState.getRawParameterValue(TIME1_ID);
    float feedback = *treeState.getRawParameterValue(FEEDBACK1_ID);

    delayOneTime = time;
    delayOneFeedback = feedback;

    playHead = this->getPlayHead();
    playHead->getCurrentPosition(currentPositionInfo);

    float tempo = currentPositionInfo.bpm;

    float samplesPerBar = getSampleRate() * 60 * 4 / tempo;

    float timeInNotes = pow(2, (time / 12.5) - 6);

    dpw1[0] = dpr1[0] + (int)(samplesPerBar * timeInNotes);
    dpw1[1] = dpr1[1] + (int)(samplesPerBar * timeInNotes);

    dpw1[0] %= delayBufferLength;
    dpw1[1] %= delayBufferLength;

    float mix = *treeState.getRawParameterValue(DMIX1_ID);

    delayOneMix = mix;

    float wetMix = mix / 100.0;
    float dryMix = 1 - wetMix;

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        float* channelData = buffer.getWritePointer(channel);
        float* delayData = delayBufferOne.getWritePointer(channel);

        for (int sample = 0; sample < totalNumSamples; sample++) {
            float in = channelData[sample];
            float out = dryMix * in + wetMix * delayData[dpr1[channel]];

            delayData[dpw1[channel]] = in + delayData[dpr1[channel]] * std::min((int)feedback, 99) / 100.0;

            if (++dpr1[channel] >= delayBufferLength) dpr1[channel] = 0;

            if (++dpw1[channel] >= delayBufferLength) dpw1[channel] = 0;

            channelData[sample] = out;
        }
    }
}

void PulpfictionAudioProcessor::delayTwo(juce::AudioBuffer<float>& buffer) {
    auto totalNumInputChannels = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    const int totalNumSamples = buffer.getNumSamples();
    const int delayBufferLength = delayBufferTwo.getNumSamples();

    float time = *treeState.getRawParameterValue(TIME2_ID);
    float feedback = *treeState.getRawParameterValue(FEEDBACK2_ID);

    delayTwoTime = time;
    delayTwoFeedback = feedback;

    playHead = this->getPlayHead();
    playHead->getCurrentPosition(currentPositionInfo);

    float tempo = currentPositionInfo.bpm;

    float samplesPerBar = getSampleRate() * 60 * 4 / tempo;

    float timeInNotes = pow(2, (time / 12.5) - 6);

    dpw2[0] = dpr2[0] + (int)(samplesPerBar * timeInNotes);
    dpw2[1] = dpr2[1] + (int)(samplesPerBar * timeInNotes);

    dpw2[0] %= delayBufferLength;
    dpw2[1] %= delayBufferLength;

    float mix = *treeState.getRawParameterValue(DMIX2_ID);

    delayTwoMix = mix;

    float wetMix = mix / 100.0;
    float dryMix = 1 - wetMix;

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        float* channelData = buffer.getWritePointer(channel);
        float* delayData = delayBufferTwo.getWritePointer(channel);

        for (int sample = 0; sample < totalNumSamples; sample++) {
            float in = channelData[sample];
            float out = dryMix * in + wetMix * delayData[dpr2[channel]];

            delayData[dpw2[channel]] = in + delayData[dpr2[channel]] * std::min((int)feedback, 99) / 100.0;

            if (++dpr2[channel] >= delayBufferLength) dpr2[channel] = 0;

            if (++dpw2[channel] >= delayBufferLength) dpw2[channel] = 0;

            channelData[sample] = out;
        }
    }
}

void PulpfictionAudioProcessor::delayThree(juce::AudioBuffer<float>& buffer) {
    auto totalNumInputChannels = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    const int totalNumSamples = buffer.getNumSamples();
    const int delayBufferLength = delayBufferThree.getNumSamples();

    float time = *treeState.getRawParameterValue(TIME3_ID);
    float feedback = *treeState.getRawParameterValue(FEEDBACK3_ID);

    delayThreeTime = time;
    delayThreeFeedback = feedback;

    playHead = this->getPlayHead();
    playHead->getCurrentPosition(currentPositionInfo);

    float tempo = currentPositionInfo.bpm;

    float samplesPerBar = getSampleRate() * 60 * 4 / tempo;

    float timeInNotes = pow(2, (time / 12.5) - 6);

    dpw3[0] = dpr3[0] + (int)(samplesPerBar * timeInNotes);
    dpw3[1] = dpr3[1] + (int)(samplesPerBar * timeInNotes);

    dpw3[0] %= delayBufferLength;
    dpw3[1] %= delayBufferLength;

    float mix = *treeState.getRawParameterValue(DMIX3_ID);

    delayThreeMix = mix;

    float wetMix = mix / 100.0;
    float dryMix = 1 - wetMix;

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        float* channelData = buffer.getWritePointer(channel);
        float* delayData = delayBufferThree.getWritePointer(channel);

        for (int sample = 0; sample < totalNumSamples; sample++) {
            float in = channelData[sample];
            float out = dryMix * in + wetMix * delayData[dpr3[channel]];

            delayData[dpw3[channel]] = in + delayData[dpr3[channel]] * std::min((int)feedback, 99) / 100.0;

            if (++dpr3[channel] >= delayBufferLength) dpr3[channel] = 0;

            if (++dpw3[channel] >= delayBufferLength) dpw3[channel] = 0;

            channelData[sample] = out;
        }
    }
}

void PulpfictionAudioProcessor::delayFour(juce::AudioBuffer<float>& buffer) {
    auto totalNumInputChannels = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    const int totalNumSamples = buffer.getNumSamples();
    const int delayBufferLength = delayBufferFour.getNumSamples();

    float time = *treeState.getRawParameterValue(TIME4_ID);
    float feedback = *treeState.getRawParameterValue(FEEDBACK4_ID);

    delayFourTime = time;
    delayFourFeedback = feedback;

    playHead = this->getPlayHead();
    playHead->getCurrentPosition(currentPositionInfo);

    float tempo = currentPositionInfo.bpm;

    float samplesPerBar = getSampleRate() * 60 * 4 / tempo;

    float timeInNotes = pow(2, (time / 12.5) - 6);

    dpw4[0] = dpr4[0] + (int)(samplesPerBar * timeInNotes);
    dpw4[1] = dpr4[1] + (int)(samplesPerBar * timeInNotes);

    dpw4[0] %= delayBufferLength;
    dpw4[1] %= delayBufferLength;

    float mix = *treeState.getRawParameterValue(DMIX4_ID);

    delayFourMix = mix;

    float wetMix = mix / 100.0;
    float dryMix = 1 - wetMix;

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        float* channelData = buffer.getWritePointer(channel);
        float* delayData = delayBufferFour.getWritePointer(channel);

        for (int sample = 0; sample < totalNumSamples; sample++) {
            float in = channelData[sample];
            float out = dryMix * in + wetMix * delayData[dpr4[channel]];

            delayData[dpw4[channel]] = in + delayData[dpr4[channel]] * std::min((int)feedback, 99) / 100.0;

            if (++dpr4[channel] >= delayBufferLength) dpr4[channel] = 0;

            if (++dpw4[channel] >= delayBufferLength) dpw4[channel] = 0;

            channelData[sample] = out;
        }
    }
}

void PulpfictionAudioProcessor::flangerOne(juce::AudioBuffer<float>& buffer) {
    auto totalNumInputChannels = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    const int totalNumSamples = buffer.getNumSamples();
    const int flangerBufferLength = flangerBufferOne.getNumSamples();

    float sampleRate = getSampleRate();

    float depth = *treeState.getRawParameterValue(FDEPTH1_ID);
    float rate = *treeState.getRawParameterValue(FRATE1_ID);

    flangerOneDepth = depth;
    flangerOneRate = rate;

    depth /= 1000.0;

    float mix = *treeState.getRawParameterValue(FMIX1_ID);

    flangerOneMix = mix;

    float wetMix = mix / 100.0;
    float dryMix = 1 - wetMix;

    for (int channel = 0; channel < totalNumInputChannels; ++channel) {
        float* channelData = buffer.getWritePointer(channel);
        float* flangerData = flangerBufferOne.getWritePointer(channel);

        for (int sample = 0; sample < totalNumSamples; ++sample) {
            const float in = channelData[sample];

            float interpolatedSample = 0.0;

            float currentDelay = depth * (0.5 + 0.5 * sinf(2.0 * float_Pi * fph1[channel]));
            float fpr = fmodf((float)fpw1[channel] - currentDelay * sampleRate + (float)flangerBufferLength - 3.0, (float)flangerBufferLength);

            float fraction = fpr - floorf(fpr);
            int previousSample = (int)floorf(fpr);
            int nextSample = (previousSample + 1) % flangerBufferLength;
            interpolatedSample = fraction * flangerData[nextSample] + (1.0 - fraction) * flangerData[previousSample];

            flangerData[fpw1[channel]] = in;

            if (++fpw1[channel] >= flangerBufferLength) fpw1[channel] = 0;

            channelData[sample] = dryMix * in + wetMix * interpolatedSample;

            fph1[channel] += rate / sampleRate;

            if (fph1[channel] >= 1.0) fph1[channel] -= 1.0;
        }
    }
}

void PulpfictionAudioProcessor::flangerTwo(juce::AudioBuffer<float>& buffer) {
    auto totalNumInputChannels = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    const int totalNumSamples = buffer.getNumSamples();
    const int flangerBufferLength = flangerBufferTwo.getNumSamples();

    float sampleRate = getSampleRate();

    float depth = *treeState.getRawParameterValue(FDEPTH2_ID);
    float rate = *treeState.getRawParameterValue(FRATE2_ID);

    flangerTwoDepth = depth;
    flangerTwoRate = rate;

    depth /= 1000.0;

    float mix = *treeState.getRawParameterValue(FMIX2_ID);

    flangerTwoMix = mix;

    float wetMix = mix / 100.0;
    float dryMix = 1 - wetMix;

    for (int channel = 0; channel < totalNumInputChannels; ++channel) {
        float* channelData = buffer.getWritePointer(channel);
        float* flangerData = flangerBufferTwo.getWritePointer(channel);

        for (int sample = 0; sample < totalNumSamples; ++sample) {
            const float in = channelData[sample];

            float interpolatedSample = 0.0;

            float currentDelay = depth * (0.5 + 0.5 * sinf(2.0 * float_Pi * fph2[channel]));
            float fpr = fmodf((float)fpw2[channel] - currentDelay * sampleRate + (float)flangerBufferLength - 3.0, (float)flangerBufferLength);

            float fraction = fpr - floorf(fpr);
            int previousSample = (int)floorf(fpr);
            int nextSample = (previousSample + 1) % flangerBufferLength;
            interpolatedSample = fraction * flangerData[nextSample] + (1.0 - fraction) * flangerData[previousSample];

            flangerData[fpw2[channel]] = in;

            if (++fpw2[channel] >= flangerBufferLength) fpw2[channel] = 0;

            channelData[sample] = dryMix * in + wetMix * interpolatedSample;

            fph2[channel] += rate / sampleRate;

            if (fph2[channel] >= 1.0) fph2[channel] -= 1.0;
        }
    }
}

void PulpfictionAudioProcessor::flangerThree(juce::AudioBuffer<float>& buffer) {
    auto totalNumInputChannels = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    const int totalNumSamples = buffer.getNumSamples();
    const int flangerBufferLength = flangerBufferThree.getNumSamples();

    float sampleRate = getSampleRate();

    float depth = *treeState.getRawParameterValue(FDEPTH3_ID);
    float rate = *treeState.getRawParameterValue(FRATE3_ID);

    flangerThreeDepth = depth;
    flangerThreeRate = rate;

    depth /= 1000.0;

    float mix = *treeState.getRawParameterValue(FMIX3_ID);

    flangerThreeMix = mix;

    float wetMix = mix / 100.0;
    float dryMix = 1 - wetMix;

    for (int channel = 0; channel < totalNumInputChannels; ++channel) {
        float* channelData = buffer.getWritePointer(channel);
        float* flangerData = flangerBufferThree.getWritePointer(channel);

        for (int sample = 0; sample < totalNumSamples; ++sample) {
            const float in = channelData[sample];

            float interpolatedSample = 0.0;

            float currentDelay = depth * (0.5 + 0.5 * sinf(2.0 * float_Pi * fph3[channel]));
            float fpr = fmodf((float)fpw3[channel] - currentDelay * sampleRate + (float)flangerBufferLength - 3.0, (float)flangerBufferLength);

            float fraction = fpr - floorf(fpr);
            int previousSample = (int)floorf(fpr);
            int nextSample = (previousSample + 1) % flangerBufferLength;
            interpolatedSample = fraction * flangerData[nextSample] + (1.0 - fraction) * flangerData[previousSample];

            flangerData[fpw3[channel]] = in;

            if (++fpw3[channel] >= flangerBufferLength) fpw3[channel] = 0;

            channelData[sample] = dryMix * in + wetMix * interpolatedSample;

            fph3[channel] += rate / sampleRate;

            if (fph3[channel] >= 1.0) fph3[channel] -= 1.0;
        }
    }
}

void PulpfictionAudioProcessor::flangerFour(juce::AudioBuffer<float>& buffer) {
    auto totalNumInputChannels = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    const int totalNumSamples = buffer.getNumSamples();
    const int flangerBufferLength = flangerBufferFour.getNumSamples();

    float sampleRate = getSampleRate();

    float depth = *treeState.getRawParameterValue(FDEPTH4_ID);
    float rate = *treeState.getRawParameterValue(FRATE4_ID);

    flangerFourDepth = depth;
    flangerFourRate = rate;

    depth /= 1000.0;

    float mix = *treeState.getRawParameterValue(FMIX4_ID);

    flangerFourMix = mix;

    float wetMix = mix / 100.0;
    float dryMix = 1 - wetMix;

    for (int channel = 0; channel < totalNumInputChannels; ++channel) {
        float* channelData = buffer.getWritePointer(channel);
        float* flangerData = flangerBufferFour.getWritePointer(channel);

        for (int sample = 0; sample < totalNumSamples; ++sample) {
            const float in = channelData[sample];

            float interpolatedSample = 0.0;

            float currentDelay = depth * (0.5 + 0.5 * sinf(2.0 * float_Pi * fph4[channel]));
            float fpr = fmodf((float)fpw4[channel] - currentDelay * sampleRate + (float)flangerBufferLength - 3.0, (float)flangerBufferLength);

            float fraction = fpr - floorf(fpr);
            int previousSample = (int)floorf(fpr);
            int nextSample = (previousSample + 1) % flangerBufferLength;
            interpolatedSample = fraction * flangerData[nextSample] + (1.0 - fraction) * flangerData[previousSample];

            flangerData[fpw4[channel]] = in;

            if (++fpw4[channel] >= flangerBufferLength) fpw4[channel] = 0;

            channelData[sample] = dryMix * in + wetMix * interpolatedSample;

            fph4[channel] += rate / sampleRate;

            if (fph4[channel] >= 1.0) fph4[channel] -= 1.0;
        }
    }
}

void PulpfictionAudioProcessor::vibratoOne(juce::AudioBuffer<float>& buffer) {
    auto totalNumInputChannels = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    const int totalNumSamples = buffer.getNumSamples();
    const int vibratoBufferLength = vibratoBufferOne.getNumSamples();

    float sampleRate = getSampleRate();

    float depth = *treeState.getRawParameterValue(VDEPTH1_ID);
    float rate = *treeState.getRawParameterValue(VRATE1_ID);

    vibratoOneDepth = depth;
    vibratoOneRate = rate;

    depth /= 100.0;

    for (int channel = 0; channel < totalNumInputChannels; ++channel) {
        float* channelData = buffer.getWritePointer(channel);
        float* vibratoData = vibratoBufferOne.getWritePointer(channel);

        for (int sample = 0; sample < totalNumSamples; ++sample) {
            const float in = channelData[sample];

            float interpolatedSample = 0.0;

            float currentDelay = depth * (0.5 + 0.5 * sinf(2.0 * float_Pi * vph1[channel]));
            float vpr = fmodf((float)vpw1[channel] - currentDelay * sampleRate + (float)vibratoBufferLength - 3.0, (float)vibratoBufferLength);

            float fraction = vpr - floorf(vpr);
            int previousSample = (int)floorf(vpr);
            int nextSample = (previousSample + 1) % vibratoBufferLength;
            interpolatedSample = fraction * vibratoData[nextSample] + (1.0 - fraction) * vibratoData[previousSample];

            vibratoData[vpw1[channel]] = in;

            if (++vpw1[channel] >= vibratoBufferLength) vpw1[channel] = 0;

            channelData[sample] = interpolatedSample;

            vph1[channel] += rate / sampleRate;

            if (vph1[channel] >= 1.0) vph1[channel] -= 1.0;
        }
    }
}

void PulpfictionAudioProcessor::vibratoTwo(juce::AudioBuffer<float>& buffer) {
    auto totalNumInputChannels = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    const int totalNumSamples = buffer.getNumSamples();
    const int vibratoBufferLength = vibratoBufferTwo.getNumSamples();

    float sampleRate = getSampleRate();

    float depth = *treeState.getRawParameterValue(VDEPTH2_ID);
    float rate = *treeState.getRawParameterValue(VRATE2_ID);

    vibratoTwoDepth = depth;
    vibratoTwoRate = rate;

    depth /= 100.0;

    for (int channel = 0; channel < totalNumInputChannels; ++channel) {
        float* channelData = buffer.getWritePointer(channel);
        float* vibratoData = vibratoBufferTwo.getWritePointer(channel);

        for (int sample = 0; sample < totalNumSamples; ++sample) {
            const float in = channelData[sample];

            float interpolatedSample = 0.0;

            float currentDelay = depth * (0.5 + 0.5 * sinf(2.0 * float_Pi * vph2[channel]));
            float vpr = fmodf((float)vpw2[channel] - currentDelay * sampleRate + (float)vibratoBufferLength - 3.0, (float)vibratoBufferLength);

            float fraction = vpr - floorf(vpr);
            int previousSample = (int)floorf(vpr);
            int nextSample = (previousSample + 1) % vibratoBufferLength;
            interpolatedSample = fraction * vibratoData[nextSample] + (1.0 - fraction) * vibratoData[previousSample];

            vibratoData[vpw2[channel]] = in;

            if (++vpw2[channel] >= vibratoBufferLength) vpw2[channel] = 0;

            channelData[sample] = interpolatedSample;

            vph2[channel] += rate / sampleRate;

            if (vph2[channel] >= 1.0) vph2[channel] -= 1.0;
        }
    }
}

void PulpfictionAudioProcessor::vibratoThree(juce::AudioBuffer<float>& buffer) {
    auto totalNumInputChannels = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    const int totalNumSamples = buffer.getNumSamples();
    const int vibratoBufferLength = vibratoBufferThree.getNumSamples();

    float sampleRate = getSampleRate();

    float depth = *treeState.getRawParameterValue(VDEPTH3_ID);
    float rate = *treeState.getRawParameterValue(VRATE3_ID);

    vibratoThreeDepth = depth;
    vibratoThreeRate = rate;

    depth /= 100.0;

    for (int channel = 0; channel < totalNumInputChannels; ++channel) {
        float* channelData = buffer.getWritePointer(channel);
        float* vibratoData = vibratoBufferThree.getWritePointer(channel);

        for (int sample = 0; sample < totalNumSamples; ++sample) {
            const float in = channelData[sample];

            float interpolatedSample = 0.0;

            float currentDelay = depth * (0.5 + 0.5 * sinf(2.0 * float_Pi * vph3[channel]));
            float vpr = fmodf((float)vpw3[channel] - currentDelay * sampleRate + (float)vibratoBufferLength - 3.0, (float)vibratoBufferLength);

            float fraction = vpr - floorf(vpr);
            int previousSample = (int)floorf(vpr);
            int nextSample = (previousSample + 1) % vibratoBufferLength;
            interpolatedSample = fraction * vibratoData[nextSample] + (1.0 - fraction) * vibratoData[previousSample];

            vibratoData[vpw3[channel]] = in;

            if (++vpw3[channel] >= vibratoBufferLength) vpw3[channel] = 0;

            channelData[sample] = interpolatedSample;

            vph3[channel] += rate / sampleRate;

            if (vph3[channel] >= 1.0) vph3[channel] -= 1.0;
        }
    }
}

void PulpfictionAudioProcessor::vibratoFour(juce::AudioBuffer<float>& buffer) {
    auto totalNumInputChannels = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    const int totalNumSamples = buffer.getNumSamples();
    const int vibratoBufferLength = vibratoBufferFour.getNumSamples();

    float sampleRate = getSampleRate();

    float depth = *treeState.getRawParameterValue(VDEPTH4_ID);
    float rate = *treeState.getRawParameterValue(VRATE4_ID);

    vibratoFourDepth = depth;
    vibratoFourRate = rate;

    depth /= 100.0;

    for (int channel = 0; channel < totalNumInputChannels; ++channel) {
        float* channelData = buffer.getWritePointer(channel);
        float* vibratoData = vibratoBufferFour.getWritePointer(channel);

        for (int sample = 0; sample < totalNumSamples; ++sample) {
            const float in = channelData[sample];

            float interpolatedSample = 0.0;

            float currentDelay = depth * (0.5 + 0.5 * sinf(2.0 * float_Pi * vph4[channel]));
            float vpr = fmodf((float)vpw4[channel] - currentDelay * sampleRate + (float)vibratoBufferLength - 3.0, (float)vibratoBufferLength);

            float fraction = vpr - floorf(vpr);
            int previousSample = (int)floorf(vpr);
            int nextSample = (previousSample + 1) % vibratoBufferLength;
            interpolatedSample = fraction * vibratoData[nextSample] + (1.0 - fraction) * vibratoData[previousSample];

            vibratoData[vpw4[channel]] = in;

            if (++vpw4[channel] >= vibratoBufferLength) vpw4[channel] = 0;

            channelData[sample] = interpolatedSample;

            vph4[channel] += rate / sampleRate;

            if (vph4[channel] >= 1.0) vph4[channel] -= 1.0;
        }
    }
}

//==============================================================================
bool PulpfictionAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* PulpfictionAudioProcessor::createEditor()
{
    return new PulpfictionAudioProcessorEditor (*this);
}

//==============================================================================
void PulpfictionAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    std::unique_ptr <XmlElement> xml(treeState.state.createXml());
    copyXmlToBinary(*xml, destData);
}

void PulpfictionAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    std::unique_ptr <XmlElement> params(getXmlFromBinary(data, sizeInBytes));

    if (params != nullptr) {
        if (params->hasTagName(treeState.state.getType())) {
            treeState.state = ValueTree::fromXml(*params);
        }
    }
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new PulpfictionAudioProcessor();
}
