#include <LiquidCrystal.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// Definindo os pinos do LCD
//LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
LiquidCrystal_I2C lcd(0x27, 16, 2); 
/*
- Botão A (Cima/Up): Digital 2 (D2)
- Botão B (Direita/Right): Digital 3 (D3)
- Botão C (Baixo/Down): Digital 4 (D4)
- Botão D (Esquerda/Left): Digital 5 (D5)
- Botão E: Digital 6 (D6)
- Botão F: Digital 7 (D7)
- Botão do Joystick (Select/Z): Geralmente também utiliza um dos pinos acima ou está mapeado para D8 ou pino analógico*/
// variáveis de estado
int estado = 0;
int menu = 1;

bool jaAvisou = false;  // impedir que mensagem de alerta do Snake rode infinitamente
int ultimoBotao = 0;

#define LED_AZUL 50

int qualBotaoPress() {
  int btnPressionado = analogRead(A0);

  if (btnPressionado < 50) return 1;   // RIGHT
  if (btnPressionado < 195) return 2;  // UP
  if (btnPressionado < 380) return 3;  // DOWN
  if (btnPressionado < 555) return 4;  // LEFT
  if (btnPressionado < 790) return 5;  // SELECT
  return 0;
}

// ================= SETUP / LOOP =================

void setup() {

  lcd.init();          // Inicializa o display
  lcd.backlight();     // Liga a luz de fundo

  lcd.begin(16, 2);
  Serial.begin(9600);
  randomSeed(analogRead(A5));

  pinMode(LED_AZUL, OUTPUT);
  digitalWrite(LED_AZUL, LOW);

  Loading();
}

void loop() {
  int botaoAtual = qualBotaoPress();

  // Menu inicial
  if (estado == 0) {
    lcd.setCursor(0, 0);
    lcd.print("Boas-vindas!");
    lcd.setCursor(0, 1);
    lcd.print("[Dir]: iniciar");

    if (botaoAtual == 1) {
      estado = 1;
      lcd.clear();
      efeitoClique();
      delay(300);
    }
  }

  // Menu principal
  else if (estado == 1) {

    if (botaoAtual != ultimoBotao) {

      if (botaoAtual == 2) {  // UP
        menu--;
        efeitoClique();
        delay(100);
      }

      if (botaoAtual == 3) {  // DOWN
        menu++;
        efeitoClique();
        delay(100);
      }

      if (botaoAtual == 5) {  // SELECT
        estado = 4;
        lcd.clear();
        delay(100);
      }

      ultimoBotao = botaoAtual;
    }

    lcd.setCursor(0, 0);
    lcd.print("Menu:");

    lcd.setCursor(0, 1);
    if (menu == 1) {
      lcd.print(">> Matematica   ");
      if (botaoAtual == 5) {  // SELECT
        estado = 4;
        lcd.clear();
        LoadingCurto();
        lcd.clear();
      }
    }

    lcd.setCursor(0, 1);
    if (menu == 2) {
      lcd.print(">> Snake Game   ");
      if (botaoAtual == 5) {  // SELECT
        estado = 5;
        lcd.clear();
        LoadingCurto();
        lcd.clear();
      }
    }

    lcd.setCursor(0, 1);
    if (menu == 3) {
      lcd.print(">> Demonstrativo");
      if (botaoAtual == 5) {
        estado = 6;
        lcd.clear();
        LoadingCurto();
        lcd.clear();
      }
    }

    lcd.setCursor(0, 1);
    if (menu == 4) {
      lcd.print(">> Baralho      ");
      if (botaoAtual == 5) {
        estado = 7;
        lcd.clear();
        LoadingCurto();
        lcd.clear();
      }
    }

    if (menu < 1) menu = 7;
    if (menu > 7) menu = 1;

    if (botaoAtual == 0) {
      ultimoBotao = 0;
    }
    delay(200);
  }

  if (estado == 4) {
    PlayMatematica();
  }

  if (estado == 5) {
    if (jaAvisou == false) {
      avisoSairSnake();
      jaAvisou = true;
    }
    PlaySnake();
  }

  if (estado == 6) {
    telaDemonstrativa();
  }

  if (estado == 7) {
    PlayBaralho();
  }
}
