/*
  ==============================================================================

    TopPanel.cpp
    Created: 11 Jan 2021 11:26:47pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "TopPanel.h"

TopPanel::TopPanel(CircadaAudioProcessor *inProcessor)
:   PanelBase(inProcessor)
{
    setSize(TOP_PANEL_WIDTH, TOP_PANEL_HEIGHT);
    
    mLengthParameter = (float *)inProcessor->parameters.getRawParameterValue("Length");
    
    mLengthSlider = std::make_unique<juce::Slider>();
    mLengthSlider->setSize(40, 40);
    mLengthSlider->setTopLeftPosition(60, 0);
    addAndMakeVisible(*mLengthSlider);
}

TopPanel::~TopPanel()
{
    
}

void TopPanel::paint(juce::Graphics& g)
{
    PanelBase::paint(g);
}
