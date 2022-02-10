

/* 
 Calculating the parameter for signal A 
 
 Surname is  "PILLAI"

 So, P=16, I=9, L=12, A=1

 a = P * 100 = 16 * 100 = 1600
  
 b = I * 100 = 9 * 100 = 900
 
 c = L + 4 = 12 + 4 = 16

 d = L * 500 = 12 * 500 = 6000
 
 mode = rem(A/4)+1 = rem(1/4)+1 = 4

*/


#define Red_Led 15
#define Green_Led 21
#define Push_button_1 22
#define Push_button_2 23         //defining variables for gpio pin in esp32

int a=1600, b=900, c=16, d=6000;          //defining the parameter of singal A waveform

boolean pushButton_1_state, pushButton_2_state;
 
void setup() {
  
pinMode(Red_Led, OUTPUT);         // Red led is for signal B
pinMode(Green_Led,OUTPUT);        // Green led is for signal A
pinMode(Push_button_1,INPUT);
pinMode(Push_button_2,INPUT);
  
}


void loop() {

pushButton_1_state= digitalRead(Push_button_1);        // defining state of push button 1 
pushButton_2_state= digitalRead(Push_button_2);         // defining state of push button 2

if(pushButton_1_state == 0){

  signal_B(50);       // starting signal B with 50 microsensond pluse width
  
  if(pushButton_2_state == 0){
    
    signal_A(a,b,c,d);        //normal signal A with parameter a, b, c and d
    
  }
  else{
    
    signal_A(a,b/2,c,d/2);        //modified signal A with half of b and d parameter
    
  } 
  
}

}



// funtion for signal B with 'x' as its parameter where x in the width of the pulse

int signal_B(int x){
   
  digitalWrite(Red_Led,HIGH);
  delayMicroseconds(x);
  digitalWrite(Red_Led,LOW);  
  
}



//funtion for signal A with parameters 'a', 'b','c' and 'd'

int signal_A(int a,int b,int c,int d){

    for(int i=0;i<c;i++){
    
      digitalWrite(Green_Led,HIGH);
      delayMicroseconds(a);
      digitalWrite(Green_Led,LOW);
      delayMicroseconds(b);
      a=a+50;
    }

    delayMicroseconds(d);

}
