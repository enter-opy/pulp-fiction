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
    setSize(850, 400);

    slotOneValue = std::make_unique<AudioProcessorValueTreeState::ComboBoxAttachment>(audioProcessor.treeState, SLOTONE_ID, slotOneComboBox);
    slotTwoValue = std::make_unique<AudioProcessorValueTreeState::ComboBoxAttachment>(audioProcessor.treeState, SLOTTWO_ID, slotTwoComboBox);
    slotThreeValue = std::make_unique<AudioProcessorValueTreeState::ComboBoxAttachment>(audioProcessor.treeState, SLOTTHREE_ID, slotThreeComboBox);
    slotFourValue = std::make_unique<AudioProcessorValueTreeState::ComboBoxAttachment>(audioProcessor.treeState, SLOTFOUR_ID, slotFourComboBox);

    chorusOneDepthValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, CDEPTH1_ID, chorusOneDepthSlider);
    chorusOneVoicesValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, CVOICES1_ID, chorusOneVoicesSlider);
    chorusTwoDepthValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, CDEPTH2_ID, chorusTwoDepthSlider);
    chorusTwoVoicesValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, CVOICES2_ID, chorusTwoVoicesSlider);
    chorusThreeDepthValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, CDEPTH3_ID, chorusThreeDepthSlider);
    chorusThreeVoicesValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, CVOICES3_ID, chorusThreeVoicesSlider);
    chorusFourDepthValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, CDEPTH4_ID, chorusFourDepthSlider);
    chorusFourVoicesValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, CVOICES4_ID, chorusFourVoicesSlider);

    delayOneTimeValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, TIME1_ID, delayOneTimeSlider);
    delayOneFeedbackValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, FEEDBACK1_ID, delayOneFeedbackSlider);
    delayTwoTimeValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, TIME2_ID, delayTwoTimeSlider);
    delayTwoFeedbackValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, FEEDBACK2_ID, delayTwoFeedbackSlider);
    delayThreeTimeValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, TIME3_ID, delayThreeTimeSlider);
    delayThreeFeedbackValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, FEEDBACK3_ID, delayThreeFeedbackSlider);
    delayFourTimeValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, TIME4_ID, delayFourTimeSlider);
    delayFourFeedbackValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, FEEDBACK4_ID, delayFourFeedbackSlider);

    flangerOneDepthValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, FDEPTH1_ID, flangerOneDepthSlider);
    flangerOneRateValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, FRATE1_ID, flangerOneRateSlider);
    flangerTwoDepthValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, FDEPTH2_ID, flangerTwoDepthSlider);
    flangerTwoRateValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, FRATE2_ID, flangerTwoRateSlider);
    flangerThreeDepthValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, FDEPTH3_ID, flangerThreeDepthSlider);
    flangerThreeRateValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, FRATE3_ID, flangerThreeRateSlider);
    flangerFourDepthValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, FDEPTH4_ID, flangerFourDepthSlider);
    flangerFourRateValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, FRATE4_ID, flangerFourRateSlider);

    vibratoOneDepthValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, VDEPTH1_ID, vibratoOneDepthSlider);
    vibratoOneRateValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, VRATE1_ID, vibratoOneRateSlider);
    vibratoTwoDepthValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, VDEPTH2_ID, vibratoTwoDepthSlider);
    vibratoTwoRateValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, VRATE2_ID, vibratoTwoRateSlider);
    vibratoThreeDepthValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, VDEPTH3_ID, vibratoThreeDepthSlider);
    vibratoThreeRateValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, VRATE3_ID, vibratoThreeRateSlider);
    vibratoFourDepthValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, VDEPTH4_ID, vibratoFourDepthSlider);
    vibratoFourRateValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, VRATE4_ID, vibratoFourRateSlider);

    chorusOneMixValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, CMIX1_ID, chorusOneMixSlider);
    chorusTwoMixValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, CMIX2_ID, chorusTwoMixSlider);
    chorusThreeMixValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, CMIX3_ID, chorusThreeMixSlider);
    chorusFourMixValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, CMIX4_ID, chorusFourMixSlider);

    delayOneMixValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, DMIX1_ID, delayOneMixSlider);
    delayTwoMixValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, DMIX2_ID, delayTwoMixSlider);
    delayThreeMixValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, DMIX3_ID, delayThreeMixSlider);
    delayFourMixValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, DMIX4_ID, delayFourMixSlider);

    flangerOneMixValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, FMIX1_ID, flangerOneMixSlider);
    flangerTwoMixValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, FMIX2_ID, flangerTwoMixSlider);
    flangerThreeMixValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, FMIX3_ID, flangerThreeMixSlider);
    flangerFourMixValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, FMIX4_ID, flangerFourMixSlider);

    chorusOneDepthSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    chorusOneDepthSlider.setRange(20.0, 30.0, 0.1);
    chorusOneDepthSlider.setValue(audioProcessor.getValue("C1D"));
    chorusOneDepthSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    chorusOneDepthSlider.setLookAndFeel(&chorusOneDepthSliderLookAndFeel);
    chorusOneDepthSlider.addListener(this);
    addAndMakeVisible(&chorusOneDepthSlider);

    chorusOneVoicesSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    chorusOneVoicesSlider.setRange(1.0, 3.0, 1.0);
    chorusOneVoicesSlider.setValue(audioProcessor.getValue("C1V"));
    chorusOneVoicesSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    chorusOneVoicesSlider.setLookAndFeel(&chorusOneVoicesSliderLookAndFeel);
    chorusOneVoicesSlider.addListener(this);
    addAndMakeVisible(&chorusOneVoicesSlider);

    chorusTwoDepthSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    chorusTwoDepthSlider.setRange(20.0, 30.0, 0.1);
    chorusTwoDepthSlider.setValue(audioProcessor.getValue("C2D"));
    chorusTwoDepthSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    chorusTwoDepthSlider.setLookAndFeel(&chorusTwoDepthSliderLookAndFeel);
    chorusTwoDepthSlider.addListener(this);
    addAndMakeVisible(&chorusTwoDepthSlider);

    chorusTwoVoicesSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    chorusTwoVoicesSlider.setRange(1.0, 3.0, 1.0);
    chorusTwoVoicesSlider.setValue(audioProcessor.getValue("C2V"));
    chorusTwoVoicesSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    chorusTwoVoicesSlider.setLookAndFeel(&chorusTwoVoicesSliderLookAndFeel);
    chorusTwoVoicesSlider.addListener(this);
    addAndMakeVisible(&chorusTwoVoicesSlider);

    chorusThreeDepthSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    chorusThreeDepthSlider.setRange(20.0, 30.0, 0.1);
    chorusThreeDepthSlider.setValue(audioProcessor.getValue("C3D"));
    chorusThreeDepthSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    chorusThreeDepthSlider.setLookAndFeel(&chorusThreeDepthSliderLookAndFeel);
    chorusThreeDepthSlider.addListener(this);
    addAndMakeVisible(&chorusThreeDepthSlider);

    chorusThreeVoicesSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    chorusThreeVoicesSlider.setRange(1.0, 3.0, 1.0);
    chorusThreeVoicesSlider.setValue(audioProcessor.getValue("C3V"));
    chorusThreeVoicesSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    chorusThreeVoicesSlider.setLookAndFeel(&chorusThreeVoicesSliderLookAndFeel);
    chorusThreeVoicesSlider.addListener(this);
    addAndMakeVisible(&chorusThreeVoicesSlider);

    chorusFourDepthSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    chorusFourDepthSlider.setRange(20.0, 30.0, 0.1);
    chorusFourDepthSlider.setValue(audioProcessor.getValue("C4D"));
    chorusFourDepthSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    chorusFourDepthSlider.setLookAndFeel(&chorusFourDepthSliderLookAndFeel);
    chorusFourDepthSlider.addListener(this);
    addAndMakeVisible(&chorusFourDepthSlider);

    chorusFourVoicesSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    chorusFourVoicesSlider.setRange(1.0, 3.0, 1.0);
    chorusFourVoicesSlider.setValue(audioProcessor.getValue("C4V"));
    chorusFourVoicesSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    chorusFourVoicesSlider.setLookAndFeel(&chorusFourVoicesSliderLookAndFeel);
    chorusFourVoicesSlider.addListener(this);
    addAndMakeVisible(&chorusFourVoicesSlider);

    delayOneTimeSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    delayOneTimeSlider.setRange(0.0, 100.0, 12.5);
    delayOneTimeSlider.setValue(audioProcessor.getValue("D1T"));
    delayOneTimeSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    delayOneTimeSlider.setLookAndFeel(&delayOneTimeSliderLookAndFeel);
    delayOneTimeSlider.addListener(this);
    addAndMakeVisible(&delayOneTimeSlider);

    delayOneFeedbackSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    delayOneFeedbackSlider.setRange(0.0, 100.0, 1.0);
    delayOneFeedbackSlider.setValue(audioProcessor.getValue("D1F"));
    delayOneFeedbackSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    delayOneFeedbackSlider.setLookAndFeel(&delayOneFeedbackSliderLookAndFeel);
    delayOneFeedbackSlider.addListener(this);
    addAndMakeVisible(&delayOneFeedbackSlider);

    delayTwoTimeSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    delayTwoTimeSlider.setRange(0.0, 100.0, 12.5);
    delayTwoTimeSlider.setValue(audioProcessor.getValue("D2T"));
    delayTwoTimeSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    delayTwoTimeSlider.setLookAndFeel(&delayTwoTimeSliderLookAndFeel);
    delayTwoTimeSlider.addListener(this);
    addAndMakeVisible(&delayTwoTimeSlider);

    delayTwoFeedbackSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    delayTwoFeedbackSlider.setRange(0.0, 100.0, 1.0);
    delayTwoFeedbackSlider.setValue(audioProcessor.getValue("D2F"));
    delayTwoFeedbackSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    delayTwoFeedbackSlider.setLookAndFeel(&delayTwoFeedbackSliderLookAndFeel);
    delayTwoFeedbackSlider.addListener(this);
    addAndMakeVisible(&delayTwoFeedbackSlider);

    delayThreeTimeSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    delayThreeTimeSlider.setRange(0.0, 100.0, 12.5);
    delayThreeTimeSlider.setValue(audioProcessor.getValue("D3T"));
    delayThreeTimeSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    delayThreeTimeSlider.setLookAndFeel(&delayThreeTimeSliderLookAndFeel);
    delayThreeTimeSlider.addListener(this);
    addAndMakeVisible(&delayThreeTimeSlider);

    delayThreeFeedbackSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    delayThreeFeedbackSlider.setRange(0.0, 100.0, 1.0);
    delayThreeFeedbackSlider.setValue(audioProcessor.getValue("D3F"));
    delayThreeFeedbackSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    delayThreeFeedbackSlider.setLookAndFeel(&delayThreeFeedbackSliderLookAndFeel);
    delayThreeFeedbackSlider.addListener(this);
    addAndMakeVisible(&delayThreeFeedbackSlider);

    delayFourTimeSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    delayFourTimeSlider.setRange(0.0, 100.0, 12.5);
    delayFourTimeSlider.setValue(audioProcessor.getValue("D4T"));
    delayFourTimeSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    delayFourTimeSlider.setLookAndFeel(&delayFourTimeSliderLookAndFeel);
    delayFourTimeSlider.addListener(this);
    addAndMakeVisible(&delayFourTimeSlider);

    delayFourFeedbackSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    delayFourFeedbackSlider.setRange(0.0, 100.0, 1.0);
    delayFourFeedbackSlider.setValue(audioProcessor.getValue("D4F"));
    delayFourFeedbackSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    delayFourFeedbackSlider.setLookAndFeel(&delayFourFeedbackSliderLookAndFeel);
    delayFourFeedbackSlider.addListener(this);
    addAndMakeVisible(&delayFourFeedbackSlider);

    flangerOneDepthSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    flangerOneDepthSlider.setRange(0.0, 10.0, 0.01);
    flangerOneDepthSlider.setValue(audioProcessor.getValue("F1D"));
    flangerOneDepthSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    flangerOneDepthSlider.setLookAndFeel(&flangerOneDepthSliderLookAndFeel);
    flangerOneDepthSlider.addListener(this);
    addAndMakeVisible(&flangerOneDepthSlider);

    flangerOneRateSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    flangerOneRateSlider.setRange(1.0, 10.0, 0.01);
    flangerOneRateSlider.setValue(audioProcessor.getValue("F1R"));
    flangerOneRateSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    flangerOneRateSlider.setLookAndFeel(&flangerOneRateSliderLookAndFeel);
    flangerOneRateSlider.addListener(this);
    addAndMakeVisible(&flangerOneRateSlider);

    flangerTwoDepthSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    flangerTwoDepthSlider.setRange(0.0, 10.0, 0.01);
    flangerTwoDepthSlider.setValue(audioProcessor.getValue("F2D"));
    flangerTwoDepthSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    flangerTwoDepthSlider.setLookAndFeel(&flangerTwoDepthSliderLookAndFeel);
    flangerTwoDepthSlider.addListener(this);
    addAndMakeVisible(&flangerTwoDepthSlider);

    flangerTwoRateSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    flangerTwoRateSlider.setRange(1.0, 10.0, 0.01);
    flangerTwoRateSlider.setValue(audioProcessor.getValue("F2R"));
    flangerTwoRateSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    flangerTwoRateSlider.setLookAndFeel(&flangerTwoRateSliderLookAndFeel);
    flangerTwoRateSlider.addListener(this);
    addAndMakeVisible(&flangerTwoRateSlider);

    flangerThreeDepthSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    flangerThreeDepthSlider.setRange(0.0, 10.0, 0.01);
    flangerThreeDepthSlider.setValue(audioProcessor.getValue("F3D"));
    flangerThreeDepthSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    flangerThreeDepthSlider.setLookAndFeel(&flangerThreeDepthSliderLookAndFeel);
    flangerThreeDepthSlider.addListener(this);
    addAndMakeVisible(&flangerThreeDepthSlider);

    flangerThreeRateSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    flangerThreeRateSlider.setRange(1.0, 10.0, 0.01);
    flangerThreeRateSlider.setValue(audioProcessor.getValue("F3R"));
    flangerThreeRateSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    flangerThreeRateSlider.setLookAndFeel(&flangerThreeRateSliderLookAndFeel);
    flangerThreeRateSlider.addListener(this);
    addAndMakeVisible(&flangerThreeRateSlider);

    flangerFourDepthSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    flangerFourDepthSlider.setRange(0.0, 10.0, 0.01);
    flangerFourDepthSlider.setValue(audioProcessor.getValue("F4D"));
    flangerFourDepthSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    flangerFourDepthSlider.setLookAndFeel(&flangerFourDepthSliderLookAndFeel);
    flangerFourDepthSlider.addListener(this);
    addAndMakeVisible(&flangerFourDepthSlider);

    flangerFourRateSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    flangerFourRateSlider.setRange(1.0, 10.0, 0.01);
    flangerFourRateSlider.setValue(audioProcessor.getValue("F4R"));
    flangerFourRateSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    flangerFourRateSlider.setLookAndFeel(&flangerFourRateSliderLookAndFeel);
    flangerFourDepthSlider.addListener(this);
    addAndMakeVisible(&flangerFourRateSlider);

    vibratoOneDepthSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    vibratoOneDepthSlider.setRange(0.0, 10.0, 0.01);
    vibratoOneDepthSlider.setValue(audioProcessor.getValue("V1D"));
    vibratoOneDepthSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    vibratoOneDepthSlider.setLookAndFeel(&vibratoOneDepthSliderLookAndFeel);
    vibratoOneDepthSlider.addListener(this);
    addAndMakeVisible(&vibratoOneDepthSlider);

    vibratoOneRateSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    vibratoOneRateSlider.setRange(0.01, 10.0, 0.001);
    vibratoOneRateSlider.setValue(audioProcessor.getValue("V1R"));
    vibratoOneRateSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    vibratoOneRateSlider.setLookAndFeel(&vibratoOneRateSliderLookAndFeel);
    vibratoOneRateSlider.addListener(this);
    addAndMakeVisible(&vibratoOneRateSlider);

    vibratoTwoDepthSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    vibratoTwoDepthSlider.setRange(0.0, 10.0, 0.01);
    vibratoTwoDepthSlider.setValue(audioProcessor.getValue("V2D"));
    vibratoTwoDepthSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    vibratoTwoDepthSlider.setLookAndFeel(&vibratoTwoDepthSliderLookAndFeel);
    vibratoTwoDepthSlider.addListener(this);
    addAndMakeVisible(&vibratoTwoDepthSlider);

    vibratoTwoRateSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    vibratoTwoRateSlider.setRange(0.01, 10.0, 0.001);
    vibratoTwoRateSlider.setValue(audioProcessor.getValue("V2R"));
    vibratoTwoRateSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    vibratoTwoRateSlider.setLookAndFeel(&vibratoTwoRateSliderLookAndFeel);
    vibratoTwoRateSlider.addListener(this);
    addAndMakeVisible(&vibratoTwoRateSlider);

    vibratoThreeDepthSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    vibratoThreeDepthSlider.setRange(0.0, 10.0, 0.01);
    vibratoThreeDepthSlider.setValue(audioProcessor.getValue("V3D"));
    vibratoThreeDepthSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    vibratoThreeDepthSlider.setLookAndFeel(&vibratoThreeDepthSliderLookAndFeel);
    vibratoThreeDepthSlider.addListener(this);
    addAndMakeVisible(&vibratoThreeDepthSlider);

    vibratoThreeRateSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    vibratoThreeRateSlider.setRange(0.01, 10.0, 0.001);
    vibratoThreeRateSlider.setValue(audioProcessor.getValue("V3R"));
    vibratoThreeRateSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    vibratoThreeRateSlider.setLookAndFeel(&vibratoThreeDepthSliderLookAndFeel);
    vibratoThreeRateSlider.addListener(this);
    addAndMakeVisible(&vibratoThreeRateSlider);

    vibratoFourDepthSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    vibratoFourDepthSlider.setRange(0.0, 10.0, 0.01);
    vibratoFourDepthSlider.setValue(audioProcessor.getValue("V4D"));
    vibratoFourDepthSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    vibratoFourDepthSlider.setLookAndFeel(&vibratoFourDepthSliderLookAndFeel);
    vibratoFourDepthSlider.addListener(this);
    addAndMakeVisible(&vibratoFourDepthSlider);

    vibratoFourRateSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    vibratoFourRateSlider.setRange(0.01, 10.0, 0.001);
    vibratoFourRateSlider.setValue(audioProcessor.getValue("V4R"));
    vibratoFourRateSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    vibratoFourRateSlider.setLookAndFeel(&vibratoFourRateSliderLookAndFeel);
    vibratoFourDepthSlider.addListener(this);
    addAndMakeVisible(&vibratoFourRateSlider);

    chorusOneMixSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    chorusOneMixSlider.setRange(0.0, 100.0, 0.1);
    chorusOneMixSlider.setValue(audioProcessor.getValue("C1M"));
    chorusOneMixSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    chorusOneMixSlider.setLookAndFeel(&chorusOneMixSliderLookAndFeel);
    chorusOneMixSlider.addListener(this);
    addAndMakeVisible(&chorusOneMixSlider);

    chorusTwoMixSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    chorusTwoMixSlider.setRange(0.0, 100.0, 0.1);
    chorusTwoMixSlider.setValue(audioProcessor.getValue("C2M"));
    chorusTwoMixSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    chorusTwoMixSlider.setLookAndFeel(&chorusTwoMixSliderLookAndFeel);
    chorusTwoMixSlider.addListener(this);
    addAndMakeVisible(&chorusTwoMixSlider);

    chorusThreeMixSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    chorusThreeMixSlider.setRange(0.0, 100.0, 0.1);
    chorusThreeMixSlider.setValue(audioProcessor.getValue("C3M"));
    chorusThreeMixSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    chorusThreeMixSlider.setLookAndFeel(&chorusThreeMixSliderLookAndFeel);
    chorusThreeMixSlider.addListener(this);
    addAndMakeVisible(&chorusThreeMixSlider);

    chorusFourMixSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    chorusFourMixSlider.setRange(0.0, 100.0, 0.1);
    chorusFourMixSlider.setValue(audioProcessor.getValue("C4M"));
    chorusFourMixSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    chorusFourMixSlider.setLookAndFeel(&chorusFourMixSliderLookAndFeel);
    chorusFourMixSlider.addListener(this);
    addAndMakeVisible(&chorusFourMixSlider);

    delayOneMixSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    delayOneMixSlider.setRange(0.0, 100.0, 0.1);
    delayOneMixSlider.setValue(audioProcessor.getValue("D1M"));
    delayOneMixSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    delayOneMixSlider.setLookAndFeel(&delayOneMixSliderLookAndFeel);
    delayOneMixSlider.addListener(this);
    addAndMakeVisible(&delayOneMixSlider);

    delayTwoMixSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    delayTwoMixSlider.setRange(0.0, 100.0, 0.1);
    delayTwoMixSlider.setValue(audioProcessor.getValue("D2M"));
    delayTwoMixSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    delayTwoMixSlider.setLookAndFeel(&delayTwoMixSliderLookAndFeel);
    delayTwoMixSlider.addListener(this);
    addAndMakeVisible(&delayTwoMixSlider);

    delayThreeMixSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    delayThreeMixSlider.setRange(0.0, 100.0, 0.1);
    delayThreeMixSlider.setValue(audioProcessor.getValue("D3M"));
    delayThreeMixSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    delayThreeMixSlider.setLookAndFeel(&delayThreeMixSliderLookAndFeel);
    delayThreeMixSlider.addListener(this);
    addAndMakeVisible(&delayThreeMixSlider);

    delayFourMixSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    delayFourMixSlider.setRange(0.0, 100.0, 0.1);
    delayFourMixSlider.setValue(audioProcessor.getValue("D4M"));
    delayFourMixSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    delayFourMixSlider.setLookAndFeel(&delayFourMixSliderLookAndFeel);
    delayFourMixSlider.addListener(this);
    addAndMakeVisible(&delayFourMixSlider);

    flangerOneMixSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    flangerOneMixSlider.setRange(0.0, 100.0, 0.1);
    flangerOneMixSlider.setValue(audioProcessor.getValue("F1M"));
    flangerOneMixSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    flangerOneMixSlider.setLookAndFeel(&flangerOneMixSliderLookAndFeel);
    flangerOneMixSlider.addListener(this);
    addAndMakeVisible(&flangerOneMixSlider);

    flangerTwoMixSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    flangerTwoMixSlider.setRange(0.0, 100.0, 0.1);
    flangerTwoMixSlider.setValue(audioProcessor.getValue("F2M"));
    flangerTwoMixSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    flangerTwoMixSlider.setLookAndFeel(&flangerTwoMixSliderLookAndFeel);
    flangerTwoMixSlider.addListener(this);
    addAndMakeVisible(&flangerTwoMixSlider);

    flangerThreeMixSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    flangerThreeMixSlider.setRange(0.0, 100.0, 0.1);
    flangerThreeMixSlider.setValue(audioProcessor.getValue("F3M"));
    flangerThreeMixSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    flangerThreeMixSlider.setLookAndFeel(&flangerThreeMixSliderLookAndFeel);
    flangerThreeMixSlider.addListener(this);
    addAndMakeVisible(&flangerThreeMixSlider);

    flangerFourMixSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    flangerFourMixSlider.setRange(0.0, 100.0, 0.1);
    flangerFourMixSlider.setValue(audioProcessor.getValue("F4M"));
    flangerFourMixSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    flangerFourMixSlider.setLookAndFeel(&flangerFourMixSliderLookAndFeel);
    flangerFourMixSlider.addListener(this);
    addAndMakeVisible(&flangerFourMixSlider);

    slotOneComboBox.addItem("None", 1);
    slotOneComboBox.addItem("Chorus", 2);
    slotOneComboBox.addItem("Delay", 3);
    slotOneComboBox.addItem("Flanger", 4);
    slotOneComboBox.addItem("Vibrato", 5);
    slotOneComboBox.setSelectedId(audioProcessor.getValue("S1"));
    slotOneComboBox.addListener(this);
    addAndMakeVisible(&slotOneComboBox);

    slotTwoComboBox.addItem("None", 1);
    slotTwoComboBox.addItem("Chorus", 2);
    slotTwoComboBox.addItem("Delay", 3);
    slotTwoComboBox.addItem("Flanger", 4);
    slotTwoComboBox.addItem("Vibrato", 5);
    slotTwoComboBox.setSelectedId(audioProcessor.getValue("S2"));
    slotTwoComboBox.addListener(this);
    addAndMakeVisible(&slotTwoComboBox);

    slotThreeComboBox.addItem("None", 1);
    slotThreeComboBox.addItem("Chorus", 2);
    slotThreeComboBox.addItem("Delay", 3);
    slotThreeComboBox.addItem("Flanger", 4);
    slotThreeComboBox.addItem("Vibrato", 5);
    slotThreeComboBox.setSelectedId(audioProcessor.getValue("S3"));
    slotThreeComboBox.addListener(this);
    addAndMakeVisible(&slotThreeComboBox);

    slotFourComboBox.addItem("None", 1);
    slotFourComboBox.addItem("Chorus", 2);
    slotFourComboBox.addItem("Delay", 3);
    slotFourComboBox.addItem("Flanger", 4);
    slotFourComboBox.addItem("Vibrato", 5);
    slotFourComboBox.setSelectedId(audioProcessor.getValue("S4"));
    slotFourComboBox.addListener(this);
    addAndMakeVisible(&slotFourComboBox);

    chorusOneDepthIndicator.setJustificationType(Justification::centred);
    chorusOneDepthIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    chorusOneDepthIndicator.setText(String(chorusOneDepthSlider.getValue()) + " ms", dontSendNotification);
    chorusOneDepthIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&chorusOneDepthIndicator);

    chorusOneVoicesIndicator.setJustificationType(Justification::centred);
    chorusOneVoicesIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    chorusOneVoicesIndicator.setText(String(chorusOneVoicesSlider.getValue()), dontSendNotification);
    chorusOneVoicesIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&chorusOneVoicesIndicator);

    chorusOneMixIndicator.setJustificationType(Justification::centred);
    chorusOneMixIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    chorusOneMixIndicator.setText(String(chorusOneMixSlider.getValue()) + " %", dontSendNotification);
    chorusOneMixIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&chorusOneMixIndicator);

    delayOneTimeIndicator.setJustificationType(Justification::centred);
    delayOneTimeIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    String timeinBars;
    if (delayOneTimeSlider.getValue() == 0.0) {
        timeinBars = "1/32";
    }
    else if (delayOneTimeSlider.getValue() == 12.5) {
        timeinBars = "1/16";
    }
    else if (delayOneTimeSlider.getValue() == 25.0) {
        timeinBars = "1/8";
    }
    else if (delayOneTimeSlider.getValue() == 37.5) {
        timeinBars = "1/4";
    }
    else if (delayOneTimeSlider.getValue() == 50.0) {
        timeinBars = "1/2";
    }
    else if (delayOneTimeSlider.getValue() == 62.5) {
        timeinBars = "1";
    }
    else if (delayOneTimeSlider.getValue() == 75.0) {
        timeinBars = "2";
    }
    else if (delayOneTimeSlider.getValue() == 87.5) {
        timeinBars = "4";
    }
    else if (delayOneTimeSlider.getValue() == 100.0) {
        timeinBars = "8";
    }
    delayOneTimeIndicator.setText(timeinBars, dontSendNotification);
    delayOneTimeIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&delayOneTimeIndicator);

    delayOneFeedbackIndicator.setJustificationType(Justification::centred);
    delayOneFeedbackIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    delayOneFeedbackIndicator.setText(String(delayOneFeedbackSlider.getValue()) + " %", dontSendNotification);
    delayOneFeedbackIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&delayOneFeedbackIndicator);

    delayOneMixIndicator.setJustificationType(Justification::centred);
    delayOneMixIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    delayOneMixIndicator.setText(String(delayOneMixSlider.getValue()) + " %", dontSendNotification);
    delayOneMixIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&delayOneMixIndicator);

    flangerOneDepthIndicator.setJustificationType(Justification::centred);
    flangerOneDepthIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    flangerOneDepthIndicator.setText(String(flangerOneDepthSlider.getValue()) + " ms", dontSendNotification);
    flangerOneDepthIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&flangerOneDepthIndicator);

    flangerOneRateIndicator.setJustificationType(Justification::centred);
    flangerOneRateIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    flangerOneRateIndicator.setText(String(flangerOneRateSlider.getValue()) + " Hz", dontSendNotification);
    flangerOneRateIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&flangerOneRateIndicator);

    flangerOneMixIndicator.setJustificationType(Justification::centred);
    flangerOneMixIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    flangerOneMixIndicator.setText(String(flangerOneMixSlider.getValue()) + " %", dontSendNotification);
    flangerOneMixIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&flangerOneMixIndicator);

    vibratoOneDepthIndicator.setJustificationType(Justification::centred);
    vibratoOneDepthIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    vibratoOneDepthIndicator.setText(String(vibratoOneDepthSlider.getValue()) + " ms", dontSendNotification);
    vibratoOneDepthIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&vibratoOneDepthIndicator);

    vibratoOneRateIndicator.setJustificationType(Justification::centred);
    vibratoOneRateIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    vibratoOneRateIndicator.setText(String(vibratoOneRateSlider.getValue()) + " Hz", dontSendNotification);
    vibratoOneRateIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&vibratoOneRateIndicator);

    chorusOneDepthLabel.setJustificationType(Justification::centred);
    chorusOneDepthLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    chorusOneDepthLabel.setText("DEPTH", dontSendNotification);
    chorusOneDepthLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&chorusOneDepthLabel);

    chorusOneVoicesLabel.setJustificationType(Justification::centred);
    chorusOneVoicesLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    chorusOneVoicesLabel.setText("VOICES", dontSendNotification);
    chorusOneVoicesLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&chorusOneVoicesLabel);

    chorusOneMixLabel.setJustificationType(Justification::centred);
    chorusOneMixLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    chorusOneMixLabel.setText("MIX", dontSendNotification);
    chorusOneMixLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&chorusOneMixLabel);

    delayOneTimeLabel.setJustificationType(Justification::centred);
    delayOneTimeLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    delayOneTimeLabel.setText("TIME", dontSendNotification);
    delayOneTimeLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&delayOneTimeLabel);

    delayOneFeedbackLabel.setJustificationType(Justification::centred);
    delayOneFeedbackLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    delayOneFeedbackLabel.setText("FEEDBACK", dontSendNotification);
    delayOneFeedbackLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&delayOneFeedbackLabel);

    delayOneMixLabel.setJustificationType(Justification::centred);
    delayOneMixLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    delayOneMixLabel.setText("MIX", dontSendNotification);
    delayOneMixLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&delayOneMixLabel);

    flangerOneDepthLabel.setJustificationType(Justification::centred);
    flangerOneDepthLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    flangerOneDepthLabel.setText("DEPTH", dontSendNotification);
    flangerOneDepthLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&flangerOneDepthLabel);

    flangerOneRateLabel.setJustificationType(Justification::centred);
    flangerOneRateLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    flangerOneRateLabel.setText("RATE", dontSendNotification);
    flangerOneRateLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&flangerOneRateLabel);

    flangerOneMixLabel.setJustificationType(Justification::centred);
    flangerOneMixLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    flangerOneMixLabel.setText("MIX", dontSendNotification);
    flangerOneMixLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&flangerOneMixLabel);

    vibratoOneDepthLabel.setJustificationType(Justification::centred);
    vibratoOneDepthLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    vibratoOneDepthLabel.setText("DEPTH", dontSendNotification);
    vibratoOneDepthLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&vibratoOneDepthLabel);

    vibratoOneRateLabel.setJustificationType(Justification::centred);
    vibratoOneRateLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    vibratoOneRateLabel.setText("RATE", dontSendNotification);
    vibratoOneRateLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&vibratoOneRateLabel);
}

