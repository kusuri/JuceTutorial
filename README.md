# JuceTutorial
This repository contains some tutorials of JUCE audio applications and plug-ins.
All projects use [JUCE v4.1.0](https://github.com/julianstorer/JUCE/releases/tag/4.1.0).

Please read ``Development environment specifications`` to clone this repo into the correct directory.

--------------
## DemoPlugin

This is a JUCE demo audio plug-in built for VST(OSX, Win64) & AU(OSX).

It supports only mono and stereo channels.

It is consisted of a slider that modifies the total gain and a button that mutes the output.

### Dependencies
VST SDK version 3.6.5


--------------
## StandalonePluginDemo

This is a standalone application containing the DemoPlugin filter.

[Here](https://github.com/kusuri/JuceTutorial/wiki/How-to-convert-an-audio-plug-in-to-a-standalone-application) are the steps on how to create a standalone plug-in from scratch.
