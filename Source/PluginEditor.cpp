/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
QrsuiAudioProcessorEditor::QrsuiAudioProcessorEditor (QrsuiAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.

    // Create rotary knob for preset selection
    presetKnob.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    presetKnob.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    presetKnob.setRange(0, 10, 1);
    presetKnob.setValue(0);
    presetKnob.addListener(this);
    addAndMakeVisible(presetKnob);

    // create pls and minus buttons for adjusting parameters
    decayMinusButton.setButtonText("-");
    decayMinusButton.addListener(this);
    addAndMakeVisible(decayMinusButton);

    decayPlusButton.setButtonText("+");
    decayPlusButton.addListener(this);
    addAndMakeVisible(decayMinusButton);

    decayPlusButton.setButtonText("+");
    decayPlusButton.addListener(this);
    addAndMakeVisible(decayPlusButton);

    // create numerical readout for decay parameter
    decayValueLabel.setText("Decay Time", juce::dontSendNotification);
    addAndMakeVisible(decayValueLabel);

    decayValueText.setJustification(juce::Justification::centred);
    decayValueText.setEnabled(false);
    decayValueText.setText("0.0", juce::dontSendNotification);
    addAndMakeVisible(decayValueText);

    //create power button
    powerButton.setButtonText("Power");
    powerButton.addListener(this);
    addAndMakeVisible(powerButton);

    //set up window size and visibility
    setSize(400, 300);
    setVisible(true);
    setSize (400, 300);
}

QrsuiAudioProcessorEditor::~QrsuiAudioProcessorEditor()
{
}

//==============================================================================
void QrsuiAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void QrsuiAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
