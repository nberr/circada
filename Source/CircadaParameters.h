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
    CP_Ramp, // 0 to 100
    CP_RampExp, // -100 to 100
    CP_Longmode, // on/off
    CP_Dry, // 0% to 100%
    CP_Wet, // -30dB to 12dB
    CP_PostRecord, // on/off
    CP_TotalNumParameters
};

typedef enum type_t {
    is_int,
    is_float,
    is_bool
}type;

typedef union value_t {
    int ivalue;
    float fvalue;
    bool bvalue;
}value;

static type CircadaParameterTypes[CP_TotalNumParameters] = {
    is_bool,
    is_float,
    is_float,
    is_float,
    is_float,
    is_float,
    is_bool,
    is_float,
    is_float,
    is_bool
};

static value CircadaParameterDefaultValues[CP_TotalNumParameters] = {
    {.bvalue = false},
    {.fvalue = 2.0},
    {.fvalue = 1000},
    {.fvalue = 0},
    {.fvalue = 100},
    {.fvalue = 0},
    {.bvalue = false},
    {.fvalue = 0},
    {.fvalue = 0},
    {.bvalue = false}
};

static value CircadaParameterMinValues[CP_TotalNumParameters] = {
    {.bvalue = false},
    {.fvalue = -2.0},
    {.fvalue = 500},
    {.fvalue = 0},
    {.fvalue = 0},
    {.fvalue = -1},
    {.bvalue = false},
    {.fvalue = 0},
    {.fvalue = -30},
    {.bvalue = false}
};

static value CircadaParamaterMaxValues[CP_TotalNumParameters] = {
    {.bvalue = true},
    {.fvalue = 2.0},
    {.fvalue = 3000},
    {.fvalue = 1},
    {.fvalue = 1},
    {.fvalue = 1},
    {.bvalue = true},
    {.fvalue = 1},
    {.fvalue = 12},
    {.bvalue = true}
};

static const juce::String CircadaParameterID[CP_TotalNumParameters] =
{
    "Play",
    "Rate",
    "Length",
    "Offset",
    "Ramp",
    "RampExp"
    "Longmode",
    "Dry",
    "Wet",
    "PostRecord"
};

static const juce::String CircadaParameterLabel[CP_TotalNumParameters] =
{
    "Play",
    "Rate",
    "Length",
    "Offset",
    "Ramp",
    "RampExp"
    "Longmode",
    "Dry",
    "Wet",
    "PostRecord"
};
