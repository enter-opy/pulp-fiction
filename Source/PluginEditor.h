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

class SliderLookAndFeel : public LookAndFeel_V4 {
public:
    void drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos, float rotatoryStartAngle, float rotatoryEndAngle, juce::Slider& slider) override {
        float diameter = jmin(width - 4, height - 4);
        float radius = diameter / 2;
        float centerX = x + width / 2;
        float centerY = y + height / 2;
        float rx = centerX - radius;
        float ry = centerY - radius;

        Rectangle<float> area(rx, ry, diameter, diameter);

        g.setColour(Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
        g.drawEllipse(area, 3.5f);

        g.setColour(Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.2));
        g.fillEllipse(area);
    }
};

class PulpfictionAudioProcessorEditor  : public juce::AudioProcessorEditor, ComboBox::Listener, Slider::Listener
{
public:
    PulpfictionAudioProcessorEditor (PulpfictionAudioProcessor&);
    ~PulpfictionAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    void comboBoxChanged(ComboBox*) override;
    void sliderValueChanged(Slider*) override;

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

    Rectangle<float> slotOneRectangle;
    Rectangle<float> slotTwoRectangle;
    Rectangle<float> slotThreeRectangle;
    Rectangle<float> slotFourRectangle;

    SliderLookAndFeel chorusOneDepthSliderLookAndFeel;
    SliderLookAndFeel chorusTwoDepthSliderLookAndFeel;
    SliderLookAndFeel chorusThreeDepthSliderLookAndFeel;
    SliderLookAndFeel chorusFourDepthSliderLookAndFeel;
    SliderLookAndFeel chorusOneVoicesSliderLookAndFeel;
    SliderLookAndFeel chorusTwoVoicesSliderLookAndFeel;
    SliderLookAndFeel chorusThreeVoicesSliderLookAndFeel;
    SliderLookAndFeel chorusFourVoicesSliderLookAndFeel;

    SliderLookAndFeel delayOneTimeSliderLookAndFeel;
    SliderLookAndFeel delayTwoTimeSliderLookAndFeel;
    SliderLookAndFeel delayThreeTimeSliderLookAndFeel;
    SliderLookAndFeel delayFourTimeSliderLookAndFeel;
    SliderLookAndFeel delayOneFeedbackSliderLookAndFeel;
    SliderLookAndFeel delayTwoFeedbackSliderLookAndFeel;
    SliderLookAndFeel delayThreeFeedbackSliderLookAndFeel;
    SliderLookAndFeel delayFourFeedbackSliderLookAndFeel;

    SliderLookAndFeel flangerOneDepthSliderLookAndFeel;
    SliderLookAndFeel flangerTwoDepthSliderLookAndFeel;
    SliderLookAndFeel flangerThreeDepthSliderLookAndFeel;
    SliderLookAndFeel flangerFourDepthSliderLookAndFeel;
    SliderLookAndFeel flangerOneRateSliderLookAndFeel;
    SliderLookAndFeel flangerTwoRateSliderLookAndFeel;
    SliderLookAndFeel flangerThreeRateSliderLookAndFeel;
    SliderLookAndFeel flangerFourRateSliderLookAndFeel;

    SliderLookAndFeel vibratoOneDepthSliderLookAndFeel;
    SliderLookAndFeel vibratoTwoDepthSliderLookAndFeel;
    SliderLookAndFeel vibratoThreeDepthSliderLookAndFeel;
    SliderLookAndFeel vibratoFourDepthSliderLookAndFeel;
    SliderLookAndFeel vibratoOneRateSliderLookAndFeel;
    SliderLookAndFeel vibratoTwoRateSliderLookAndFeel;
    SliderLookAndFeel vibratoThreeRateSliderLookAndFeel;
    SliderLookAndFeel vibratoFourRateSliderLookAndFeel;

    SliderLookAndFeel chorusOneMixSliderLookAndFeel;
    SliderLookAndFeel chorusTwoMixSliderLookAndFeel;
    SliderLookAndFeel chorusThreeMixSliderLookAndFeel;
    SliderLookAndFeel chorusFourMixSliderLookAndFeel;

