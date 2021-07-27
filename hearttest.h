int ai=0;
volatile int bt=0;
int bi=0;
int ci=141;
int teth=130;
int teth1=260;
int ibm=120;
int ibm1=120;
volatile boolean key = false;
volatile int al=0;
volatile int newva=0;
volatile int newvb=0;
volatile int maxva=0;
volatile int minva=2000;
volatile int bza=0;
volatile int bzb=0;
volatile int bzsum=0;
volatile int timewh=0;
volatile int timewha=0;
volatile int timet=0;
void heart(){
    if(newva>newvb){
       bza=1;
       bzsum++;
      }
      else{ bza=0;
      bzsum=0;
      }
      if(ci<71){
       
        if(ci<1){
        ci=141;
        maxva=maxva-teth;
        minva=minva+teth/4;
        
        }
        else{
        teth1=maxva-minva;
        if(teth1>30){
        teth=teth1/2;
        }
        
          }
        }
      else {
      if(maxva<newva){
        maxva=newva;}
      if(minva>newva){
        minva=newva;}
      }
      ci--;
//    Serial.println(newva);
//    Serial.println(y4);
      int wh=(maxva-minva)*6/10+minva;
      if((bzsum=6)&&(al==0)){
         if(newva>wh){
        bt++;
        al=1;
        key=false;
        timewha=timewh;
        timewh=millis();
        timet=timewh-timewha;
        }
         if((400<timet)&&(timet<1000)){
          ibm=60000/timet;
          ibm1=ibm;}
        else{ibm=ibm1;}
        }
        if((ai<16)&&(al==1))
        {ai++;}
          else{
            ai=0;
            al=0;}
        Serial.print(timet);
        Serial.print(" ");
        Serial.print(maxva);
        Serial.print(" ");
        Serial.print(wh);
        Serial.print(" ");
        Serial.println(minva);
        Serial.print(newva);
        Serial.print(" ");
  
  }
