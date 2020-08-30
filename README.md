# Wecker
![Wecker status](https://github.com/sbehren/wecker/workflows/Wecker/badge.svg)

## About
An embedded C++ embedded Arduino project for building a light alarm clock. The German word *Wecker* means alarm clock.

## Status: Work in progress
* Not done for Arduino. It compiles for and runs on Arduino but not all embedded components are fully developed yet.
* Done for x64: The mockups for PC-based dev and debugging are done.

## High-level code overview
* I try to avoid embedded debugging. Thus, I chose an architecture that favours development on the PC in order to keep embedded debugging minimal.
* I use polymorphism to support the two different environments: Arduino and PC.
* Every embedded component (suffix _arduino) has a mockup for the PC (suffix _pc).
* The wecker's state is a finite state machine. I use the Gang-of-Four-pattern *Objects for States* for the state of the wecker.
* I want the embedded functions and the mockups to reside in the same folder. Since the official Arduino compiler attempts to compile every source file it finds, we need to use macros to hide some code blocks from it.

## Debugging
## Clock mockup
The file clock_mockup.txt contains hours in the first and minutes in the second line.
