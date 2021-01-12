/*
  ==============================================================================

    RightPanel.cpp
    Created: 11 Jan 2021 11:27:19pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "RightPanel.h"

RightPanel::RightPanel(CircadaAudioProcessor *inProcessor)
:   PanelBase(inProcessor)
{
    setSize(RIGHT_PANEL_WIDTH, RIGHT_PANEL_HEIGHT);
}

RightPanel::~RightPanel()
{
    
}

void RightPanel::paint(juce::Graphics& g)
{
    PanelBase::paint(g);
}

