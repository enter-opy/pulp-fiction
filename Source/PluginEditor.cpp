/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PulpfictionAudioProcessorEditor::PulpfictionAudioProcessorEditor (PulpfictionAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
}

PulpfictionAudioProcessorEditor::~PulpfictionAudioProcessorEditor()
{
}

//==============================================================================
void PulpfictionAudioProcessorEditor::paint (juce::Graphics& g)
{
}

void PulpfictionAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
