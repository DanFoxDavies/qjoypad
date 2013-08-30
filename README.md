Dev notes for qjoypad 4.2alpha

Hello!

I wanted to use my PS2 joypad with programs that require multiple buttons to be pushed simultaneously to do the majority of useful things, eg. move the camera, zoom, edit stuff. There were more keyboard shortcuts than buttons on my controller, so I decided I wanted to map multiple keypresses to each controller button or axis. Unfortunately, none of the existing Linux joypad programs had that function.

So, I asked a friend to help. They agreed to help, but warned that the solution would be incredibly hacky and they were not prepared to put their name to it, and so remain anonymous to the wider world beyond our hackerspace. Hence the 'alpha' marker.

So, with edits to axis.cpp and .h, event.cpp and .h, error.h, and button.cpp and .h, several hours of frustrated late night faffing and a redefinition of the config file syntax to some degree, we got it to work, at least when entering keyboard symbols and letters into a notepad. The jury is still out as to whether it will work with the intended game, but then it's a game, so there may be other issues going on there.

Not wanting the hard work to go to waste, we decided to contribute it to Github for future development.

Please note: I cannot program. This code was a set of edits written by my friend to a much larger set of code last updated years ago. If you want it improved further, get hold of a programmer with spare time and C++ knowledge.

When you are configuring a controller and want MULTIPLE key presses, DO NOT USE THE GUI TO CREATE THE FINAL LAYOUT FILE with this current iteration of the code. It will ignore all multiple presses and overwrite them with single. We didn't edit the GUI, only the backend this time round.

You can use the GUI to work out what numbers qjoypad assigns the letters on your keyboard, however. Then you can map those numbers to the buttons on your joypad by manually editing the .lyt files in the layout folder. In the .lyt syntax, you want each button or axis to have a line. 

The following is an example file, the first joypad section filled with comments which must all be removed except the first one for the file to work and the second joypad section left without them to show how the syntax is normally presented without the comments. Please note the numbers in this file do not work as an actual layout, they are mainly just random to make an example.

------------------------------------------------
```
# QJoyPad 4.1 Layout File

# Do not save to this file from the GUI if # you are using more than one key command # # per button press.

Joystick 1 {
# Left Analog -Left/+Right
	Axis 1: +key 40, -key 38
# Left Analog -Up/+Down
	Axis 2: +key 39, -key 25
# Right Analog -Left/+Right
	Axis 3: gradient, maxSpeed 25, mouse+h
# Right Analog -Up/+Down
	Axis 4: gradient, maxSpeed 25, mouse+v
#Select
	Button 1: key 37 31
#L3 (push left analog stick in)
	Button 2: key 64
#R3 (push right analog stick in)
	Button 3: key 37 64 50 33
#Start
	Button 4: key 37 58
#D-Pad:
#Up
	Button 5: key 37 64 50 111
#Right
	Button 6: key 37 64 50 114
#Down
	Button 7: key 37 64 50 116
#Left
	Button 8: key 37 64 50 113
#L2
	Button 9: key 117
#R2
	Button 10: key 37
#L1
	Button 11: key 112
#R1
	Button 12: key 50
#Triangle
	Button 13: key 37 50 58
#Circle
	Button 14: key 37 64 39
#X (a.k.a. Cross)
	Button 15: mouse 1
#Square
	Button 16: mouse 3
#Analog (on/off button)
	Button 17: key 64
#?
	Button 18: key 32
#?
	Button 19: key 33
}

Joystick 2 {
	Axis 1: +key 64 31, -key 64 35
	Axis 2: +key 64 33, -key 64 34
	Axis 3: +key 57, -key 56
	Axis 4: +key 59, -key 58
	Button 1: key 37 31
	Button 2: key 67
	Button 3: key 68
	Button 4: key 37 58 34 111
	Button 5: key 70 22 30
	Button 6: key 71
	Button 7: key 72
	Button 8: key 73
	Button 9: key 74
	Button 10: key 75
	Button 11: key 76
	Button 12: key 96
	Button 13: key 107
	Button 14: key 78
	Button 15: key 121
	Button 16: key 122
	Button 17: key 49
	Button 18: key 10
	Button 19: key 11
}
```
------------------------------------------------

Please note that if it does not work when put together similar to Joystick 2 above, try it like this with 999s to fill the 'gaps' instead:

------------------------------------------------
```
# QJoyPad 4.1 Layout File

Joystick 2 {
	Axis 1: +key 114 999 999 999, -key 113 999 999 999
	Axis 2: +key 116 999 999 999, -key 111 999 999 999
	Axis 3: gradient, maxSpeed 25, mouse+h
	Axis 4: gradient, maxSpeed 25, mouse+v
	Button 1: key 37 31 999 999
	Button 2: key 64 999 999 999
	Button 3: key 37 64 50 33
	Button 4: key 37 58 999 999
	Button 5: key 37 64 50 25
	Button 6: key 37 64 50 40
	Button 7: key 37 64 50 39
	Button 8: key 37 64 50 38
	Button 9: key 117 999 999 999
	Button 10: key 37 999 999 999
	Button 11: key 112 999 999 999
	Button 12: key 50 999 999 999
	Button 13: key 37 50 58 999
	Button 14: key 37 64 39 999
	Button 15: mouse 1
	Button 16: mouse 3
	Button 17: key 64 999 999 999
	Button 18: key 32
	Button 19: key 33
}
```
-------------------------------------------------

Note that 999s are not required on the mouse ones (we didn't change those) and Buttons 18 and 19 don't exist (at least not on the outside) on my Sony PS2 controller.

This whole edit is a one-off provided as-is in the hope it will catalyse continued qjoypad development from other people.

Thanks for reading and I hope it works for you or at least provides some sort of useful progress on adding new features.
