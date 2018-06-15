//int enabler1=8;
//const int pin1=28;
int starttime;
int endtime;
const int enabler = 6;
const int pin1 = 38;
const int pin2 = 39;
const int prox1 = 21;
const int prox2 =20;
int x = 0;
int y = 0;
const int enabler2=13; // 1 2
const int pin2_1=46;
const int pin2_2=47;

//const int enabler3=; // 1 3
//const int pin3=32;

const int enabler4=12;  // 2 1
const int pin4_1=48;
const int pin4_2=49;

const int enabler5=8;  // 2 2`
const int pin5=27;

const int enabler6=9;  // 2 3
const int pin6=26;

const int enabler7=11;  // 3 1
const int pin7_1=51;
const int pin7_2=50;

const int enabler8=10;  // 3 2
const int pin8_1=53;
const int pin8_2=52;

const int enabler17=3; // 2 5
const int pin17=40;

const int enabler18=4; // 2 4
const int pin18=42;

const int enabler19=2;  // 3 6
const int pin19=44;

const int enabler20=5;  // 3 5
const int pin20=46;

//int A[50]={0};
//int down=0;
//int which[5]={0}
const int speed=100;
int flag=0;

void setup() {
  Serial.begin(9600);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(enabler, OUTPUT);
  pinMode(20, INPUT);
  pinMode(21, INPUT);

  attachInterrupt(digitalPinToInterrupt(20), isr, CHANGE);
  attachInterrupt(digitalPinToInterrupt(21), isr1, CHANGE);
  
  //pinMode(pin1,OUTPUT);
  pinMode(pin2_1,OUTPUT);
  pinMode(pin2_2,OUTPUT);
  //pinMode(pin3,OUTPUT);
  pinMode(pin4_1,OUTPUT);
  pinMode(pin4_2,OUTPUT);
  pinMode(pin5,OUTPUT);
  pinMode(pin6,OUTPUT);
  pinMode(pin7_1,OUTPUT);
  pinMode(pin7_2,OUTPUT);
  pinMode(pin8_1,OUTPUT);
  pinMode(pin8_2,OUTPUT);
  pinMode(pin17,OUTPUT);
  pinMode(pin18,OUTPUT);
  pinMode(pin19,OUTPUT);
  pinMode(pin20,OUTPUT);
  //pinMode(enabler1,OUTPUT);
  pinMode(enabler2,OUTPUT);
  //pinMode(enabler3,OUTPUT);
  pinMode(enabler4,OUTPUT);
  pinMode(enabler5,OUTPUT);
  pinMode(enabler6,OUTPUT);
  pinMode(enabler7,OUTPUT);
  pinMode(enabler8,OUTPUT);
  pinMode(enabler17,OUTPUT);
  pinMode(enabler18,OUTPUT);
  pinMode(enabler19,OUTPUT);
  pinMode(enabler20,OUTPUT);

}

