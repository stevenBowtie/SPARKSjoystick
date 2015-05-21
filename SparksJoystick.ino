/*
X Min:173 Center:547 Max:897
Y Min:160 Center:511 Max:853
*/

float x, y, throttle;
byte left_motor=64, right_motor=64;

void setup() {
  Serial.begin(38400);

}

void loop() {
  x=(analogRead(0)-547.0)/362.5;
  y=(analogRead(1)-511.0)/347.5;
  throttle=(analogRead(2)-90.0)/795;
  left_motor=(64+(y * throttle * 64)+(x * throttle * 25 ));
  right_motor=(64+(y * throttle * 64)-(x * throttle * 25));
  left_motor=max(1, min(127, left_motor));
  right_motor=max(1, min(127, right_motor));
  Serial.write(left_motor);
  Serial.write(-right_motor);
  Serial.flush();
  delay(100);
}

