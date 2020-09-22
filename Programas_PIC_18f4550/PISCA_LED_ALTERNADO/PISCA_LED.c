/*

*/
  #pragma orgall 0x1000
  #define LED0 ra4_bit
  #define LED1 ra5_bit
  void main (void) org 0x1000{
   trisa4_bit = 0;
   trisa5_bit = 0;
   
   while(1){
    LED0 = 0;
    LED1 = 0;
    delay_ms(200);
    LED0 = 0;
    LED1 = 1;
    delay_ms(200);
    LED0 = 1;
    LED1 = 0;
    delay_ms(200);
    LED0 = 1;
    LED1 = 1;
    delay_ms(200);
    
   
   }
 }