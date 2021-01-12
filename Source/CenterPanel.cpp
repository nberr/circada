/*
  ==============================================================================

    CenterPanel.cpp
    Created: 11 Jan 2021 11:27:12pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "CenterPanel.h"

CenterPanel::CenterPanel(CircadaAudioProcessor *inProcessor)
:   PanelBase(inProcessor)
{
    setSize(CENTER_PANEL_WIDTH, CENTER_PANEL_HEIGHT);
}

CenterPanel::~CenterPanel()
{
    
}

void CenterPanel::paint(juce::Graphics& g)
{
    PanelBase::paint(g);
}
