>[!CAUTION]  
>WIP as in Work In Progress
>This warning will be removed only after when this report is finished.  

<p align="center">
<img src="media/working_chaos.jpg" alt="Check product name and model name from settings about menu" style="width:100%; height:auto;">  
</p>

<p align="center">
More chaos, more creativity? 
</p>

# Arduino based dual axis solar tracker ☀️

This Arduino nano based project uses light dependent resistors to control and turn two servo motors to the brightest light source.

## Tools
- Laptop for programming
- Soldering iron
- Phillips head screwdrivers
- Hot glue gun
- Scissors

## Parts and materials

- Cardboard

## Arduino nano
 - Arduino nano
 - USB-A (male) to micro-USB (male) cable for programming
 - Arduino IDE software for programming

## LDRs and resistors

4 x **L**ight **D**ependent **R**esistors (ohm?) are installed with resistor for each...

## Servo motors

Project utilizes two `DMS-MG90 micro servos`. Scroll [specifiation page](https://www.dfrobot.com/product-1338.html) down for the details. [Motor dimensions](https://github.com/Arduinolibrary/DFRobot_DMS_MG90/blob/master/DMS-MG90%20Servo%20Dimension.pdf) at GitHub.

## LEDs

There are three LEDs (red, yellow and green) to indicate solar tracker status. Each LED has resistor that limits maximum current to 15mA. Current limiting resistors are sized according to [specification](https://www.pcboard.ca/5mm-frosted-lens-led/).

As we can see from the datasheet specification below red and yellow LED has lower *`Typical Voltage`* and *`Forward Voltage`*.


 
| Led colour:              | RF0991-08 - Red    | YF0991-06 - Yellow | GF0991-07 - Green  |
|--------------------------|--------------------|--------------------|--------------------|
| Color Frequency:         | 628nm              | 590nm              | 525nm              |
| Luminous Intensity:      | 5,000mcd           | 3,200mcd           | 23,200mcd          |
| Viewing Angle:           | Diffused Lens      | Diffused Lens      | Diffused Lens      |
| Forward Voltage:         | 1.9v - 2.1v        | 1.9v - 2.1v        | 2.7v - 3.0v        |
| Typical Voltage:         | 2.0v               | 2.0v               | 2.8v               |
| Typical Forward Current: | 20mA               | 20mA               | 20mA               |
| Style:                   | Round 5mm - T1 3/4 | Round 5mm - T1 3/4 | Round 5mm - T1 3/4 |
| Lens:                    | Frosted            | Frosted            | Frosted            |


>[!NOTE]  
> Following formula is used for sizing currency limiting resistor for single LED in series.  


$R=\frac{V-V_{f}}{I_{F}}$  

When selecting current limiting resistors, variations in LED specifications are taken into account as follows.

Resistor sizing for red and yellow LEDs: 

$R=\frac{{5V-2V}}{0.015A}=200\Omega$   

-> 220 𝛺 resistor will be used.

...and resistor for green LED:  

​
$R=\frac{{5V-2.8V}}{0.015A}≈146,6\Omega$  

-> 150 𝛺 resistor will be used.      


 - 🟢 Green LED lights on when the system initialized and running.
 - 🔴 Red LED is blinking when the system is tracking for the best light source.
 - 🟢🟡 Both green and yellow LEDs are lit simultaneously when the light source tracking is optimal. 

## Button for ISR
- Microswitch push button
- Resistor and a capacitor for debouncing??? 

## ISR Interrupt Service Routine reset

System can be resetted and initialized to start by pushing button for three seconds period.

## Color display (LCD)

System uses [Gravity: I2C 16x2 Arduino LCD with RGB Backlight Display](https://www.dfrobot.com/product-1609.html). Check the [Documentation at GitHub](https://github.com/DFRobot/DFRobot_RGBLCD1602).

Both `LDR raw values` and `LDR percentual values` are printed out (3 seconds at the time?) on the LCD screen.  

### Help?
(LCD shows system status and help every time system starts??)

## Connections

## Code

## Angle limits considerations in Finland for the servos

Angle limits are considered by the installation location of the solar tracker. The latitude of Finland ranges from approximately 60°N in the south to over 70°N in the north. This high latitude means that the sun is low on the horizon for much of the year, particularly during winter months comparing to summer. ```In Finland there isn't too much solar energy harvested In the winter time``` Check the [Fingrid statistics](https://www.fingrid.fi/en/electricity-market-information/solar-power) for the annual solar power generation in Finland.     

Latitude Range: 
 
    Southern Finland (e.g., Helsinki at about 60°N): The sun's maximum elevation angle can reach up to approximately 52.5 degrees in summer and as low as around 7 degrees in winter.
    Northern Finland (e.g., Rovaniemi at about 66.5°N): The sun's maximum elevation angle is much lower, reaching around 30 degrees in summer and barely rising above the horizon in winter.

Vertical Angle Limits:

    Summer: In southern parts of Finland, servomotors should be able to adjust between roughly 7 degrees (during sunrise) to about 52-53 degrees (at solar noon during the summer solstice).
    Winter: The vertical range is much smaller due to the low sun angle. In southern Finland, this might be from just above the horizon (~7 degrees) to around 15-20 degrees.