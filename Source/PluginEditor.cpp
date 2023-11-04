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
    setSize(730, 300);

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
    chorusOneDepthSlider.setRange(20.0, 30.0, 0.01);
    chorusOneDepthSlider.setValue(audioProcessor.getValue("C1D"));
    chorusOneDepthSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&chorusOneDepthSlider);

    chorusOneVoicesSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    chorusOneVoicesSlider.setRange(1.0, 3.0, 1.0);
    chorusOneVoicesSlider.setValue(audioProcessor.getValue("C1V"));
    chorusOneVoicesSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&chorusOneVoicesSlider);

    chorusTwoDepthSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    chorusTwoDepthSlider.setRange(20.0, 30.0, 0.01);
    chorusTwoDepthSlider.setValue(audioProcessor.getValue("C2D"));
    chorusTwoDepthSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&chorusTwoDepthSlider);

    chorusTwoVoicesSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    chorusTwoVoicesSlider.setRange(1.0, 3.0, 1.0);
    chorusTwoVoicesSlider.setValue(audioProcessor.getValue("C2V"));
    chorusTwoVoicesSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&chorusTwoVoicesSlider);

    chorusThreeDepthSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    chorusThreeDepthSlider.setRange(20.0, 30.0, 0.01);
    chorusThreeDepthSlider.setValue(audioProcessor.getValue("C3D"));
    chorusThreeDepthSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&chorusThreeDepthSlider);

    chorusThreeVoicesSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    chorusThreeVoicesSlider.setRange(1.0, 3.0, 1.0);
    chorusThreeVoicesSlider.setValue(audioProcessor.getValue("C3V"));
    chorusThreeVoicesSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&chorusThreeVoicesSlider);

    chorusFourDepthSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    chorusFourDepthSlider.setRange(20.0, 30.0, 0.01);
    chorusFourDepthSlider.setValue(audioProcessor.getValue("C4D"));
    chorusFourDepthSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&chorusFourDepthSlider);

    chorusFourVoicesSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    chorusFourVoicesSlider.setRange(1.0, 3.0, 1.0);
    chorusFourVoicesSlider.setValue(audioProcessor.getValue("C4V"));
    chorusFourVoicesSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&chorusFourVoicesSlider);

    delayOneTimeSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    delayOneTimeSlider.setRange(0.0, 100.0, 12.5);
    delayOneTimeSlider.setValue(audioProcessor.getValue("D1T"));
    delayOneTimeSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&delayOneTimeSlider);

    delayOneFeedbackSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    delayOneFeedbackSlider.setRange(0.0, 100.0, 1.0);
    delayOneFeedbackSlider.setValue(audioProcessor.getValue("D1F"));
    delayOneFeedbackSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&delayOneFeedbackSlider);

    delayTwoTimeSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    delayTwoTimeSlider.setRange(0.0, 100.0, 12.5);
    delayTwoTimeSlider.setValue(audioProcessor.getValue("D2T"));
    delayTwoTimeSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&delayTwoTimeSlider);

    delayTwoFeedbackSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    delayTwoFeedbackSlider.setRange(0.0, 100.0, 1.0);
    delayTwoFeedbackSlider.setValue(audioProcessor.getValue("D2F"));
    delayTwoFeedbackSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&delayTwoFeedbackSlider);

    delayThreeTimeSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    delayThreeTimeSlider.setRange(0.0, 100.0, 12.5);
    delayThreeTimeSlider.setValue(audioProcessor.getValue("D3T"));
    delayThreeTimeSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&delayThreeTimeSlider);

    delayThreeFeedbackSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    delayThreeFeedbackSlider.setRange(0.0, 100.0, 1.0);
    delayThreeFeedbackSlider.setValue(audioProcessor.getValue("D3F"));
    delayThreeFeedbackSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&delayThreeFeedbackSlider);

    delayFourTimeSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    delayFourTimeSlider.setRange(0.0, 100.0, 12.5);
    delayFourTimeSlider.setValue(audioProcessor.getValue("D4T"));
    delayFourTimeSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&delayFourTimeSlider);

    delayFourFeedbackSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    delayFourFeedbackSlider.setRange(0.0, 100.0, 1.0);
    delayFourFeedbackSlider.setValue(audioProcessor.getValue("D4F"));
    delayFourFeedbackSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&delayFourFeedbackSlider);

    flangerOneDepthSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    flangerOneDepthSlider.setRange(0.0, 10.0, 0.01);
    flangerOneDepthSlider.setValue(audioProcessor.getValue("F1D"));
    flangerOneDepthSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&flangerOneDepthSlider);

    flangerOneRateSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    flangerOneRateSlider.setRange(1.0, 10.0, 0.01);
    flangerOneRateSlider.setValue(audioProcessor.getValue("F1R"));
    flangerOneRateSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&flangerOneRateSlider);

    flangerTwoDepthSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    flangerTwoDepthSlider.setRange(0.0, 10.0, 0.01);
    flangerTwoDepthSlider.setValue(audioProcessor.getValue("F2D"));
    flangerTwoDepthSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&flangerTwoDepthSlider);

    flangerTwoRateSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    flangerTwoRateSlider.setRange(1.0, 10.0, 0.01);
    flangerTwoRateSlider.setValue(audioProcessor.getValue("F2R"));
    flangerTwoRateSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&flangerTwoRateSlider);

    flangerThreeDepthSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    flangerThreeDepthSlider.setRange(0.0, 10.0, 0.01);
    flangerThreeDepthSlider.setValue(audioProcessor.getValue("F3D"));
    flangerThreeDepthSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&flangerThreeDepthSlider);

    flangerThreeRateSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    flangerThreeRateSlider.setRange(1.0, 10.0, 0.01);
    flangerThreeRateSlider.setValue(audioProcessor.getValue("F3R"));
    flangerThreeRateSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&flangerThreeRateSlider);

    flangerFourDepthSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    flangerFourDepthSlider.setRange(0.0, 10.0, 0.01);
    flangerFourDepthSlider.setValue(audioProcessor.getValue("F4D"));
    flangerFourDepthSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&flangerFourDepthSlider);

    flangerFourRateSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    flangerFourRateSlider.setRange(1.0, 10.0, 0.01);
    flangerFourRateSlider.setValue(audioProcessor.getValue("F4R"));
    flangerFourRateSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&flangerFourRateSlider);

    vibratoOneDepthSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    vibratoOneDepthSlider.setRange(0.0, 10.0, 0.01);
    vibratoOneDepthSlider.setValue(audioProcessor.getValue("V1D"));
    vibratoOneDepthSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&vibratoOneDepthSlider);

    vibratoOneRateSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    vibratoOneRateSlider.setRange(0.01, 10.0, 0.001);
    vibratoOneRateSlider.setValue(audioProcessor.getValue("V1R"));
    vibratoOneRateSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&vibratoOneRateSlider);

    vibratoTwoDepthSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    vibratoTwoDepthSlider.setRange(0.0, 10.0, 0.01);
    vibratoTwoDepthSlider.setValue(audioProcessor.getValue("V2D"));
    vibratoTwoDepthSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&vibratoTwoDepthSlider);

    vibratoTwoRateSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    vibratoTwoRateSlider.setRange(0.01, 10.0, 0.001);
    vibratoTwoRateSlider.setValue(audioProcessor.getValue("V2R"));
    vibratoTwoRateSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&vibratoTwoRateSlider);

    vibratoThreeDepthSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    vibratoThreeDepthSlider.setRange(0.0, 10.0, 0.01);
    vibratoThreeDepthSlider.setValue(audioProcessor.getValue("V3D"));
    vibratoThreeDepthSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&vibratoThreeDepthSlider);

    vibratoThreeRateSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    vibratoThreeRateSlider.setRange(0.01, 10.0, 0.001);
    vibratoThreeRateSlider.setValue(audioProcessor.getValue("V3R"));
    vibratoThreeRateSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&vibratoThreeRateSlider);

    vibratoFourDepthSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    vibratoFourDepthSlider.setRange(0.0, 10.0, 0.01);
    vibratoFourDepthSlider.setValue(audioProcessor.getValue("V4D"));
    vibratoFourDepthSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&vibratoFourDepthSlider);

    vibratoFourRateSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    vibratoFourRateSlider.setRange(0.01, 10.0, 0.001);
    vibratoFourRateSlider.setValue(audioProcessor.getValue("V4R"));
    vibratoFourRateSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&vibratoFourRateSlider);

    chorusOneMixSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    chorusOneMixSlider.setRange(0.0, 100.0, 0.1);
    chorusOneMixSlider.setValue(audioProcessor.getValue("C1M"));
    chorusOneMixSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&chorusOneMixSlider);

    chorusTwoMixSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    chorusTwoMixSlider.setRange(0.0, 100.0, 0.1);
    chorusTwoMixSlider.setValue(audioProcessor.getValue("C2M"));
    chorusTwoMixSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&chorusTwoMixSlider);

    chorusThreeMixSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    chorusThreeMixSlider.setRange(0.0, 100.0, 0.1);
    chorusThreeMixSlider.setValue(audioProcessor.getValue("C3M"));
    chorusThreeMixSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&chorusThreeMixSlider);

    chorusFourMixSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    chorusFourMixSlider.setRange(0.0, 100.0, 0.1);
    chorusFourMixSlider.setValue(audioProcessor.getValue("C4M"));
    chorusFourMixSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&chorusFourMixSlider);

    delayOneMixSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    delayOneMixSlider.setRange(0.0, 100.0, 0.1);
    delayOneMixSlider.setValue(audioProcessor.getValue("D1M"));
    delayOneMixSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&delayOneMixSlider);

    delayTwoMixSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    delayTwoMixSlider.setRange(0.0, 100.0, 0.1);
    delayTwoMixSlider.setValue(audioProcessor.getValue("D2M"));
    delayTwoMixSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&delayTwoMixSlider);

    delayThreeMixSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    delayThreeMixSlider.setRange(0.0, 100.0, 0.1);
    delayThreeMixSlider.setValue(audioProcessor.getValue("D3M"));
    delayThreeMixSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&delayThreeMixSlider);

    delayFourMixSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    delayFourMixSlider.setRange(0.0, 100.0, 0.1);
    delayFourMixSlider.setValue(audioProcessor.getValue("D4M"));
    delayFourMixSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&delayFourMixSlider);

    flangerOneMixSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    flangerOneMixSlider.setRange(0.0, 100.0, 0.1);
    flangerOneMixSlider.setValue(audioProcessor.getValue("F1M"));
    flangerOneMixSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&flangerOneMixSlider);

    flangerTwoMixSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    flangerTwoMixSlider.setRange(0.0, 100.0, 0.1);
    flangerTwoMixSlider.setValue(audioProcessor.getValue("F2M"));
    flangerTwoMixSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&flangerTwoMixSlider);

    flangerThreeMixSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    flangerThreeMixSlider.setRange(0.0, 100.0, 0.1);
    flangerThreeMixSlider.setValue(audioProcessor.getValue("F3M"));
    flangerThreeMixSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&flangerThreeMixSlider);

    flangerFourMixSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    flangerFourMixSlider.setRange(0.0, 100.0, 0.1);
    flangerFourMixSlider.setValue(audioProcessor.getValue("F4M"));
    flangerFourMixSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
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
    slotOneComboBox.setBounds(10, 10, 170, 20);
    slotTwoComboBox.setBounds(190, 10, 170, 20);
    slotThreeComboBox.setBounds(370, 10, 170, 20);
    slotFourComboBox.setBounds(550, 10, 170, 20);

    chorusOneDepthSlider.setBounds(10, 40, 80, 80);
    chorusOneVoicesSlider.setBounds(100, 40, 80, 80);
    chorusTwoDepthSlider.setBounds(190, 40, 80, 80);
    chorusTwoVoicesSlider.setBounds(280, 40, 80, 80);
    chorusThreeDepthSlider.setBounds(370, 40, 80, 80);
    chorusThreeVoicesSlider.setBounds(460, 40, 80, 80);
    chorusFourDepthSlider.setBounds(550, 40, 80, 80);
    chorusFourVoicesSlider.setBounds(640, 40, 80, 80);

    delayOneTimeSlider.setBounds(10, 40, 80, 80);
    delayOneFeedbackSlider.setBounds(100, 40, 80, 80);
    delayTwoTimeSlider.setBounds(190, 40, 80, 80);
    delayTwoFeedbackSlider.setBounds(280, 40, 80, 80);
    delayThreeTimeSlider.setBounds(370, 40, 80, 80);
    delayThreeFeedbackSlider.setBounds(460, 40, 80, 80);
    delayFourTimeSlider.setBounds(550, 40, 80, 80);
    delayFourFeedbackSlider.setBounds(640, 40, 80, 80);

    flangerOneDepthSlider.setBounds(10, 40, 80, 80);
    flangerOneRateSlider.setBounds(100, 40, 80, 80);
    flangerTwoDepthSlider.setBounds(190, 40, 80, 80);
    flangerTwoRateSlider.setBounds(280, 40, 80, 80);
    flangerThreeDepthSlider.setBounds(370, 40, 80, 80);
    flangerThreeRateSlider.setBounds(460, 40, 80, 80);
    flangerFourDepthSlider.setBounds(550, 40, 80, 80);
    flangerFourRateSlider.setBounds(640, 40, 80, 80);

    vibratoOneDepthSlider.setBounds(10, 40, 80, 80);
    vibratoOneRateSlider.setBounds(100, 40, 80, 80);
    vibratoTwoDepthSlider.setBounds(190, 40, 80, 80);
    vibratoTwoRateSlider.setBounds(280, 40, 80, 80);
    vibratoThreeDepthSlider.setBounds(370, 40, 80, 80);
    vibratoThreeRateSlider.setBounds(460, 40, 80, 80);
    vibratoFourDepthSlider.setBounds(550, 40, 80, 80);
    vibratoFourRateSlider.setBounds(640, 40, 80, 80);

    chorusOneMixSlider.setBounds(10, 150, 120, 120);
    chorusTwoMixSlider.setBounds(190, 150, 120, 120);
    chorusThreeMixSlider.setBounds(370, 150, 120, 120);
    chorusFourMixSlider.setBounds(550, 150, 120, 120);

    delayOneMixSlider.setBounds(10, 150, 120, 120);
    delayTwoMixSlider.setBounds(190, 150, 120, 120);
    delayThreeMixSlider.setBounds(370, 150, 120, 120);
    delayFourMixSlider.setBounds(550, 150, 120, 120);

    flangerOneMixSlider.setBounds(10, 150, 120, 120);
    flangerTwoMixSlider.setBounds(190, 150, 120, 120);
    flangerThreeMixSlider.setBounds(370, 150, 120, 120);
    flangerFourMixSlider.setBounds(550, 150, 120, 120);
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