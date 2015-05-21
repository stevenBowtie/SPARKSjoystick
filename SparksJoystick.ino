/*
X Min:173 Center:547 Max:897
Y Min:160 Center:511 Max:853
*/

float x, y, throttle;
byte left_motor=64, right_motor=64;

void setup() {
  Serial.begin(9600);

}

void loop() {
  x=(analogRead(0)-547.0)/362.5;
  y=(analogRead(1)-511.0)/347.5;
  throttle=(analogRead(2)-90.0)/795;
  left_motor=(64+(y * throttle * 64)-(x * throttle *64 ));
  right_motor=(64+(y * throttle * 64)+(x * throttle * 64));
  Serial.print("X:");
  Serial.print(x);
  Serial.print(" Y:");
  Serial.print(y);
  Serial.print(" T:");
  Serial.println(throttle);
  Serial.print(left_motor);
  Serial.print(", ");
  Serial.println(right_motor);
  delay(100);
}
