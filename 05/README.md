# Dice

A 7-segment display is an array of seven individual LEDs that are arranged in such a way that the numbers
from 0 to 9 can be rendered. E.g., considering the pinout diagram below, the digit "1" can be rendered by
turning on segments "b" and "c" and all other segments off. Each LED should have its
<a href="https://electronics.stackexchange.com/questions/22291/why-exactly-cant-a-single-resistor-be-used-for-many-parallel-leds">own resistor</a>
to avoid burnout. Connecting each of the seven LEDs to a different pin of the Arduino allows to render
different numbers. Sketch
<a href="https://github.com/apuder/iot-workshop/blob/master/05/DiceSimple/DiceSimple.ino">`DiceSimple`</a>
demonstrates a simple electronic dice. Pushing the button will cycle very quickly through the numbers
1 to 6. Releasing the button will stop cycling at a random number. Sketch
<a href="https://github.com/apuder/iot-workshop/blob/master/05/Dice/Dice.ino">`Dice`</a> is a more elaborate
version that uses some animations for visual effects.

<a href="https://www.sunfounder.com/learn/Super_Kit_V3_0_for_Raspberry_Pi/lesson-14-driving-7-segment-display-by-74hc595-super-kit-v3-0-for-raspberry-pi.html">
<img src="https://www.sunfounder.com/media/wysiwyg/picture1/2.jpg" width="30%"/>
</a>



<img src="Dice_bb.png" width="50%"/>

