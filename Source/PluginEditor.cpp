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
    chorusOneVoicesSlider.setMouseDragSensitivity(50.0);
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
    chorusTwoVoicesSlider.setMouseDragSensitivity(50.0);
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
    chorusThreeVoicesSlider.setMouseDragSensitivity(50.0);
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
    chorusFourVoicesSlider.setMouseDragSensitivity(50.0);
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
    vibratoOneRateSlider.setSkewFactorFromMidPoint(1.0);
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
    vibratoTwoRateSlider.setSkewFactorFromMidPoint(1.0);
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
    vibratoThreeRateSlider.setSkewFactorFromMidPoint(1.0);
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
    vibratoFourRateSlider.setSkewFactorFromMidPoint(1.0);
    vibratoFourRateSlider.setValue(audioProcessor.getValue("V4R"));
    vibratoFourRateSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    vibratoFourRateSlider.setLookAndFeel(&vibratoFourRateSliderLookAndFeel);
    vibratoFourRateSlider.addListener(this);
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

    slotOneComboBox.addItem("Empty", 1);
    slotOneComboBox.addItem("Chorus", 2);
    slotOneComboBox.addItem("Delay", 3);
    slotOneComboBox.addItem("Flanger", 4);
    slotOneComboBox.addItem("Vibrato", 5);
    slotOneComboBox.setSelectedId(audioProcessor.getValue("S1"));
    slotOneComboBox.setLookAndFeel(&slotOneComboBoxLookAndFeel);
    slotOneComboBox.addListener(this);
    addAndMakeVisible(&slotOneComboBox);

    slotTwoComboBox.addItem("Empty", 1);
    slotTwoComboBox.addItem("Chorus", 2);
    slotTwoComboBox.addItem("Delay", 3);
    slotTwoComboBox.addItem("Flanger", 4);
    slotTwoComboBox.addItem("Vibrato", 5);
    slotTwoComboBox.setSelectedId(audioProcessor.getValue("S2"));
    slotTwoComboBox.setLookAndFeel(&slotTwoComboBoxLookAndFeel);
    slotTwoComboBox.addListener(this);
    addAndMakeVisible(&slotTwoComboBox);

    slotThreeComboBox.addItem("Empty", 1);
    slotThreeComboBox.addItem("Chorus", 2);
    slotThreeComboBox.addItem("Delay", 3);
    slotThreeComboBox.addItem("Flanger", 4);
    slotThreeComboBox.addItem("Vibrato", 5);
    slotThreeComboBox.setSelectedId(audioProcessor.getValue("S3"));
    slotThreeComboBox.setLookAndFeel(&slotThreeComboBoxLookAndFeel);
    slotThreeComboBox.addListener(this);
    addAndMakeVisible(&slotThreeComboBox);

    slotFourComboBox.addItem("Empty", 1);
    slotFourComboBox.addItem("Chorus", 2);
    slotFourComboBox.addItem("Delay", 3);
    slotFourComboBox.addItem("Flanger", 4);
    slotFourComboBox.addItem("Vibrato", 5);
    slotFourComboBox.setSelectedId(audioProcessor.getValue("S4"));
    slotFourComboBox.setLookAndFeel(&slotFourComboBoxLookAndFeel);
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
    String timeOneinBars;
    if (delayOneTimeSlider.getValue() == 0.0) {
        timeOneinBars = "1/32";
    }
    else if (delayOneTimeSlider.getValue() == 12.5) {
        timeOneinBars = "1/16";
    }
    else if (delayOneTimeSlider.getValue() == 25.0) {
        timeOneinBars = "1/8";
    }
    else if (delayOneTimeSlider.getValue() == 37.5) {
        timeOneinBars = "1/4";
    }
    else if (delayOneTimeSlider.getValue() == 50.0) {
        timeOneinBars = "1/2";
    }
    else if (delayOneTimeSlider.getValue() == 62.5) {
        timeOneinBars = "1";
    }
    else if (delayOneTimeSlider.getValue() == 75.0) {
        timeOneinBars = "2";
    }
    else if (delayOneTimeSlider.getValue() == 87.5) {
        timeOneinBars = "4";
    }
    else if (delayOneTimeSlider.getValue() == 100.0) {
        timeOneinBars = "8";
    }
    delayOneTimeIndicator.setText(timeOneinBars, dontSendNotification);
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

    chorusTwoDepthIndicator.setJustificationType(Justification::centred);
    chorusTwoDepthIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    chorusTwoDepthIndicator.setText(String(chorusTwoDepthSlider.getValue()) + " ms", dontSendNotification);
    chorusTwoDepthIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&chorusTwoDepthIndicator);

    chorusTwoVoicesIndicator.setJustificationType(Justification::centred);
    chorusTwoVoicesIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    chorusTwoVoicesIndicator.setText(String(chorusTwoVoicesSlider.getValue()), dontSendNotification);
    chorusTwoVoicesIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&chorusTwoVoicesIndicator);

    chorusTwoMixIndicator.setJustificationType(Justification::centred);
    chorusTwoMixIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    chorusTwoMixIndicator.setText(String(chorusTwoMixSlider.getValue()) + " %", dontSendNotification);
    chorusTwoMixIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&chorusTwoMixIndicator);

    delayTwoTimeIndicator.setJustificationType(Justification::centred);
    delayTwoTimeIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    String timeTwoinBars;
    if (delayTwoTimeSlider.getValue() == 0.0) {
        timeTwoinBars = "1/32";
    }
    else if (delayTwoTimeSlider.getValue() == 12.5) {
        timeTwoinBars = "1/16";
    }
    else if (delayTwoTimeSlider.getValue() == 25.0) {
        timeTwoinBars = "1/8";
    }
    else if (delayTwoTimeSlider.getValue() == 37.5) {
        timeTwoinBars = "1/4";
    }
    else if (delayTwoTimeSlider.getValue() == 50.0) {
        timeTwoinBars = "1/2";
    }
    else if (delayTwoTimeSlider.getValue() == 62.5) {
        timeTwoinBars = "1";
    }
    else if (delayTwoTimeSlider.getValue() == 75.0) {
        timeTwoinBars = "2";
    }
    else if (delayTwoTimeSlider.getValue() == 87.5) {
        timeTwoinBars = "4";
    }
    else if (delayTwoTimeSlider.getValue() == 100.0) {
        timeTwoinBars = "8";
    }
    delayTwoTimeIndicator.setText(timeTwoinBars, dontSendNotification);
    delayTwoTimeIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&delayTwoTimeIndicator);

    delayTwoFeedbackIndicator.setJustificationType(Justification::centred);
    delayTwoFeedbackIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    delayTwoFeedbackIndicator.setText(String(delayTwoFeedbackSlider.getValue()) + " %", dontSendNotification);
    delayTwoFeedbackIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&delayTwoFeedbackIndicator);

    delayTwoMixIndicator.setJustificationType(Justification::centred);
    delayTwoMixIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    delayTwoMixIndicator.setText(String(delayTwoMixSlider.getValue()) + " %", dontSendNotification);
    delayTwoMixIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&delayTwoMixIndicator);

    flangerTwoDepthIndicator.setJustificationType(Justification::centred);
    flangerTwoDepthIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    flangerTwoDepthIndicator.setText(String(flangerTwoDepthSlider.getValue()) + " ms", dontSendNotification);
    flangerTwoDepthIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&flangerTwoDepthIndicator);

    flangerTwoRateIndicator.setJustificationType(Justification::centred);
    flangerTwoRateIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    flangerTwoRateIndicator.setText(String(flangerTwoRateSlider.getValue()) + " Hz", dontSendNotification);
    flangerTwoRateIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&flangerTwoRateIndicator);

    flangerTwoMixIndicator.setJustificationType(Justification::centred);
    flangerTwoMixIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    flangerTwoMixIndicator.setText(String(flangerTwoMixSlider.getValue()) + " %", dontSendNotification);
    flangerTwoMixIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&flangerTwoMixIndicator);

    vibratoTwoDepthIndicator.setJustificationType(Justification::centred);
    vibratoTwoDepthIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    vibratoTwoDepthIndicator.setText(String(vibratoTwoDepthSlider.getValue()) + " ms", dontSendNotification);
    vibratoTwoDepthIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&vibratoTwoDepthIndicator);

    vibratoTwoRateIndicator.setJustificationType(Justification::centred);
    vibratoTwoRateIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    vibratoTwoRateIndicator.setText(String(vibratoTwoRateSlider.getValue()) + " Hz", dontSendNotification);
    vibratoTwoRateIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&vibratoTwoRateIndicator);

    chorusThreeDepthIndicator.setJustificationType(Justification::centred);
    chorusThreeDepthIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    chorusThreeDepthIndicator.setText(String(chorusThreeDepthSlider.getValue()) + " ms", dontSendNotification);
    chorusThreeDepthIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&chorusThreeDepthIndicator);

    chorusThreeVoicesIndicator.setJustificationType(Justification::centred);
    chorusThreeVoicesIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    chorusThreeVoicesIndicator.setText(String(chorusOneVoicesSlider.getValue()), dontSendNotification);
    chorusThreeVoicesIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&chorusThreeVoicesIndicator);

    chorusThreeMixIndicator.setJustificationType(Justification::centred);
    chorusThreeMixIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    chorusThreeMixIndicator.setText(String(chorusThreeMixSlider.getValue()) + " %", dontSendNotification);
    chorusThreeMixIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&chorusThreeMixIndicator);

    delayThreeTimeIndicator.setJustificationType(Justification::centred);
    delayThreeTimeIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    String timeThreeinBars;
    if (delayThreeTimeSlider.getValue() == 0.0) {
        timeThreeinBars = "1/32";
    }
    else if (delayThreeTimeSlider.getValue() == 12.5) {
        timeThreeinBars = "1/16";
    }
    else if (delayThreeTimeSlider.getValue() == 25.0) {
        timeThreeinBars = "1/8";
    }
    else if (delayThreeTimeSlider.getValue() == 37.5) {
        timeThreeinBars = "1/4";
    }
    else if (delayThreeTimeSlider.getValue() == 50.0) {
        timeThreeinBars = "1/2";
    }
    else if (delayThreeTimeSlider.getValue() == 62.5) {
        timeThreeinBars = "1";
    }
    else if (delayThreeTimeSlider.getValue() == 75.0) {
        timeThreeinBars = "2";
    }
    else if (delayThreeTimeSlider.getValue() == 87.5) {
        timeThreeinBars = "4";
    }
    else if (delayThreeTimeSlider.getValue() == 100.0) {
        timeThreeinBars = "8";
    }
    delayThreeTimeIndicator.setText(timeThreeinBars, dontSendNotification);
    delayThreeTimeIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&delayThreeTimeIndicator);

    delayThreeFeedbackIndicator.setJustificationType(Justification::centred);
    delayThreeFeedbackIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    delayThreeFeedbackIndicator.setText(String(delayThreeFeedbackSlider.getValue()) + " %", dontSendNotification);
    delayThreeFeedbackIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&delayThreeFeedbackIndicator);

    delayThreeMixIndicator.setJustificationType(Justification::centred);
    delayThreeMixIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    delayThreeMixIndicator.setText(String(delayThreeMixSlider.getValue()) + " %", dontSendNotification);
    delayThreeMixIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&delayThreeMixIndicator);

    flangerThreeDepthIndicator.setJustificationType(Justification::centred);
    flangerThreeDepthIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    flangerThreeDepthIndicator.setText(String(flangerThreeDepthSlider.getValue()) + " ms", dontSendNotification);
    flangerThreeDepthIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&flangerThreeDepthIndicator);

    flangerThreeRateIndicator.setJustificationType(Justification::centred);
    flangerThreeRateIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    flangerThreeRateIndicator.setText(String(flangerThreeRateSlider.getValue()) + " Hz", dontSendNotification);
    flangerThreeRateIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&flangerThreeRateIndicator);

    flangerThreeMixIndicator.setJustificationType(Justification::centred);
    flangerThreeMixIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    flangerThreeMixIndicator.setText(String(flangerThreeMixSlider.getValue()) + " %", dontSendNotification);
    flangerThreeMixIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&flangerThreeMixIndicator);

    vibratoThreeDepthIndicator.setJustificationType(Justification::centred);
    vibratoThreeDepthIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    vibratoThreeDepthIndicator.setText(String(vibratoThreeDepthSlider.getValue()) + " ms", dontSendNotification);
    vibratoThreeDepthIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&vibratoThreeDepthIndicator);

    vibratoThreeRateIndicator.setJustificationType(Justification::centred);
    vibratoThreeRateIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    vibratoThreeRateIndicator.setText(String(vibratoThreeRateSlider.getValue()) + " Hz", dontSendNotification);
    vibratoThreeRateIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&vibratoThreeRateIndicator);

    chorusFourDepthIndicator.setJustificationType(Justification::centred);
    chorusFourDepthIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    chorusFourDepthIndicator.setText(String(chorusFourDepthSlider.getValue()) + " ms", dontSendNotification);
    chorusFourDepthIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&chorusFourDepthIndicator);

    chorusFourVoicesIndicator.setJustificationType(Justification::centred);
    chorusFourVoicesIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    chorusFourVoicesIndicator.setText(String(chorusFourVoicesSlider.getValue()), dontSendNotification);
    chorusFourVoicesIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&chorusFourVoicesIndicator);

    chorusFourMixIndicator.setJustificationType(Justification::centred);
    chorusFourMixIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    chorusFourMixIndicator.setText(String(chorusFourMixSlider.getValue()) + " %", dontSendNotification);
    chorusFourMixIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&chorusFourMixIndicator);

    delayFourTimeIndicator.setJustificationType(Justification::centred);
    delayFourTimeIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    String timeFourinBars;
    if (delayFourTimeSlider.getValue() == 0.0) {
        timeFourinBars = "1/32";
    }
    else if (delayFourTimeSlider.getValue() == 12.5) {
        timeFourinBars = "1/16";
    }
    else if (delayFourTimeSlider.getValue() == 25.0) {
        timeFourinBars = "1/8";
    }
    else if (delayFourTimeSlider.getValue() == 37.5) {
        timeFourinBars = "1/4";
    }
    else if (delayFourTimeSlider.getValue() == 50.0) {
        timeFourinBars = "1/2";
    }
    else if (delayFourTimeSlider.getValue() == 62.5) {
        timeFourinBars = "1";
    }
    else if (delayFourTimeSlider.getValue() == 75.0) {
        timeFourinBars = "2";
    }
    else if (delayFourTimeSlider.getValue() == 87.5) {
        timeFourinBars = "4";
    }
    else if (delayFourTimeSlider.getValue() == 100.0) {
        timeFourinBars = "8";
    }
    delayFourTimeIndicator.setText(timeFourinBars, dontSendNotification);
    delayFourTimeIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&delayFourTimeIndicator);

    delayFourFeedbackIndicator.setJustificationType(Justification::centred);
    delayFourFeedbackIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    delayFourFeedbackIndicator.setText(String(delayFourFeedbackSlider.getValue()) + " %", dontSendNotification);
    delayFourFeedbackIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&delayFourFeedbackIndicator);

    delayFourMixIndicator.setJustificationType(Justification::centred);
    delayFourMixIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    delayFourMixIndicator.setText(String(delayFourMixSlider.getValue()) + " %", dontSendNotification);
    delayFourMixIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&delayFourMixIndicator);

    flangerFourDepthIndicator.setJustificationType(Justification::centred);
    flangerFourDepthIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    flangerFourDepthIndicator.setText(String(flangerFourDepthSlider.getValue()) + " ms", dontSendNotification);
    flangerFourDepthIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&flangerFourDepthIndicator);

    flangerFourRateIndicator.setJustificationType(Justification::centred);
    flangerFourRateIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    flangerFourRateIndicator.setText(String(flangerFourRateSlider.getValue()) + " Hz", dontSendNotification);
    flangerFourRateIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&flangerTwoRateIndicator);

    flangerFourMixIndicator.setJustificationType(Justification::centred);
    flangerFourMixIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    flangerFourMixIndicator.setText(String(flangerFourMixSlider.getValue()) + " %", dontSendNotification);
    flangerFourMixIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&flangerFourMixIndicator);

    vibratoFourDepthIndicator.setJustificationType(Justification::centred);
    vibratoFourDepthIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    vibratoFourDepthIndicator.setText(String(vibratoFourDepthSlider.getValue()) + " ms", dontSendNotification);
    vibratoFourDepthIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&vibratoFourDepthIndicator);

    vibratoFourRateIndicator.setJustificationType(Justification::centred);
    vibratoFourRateIndicator.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    vibratoFourRateIndicator.setText(String(vibratoFourRateSlider.getValue()) + " Hz", dontSendNotification);
    vibratoFourRateIndicator.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&vibratoFourRateIndicator);

    chorusOneDepthLabel.setJustificationType(Justification::centred);
    chorusOneDepthLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    chorusOneDepthLabel.setText("Depth", dontSendNotification);
    chorusOneDepthLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&chorusOneDepthLabel);

    chorusOneVoicesLabel.setJustificationType(Justification::centred);
    chorusOneVoicesLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    chorusOneVoicesLabel.setText("Voices", dontSendNotification);
    chorusOneVoicesLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&chorusOneVoicesLabel);

    chorusOneMixLabel.setJustificationType(Justification::centred);
    chorusOneMixLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    chorusOneMixLabel.setText("Mix", dontSendNotification);
    chorusOneMixLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&chorusOneMixLabel);

    delayOneTimeLabel.setJustificationType(Justification::centred);
    delayOneTimeLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    delayOneTimeLabel.setText("Time", dontSendNotification);
    delayOneTimeLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&delayOneTimeLabel);

    delayOneFeedbackLabel.setJustificationType(Justification::centred);
    delayOneFeedbackLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    delayOneFeedbackLabel.setText("Feedback", dontSendNotification);
    delayOneFeedbackLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&delayOneFeedbackLabel);

    delayOneMixLabel.setJustificationType(Justification::centred);
    delayOneMixLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    delayOneMixLabel.setText("Mix", dontSendNotification);
    delayOneMixLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&delayOneMixLabel);

    flangerOneDepthLabel.setJustificationType(Justification::centred);
    flangerOneDepthLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    flangerOneDepthLabel.setText("Depth", dontSendNotification);
    flangerOneDepthLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&flangerOneDepthLabel);

    flangerOneRateLabel.setJustificationType(Justification::centred);
    flangerOneRateLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    flangerOneRateLabel.setText("Rate", dontSendNotification);
    flangerOneRateLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&flangerOneRateLabel);

    flangerOneMixLabel.setJustificationType(Justification::centred);
    flangerOneMixLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    flangerOneMixLabel.setText("Mix", dontSendNotification);
    flangerOneMixLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&flangerOneMixLabel);

    vibratoOneDepthLabel.setJustificationType(Justification::centred);
    vibratoOneDepthLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    vibratoOneDepthLabel.setText("Depth", dontSendNotification);
    vibratoOneDepthLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&vibratoOneDepthLabel);

    vibratoOneRateLabel.setJustificationType(Justification::centred);
    vibratoOneRateLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    vibratoOneRateLabel.setText("Rate", dontSendNotification);
    vibratoOneRateLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&vibratoOneRateLabel);

    chorusTwoDepthLabel.setJustificationType(Justification::centred);
    chorusTwoDepthLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    chorusTwoDepthLabel.setText("Depth", dontSendNotification);
    chorusTwoDepthLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&chorusTwoDepthLabel);

    chorusTwoVoicesLabel.setJustificationType(Justification::centred);
    chorusTwoVoicesLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    chorusTwoVoicesLabel.setText("Voices", dontSendNotification);
    chorusTwoVoicesLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&chorusTwoVoicesLabel);

    chorusTwoMixLabel.setJustificationType(Justification::centred);
    chorusTwoMixLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    chorusTwoMixLabel.setText("Mix", dontSendNotification);
    chorusTwoMixLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&chorusTwoMixLabel);

    delayTwoTimeLabel.setJustificationType(Justification::centred);
    delayTwoTimeLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    delayTwoTimeLabel.setText("Time", dontSendNotification);
    delayTwoTimeLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&delayTwoTimeLabel);

    delayTwoFeedbackLabel.setJustificationType(Justification::centred);
    delayTwoFeedbackLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    delayTwoFeedbackLabel.setText("Feedback", dontSendNotification);
    delayTwoFeedbackLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&delayTwoFeedbackLabel);

    delayTwoMixLabel.setJustificationType(Justification::centred);
    delayTwoMixLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    delayTwoMixLabel.setText("Mix", dontSendNotification);
    delayTwoMixLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&delayTwoMixLabel);

    flangerTwoDepthLabel.setJustificationType(Justification::centred);
    flangerTwoDepthLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    flangerTwoDepthLabel.setText("Depth", dontSendNotification);
    flangerTwoDepthLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&flangerTwoDepthLabel);

    flangerTwoRateLabel.setJustificationType(Justification::centred);
    flangerTwoRateLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    flangerTwoRateLabel.setText("Rate", dontSendNotification);
    flangerTwoRateLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&flangerTwoRateLabel);

    flangerTwoMixLabel.setJustificationType(Justification::centred);
    flangerTwoMixLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    flangerTwoMixLabel.setText("Mix", dontSendNotification);
    flangerTwoMixLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&flangerTwoMixLabel);

    vibratoTwoDepthLabel.setJustificationType(Justification::centred);
    vibratoTwoDepthLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    vibratoTwoDepthLabel.setText("Depth", dontSendNotification);
    vibratoTwoDepthLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&vibratoTwoDepthLabel);

    vibratoTwoRateLabel.setJustificationType(Justification::centred);
    vibratoTwoRateLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    vibratoTwoRateLabel.setText("Rate", dontSendNotification);
    vibratoTwoRateLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&vibratoTwoRateLabel);

    chorusThreeDepthLabel.setJustificationType(Justification::centred);
    chorusThreeDepthLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    chorusThreeDepthLabel.setText("Depth", dontSendNotification);
    chorusThreeDepthLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&chorusThreeDepthLabel);

    chorusThreeVoicesLabel.setJustificationType(Justification::centred);
    chorusThreeVoicesLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    chorusThreeVoicesLabel.setText("Voices", dontSendNotification);
    chorusThreeVoicesLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&chorusThreeVoicesLabel);

    chorusThreeMixLabel.setJustificationType(Justification::centred);
    chorusThreeMixLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    chorusThreeMixLabel.setText("Mix", dontSendNotification);
    chorusThreeMixLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&chorusThreeMixLabel);

    delayThreeTimeLabel.setJustificationType(Justification::centred);
    delayThreeTimeLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    delayThreeTimeLabel.setText("Time", dontSendNotification);
    delayThreeTimeLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&delayThreeTimeLabel);

    delayThreeFeedbackLabel.setJustificationType(Justification::centred);
    delayThreeFeedbackLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    delayThreeFeedbackLabel.setText("Feedback", dontSendNotification);
    delayThreeFeedbackLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&delayThreeFeedbackLabel);

    delayThreeMixLabel.setJustificationType(Justification::centred);
    delayThreeMixLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    delayThreeMixLabel.setText("Mix", dontSendNotification);
    delayThreeMixLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&delayThreeMixLabel);

    flangerThreeDepthLabel.setJustificationType(Justification::centred);
    flangerThreeDepthLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    flangerThreeDepthLabel.setText("Depth", dontSendNotification);
    flangerThreeDepthLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&flangerThreeDepthLabel);

    flangerThreeRateLabel.setJustificationType(Justification::centred);
    flangerThreeRateLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    flangerThreeRateLabel.setText("Rate", dontSendNotification);
    flangerThreeRateLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&flangerThreeRateLabel);

    flangerThreeMixLabel.setJustificationType(Justification::centred);
    flangerThreeMixLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    flangerThreeMixLabel.setText("Mix", dontSendNotification);
    flangerThreeMixLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&flangerThreeMixLabel);

    vibratoThreeDepthLabel.setJustificationType(Justification::centred);
    vibratoThreeDepthLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    vibratoThreeDepthLabel.setText("Depth", dontSendNotification);
    vibratoThreeDepthLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&vibratoThreeDepthLabel);

    vibratoThreeRateLabel.setJustificationType(Justification::centred);
    vibratoThreeRateLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    vibratoThreeRateLabel.setText("Rate", dontSendNotification);
    vibratoThreeRateLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&vibratoThreeRateLabel);

    chorusFourDepthLabel.setJustificationType(Justification::centred);
    chorusFourDepthLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    chorusFourDepthLabel.setText("Depth", dontSendNotification);
    chorusFourDepthLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&chorusFourDepthLabel);

    chorusFourVoicesLabel.setJustificationType(Justification::centred);
    chorusFourVoicesLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    chorusFourVoicesLabel.setText("Voices", dontSendNotification);
    chorusFourVoicesLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&chorusFourVoicesLabel);

    chorusFourMixLabel.setJustificationType(Justification::centred);
    chorusFourMixLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    chorusFourMixLabel.setText("Mix", dontSendNotification);
    chorusFourMixLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&chorusFourMixLabel);

    delayFourTimeLabel.setJustificationType(Justification::centred);
    delayFourTimeLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    delayFourTimeLabel.setText("Time", dontSendNotification);
    delayFourTimeLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&delayFourTimeLabel);

    delayFourFeedbackLabel.setJustificationType(Justification::centred);
    delayFourFeedbackLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    delayFourFeedbackLabel.setText("Feedback", dontSendNotification);
    delayFourFeedbackLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&delayFourFeedbackLabel);

    delayFourMixLabel.setJustificationType(Justification::centred);
    delayFourMixLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    delayFourMixLabel.setText("Mix", dontSendNotification);
    delayFourMixLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&delayFourMixLabel);

    flangerFourDepthLabel.setJustificationType(Justification::centred);
    flangerFourDepthLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    flangerFourDepthLabel.setText("Depth", dontSendNotification);
    flangerFourDepthLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&flangerFourDepthLabel);

    flangerFourRateLabel.setJustificationType(Justification::centred);
    flangerFourRateLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    flangerFourRateLabel.setText("Rate", dontSendNotification);
    flangerFourRateLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&flangerFourRateLabel);

    flangerFourMixLabel.setJustificationType(Justification::centred);
    flangerFourMixLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    flangerFourMixLabel.setText("Mix", dontSendNotification);
    flangerFourMixLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&flangerFourMixLabel);

    vibratoFourDepthLabel.setJustificationType(Justification::centred);
    vibratoFourDepthLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    vibratoFourDepthLabel.setText("Depth", dontSendNotification);
    vibratoFourDepthLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&vibratoFourDepthLabel);

    vibratoFourRateLabel.setJustificationType(Justification::centred);
    vibratoFourRateLabel.setColour(Label::textColourId, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.8));
    vibratoFourRateLabel.setText("Rate", dontSendNotification);
    vibratoFourRateLabel.setInterceptsMouseClicks(false, false);
    addAndMakeVisible(&vibratoFourRateLabel);

    chorusOneDepthIndicator.setFont(Font(customFont).withHeight(20));
    chorusOneVoicesIndicator.setFont(Font(customFont).withHeight(20));
    chorusOneMixIndicator.setFont(Font(customFont).withHeight(28));

    delayOneTimeIndicator.setFont(Font(customFont).withHeight(20));
    delayOneFeedbackIndicator.setFont(Font(customFont).withHeight(20));
    delayOneMixIndicator.setFont(Font(customFont).withHeight(28));

    flangerOneDepthIndicator.setFont(Font(customFont).withHeight(20));
    flangerOneRateIndicator.setFont(Font(customFont).withHeight(20));
    flangerOneMixIndicator.setFont(Font(customFont).withHeight(28));

    vibratoOneDepthIndicator.setFont(Font(customFont).withHeight(20));
    vibratoOneRateIndicator.setFont(Font(customFont).withHeight(20));

    chorusTwoDepthIndicator.setFont(Font(customFont).withHeight(20));
    chorusTwoVoicesIndicator.setFont(Font(customFont).withHeight(20));
    chorusTwoMixIndicator.setFont(Font(customFont).withHeight(28));

    delayTwoTimeIndicator.setFont(Font(customFont).withHeight(20));
    delayTwoFeedbackIndicator.setFont(Font(customFont).withHeight(20));
    delayTwoMixIndicator.setFont(Font(customFont).withHeight(28));

    flangerTwoDepthIndicator.setFont(Font(customFont).withHeight(20));
    flangerTwoRateIndicator.setFont(Font(customFont).withHeight(20));
    flangerTwoMixIndicator.setFont(Font(customFont).withHeight(28));

    vibratoTwoDepthIndicator.setFont(Font(customFont).withHeight(20));
    vibratoTwoRateIndicator.setFont(Font(customFont).withHeight(20));

    chorusThreeDepthIndicator.setFont(Font(customFont).withHeight(20));
    chorusThreeVoicesIndicator.setFont(Font(customFont).withHeight(20));
    chorusThreeMixIndicator.setFont(Font(customFont).withHeight(28));

    delayThreeTimeIndicator.setFont(Font(customFont).withHeight(20));
    delayThreeFeedbackIndicator.setFont(Font(customFont).withHeight(20));
    delayThreeMixIndicator.setFont(Font(customFont).withHeight(28));

    flangerThreeDepthIndicator.setFont(Font(customFont).withHeight(20));
    flangerThreeRateIndicator.setFont(Font(customFont).withHeight(20));
    flangerThreeMixIndicator.setFont(Font(customFont).withHeight(28));

    vibratoThreeDepthIndicator.setFont(Font(customFont).withHeight(20));
    vibratoThreeRateIndicator.setFont(Font(customFont).withHeight(20));

    chorusFourDepthIndicator.setFont(Font(customFont).withHeight(20));
    chorusFourVoicesIndicator.setFont(Font(customFont).withHeight(20));
    chorusFourMixIndicator.setFont(Font(customFont).withHeight(28));

    delayFourTimeIndicator.setFont(Font(customFont).withHeight(20));
    delayFourFeedbackIndicator.setFont(Font(customFont).withHeight(20));
    delayFourMixIndicator.setFont(Font(customFont).withHeight(28));

    flangerFourDepthIndicator.setFont(Font(customFont).withHeight(20));
    flangerFourRateIndicator.setFont(Font(customFont).withHeight(20));
    flangerFourMixIndicator.setFont(Font(customFont).withHeight(28));

    vibratoFourDepthIndicator.setFont(Font(customFont).withHeight(20));
    vibratoFourRateIndicator.setFont(Font(customFont).withHeight(20));

    chorusOneDepthLabel.setFont(Font(customFont).withHeight(18));
    chorusOneVoicesLabel.setFont(Font(customFont).withHeight(18));
    chorusOneMixLabel.setFont(Font(customFont).withHeight(24));

    delayOneTimeLabel.setFont(Font(customFont).withHeight(18));
    delayOneFeedbackLabel.setFont(Font(customFont).withHeight(19));
    delayOneMixLabel.setFont(Font(customFont).withHeight(24));

    flangerOneDepthLabel.setFont(Font(customFont).withHeight(18));
    flangerOneRateLabel.setFont(Font(customFont).withHeight(18));
    flangerOneMixLabel.setFont(Font(customFont).withHeight(24));

    vibratoOneDepthLabel.setFont(Font(customFont).withHeight(18));
    vibratoOneRateLabel.setFont(Font(customFont).withHeight(18));

    chorusTwoDepthLabel.setFont(Font(customFont).withHeight(18));
    chorusTwoVoicesLabel.setFont(Font(customFont).withHeight(18));
    chorusTwoMixLabel.setFont(Font(customFont).withHeight(24));

    delayTwoTimeLabel.setFont(Font(customFont).withHeight(18));
    delayTwoFeedbackLabel.setFont(Font(customFont).withHeight(19));
    delayTwoMixLabel.setFont(Font(customFont).withHeight(24));

    flangerTwoDepthLabel.setFont(Font(customFont).withHeight(18));
    flangerTwoRateLabel.setFont(Font(customFont).withHeight(18));
    flangerTwoMixLabel.setFont(Font(customFont).withHeight(24));

    vibratoTwoDepthLabel.setFont(Font(customFont).withHeight(18));
    vibratoTwoRateLabel.setFont(Font(customFont).withHeight(18));

    chorusThreeDepthLabel.setFont(Font(customFont).withHeight(18));
    chorusThreeVoicesLabel.setFont(Font(customFont).withHeight(18));
    chorusThreeMixLabel.setFont(Font(customFont).withHeight(24));

    delayThreeTimeLabel.setFont(Font(customFont).withHeight(18));
    delayThreeFeedbackLabel.setFont(Font(customFont).withHeight(19));
    delayThreeMixLabel.setFont(Font(customFont).withHeight(24));

    flangerThreeDepthLabel.setFont(Font(customFont).withHeight(18));
    flangerThreeRateLabel.setFont(Font(customFont).withHeight(18));
    flangerThreeMixLabel.setFont(Font(customFont).withHeight(24));

    vibratoThreeDepthLabel.setFont(Font(customFont).withHeight(18));
    vibratoThreeRateLabel.setFont(Font(customFont).withHeight(18));

    chorusFourDepthLabel.setFont(Font(customFont).withHeight(18));
    chorusFourVoicesLabel.setFont(Font(customFont).withHeight(18));
    chorusFourMixLabel.setFont(Font(customFont).withHeight(24));

    delayFourTimeLabel.setFont(Font(customFont).withHeight(18));
    delayFourFeedbackLabel.setFont(Font(customFont).withHeight(19));
    delayFourMixLabel.setFont(Font(customFont).withHeight(24));

    flangerFourDepthLabel.setFont(Font(customFont).withHeight(18));
    flangerFourRateLabel.setFont(Font(customFont).withHeight(18));
    flangerFourMixLabel.setFont(Font(customFont).withHeight(24));

    vibratoFourDepthLabel.setFont(Font(customFont).withHeight(18));
    vibratoFourRateLabel.setFont(Font(customFont).withHeight(18));
}

