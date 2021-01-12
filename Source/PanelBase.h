/*
  ==============================================================================

    PanelBase.h
    Created: 11 Jan 2021 11:26:16pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

#include "InterfaceDefines.h"
#include "PluginProcessor.h"
#include "CircadaLookAndFeel.h"

class PanelBase
: public juce::Component
{
public:
    PanelBase(CircadaAudioProcessor* inProcessor);
    ~PanelBase();
    
    void paint(juce::Graphics& g) override;
    
private:
    CircadaAudioProcessor *mProcessor;
};
