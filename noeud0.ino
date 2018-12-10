#include <RF24.h> 
#include<RF24Network.h>
#include<SPI.h> 
#include<LiquidCrystal.h>
LiquidCrystal lcd(8,7,6,5,4,3);
RF24 radio(10,9) ;
RF24Network network(radio) ; //include the radio in the network
const uint16_t this_node=00 ;
const uint16_t node01=01;

void setup() {
 SPI.begin() ;
 radio.begin() ;
 network.begin(90,this_node) ;
  lcd.begin(16,2);

pinMode(8,OUTPUT);
pinMode(7,OUTPUT);
pinMode(6,OUTPUT);
pinMode(5,OUTPUT);
pinMode(4,OUTPUT);
pinMode(3,OUTPUT);

}

void loop() {
network.update() ;
while(network.available()){
unsigned long incomingData1 ;
RF24NetworkHeader header(node01) ;
network.read(header,&incomingData1,sizeof(incomingData1)) ;
lcd.setCursor(0,0);
lcd.print(incomingData1);
  }
}
  
  
  


