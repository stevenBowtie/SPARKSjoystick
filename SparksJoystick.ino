float x, y, throttle;
byte left_motor=64, right_motor=64;

void setup() {
  Serial.begin(9600);

}

void loop() {
  x=(analogRead(0)-172.0)/725;
  y=(analogRead(1)-160.0)/695;
  throttle=(analogRead(2)-90.0)/795;
  left_motor=(y * throttle * 128);
  right_motor=(y * throttle * 128);
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
