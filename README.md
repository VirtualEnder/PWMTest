# PWMTest
PWM Generation code for ESC Testing


This is just a quick and dirty PWM Generation code using the Arduino 16Bit timer.  
I could have spent a bit more time on it and removed the delayMicroseconds from the timer script, but it is working fine as is, so I haven't yet.

TODO
I need to log the PWM output at some point, and find a way of syncing it with the other data collected from the ESC.  Eventually it may be worth re-writing the whole thing to do all the logging through this one program. Using a 100A current sensor and an RPM sensor it should be possible.   This may end up expanding significantly over time.
