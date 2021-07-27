#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306.h" // alias for `#include "SSD1306Wire.h"`
#include "hearttest.h"

int x=0;
int y4=0;
int lastx=0;
int lasty=0;
volatile int va=0;
volatile int ba[16];
int i=0;
volatile int sum=0;
SSD1306  display(0x3c, 4, 15);
 void setup() {
 pinMode(35,INPUT);
 Serial.begin(115200);
 int analogRead(35);
display.init();
display.flipScreenVertically();
display.setFont(ArialMT_Plain_10);

}

void loop() {
 
//  display.clear();
  va= analogRead(35);
 if((va>1300)&&(va<3000)){
  if(i<16){
    ba[i]=va;
    sum=sum+ba[i];
    i++;
  }
  else{ 
    newvb=newva;
    newva=sum/16;
    sum=va;
    i=1;
    heart();
    int y1=teth/8;
    int y2=teth/15;
    int y3=newva-minva;
    int y4=44-y3/y2-y1/8;
    if(x>127)
    {
      display.clear();
      x=0;
      lastx=x;
      }
    display.setColor(WHITE);
    display.drawLine(lastx,lasty,x,y4);
    display.display();
     lasty=y4;
     lastx=x;
     x++;
     Serial.print(y4);
        Serial.print(" ");
     } 
    }

delay(1);
display.setColor(BLACK);
display.fillRect(0,54,128,64);
display.setTextAlignment(TEXT_ALIGN_LEFT);
display.setFont(ArialMT_Plain_10);
display.setColor(WHITE);
display.drawString(12,54,String(ibm));
display.drawString(50,54,String(timet));
display.display();
}
