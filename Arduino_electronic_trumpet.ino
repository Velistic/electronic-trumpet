int speaker = 11; // Speaker au digital pin 11
int analogPin = A3; //analog pin 1
int sw1 = 8; // Switch au digital pin 8
int sw2 = 9; // Switch au digital pin 9
int sw3 = 10; // Switch au digital pin 10
int valve1; 
int valve2; 
int valve3;
int led1 = 1;
int led2 = 2;
int led3 = 3;
int led4 = 4;
int led5 = 5;
int led6 = 6;
int led12 = 12;
;
unsigned int ADCValue;
double Voltage;
float Vcc = 5.0;
int temp=0;
int Blow=0;
int Flow=0;
int count=0;
int wait=0;
int start=0;
int debounce=0;
;
int numTones = 32;
//Frequences des notes de musique (https://pages.mtu.edu/~suits/notefreqs.html)
int tones[] = {185, 196, 208, 220, 233, 247, 262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494, 523, 554, 587, 622, 659, 698, 740, 784, 831, 880, 932, 988, 1047, 1109}; 

void setup() 
{
  // initialize serial communication at 9600 bits per second:
  //Serial.begin(9600);
  pinMode(led1, OUTPUT);      // sets the digital pin as output
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led12, OUTPUT);  
  pinMode(speaker, OUTPUT);
  pinMode(sw1, INPUT);
  digitalWrite(sw1, HIGH);
  pinMode(sw2, INPUT);
  digitalWrite(sw2, HIGH);
  pinMode(sw3, INPUT);
  digitalWrite(sw3, HIGH);
  //Serial.begin(9600);
}

