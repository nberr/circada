/*
  ==============================================================================

    BottomPanel.cpp
    Created: 11 Jan 2021 11:26:58pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "BottomPanel.h"

BottomPanel::BottomPanel(CircadaAudioProcessor *inProcessor)
:   PanelBase(inProcessor)
{
    setSize(BOTTOM_PANEL_WIDTH, BOTTOM_PANEL_HEIGHT);
}

BottomPanel::~BottomPanel()
{
    
}

void BottomPanel::paint(juce::Graphics& g)
{
    PanelBase::paint(g);
}
