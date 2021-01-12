/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
CircadaAudioProcessorEditor::CircadaAudioProcessorEditor (CircadaAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);
    
    mMainPanel = std::make_unique<MainPanel>(&audioProcessor);
    mMainPanel->setTopLeftPosition(0, 0);
    addAndMakeVisible(*mMainPanel);
}

CircadaAudioProcessorEditor::~CircadaAudioProcessorEditor()
{
    setLookAndFeel(nullptr);
    juce::LookAndFeel::setDefaultLookAndFeel(nullptr);
}

//==============================================================================
void CircadaAudioProcessorEditor::paint (juce::Graphics& g)
{
    
}

void CircadaAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
