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
class QrsuiAudioProcessorEditor  : public juce::AudioProcessorEditor,
    public juce::Slider::Listener,
    public juce::Button::Listener
{
public:
    QrsuiAudioProcessorEditor (QrsuiAudioProcessor&);
    ~QrsuiAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.


    juce::Slider presetKnob;
    juce::TextButton decayMinusButton;
    juce::TextButton decayPlusButton;
    juce::Label decayValueLabel;
    juce::TextEditor decayValueText;
    juce::TextButton powerButton;
    QrsuiAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (QrsuiAudioProcessorEditor)
};
