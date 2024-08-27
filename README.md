Aiming to make some sort of a speedometer for my bike, ideally for indoor use w/ a trainer. I'd like to have an idea of how fast I'm going and how far I go in one session. 

Code and circuit based on : https://maker.pro/arduino/tutorial/how-to-use-a-hall-effect-sensor-with-arduino
https://maker.pro/arduino/tutorial/how-to-use-a-hall-effect-sensor-with-arduino


using PlatformIO and an arduino Uno for now.

Oh and the specific hall sensor is: https://canada.newark.com/honeywell/ss441r/hall-effect-sensor-uni-polar-to92/dp/50R8558



[x] ok so something's up w/ the actual detection on the sensor?
[x] sensor seems perhaps not very sensitive (is this cause I only have SHIT magnets)
  [x] https://www.farnell.com/datasheets/3953210.pdf based on data sheet I have 441Rs which are listed as high sensitivity
  [] better magnet needed - ordered
[] is code slow or is sensitivity low


information I'd like to be able to get out of this
- during a bike
  [] global average speed
    - this can be calculated via averaging the local averages 
  [] local average speed (over a period of time? or over a number of rotations)
- after
  [x] total distance covered
    - this is likely just rolling sum 

[] I'd like to dump those into a file that I can grab after at a minimum
[] ideally we'd be able to upload those to an accessible location after the bike instead

[] all of these imply that there's gotta be a way to start / stop tracking
[] do we need a total time biked? I'd like one if running a consistent timer isn't shit on the controller
