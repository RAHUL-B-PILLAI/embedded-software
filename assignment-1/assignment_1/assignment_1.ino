

/* 
 Calculating the parameter for signal A 
 
 SURNAME IS PILLAI

 So, P=16, I=9, L=12, A=1

 a = P * 100 = 16 * 100 = 1600
  
 b = I * 100 = 9 * 100 = 900
 
 c = L + 4 = 12 + 4 = 16

 d = L * 500 = 12 * 500 = 6000
 
 mode = rem(A/4)+1 =

*/


#define red_led 15
#define green_led 21
#define push_1 22
#define push_2 23          //defining variables for gpio pin in esp32

int a=1600, b=900, c=16, d=6000;                    //defining the parameter of singal A waveform

void setup() {
  
pinMode(red_led, OUTPUT);
pinMode(green_led,OUTPUT);
pinMode(push_1,INPUT);
pinMode(push_2,INPUT);
  
}

void loop() {


// Red led is for signal B and green led is for signal A

//starting Signal B for 50 microseconds

digitalWrite(red_led,HIGH);
delayMicroseconds(50);
digitalWrite(red_led,LOW); 

//starting Signal A

for(int i=0;i<=c;i++){

  digitalWrite(green_led,HIGH);
  delayMicroseconds(a);
  digitalWrite(green_led,LOW);
  delayMicroseconds(b);

}


}
