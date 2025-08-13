#define ml 4
#define m2 5
#define cutter 7
#define cutter1 6
#define relay1 12
#define relay2 11
#define relay3 10
#define relay4 9
#define relay5 2
#define buz 13

void Stop(void)
{

digitalWrite(relay1, HIGH);
digitalWrite(relay2, HIGH);
digitalWrite(relay3, HIGH);
digitalWrite(relay4,HIGH);
}

void Backward(void)
{
digitalWrite(relay1, HIGH); 
digitalWrite(relay2, LOW); 
digitalWrite(relay3, HIGH); 
digitalWrite(relay4, LOW);
 }

void Forward(void) 
{

digitalWrite(relay1, LOW);
digitalWrite(relay2, HIGH);
digitalWrite(relay3, LOW);
digitalWrite(relay4, HIGH);
}

void Left(void)
{

digitalWrite(relay1, HIGH);
digitalWrite(relay2, LOW);
digitalWrite(relay3, LOW);
digitalWrite(relay4, HIGH);
}
void right(void)
{

digitalWrite(relay1, LOW);
digitalWrite(relay2, HIGH);
digitalWrite(relay3, HIGH);
digitalWrite(relay4, LOW);
}

void Up(void)
{
digitalWrite(4, HIGH);
digitalWrite(m2, LOW);

delay(500);
digitalWrite(4, LOW);
digitalWrite(m2, LOW);
}

void Down(void)
{
digitalWrite(4, LOW);
digitalWrite(m2, HIGH);
delay(500);
digitalWrite(4, LOW);
digitalWrite(m2, LOW);
}

void Cutter_on(void)
{
digitalWrite(cutter, HIGH);
digitalWrite(6, LOW);
}

void Cutter_off (void)

{
digitalWrite(cutter, LOW);
digitalWrite(6, LOW);
}

void Water_on(void)
{
digitalWrite(relay5, LOW);
}

void Water_off(void)
{
digitalWrite(relay5, HIGH);
}

void setup()

{
Serial.begin(9600);
pinMode(4, OUTPUT); 
pinMode(m2, OUTPUT); 
pinMode(cutter, OUTPUT); 
pinMode(6, OUTPUT);
pinMode(relay1, OUTPUT); 
pinMode(relay2, OUTPUT); 
pinMode(relay3, OUTPUT); 
pinMode(relay4, OUTPUT);
pinMode(relay5, OUTPUT);
pinMode(buz, OUTPUT);
Stop();

Serial.println("WELCOME");

Serial.println("Front→ F; Back→B; Left →L; Right R; Stop→S;");
Serial.println("Pump on W; Pump off--> X; Cutter On -> C; Cutter Off--> E; Plougher Up--> U; Plougher Down--> D; ");

delay(1000);

digitalWrite(buz,HIGH);
digitalWrite(buz,LOW);

digitalWrite(relay1,HIGH);
digitalWrite(relay2,HIGH);
digitalWrite(relay3,HIGH);
digitalWrite(relay5,HIGH);
digitalWrite(relay4,HIGH);

delay(1000);

}

void loop(){

delay(500);

if (Serial.available() > 0)

{
char Data = Serial.read();
Serial.println(Data);
delay(100);

if (Data == 'F')
{
Serial.println("Moving Forward");
Forward();
}

else if (Data == 'B')
{
Serial.println("Moving Backward");

Backward();

}

else if (Data == 'L')

{

Serial.println("Moving Left");

Left();

}

else if (Data == 'R')

{

Serial.println("Moving Right");
right();

}

else if(Data == 'S')
{

Serial.println("Stoped");

Stop();

}

else if (Data == 'W')
{
Serial.println("Pump ON");
Water_on();
}

else if (Data == 'X')
{
Serial.println("Pump OFF"); Water_off();
Water_off();
}
else if (Data =='C')
{ 
  Serial.println("Cutter ON"); 
  Cutter_on();
}

else if (Data == 'E')

{

Serial.println("Cutter OFF"); 
Cutter_off();

}

else if (Data == 'U')

{

Serial.println("Up");

Up();

}

else if (Data == 'D')

{
Serial.println("Down");

Down();

}

}

}