//    http://www.fibidi.com/?p=734
#include "ArduinoProject.h"
#include <stdio.h>
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8,9,4,5,6,7);
void setup() {
  //Inicializando o LCD e informando o tamanho de 16 colunas e 2 linhas
  //que é o tamanho do LCD JHD 162A usado neste projeto.
  lcd.begin(16, 2);
}
 
void loop() {
  lcd.clear();          //limpa o display do LCD.    
  lcd.print("Oi!!! ");  //imprime a string no display do LCD.
  delay(2000);                
   
  lcd.setCursor(0,1);   //posiciona cursor na coluna 0 linha 1 do LCD
  lcd.print("Tudo Bem???"); //imprime a string no display do LCD.
  delay(2000);   
   
  lcd.clear();
  lcd.print("Quer aprender");
  lcd.setCursor(0,1);
  lcd.print("este projeto?");
  delay(4000);
   
  lcd.clear();
  lcd.print("www.ComoFazerAsCoisas.com.br");
  delay(1000);
   
  //Rolando o display para a esquerda 12 vezes
  for (int i = 0; i < 12; i++) {
    lcd.scrollDisplayLeft();
    delay(600);
  }
   
  delay(1000);
}