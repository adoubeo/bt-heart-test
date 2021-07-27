import processing.serial.*;

Serial myPort;
int xPos=1;
float fValue=1800;
boolean newVal=false;
int height1=799;
int with1=1000;
float maxh=0;
float maxh1=3000;
float minh1=1000;
float minh=0;
int lastx=0;
float lasty=0;
int iq=0;
float easing=0.5;
float easval;
float aa1;

void settings(){
size(1000,550);

}
void setup(){
     String myaa=Serial.list()[0];
     myPort=new Serial(this,myaa,115200);
     myPort.bufferUntil('\n');
     background(0);
}
    
void draw(){
       
     if(fValue>maxh){
          maxh=fValue;
          }
          else{iq++;}
          if(fValue<minh){
          minh=fValue;
          }
          if(iq>500){
           maxh=fValue;
           minh=fValue;
           iq=0;
          }
          if(iq==200){
          maxh1=maxh;
          }
   aa1=maxh1-minh;
   float aa2=(aa1/200);
   float y=(fValue-minh)/aa2;
   println(y);
   println(aa1);
   println(a2);
   int targetval=int(500-y);
   easval+=(targetval-easval)*easing;
   map(easval,0,200,0,100);
   line(lastx,lasty,xPos,easval);
   lastx=xPos;
   lasty=easval;
   if(xPos>=with1){
   xPos=0;
   lastx=xPos;
   background(2);
   }
   xPos+=2;
   }
   

void serialEvent(Serial myPort){
          String inString=myPort.readStringUntil('\n');
          if(myPort.available() > 0){
          fValue=float(inString);
          inString = trim(inString);
         String[] list = split(inString, ':');
         if (list.length != 10) return;
          }
}
