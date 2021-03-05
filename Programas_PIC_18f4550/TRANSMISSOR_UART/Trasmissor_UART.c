#pragma orgall 0x1000

#define snd rd0_bit
#define inc rd1_bit
#define dec rd2_bit

char cnt = 0;
char flag = 0;

void dcb(char n);

void main(void) org 0x1000
{
    TRISB = 0xF0;
    
    PORTB = 0x00;
    delay_ms(500);
    PORTB = 0x0F;
    delay_ms(500);
    PORTB = 0x00;
    
    TRISD = 0X07;
    
    while(1)
    {
      if(inc && cnt < 15 && flag == 0)
      {
        cnt++;
        dcb(cnt);
        flag = 1;
        delay_ms(2000);
      }

      if(dec && cnt > 0)
      {
        cnt--;
        dcb(cnt);
        flag = 1;
        delay_ms(2000);
      }

      flag = 0;
    }


}

void dcb(char n)
{
  switch (n)
  {
    case 0:
      rb3_bit = 0;
      rb2_bit = 0;
      rb1_bit = 0;
      rb0_bit = 0;
    break;
  
    case 1:
      rb3_bit = 0;
      rb2_bit = 0;
      rb1_bit = 0;
      rb0_bit = 1;
    break;

    case 2:
      rb3_bit = 0;
      rb2_bit = 0;
      rb1_bit = 1;
      rb0_bit = 0;
    break;

    case 3:
      rb3_bit = 0;
      rb2_bit = 0;
      rb1_bit = 1;
      rb0_bit = 1;
    break;
    
    case 4:
      rb3_bit = 0;
      rb2_bit = 1;
      rb1_bit = 0;
      rb0_bit = 0;
    break;

    case 5:
      rb3_bit = 0;
      rb2_bit = 1;
      rb1_bit = 0;
      rb0_bit = 1;
    break;

    case 6:
      rb3_bit = 0;
      rb2_bit = 1;
      rb1_bit = 1;
      rb0_bit = 0;
    break;

    case 7:
      rb3_bit = 0;
      rb2_bit = 1;
      rb1_bit = 1;
      rb0_bit = 1;
    break;
  
    case 8:
      rb3_bit = 1;
      rb2_bit = 0;
      rb1_bit = 0;
      rb0_bit = 0;
    break;

    case 9:
      rb3_bit = 1;
      rb2_bit = 0;
      rb1_bit = 0;
      rb0_bit = 1;
    break;

    case 10:
      rb3_bit = 1;
      rb2_bit = 0;
      rb1_bit = 1;
      rb0_bit = 0;
    break;

    case 11:
      rb3_bit = 1;
      rb2_bit = 0;
      rb1_bit = 1;
      rb0_bit = 1;
    break;

    case 12:
      rb3_bit = 1;
      rb2_bit = 1;
      rb1_bit = 0;
      rb0_bit = 0;
    break;

    case 13:
      rb3_bit = 1;
      rb2_bit = 1;
      rb1_bit = 0;
      rb0_bit = 1;
    break;

    case 14:
      rb3_bit = 1;
      rb2_bit = 1;
      rb1_bit = 1;
      rb0_bit = 0;
    break;

    case 15:
      rb3_bit = 1;
      rb2_bit = 1;
      rb1_bit = 1;
      rb0_bit = 1;
    break;
  }
}