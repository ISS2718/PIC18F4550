/*
São Paulo, 08 de Março de 2018
*/
          #pragma orgall 0x1000
          #define A (Button(&PORTB, 0, 50, 0))
          #define B (Button(&PORTB, 1, 50, 0))
          #define S rc0_bit
          void main (void) org 0x1000
          {
          trisb=0xff;
          trisc=0x00;
          portc=0x00;
          while(1)
          {
          /*if((A)&&(B)) // AND
          {
          S=1;
          }
          else
          S=0;*/
          /*if(!((A)&&(B))) // NAND
          {
          S=1;
          }
          else
          S=0;*/
          if((A)||(B)) // OR
          {
          S=1;
          }
          else
          S=0;
          /*if(!((A)||(B))) // NOR
          {
          S=1;
          }
          else
          S=0;*/
          /*if(!A) NOT
          {
          S=1;
          }
          else
          S=0;*/
          /*if((A)^(B)) // XOR
          {
          S=1;
          }
          else
          S=0;*/
          /*if(!((A)^(B))) // XNOR
          {
          S=1;
          }
          else
          S=0;*/



 }
}