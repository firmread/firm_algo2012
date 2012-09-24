# firm_algo2012
=============
Firm Read Tothong's Repository 

for [Algorithmic Animation](http://www.newschool.edu/Parsons/faculty.aspx?id=67509) class Fall 2012 

MFA Design and Technology, Parsons The New School For Design



Course conducted by [Zach Lieberman](http://www.newschool.edu/Parsons/faculty.aspx?id=48257)

This class will look at the fundamentals of animation and animated form through the lens of computation. Artists have always used different technology to animate - from early zoetropes to hand drawn etched film - and with programming, there is a new branch of a long tradition forming. We will focus on techniques for writing code to move objects in a compelling and life-like manner. For folks who are newer to code, this class will work as a gentle but serious introduction to the medium, for experts this will present new approaches and strategies for expression. In addition to looking at and working through code, we will be studying several pioneers of abstract animation, Norman McLaren, John Whitney, Oskar Fischinger, as well as modern day practitioners like Toshio Iwai and Masahiko Sato. Technically, the course will be taught using a series of code examples, tools and problems coded in open frameworks, a cross platform c++ toolkit for creative hacking. This is an advanced programming class, students should be very comfortable with reading and writing code. 



### Links

[GitHub](https://github.com/ofZach/algo2012)

[Blog](http://scriptogr.am/algo2012)

### Git sidenotes

to get a classroom repo working

a) clone the algo2012_students repo

b) run this command: 
   git pull && git submodule init && git submodule update && git submodule status

c) run this command: 
   git submodule foreach git checkout master

d) sync! 
   git submodule foreach git pull
 
 
 

## Week 1 assignment
=============

###1 ] [Flipbook animation](http://youtu.be/XRVpBauINiY)
make a flip book.  Please use a “thicker” type sketchbook.  I recommend the square sketchbooks from NY Central Art Supply.

###2 ] [Motion Tracking - 14th Street Station](http://youtu.be/pUa7wKBopLM) and [Pratt Brooklyn Campus](http://youtu.be/JKhYQE8U_5k)
make three recordings (using a handheld camera that’s sationary) of three different scenes which have interesting motion.  Pick one point to watch during the video, and sketch out it’s motion path.  Try to find both rhythmic (repetitive) and organic motions.



###3 ] code:

###a-c is included in [w1-1_linearInterpolate_speed_position](https://github.com/firmread/firm_algo2012/tree/master/w1-1_linearInterpolate_speed_position)

####a) fastest non moving speed

find the fastest speed for the square to move across the screen and have the motion be imperceptible. Time how long it takes for the square to move across the screen and measure the physical (not pixel) distance. What is this speed in inches/second ? for kicks, What is it in in mph?

####b) fastest still perceptible speed

find the fastest speed for the square to move across the screen and have the motion be still perceived as continuous (not discrete jumps). Time how long it takes for the square to move across the screen and measure the physical (not pixel) distance. What is this speed in inches/second ? What is this rate in mph?

####c) click to change pta and ptb

make an application where whenever you click, you change either the ptA position or the ptB position to the mouse position, alternating every time you click.

###d-f is included in [w1-2_multipleXeno](https://github.com/firmread/firm_algo2012/tree/master/w1-2_multipleXeno)

####d) shaper controlls something else besides position

Make the shape code control another property of the object, such as its size or color.  Make the nicest composition that you can.  Try to make it elegant and organic.

(for the xeno code)

####e) multiple xenos

make a series of xeno objects which follow the mouse, each at different rates. give them slightly different colors so that you can perceive them as independent objects.   you will have to modify the rectangle object so that they can have unique colors.

+

bonus homeworks

####f) multiple xenos trail

If you are really feeling like showing off, make an array of xeno objects where the first element follows the mouse, the second element follows the first, the third follows the second, etc.

####g) shapers via penner

in class, we used powf to shape a linear signal.  there are more advanced ways to do this (for easing and out, and for snap to, etc).  Some of these have been collected by robert penner as “easing equations”.  some folks have ported this from AS to c++, you can find them here & here  (I'll add these links to the blog, but google cppPennerEasing and ofxEasingFunc).  Also google "golan shaper function" he's agressive catalogued alot of these. 

try to hook them up and make a compelling composition with linear and nonlinear animating elements.


##Week 2 assignment
=============
###animation experiment
Based on the work of Robin Rhode, make an animation with still images. If you can, cross fade between them. Can you tell a story with just a few frames? Think especially of using people and or mixing scales. Don’t doctor the images, and keep the camera stationary.

more robin rhode info: here here

###code homework
####a) make a composition using the animation techniques that is a tribute to john whitney.
See for example:

profile, info, videos, catalog (made in 1961! non-digital!)

####b) visuals + music
Since we talked briefly in class about this idea of a relationship between sound and visual synthesis (and harmony) find a short piece of music (can be any duration as long as there are multiple notes – a short snippet, or a long song) and make a composition that is a visual equivalent of that sound. Think about how the make a visual equivalent using the techniques we talked about this week. Post both the sound and the resulting animation. Try to bring out some essential truth of the audio through the visualization.

####c) natual phenomenon
try to use sin and cos to emulate a natural phenomenon (ie, something you see in the natural world). be sure to provide some documentation (video / picture / text) of what this phenomenon is.

####d) xeno atan creature
extend the xeno / atan2 code, making a creature which follows the mouse. think of how you could use sinusoidal animation techniques to give the object some “life” – breathing, blinking, etc.

(advanced homework)

####e) synthesis
since we talked about amplitude modulation in relationship to sin/cos animation, see if you can implement visual equivalents of other synthesis techniques, such as FM synthesis (modulating the carrier frequency) or additive synthesis. Make an interesting composition with what you’ve implemented.

finally, remember: every homework assignment is an opportunity for genius.
