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
                       )
#endif
{
    
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
    MemoryInputStream inputStream(BinaryData::watersplash_wav, BinaryData::watersplash_wavSize, false);

    WavAudioFormat wavFormat;

    AudioFormatReader* reader(wavFormat.createReaderFor(&inputStream, false));

    if (reader != nullptr)
    {
        sampleBuffer.setSize(reader->numChannels, reader->lengthInSamples);
        reader->read(&sampleBuffer, 0, reader->lengthInSamples, 0, true, true);

        sampleLength = reader->lengthInSamples;
    }
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

void PulpfictionAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    auto totalNumSamples = buffer.getNumSamples();

    float* leftChannelData = buffer.getWritePointer(0);
    float* rightChannelData = buffer.getWritePointer(1);

    if (numSamplesRemaining >= totalNumSamples) {
        buffer.addFrom(0, 0, sampleBuffer, 0, sampleLength - numSamplesRemaining, totalNumSamples, 1);
        buffer.addFrom(1, 0, sampleBuffer, 1, sampleLength - numSamplesRemaining, totalNumSamples, 1);

        numSamplesRemaining -= totalNumSamples;
    }
    else if (numSamplesRemaining > 0) {
        buffer.addFrom(0, 0, sampleBuffer, 0, sampleLength - numSamplesRemaining, numSamplesRemaining, 1);
        buffer.addFrom(1, 0, sampleBuffer, 1, sampleLength - numSamplesRemaining, numSamplesRemaining, 1);

        numSamplesRemaining = 0;
    }
    else {
        numSamplesRemaining = sampleLength;
    }

    transientIndices = detectTransients(leftChannelData, rightChannelData, totalNumSamples);

    for (int sample = 0; sample < totalNumSamples; sample++) {
        for (auto& transientIndex : transientIndices) {
            if (sample == transientIndex) {

            }
        }
    }
}

std::vector<int> PulpfictionAudioProcessor::detectTransients(const float* leftChannelData, const float* rightChannelData, const int totalNumSamples) {
    std::vector<int> transientIndices;

    int windowSize = 512;
    float threshold = 0.5;
    float decayThreshold = threshold * 0.5;
    int transientDuration;
    int minTransientDuration = 10;
    bool isTransient = false;
    int transientStartIndex = -1;

    for (int sample = 0; sample < totalNumSamples; sample += 1)
    {
        float currentSample = std::max(abs(leftChannelData[sample]), abs(rightChannelData[sample]));

        if (isTransient) {
            if (currentSample < decayThreshold) {
                isTransient = false;
                
                transientDuration = sample - transientStartIndex;
                if (transientDuration >= minTransientDuration) {
                    transientIndices.push_back(transientStartIndex);
                } 
            }
        }

        if (currentSample > threshold) {
            if (!isTransient) {
                isTransient = true;
                transientStartIndex = sample;
            }
        }
    }

    return transientIndices;
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
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void PulpfictionAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new PulpfictionAudioProcessor();
}