void loop() 
{
  starttime = millis();
  endtime = starttime;
  flag=0;
  analogWrite(enabler,250);
  digitalWrite(pin1, LOW );
  digitalWrite(pin2, HIGH);
  /*
  delay(200);
  digitalWrite(pin1, LOW );
  digitalWrite(pin2, HIGH);
   */
  while ((endtime - starttime) <=21500) 
  {
    if (x == 1)
    {
      //delay(500);
      digitalWrite(pin1, LOW );
      digitalWrite(pin2, HIGH);
      x = 0;
    }
    if (y == 1)
    {
      //delay(500);
      digitalWrite(pin1, HIGH);
      digitalWrite(pin2, LOW);
      y = 0;
    } 
    endtime = millis(); 
    Serial.println(endtime-starttime);
    Serial.println(flag);
    if ((endtime-starttime+1000)>=3500 and flag==0)
    {
      D_on();
      flag+=1;  
    }
    else if ((endtime-starttime+1000)>=6000 and flag==1)
    {
      D_off();
      G_on();
      flag+=1;
    }
    else if ((endtime-starttime+1000)>=8500 and flag==2)
    {
      G_off();
      D_on();
      flag+=1;
    }
    else if ((endtime-starttime+1000)>=11000 and flag==3)
    {
      D_off();
      G_on();
      flag+=1;
    }
    else if ((endtime-starttime+1000)>=13500 and flag==4)
    {
      G_off();
      A_on();
      flag+=1;
    }
    else if ((endtime-starttime+1000)>=16000 and flag==5)
    {
      A_off();
      D_on();
      flag+=1;
    }
    else if ((endtime-starttime+1000)>=18500 and flag==6)
    {
      D_off();
      G_on();
      flag+=1;
    }
    else if ((endtime-starttime+1000)>=21000 and flag==7)
    {
      G_off();
      D_on();
      flag+=1;
    }
    D_off();
  }  
}
void down()
{
  analogWrite(enabler,200);
  digitalWrite(pin1, LOW );
  digitalWrite(pin2, HIGH);
  
}
void up()
{
  analogWrite(enabler,200);
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW );
  
}
void strum(int t)
{
  starttime = millis();
  endtime = starttime;
  while ((endtime - starttime) <=t) {
  analogWrite(enabler, 200);
  if (x == 1)
  {
    digitalWrite(pin1, LOW );
    digitalWrite(pin2, HIGH);
    x = 0;
  }
  if (y == 1)
  {
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
    y = 0;
  } endtime = millis(); }
}
void A(int t)
{
  analogWrite(enabler5,speed);
  analogWrite(enabler6,speed);
  analogWrite(enabler18,speed);
  digitalWrite(pin5,HIGH);
  digitalWrite(pin6,HIGH);
  digitalWrite(pin18,HIGH);
  strum(t);
  //delay(t);
  digitalWrite(pin5,LOW);
  digitalWrite(pin6,LOW);
  digitalWrite(pin18,LOW);
  //analogWrite(enabler5,0);
  //analogWrite(enabler6,0);
  //analogWrite(enabler18,0);
}

void A_on()
{
  analogWrite(enabler5,speed);
  analogWrite(enabler6,speed);
  analogWrite(enabler18,speed);
  digitalWrite(pin5,HIGH);
  digitalWrite(pin6,HIGH);
  digitalWrite(pin18,HIGH);
}

void A_off()
{
  digitalWrite(pin5,LOW);
  digitalWrite(pin6,LOW);
  digitalWrite(pin18,LOW);
  //analogWrite(enabler5,0);
  //analogWrite(enabler6,0);
  //analogWrite(enabler18,0);
}
void isr()
{
  x = 1;
}

void isr1()
{
  y = 1;
}

/*void Am(int t)
{
  analogWrite(enabler2,speed);
  analogWrite(enabler6,speed);
  analogWrite(enabler18,speed);
  digitalWrite(pin2,HIGH);
  digitalWrite(pin6,HIGH);
  digitalWrite(pin18,HIGH);
  delay(t);
  digitalWrite(pin2,LOW);
  digitalWrite(pin6,LOW);
  digitalWrite(pin18,LOW);
}*/
void D(int t)
{
  analogWrite(enabler4,speed);
  analogWrite(enabler6,speed);
  analogWrite(enabler8,speed);
  digitalWrite(pin6,HIGH);
  digitalWrite(pin4_1,HIGH);
  digitalWrite(pin4_2,LOW);
  digitalWrite(pin8_1,HIGH);
  digitalWrite(pin8_2,LOW);
  strum(t);
  //delay(t);
  digitalWrite(pin6,LOW);
  digitalWrite(pin4_2,HIGH);
  digitalWrite(pin4_1,LOW);
  digitalWrite(pin8_2,HIGH);
  digitalWrite(pin8_1,LOW);
  analogWrite(enabler4,0);
  analogWrite(enabler6,0);
  analogWrite(enabler8,0);
}

