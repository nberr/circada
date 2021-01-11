/*
  ==============================================================================

    CircadaParameters.h
    Created: 11 Jan 2021 1:28:15am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

enum CircadaParameter
{
    CP_Play = 0, // on/off
    CP_Rate, // -2Hz to 2Hz
    CP_Length, // 500ms to 3s
    CP_Offset, // 0% to 100%
    //Reset, // button skips playback to the offset position
    //Rampsmooth
    CP_Longmode, // on/off
    CP_Dry, // 0% to 100%
    CP_Wet, // -30dB to 12dB
    // vu meter
    CP_PostRecord, // on/off
    CP_TotalNumParameters
};

static const juce::String CircadaParameterID[CP_TotalNumParameters] =
{
    "Play",
    "Rate",
    "Length",
    "Offset",
    //"Reset",
    //"Rampsmooth",
    "Longmode",
    "Dry",
    "Wet",
    //"VU",
    "PostRecord"
};

static const juce::String CircadaParameterLabel[CP_TotalNumParameters] =
{
    "Play",
    "Rate",
    "Length",
    "Offset",
    //"Reset",
    //"Rampsmooth",
    "Longmode",
    "Dry",
    "Wet",
    //"VU",
    "PostRecord"
};