PulpfictionAudioProcessorEditor::~PulpfictionAudioProcessorEditor()
{
}

//==============================================================================
void PulpfictionAudioProcessorEditor::paint(juce::Graphics& g)
{
    ColourGradient fillGradient(Colour::fromFloatRGBA(0.95, 0.965, 0.98, 1.0), slotOneRectangle.getCentreX(), 0, Colour::fromFloatRGBA(0.96, 0.965, 0.97, 1.0), slotOneRectangle.getCentreX(), getBottom(), false);
    g.setGradientFill(fillGradient);
    g.fillAll();

    DropShadow slotShadow(Colour::fromFloatRGBA(0.0, 0.0, 0.0, 0.25), 10, Point<int>(5, 5));
    DropShadow comboBoxShadow(Colour::fromFloatRGBA(0.0, 0.0, 0.0, 0.25), 10, Point<int>(5, 5));

    comboBoxShadow.drawForRectangle(g, comboBoxOneRectangle.toNearestInt());
    comboBoxShadow.drawForRectangle(g, comboBoxTwoRectangle.toNearestInt());
    comboBoxShadow.drawForRectangle(g, comboBoxThreeRectangle.toNearestInt());
    comboBoxShadow.drawForRectangle(g, comboBoxFourRectangle.toNearestInt());

    if (slotOneComboBox.getSelectedId() != 1) {
        slotShadow.drawForRectangle(g, slotOneRectangle.toNearestInt());
    }
    else {
        ColourGradient slotOneGradient(Colour::fromRGB(0x0C, 0x0C, 0x0C), slotOneRectangle.getCentreX(), 0, Colour::fromRGB(0x0D, 0x0D, 0x0D), slotOneRectangle.getCentreX(), getBottom(), false);
        g.setGradientFill(slotOneGradient);
        g.fillRoundedRectangle(comboBoxOneRectangle, 5);
    }
    if (slotTwoComboBox.getSelectedId() != 1) {
        slotShadow.drawForRectangle(g, slotTwoRectangle.toNearestInt());
    }
    else {
        ColourGradient slotTwoGradient(Colour::fromRGB(0x0C, 0x0C, 0x0C), slotTwoRectangle.getCentreX(), 0, Colour::fromRGB(0x0D, 0x0D, 0x0D), slotTwoRectangle.getCentreX(), getBottom(), false);
        g.setGradientFill(slotTwoGradient);
        g.fillRoundedRectangle(comboBoxTwoRectangle, 5);
    }
    if (slotThreeComboBox.getSelectedId() != 1) {
        slotShadow.drawForRectangle(g, slotThreeRectangle.toNearestInt());
    }
    else {
        ColourGradient slotThreeGradient(Colour::fromRGB(0x0C, 0x0C, 0x0C), slotThreeRectangle.getCentreX(), 0, Colour::fromRGB(0x0D, 0x0D, 0x0D), slotThreeRectangle.getCentreX(), getBottom(), false);
        g.setGradientFill(slotThreeGradient);
        g.fillRoundedRectangle(comboBoxThreeRectangle, 5);
    }
    if (slotFourComboBox.getSelectedId() != 1) {
        slotShadow.drawForRectangle(g, slotFourRectangle.toNearestInt());
    }
    else {
        ColourGradient slotFourGradient(Colour::fromRGB(0x0C, 0x0C, 0x0C), slotFourRectangle.getCentreX(), 0, Colour::fromRGB(0x0D, 0x0D, 0x0D), slotFourRectangle.getCentreX(), getBottom(), false);
        g.setGradientFill(slotFourGradient);
        g.fillRoundedRectangle(comboBoxFourRectangle, 5);
    }
    
    if (slotOneComboBox.getSelectedId() == 2) {
        ColourGradient slotOneGradient(Colour::fromRGB(0x30, 0xA0, 0xFF), slotOneRectangle.getCentreX(), 0, Colour::fromRGB(0xFF, 0x30, 0x70), slotOneRectangle.getCentreX(), getBottom(), false);
        g.setGradientFill(slotOneGradient);
        g.fillRoundedRectangle(slotOneRectangle, 5);
        g.fillRoundedRectangle(comboBoxOneRectangle, 2);
    }
    else if (slotOneComboBox.getSelectedId() == 3) {
        ColourGradient slotOneGradient(Colour::fromRGB(0x05, 0xD5, 0x10), slotOneRectangle.getCentreX(), 0, Colour::fromRGB(0x80, 0xB0, 0xFF), slotOneRectangle.getCentreX(), getBottom(), false);
        g.setGradientFill(slotOneGradient);
        g.fillRoundedRectangle(slotOneRectangle, 5);
        g.fillRoundedRectangle(comboBoxOneRectangle, 2);
    }
    else if (slotOneComboBox.getSelectedId() == 4) {
        ColourGradient slotOneGradient(Colour::fromRGB(0xFF, 0x00, 0xD5), slotOneRectangle.getCentreX(), 0, Colour::fromRGB(0xFF, 0x95, 0x20), slotOneRectangle.getCentreX(), getBottom(), false);
        g.setGradientFill(slotOneGradient);
        g.fillRoundedRectangle(slotOneRectangle, 5);
        g.fillRoundedRectangle(comboBoxOneRectangle, 2);
    }
    else if (slotOneComboBox.getSelectedId() == 5) {
        ColourGradient slotOneGradient(Colour::fromRGB(0x00, 0x40, 0x90), slotOneRectangle.getCentreX(), 0, Colour::fromRGB(0x80, 0xFF, 0xFF), slotOneRectangle.getCentreX(), getBottom(), false);
        g.setGradientFill(slotOneGradient);
        g.fillRoundedRectangle(slotOneRectangle, 5);
        g.fillRoundedRectangle(comboBoxOneRectangle, 2);
    }

    if (slotTwoComboBox.getSelectedId() == 2) {
        ColourGradient slotTwoGradient(Colour::fromRGB(0x30, 0xA0, 0xFF), slotTwoRectangle.getCentreX(), 0, Colour::fromRGB(0xFF, 0x30, 0x70), slotTwoRectangle.getCentreX(), getBottom(), false);
        g.setGradientFill(slotTwoGradient);
        g.fillRoundedRectangle(slotTwoRectangle, 5);
        g.fillRoundedRectangle(comboBoxTwoRectangle, 2);
    }
    else if (slotTwoComboBox.getSelectedId() == 3) {
        ColourGradient slotTwoGradient(Colour::fromRGB(0x05, 0xD5, 0x10), slotTwoRectangle.getCentreX(), 0, Colour::fromRGB(0x80, 0xB0, 0xFF), slotTwoRectangle.getCentreX(), getBottom(), false);
        g.setGradientFill(slotTwoGradient);
        g.fillRoundedRectangle(slotTwoRectangle, 5);
        g.fillRoundedRectangle(comboBoxTwoRectangle, 2);
    }
    else if (slotTwoComboBox.getSelectedId() == 4) {
        ColourGradient slotTwoGradient(Colour::fromRGB(0xFF, 0x00, 0xD5), slotTwoRectangle.getCentreX(), 0, Colour::fromRGB(0xFF, 0x95, 0x20), slotTwoRectangle.getCentreX(), getBottom(), false);
        g.setGradientFill(slotTwoGradient);
        g.fillRoundedRectangle(slotTwoRectangle, 5);
        g.fillRoundedRectangle(comboBoxTwoRectangle, 2);
    }
    else if (slotTwoComboBox.getSelectedId() == 5) {
        ColourGradient slotTwoGradient(Colour::fromRGB(0x00, 0x40, 0x90), slotTwoRectangle.getCentreX(), 0, Colour::fromRGB(0x80, 0xFF, 0xFF), slotTwoRectangle.getCentreX(), getBottom(), false);
        g.setGradientFill(slotTwoGradient);
        g.fillRoundedRectangle(slotTwoRectangle, 5);
        g.fillRoundedRectangle(comboBoxTwoRectangle, 2);
    }

    if (slotThreeComboBox.getSelectedId() == 2) {
        ColourGradient slotThreeGradient(Colour::fromRGB(0x30, 0xA0, 0xFF), slotThreeRectangle.getCentreX(), 0, Colour::fromRGB(0xFF, 0x30, 0x70), slotThreeRectangle.getCentreX(), getBottom(), false);
        g.setGradientFill(slotThreeGradient);
        g.fillRoundedRectangle(slotThreeRectangle, 5);
        g.fillRoundedRectangle(comboBoxThreeRectangle, 2);
    }
    else if (slotThreeComboBox.getSelectedId() == 3) {
        ColourGradient slotThreeGradient(Colour::fromRGB(0x05, 0xD5, 0x10), slotThreeRectangle.getCentreX(), 0, Colour::fromRGB(0x80, 0xB0, 0xFF), slotThreeRectangle.getCentreX(), getBottom(), false);
        g.setGradientFill(slotThreeGradient);
        g.fillRoundedRectangle(slotThreeRectangle, 5);
        g.fillRoundedRectangle(comboBoxThreeRectangle, 2);
    }
    else if (slotThreeComboBox.getSelectedId() == 4) {
        ColourGradient slotThreeGradient(Colour::fromRGB(0xFF, 0x00, 0xD5), slotThreeRectangle.getCentreX(), 0, Colour::fromRGB(0xFF, 0x95, 0x20), slotThreeRectangle.getCentreX(), getBottom(), false);
        g.setGradientFill(slotThreeGradient);
        g.fillRoundedRectangle(slotThreeRectangle, 5);
        g.fillRoundedRectangle(comboBoxThreeRectangle, 2);
    }
    else if (slotThreeComboBox.getSelectedId() == 5) {
        ColourGradient slotThreeGradient(Colour::fromRGB(0x00, 0x40, 0x90), slotThreeRectangle.getCentreX(), 0, Colour::fromRGB(0x80, 0xFF, 0xFF), slotThreeRectangle.getCentreX(), getBottom(), false);
        g.setGradientFill(slotThreeGradient);
        g.fillRoundedRectangle(slotThreeRectangle, 5);
        g.fillRoundedRectangle(comboBoxThreeRectangle, 2);
    }

    if (slotFourComboBox.getSelectedId() == 2) {
        ColourGradient slotFourGradient(Colour::fromRGB(0x30, 0xA0, 0xFF), slotFourRectangle.getCentreX(), 0, Colour::fromRGB(0xFF, 0x30, 0x70), slotFourRectangle.getCentreX(), getBottom(), false);
        g.setGradientFill(slotFourGradient);
        g.fillRoundedRectangle(slotFourRectangle, 5);
        g.fillRoundedRectangle(comboBoxFourRectangle, 2);
    }
    else if (slotFourComboBox.getSelectedId() == 3) {
        ColourGradient slotFourGradient(Colour::fromRGB(0x05, 0xD5, 0x10), slotFourRectangle.getCentreX(), 0, Colour::fromRGB(0x80, 0xB0, 0xFF), slotFourRectangle.getCentreX(), getBottom(), false);
        g.setGradientFill(slotFourGradient);
        g.fillRoundedRectangle(slotFourRectangle, 5);
        g.fillRoundedRectangle(comboBoxFourRectangle, 2);
    }
    else if (slotFourComboBox.getSelectedId() == 4) {
        ColourGradient slotFourGradient(Colour::fromRGB(0xFF, 0x00, 0xD5), slotFourRectangle.getCentreX(), 0, Colour::fromRGB(0xFF, 0x95, 0x20), slotFourRectangle.getCentreX(), getBottom(), false);
        g.setGradientFill(slotFourGradient);
        g.fillRoundedRectangle(slotFourRectangle, 5);
        g.fillRoundedRectangle(comboBoxFourRectangle, 2);
    }
    else if (slotFourComboBox.getSelectedId() == 5) {
        ColourGradient slotFourGradient(Colour::fromRGB(0x00, 0x40, 0x90), slotFourRectangle.getCentreX(), 0, Colour::fromRGB(0x80, 0xFF, 0xFF), slotFourRectangle.getCentreX(), getBottom(), false);
        g.setGradientFill(slotFourGradient);
        g.fillRoundedRectangle(slotFourRectangle, 5);
        g.fillRoundedRectangle(comboBoxFourRectangle, 2);
    }
}

