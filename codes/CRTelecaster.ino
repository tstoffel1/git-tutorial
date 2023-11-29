
#include "pitches.h"
#include <ezButton.h>
ezButton toggleSwitch(7);
int pos = 0;
int notes = 0;
int scalesel = 0;
int bassmode = 1;
float smoothADC;
int vibra=0;
  //songs
    //nokia ringtone
    int nokia[13] = {E5,D5,FS4,GS4,CS5,B4,D4,FS4,B4,A4,CS4,E4,A4};
    int nokiadur[13] = {8,8,4,4,8,8,4,4,8,8,4,4,1};
    //Fnaf Song
    int fnaf[35] = {C4,D4,C4,A3,A3,A3,G3,A3,AS3,A3,AS3,G3,C4,A3,F3,D3,G3,C3,G3,G3,D4,C4,AS3,A3,G3,A3,AS3,A3,E3,E3,A3,A3,GS3,B3,A3};
    float fnafdur[35] = {4,8,8,4,4,8,8,8,8,1.5,4,8,8,1.5,4,8,8,1.5,2,8,8,8,8,8,8,8,8,3,8,4,4,4,8,8,1};
    //Ben 10
    int ben[45] = {AS4,AS4,CS5,FS4,GS4,GS4,AS4,DS4,FS4,GS4,FS4,DS4,DS4,0,AS4,AS4,CS5,FS4,GS4,GS4,AS4,DS4,FS4,GS4,FS4,DS4,DS4,0,AS4,AS4,CS5,AS4,DS5,CS5,AS4,FS4,GS4,AS4,GS4,FS4,DS4,CS4,DS4,DS4,0};
    float bendur[45] = {4,4,4,4,4,4,4,4,4,4,4,4,2,2,4,4,4,4,4,4,4,4,4,4,4,4,2,2,4,4,4,4,4,4,4,4,4,4,4,4,4,4,2,2,2};
    //Buddy Holly Riff
    int bh[9] = {GS4,E4,GS4,AS4,C5,AS4,GS4,E4,DS4};
    float bhdur[9] = {8,8,8,8,8,8,8,8,2};
    //Fallen down
    int FD[47] = {FS4,CS4,FS4,CS4,FS4,CS4,FS4,CS4,FS4,CS4,FS4,CS4,B3,A3,CS4,A3,B3,E4,DS4,E4,FS4,DS4,B3,FS4,B3,FS4,B3,FS4,B3,FS4,AS3,FS4,AS3,G4,AS3,FS4,D4,FS4,D4,E4,FS4,E4,FS3,D4,FS3,CS4,FS3};
    float FDdur[47] = {8,8,8,8,8,8,8,8,8,8,8,8,8,8,4,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,4,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8};
    //Travelers
    int OW[46] = {C3,G3,B3,G3,C4,B3,A3,G3,A3,B3,G3,D3,G3,B3,G3,C4,B3,A3,G3,A3,B3,D4,B3,E3,G3,B3,G3,C4,B3,A3,G3,A3,B3,G3,D3,G3,B3,G3,C4,B3,A3,G3,A3,B3,D4,B3};
    float OWdur[46] = {4,4,3,8,8,8,8,8,8,8,4,4,4,3,8,8,8,8,8,8,8,8,8,4,4,3,8,8,8,8,8,8,8,4,4,4,3,8,8,8,8,8,8,8,8,8};
    
int scale[16][16] = {
                     {C3, CS3, D3, DS3, E3, F3, FS3, G3, GS3, A3, AS3, B3, C4, CS4, D4, DS4,},
                     {C3, D3, E3, F3, G3, A3, B3, C4, D4, E4, F4, G4, A4, B4, C5, D5},
                     {CS3, DS3, F3, FS3, GS3, AS3, C4, CS4, DS4, F4, FS4, GS4, AS4, C5, CS5, DS5},
                     {D3, E3, FS3, G3, A3, B3, CS4, D4, E4, FS4, G4, A4, B4, CS5, D5,E5},
                     {DS3, F3, G3, GS3, AS3, C4, D4, DS4, F4, G4, GS4, AS4, C5, D5, DS5, F5},
                     {E3, FS3, GS3, A3, B3, CS4, DS4, E4, FS4, GS4, A4, B4, CS5, DS5, E5, FS5},
                     {F2, G2, A2, AS2, C3, D3, E3, F3, G3, A3, AS3, C4, D4, E4, F4, G4},
                     {FS3, GS3, AS3, B3, CS4, DS4, F4, FS4, GS4, AS4, B4, CS5, DS5, F5, FS5, GS5},
                     {G3, A3, B3, C4, D4, E4, FS4, G4, A4, B4, C5, D5, E5, FS5, G5, A5},
                     {GS3, AS3, C4, CS4, DS4, F4, G4, GS4, AS4, C5, CS5, DS5, F5, G5, GS5, AS5},
                     {A3, B3, CS4, D4, E4, FS4, GS4, A4, B4, CS5, D5, E5, FS5, GS5, A5, B5},
                     {AS3, C4, D4, DS4, F4, G4, A4, AS4, C5, D5, DS5, F5, G5, A5, AS5, C6},
                     {B2, CS3, DS3, E3, FS3, GS3, AS3, B3, CS4, DS4, E4, FS4, GS4, AS4, B4, CS5},
                     //Iwato scale
                     {C2, CS2, F2, FS2, AS2, C3, CS3, F3, FS3, AS3, C4, CS4, F4, FS4, AS4, 150 },
                     //Yo scale, very good for Amazing Grace aparently
                     {D3, E3, G3, A3, B3, D4, E4, G4, A4, B4, D5, E5,G5, A5, B5, D6},
                     //Dorian A mode(Medieval Sounds)
                     {A2, B2, C3, D3, E3, FS3, G3, A3, B3, C4, D4, E4, FS4, G4, A4, B4}};



                     

