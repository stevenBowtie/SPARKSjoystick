/*
X Min:173 Center:547 Max:897
Y Min:160 Center:511 Max:853

X Min:343 Center:680 Max:930
Y Min:310 Center:647 Max:895
*/

float x, y, throttle;
byte left_motor=64, right_motor=64;

void setup() {
  Serial.begin(38400);
  digitalWrite(A0, 1); // Add pull-up to check if joystick attached.
  digitalWrite(A1, 1);
  digitalWrite(A2, 1);
}

void loop() {
  if(analogRead(0)>1000 || analogRead(1)>1000){  //Sanity check to make sure joystick is connected
    x=0;
    y=0;
  }
  else{
    x=(analogRead(0)-680.0)/293.5; // X centering and scaling
    y=(analogRead(1)-647)/292.5; // Y centering and scaling
  }
  throttle=(analogRead(2)-200.0)/680; // Throttle centering and scaling
  left_motor=(64+(y * throttle * 64)+(x * throttle * 25 )); //left motor mapping
  right_motor=(64+(y * throttle * 64)-(x * throttle * 25)); //right motor mapping
  left_motor=max(1, min(127, left_motor)); //Motor speed limits. If exceeded motor driver goes full throttle.
  right_motor=max(1, min(127, right_motor)); 
  Serial.write(left_motor); 
  Serial.write(-right_motor); //Motor controller expects 2 bytes, - pushes correct values
  Serial.flush();
  delay(100);
 
}

