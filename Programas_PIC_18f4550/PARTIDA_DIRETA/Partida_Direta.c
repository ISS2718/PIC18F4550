/*
 São Paulo, 22 de março de 2018.
 Programa: PARTIDA_DIRETA.
 Versão: 1.0
 Concluida em: 23/03/18
 Autor: Isaac Soares
 
 Clock: 48000Mhz
 Dispositivo: PIC18F4550

 Descrição de funcionamento:

 Este programa tem a função de fazer uma partida
 direta.
 Tem um botão de emergência, um de desligar
 e um de ligar. Os botões tem prioridades a serem
 respeitadas, onde o botão de emergência tem prioridade
 acima de todos os outros botões desligando o sistema a
 "força", depois dele vem o botão de desligar onde se o
 botão for precionado e o circuito estiver funcionando
 será ele será desligado, e o botão de ligar que liga o
 circuito se o btão de emergencia não tiver sido precionado.

 Lista de alocação:

PINO    NOME      Função              Apelido
        
33      RB0       Entrada digital     L(Ligar)
34      RB1       Entrada digital     D(Desligar)
35      RB2       Entrada digital     E(Emergencia)
15      RC0       Saida   digital     VM(LED Vermelho)
16      RC1       Saida   digital     VD(LED VERDE)
25      RC6       Saida   digital     AM(LED AMARELO)
26      RC7       Saida   digital     MT(Motor)

*/
        #pragma orgal 0x1000
        #define L (Button(&PORTB, 0, 50, 0)) //Define rb0 com a função de button em pull up e o apelido de L
        #define D (Button(&PORTB, 1, 50, 0)) //Define rb1 com a função de button em pull up e o apelido de D
        #define E (Button(&PORTB, 2, 50, 0)) //Define rb2 com a função de button em pull up e o apelido de E
        #define VM rc0_bit  //Coloca o apelido no rc0 de VM
        #define VD rc1_bit  //Coloca o apelido no rc1 de VD
        #define AM rc6_bit  //Coloca o apelido no rc6 de AM
        #define MT rc7_bit  //Coloca o apelido no rc7 de MT
        int trava;  // Cria uma variavel do tipo inteiro com apelido de trava
        void main (void) org 0x1000
        { //Início do programa
         trisb=0xff; //Define os pinos rb como entrada
         trisc=0x00; //Define os pinos rc como saida
         portc=0x00; //Define as saidas como nivel baixo
         trava=0; //Coloca o valor 0 na varialvel trava
         
         while(1) //Loop Infinito (enquanto 1 for verdadeiro)
         { // Início do Loop
          if(E) //Se E for verdadeiro
          {
           VM=0; //Led Vermelho apagado
           VD=0; //Led Verde apagado
           MT=0; //Motor desligado
           AM=~AM; //Amarelo mudando seu estado
           delay_ms(100); //Dá um intervalo para repetir os camandos
          }
          if(((D)||(trava==0))&&(!E)) //Se D for verdadeiro ou trava igual a 0 e E for falso
          {
           trava=0; //Define trava como 0
           MT=0;
           VM=0;
           VD=1; //Led Verde aceso
           AM=0; //Amarelo apagado
          }
          if((((L)||(trava==1))&&(D==0))&&(!E)) //Se D for verdadeiro ou trava igual a 1 e E for falso
          {
           trava=1; //Define trava como 1
           MT=1; //Motor ligado
           VM=1; //Led Vermelho aceso
           VD=0;
           AM=0;
          }
         } //Fim do Loop Infinito
        } //Fim do Progrma