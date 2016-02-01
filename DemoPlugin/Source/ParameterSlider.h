/*
  ==============================================================================

    ParameterSlider.h
    Created: 1 Feb 2016 6:11:28pm
    Author:  maria kourousi

  ==============================================================================
*/

#ifndef PARAMETERSLIDER_H_INCLUDED
#define PARAMETERSLIDER_H_INCLUDED

// Define Headers
#include "../JuceLibraryCode/JuceHeader.h"

/*
 This is a slider subclass that controls an AudioProcessorParameter.
 */
class ParameterSlider   :   public Slider,
                            private Timer
{
public:
    /** Constructor
     * @param p     The AudioProcessorParameter that this slider affects.
     * @param minimum The minimum value of the slider
     * @param maximum The maximum value of the slider
     * @param interval The steps of the slider
     */
    ParameterSlider (AudioProcessorParameter& p, double minimum, double maximum, double interval);
    
    /** Destructor
     */
    ~ParameterSlider();
    
    void valueChanged() override;
    void startedDragging() override;
    void stoppedDragging() override;

    double getValueFromText (const String& text) override;
    String getTextFromValue (double value) override;
    
    /** Updates the value of the slider with the current value of the parameter.
     */
    void updateSliderPos();

    void timerCallback() override;

private:
    AudioProcessorParameter& param;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ParameterSlider)
};



#endif  // PARAMETERSLIDER_H_INCLUDED
