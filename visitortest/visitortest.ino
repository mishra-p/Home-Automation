int s=3;
int counter=0;
void setup() {
  // put your setup code here, to run once:
pinMode(s,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(s))
{
  in();
  delay(2000);
}
}
void in()
{
  counter++;
  Serial.print("Visitors:-");
  Serial.println(counter);
}

