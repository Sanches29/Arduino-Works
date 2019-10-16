//Guilherme Silva Sanches     16/10/19
//Programa feito com o intuito de testar o método de Oversampling utiliado na aquisição de sinais pelo
//conversor AD do Arduino, aumentando sua resoluçao de 10 bits para 14 bits
#define ASCH1_PIN    A5
#define ASCH2_PIN    A7
void setup() {
  Serial.begin(9600);
  Serial.println("Sensor pressao ASCHROFT + oversampling");
 
}

void loop() {
  
   unsigned long ASCH1;
   unsigned long ASCH2;
   unsigned int counter;
   float pressao1;
   float pressao1c;
   float pressao2;
   float pressao2c;
   
  ASCH1=0;
  ASCH2=0;
  pressao1 = 0;
  pressao2 = 0;
  

  
  for(counter=256; counter; counter--)
   {
      ASCH1 += analogRead(ASCH1_PIN); // Faz a conversão de 256 amostras do sinal analogico  
      delay(2); // 4 * 256 é aproximadamente 1 segundo. 
      ASCH2 += analogRead(ASCH2_PIN);
      delay(2);
   }
   ASCH1 >>= 4;
   ASCH2 >>= 4;

   pressao1 = ((2540*(float)ASCH1)/16368);  
   pressao2 = ((2540*(float)ASCH2)/16368);          //talvez aumentar o range de 2540 para 2600
   


    // PRESSAO1 CALIBRADA SOFTWARE
   if(0.0f <= (float)pressao1 && (float)pressao1 <= 12.0f ){
    pressao1c = pressao1*0.0;
   }
   else if ( 12.0f <= (float)pressao1 && (float)pressao1 < 18.2f){          
    pressao1c = (float)pressao1*0.54;
   }
   else if ( 18.2f <= (float)pressao1 && (float)pressao1 < 27.3f){          
    pressao1c = (float)pressao1*0.73;
   }  
   else if ( 27.3f <= (float)pressao1 && (float)pressao1 < 37.2f){          
    pressao1c = (float)pressao1*0.80;
   }
   else if ( 37.2f <= (float)pressao1 && (float)pressao1 < 47.8f){          
    pressao1c = (float)pressao1*0.83;
   }
   else if ( 47.8f <= (float)pressao1 && (float)pressao1 < 57.0f){          
    pressao1c = (float)pressao1*0.87;
   }
   else if ( 57.0f <= (float)pressao1 && (float)pressao1 < 67.8f){          
    pressao1c = (float)pressao1*0.88;
   }
   else if ( 67.8f <= (float)pressao1 && (float)pressao1 < 77.3f){          
    pressao1c = (float)pressao1*0.90;
   }
   else if ( 77.3f <= (float)pressao1 && (float)pressao1 < 87.2f){          
    pressao1c = (float)pressao1*0.91;
   }
   else if ( 87.2f <= (float)pressao1 && (float)pressao1 < 96.9f){          
    pressao1c = (float)pressao1*0.92;
   }
   else if ( 106.3f <= (float)pressao1 && (float)pressao1 < 146.0f){          
    pressao1c = (float)pressao1*0.94;
   }
   else if ( 146.0f <= (float)pressao1 && (float)pressao1 < 187.0f){          
    pressao1c = (float)pressao1*0.95;
   }
   else if ( 187.0f <= (float)pressao1 && (float)pressao1 < 288.5f){          
    pressao1c = (float)pressao1*0.96;
   }
   else if ( 288.5f <= (float)pressao1 && (float)pressao1 < 653.6f){          
    pressao1c = (float)pressao1*0.97;
   }
   else if ( 653.6f <= (float)pressao1 && (float)pressao1 < 2490.0f){          //conferir pontos de 2540 pra trás
    pressao1c = (float)pressao1*0.98;
   }
   else if ( 2490.0f < (float)pressao1){          //conferir
    pressao1c = (float)pressao1*1.00;
   }

   //PRESSAO2 CALIBRADA SOFTWARE (VAZAO DO BOCAL) ------> PRECISA CONFIGURAR PARA MULTIPLICAR PELOS FATORES K'S DE ACORDO COM A SELEÇÃO DO BOCAL(FUNÇAO SELEÃO BOCAL
   // TERÁ DE TER SUA VARIAVEL SELEÇÃO DECLARADA COMO GLOBAL.
      if(0.0f <= (float)pressao2 && (float)pressao2 <= 12.0f ){
    pressao2c = pressao2*0.0;
   }
   else if ( 12.0f <= (float)pressao2 && (float)pressao2 < 18.2f){          
    pressao2c = (float)pressao2*0.54;
   }
   else if ( 18.2f <= (float)pressao2 && (float)pressao2 < 27.3f){          
    pressao2c = (float)pressao2*0.73;
   }  
   else if ( 27.3f <= (float)pressao2 && (float)pressao2 < 37.2f){          
    pressao2c = (float)pressao2*0.80;
   }
   else if ( 37.2f <= (float)pressao2 && (float)pressao2 < 47.8f){          
    pressao2c = (float)pressao2*0.83;
   }
   else if ( 47.8f <= (float)pressao2 && (float)pressao2 < 57.0f){          
    pressao2c = (float)pressao2*0.87;
   }
   else if ( 57.0f <= (float)pressao2 && (float)pressao2 < 67.8f){          
    pressao2c = (float)pressao2*0.88;
   }
   else if ( 67.8f <= (float)pressao2 && (float)pressao2 < 77.3f){          
    pressao2c = (float)pressao2*0.90;
   }
   else if ( 77.3f <= (float)pressao2 && (float)pressao2 < 87.2f){          
    pressao2c = (float)pressao2*0.91;
   }
   else if ( 87.2f <= (float)pressao2 && (float)pressao2 < 96.9f){          
    pressao2c = (float)pressao2*0.92;
   }
   else if ( 106.3f <= (float)pressao2 && (float)pressao2 < 146.0f){          
    pressao2c = (float)pressao2*0.94;
   }
   else if ( 146.0f <= (float)pressao2 && (float)pressao2 < 187.0f){          
    pressao2c = (float)pressao2*0.95;
   }
   else if ( 187.0f <= (float)pressao2 && (float)pressao2 < 288.5f){          
    pressao2c = (float)pressao2*0.96;
   }
   else if ( 288.5f <= (float)pressao2 && (float)pressao2 < 653.6f){          
    pressao2c = (float)pressao2*0.97;
   }
   else if ( 653.6f <= (float)pressao2 && (float)pressao2 < 2490.0f){          //conferir pontos de 2540 pra trás
    pressao2c = (float)pressao2*0.98;
   }
   else if ( 2490.0f < (float)pressao2){          //conferir
    pressao2c = (float)pressao2*1.00;
   }

   

   
  // t_lm35 = ((float)lm35*5/16384);
   Serial.println("Pressao 1");
   Serial.println(pressao1c, 1);
   Serial.println("Pressao 2");
   Serial.println(pressao2c, 1);
   

   }