PulpfictionAudioProcessorEditor::~PulpfictionAudioProcessorEditor()
{
}

//==============================================================================
void PulpfictionAudioProcessorEditor::paint (juce::Graphics& g)
{
    ColourGradient fillGradient(Colour::fromRGB(0xE5, 0xF0, 0xF0), slotOneRectangle.getCentreX(), 0, Colour::fromRGB(0xE0, 0xE5, 0xE5), slotOneRectangle.getCentreX(), getBottom(), false);
    g.setGradientFill(fillGradient);
    g.fillAll();

    DropShadow slotShadow(Colour::fromFloatRGBA(0.0, 0.0, 0.0, 0.25), 10, Point<int>(5, 5));
    if (slotOneComboBox.getSelectedId() != 1) slotShadow.drawForRectangle(g, slotOneRectangle.toNearestInt());
    if (slotTwoComboBox.getSelectedId() != 1) slotShadow.drawForRectangle(g, slotTwoRectangle.toNearestInt());
    if (slotThreeComboBox.getSelectedId() != 1) slotShadow.drawForRectangle(g, slotThreeRectangle.toNearestInt());
    if (slotFourComboBox.getSelectedId() != 1) slotShadow.drawForRectangle(g, slotFourRectangle.toNearestInt());
    
    if (slotOneComboBox.getSelectedId() == 2) {
        ColourGradient slotOneGradient(Colour::fromRGB(0x30, 0xA0, 0xFF), slotOneRectangle.getCentreX(), 0, Colour::fromRGB(0xFF, 0x30, 0x70), slotOneRectangle.getCentreX(), getBottom(), false);
        g.setGradientFill(slotOneGradient);
        g.fillRoundedRectangle(slotOneRectangle, 5);
    }
    else if (slotOneComboBox.getSelectedId() == 3) {
        ColourGradient slotOneGradient(Colour::fromRGB(0x05, 0xD5, 0x10), slotOneRectangle.getCentreX(), 0, Colour::fromRGB(0x80, 0xB0, 0xFF), slotOneRectangle.getCentreX(), getBottom(), false);
        g.setGradientFill(slotOneGradient);
        g.fillRoundedRectangle(slotOneRectangle, 5);
    }
    else if (slotOneComboBox.getSelectedId() == 4) {
        ColourGradient slotOneGradient(Colour::fromRGB(0xFF, 0x00, 0xD5), slotOneRectangle.getCentreX(), 0, Colour::fromRGB(0xFF, 0x95, 0x20), slotOneRectangle.getCentreX(), getBottom(), false);
        g.setGradientFill(slotOneGradient);
        g.fillRoundedRectangle(slotOneRectangle, 5);
    }
    else if (slotOneComboBox.getSelectedId() == 5) {
        ColourGradient slotOneGradient(Colour::fromRGB(0x00, 0x40, 0x90), slotOneRectangle.getCentreX(), 0, Colour::fromRGB(0x80, 0xFF, 0xFF), slotOneRectangle.getCentreX(), getBottom(), false);
        g.setGradientFill(slotOneGradient);
        g.fillRoundedRectangle(slotOneRectangle, 5);
    }

    if (slotTwoComboBox.getSelectedId() == 2) {
        ColourGradient slotTwoGradient(Colour::fromRGB(0x30, 0xA0, 0xFF), slotTwoRectangle.getCentreX(), 0, Colour::fromRGB(0xFF, 0x30, 0x70), slotTwoRectangle.getCentreX(), getBottom(), false);
        g.setGradientFill(slotTwoGradient);
        g.fillRoundedRectangle(slotTwoRectangle, 5);
    }
    else if (slotTwoComboBox.getSelectedId() == 3) {
        ColourGradient slotTwoGradient(Colour::fromRGB(0x05, 0xD5, 0x10), slotTwoRectangle.getCentreX(), 0, Colour::fromRGB(0x80, 0xB0, 0xFF), slotTwoRectangle.getCentreX(), getBottom(), false);
        g.setGradientFill(slotTwoGradient);
        g.fillRoundedRectangle(slotTwoRectangle, 5);
    }
    else if (slotTwoComboBox.getSelectedId() == 4) {
        ColourGradient slotTwoGradient(Colour::fromRGB(0xFF, 0x00, 0xD5), slotTwoRectangle.getCentreX(), 0, Colour::fromRGB(0xFF, 0x95, 0x20), slotTwoRectangle.getCentreX(), getBottom(), false);
        g.setGradientFill(slotTwoGradient);
        g.fillRoundedRectangle(slotTwoRectangle, 5);
    }
    else if (slotTwoComboBox.getSelectedId() == 5) {
        ColourGradient slotTwoGradient(Colour::fromRGB(0x00, 0x40, 0x90), slotTwoRectangle.getCentreX(), 0, Colour::fromRGB(0x80, 0xFF, 0xFF), slotTwoRectangle.getCentreX(), getBottom(), false);
        g.setGradientFill(slotTwoGradient);
        g.fillRoundedRectangle(slotTwoRectangle, 5);
    }

    if (slotThreeComboBox.getSelectedId() == 2) {
        ColourGradient slotThreeGradient(Colour::fromRGB(0x30, 0xA0, 0xFF), slotThreeRectangle.getCentreX(), 0, Colour::fromRGB(0xFF, 0x30, 0x70), slotThreeRectangle.getCentreX(), getBottom(), false);
        g.setGradientFill(slotThreeGradient);
        g.fillRoundedRectangle(slotThreeRectangle, 5);
    }
    else if (slotThreeComboBox.getSelectedId() == 3) {
        ColourGradient slotThreeGradient(Colour::fromRGB(0x05, 0xD5, 0x10), slotThreeRectangle.getCentreX(), 0, Colour::fromRGB(0x80, 0xB0, 0xFF), slotThreeRectangle.getCentreX(), getBottom(), false);
        g.setGradientFill(slotThreeGradient);
        g.fillRoundedRectangle(slotThreeRectangle, 5);
    }
    else if (slotThreeComboBox.getSelectedId() == 4) {
        ColourGradient slotThreeGradient(Colour::fromRGB(0xFF, 0x00, 0xD5), slotThreeRectangle.getCentreX(), 0, Colour::fromRGB(0xFF, 0x95, 0x20), slotThreeRectangle.getCentreX(), getBottom(), false);
        g.setGradientFill(slotThreeGradient);
        g.fillRoundedRectangle(slotThreeRectangle, 5);
    }
    else if (slotThreeComboBox.getSelectedId() == 5) {
        ColourGradient slotThreeGradient(Colour::fromRGB(0x00, 0x40, 0x90), slotThreeRectangle.getCentreX(), 0, Colour::fromRGB(0x80, 0xFF, 0xFF), slotThreeRectangle.getCentreX(), getBottom(), false);
        g.setGradientFill(slotThreeGradient);
        g.fillRoundedRectangle(slotThreeRectangle, 5);
    }

    if (slotFourComboBox.getSelectedId() == 2) {
        ColourGradient slotFourGradient(Colour::fromRGB(0x30, 0xA0, 0xFF), slotFourRectangle.getCentreX(), 0, Colour::fromRGB(0xFF, 0x30, 0x70), slotFourRectangle.getCentreX(), getBottom(), false);
        g.setGradientFill(slotFourGradient);
        g.fillRoundedRectangle(slotFourRectangle, 5);
    }
    else if (slotFourComboBox.getSelectedId() == 3) {
        ColourGradient slotFourGradient(Colour::fromRGB(0x05, 0xD5, 0x10), slotFourRectangle.getCentreX(), 0, Colour::fromRGB(0x80, 0xB0, 0xFF), slotFourRectangle.getCentreX(), getBottom(), false);
        g.setGradientFill(slotFourGradient);
        g.fillRoundedRectangle(slotFourRectangle, 5);
    }
    else if (slotFourComboBox.getSelectedId() == 4) {
        ColourGradient slotFourGradient(Colour::fromRGB(0xFF, 0x00, 0xD5), slotFourRectangle.getCentreX(), 0, Colour::fromRGB(0xFF, 0x95, 0x20), slotFourRectangle.getCentreX(), getBottom(), false);
        g.setGradientFill(slotFourGradient);
        g.fillRoundedRectangle(slotFourRectangle, 5);
    }
    else if (slotFourComboBox.getSelectedId() == 5) {
        ColourGradient slotFourGradient(Colour::fromRGB(0x00, 0x40, 0x90), slotFourRectangle.getCentreX(), 0, Colour::fromRGB(0x80, 0xFF, 0xFF), slotFourRectangle.getCentreX(), getBottom(), false);
        g.setGradientFill(slotFourGradient);
        g.fillRoundedRectangle(slotFourRectangle, 5);
    }
}

