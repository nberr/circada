/*
  ==============================================================================

    BottomPanel.h
    Created: 11 Jan 2021 11:26:58pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"

class BottomPanel
:   public PanelBase
{
public:
    BottomPanel(CircadaAudioProcessor* inProcessor);
    ~BottomPanel();
    
    void paint(juce::Graphics& g) override;
    
private:
    
};
