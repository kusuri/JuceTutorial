/*
  ==============================================================================

    ParameterSlider.cpp
    Created: 1 Feb 2016 6:11:28pm
    Author:  maria kourousi

  ==============================================================================
*/

#include "ParameterSlider.h"


ParameterSlider::ParameterSlider (AudioProcessorParameter& p, double minimum, double maximum, double interval)
: Slider (p.getName (256)), param (p)
{
    setRange (minimum, maximum, interval);
    startTimerHz (30);
    updateSliderPos();
}

ParameterSlider::~ParameterSlider() {}


void ParameterSlider::startedDragging()
{
    param.beginChangeGesture();
}

void ParameterSlider::valueChanged()
{
    const float sliderValue = (float) this->getValue();
    
    param.setValue (sliderValue);
}

void ParameterSlider::stoppedDragging()
{
    param.endChangeGesture();
}

double ParameterSlider::getValueFromText (const String& text)
{
    return param.getValueForText (text);
}

String ParameterSlider::getTextFromValue (double value)
{
    return param.getText ((float) value, 1024);
}

void ParameterSlider::updateSliderPos()
{
    const float newValue = param.getValue();
    
    if (newValue != (float) Slider::getValue())
        Slider::setValue (newValue);
}

void ParameterSlider::timerCallback()
{
    updateSliderPos();
}

