/*
  ==============================================================================

    PanelBase.cpp
    Created: 11 Jan 2021 11:26:16pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "PanelBase.h"
PanelBase::PanelBase(CircadaAudioProcessor* inProcessor)
{
    mProcessor = inProcessor;
}

PanelBase::~PanelBase()
{
    
}

void PanelBase::paint(juce::Graphics& g)
{
    g.setColour(juce::Colours::white);
    g.fillAll();
        
    g.setColour(juce::Colours::black);
    g.drawRoundedRectangle(0, 0, getWidth(), getHeight(), 4, 8);
}
