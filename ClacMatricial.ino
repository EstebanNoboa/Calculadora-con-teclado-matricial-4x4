/*
 * ........CALCULADORA CON TECLADO.........
 * NOMBRE: Esteban Noboa
 * FECHA: 29/10/2018
 */
#include <LiquidCrystal.h> //libreria para inicializar pantalla LCD
#include <Keypad.h>        //libreria para uso teclado matricial
#include <Wire.h>          //libreria que permite la comunicacion del teclado con la pantalla

LiquidCrystal lcd(13,12,11,10,9,8); //definir pines:RS E d4 d5 d6 d7

const byte COLUMNAS = 4; //declarar columnas y filas
const byte FILAS = 4; //declarar columnas y filas
char teclas [FILAS] [COLUMNAS] = {{'4','1','7','x'},{'5','2','8','-'},{'6','3','9','='},{'+','-','x','/'}}; //se da el valor dde cada tecla en la matriz
byte pinesfila[FILAS] = {3,2,1,0}; //define pines de salinas filas
byte pinescol [COLUMNAS] = {7,6,5,4}; //define pines de salinas columnas
Keypad Teclado = Keypad(makeKeymap(teclas),pinesfila,pinescol,FILAS,COLUMNAS); 

boolean inicio = false; // variable control
boolean final = false; // variable de control

String num1, num2; //variables numericas usadas en la operacion
int calTotal;
char operacion; //variable para guardar las operacion + - / * 

void setup()
{
  lcd.begin(16,2); //inicializar pantalla lcd
  lcd.setCursor(0,0); //situar la escritura en la posicion 0,0
  lcd.print("Iniciando..."); //mensaje inicial
  delay (2000); // tiempo del mensaje inicial
  lcd.clear(); //limpiar pantalla
}

void loop()
{
  char key = Teclado.getKey(); 
  
  if (key != NO_KEY && (key=='1' || key=='2' || key=='3' || key=='4' || key=='5' || key=='6' || key=='7' || key=='8' || key=='9' || key=='0')) //comprobar si se presiona teclas correctamente
  {
    if(inicio == false){ //suma
      num1 = num1 + key; //suma con las variables obtenidas antes
      int numLength = num1.length(); //obtener posicion en la panatalla lcd de la suma
      lcd.setCursor(15-numLength,0); //posicionar el resultado
      lcd.print(num1);  //impresion del resultado
  }
     else {
      num2 = num2 + key;
      int numLength = num2.length();
      lcd.setCursor(15-numLength,1);
      lcd.print(num2);
      final = true;
  }
}

if (inicio == false && key != NO_KEY && (key == '+' || key == '-' || key == 'x' || key == '/')){ //correcto uso de las operaciones
  inicio = true; //variable control
 operacion = key; //se guarda en la variable operacion
 lcd.setCursor(15,0); //se pide escribir en la posicion 15,0
 lcd.print (operacion); 

}
if (final == true && key !=NO_KEY && key == '=')
{
    if (operacion == '+')
    {calTotal= num1.toInt() + num2.toInt();} //suma
    if (operacion == '-')
    {calTotal= num1.toInt() - num2.toInt();} //resta
    if (operacion == 'x')
    {calTotal= num1.toInt() * num2.toInt();} // multiplicacion
    if (operacion == '/')
    {calTotal= num1.toInt() / num2.toInt();} //division
    
    lcd.clear(); //limpiar cursor
    lcd.setCursor(15,0); 
    lcd.autoscroll();
    lcd.print(calTotal);
    lcd.noAutoscroll();    
}
}

