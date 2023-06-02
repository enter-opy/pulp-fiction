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
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
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

    AudioSampleBuffer noise;
    noise.makeCopyOf(buffer);

    for (int channel = 0; channel < totalNumInputChannels; channel++) {
        float* noiseChannelData = noise.getWritePointer(channel);
        float* ChannelData = buffer.getWritePointer(channel);

        for (int sample = 0; sample < totalNumSamples; sample++) {
            noiseChannelData[sample] = (random.nextFloat() * 2.0f - 1.0f);
        }

        std::vector<int> transientIndices = detectTransients(ChannelData, totalNumSamples);

        for (int sample = 0; sample < totalNumSamples; sample++) {
            for (auto& transientIndex : transientIndices) {
                if (sample == transientIndex) {
                    buffer.addFrom(channel, sample, noise, channel, 0, 2205, 1);
                }
            }
        }
    }


}

std::vector<int> PulpfictionAudioProcessor::detectTransients(const float* buffer, const int numSamples) {
    std::vector<int> transientIndices;

    const int blockSize = 512;
    const float threshold = 0.5f;

    float previousAmplitude = 0.0f;

    for (int i = 0; i < numSamples; i += blockSize)
    {
        float blockAmplitude = 0.0f;

        // Calculate the energy/amplitude envelope of the block
        for (int j = i; j < i + blockSize && j < numSamples; ++j)
        {
            float sample = buffer[j];
            blockAmplitude += sample * sample;
        }

        blockAmplitude = std::sqrt(blockAmplitude);

        // Check for transient by comparing with the previous block's amplitude
        if (blockAmplitude > threshold * previousAmplitude)
        {
            transientIndices.push_back(i);
        }

        previousAmplitude = blockAmplitude;
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