void loop() {

valve1 = digitalRead(sw1); // Reads switch 1
valve2 = digitalRead(sw2); // Reads switch 2
valve3 = digitalRead(sw3); // Reads switch 3
count = count + 1;
  // read the input on analog pin 3:


//pressure sensor measures difference between blown air and atmospheric pressure, translates intensity of blow into voltage

  ADCValue = analogRead(A3);
  Voltage = (ADCValue / 1023.0) * Vcc;

 
    if (Voltage > 0.5 && Voltage <= 0.75) 
    {
       if(Flow ==0 && debounce==0)
       { 
          start=1;
       }
       else
       {
         start=0;
       }
        Flow = 1;
        if(debounce==0)
         {
            debounce=1;
            count=0;
         }
    }
    
    if (Voltage > 1.75 && Voltage <= 2.0) 
    {
        Flow = 2;
        if(debounce==0)
          {
            debounce=1;
            count=0;
          }
   }
    if (Voltage > 3.0 && Voltage <= 3.25) 
     {
       Flow = 3;
       if(debounce==0)
          {
            debounce=1;
            count=0;
          }
    }  
    if (Voltage > 4.25 && Voltage <= 4.5) 
     {
       Flow = 4;
       if(debounce==0)
          {
            debounce=1;
            count=0;
          }
      }      
     if (Voltage > 4.85) 
      {
       Flow = 5;
       if(debounce==0)
          {
            debounce=1;
            count=0;
          }
      }  
      if (Voltage < 0.25)
     {
           Flow = 0;
           Blow = 0;
     }
     	 
    //Test the signal
  PORTD = 0b00000000;
  bitWrite(PORTD, Flow, 1);
  
  //Delay debouncing Flow
  if(start == 1)
  {
    wait=600;
  }
  else
  {
    wait=200;
  }
  if(debounce == 1)
  {
      digitalWrite(led12, HIGH);
      if(count > wait) 
     {
	  Blow = Flow;
          debounce = 0;
          start=0;
          digitalWrite(led12, LOW);
     }
  }    

///////////////////////////////////
//           Combinaisons

//                                  /
//                               |
//     Valves:   1 2 3           /|
//        _______I_I_I_________/ |
//  D====/ ____________________  |  - -
//       ||   __| | | |___  || \ |
//       \\__[_=|_[[|_|==_]_//  \|
//        \_________________/    |  \
//               = = =

//Valve press = LOW
//Valve not pressed = HIGH
//Blow pressure level =  Blow (also equals voltage flow using pressure sensor)

//////////////////////////////////

if ((valve1 == LOW) && (valve2 == LOW) && (valve3 == LOW) && (Blow == 10)) { // If all valves are pressed, and user blows lightly then play lowest note
  tone(speaker, tones[0]); // low f#
   delay (1); 
    } 
  else if ((valve1 == LOW) && (valve2 == HIGH) && (valve3 == LOW) && (Blow == 10)) { 
  tone(speaker, tones[1]); // low g
   delay (1); 
  } 
  else if ((valve1 == HIGH) && (valve2 == LOW) && (valve3 == LOW) && (Blow == 10)) {
  tone(speaker, tones[2]); // low g#
   delay (1); 
  }   
  else if ((valve1 == LOW) && (valve2 == LOW) && (valve3 == HIGH) && (Blow == 10)) { 
  tone(speaker, tones[3]); //low a
   delay (1); 
  } 
  else if ((valve1 == LOW) && (valve2 == HIGH) && (valve3 == HIGH) && (Blow == 10)) { 
  tone(speaker, tones[4]); // low a#
   delay (1); 
  } 
  else if ((valve1 == HIGH) && (valve2 == LOW) && (valve3 == HIGH) && (Blow == 10)) { 
   tone(speaker, tones[5]);// LOW b
   delay (1); 
  }
  else if ((valve1 == HIGH) && (valve2 == HIGH) && (valve3 == HIGH) && (Blow == 1)) {
    tone(speaker, 262); //middle c
   delay (1); 
  }   
  else if ((valve1 == LOW) && (valve2 == LOW) && (valve3 == LOW) && (Blow == 1)) { 
  tone(speaker, tones[7]); //c#
   delay (1); 
  } 
  else if ((valve1 == LOW) && (valve2 == HIGH) && (valve3 == LOW) && (Blow == 1)) { 
   tone(speaker, tones[8]); //d
   delay (1); 
  }
  else if ((valve1 == HIGH) && (valve2 == LOW) && (valve3 == LOW) && (Blow == 1)) { 
  tone(speaker, tones[9]);//d#
   delay (1); 
  }   
  else if ((valve1 == LOW) && (valve2 == LOW) && (valve3 == HIGH) && (Blow == 1)) { 
  tone(speaker, tones[10]);//e
   delay (1); 
  }   
  else if ((valve1 == LOW) && (valve2 == HIGH) && (valve3 == HIGH) && (Blow == 1)) {
  tone(speaker, tones[11]);//f
   delay (1); 
  }   
  else if ((valve1 == HIGH) && (valve2 == LOW) && (valve3 == HIGH) && (Blow == 1)) { 
  tone(speaker, tones[12]);//f#
   delay (1); 
  }   
  else if ((valve1 == HIGH) && (valve2 == HIGH) && (valve3 == HIGH) && (Blow == 2)) { 
  tone(speaker, tones[13]);//g
   delay (1); 
  }   
  else if ((valve1 == HIGH) && (valve2 == LOW) && (valve3 == LOW) && (Blow == 2)) { 
  tone(speaker, tones[14]);//g#
   delay (1); 
  }  
  else if ((valve1 == LOW) && (valve2 == LOW) && (valve3 == HIGH) && (Blow == 2)) { 
  tone(speaker, tones[15]);//a
   delay (1); 
  }
  else if ((valve1 == LOW) && (valve2 == HIGH) && (valve3 == HIGH) && (Blow == 2)) { 
  tone(speaker, tones[16]);//a#
   delay (1); 
  } 
  else if ((valve1 == HIGH) && (valve2 == LOW) && (valve3 == HIGH) && (Blow == 2)) {
  tone(speaker, tones[17]);//b
   delay (1); 
  } 
  else if ((valve1 == HIGH) && (valve2 == HIGH) && (valve3 == HIGH) && (Blow == 3)) {
   tone(speaker, tones[18]);//C
   delay (1);  
  }    
  else if ((valve1 == LOW) && (valve2 == LOW) && (valve3 == HIGH) && (Blow == 3)) {
  tone(speaker, tones[19]);//C#
   delay (1);  
  } 
  else if ((valve1 == LOW) && (valve2 == HIGH) && (valve3 == HIGH) && (Blow == 3)) { // If all valves are pressed, then
  tone(speaker, tones[20]);//D
   delay (1); 
  }    
  else if ((valve1 == HIGH) && (valve2 == LOW) && (valve3 == HIGH) && (Blow == 3)) {
   tone(speaker, tones[21]);//D#
   delay (1);  
  }      
  else if ((valve1 == HIGH) && (valve2 == HIGH) && (valve3 == HIGH) && (Blow == 4)) {
  tone(speaker, tones[22]);//E
   delay (1); 
  }
  else if ((valve1 == LOW) && (valve2 == HIGH) && (valve3 == HIGH) && (Blow == 4)) { 
  tone(speaker, tones[23]);//F
   delay (1); 
  } 
  else if ((valve1 == HIGH) && (valve2 == LOW) && (valve3 == HIGH) && (Blow == 4)) {
   tone(speaker, tones[24]);//F#
   delay (1);  
  } 
  else if ((valve1 == HIGH) && (valve2 == HIGH) && (valve3 == HIGH) && (Blow == 5)) { 
  tone(speaker, tones[25]);//G
   delay (1); 
  }     
  else if ((valve1 == HIGH) && (valve2 == LOW) && (valve3 == LOW) && (Blow == 5)) { 
  tone(speaker, tones[26]);//G#
   delay (1); 
  }
  else if ((valve1 == LOW) && (valve2 == LOW) && (valve3 == HIGH) && (Blow == 5)) { 
  tone(speaker, tones[27]);//A
   delay (1); 
  }  
  else if ((valve1 == LOW) && (valve2 == HIGH) && (valve3 == HIGH) && (Blow == 5)) { 
  tone(speaker, tones[28]);//A#
   delay (1); 
  }  
  else if ((valve1 == HIGH) && (valve2 == LOW) && (valve3 == HIGH) && (Blow == 5)) {
  tone(speaker, tones[29]);//B
   delay (1); 
  }  
  else if ((valve1 == LOW) && (valve2 == LOW) && (valve3 == LOW) && (Blow == 5)) { // If all valves are pressed, and user blows strongly then play highest note
  tone(speaker, tones[30]);//HIGHEST C
   delay (1); 
  }   
  else if ((valve1 == HIGH) && (valve2 == HIGH) && (valve3 == LOW) && (Blow == 5)) { 
  tone(speaker, tones[31]);//HC#
   delay (1); 
  }
  else{
  noTone(speaker);
  delay(1);
  }
     
}
