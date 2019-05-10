
byte PIN_KEYPAD = A0; // may be changed to any analog pin
int val; 
char key;

char keypress()
{
  char k = NULL;
  val = 0;
  for(byte i=0;i<10;i++)
  {
      val += analogRead(PIN_KEYPAD);
  }
  val/=10;
  
  //Serial.println(val);  //Uncomment to show raw values

 // the integer values here may be edited according to your specific devices.
  if(val>=1018 && val<= 1023) k = '1';
  else if(val>=926 && val<= 930) k = '2';
  else if(val>=848 && val<= 852) k = '3';  
  else if(val>=782 && val<= 788) k = 'A';  
  else if(val>=782 && val<= 788) k = 'A';   
  else if(val>=680 && val<= 699) k = '4';   
  else if(val>=648 && val<= 654) k = '5';    
  else if(val>=608 && val<= 615) k = '6'; 
  else if(val>=574 && val<= 582) k = 'B'; 
  else if(val>=519 && val<= 529) k = '7';
  else if(val>=497 && val<= 505) k = '8';  
  else if(val>=474 && val<= 481) k = '9';  
  else if(val>=455 && val<= 460) k = 'C';   
  else if(val>=420 && val<= 426) k = '*';   
  else if(val>=403 && val<= 411) k = '0';    
  else if(val>=387 && val<= 395) k = '#'; 
  else if(val>=373 && val<= 380) k = 'D';   

  return k;
}


void setup() {
  Serial.begin(115200);
}

void loop() {
  key = keypress(); // pass here as frequent as possible
  if(key) Serial.println(key); // if a key is pressed (key is not Null), then print on Serial monitor
}