void PulpfictionAudioProcessorEditor::resized()
{
    slotOneComboBox.setBounds(50, 40, 150, 25);
    slotTwoComboBox.setBounds(250, 40, 150, 25);
    slotThreeComboBox.setBounds(450, 40, 150, 25);
    slotFourComboBox.setBounds(650, 40, 150, 25);

    comboBoxOneRectangle.setBounds(slotOneComboBox.getX(), slotOneComboBox.getY(), slotOneComboBox.getWidth(), slotOneComboBox.getHeight());
    comboBoxTwoRectangle.setBounds(slotTwoComboBox.getX(), slotTwoComboBox.getY(), slotTwoComboBox.getWidth(), slotTwoComboBox.getHeight());
    comboBoxThreeRectangle.setBounds(slotThreeComboBox.getX(), slotThreeComboBox.getY(), slotThreeComboBox.getWidth(), slotThreeComboBox.getHeight());
    comboBoxFourRectangle.setBounds(slotFourComboBox.getX(), slotFourComboBox.getY(), slotFourComboBox.getWidth(), slotFourComboBox.getHeight());

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

    chorusTwoDepthIndicator.setBounds(235, 125, 100, 20);
    chorusTwoVoicesIndicator.setBounds(315, 125, 100, 20);
    chorusTwoMixIndicator.setBounds(250, 240, 100, 20);

    delayTwoTimeIndicator.setBounds(235, 125, 100, 20);
    delayTwoFeedbackIndicator.setBounds(315, 125, 100, 20);
    delayTwoMixIndicator.setBounds(250, 240, 100, 20);

    flangerTwoDepthIndicator.setBounds(235, 125, 100, 20);
    flangerTwoRateIndicator.setBounds(315, 125, 100, 20);
    flangerTwoMixIndicator.setBounds(250, 240, 100, 20);

    vibratoTwoDepthIndicator.setBounds(235, 125, 100, 20);
    vibratoTwoRateIndicator.setBounds(315, 225, 100, 20);

    chorusThreeDepthIndicator.setBounds(435, 125, 100, 20);
    chorusThreeVoicesIndicator.setBounds(515, 125, 100, 20);
    chorusThreeMixIndicator.setBounds(450, 240, 100, 20);

    delayThreeTimeIndicator.setBounds(435, 125, 100, 20);
    delayThreeFeedbackIndicator.setBounds(515, 125, 100, 20);
    delayThreeMixIndicator.setBounds(450, 240, 100, 20);

    flangerThreeDepthIndicator.setBounds(435, 125, 100, 20);
    flangerThreeRateIndicator.setBounds(515, 125, 100, 20);
    flangerThreeMixIndicator.setBounds(450, 240, 100, 20);

    vibratoThreeDepthIndicator.setBounds(435, 125, 100, 20);
    vibratoThreeRateIndicator.setBounds(515, 225, 100, 20);

    chorusFourDepthIndicator.setBounds(635, 125, 100, 20);
    chorusFourVoicesIndicator.setBounds(715, 125, 100, 20);
    chorusFourMixIndicator.setBounds(650, 240, 100, 20);

    delayFourTimeIndicator.setBounds(635, 125, 100, 20);
    delayFourFeedbackIndicator.setBounds(715, 125, 100, 20);
    delayFourMixIndicator.setBounds(650, 240, 100, 20);

    flangerFourDepthIndicator.setBounds(635, 125, 100, 20);
    flangerFourRateIndicator.setBounds(715, 125, 100, 20);
    flangerFourMixIndicator.setBounds(650, 240, 100, 20);

    vibratoFourDepthIndicator.setBounds(635, 125, 100, 20);
    vibratoFourRateIndicator.setBounds(715, 225, 100, 20);

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

    chorusTwoDepthLabel.setBounds(235, 175, 100, 20);
    chorusTwoVoicesLabel.setBounds(315, 175, 100, 20);
    chorusTwoMixLabel.setBounds(250, 305, 100, 20);

    delayTwoTimeLabel.setBounds(235, 175, 100, 20);
    delayTwoFeedbackLabel.setBounds(315, 175, 100, 20);
    delayTwoMixLabel.setBounds(250, 305, 100, 20);

    flangerTwoDepthLabel.setBounds(235, 175, 100, 20);
    flangerTwoRateLabel.setBounds(315, 175, 100, 20);
    flangerTwoMixLabel.setBounds(250, 305, 100, 20);

    vibratoTwoDepthLabel.setBounds(235, 175, 100, 20);
    vibratoTwoRateLabel.setBounds(315, 275, 100, 20);

    chorusThreeDepthLabel.setBounds(435, 175, 100, 20);
    chorusThreeVoicesLabel.setBounds(515, 175, 100, 20);
    chorusThreeMixLabel.setBounds(450, 305, 100, 20);

    delayThreeTimeLabel.setBounds(435, 175, 100, 20);
    delayThreeFeedbackLabel.setBounds(515, 175, 100, 20);
    delayThreeMixLabel.setBounds(450, 305, 100, 20);

    flangerThreeDepthLabel.setBounds(435, 175, 100, 20);
    flangerThreeRateLabel.setBounds(515, 175, 100, 20);
    flangerThreeMixLabel.setBounds(450, 305, 100, 20);

    vibratoThreeDepthLabel.setBounds(435, 175, 100, 20);
    vibratoThreeRateLabel.setBounds(515, 275, 100, 20);

    chorusFourDepthLabel.setBounds(635, 175, 100, 20);
    chorusFourVoicesLabel.setBounds(715, 175, 100, 20);
    chorusFourMixLabel.setBounds(650, 305, 100, 20);

    delayFourTimeLabel.setBounds(635, 175, 100, 20);
    delayFourFeedbackLabel.setBounds(715, 175, 100, 20);
    delayFourMixLabel.setBounds(650, 305, 100, 20);

    flangerFourDepthLabel.setBounds(635, 175, 100, 20);
    flangerFourRateLabel.setBounds(715, 175, 100, 20);
    flangerFourMixLabel.setBounds(650, 305, 100, 20);

    vibratoFourDepthLabel.setBounds(635, 175, 100, 20);
    vibratoFourRateLabel.setBounds(715, 275, 100, 20);
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

            chorusTwoDepthIndicator.setVisible(false);
            chorusTwoVoicesIndicator.setVisible(false);
            chorusTwoMixIndicator.setVisible(false);

            delayTwoTimeIndicator.setVisible(false);
            delayTwoFeedbackIndicator.setVisible(false);
            delayTwoMixIndicator.setVisible(false);

            flangerTwoDepthIndicator.setVisible(false);
            flangerTwoRateIndicator.setVisible(false);
            flangerTwoMixIndicator.setVisible(false);

            vibratoTwoDepthIndicator.setVisible(false);
            vibratoTwoRateIndicator.setVisible(false);

            chorusTwoDepthLabel.setVisible(false);
            chorusTwoVoicesLabel.setVisible(false);
            chorusTwoMixLabel.setVisible(false);

            delayTwoTimeLabel.setVisible(false);
            delayTwoFeedbackLabel.setVisible(false);
            delayTwoMixLabel.setVisible(false);

            flangerTwoDepthLabel.setVisible(false);
            flangerTwoRateLabel.setVisible(false);
            flangerTwoMixLabel.setVisible(false);

            vibratoTwoDepthLabel.setVisible(false);
            vibratoTwoRateLabel.setVisible(false);

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

            chorusTwoDepthIndicator.setVisible(true);
            chorusTwoVoicesIndicator.setVisible(true);
            chorusTwoMixIndicator.setVisible(true);

            delayTwoTimeIndicator.setVisible(false);
            delayTwoFeedbackIndicator.setVisible(false);
            delayTwoMixIndicator.setVisible(false);

            flangerTwoDepthIndicator.setVisible(false);
            flangerTwoRateIndicator.setVisible(false);
            flangerTwoMixIndicator.setVisible(false);

            vibratoTwoDepthIndicator.setVisible(false);
            vibratoTwoRateIndicator.setVisible(false);

            chorusTwoDepthLabel.setVisible(true);
            chorusTwoVoicesLabel.setVisible(true);
            chorusTwoMixLabel.setVisible(true);

            delayTwoTimeLabel.setVisible(false);
            delayTwoFeedbackLabel.setVisible(false);
            delayTwoMixLabel.setVisible(false);

            flangerTwoDepthLabel.setVisible(false);
            flangerTwoRateLabel.setVisible(false);
            flangerTwoMixLabel.setVisible(false);

            vibratoTwoDepthLabel.setVisible(false);
            vibratoTwoRateLabel.setVisible(false);

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

            chorusTwoDepthIndicator.setVisible(false);
            chorusTwoVoicesIndicator.setVisible(false);
            chorusTwoMixIndicator.setVisible(false);

            delayTwoTimeIndicator.setVisible(true);
            delayTwoFeedbackIndicator.setVisible(true);
            delayTwoMixIndicator.setVisible(true);

            flangerTwoDepthIndicator.setVisible(false);
            flangerTwoRateIndicator.setVisible(false);
            flangerTwoMixIndicator.setVisible(false);

            vibratoTwoDepthIndicator.setVisible(false);
            vibratoTwoRateIndicator.setVisible(false);

            chorusTwoDepthLabel.setVisible(false);
            chorusTwoVoicesLabel.setVisible(false);
            chorusTwoMixLabel.setVisible(false);

            delayTwoTimeLabel.setVisible(true);
            delayTwoFeedbackLabel.setVisible(true);
            delayTwoMixLabel.setVisible(true);

            flangerTwoDepthLabel.setVisible(false);
            flangerTwoRateLabel.setVisible(false);
            flangerTwoMixLabel.setVisible(false);

            vibratoTwoDepthLabel.setVisible(false);
            vibratoTwoRateLabel.setVisible(false);

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

            chorusTwoDepthIndicator.setVisible(false);
            chorusTwoVoicesIndicator.setVisible(false);
            chorusTwoMixIndicator.setVisible(false);

            delayTwoTimeIndicator.setVisible(false);
            delayTwoFeedbackIndicator.setVisible(false);
            delayTwoMixIndicator.setVisible(false);

            flangerTwoDepthIndicator.setVisible(true);
            flangerTwoRateIndicator.setVisible(true);
            flangerTwoMixIndicator.setVisible(true);

            vibratoTwoDepthIndicator.setVisible(false);
            vibratoTwoRateIndicator.setVisible(false);

            chorusTwoDepthLabel.setVisible(false);
            chorusTwoVoicesLabel.setVisible(false);
            chorusTwoMixLabel.setVisible(false);

            delayTwoTimeLabel.setVisible(false);
            delayTwoFeedbackLabel.setVisible(false);
            delayTwoMixLabel.setVisible(false);

            flangerTwoDepthLabel.setVisible(true);
            flangerTwoRateLabel.setVisible(true);
            flangerTwoMixLabel.setVisible(true);

            vibratoTwoDepthLabel.setVisible(false);
            vibratoTwoRateLabel.setVisible(false);

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

            chorusTwoDepthIndicator.setVisible(false);
            chorusTwoVoicesIndicator.setVisible(false);
            chorusTwoMixIndicator.setVisible(false);

            delayTwoTimeIndicator.setVisible(false);
            delayTwoFeedbackIndicator.setVisible(false);
            delayTwoMixIndicator.setVisible(false);

            flangerTwoDepthIndicator.setVisible(false);
            flangerTwoRateIndicator.setVisible(false);
            flangerTwoMixIndicator.setVisible(false);

            vibratoTwoDepthIndicator.setVisible(true);
            vibratoTwoRateIndicator.setVisible(true);

            chorusTwoDepthLabel.setVisible(false);
            chorusTwoVoicesLabel.setVisible(false);
            chorusTwoMixLabel.setVisible(false);

            delayTwoTimeLabel.setVisible(false);
            delayTwoFeedbackLabel.setVisible(false);
            delayTwoMixLabel.setVisible(false);

            flangerTwoDepthLabel.setVisible(false);
            flangerTwoRateLabel.setVisible(false);
            flangerTwoMixLabel.setVisible(false);

            vibratoTwoDepthLabel.setVisible(true);
            vibratoTwoRateLabel.setVisible(true);

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

            chorusThreeDepthIndicator.setVisible(false);
            chorusThreeVoicesIndicator.setVisible(false);
            chorusThreeMixIndicator.setVisible(false);

            delayThreeTimeIndicator.setVisible(false);
            delayThreeFeedbackIndicator.setVisible(false);
            delayThreeMixIndicator.setVisible(false);

            flangerThreeDepthIndicator.setVisible(false);
            flangerThreeRateIndicator.setVisible(false);
            flangerThreeMixIndicator.setVisible(false);

            vibratoThreeDepthIndicator.setVisible(false);
            vibratoThreeRateIndicator.setVisible(false);

            chorusThreeDepthLabel.setVisible(false);
            chorusThreeVoicesLabel.setVisible(false);
            chorusThreeMixLabel.setVisible(false);

            delayThreeTimeLabel.setVisible(false);
            delayThreeFeedbackLabel.setVisible(false);
            delayThreeMixLabel.setVisible(false);

            flangerThreeDepthLabel.setVisible(false);
            flangerThreeRateLabel.setVisible(false);
            flangerThreeMixLabel.setVisible(false);

            vibratoThreeDepthLabel.setVisible(false);
            vibratoThreeRateLabel.setVisible(false);

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

            chorusThreeDepthIndicator.setVisible(true);
            chorusThreeVoicesIndicator.setVisible(true);
            chorusThreeMixIndicator.setVisible(true);

            delayThreeTimeIndicator.setVisible(false);
            delayThreeFeedbackIndicator.setVisible(false);
            delayThreeMixIndicator.setVisible(false);

            flangerThreeDepthIndicator.setVisible(false);
            flangerThreeRateIndicator.setVisible(false);
            flangerThreeMixIndicator.setVisible(false);

            vibratoThreeDepthIndicator.setVisible(false);
            vibratoThreeRateIndicator.setVisible(false);

            chorusThreeDepthLabel.setVisible(true);
            chorusThreeVoicesLabel.setVisible(true);
            chorusThreeMixLabel.setVisible(true);

            delayThreeTimeLabel.setVisible(false);
            delayThreeFeedbackLabel.setVisible(false);
            delayThreeMixLabel.setVisible(false);

            flangerThreeDepthLabel.setVisible(false);
            flangerThreeRateLabel.setVisible(false);
            flangerThreeMixLabel.setVisible(false);

            vibratoThreeDepthLabel.setVisible(false);
            vibratoThreeRateLabel.setVisible(false);

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

            chorusThreeDepthIndicator.setVisible(false);
            chorusThreeVoicesIndicator.setVisible(false);
            chorusThreeMixIndicator.setVisible(false);

            delayThreeTimeIndicator.setVisible(true);
            delayThreeFeedbackIndicator.setVisible(true);
            delayThreeMixIndicator.setVisible(true);

            flangerThreeDepthIndicator.setVisible(false);
            flangerThreeRateIndicator.setVisible(false);
            flangerThreeMixIndicator.setVisible(false);

            vibratoThreeDepthIndicator.setVisible(false);
            vibratoThreeRateIndicator.setVisible(false);

            chorusThreeDepthLabel.setVisible(false);
            chorusThreeVoicesLabel.setVisible(false);
            chorusThreeMixLabel.setVisible(false);

            delayThreeTimeLabel.setVisible(true);
            delayThreeFeedbackLabel.setVisible(true);
            delayThreeMixLabel.setVisible(true);

            flangerThreeDepthLabel.setVisible(false);
            flangerThreeRateLabel.setVisible(false);
            flangerThreeMixLabel.setVisible(false);

            vibratoThreeDepthLabel.setVisible(false);
            vibratoThreeRateLabel.setVisible(false);

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

            chorusThreeDepthIndicator.setVisible(false);
            chorusThreeVoicesIndicator.setVisible(false);
            chorusThreeMixIndicator.setVisible(false);

            delayThreeTimeIndicator.setVisible(false);
            delayThreeFeedbackIndicator.setVisible(false);
            delayThreeMixIndicator.setVisible(false);

            flangerThreeDepthIndicator.setVisible(true);
            flangerThreeRateIndicator.setVisible(true);
            flangerThreeMixIndicator.setVisible(true);

            vibratoThreeDepthIndicator.setVisible(false);
            vibratoThreeRateIndicator.setVisible(false);

            chorusThreeDepthLabel.setVisible(false);
            chorusThreeVoicesLabel.setVisible(false);
            chorusThreeMixLabel.setVisible(false);

            delayThreeTimeLabel.setVisible(false);
            delayThreeFeedbackLabel.setVisible(false);
            delayThreeMixLabel.setVisible(false);

            flangerThreeDepthLabel.setVisible(true);
            flangerThreeRateLabel.setVisible(true);
            flangerThreeMixLabel.setVisible(true);

            vibratoThreeDepthLabel.setVisible(false);
            vibratoThreeRateLabel.setVisible(false);

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

            chorusThreeDepthIndicator.setVisible(false);
            chorusThreeVoicesIndicator.setVisible(false);
            chorusThreeMixIndicator.setVisible(false);

            delayThreeTimeIndicator.setVisible(false);
            delayThreeFeedbackIndicator.setVisible(false);
            delayThreeMixIndicator.setVisible(false);

            flangerThreeDepthIndicator.setVisible(false);
            flangerThreeRateIndicator.setVisible(false);
            flangerThreeMixIndicator.setVisible(false);

            vibratoThreeDepthIndicator.setVisible(true);
            vibratoThreeRateIndicator.setVisible(true);

            chorusThreeDepthLabel.setVisible(false);
            chorusThreeVoicesLabel.setVisible(false);
            chorusThreeMixLabel.setVisible(false);

            delayThreeTimeLabel.setVisible(false);
            delayThreeFeedbackLabel.setVisible(false);
            delayThreeMixLabel.setVisible(false);

            flangerThreeDepthLabel.setVisible(false);
            flangerThreeRateLabel.setVisible(false);
            flangerThreeMixLabel.setVisible(false);

            vibratoThreeDepthLabel.setVisible(true);
            vibratoThreeRateLabel.setVisible(true);

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

            chorusFourDepthIndicator.setVisible(false);
            chorusFourVoicesIndicator.setVisible(false);
            chorusFourMixIndicator.setVisible(false);

            delayFourTimeIndicator.setVisible(false);
            delayFourFeedbackIndicator.setVisible(false);
            delayFourMixIndicator.setVisible(false);

            flangerFourDepthIndicator.setVisible(false);
            flangerFourRateIndicator.setVisible(false);
            flangerFourMixIndicator.setVisible(false);

            vibratoFourDepthIndicator.setVisible(false);
            vibratoFourRateIndicator.setVisible(false);

            chorusFourDepthLabel.setVisible(false);
            chorusFourVoicesLabel.setVisible(false);
            chorusFourMixLabel.setVisible(false);

            delayFourTimeLabel.setVisible(false);
            delayFourFeedbackLabel.setVisible(false);
            delayFourMixLabel.setVisible(false);

            flangerFourDepthLabel.setVisible(false);
            flangerFourRateLabel.setVisible(false);
            flangerFourMixLabel.setVisible(false);

            vibratoFourDepthLabel.setVisible(false);
            vibratoFourRateLabel.setVisible(false);

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

            chorusFourDepthIndicator.setVisible(true);
            chorusFourVoicesIndicator.setVisible(true);
            chorusFourMixIndicator.setVisible(true);

            delayFourTimeIndicator.setVisible(false);
            delayFourFeedbackIndicator.setVisible(false);
            delayFourMixIndicator.setVisible(false);

            flangerFourDepthIndicator.setVisible(false);
            flangerFourRateIndicator.setVisible(false);
            flangerFourMixIndicator.setVisible(false);

            vibratoFourDepthIndicator.setVisible(false);
            vibratoFourRateIndicator.setVisible(false);

            chorusFourDepthLabel.setVisible(true);
            chorusFourVoicesLabel.setVisible(true);
            chorusFourMixLabel.setVisible(true);

            delayFourTimeLabel.setVisible(false);
            delayFourFeedbackLabel.setVisible(false);
            delayFourMixLabel.setVisible(false);

            flangerFourDepthLabel.setVisible(false);
            flangerFourRateLabel.setVisible(false);
            flangerFourMixLabel.setVisible(false);

            vibratoFourDepthLabel.setVisible(false);
            vibratoFourRateLabel.setVisible(false);

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

            chorusFourDepthIndicator.setVisible(false);
            chorusFourVoicesIndicator.setVisible(false);
            chorusFourMixIndicator.setVisible(false);

            delayFourTimeIndicator.setVisible(true);
            delayFourFeedbackIndicator.setVisible(true);
            delayFourMixIndicator.setVisible(true);

            flangerFourDepthIndicator.setVisible(false);
            flangerFourRateIndicator.setVisible(false);
            flangerFourMixIndicator.setVisible(false);

            vibratoFourDepthIndicator.setVisible(false);
            vibratoFourRateIndicator.setVisible(false);

            chorusFourDepthLabel.setVisible(false);
            chorusFourVoicesLabel.setVisible(false);
            chorusFourMixLabel.setVisible(false);

            delayFourTimeLabel.setVisible(true);
            delayFourFeedbackLabel.setVisible(true);
            delayFourMixLabel.setVisible(true);

            flangerFourDepthLabel.setVisible(false);
            flangerFourRateLabel.setVisible(false);
            flangerFourMixLabel.setVisible(false);

            vibratoFourDepthLabel.setVisible(false);
            vibratoFourRateLabel.setVisible(false);

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

            chorusFourDepthIndicator.setVisible(false);
            chorusFourVoicesIndicator.setVisible(false);
            chorusFourMixIndicator.setVisible(false);

            delayFourTimeIndicator.setVisible(false);
            delayFourFeedbackIndicator.setVisible(false);
            delayFourMixIndicator.setVisible(false);

            flangerFourDepthIndicator.setVisible(true);
            flangerFourRateIndicator.setVisible(true);
            flangerFourMixIndicator.setVisible(true);

            vibratoFourDepthIndicator.setVisible(false);
            vibratoFourRateIndicator.setVisible(false);

            chorusFourDepthLabel.setVisible(false);
            chorusFourVoicesLabel.setVisible(false);
            chorusFourMixLabel.setVisible(false);

            delayFourTimeLabel.setVisible(false);
            delayFourFeedbackLabel.setVisible(false);
            delayFourMixLabel.setVisible(false);

            flangerFourDepthLabel.setVisible(true);
            flangerFourRateLabel.setVisible(true);
            flangerFourMixLabel.setVisible(true);

            vibratoFourDepthLabel.setVisible(false);
            vibratoFourRateLabel.setVisible(false);

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

            chorusFourDepthIndicator.setVisible(false);
            chorusFourVoicesIndicator.setVisible(false);
            chorusFourMixIndicator.setVisible(false);

            delayFourTimeIndicator.setVisible(false);
            delayFourFeedbackIndicator.setVisible(false);
            delayFourMixIndicator.setVisible(false);

            flangerFourDepthIndicator.setVisible(false);
            flangerFourRateIndicator.setVisible(false);
            flangerFourMixIndicator.setVisible(false);

            vibratoFourDepthIndicator.setVisible(true);
            vibratoFourRateIndicator.setVisible(true);

            chorusFourDepthLabel.setVisible(false);
            chorusFourVoicesLabel.setVisible(false);
            chorusFourMixLabel.setVisible(false);

            delayFourTimeLabel.setVisible(false);
            delayFourFeedbackLabel.setVisible(false);
            delayFourMixLabel.setVisible(false);

            flangerFourDepthLabel.setVisible(false);
            flangerFourRateLabel.setVisible(false);
            flangerFourMixLabel.setVisible(false);

            vibratoFourDepthLabel.setVisible(true);
            vibratoFourRateLabel.setVisible(true);

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

    else if (slider == &chorusTwoDepthSlider) {
        chorusTwoDepthIndicator.setText(String(chorusTwoDepthSlider.getValue()) + " ms", dontSendNotification);
    }
    else if (slider == &chorusTwoVoicesSlider) {
        chorusTwoVoicesIndicator.setText(String(chorusTwoVoicesSlider.getValue()), dontSendNotification);
    }
    else if (slider == &chorusTwoMixSlider) {
        chorusTwoMixIndicator.setText(String(chorusTwoMixSlider.getValue()) + " %", dontSendNotification);
    }

    else if (slider == &delayTwoTimeSlider) {
        String timeinBars;

        if (delayTwoTimeSlider.getValue() == 0.0) {
            timeinBars = "1/32";
        }
        else if (delayTwoTimeSlider.getValue() == 12.5) {
            timeinBars = "1/16";
        }
        else if (delayTwoTimeSlider.getValue() == 25.0) {
            timeinBars = "1/8";
        }
        else if (delayTwoTimeSlider.getValue() == 37.5) {
            timeinBars = "1/4";
        }
        else if (delayTwoTimeSlider.getValue() == 50.0) {
            timeinBars = "1/2";
        }
        else if (delayTwoTimeSlider.getValue() == 62.5) {
            timeinBars = "1";
        }
        else if (delayTwoTimeSlider.getValue() == 75.0) {
            timeinBars = "2";
        }
        else if (delayTwoTimeSlider.getValue() == 87.5) {
            timeinBars = "4";
        }
        else if (delayTwoTimeSlider.getValue() == 100.0) {
            timeinBars = "8";
        }

        delayTwoTimeIndicator.setText(timeinBars, dontSendNotification);
    }
    else if (slider == &delayTwoFeedbackSlider) {
        delayTwoFeedbackIndicator.setText(String(delayTwoFeedbackSlider.getValue()) + " %", dontSendNotification);
    }
    else if (slider == &delayTwoMixSlider) {
        delayTwoMixIndicator.setText(String(delayTwoMixSlider.getValue()) + " %", dontSendNotification);
    }

    else if (slider == &flangerTwoDepthSlider) {
        flangerTwoDepthIndicator.setText(String(flangerTwoDepthSlider.getValue()) + " ms", dontSendNotification);
    }
    else if (slider == &flangerTwoRateSlider) {
        flangerTwoRateIndicator.setText(String(flangerTwoRateSlider.getValue()) + " Hz", dontSendNotification);
    }
    else if (slider == &flangerTwoMixSlider) {
        flangerTwoMixIndicator.setText(String(flangerTwoMixSlider.getValue()) + " %", dontSendNotification);
    }

    else if (slider == &vibratoTwoDepthSlider) {
        vibratoTwoDepthIndicator.setText(String(vibratoTwoDepthSlider.getValue()) + " ms", dontSendNotification);
    }
    else if (slider == &vibratoTwoRateSlider) {
        vibratoTwoRateIndicator.setText(String(vibratoTwoRateSlider.getValue()) + " Hz", dontSendNotification);
    }

    else if (slider == &chorusOneDepthSlider) {
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

    else if (slider == &chorusTwoDepthSlider) {
        chorusTwoDepthIndicator.setText(String(chorusTwoDepthSlider.getValue()) + " ms", dontSendNotification);
    }
    else if (slider == &chorusTwoVoicesSlider) {
        chorusTwoVoicesIndicator.setText(String(chorusTwoVoicesSlider.getValue()), dontSendNotification);
    }
    else if (slider == &chorusTwoMixSlider) {
        chorusTwoMixIndicator.setText(String(chorusTwoMixSlider.getValue()) + " %", dontSendNotification);
    }

    else if (slider == &delayTwoTimeSlider) {
        String timeinBars;

        if (delayTwoTimeSlider.getValue() == 0.0) {
            timeinBars = "1/32";
        }
        else if (delayTwoTimeSlider.getValue() == 12.5) {
            timeinBars = "1/16";
        }
        else if (delayTwoTimeSlider.getValue() == 25.0) {
            timeinBars = "1/8";
        }
        else if (delayTwoTimeSlider.getValue() == 37.5) {
            timeinBars = "1/4";
        }
        else if (delayTwoTimeSlider.getValue() == 50.0) {
            timeinBars = "1/2";
        }
        else if (delayTwoTimeSlider.getValue() == 62.5) {
            timeinBars = "1";
        }
        else if (delayTwoTimeSlider.getValue() == 75.0) {
            timeinBars = "2";
        }
        else if (delayTwoTimeSlider.getValue() == 87.5) {
            timeinBars = "4";
        }
        else if (delayTwoTimeSlider.getValue() == 100.0) {
            timeinBars = "8";
        }

        delayTwoTimeIndicator.setText(timeinBars, dontSendNotification);
    }
    else if (slider == &delayTwoFeedbackSlider) {
        delayTwoFeedbackIndicator.setText(String(delayTwoFeedbackSlider.getValue()) + " %", dontSendNotification);
    }
    else if (slider == &delayTwoMixSlider) {
        delayTwoMixIndicator.setText(String(delayTwoMixSlider.getValue()) + " %", dontSendNotification);
    }

    else if (slider == &flangerTwoDepthSlider) {
        flangerTwoDepthIndicator.setText(String(flangerTwoDepthSlider.getValue()) + " ms", dontSendNotification);
    }
    else if (slider == &flangerTwoRateSlider) {
        flangerTwoRateIndicator.setText(String(flangerTwoRateSlider.getValue()) + " Hz", dontSendNotification);
    }
    else if (slider == &flangerTwoMixSlider) {
        flangerTwoMixIndicator.setText(String(flangerTwoMixSlider.getValue()) + " %", dontSendNotification);
    }

    else if (slider == &vibratoTwoDepthSlider) {
        vibratoTwoDepthIndicator.setText(String(vibratoTwoDepthSlider.getValue()) + " ms", dontSendNotification);
    }
    else if (slider == &vibratoTwoRateSlider) {
        vibratoTwoRateIndicator.setText(String(vibratoTwoRateSlider.getValue()) + " Hz", dontSendNotification);
    }

    else if (slider == &chorusThreeDepthSlider) {
        chorusThreeDepthIndicator.setText(String(chorusThreeDepthSlider.getValue()) + " ms", dontSendNotification);
    }
    else if (slider == &chorusThreeVoicesSlider) {
        chorusThreeVoicesIndicator.setText(String(chorusThreeVoicesSlider.getValue()), dontSendNotification);
    }
    else if (slider == &chorusThreeMixSlider) {
        chorusThreeMixIndicator.setText(String(chorusThreeMixSlider.getValue()) + " %", dontSendNotification);
    }

    else if (slider == &delayThreeTimeSlider) {
        String timeinBars;

        if (delayThreeTimeSlider.getValue() == 0.0) {
            timeinBars = "1/32";
        }
        else if (delayThreeTimeSlider.getValue() == 12.5) {
            timeinBars = "1/16";
        }
        else if (delayThreeTimeSlider.getValue() == 25.0) {
            timeinBars = "1/8";
        }
        else if (delayThreeTimeSlider.getValue() == 37.5) {
            timeinBars = "1/4";
        }
        else if (delayThreeTimeSlider.getValue() == 50.0) {
            timeinBars = "1/2";
        }
        else if (delayThreeTimeSlider.getValue() == 62.5) {
            timeinBars = "1";
        }
        else if (delayThreeTimeSlider.getValue() == 75.0) {
            timeinBars = "2";
        }
        else if (delayThreeTimeSlider.getValue() == 87.5) {
            timeinBars = "4";
        }
        else if (delayThreeTimeSlider.getValue() == 100.0) {
            timeinBars = "8";
        }

        delayThreeTimeIndicator.setText(timeinBars, dontSendNotification);
    }
    else if (slider == &delayThreeFeedbackSlider) {
        delayThreeFeedbackIndicator.setText(String(delayThreeFeedbackSlider.getValue()) + " %", dontSendNotification);
    }
    else if (slider == &delayThreeMixSlider) {
        delayThreeMixIndicator.setText(String(delayThreeMixSlider.getValue()) + " %", dontSendNotification);
    }

    else if (slider == &flangerThreeDepthSlider) {
        flangerThreeDepthIndicator.setText(String(flangerThreeDepthSlider.getValue()) + " ms", dontSendNotification);
    }
    else if (slider == &flangerThreeRateSlider) {
        flangerThreeRateIndicator.setText(String(flangerThreeRateSlider.getValue()) + " Hz", dontSendNotification);
    }
    else if (slider == &flangerThreeMixSlider) {
        flangerThreeMixIndicator.setText(String(flangerThreeMixSlider.getValue()) + " %", dontSendNotification);
    }

    else if (slider == &vibratoThreeDepthSlider) {
        vibratoThreeDepthIndicator.setText(String(vibratoThreeDepthSlider.getValue()) + " ms", dontSendNotification);
    }
    else if (slider == &vibratoThreeRateSlider) {
        vibratoThreeRateIndicator.setText(String(vibratoThreeRateSlider.getValue()) + " Hz", dontSendNotification);
    }

    else if (slider == &chorusFourDepthSlider) {
        chorusFourDepthIndicator.setText(String(chorusFourDepthSlider.getValue()) + " ms", dontSendNotification);
    }
    else if (slider == &chorusFourVoicesSlider) {
        chorusFourVoicesIndicator.setText(String(chorusFourVoicesSlider.getValue()), dontSendNotification);
    }
    else if (slider == &chorusFourMixSlider) {
        chorusFourMixIndicator.setText(String(chorusFourMixSlider.getValue()) + " %", dontSendNotification);
    }

    else if (slider == &delayFourTimeSlider) {
        String timeinBars;

        if (delayFourTimeSlider.getValue() == 0.0) {
            timeinBars = "1/32";
        }
        else if (delayFourTimeSlider.getValue() == 12.5) {
            timeinBars = "1/16";
        }
        else if (delayFourTimeSlider.getValue() == 25.0) {
            timeinBars = "1/8";
        }
        else if (delayFourTimeSlider.getValue() == 37.5) {
            timeinBars = "1/4";
        }
        else if (delayFourTimeSlider.getValue() == 50.0) {
            timeinBars = "1/2";
        }
        else if (delayFourTimeSlider.getValue() == 62.5) {
            timeinBars = "1";
        }
        else if (delayFourTimeSlider.getValue() == 75.0) {
            timeinBars = "2";
        }
        else if (delayFourTimeSlider.getValue() == 87.5) {
            timeinBars = "4";
        }
        else if (delayFourTimeSlider.getValue() == 100.0) {
            timeinBars = "8";
        }

        delayFourTimeIndicator.setText(timeinBars, dontSendNotification);
    }
    else if (slider == &delayFourFeedbackSlider) {
        delayFourFeedbackIndicator.setText(String(delayFourFeedbackSlider.getValue()) + " %", dontSendNotification);
    }
    else if (slider == &delayFourMixSlider) {
        delayFourMixIndicator.setText(String(delayFourMixSlider.getValue()) + " %", dontSendNotification);
    }

    else if (slider == &flangerFourDepthSlider) {
        flangerFourDepthIndicator.setText(String(flangerFourDepthSlider.getValue()) + " ms", dontSendNotification);
    }
    else if (slider == &flangerFourRateSlider) {
        flangerFourRateIndicator.setText(String(flangerFourRateSlider.getValue()) + " Hz", dontSendNotification);
    }
    else if (slider == &flangerFourMixSlider) {
        flangerFourMixIndicator.setText(String(flangerFourMixSlider.getValue()) + " %", dontSendNotification);
    }

    else if (slider == &vibratoFourDepthSlider) {
        vibratoFourDepthIndicator.setText(String(vibratoFourDepthSlider.getValue()) + " ms", dontSendNotification);
    }
    else if (slider == &vibratoFourRateSlider) {
        vibratoFourRateIndicator.setText(String(vibratoFourRateSlider.getValue()) + " Hz", dontSendNotification);
    }
}