void D_on()
{
  analogWrite(enabler4,speed);
  analogWrite(enabler6,speed);
  //analogWrite(enabler8,speed);
  digitalWrite(pin6,HIGH);
  digitalWrite(pin4_1,HIGH);
  digitalWrite(pin4_2,LOW);
  //digitalWrite(pin8_1,HIGH);
  //digitalWrite(pin8_2,LOW);
}

void D_off()
{
  digitalWrite(pin6,LOW);
  digitalWrite(pin4_2,HIGH);
  digitalWrite(pin4_1,LOW);
  //digitalWrite(pin8_2,HIGH);
  //digitalWrite(pin8_1,LOW);
  //analogWrite(enabler4,0);
  //analogWrite(enabler6,0);
  //analogWrite(enabler8,0);
}

void G(int t)
{
  analogWrite(enabler7,speed);
  analogWrite(enabler17,speed);
  analogWrite(enabler19,speed);
  digitalWrite(pin7_1,HIGH);
  digitalWrite(pin7_2,LOW);
  digitalWrite(pin17,HIGH);
  digitalWrite(pin19,HIGH);
  strum(t);
  //delay(t);
  digitalWrite(pin7_2,HIGH);
  digitalWrite(pin7_1,LOW);
  digitalWrite(pin17,LOW);
  digitalWrite(pin19,LOW);
  analogWrite(enabler7,0);
  analogWrite(enabler17,0);
  analogWrite(enabler19,0);
}

void G_on()
{
  analogWrite(enabler7,speed);
  analogWrite(enabler17,speed);
  analogWrite(enabler19,speed);
  digitalWrite(pin7_1,HIGH);
  digitalWrite(pin7_2,LOW);
  digitalWrite(pin17,HIGH);
  digitalWrite(pin19,HIGH);
}

void G_off()
{
  digitalWrite(pin7_2,HIGH);
  digitalWrite(pin7_1,LOW);
  digitalWrite(pin17,LOW);
  digitalWrite(pin19,LOW);
  //analogWrite(enabler7,0);
  //analogWrite(enabler17,0);
  //analogWrite(enabler19,0);
}
void C(int t)
{
  analogWrite(enabler2,speed);
  analogWrite(enabler18,speed);
  analogWrite(enabler20,speed);
  digitalWrite(pin2,HIGH);
  digitalWrite(pin18,HIGH);
  digitalWrite(pin20,HIGH);
  delay(t);
  digitalWrite(pin2,LOW);
  digitalWrite(pin18,LOW);
  digitalWrite(pin20,LOW);
}

void C_on()
{
  analogWrite(enabler2,speed);
  analogWrite(enabler18,speed);
  analogWrite(enabler20,speed);
  digitalWrite(pin2,HIGH);
  digitalWrite(pin18,HIGH);
  digitalWrite(pin20,HIGH);
}

void C_off()
{
  
  digitalWrite(pin2,LOW);
  digitalWrite(pin18,LOW);
  digitalWrite(pin20,LOW);
  //analogWrite(enabler2,0);
  //analogWrite(enabler18,0);
  //analogWrite(enabler20,0);
}


void Em_on()
{
  analogWrite(enabler18,speed);
  analogWrite(enabler17,speed);
  digitalWrite(pin18,HIGH);
  digitalWrite(pin17,HIGH);
}

void Em_off()
{
  
  digitalWrite(pin18,LOW);
  digitalWrite(pin17,LOW);
  //analogWrite(enabler18,0);
  //analogWrite(enabler17,0);
}