void PulpfictionAudioProcessorEditor::resized()
{
    slotOneComboBox.setBounds(50, 20, 150, 20);
    slotTwoComboBox.setBounds(250, 20, 150, 20);
    slotThreeComboBox.setBounds(450, 20, 150, 20);
    slotFourComboBox.setBounds(650, 20, 150, 20);

    chorusOneDepthSlider.setBounds(50, 100, 70, 70);
    chorusOneVoicesSlider.setBounds(130, 100, 70, 70);
    chorusTwoDepthSlider.setBounds(250, 100, 70, 70);
    chorusTwoVoicesSlider.setBounds(330, 100, 70, 70);
    chorusThreeDepthSlider.setBounds(450, 100, 70, 70);
    chorusThreeVoicesSlider.setBounds(530, 100, 70, 70);
    chorusFourDepthSlider.setBounds(650, 100, 70, 70);
    chorusFourVoicesSlider.setBounds(730, 100, 70, 70);

    delayOneTimeSlider.setBounds(50, 100, 70, 70);
    delayOneFeedbackSlider.setBounds(130, 100, 70, 70);
    delayTwoTimeSlider.setBounds(250, 100, 70, 70);
    delayTwoFeedbackSlider.setBounds(330, 100, 70, 70);
    delayThreeTimeSlider.setBounds(450, 100, 70, 70);
    delayThreeFeedbackSlider.setBounds(530, 100, 70, 70);
    delayFourTimeSlider.setBounds(650, 100, 70, 70);
    delayFourFeedbackSlider.setBounds(730, 100, 70, 70);

    flangerOneDepthSlider.setBounds(50, 100, 70, 70);
    flangerOneRateSlider.setBounds(130, 100, 70, 70);
    flangerTwoDepthSlider.setBounds(250, 100, 70, 70);
    flangerTwoRateSlider.setBounds(330, 100, 70, 70);
    flangerThreeDepthSlider.setBounds(450, 100, 70, 70);
    flangerThreeRateSlider.setBounds(530, 100, 70, 70);
    flangerFourDepthSlider.setBounds(650, 100, 70, 70);
    flangerFourRateSlider.setBounds(730, 100, 70, 70);

    vibratoOneDepthSlider.setBounds(50, 100, 70, 70);
    vibratoOneRateSlider.setBounds(130, 200, 70, 70);
    vibratoTwoDepthSlider.setBounds(250, 100, 70, 70);
    vibratoTwoRateSlider.setBounds(330, 200, 70, 70);
    vibratoThreeDepthSlider.setBounds(450, 100, 70, 70);
    vibratoThreeRateSlider.setBounds(530, 200, 70, 70);
    vibratoFourDepthSlider.setBounds(650, 100, 70, 70);
    vibratoFourRateSlider.setBounds(730, 200, 70, 70);

    chorusOneMixSlider.setBounds(50, 200, 100, 100);
    chorusTwoMixSlider.setBounds(250, 200, 100, 100);
    chorusThreeMixSlider.setBounds(450, 200, 100, 100);
    chorusFourMixSlider.setBounds(650, 200, 100, 100);

    delayOneMixSlider.setBounds(50, 200, 100, 100);
    delayTwoMixSlider.setBounds(250, 200, 100, 100);
    delayThreeMixSlider.setBounds(450, 200, 100, 100);
    delayFourMixSlider.setBounds(650, 200, 100, 100);

    flangerOneMixSlider.setBounds(50, 200, 100, 100);
    flangerTwoMixSlider.setBounds(250, 200, 100, 100);
    flangerThreeMixSlider.setBounds(450, 200, 100, 100);
    flangerFourMixSlider.setBounds(650, 200, 100, 100);

    slotOneRectangle.setBounds(50, 100, 150, 250);
    slotTwoRectangle.setBounds(250, 100, 150, 250);
    slotThreeRectangle.setBounds(450, 100, 150, 250);
    slotFourRectangle.setBounds(650, 100, 150, 250);

    chorusOneDepthIndicator.setBounds(35, 125, 100, 20);
    chorusOneVoicesIndicator.setBounds(115, 125, 100, 20);
    chorusOneMixIndicator.setBounds(50, 240, 100, 20);

    delayOneTimeIndicator.setBounds(35, 125, 100, 20);
    delayOneFeedbackIndicator.setBounds(115, 125, 100, 20);
    delayOneMixIndicator.setBounds(50, 240, 100, 20);

    flangerOneDepthIndicator.setBounds(35, 125, 100, 20);
    flangerOneRateIndicator.setBounds(115, 125, 100, 20);
    flangerOneMixIndicator.setBounds(50, 240, 100, 20);

    vibratoOneDepthIndicator.setBounds(35, 125, 100, 20);
    vibratoOneRateIndicator.setBounds(115, 225, 100, 20);

    chorusOneDepthLabel.setBounds(35, 175, 100, 20);
    chorusOneVoicesLabel.setBounds(115, 175, 100, 20);
    chorusOneMixLabel.setBounds(50, 305, 100, 20);

    delayOneTimeLabel.setBounds(35, 175, 100, 20);
    delayOneFeedbackLabel.setBounds(115, 175, 100, 20);
    delayOneMixLabel.setBounds(50, 305, 100, 20);

    flangerOneDepthLabel.setBounds(35, 175, 100, 20);
    flangerOneRateLabel.setBounds(115, 175, 100, 20);
    flangerOneMixLabel.setBounds(50, 305, 100, 20);

    vibratoOneDepthLabel.setBounds(35, 175, 100, 20);
    vibratoOneRateLabel.setBounds(115, 275, 100, 20);
}

