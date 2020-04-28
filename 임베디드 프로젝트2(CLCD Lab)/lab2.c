#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <wiringPi.h>
#define LCD_RS 7
#define LCD_EN 0
#define LCD_D4 2
#define LCD_D5 3
#define LCD_D6 1
#define LCD_D7 4
#define PORT_0 12
#define PORT_1 13
#define PORT_2 14
#define PORT_3 21
#define PORT_4 22
#define PORT_5 23
#define PORT_6 24
#define PORT_7 27
#define PORT_8 26
#define PORT_9 11
#define PORT_10 10
#define PORT_BUTTON1 5
#define PORT_BUTTON2 6
void write4bits(unsigned char command)
{
   digitalWrite(LCD_D4, (command & 1));
   command >>=1;
   digitalWrite(LCD_D5, (command & 1));
   command >>=1;
   digitalWrite(LCD_D6, (command & 1));
   command >>=1;
   digitalWrite(LCD_D7, (command & 1));
   digitalWrite(LCD_EN, 1);
   delayMicroseconds(50);
   digitalWrite(LCD_EN, 0);
   delayMicroseconds(50);
}

void sendDataCmd4(unsigned char data)
{
   write4bits( ((data>>4)&0x0f) );
   write4bits( (data&0x0f) );
}

void putCmd4(unsigned char cmd)
{
    digitalWrite(LCD_RS, 0);
    sendDataCmd4(cmd);
}

void putChar(char c){	 
  digitalWrite(LCD_RS, 1);
  sendDataCmd4(c);
}


void initialize_textlcd(){	
      digitalWrite(LCD_RS, 0);      pinMode(LCD_RS, OUTPUT);
      digitalWrite(LCD_EN, 0);      pinMode(LCD_EN, OUTPUT);
      digitalWrite(LCD_D4, 0);      pinMode(LCD_D4, OUTPUT);
      digitalWrite(LCD_D5, 0);      pinMode(LCD_D5, OUTPUT);
      digitalWrite(LCD_D6, 0);      pinMode(LCD_D6, OUTPUT);
      digitalWrite(LCD_D7, 0);      pinMode(LCD_D7, OUTPUT);
      delay(35); 

      putCmd4(0x28);
      putCmd4(0x28);
      putCmd4(0x28);
	putCmd4(0x0e); 
	putCmd4(0x02); 
        delay(2);
	putCmd4 (0x01); 
	delay(2);
        pinMode(PORT_BUTTON1, INPUT);
        pullUpDnControl(PORT_BUTTON1, PUD_UP);
        pinMode(PORT_BUTTON2, INPUT);
       pullUpDnControl(PORT_BUTTON2, PUD_UP);       
}


