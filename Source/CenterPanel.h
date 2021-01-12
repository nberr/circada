/*
  ==============================================================================

    CenterPanel.h
    Created: 11 Jan 2021 11:27:12pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"

class CenterPanel
:   public PanelBase
{
public:
    CenterPanel(CircadaAudioProcessor* inProcessor);
    ~CenterPanel();
    
    void paint(juce::Graphics& g) override;
    
private:
    
};