void PulpfictionAudioProcessorEditor::comboBoxChanged(ComboBox* comboBox) {
    if (comboBox == &slotOneComboBox) {
        switch (slotOneComboBox.getSelectedId()) {
        case 1:
            chorusOneDepthSlider.setEnabled(false);
            chorusOneDepthSlider.setVisible(false);
            chorusOneVoicesSlider.setEnabled(false);
            chorusOneVoicesSlider.setVisible(false);

            delayOneTimeSlider.setEnabled(false);
            delayOneTimeSlider.setVisible(false);
            delayOneFeedbackSlider.setEnabled(false);
            delayOneFeedbackSlider.setVisible(false);

            flangerOneDepthSlider.setEnabled(false);
            flangerOneDepthSlider.setVisible(false);
            flangerOneRateSlider.setEnabled(false);
            flangerOneRateSlider.setVisible(false);

            vibratoOneDepthSlider.setEnabled(false);
            vibratoOneDepthSlider.setVisible(false);
            vibratoOneRateSlider.setEnabled(false);
            vibratoOneRateSlider.setVisible(false);

            chorusOneMixSlider.setEnabled(false);
            chorusOneMixSlider.setVisible(false);
            delayOneMixSlider.setEnabled(false);
            delayOneMixSlider.setVisible(false);
            flangerOneMixSlider.setEnabled(false);
            flangerOneMixSlider.setVisible(false);

            chorusOneDepthIndicator.setVisible(false);
            chorusOneVoicesIndicator.setVisible(false);
            chorusOneMixIndicator.setVisible(false);

            delayOneTimeIndicator.setVisible(false);
            delayOneFeedbackIndicator.setVisible(false);
            delayOneMixIndicator.setVisible(false);

            flangerOneDepthIndicator.setVisible(false);
            flangerOneRateIndicator.setVisible(false);
            flangerOneMixIndicator.setVisible(false);

            vibratoOneDepthIndicator.setVisible(false);
            vibratoOneRateIndicator.setVisible(false);

            chorusOneDepthLabel.setVisible(false);
            chorusOneVoicesLabel.setVisible(false);
            chorusOneMixLabel.setVisible(false);

            delayOneTimeLabel.setVisible(false);
            delayOneFeedbackLabel.setVisible(false);
            delayOneMixLabel.setVisible(false);

            flangerOneDepthLabel.setVisible(false);
            flangerOneRateLabel.setVisible(false);
            flangerOneMixLabel.setVisible(false);

            vibratoOneDepthLabel.setVisible(false);
            vibratoOneRateLabel.setVisible(false);

            break;

        case 2:
            chorusOneDepthSlider.setEnabled(true);
            chorusOneDepthSlider.setVisible(true);
            chorusOneVoicesSlider.setEnabled(true);
            chorusOneVoicesSlider.setVisible(true);

            delayOneTimeSlider.setEnabled(false);
            delayOneTimeSlider.setVisible(false);
            delayOneFeedbackSlider.setEnabled(false);
            delayOneFeedbackSlider.setVisible(false);

            flangerOneDepthSlider.setEnabled(false);
            flangerOneDepthSlider.setVisible(false);
            flangerOneRateSlider.setEnabled(false);
            flangerOneRateSlider.setVisible(false);

            vibratoOneDepthSlider.setEnabled(false);
            vibratoOneDepthSlider.setVisible(false);
            vibratoOneRateSlider.setEnabled(false);
            vibratoOneRateSlider.setVisible(false);

            chorusOneMixSlider.setEnabled(true);
            chorusOneMixSlider.setVisible(true);
            delayOneMixSlider.setEnabled(false);
            delayOneMixSlider.setVisible(false);
            flangerOneMixSlider.setEnabled(false);
            flangerOneMixSlider.setVisible(false);

            chorusOneDepthIndicator.setVisible(true);
            chorusOneVoicesIndicator.setVisible(true);
            chorusOneMixIndicator.setVisible(true);

            delayOneTimeIndicator.setVisible(false);
            delayOneFeedbackIndicator.setVisible(false);
            delayOneMixIndicator.setVisible(false);

            flangerOneDepthIndicator.setVisible(false);
            flangerOneRateIndicator.setVisible(false);
            flangerOneMixIndicator.setVisible(false);

            vibratoOneDepthIndicator.setVisible(false);
            vibratoOneRateIndicator.setVisible(false);

            chorusOneDepthLabel.setVisible(true);
            chorusOneVoicesLabel.setVisible(true);
            chorusOneMixLabel.setVisible(true);

            delayOneTimeLabel.setVisible(false);
            delayOneFeedbackLabel.setVisible(false);
            delayOneMixLabel.setVisible(false);

            flangerOneDepthLabel.setVisible(false);
            flangerOneRateLabel.setVisible(false);
            flangerOneMixLabel.setVisible(false);

            vibratoOneDepthLabel.setVisible(false);
            vibratoOneRateLabel.setVisible(false);

            break;

        case 3:
            chorusOneDepthSlider.setEnabled(false);
            chorusOneDepthSlider.setVisible(false);
            chorusOneVoicesSlider.setEnabled(false);
            chorusOneVoicesSlider.setVisible(false);

            delayOneTimeSlider.setEnabled(true);
            delayOneTimeSlider.setVisible(true);
            delayOneFeedbackSlider.setEnabled(true);
            delayOneFeedbackSlider.setVisible(true);

            flangerOneDepthSlider.setEnabled(false);
            flangerOneDepthSlider.setVisible(false);
            flangerOneRateSlider.setEnabled(false);
            flangerOneRateSlider.setVisible(false);

            vibratoOneDepthSlider.setEnabled(false);
            vibratoOneDepthSlider.setVisible(false);
            vibratoOneRateSlider.setEnabled(false);
            vibratoOneRateSlider.setVisible(false);

            chorusOneMixSlider.setEnabled(false);
            chorusOneMixSlider.setVisible(false);
            delayOneMixSlider.setEnabled(true);
            delayOneMixSlider.setVisible(true);
            flangerOneMixSlider.setEnabled(false);
            flangerOneMixSlider.setVisible(false);

            chorusOneDepthIndicator.setVisible(false);
            chorusOneVoicesIndicator.setVisible(false);
            chorusOneMixIndicator.setVisible(false);

            delayOneTimeIndicator.setVisible(true);
            delayOneFeedbackIndicator.setVisible(true);
            delayOneMixIndicator.setVisible(true);

            flangerOneDepthIndicator.setVisible(false);
            flangerOneRateIndicator.setVisible(false);
            flangerOneMixIndicator.setVisible(false);

            vibratoOneDepthIndicator.setVisible(false);
            vibratoOneRateIndicator.setVisible(false);

            chorusOneDepthLabel.setVisible(false);
            chorusOneVoicesLabel.setVisible(false);
            chorusOneMixLabel.setVisible(false);

            delayOneTimeLabel.setVisible(true);
            delayOneFeedbackLabel.setVisible(true);
            delayOneMixLabel.setVisible(true);

            flangerOneDepthLabel.setVisible(false);
            flangerOneRateLabel.setVisible(false);
            flangerOneMixLabel.setVisible(false);

            vibratoOneDepthLabel.setVisible(false);
            vibratoOneRateLabel.setVisible(false);

            break;

        case 4:
            chorusOneDepthSlider.setEnabled(false);
            chorusOneDepthSlider.setVisible(false);
            chorusOneVoicesSlider.setEnabled(false);
            chorusOneVoicesSlider.setVisible(false);

            delayOneTimeSlider.setEnabled(false);
            delayOneTimeSlider.setVisible(false);
            delayOneFeedbackSlider.setEnabled(false);
            delayOneFeedbackSlider.setVisible(false);

            flangerOneDepthSlider.setEnabled(true);
            flangerOneDepthSlider.setVisible(true);
            flangerOneRateSlider.setEnabled(true);
            flangerOneRateSlider.setVisible(true);

            vibratoOneDepthSlider.setEnabled(false);
            vibratoOneDepthSlider.setVisible(false);
            vibratoOneRateSlider.setEnabled(false);
            vibratoOneRateSlider.setVisible(false);

            chorusOneMixSlider.setEnabled(false);
            chorusOneMixSlider.setVisible(false);
            delayOneMixSlider.setEnabled(false);
            delayOneMixSlider.setVisible(false);
            flangerOneMixSlider.setEnabled(true);
            flangerOneMixSlider.setVisible(true);

            chorusOneDepthIndicator.setVisible(false);
            chorusOneVoicesIndicator.setVisible(false);
            chorusOneMixIndicator.setVisible(false);

            delayOneTimeIndicator.setVisible(false);
            delayOneFeedbackIndicator.setVisible(false);
            delayOneMixIndicator.setVisible(false);

            flangerOneDepthIndicator.setVisible(true);
            flangerOneRateIndicator.setVisible(true);
            flangerOneMixIndicator.setVisible(true);

            vibratoOneDepthIndicator.setVisible(false);
            vibratoOneRateIndicator.setVisible(false);

            chorusOneDepthLabel.setVisible(false);
            chorusOneVoicesLabel.setVisible(false);
            chorusOneMixLabel.setVisible(false);

            delayOneTimeLabel.setVisible(false);
            delayOneFeedbackLabel.setVisible(false);
            delayOneMixLabel.setVisible(false);

            flangerOneDepthLabel.setVisible(true);
            flangerOneRateLabel.setVisible(true);
            flangerOneMixLabel.setVisible(true);

            vibratoOneDepthLabel.setVisible(false);
            vibratoOneRateLabel.setVisible(false);

            break;

        case 5:
            chorusOneDepthSlider.setEnabled(false);
            chorusOneDepthSlider.setVisible(false);
            chorusOneVoicesSlider.setEnabled(false);
            chorusOneVoicesSlider.setVisible(false);

            delayOneTimeSlider.setEnabled(false);
            delayOneTimeSlider.setVisible(false);
            delayOneFeedbackSlider.setEnabled(false);
            delayOneFeedbackSlider.setVisible(false);

            flangerOneDepthSlider.setEnabled(false);
            flangerOneDepthSlider.setVisible(false);
            flangerOneRateSlider.setEnabled(false);
            flangerOneRateSlider.setVisible(false);

            vibratoOneDepthSlider.setEnabled(true);
            vibratoOneDepthSlider.setVisible(true);
            vibratoOneRateSlider.setEnabled(true);
            vibratoOneRateSlider.setVisible(true);

            chorusOneMixSlider.setEnabled(false);
            chorusOneMixSlider.setVisible(false);
            delayOneMixSlider.setEnabled(false);
            delayOneMixSlider.setVisible(false);
            flangerOneMixSlider.setEnabled(false);
            flangerOneMixSlider.setVisible(false);

            chorusOneDepthIndicator.setVisible(false);
            chorusOneVoicesIndicator.setVisible(false);
            chorusOneMixIndicator.setVisible(false);

            delayOneTimeIndicator.setVisible(false);
            delayOneFeedbackIndicator.setVisible(false);
            delayOneMixIndicator.setVisible(false);

            flangerOneDepthIndicator.setVisible(false);
            flangerOneRateIndicator.setVisible(false);
            flangerOneMixIndicator.setVisible(false);

            vibratoOneDepthIndicator.setVisible(true);
            vibratoOneRateIndicator.setVisible(true);

            chorusOneDepthLabel.setVisible(false);
            chorusOneVoicesLabel.setVisible(false);
            chorusOneMixLabel.setVisible(false);

            delayOneTimeLabel.setVisible(false);
            delayOneFeedbackLabel.setVisible(false);
            delayOneMixLabel.setVisible(false);

            flangerOneDepthLabel.setVisible(false);
            flangerOneRateLabel.setVisible(false);
            flangerOneMixLabel.setVisible(false);

            vibratoOneDepthLabel.setVisible(true);
            vibratoOneRateLabel.setVisible(true);

            break;

        default: break;
        }
    }

    else if (comboBox == &slotTwoComboBox) {
        switch (slotTwoComboBox.getSelectedId()) {
        case 1:
            chorusTwoDepthSlider.setEnabled(false);
            chorusTwoDepthSlider.setVisible(false);
            chorusTwoVoicesSlider.setEnabled(false);
            chorusTwoVoicesSlider.setVisible(false);

            delayTwoTimeSlider.setEnabled(false);
            delayTwoTimeSlider.setVisible(false);
            delayTwoFeedbackSlider.setEnabled(false);
            delayTwoFeedbackSlider.setVisible(false);

            flangerTwoDepthSlider.setEnabled(false);
            flangerTwoDepthSlider.setVisible(false);
            flangerTwoRateSlider.setEnabled(false);
            flangerTwoRateSlider.setVisible(false);

            vibratoTwoDepthSlider.setEnabled(false);
            vibratoTwoDepthSlider.setVisible(false);
            vibratoTwoRateSlider.setEnabled(false);
            vibratoTwoRateSlider.setVisible(false);
            
            chorusTwoMixSlider.setEnabled(false);
            chorusTwoMixSlider.setVisible(false);
            delayTwoMixSlider.setEnabled(false);
            delayTwoMixSlider.setVisible(false);
            flangerTwoMixSlider.setEnabled(false);
            flangerTwoMixSlider.setVisible(false);

            break;

        case 2:
            chorusTwoDepthSlider.setEnabled(true);
            chorusTwoDepthSlider.setVisible(true);
            chorusTwoVoicesSlider.setEnabled(true);
            chorusTwoVoicesSlider.setVisible(true);

            delayTwoTimeSlider.setEnabled(false);
            delayTwoTimeSlider.setVisible(false);
            delayTwoFeedbackSlider.setEnabled(false);
            delayTwoFeedbackSlider.setVisible(false);

            flangerTwoDepthSlider.setEnabled(false);
            flangerTwoDepthSlider.setVisible(false);
            flangerTwoRateSlider.setEnabled(false);
            flangerTwoRateSlider.setVisible(false);

            vibratoTwoDepthSlider.setEnabled(false);
            vibratoTwoDepthSlider.setVisible(false);
            vibratoTwoRateSlider.setEnabled(false);
            vibratoTwoRateSlider.setVisible(false);

            chorusTwoMixSlider.setEnabled(true);
            chorusTwoMixSlider.setVisible(true);
            delayTwoMixSlider.setEnabled(false);
            delayTwoMixSlider.setVisible(false);
            flangerTwoMixSlider.setEnabled(false);
            flangerTwoMixSlider.setVisible(false);

            break;

        case 3:
            chorusTwoDepthSlider.setEnabled(false);
            chorusTwoDepthSlider.setVisible(false);
            chorusTwoVoicesSlider.setEnabled(false);
            chorusTwoVoicesSlider.setVisible(false);

            delayTwoTimeSlider.setEnabled(true);
            delayTwoTimeSlider.setVisible(true);
            delayTwoFeedbackSlider.setEnabled(true);
            delayTwoFeedbackSlider.setVisible(true);

            flangerTwoDepthSlider.setEnabled(false);
            flangerTwoDepthSlider.setVisible(false);
            flangerTwoRateSlider.setEnabled(false);
            flangerTwoRateSlider.setVisible(false);

            vibratoTwoDepthSlider.setEnabled(false);
            vibratoTwoDepthSlider.setVisible(false);
            vibratoTwoRateSlider.setEnabled(false);
            vibratoTwoRateSlider.setVisible(false);

            chorusTwoMixSlider.setEnabled(false);
            chorusTwoMixSlider.setVisible(false);
            delayTwoMixSlider.setEnabled(true);
            delayTwoMixSlider.setVisible(true);
            flangerTwoMixSlider.setEnabled(false);
            flangerTwoMixSlider.setVisible(false);

            break;

        case 4:
            chorusTwoDepthSlider.setEnabled(false);
            chorusTwoDepthSlider.setVisible(false);
            chorusTwoVoicesSlider.setEnabled(false);
            chorusTwoVoicesSlider.setVisible(false);

            delayTwoTimeSlider.setEnabled(false);
            delayTwoTimeSlider.setVisible(false);
            delayTwoFeedbackSlider.setEnabled(false);
            delayTwoFeedbackSlider.setVisible(false);

            flangerTwoDepthSlider.setEnabled(true);
            flangerTwoDepthSlider.setVisible(true);
            flangerTwoRateSlider.setEnabled(true);
            flangerTwoRateSlider.setVisible(true);

            vibratoTwoDepthSlider.setEnabled(false);
            vibratoTwoDepthSlider.setVisible(false);
            vibratoTwoRateSlider.setEnabled(false);
            vibratoTwoRateSlider.setVisible(false);

            chorusTwoMixSlider.setEnabled(false);
            chorusTwoMixSlider.setVisible(false);
            delayTwoMixSlider.setEnabled(false);
            delayTwoMixSlider.setVisible(false);
            flangerTwoMixSlider.setEnabled(true);
            flangerTwoMixSlider.setVisible(true);

            break;

        case 5:
            chorusTwoDepthSlider.setEnabled(false);
            chorusTwoDepthSlider.setVisible(false);
            chorusTwoVoicesSlider.setEnabled(false);
            chorusTwoVoicesSlider.setVisible(false);

            delayTwoTimeSlider.setEnabled(false);
            delayTwoTimeSlider.setVisible(false);
            delayTwoFeedbackSlider.setEnabled(false);
            delayTwoFeedbackSlider.setVisible(false);

            flangerTwoDepthSlider.setEnabled(false);
            flangerTwoDepthSlider.setVisible(false);
            flangerTwoRateSlider.setEnabled(false);
            flangerTwoRateSlider.setVisible(false);

            vibratoTwoDepthSlider.setEnabled(true);
            vibratoTwoDepthSlider.setVisible(true);
            vibratoTwoRateSlider.setEnabled(true);
            vibratoTwoRateSlider.setVisible(true);

            chorusTwoMixSlider.setEnabled(false);
            chorusTwoMixSlider.setVisible(false);
            delayTwoMixSlider.setEnabled(false);
            delayTwoMixSlider.setVisible(false);
            flangerTwoMixSlider.setEnabled(false);
            flangerTwoMixSlider.setVisible(false);

            break;

        default: break;
        }
    }

    else if (comboBox == &slotThreeComboBox) {
        switch (slotThreeComboBox.getSelectedId()) {
        case 1:
            chorusThreeDepthSlider.setEnabled(false);
            chorusThreeDepthSlider.setVisible(false);
            chorusThreeVoicesSlider.setEnabled(false);
            chorusThreeVoicesSlider.setVisible(false);

            delayThreeTimeSlider.setEnabled(false);
            delayThreeTimeSlider.setVisible(false);
            delayThreeFeedbackSlider.setEnabled(false);
            delayThreeFeedbackSlider.setVisible(false);

            flangerThreeDepthSlider.setEnabled(false);
            flangerThreeDepthSlider.setVisible(false);
            flangerThreeRateSlider.setEnabled(false);
            flangerThreeRateSlider.setVisible(false);

            vibratoThreeDepthSlider.setEnabled(false);
            vibratoThreeDepthSlider.setVisible(false);
            vibratoThreeRateSlider.setEnabled(false);
            vibratoThreeRateSlider.setVisible(false);

            chorusThreeMixSlider.setEnabled(false);
            chorusThreeMixSlider.setVisible(false);
            delayThreeMixSlider.setEnabled(false);
            delayThreeMixSlider.setVisible(false);
            flangerThreeMixSlider.setEnabled(false);
            flangerThreeMixSlider.setVisible(false);

            break;

        case 2:
            chorusThreeDepthSlider.setEnabled(true);
            chorusThreeDepthSlider.setVisible(true);
            chorusThreeVoicesSlider.setEnabled(true);
            chorusThreeVoicesSlider.setVisible(true);

            delayThreeTimeSlider.setEnabled(false);
            delayThreeTimeSlider.setVisible(false);
            delayThreeFeedbackSlider.setEnabled(false);
            delayThreeFeedbackSlider.setVisible(false);

            flangerThreeDepthSlider.setEnabled(false);
            flangerThreeDepthSlider.setVisible(false);
            flangerThreeRateSlider.setEnabled(false);
            flangerThreeRateSlider.setVisible(false);

            vibratoThreeDepthSlider.setEnabled(false);
            vibratoThreeDepthSlider.setVisible(false);
            vibratoThreeRateSlider.setEnabled(false);
            vibratoThreeRateSlider.setVisible(false);

            chorusThreeMixSlider.setEnabled(true);
            chorusThreeMixSlider.setVisible(true);
            delayThreeMixSlider.setEnabled(false);
            delayThreeMixSlider.setVisible(false);
            flangerThreeMixSlider.setEnabled(false);
            flangerThreeMixSlider.setVisible(false);

            break;

        case 3:
            chorusThreeDepthSlider.setEnabled(false);
            chorusThreeDepthSlider.setVisible(false);
            chorusThreeVoicesSlider.setEnabled(false);
            chorusThreeVoicesSlider.setVisible(false);

            delayThreeTimeSlider.setEnabled(true);
            delayThreeTimeSlider.setVisible(true);
            delayThreeFeedbackSlider.setEnabled(true);
            delayThreeFeedbackSlider.setVisible(true);

            flangerThreeDepthSlider.setEnabled(false);
            flangerThreeDepthSlider.setVisible(false);
            flangerThreeRateSlider.setEnabled(false);
            flangerThreeRateSlider.setVisible(false);

            vibratoThreeDepthSlider.setEnabled(false);
            vibratoThreeDepthSlider.setVisible(false);
            vibratoThreeRateSlider.setEnabled(false);
            vibratoThreeRateSlider.setVisible(false);

            chorusThreeMixSlider.setEnabled(false);
            chorusThreeMixSlider.setVisible(false);
            delayThreeMixSlider.setEnabled(true);
            delayThreeMixSlider.setVisible(true);
            flangerThreeMixSlider.setEnabled(false);
            flangerThreeMixSlider.setVisible(false);

            break;

        case 4:
            chorusThreeDepthSlider.setEnabled(false);
            chorusThreeDepthSlider.setVisible(false);
            chorusThreeVoicesSlider.setEnabled(false);
            chorusThreeVoicesSlider.setVisible(false);

            delayThreeTimeSlider.setEnabled(false);
            delayThreeTimeSlider.setVisible(false);
            delayThreeFeedbackSlider.setEnabled(false);
            delayThreeFeedbackSlider.setVisible(false);

            flangerThreeDepthSlider.setEnabled(true);
            flangerThreeDepthSlider.setVisible(true);
            flangerThreeRateSlider.setEnabled(true);
            flangerThreeRateSlider.setVisible(true);

            vibratoThreeDepthSlider.setEnabled(false);
            vibratoThreeDepthSlider.setVisible(false);
            vibratoThreeRateSlider.setEnabled(false);
            vibratoThreeRateSlider.setVisible(false);

            chorusThreeMixSlider.setEnabled(false);
            chorusThreeMixSlider.setVisible(false);
            delayThreeMixSlider.setEnabled(false);
            delayThreeMixSlider.setVisible(false);
            flangerThreeMixSlider.setEnabled(true);
            flangerThreeMixSlider.setVisible(true);

            break;

        case 5:
            chorusThreeDepthSlider.setEnabled(false);
            chorusThreeDepthSlider.setVisible(false);
            chorusThreeVoicesSlider.setEnabled(false);
            chorusThreeVoicesSlider.setVisible(false);

            delayThreeTimeSlider.setEnabled(false);
            delayThreeTimeSlider.setVisible(false);
            delayThreeFeedbackSlider.setEnabled(false);
            delayThreeFeedbackSlider.setVisible(false);

            flangerThreeDepthSlider.setEnabled(false);
            flangerThreeDepthSlider.setVisible(false);
            flangerThreeRateSlider.setEnabled(false);
            flangerThreeRateSlider.setVisible(false);

            vibratoThreeDepthSlider.setEnabled(true);
            vibratoThreeDepthSlider.setVisible(true);
            vibratoThreeRateSlider.setEnabled(true);
            vibratoThreeRateSlider.setVisible(true);

            chorusThreeMixSlider.setEnabled(false);
            chorusThreeMixSlider.setVisible(false);
            delayThreeMixSlider.setEnabled(false);
            delayThreeMixSlider.setVisible(false);
            flangerThreeMixSlider.setEnabled(false);
            flangerThreeMixSlider.setVisible(false);

            break;

        default: break;
        }
    }

    else if (comboBox == &slotFourComboBox) {
        switch (slotFourComboBox.getSelectedId()) {
        case 1:
            chorusFourDepthSlider.setEnabled(false);
            chorusFourDepthSlider.setVisible(false);
            chorusFourVoicesSlider.setEnabled(false);
            chorusFourVoicesSlider.setVisible(false);

            delayFourTimeSlider.setEnabled(false);
            delayFourTimeSlider.setVisible(false);
            delayFourFeedbackSlider.setEnabled(false);
            delayFourFeedbackSlider.setVisible(false);

            flangerFourDepthSlider.setEnabled(false);
            flangerFourDepthSlider.setVisible(false);
            flangerFourRateSlider.setEnabled(false);
            flangerFourRateSlider.setVisible(false);

            vibratoFourDepthSlider.setEnabled(false);
            vibratoFourDepthSlider.setVisible(false);
            vibratoFourRateSlider.setEnabled(false);
            vibratoFourRateSlider.setVisible(false);

            chorusFourMixSlider.setEnabled(false);
            chorusFourMixSlider.setVisible(false);
            delayFourMixSlider.setEnabled(false);
            delayFourMixSlider.setVisible(false);
            flangerFourMixSlider.setEnabled(false);
            flangerFourMixSlider.setVisible(false);

            break;

        case 2:
            chorusFourDepthSlider.setEnabled(true);
            chorusFourDepthSlider.setVisible(true);
            chorusFourVoicesSlider.setEnabled(true);
            chorusFourVoicesSlider.setVisible(true);

            delayFourTimeSlider.setEnabled(false);
            delayFourTimeSlider.setVisible(false);
            delayFourFeedbackSlider.setEnabled(false);
            delayFourFeedbackSlider.setVisible(false);

            flangerFourDepthSlider.setEnabled(false);
            flangerFourDepthSlider.setVisible(false);
            flangerFourRateSlider.setEnabled(false);
            flangerFourRateSlider.setVisible(false);

            vibratoFourDepthSlider.setEnabled(false);
            vibratoFourDepthSlider.setVisible(false);
            vibratoFourRateSlider.setEnabled(false);
            vibratoFourRateSlider.setVisible(false);

            chorusFourMixSlider.setEnabled(true);
            chorusFourMixSlider.setVisible(true);
            delayFourMixSlider.setEnabled(false);
            delayFourMixSlider.setVisible(false);
            flangerFourMixSlider.setEnabled(false);
            flangerFourMixSlider.setVisible(false);

            break;

        case 3:
            chorusFourDepthSlider.setEnabled(false);
            chorusFourDepthSlider.setVisible(false);
            chorusFourVoicesSlider.setEnabled(false);
            chorusFourVoicesSlider.setVisible(false);

            delayFourTimeSlider.setEnabled(true);
            delayFourTimeSlider.setVisible(true);
            delayFourFeedbackSlider.setEnabled(true);
            delayFourFeedbackSlider.setVisible(true);

            flangerFourDepthSlider.setEnabled(false);
            flangerFourDepthSlider.setVisible(false);
            flangerFourRateSlider.setEnabled(false);
            flangerFourRateSlider.setVisible(false);

            vibratoFourDepthSlider.setEnabled(false);
            vibratoFourDepthSlider.setVisible(false);
            vibratoFourRateSlider.setEnabled(false);
            vibratoFourRateSlider.setVisible(false);

            chorusFourMixSlider.setEnabled(false);
            chorusFourMixSlider.setVisible(false);
            delayFourMixSlider.setEnabled(true);
            delayFourMixSlider.setVisible(true);
            flangerFourMixSlider.setEnabled(false);
            flangerFourMixSlider.setVisible(false);

            break;

        case 4:
            chorusFourDepthSlider.setEnabled(false);
            chorusFourDepthSlider.setVisible(false);
            chorusFourVoicesSlider.setEnabled(false);
            chorusFourVoicesSlider.setVisible(false);

            delayFourTimeSlider.setEnabled(false);
            delayFourTimeSlider.setVisible(false);
            delayFourFeedbackSlider.setEnabled(false);
            delayFourFeedbackSlider.setVisible(false);

            flangerFourDepthSlider.setEnabled(true);
            flangerFourDepthSlider.setVisible(true);
            flangerFourRateSlider.setEnabled(true);
            flangerFourRateSlider.setVisible(true);

            vibratoFourDepthSlider.setEnabled(false);
            vibratoFourDepthSlider.setVisible(false);
            vibratoFourRateSlider.setEnabled(false);
            vibratoFourRateSlider.setVisible(false);

            chorusFourMixSlider.setEnabled(false);
            chorusFourMixSlider.setVisible(false);
            delayFourMixSlider.setEnabled(false);
            delayFourMixSlider.setVisible(false);
            flangerFourMixSlider.setEnabled(true);
            flangerFourMixSlider.setVisible(true);

            break;

        case 5:
            chorusFourDepthSlider.setEnabled(false);
            chorusFourDepthSlider.setVisible(false);
            chorusFourVoicesSlider.setEnabled(false);
            chorusFourVoicesSlider.setVisible(false);

            delayFourTimeSlider.setEnabled(false);
            delayFourTimeSlider.setVisible(false);
            delayFourFeedbackSlider.setEnabled(false);
            delayFourFeedbackSlider.setVisible(false);

            flangerFourDepthSlider.setEnabled(false);
            flangerFourDepthSlider.setVisible(false);
            flangerFourRateSlider.setEnabled(false);
            flangerFourRateSlider.setVisible(false);

            vibratoFourDepthSlider.setEnabled(true);
            vibratoFourDepthSlider.setVisible(true);
            vibratoFourRateSlider.setEnabled(true);
            vibratoFourRateSlider.setVisible(true);

            chorusFourMixSlider.setEnabled(false);
            chorusFourMixSlider.setVisible(false);
            delayFourMixSlider.setEnabled(false);
            delayFourMixSlider.setVisible(false);
            flangerFourMixSlider.setEnabled(false);
            flangerFourMixSlider.setVisible(false);

            break;

        default: break;
        }
    }

    repaint();
}

