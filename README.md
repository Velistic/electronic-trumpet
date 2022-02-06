# Arduino electronic-trumpet

![image](https://user-images.githubusercontent.com/75145721/152664611-9607d721-0d6e-44d9-86f3-2cb956981fa9.png)


# A. Introduction

Arduino electronic trumpet with air pressure sensor

Small project that combines both my scientific competencies and my harmonic passion for the musical arts.
Inspired by various "elctronic pianos" projects previously done with Arduino.
Three buttons mimic a trumpet's valve.  It integrates the heart and soul of playing the trumpet: blowing air through its tube.
You can blow inside a sensor to recreate a real trumpet’s range of pitches. Nevertheless, the blowing mechanism still needs some development in order to perfect the simulation of blowing inside a real trumpet.


# B. Trumpet Fingering Chart
  
![image](https://user-images.githubusercontent.com/75145721/152664726-30823954-ffc1-4bff-9d31-6c42750043f3.png)

 ## Trumpet

Trumpets are musical instruments. They have the highest pitch in the brass family. They are played by producing “buzzing” sounds that act as constant waves thus producing certain musical notes. The stronger the blow, the higher the amplitude of the wave will be, making the sound much louder. This wave is propelled inside their many valves. The three piston valves are able to modify the frequency of the sound waves by delaying the air, thus changing its period (see Sound and Speakers for the link between frequencies and musical notes).
![trumpet image](https://user-images.githubusercontent.com/75145721/152664018-3d764cb5-dd62-49bc-8b8f-072704ae3620.png)
<br>
(image src: Wikipedia Trumpet article)

<p width='50%'>
Trumpets are transposing instruments. The most common type is the B♭ trumpet, but A, C, D, E♭, E, low F, and G trumpets are also built. The trumpet that I produced is in C because it easily satisfied the initial condition: it must play a simple major C scale.

# C. Pressure sensor
  
  ![image](https://user-images.githubusercontent.com/75145721/152664541-d0a5103a-c0f4-4abd-93df-fbf1e10fd18b.png)

### MPXC201xDT1: 0 to 10kPa, Differential, High Volume Pressure 
  
 The electrical component that simulates the blowing range of a trumpet is a differential pressure sensor. It detects changes in pressure by comparing the pressure of the blown air to the atmospheric pressure. It translates the intensity of the blow into the voltage of an electrical current. 
  
 It is possible to measure the range of intensity of a normal person’s blow by using a serial monitor (see Results and Adjustments) A trumpet has a range of seven levels of pitches, as shown in the figure below. I have decided to limit my trumpet to five levels to decrease its difficulty. I removed the lowest and the highest playable notes. On the other hand, by doing so, I have decreased the total number of playable notes. Nevertheless, there are still plenty (26 are left.)
  
  ![image](https://user-images.githubusercontent.com/75145721/152664471-7afbec25-d9df-4811-ab76-d54faa0a4a3b.png)
<br>
  Electronic trumpet’s Levels of Pitches
 <br>
  
 As it is shown in the above figure, there are seven notes that can be played with the same combination of valves on a trumpet by only changing the intensity of the air that flows inside of it(it is much more difficult than it sounds).  I have marked in red the notes that I have removed on my trumpet. 
  

First of all, the trumpet has its own fingering and uses combination of pressed valves and air intensity to play musical notes. In order to recreate these combinations, I needed to separate the intensity of my own blow into the correct levels.

![image](https://user-images.githubusercontent.com/75145721/152664576-3e56f967-8061-4f95-a6ef-92b389404746.png)

Arduino’s serial monitor had the ability to translate the intensity of my blow into a certain voltage. Since it fluctuates a lot, I then proceeded to limit the intensity into five groups to allow the player to have a bigger range. The stronger the air flow, the higher the level. It took a lot of testing in order to find the correct borders of intensity to create a similar feeling as blowing into the real instrument. Nevertheless, my instrument turned out to be relatively easier to play. 

Nonetheless, even with the sensor, the blowing doesn’t feel quite the same as in a real trumpet. The component could not detect vibrations, but only changes in the intensity. On a real trumpet, blowing harder would produce a louder sound, but still play the same note. To change notes, in other words to change levels, we need to vary the pressure of the “buzzing” using our diaphragm. On my trumpet, I could only control the intensity of the air flow. Thus, my object is not a perfect electrical replica of the original instrument. However, it is still a decent simulation. The fingering on my object is exactly the same as on a real trumpet. It is therefore a nice replacement for those that do not have the money to buy the real thing.  
  

# D.  Visual Indicators

![image](https://user-images.githubusercontent.com/75145721/152664583-d19100d0-e340-4f6a-a709-1b0fb057e167.png)


It was also difficult to reach a particular level when blowing a first note, especially the higher ones. To counter this problem, I installed visual indicators. The five red LEDs represent the five levels (in order form right to left.) There are also two yellow LEDs that signal when we are too close to another level, in order to adjust the air flow. I also had to adjust the code accordingly.
  
 The tail is just for esthetics. It makes the object look more like a real trumpet. It does not hold any specific function.
  
  
 # E. Material 
  
 <ul>
   <li> Arduino Uno </li>
<li>	Atmega328P-PU Microcontroller </li>
<li>	LM386 Low Voltage Power Amplifier </li>
<li>	3 Push-button Switches </li>
<li>	16 MHz Cristal </li>
<li> 2 22 pF Capacitors </li>
<li> 	1 100 nF Capacitor  </li>
<li>	1 47 F Capacitor </li>
<li>	1 10 F Capacitor </li>
<li>	Soldering Tools </li>
  <li> 1 250 F Capacitor  </li>
<li>	1 0.05 F Capacitor
<li>	1 10 kΩ Variable Resistor </li>
<li>	Speaker </li>
<li>	8 100 kΩ Resistors </li>
<li>	8 Light-emitting diodes (LEDs) </li>
<li>1 ON/OFF Switch </li>
<li>9V Battery </li>
<li>MPXC201xDT1: 0 to 10kPa, Differential, High Volume Pressure  </li>
 </ul>
 
 ![image](https://user-images.githubusercontent.com/75145721/152664550-b628de0f-83d6-45ef-b06e-48e6e117d4bf.png)

![image](https://user-images.githubusercontent.com/75145721/152664556-d4a18e71-1846-4069-95f2-b6bc8cdd9885.png)
 
  
  
  # F. Schematics
  
  ![image](https://user-images.githubusercontent.com/75145721/152664633-daed63d0-067b-4fd3-94c1-0bd1214a8b07.png)
  
  ![image](https://user-images.githubusercontent.com/75145721/152664636-265afeb4-b945-4f20-8355-6db0fc4c6dfe.png)


  

  
