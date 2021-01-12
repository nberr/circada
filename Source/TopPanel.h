/*
  ==============================================================================

    TopPanel.h
    Created: 11 Jan 2021 11:26:47pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"

class TopPanel
:   public PanelBase
{
public:
    TopPanel(CircadaAudioProcessor* inProcessor);
    ~TopPanel();
    
    void paint(juce::Graphics& g) override;
    
private:
    std::unique_ptr<juce::Slider> mLengthSlider;
    
    float *mLengthParameter;
};
