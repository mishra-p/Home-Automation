int gate_sensor_out=2;
int gate_sensor_in=3;
int led1=4;
int room_ldr=A0;
int temp=A1;
int ldr_value=0;
int counter=0;
int fan1=5;
int fan2=6;
int a=7;
int b=8;
int c=9;
int z=0;
int mod1=11;
int mod2=12;
int clk=13;
int temp_value=0;
int c2;
void setup() {
  // put your setup code here, to run once:
pinMode(gate_sensor_out,INPUT);
pinMode(gate_sensor_in,INPUT);
pinMode(mod1,OUTPUT);
pinMode(mod2,OUTPUT);
pinMode(clk,OUTPUT);
pinMode(temp,INPUT);
pinMode(led1,OUTPUT);
pinMode(fan1,OUTPUT);
pinMode(fan2,OUTPUT);
pinMode(a,INPUT);
pinMode(b,INPUT);
pinMode(c,INPUT);
Serial.begin(9600);
}

void loop() {
 
  // put your main code here, to run repeatedly:
 if(digitalRead(gate_sensor_out))
 {
  in();
  cou1();
  delay(1500);  
 }
 else if(digitalRead(gate_sensor_in))
 {
  out();
  cou2();
  delay(1500);
 }
 else
 {
    counter_check();
 }
}
void counter_check()
  {
    if(counter>0)
    {
      ldr_value=analogRead(room_ldr);
      temp_value=analogRead(temp);
      if(z==0)
      {
        Serial.print("Intensity of light inside the room:-");
        Serial.println(ldr_value);
        Serial.print("Room temperature:-");
        Serial.println(temp_value);
        z++;
      }
      if(ldr_value<=500)
      {
        digitalWrite(led1,HIGH);
      }
      if(ldr_value>500)
      {
        digitalWrite(led1,LOW);
      }
      if(temp_value>=92)
      {
        digitalWrite(fan1,HIGH);
        digitalWrite(fan2,LOW);
      }
      if(temp_value<92)
      {
        digitalWrite(fan1,LOW);
        digitalWrite(fan2,LOW);
      }
    }
    else if(counter<=0)
    {
        digitalWrite(led1,LOW);
        digitalWrite(fan1,LOW);
        digitalWrite
        (fan2,LOW);
    }
  }
  /*entry function*/
  void in()
  {
    if(counter<7)
    {
      counter=counter+1;
      Serial.println(counter);
      z=0;
      counter_check();
    }
    if(counter>=7)
    {
      counter=0;
      Serial.println(counter);
      z=0;
      counter_check();
    }
  }
  /*exit function*/
  void out()
  {
    if(counter>0){
      counter=counter-1;
      Serial.println(counter);  
      z=0;
      counter_check(); 
      
    }
  }
  void cou1()
  {
    digitalWrite(mod1,HIGH);
    digitalWrite(mod2,LOW);
    digitalWrite(clk,HIGH);
    delay(50);
    digitalWrite(clk,LOW);
    delay(50);
    int a1=digitalRead(a);
    int b1=digitalRead(b);
    int c1=digitalRead(c);
    if(a1==0&&b1==0&&c1==0)
    {
      c2=0;
    }
    if(a1==0&&b1==0&&c1==0)
    {
      c2=1;
    }
    if(a1==0&&b1==0&&c1==1)
    {
      c2=2;
    }
    if(a1==0&&b1==0&&c1==1)
    {
      c2=3;
    }
    if(a1==0&&b1==1&&c1==0)
    {
      c2=4;
    }
    if(a1==0&&b1==1&&c1==0)
    {
      c2=5;
    }
    if(a1==0&&b1==1&&c1==1)
    {
      c2=6;
    }
    if(a1==0&&b1==1&&c1==1)
    {
      c2=7;
    }
  }
   void cou2()
  {
    digitalWrite(mod1,LOW);
    digitalWrite(mod2,HIGH);
    digitalWrite(clk,HIGH);
    delay(50);
    digitalWrite(clk,LOW);
    delay(50);
    int a1=digitalRead(a);
    int b1=digitalRead(b);
    int c1=digitalRead(c);
    if(a1==0&&b1==0&&c1==0)
    {
      c2=0;
    }
    if(a1==0&&b1==0&&c1==0)
    {
      c2=1;
    }
    if(a1==0&&b1==0&&c1==1)
    {
      c2=2;
    }
    if(a1==0&&b1==0&&c1==1)
    {
      c2=3;
    }
    if(a1==0&&b1==1&&c1==0)
    {
      c2=4;
    }
    if(a1==0&&b1==1&&c1==0)
    {
      c2=5;
    }
    if(a1==0&&b1==1&&c1==1)
    {
      c2=6;
    }
    if(a1==0&&b1==1&&c1==1)
    {
      c2=7;
    }
  }

