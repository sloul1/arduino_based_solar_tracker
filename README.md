>[!CAUTION]  
>WIP as in Work In Progress
>This warning will be removed only after when this report is finished. 

# Arduino based dual axis solar tracker ☀️

This Arduino nano based project uses light depended resistors to control and turn two servomotors to brightest light source.

## LDRs and resistors

Four LDRs (ohm?) are installed with resistors...

## LEDs

There are three LEDs to indicate solar tracker status.

 - 🟢 Green LED lights on when the system initialized and running.
 - 🔴 Red LED is blinking when the system is tracking for the best light source.
 - 🟢🟡 Both green and yellow LEDs are lit simultaneously when the light source tracking is optimal. 

## ISR Interrupt Service Routine reset

System can be resetted and initialized to start by pushing button for three seconds period.

## Color display (LCD)

Both `LDR raw values` and `LDR percentual values` are printed out (3 seconds at the time?) on the LCD screen.  

### Help?
(LCD shows system status and help every time system starts??)
