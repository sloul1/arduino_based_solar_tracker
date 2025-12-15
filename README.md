>[!CAUTION]  
>WIP as in Work In Progress
>This warning will be removed only after when this report is finished. 

# Arduino based dual axis solar tracker ☀️

This Arduino nano based project uses light depended resistors to control and turn two servo motors to the brightest light source.

## Parts

## LDRs and resistors

Four LDRs (ohm?) are installed with resistors...

## Servo motors

Project utilizes two [DMS-MG90 micro servos](https://www.dfrobot.com/product-1338.html). Scroll page down for the specifications. [Dimensions at GitHub](https://github.com/Arduinolibrary/DFRobot_DMS_MG90/blob/master/DMS-MG90%20Servo%20Dimension.pdf)

## LEDs

There are three LEDs to indicate solar tracker status.

 - 🟢 Green LED lights on when the system initialized and running.
 - 🔴 Red LED is blinking when the system is tracking for the best light source.
 - 🟢🟡 Both green and yellow LEDs are lit simultaneously when the light source tracking is optimal. 

## ISR Interrupt Service Routine reset

System can be resetted and initialized to start by pushing button for three seconds period.

## Color display (LCD)

System uses [Gravity: I2C 16x2 Arduino LCD with RGB Backlight Display](https://www.dfrobot.com/product-1609.html). Check the [Documentation at GitHub](https://github.com/DFRobot/DFRobot_RGBLCD1602).

Both `LDR raw values` and `LDR percentual values` are printed out (3 seconds at the time?) on the LCD screen.  

### Help?
(LCD shows system status and help every time system starts??)