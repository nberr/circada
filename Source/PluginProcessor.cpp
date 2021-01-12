/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

#include "CircadaParameters.h"

//==============================================================================
CircadaAudioProcessor::CircadaAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       ),
#endif
parameters(*this, nullptr, "PARAMETERS", createParameterLayout())
{
}

CircadaAudioProcessor::~CircadaAudioProcessor()
{
}

//==============================================================================
const juce::String CircadaAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool CircadaAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool CircadaAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool CircadaAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double CircadaAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int CircadaAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int CircadaAudioProcessor::getCurrentProgram()
{
    return 0;
}

void CircadaAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String CircadaAudioProcessor::getProgramName (int index)
{
    return {};
}

void CircadaAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void CircadaAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void CircadaAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool CircadaAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void CircadaAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        // auto* channelData = buffer.getWritePointer (channel);

        // ..do something to the data...
    }
}

//==============================================================================
bool CircadaAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* CircadaAudioProcessor::createEditor()
{
    return new CircadaAudioProcessorEditor (*this);
}

//==============================================================================
void CircadaAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    auto state = parameters.copyState();
    std::unique_ptr<juce::XmlElement> xml (state.createXml());
    copyXmlToBinary (*xml, destData);
}

void CircadaAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    std::unique_ptr<juce::XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));

    if (xmlState.get() != nullptr)
        if (xmlState->hasTagName (parameters.state.getType()))
            parameters.replaceState (juce::ValueTree::fromXml (*xmlState));
}

juce::AudioProcessorValueTreeState::ParameterLayout  CircadaAudioProcessor::createParameterLayout()
{
    juce::AudioProcessorValueTreeState::ParameterLayout params;
    
    // play - on/off
    params.add(std::make_unique<juce::AudioParameterBool>(CircadaParameterID[0], CircadaParameterID[0], false));
    
    // rate - -2hz to 2hz
    params.add(std::make_unique<juce::AudioParameterFloat>(CircadaParameterID[1],CircadaParameterID[1], -2, 2, 0));
    
    // length - 500ms to 3s
    params.add(std::make_unique<juce::AudioParameterFloat>(CircadaParameterID[2],CircadaParameterID[2], 0.5, 3, 1));
    
    // offset - 0% to 100%
    params.add(std::make_unique<juce::AudioParameterFloat>(CircadaParameterID[3],CircadaParameterID[3], 0, 1, 0.5));
    
    // longmode - on/off
    params.add(std::make_unique<juce::AudioParameterBool>(CircadaParameterID[4], CircadaParameterID[4], false));
    
    // dry - 0% to 100%
    params.add(std::make_unique<juce::AudioParameterFloat>(CircadaParameterID[5],CircadaParameterID[5], 0, 1, 0.5));
    
    // wet - -30dB to 12dB
    params.add(std::make_unique<juce::AudioParameterFloat>(CircadaParameterID[6],CircadaParameterID[6], -30, 12, 0));
    
    // postrecord - on/off
    params.add(std::make_unique<juce::AudioParameterBool>(CircadaParameterID[7], CircadaParameterID[7], false));
    
    return params;
}


//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new CircadaAudioProcessor();
}
