/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class PulpfictionAudioProcessorEditor  : public juce::AudioProcessorEditor, ComboBox::Listener
{
public:
    PulpfictionAudioProcessorEditor (PulpfictionAudioProcessor&);
    ~PulpfictionAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    void comboBoxChanged(ComboBox*) override;

private:
    PulpfictionAudioProcessor& audioProcessor;

    ComboBox slotOneComboBox;
    ComboBox slotTwoComboBox;
    ComboBox slotThreeComboBox;
    ComboBox slotFourComboBox;

    Slider chorusOneDepthSlider;
    Slider chorusOneVoicesSlider;
    Slider chorusTwoDepthSlider;
    Slider chorusTwoVoicesSlider;
    Slider chorusThreeDepthSlider;
    Slider chorusThreeVoicesSlider;
    Slider chorusFourDepthSlider;
    Slider chorusFourVoicesSlider;

    Slider delayOneTimeSlider;
    Slider delayOneFeedbackSlider;
    Slider delayTwoTimeSlider;
    Slider delayTwoFeedbackSlider;
    Slider delayThreeTimeSlider;
    Slider delayThreeFeedbackSlider;
    Slider delayFourTimeSlider;
    Slider delayFourFeedbackSlider;

    Slider flangerOneDepthSlider;
    Slider flangerOneRateSlider;
    Slider flangerTwoDepthSlider;
    Slider flangerTwoRateSlider;
    Slider flangerThreeDepthSlider;
    Slider flangerThreeRateSlider;
    Slider flangerFourDepthSlider;
    Slider flangerFourRateSlider;

    Slider vibratoOneDepthSlider;
    Slider vibratoOneRateSlider;
    Slider vibratoTwoDepthSlider;
    Slider vibratoTwoRateSlider;
    Slider vibratoThreeDepthSlider;
    Slider vibratoThreeRateSlider;
    Slider vibratoFourDepthSlider;
    Slider vibratoFourRateSlider;

    Slider chorusOneMixSlider;
    Slider chorusTwoMixSlider;
    Slider chorusThreeMixSlider;
    Slider chorusFourMixSlider;

    Slider delayOneMixSlider;
    Slider delayTwoMixSlider;
    Slider delayThreeMixSlider;
    Slider delayFourMixSlider;

    Slider flangerOneMixSlider;
    Slider flangerTwoMixSlider;
    Slider flangerThreeMixSlider;
    Slider flangerFourMixSlider;

    std::unique_ptr <AudioProcessorValueTreeState::ComboBoxAttachment> slotOneValue;
    std::unique_ptr <AudioProcessorValueTreeState::ComboBoxAttachment> slotTwoValue;
    std::unique_ptr <AudioProcessorValueTreeState::ComboBoxAttachment> slotThreeValue;
    std::unique_ptr <AudioProcessorValueTreeState::ComboBoxAttachment> slotFourValue;

    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> chorusOneDepthValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> chorusOneVoicesValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> chorusTwoDepthValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> chorusTwoVoicesValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> chorusThreeDepthValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> chorusThreeVoicesValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> chorusFourDepthValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> chorusFourVoicesValue;

    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> delayOneTimeValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> delayOneFeedbackValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> delayTwoTimeValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> delayTwoFeedbackValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> delayThreeTimeValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> delayThreeFeedbackValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> delayFourTimeValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> delayFourFeedbackValue;

    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> flangerOneDepthValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> flangerOneRateValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> flangerTwoDepthValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> flangerTwoRateValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> flangerThreeDepthValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> flangerThreeRateValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> flangerFourDepthValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> flangerFourRateValue;

    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> vibratoOneDepthValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> vibratoOneRateValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> vibratoTwoDepthValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> vibratoTwoRateValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> vibratoThreeDepthValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> vibratoThreeRateValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> vibratoFourDepthValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> vibratoFourRateValue;

    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> chorusOneMixValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> chorusTwoMixValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> chorusThreeMixValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> chorusFourMixValue;

    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> delayOneMixValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> delayTwoMixValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> delayThreeMixValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> delayFourMixValue;

    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> flangerOneMixValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> flangerTwoMixValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> flangerThreeMixValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> flangerFourMixValue;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PulpfictionAudioProcessorEditor)
};
