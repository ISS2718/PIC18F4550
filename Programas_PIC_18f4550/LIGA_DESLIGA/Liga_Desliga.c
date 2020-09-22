
#pragma orgall 0x1000
#define BOT (Button (&PORTB,0,50,0))
#define LED RC0_bit
bit flag;
        void main (void) org 0x1000
        {
         trisb0_bit=1;
         trisc0_bit=0;
         while(1)
         {
          if((BOT)&&(flag==0)) // Começa ligado{
          {
           LED=~LED;
           flag=1;
          }
          if((!BOT)&&(flag==1))
          {
           flag=0;
          }                   // }
           /*if((!BOT)&&(flag==0)) // Começa desligado{
          {
           LED=~LED;
           flag=1;
          }
          if((BOT)&&(flag==1))
          {
           flag=0;
          }  */                 // }
         }
        }