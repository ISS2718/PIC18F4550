/*============================================================================\\
São Paulo, 15 de julho de 2018.
Programa: Contador
Versão: 4.0
Autor: Isaac Santos Soares
Conclusão:
 
Clock: 20MHz
Dispositivo: 18F4550

Descrição de Funcionamento:



Lista de alocação:

Terminal  Nome   Função    Apelido







//============================================================================*/

#pragma orgal 0x1000

//---Variáveis Globais---\\
  
  int trava,uni,dez,cen,valc;
  
//---Protótipos das Funções---\\
  
  void contador(void);
  void setup(void);
//---#define---\\
  
  #define sen rc0_bit
  #define b1  rc1_bit
  #define b2  rc2_bit
  #define b3  rc4_bit
  #define le1 rb0_bit
  #define le2 rb1_bit
  #define le3 rb2_bit
  #define a   rd0_bit
  #define b   rd1_bit
  #define c   rd2_bit
  #define d   rd3_bit
  #define lt  rd4_bit
  #define bi1 rd5_bit
  #define bi2 rd6_bit
  #define bi3 rd7_bit

//============================================================================\\
        
        void main(void) org 0x1000
         {
         
           setup();// chama a função setup
           contador();// chama função contador
           
          while (1)
          {
            
            if(b1)
              {

                valc=1;

               }
             if(b2)
              {

                valc=2;

               }

             if(b3)
              {

               valc=3;

               }

            if((sen)&&(trava==0))
              {

                uni= uni+valc;
                trava=1;
                contador();// chama função contador
                delay_ms(1000);

               }
             if((!sen)&&(trava==1))
              {

                trava=0;

               }
           
           }
           
          }
         
         void setup(void)
          {
          
           //---Variáveis Locais--\\


            
           //---Inicializção das Variáveis---\\

             trava=0;
             uni=0;
             dez=0;
             cen=0;
             valc=2;

           //=================================================================\\
           
           //---Inicialização das I/O---\\
           
            trisb=0x0F;
            trisc=0x00;
            trisd=0x00;
            portb=0x00;
            portc=0x00;
            portd=0x00;
           //---------------------------\\
           
           //Teste dos Segmentos dos Displays---\\
           
            lt=1;// desliga teste
            delay_ms(500);
            lt=0;// liga teste
            delay_ms(500);
            lt=1;// Desliga teste

           //-----------------------------------\\

           //---iniciação dos Displays---\\
           
            bi1=1;// liga dispaly da unidade
            bi2=1;// liga dispaly da dezena
            bi3=1;// liga dispaly da centena
            
            le1=0;// Abilita leitura para o dispaly da unidade
            le2=0;// Abilita leitura para o dispaly da dezena
            le3=0;// Abilita leitura para o dispaly da centena
            
           //----------------------------\\
           
           //---Teste de contagem---\\
           
           // Mostra 0 em todos displays
            a=0;
            b=0;
            c=0;
            d=0;
            delay_ms(250);

           // Mostra 1 em todos displays
            a=1;
            b=0;
            c=0;
            d=0;
            delay_ms(250);

           // Mostra 2 em todos displays
            a=0;
            b=1;
            c=0;
            d=0;
            delay_ms(250);

           // Mostra 3 em todos displays
            a=1;
            b=1;
            c=0;
            d=0;
            delay_ms(250);

           // Mostra 4 em todos displays
            a=0;
            b=0;
            c=1;
            d=0;
            delay_ms(250);

           // Mostra 5 em todos displays
            a=1;
            b=0;
            c=1;
            d=0;
            delay_ms(250);

           // Mostra 6 em todos displays
            a=1;
            b=0;
            c=1;
            d=0;
            delay_ms(250);
            
           // Mostra 7 em todos displays
            a=1;
            b=1;
            c=1;
            d=0;
            delay_ms(250);

           // Mostra 8 em todos displays
            a=0;
            b=0;
            c=0;
            d=1;
            delay_ms(250);

           // Mostra 9 em todos displays
            a=1;
            b=0;
            c=0;
            d=1;
            delay_ms(250);

           //-----------------------\\

           //---Seta todos os prot como 0---\\
           
            portd=0x00;
            portc=0x00;
            portb=0x00;
           //-------------------------------\\
           
            lt=1;// desliga teste
            le1=1;// congela display da unidade
            le2=1;// congela display da dezena
            le3=1;// congela display da centena
            
            return;// retorna a função principal
           }
           
          void contador(void)
           {
               
             if(uni>9)
              {
              
               dez=dez+1;
               uni=uni-10;
               }

             if(dez>9)
              {
              
               cen=cen+1;
               dez=dez-10;
              
               }
              if(cen>9)
               {
               
                uni=0;
                dez=0;
                cen=0;
               
               }
               
             switch (uni)
              {
               case 0:
               
                bi1=1;// liga display da unidade

                le1=0;// abilita leitura da unidade
                le2=1;// congela display da dezena
                le3=1;// congela display da centena

                //Mostra 0 no display
                a=0;
                b=0;
                c=0;
                d=0;

                le1=1;// congela display da unidade

               break;

               case 1:

                bi1=1;// liga display da unidade

                le1=0;// abilita leitura da unidade
                le2=1;// congela display da dezena
                le3=1;// congela display da centena

                //Mostra 1 no display
                a=1;
                b=0;
                c=0;
                d=0;

                le1=1;// congela display da unidade

               break;

               case 2:

                bi1=1;// liga display da unidade

                le1=0;// abilita leitura da unidade
                le2=1;// congela display da dezena
                le3=1;// congela display da centena

                //Mostra 2 no display
                a=0;
                b=1;
                c=0;
                d=0;

                le1=1;// congela display da unidade

               break;

               case 3:

                bi1=1;// liga display da unidade

                le1=0;// abilita leitura da unidade
                le2=1;// congela display da dezena
                le3=1;// congela display da centena

                //Mostra 3 no display
                a=1;
                b=1;
                c=0;
                d=0;

                le1=1;// congela display da unidade

               break;

               case 4:

                bi1=1;// liga display da unidade

                le1=0;// abilita leitura da unidade
                le2=1;// congela display da dezena
                le3=1;// congela display da centena

                //Mostra 4 no display
                a=0;
                b=0;
                c=1;
                d=0;

                le1=1;// congela display da unidade

               break;

               case 5:

                bi1=1;// liga display da unidade

                le1=0;// abilita leitura da unidade
                le2=1;// congela display da dezena
                le3=1;// congela display da centena

                //Mostra 5 no display
                a=1;
                b=0;
                c=1;
                d=0;

                le1=1;// congela display da unidade

               break;

               case 6:

                bi1=1;// liga display da unidade

                le1=0;// abilita leitura da unidade
                le2=1;// congela display da dezena
                le3=1;// congela display da centena

                //Mostra 6 no display
                a=0;
                b=1;
                c=1;
                d=0;

                le1=1;// congela display da unidade

               break;

               case 7:

                bi1=1;// liga display da unidade

                le1=0;// abilita leitura da unidade
                le2=1;// congela display da dezena
                le3=1;// congela display da centena

                //Mostra 7 no display
                a=1;
                b=1;
                c=1;
                d=0;

                le1=1;// congela display da unidade

               break;

               case 8:

                bi1=1;// liga display da unidade

                le1=0;// abilita leitura da unidade
                le2=1;// congela display da dezena
                le3=1;// congela display da centena

                //Mostra 8 no display
                a=0;
                b=0;
                c=0;
                d=1;

                le1=1;// congela display da unidade

               break;

               case 9:

                bi1=1;// liga display da unidade

                le1=0;// abilita leitura da unidade
                le2=1;// congela display da dezena
                le3=1;// congela display da centena

                //Mostra 9 no display
                a=1;
                b=0;
                c=0;
                d=1;

                le1=1;// congela display da unidade

               break;
               }
              
             switch (dez)
              {
               case 0:
                if(cen<=0)
                 {
                  bi2=0;// desliga display da dezena

                  le1=1;// congela leitura da unidade
                  le2=1;// congela display da dezena
                  le3=1;// congela display da centena
                  }
                else
                 
                 bi2=1;// liga display da dezena

                 le1=1;// congela leitura da unidade
                 le2=0;// abilita display da dezena
                 le3=1;// congela display da centena
                 
                 // Mostra 0 no display
                 a=0;
                 b=0;
                 c=0;
                 d=0;
                 
                 le2=1;// congela display da dezena
                 
               break;
               
               case 1:

                bi2=1;// liga display da dezena

                le1=1;// congela display da unidade
                le2=0;// abilita leitura da dezena
                le3=1;// congela display da centena

                //Mostra 1 no display
                a=1;
                b=0;
                c=0;
                d=0;

                le2=1;// congela display da dezena

               break;

               case 2:

                bi2=1;// liga display da dezena

                le1=1;// congela display da unidade
                le2=0;// abilita leitura da dezena
                le3=1;// congela display da centena

                //Mostra 2 no display
                a=0;
                b=1;
                c=0;
                d=0;

                le2=1;// congela display da dezena

               break;

               case 3:

                bi2=1;// liga display da dezena

                le1=1;// congela display da unidade
                le2=0;// abilita leitura da dezena
                le3=1;// congela display da centena

                //Mostra 3 no display
                a=1;
                b=1;
                c=0;
                d=0;

                le2=1;// congela display da dezena

               break;

               case 4:

                bi2=1;// liga display da dezena

                le1=1;// congela display da unidade
                le2=0;// abilita leitura da dezena
                le3=1;// congela display da centena

                //Mostra 4 no display
                a=0;
                b=0;
                c=1;
                d=0;

                le2=1;// congela display da dezena

               break;

               case 5:

                bi2=1;// liga display da dezena

                le1=1;// congela display da unidade
                le2=0;// abilita leitura da dezena
                le3=1;// congela display da centena

                //Mostra 5 no display
                a=1;
                b=0;
                c=1;
                d=0;

                le2=1;// congela display da dezena

               break;

               case 6:

                bi2=1;// liga display da dezena

                le1=1;// congela display da unidade
                le2=0;// abilita leitura da dezena
                le3=1;// congela display da centena

                //Mostra 6 no display
                a=0;
                b=1;
                c=1;
                d=0;

                le2=1;// congela display da dezena

               break;

               case 7:

                bi2=1;// liga display da dezena

                le1=1;// congela display da unidade
                le2=0;// abilita leitura da dezena
                le3=1;// congela display da centena

                //Mostra 7 no display
                a=1;
                b=1;
                c=1;
                d=0;

                le2=1;// congela display da dezena

               break;

               case 8:

                bi2=1;// liga display da dezena

                le1=1;// congela display da unidade
                le2=0;// abilita leitura da dezena
                le3=1;// congela display da centena

                //Mostra 8 no display
                a=0;
                b=0;
                c=0;
                d=1;

                le2=1;// congela display da dezena

               break;

               case 9:

                bi2=1;// liga display da dezena

                le1=1;// congela display da unidade
                le2=0;// abilita leitura da dezena
                le3=1;// congela display da centena

                //Mostra 9 no display
                a=1;
                b=0;
                c=0;
                d=1;

                le2=1;// congela display da dezena

               break;
               }
               
             switch (cen)
              {
               case 0:

                bi3=0;// desliga display da centena

                le1=1;// congela display da unidade
                le2=1;// congela display da dezena
                le3=1;// congela display da centena

               break;
               
               case 1:

                bi3=1;// liga display da centena

                le1=1;// congela display da unidade
                le2=1;// congela display da dezena
                le3=0;// abilita leitura da centena

                //Mostra 1 no display
                a=1;
                b=0;
                c=0;
                d=0;

                le3=1;// congela display da centena

               break;

               case 2:

                bi3=1;// liga display da centena

                le1=1;// congela display da unidade
                le2=1;// congela display da dezena
                le3=0;// abilita leitura da centena

                //Mostra 2 no display
                a=0;
                b=1;
                c=0;
                d=0;

                le3=1;// congela display da centena

               break;

               case 3:

                bi3=1;// liga display da centena

                le1=1;// congela display da unidade
                le2=1;// congela display da dezena
                le3=0;// abilita leitura da centena

                //Mostra 3 no display
                a=1;
                b=1;
                c=0;
                d=0;

                le3=1;// congela display da centena

               break;

               case 4:

                bi3=1;// liga display da centena

                le1=1;// congela display da unidade
                le2=1;// congela display da dezena
                le3=0;// abilita leitura da centena

                //Mostra 4 no display
                a=0;
                b=0;
                c=1;
                d=0;

                le3=1;// congela display da centena

               break;

               case 5:

                bi3=1;// liga display da centena

                le1=1;// congela display da unidade
                le2=1;// congela display da dezena
                le3=0;// abilita leitura da centena

                //Mostra 5 no display
                a=1;
                b=0;
                c=1;
                d=0;

                le3=1;// congela display da centena

               break;

               case 6:

                bi3=1;// liga display da centena

                le1=1;// congela display da unidade
                le2=1;// congela display da dezena
                le3=0;// abilita leitura da centena

                //Mostra 6 no display
                a=0;
                b=1;
                c=1;
                d=0;

                le3=1;// congela display da centena

               break;

               case 7:

                bi3=1;// liga display da centena

                le1=1;// congela display da unidade
                le2=1;// congela display da dezena
                le3=0;// abilita leitura da centena

                //Mostra 7 no display
                a=1;
                b=1;
                c=1;
                d=0;

                le3=1;// congela display da centena

               break;

               case 8:

                bi3=1;// liga display da centena

                le1=1;// congela display da unidade
                le2=1;// congela display da dezena
                le3=0;// abilita leitura da centena

                //Mostra 8 no display
                a=0;
                b=0;
                c=0;
                d=1;

                le3=1;// congela display da centena

               break;

               case 9:

                bi3=1;// liga display da centena

                le1=1;// congela display da unidade
                le2=1;// congela display da dezena
                le3=0;// abilita leitura da centena

                //Mostra 9 no display
                a=1;
                b=0;
                c=0;
                d=1;

                le3=1;// congela display da centena

               break;
               }
             return;
            }