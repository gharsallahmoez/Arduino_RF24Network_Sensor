#include <RF24.h> 
#include<RF24Network.h>
#include<SPI.h> 
float vol;
 float temp ;
RF24 radio(10,9) ;
RF24 Network network(radio) ; //include the radio in the network
const unit16_t this_node=10 ;
const unit16_t node00=00;
void setup() {
 SPI.begin() ;
 radio.begin() ;
 network.begin(90,this_node) ;
}

void loop() {
  network.update() ;
vol=analogRead(A0);
temp=vol*500/1023;
RF24NetworkHeader header(node00) ;
bool ok=network.write(header,&angeValue,sizeof(angeValue)) ; //send the data
}