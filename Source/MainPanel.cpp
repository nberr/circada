/*
  ==============================================================================

    MainPanel.cpp
    Created: 11 Jan 2021 11:49:55pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "MainPanel.h"

MainPanel::MainPanel(CircadaAudioProcessor *inProcessor)
:   PanelBase(inProcessor)
{
    setSize(MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);
    
    mTopPanel = std::make_unique<TopPanel>(inProcessor);
    mTopPanel->setTopLeftPosition(BUFFER, BUFFER);
    addAndMakeVisible(*mTopPanel);
    
    mCenterPanel = std::make_unique<CenterPanel>(inProcessor);
    mCenterPanel->setTopLeftPosition(BUFFER, (BUFFER * 2) + TOP_PANEL_HEIGHT);
    addAndMakeVisible(*mCenterPanel);
    
    mBottomPanel = std::make_unique<BottomPanel>(inProcessor);
    mBottomPanel->setTopLeftPosition(BUFFER, (BUFFER * 3) + TOP_PANEL_HEIGHT + CENTER_PANEL_HEIGHT);
    addAndMakeVisible(*mBottomPanel);
    
    mRightPanel = std::make_unique<RightPanel>(inProcessor);
    mRightPanel->setTopLeftPosition((BUFFER * 2) + TOP_PANEL_WIDTH, BUFFER);
    addAndMakeVisible(*mRightPanel);
}

MainPanel::~MainPanel()
{
    
}