int main(int argc, char **argv){
        
      wiringPiSetup();
      initialize_textlcd();
      
        pinMode(PORT_0,INPUT); 
        pinMode(PORT_1, INPUT);
        pinMode(PORT_2, INPUT);
        pinMode(PORT_3, INPUT);
       pinMode(PORT_4, INPUT);
       pinMode(PORT_5, INPUT);
       pinMode(PORT_6, INPUT);
       pinMode(PORT_7, INPUT);
       pinMode(PORT_8, INPUT);
       pinMode(PORT_9, INPUT);
       pinMode(PORT_10, INPUT);
       pullUpDnControl(PORT_5, PUD_UP);
       pullUpDnControl(PORT_10, PUD_UP); 
        delay(38); 
       int max = 0;
       long long number = 0;
       long long sum=0;
       int f= 0;
       int f1=0;
      while(1) {
       while(1){
          delay(1);
         int flag2= 0;
         while(1){
          if (flag2==1)
              break;
   if(!digitalRead(PORT_0) || !digitalRead(PORT_1) || !digitalRead(PORT_2) || !digitalRead(PORT_3) || !digitalRead(PORT_4) || !digitalRead(PORT_5) || !digitalRead(PORT_6) || !digitalRead(PORT_7) || !digitalRead(PORT_8) || !digitalRead(PORT_9) || !digitalRead(PORT_BUTTON2) || !digitalRead(PORT_BUTTON1) || !digitalRead(PORT_10)) {
           flag2 = 1;
       }
        
        }

       
        if (!digitalRead(PORT_0)){
            number = number *10;
            number = number +0;
            if (max ==16){ 
               putCmd4(0xC0);
            }
             putChar('0');
             max++;
            
          }
        if (!digitalRead(PORT_1)) { 
             number = number*10;
            number = number +1;
             if(max==16) {
                putCmd4(0xC0);
              
           }    
             putChar('1');
             max++;     
          }
       
        if (!digitalRead(PORT_2)){
              number = number*10;
              number = number +2;
              if (max==16){
               putCmd4(0xC0);
             }
              putChar('2');
              max++;
             }
          

        if (!digitalRead(PORT_3)){
              number = number*10;
              number = number +3;
               if(max==16){
               putCmd4(0xC0);
               }
               putChar('3');
               max++;
            }
           
        if (!digitalRead(PORT_4)){ 
               
              number = number*10;
              number = number +4;
               if(max==16){
               putCmd4(0xC0);
               }
               putChar('4');
               max++;
             }
        if(!digitalRead(PORT_5)){
              number = number*10;
              number = number +5;
             if(max==16) {
                putCmd4(0xC0);
              }
             putChar('5');
             max++;
            }
        if(!digitalRead(PORT_6)){
              number = number*10;
              number = number +6;
            if (max==16){
                putCmd4(0xC0);
             }
              putChar('6'); 
               max++;
            }
        if(!digitalRead(PORT_7)){
              number = number*10;
              number = number +7;
             if (max==16){
                 putCmd4(0xC0);

             }
              putChar('7');
              max++;
              }
         if(!digitalRead(PORT_8)){
              number = number*10;
              number = number +8;
             if( max==16) {
                putCmd4(0xC0);
               }
                 putChar('8');
                  max++;

                }
         if(!digitalRead(PORT_9)) {
              number = number*10;
              number = number +9;
                if (max==16) {
                  putCmd4(0xC0);
                  }
               putChar('9');
                  max++;
                  }
        if(!digitalRead(PORT_10)){
                  if(max==16) {
                   putCmd4(0xC0);
                    }
                putChar('=');
                     max++;
                  if (f==0 && f1==0) {
                       sum = number;
                  }
                  else if (f==1) {
                        sum = sum+number;
                    }
                else if ( f1==1) {
                        sum = sum-number;
                   }
                  char buf[200];
                  sprintf(buf,"%lld", sum);
                  int a= strlen(buf);
                  int i1;
                   if (a+max >= 32) {
                    initialize_textlcd();
                     max = 0;
                     putChar('='); 
                    }  
                  for ( i1=0; i1<a; i1++){
                      if (max ==16){
                         putCmd4(0xC0);
                      }
                  
                      putChar(buf[i1]); 
                      max = max+1;
                     }
                  delay(300);
                  break;
               }
        if(!digitalRead(PORT_BUTTON1)){
                  if(max==16) {
                    putCmd4(0xC0);
                   }
                  putChar('+');
                     max++;
                  if (f==0 && f1==0){
                       sum = number;
                        number = 0;
                   }
                   else if (f==1){
                   sum = sum+number;
                         number = 0;
                    }
                   else if (f1==1){
                     sum = sum -number;
                    number = 0;
                    }
                    f=1;
                    f1=0;
         }
       if(!digitalRead(PORT_BUTTON2)) {
                 if(max==16) {
                   putCmd4(0xC0);
                  }
                 putChar('-');
                    max++;
                  if (f==0 && f1==0) {
                     sum = number;
                     number = 0;
                    }
                   else if (f==1) { 
                      sum = sum + number; 
                        number = 0;
                        }
                  else if (f1==1){
                       sum = sum - number;
                            number = 0;
                      }

              
                f=0; 
                  f1= 1;
         }
         delay(275);
         }
       int flag = 0; 
        sum = 0;
        f=0;
       f1 =0;
       number = 0;
       max= 0; 

   while(1) {
    if (flag == 1)
      break; 
    delay(38); 
   if(!digitalRead(PORT_0) || !digitalRead(PORT_1) || !digitalRead(PORT_2) || !digitalRead(PORT_3) || !digitalRead(PORT_4) || !digitalRead(PORT_5) || !digitalRead(PORT_6) || !digitalRead(PORT_7) || !digitalRead(PORT_8) || !digitalRead(PORT_9) || !digitalRead(PORT_BUTTON2)) {
           flag = 1;
       }
          
}    
        if (flag==1) {
        initialize_textlcd(); 
        continue;         
     }
   
}
     
}



