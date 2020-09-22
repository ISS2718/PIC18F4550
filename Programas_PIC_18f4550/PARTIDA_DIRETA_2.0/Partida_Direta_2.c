        #pragma orgall 0x1000
        #define EM (Button(&PORTB,0,50,0))
        #define STOP (Button(&PORTB,1,50,0))
        #define START (Button(&PORTB,2,50,0))
        #define LED_Y rc0_bit
        #define LED_G rc1_bit
        #define LED_R rc6_bit
        #define MOTOR rc7_bit
        bit flag;
        void main(void)org 0x1000
        {
        trisb=0xff;
        trisb=0x00;
        portc=0x00;
        while(1)
        {
        if(EM)
        {
        MOTOR=0;
        LED_R=0;
        LED_G=0;
        LED_Y=~LED_Y;
        flag=1;
        delay_ms(200);
        }
        else
        if((!EM)&&(STOP))
        {
        MOTOR=0;
        LED_R=0;
        LED_G=1;
        LED_Y=0;
        }
        else
        if((!EM)&&(!STOP)&&(START))
        {
        MOTOR=1;
        LED_R=1;
        LED_G=0;
        LED_Y=0;
        }
        else
        if((!EM)&&(!STOP)&&(!START)&&(flag==1))
        {
        MOTOR=0;
        LED_R=0;
        LED_G=1;
        LED_Y=0;
        flag=0;
        }
        }
        }
        