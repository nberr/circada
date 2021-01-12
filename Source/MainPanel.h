/*
  ==============================================================================

    MainPanel.h
    Created: 11 Jan 2021 11:49:55pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"

#include "TopPanel.h"
#include "CenterPanel.h"
#include "RightPanel.h"
#include "BottomPanel.h"

class MainPanel
:   public PanelBase
{
public:
    MainPanel(CircadaAudioProcessor* inProcessor);
    ~MainPanel();
    
private:
    std::unique_ptr<TopPanel> mTopPanel;
    std::unique_ptr<CenterPanel> mCenterPanel;
    std::unique_ptr<BottomPanel> mBottomPanel;
    std::unique_ptr<RightPanel> mRightPanel;
    
};