    SliderLookAndFeel delayOneMixSliderLookAndFeel;
    SliderLookAndFeel delayTwoMixSliderLookAndFeel;
    SliderLookAndFeel delayThreeMixSliderLookAndFeel;
    SliderLookAndFeel delayFourMixSliderLookAndFeel;

    SliderLookAndFeel flangerOneMixSliderLookAndFeel;
    SliderLookAndFeel flangerTwoMixSliderLookAndFeel;
    SliderLookAndFeel flangerThreeMixSliderLookAndFeel;
    SliderLookAndFeel flangerFourMixSliderLookAndFeel;

    Label chorusOneDepthIndicator;
    Label chorusOneVoicesIndicator;
    Label chorusOneMixIndicator;

    Label delayOneTimeIndicator;
    Label delayOneFeedbackIndicator;
    Label delayOneMixIndicator;

    Label flangerOneDepthIndicator;
    Label flangerOneRateIndicator;
    Label flangerOneMixIndicator;

    Label vibratoOneDepthIndicator;
    Label vibratoOneRateIndicator;

    Label chorusOneDepthLabel;
    Label chorusOneVoicesLabel;
    Label chorusOneMixLabel;

    Label delayOneTimeLabel;
    Label delayOneFeedbackLabel;
    Label delayOneMixLabel;

    Label flangerOneDepthLabel;
    Label flangerOneRateLabel;
    Label flangerOneMixLabel;

    Label vibratoOneDepthLabel;
    Label vibratoOneRateLabel;

    Label chorusTwoDepthIndicator;
    Label chorusTwoVoicesIndicator;
    Label chorusTwoMixIndicator;

    Label delayTwoTimeIndicator;
    Label delayTwoFeedbackIndicator;
    Label delayTwoMixIndicator;

    Label flangerTwoDepthIndicator;
    Label flangerTwoRateIndicator;
    Label flangerTwoMixIndicator;

    Label vibratoTwoDepthIndicator;
    Label vibratoTwoRateIndicator;

    Label chorusTwoDepthLabel;
    Label chorusTwoVoicesLabel;
    Label chorusTwoMixLabel;

    Label delayTwoTimeLabel;
    Label delayTwoFeedbackLabel;
    Label delayTwoMixLabel;

    Label flangerTwoDepthLabel;
    Label flangerTwoRateLabel;
    Label flangerTwoMixLabel;

    Label vibratoTwoDepthLabel;
    Label vibratoTwoRateLabel;

    Label chorusThreeDepthIndicator;
    Label chorusThreeVoicesIndicator;
    Label chorusThreeMixIndicator;

    Label delayThreeTimeIndicator;
    Label delayThreeFeedbackIndicator;
    Label delayThreeMixIndicator;

    Label flangerThreeDepthIndicator;
    Label flangerThreeRateIndicator;
    Label flangerThreeMixIndicator;

    Label vibratoThreeDepthIndicator;
    Label vibratoThreeRateIndicator;

    Label chorusThreeDepthLabel;
    Label chorusThreeVoicesLabel;
    Label chorusThreeMixLabel;

    Label delayThreeTimeLabel;
    Label delayThreeFeedbackLabel;
    Label delayThreeMixLabel;

    Label flangerThreeDepthLabel;
    Label flangerThreeRateLabel;
    Label flangerThreeMixLabel;

    Label vibratoThreeDepthLabel;
    Label vibratoThreeRateLabel;

    Label chorusFourDepthIndicator;
    Label chorusFourVoicesIndicator;
    Label chorusFourMixIndicator;

    Label delayFourTimeIndicator;
    Label delayFourFeedbackIndicator;
    Label delayFourMixIndicator;

    Label flangerFourDepthIndicator;
    Label flangerFourRateIndicator;
    Label flangerFourMixIndicator;

    Label vibratoFourDepthIndicator;
    Label vibratoFourRateIndicator;

    Label chorusFourDepthLabel;
    Label chorusFourVoicesLabel;
    Label chorusFourMixLabel;

    Label delayFourTimeLabel;
    Label delayFourFeedbackLabel;
    Label delayFourMixLabel;

    Label flangerFourDepthLabel;
    Label flangerFourRateLabel;
    Label flangerFourMixLabel;

    Label vibratoFourDepthLabel;
    Label vibratoFourRateLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PulpfictionAudioProcessorEditor)
};
