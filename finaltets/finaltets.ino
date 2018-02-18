int gate_sensor_out=2;
int gate_sensor_in=3;
int led1=4;
int led2=5;
int led3=6;
int led4=7;
int led5=8;
int fan=9;
int room_ldr=A0;
int temp=A1;
int ldr_value=0;
int counter=0;

int temp_value=0;
void setup() {
  // put your setup code here, to run once:
pinMode(gate_sensor_out,INPUT);
pinMode(gate_sensor_in,INPUT);
pinMode(fan,OUTPUT);
pinMode(temp,INPUT);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);
pinMode(led5,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 if(digitalRead(gate_sensor_out))
 {
  in();
  delay(1500);  
 }
 else if(digitalRead(gate_sensor_in))
 {
  out();
  delay(1500);
 }
 else
 {
    counter_check();
 }
}
void counter_check()
  {
    ldr_value=analogRead(room_ldr);
      temp_value=analogRead(temp);
    if(counter>0)
    {
      if(ldr_value<=500)
      {
        digitalWrite(led1,HIGH);
        digitalWrite(led2,HIGH);
        digitalWrite(led3,HIGH);
        digitalWrite(led4,HIGH);
        digitalWrite(led5,HIGH);
        if(temp_value>=50)
        {
          digitalWrite(fan,HIGH);
          Serial.println("fan is ON");
        }
        else
        {
          digitalWrite(fan,LOW);
          Serial.println("fan is OFF");
        }
      }
      if(ldr_value>500)
      {
        digitalWrite(led1,LOW);
        digitalWrite(led2,LOW);
        digitalWrite(led3,LOW);
        digitalWrite(led4,LOW);
        digitalWrite(led5,LOW);
         if(temp_value>=50)
        {
          digitalWrite(fan,HIGH);
           Serial.println("fan is ON");
        }
        else
        {
          digitalWrite(fan,LOW);
           Serial.println("fan is OFF");
        }
      }
    }
    else if(counter<=0)
    {
        digitalWrite(led1,LOW);
        digitalWrite(led2,LOW);
        digitalWrite(led3,LOW);
        digitalWrite(led4,LOW);
        digitalWrite(led5,LOW);
        digitalWrite(fan,LOW);
         Serial.println("fan is OFF");
    }
  }
  /*entry function*/
  void in()
  {
    counter=counter+1;
    Serial.println(counter);
    counter_check();
  }
  /*exit function*/
  void out()
  {
    counter=counter-1;
    Serial.println(counter);  
    counter_check(); 
  }