void PulpfictionAudioProcessorEditor::sliderValueChanged(Slider* slider) {
    if (slider == &chorusOneDepthSlider) {
        chorusOneDepthIndicator.setText(String(chorusOneDepthSlider.getValue()) + " ms", dontSendNotification);
    }
    else if (slider == &chorusOneVoicesSlider) {
        chorusOneVoicesIndicator.setText(String(chorusOneVoicesSlider.getValue()), dontSendNotification);
    }
    else if (slider == &chorusOneMixSlider) {
        chorusOneMixIndicator.setText(String(chorusOneMixSlider.getValue()) + " %", dontSendNotification);
    }

    else if (slider == &delayOneTimeSlider) {
        String timeinBars;

        if (delayOneTimeSlider.getValue() == 0.0) {
            timeinBars = "1/32";
        }
        else if (delayOneTimeSlider.getValue() == 12.5) {
            timeinBars = "1/16";
        }
        else if (delayOneTimeSlider.getValue() == 25.0) {
            timeinBars = "1/8";
        }
        else if (delayOneTimeSlider.getValue() == 37.5) {
            timeinBars = "1/4";
        }
        else if (delayOneTimeSlider.getValue() == 50.0) {
            timeinBars = "1/2";
        }
        else if (delayOneTimeSlider.getValue() == 62.5) {
            timeinBars = "1";
        }
        else if (delayOneTimeSlider.getValue() == 75.0) {
            timeinBars = "2";
        }
        else if (delayOneTimeSlider.getValue() == 87.5) {
            timeinBars = "4";
        }
        else if (delayOneTimeSlider.getValue() == 100.0) {
            timeinBars = "8";
        }

        delayOneTimeIndicator.setText(timeinBars, dontSendNotification);
    }
    else if (slider == &delayOneFeedbackSlider) {
        delayOneFeedbackIndicator.setText(String(delayOneFeedbackSlider.getValue()) + " %", dontSendNotification);
    }
    else if (slider == &delayOneMixSlider) {
        delayOneMixIndicator.setText(String(delayOneMixSlider.getValue()) + " %", dontSendNotification);
    }

    else if (slider == &flangerOneDepthSlider) {
        flangerOneDepthIndicator.setText(String(flangerOneDepthSlider.getValue()) + " ms", dontSendNotification);
    }
    else if (slider == &flangerOneRateSlider) {
        flangerOneRateIndicator.setText(String(flangerOneRateSlider.getValue()) + " Hz", dontSendNotification);
    }
    else if (slider == &flangerOneMixSlider) {
        flangerOneMixIndicator.setText(String(flangerOneMixSlider.getValue()) + " %", dontSendNotification);
    }

    else if (slider == &vibratoOneDepthSlider) {
        vibratoOneDepthIndicator.setText(String(vibratoOneDepthSlider.getValue()) + " ms", dontSendNotification);
    }
    else if (slider == &vibratoOneRateSlider) {
        vibratoOneRateIndicator.setText(String(vibratoOneRateSlider.getValue()) + " Hz", dontSendNotification);
    }
}