/*void C(int t)
{
  analogWrite(enabler2,speed);
  analogWrite(enabler18,speed);
  analogWrite(enabler20,speed);
  digitalWrite(pin2,HIGH);
  digitalWrite(pin18,HIGH);
  digitalWrite(pin20,HIGH);
  delay(t);
  digitalWrite(pin2,LOW);
  digitalWrite(pin18,LOW);
  digitalWrite(pin20,LOW);
}*/
/*
void A()
{
  int a=0,b=0,c=0;
  for (int i=0;i<down;i++)
  {
    if (which[i]==pin5) a=1;
    else if (which[i]==pin6) b=1;
    else if (which[i]==pin18) c=1;
    else
    {
      digitalWrite(which[i],LOW);
    }
  }
  if (a==0)   digitalWrite(pin5, HIGH);
  if (b==0)   digitalWrite(pin6, HIGH);
  if (c==0)   digitalWrite(pin18, HIGH);
  delay(100);
  down=3;
  which[0]=pin5;
  which[1]=pin6;
  which[2]=pin18;
}*/
/*
void Am()
{
  int a=0,b=0,c=0;
  for (int i=0;i<down;i++)
  {
    if (which[i]==pin2) a=1;
    else if (which[i]==pin6) b=1;
    else if (which[i]==pin18) c=1;
    else
    {
      digitalWrite(which[i],LOW);
    }
  }
  if (a==0)   digitalWrite(pin2, HIGH);
  if (b==0)   digitalWrite(pin6, HIGH);
  if (c==0)   digitalWrite(pin18, HIGH);
  delay(100);
  down=3;
  which[0]=pin2;
  which[1]=pin6;
  which[2]=pin18;
}
void C()
{
  int a=0,b=0,c=0;
  for (int i=0;i<down;i++)
  {
    if (which[i]==pin2) a=1;
    else if (which[i]==pi20) b=1;
    else if (which[i]==pin18) c=1;
    else
    {
      digitalWrite(which[i],LOW);
    }
  }
  if (a==0)   digitalWrite(pin2, HIGH);
  if (b==0)   digitalWrite(pin20, HIGH);
  if (c==0)   digitalWrite(pin18, HIGH);
  delay(100);
  down=3;
  which[0]=pin2;
  which[1]=pin20;
  which[2]=pin18;
}
void D()
{
  int a=0,b=0,c=0;
  for (int i=0;i<down;i++)
  {
    if (which[i]==pin4) a=1;
    else if (which[i]==pin6) b=1;
    else if (which[i]==pin8) c=1;
    else
    {
      digitalWrite(which[i],LOW);
    }
  }
  if (a==0)   digitalWrite(pin4, HIGH);
  if (b==0)   digitalWrite(pin6, HIGH);
  if (c==0)   digitalWrite(pin8, HIGH);
  delay(100);
  down=3;
  which[0]=pin4;
  which[1]=pin6;
  which[2]=pin8;
}
void Dm()
{
  int a=0,b=0,c=0;
  for (int i=0;i<down;i++)
  {
    if (which[i]==pin1) a=1;
    else if (which[i]==pin6) b=1;
    else if (which[i]==pin8) c=1;
    else
    {
      digitalWrite(which[i],LOW);
    }
  }
  if (a==0)   digitalWrite(pin1, HIGH);
  if (b==0)   digitalWrite(pin6, HIGH);
  if (c==0)   digitalWrite(pin8, HIGH);
  delay(100);
  down=3;
  which[0]=pin1;
  which[1]=pin6;
  which[2]=pin8;
}
void E()
{
  int a=0,b=0,c=0;
  for (int i=0;i<down;i++)
  {
    if (which[i]==pin3) a=1;
    else if (which[i]==pin17) b=1;
    else if (which[i]==pin18) c=1;
    else
    {
      digitalWrite(which[i],LOW);
    }
  }
  if (a==0)   digitalWrite(pin3, HIGH);
  if (b==0)   digitalWrite(pin17, HIGH);
  if (c==0)   digitalWrite(pin18, HIGH);
  delay(100);
  down=3;
  which[0]=pin3;
  which[1]=pin17;
  which[2]=pin18;
}
void Em()
{
  int a=0,b=0;
  for (int i=0;i<down;i++)
  {
    if (which[i]==pin17) a=1;
    else if (which[i]==pin18) b=1;
    else
    {
      digitalWrite(which[i],LOW);
    }
  }
  if (b==0)   digitalWrite(pin17, HIGH);
  if (b==0)   digitalWrite(pin18, HIGH);
  delay(100);
  down=2;
  which[0]=pin17;
  which[1]=pin18;
}*/