void setup() {
  Serial.begin(9600);
  pinMode(11, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A4, INPUT);
  pinMode(6, INPUT);
  digitalWrite(6, HIGH);
  pinMode(5, INPUT);
  digitalWrite(5, HIGH);
  pinMode(4, INPUT);
  digitalWrite(4, HIGH);
  toggleSwitch.setDebounceTime(100);
}
void loop() {
  toggleSwitch.loop();
  int note = analogRead(A0);
  int tens = analogRead(A1);
  int ones = analogRead(A3);
  int state = toggleSwitch.getState();
  if (state == HIGH)
    bassmode = 1;
  else
    bassmode = 2;

  int melsel = scalesel;
  int maxscale = 22;

  //Vibrato Function
  if (digitalRead(4)==LOW&&digitalRead(5)==LOW)
  {
     scalesel=16;
      delay(400);
      tone(11,200);
      delay(100);
      tone(11,400);
      delay(100);
      noTone(11);
  }

  //Scale Selection
  if (digitalRead(5)==LOW){ 
    if(scalesel==maxscale)
    {
        scalesel=0;
        delay(400);
    }
    else
      scalesel++;
      delay(400);
  }
  if (digitalRead(4)==LOW)
  {
     if(scalesel==0)
    {
        scalesel=maxscale;
        delay(400);
    }
    else
      scalesel--;
      delay(400);
  }
  
  //Scale Test and Autosongs
  if (digitalRead(6)==LOW){
     if(scalesel==16){
      tone(11,440);
     }
     else if(scalesel>16){
    if(melsel==17){
       for (int nextnote = 0; nextnote < 13; nextnote++){
          int dura = 1000 / nokiadur[nextnote];
          tone(11, nokia[nextnote]/bassmode, dura);
          int pauseBetweenNotes = dura * 1.30;
          delay(pauseBetweenNotes);
          noTone(11);  
       }
     }
     else if(melsel==18){
       for (int nextnote = 0; nextnote < 35; nextnote++){
          int dura = 1000 / fnafdur[nextnote];
          tone(11, fnaf[nextnote]/bassmode, dura);
          int pauseBetweenNotes = dura * 1.90;
          delay(pauseBetweenNotes);
          noTone(11);  
       }
     }
      else if(melsel==19){
       for (int nextnote = 0; nextnote < 45; nextnote++){
          int dura = 750 / bendur[nextnote];
          tone(11, ben[nextnote]/bassmode, dura);
          int pauseBetweenNotes = dura * 1.30;
          delay(pauseBetweenNotes);
          noTone(11);  
       }
     }
     else if(melsel==20){
       for (int nextnote = 0; nextnote < 47; nextnote++){
          int dura = 2000 / FDdur[nextnote];
          tone(11, FD[nextnote]/bassmode, dura);
          int pauseBetweenNotes = dura * 1.0;
          delay(pauseBetweenNotes);
          noTone(11);  
       }
     }
     else if(melsel==21){
       for (int nextnote = 0; nextnote < 46; nextnote++){
          int dura = 2000 / OWdur[nextnote];
          tone(11, OW[nextnote]/bassmode, dura);
          int pauseBetweenNotes = dura * 1.3;
          delay(pauseBetweenNotes);
          noTone(11);  
       }
     }
     else if(melsel==22){
       for (int nextnote = 0; nextnote < 30; nextnote++){
          int dura = 1500 / bhdur[nextnote];
          tone(11, bh[nextnote]/bassmode, dura);
          int pauseBetweenNotes = dura * 1.30;
          delay(pauseBetweenNotes);
          noTone(11);  
       }
     }
     }
     else if(scalesel<16){
       for(int i=0;i<16;i++){
         tone(11,scale[scalesel][i]);
         delay(75);
         noTone(11);
         delay(75);
         }
     }
  }
  else if (scalesel==16){note = map(note, 0, 1023, 294, 1500);}
  else             {note = map(note, 0, 1023, 0, 5000);}
  //Note selection
    if      (note < 100)  {pos = 13;}
    else if (note < 200) {pos = 12;}
    else if (note < 400) {pos = 11;}
    else if (note < 600) {pos = 10;}
    else if (note < 800) {pos = 9;}
    else if (note < 1000) {pos = 8;}
    else if (note < 1200) {pos = 7;}
    else if (note < 1333) {pos = 6;}
    else if (note < 1500) {pos = 5;}
    else if (note < 1800) {pos = 4;}
    else if (note < 2333) {pos = 3;}
    else if (note < 3000) {pos = 2;}
    else if (note < 3800) {pos = 1;}
    else                {pos = 0;}
    notes = scale[scalesel][pos];


  //playing the guitar
  Serial.print("Analog: ");
  Serial.print(note);
  Serial.print(" ");
  Serial.print(notes);
  Serial.print(" ");
  Serial.print(pos);
  Serial.print(" ");
  Serial.print(bassmode);
  Serial.print('\n');
  Serial.print(scalesel);
  Serial.print('\n');
  Serial.print(vibra);
  Serial.print('\n');
  delay(5);
        if (scalesel == 16&&note>=350)      
        {
          tone(11,(1550-note)/bassmode);
        }
        else if (scalesel<16&&note>50)     
        {
          tone(11,notes/bassmode);
        }
        else{noTone(11);}





  }