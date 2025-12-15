// Define the pins connected to the LDRs
/*

LDR quadrants visualization
  -----------------
  |       |       |
  |  A1   |  A2   |
  |       |       |
  -----------------
  |       |       |
  |  A0   |  A3   |
  |       |       |
  -----------------

*/
const int ldrPin00 = A0; // Lower left LDR
const int ldrPin01 = A1; // Higher left LDR
const int ldrPin02 = A2; // Higher right LDR
const int ldrPin03 = A3; // Lower right LDR

void setup() {
  // Begin serial communication at a baud rate of 9600
  Serial.begin(9600);
  
  // Initialize the LDR pins as an inputs
  pinMode(ldrPin00, INPUT);
  pinMode(ldrPin01, INPUT);
  pinMode(ldrPin02, INPUT);
  pinMode(ldrPin03, INPUT); 
   
}

void loop() {
  // Read the analog value from the LDR
  int ldr00Value = analogRead(ldrPin00);
  int ldr01Value = analogRead(ldrPin01);
  int ldr02Value = analogRead(ldrPin02);
  int ldr03Value = analogRead(ldrPin03);
  // Print the value to the Serial Monitor
  //Serial.print("LDR Value: ");
  //Serial.println(ldrValue);

  // Optional: Map the value to a more understandable range (e.g., 0-100)
  int lightLevel00 = map(ldr00Value, 0, 1023, 0, 100);
  int lightLevel01 = map(ldr01Value, 0, 1023, 0, 100);
  int lightLevel02 = map(ldr02Value, 0, 1023, 0, 100);
  int lightLevel03 = map(ldr03Value, 0, 1023, 0, 100);
  

  // Print the mapped light level
  
  if(Serial.available()) 
    Serial.println("Start: ");
    // Serial.println("Light Level: "+ String(lightLevel00)+ " %");
    // Serial.println("LDR-01 Value: "+ String(ldr01Value)+ " = Light Level: "+ String(lightLevel01)+ " %");
    // Serial.println("LDR-02 Value: "+ String(ldr02Value)+ " = Light Level: "+ String(lightLevel02)+ " %");
    // Serial.println("LDR-03 Value: "+ String(ldr03Value)+ " = Light Level: "+ String(lightLevel03)+ " %");
    // Serial.println("");

    Serial.println("LDR00: "+ String(lightLevel00)+ " %");
    Serial.println("LDR01: "+ String(lightLevel01)+ " %");
    Serial.println("LDR02: "+ String(lightLevel02)+ " %");
    Serial.println("LDR03: "+ String(lightLevel03)+ " %");
    Serial.println("");


  // Delay for stability
  delay(1500);
  
}