/*
  ==============================================================================

    RightPanel.h
    Created: 11 Jan 2021 11:27:19pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"

class RightPanel
:   public PanelBase
{
public:
    RightPanel(CircadaAudioProcessor* inProcessor);
    ~RightPanel();
    
    void paint(juce::Graphics& g) override;
    
private:
    
};
