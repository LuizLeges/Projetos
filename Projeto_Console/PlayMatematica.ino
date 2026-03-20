void ledOn() {
  digitalWrite(LED_AZUL, HIGH);
}

void ledOff() {
  digitalWrite(LED_AZUL, LOW);
}

void efeitoClique() {
  ledOn();
  delay(80);
  ledOff();
}

void efeitoAcerto() {
  for (int i = 0; i < 3; i++) {
    ledOn();
    delay(150);
    ledOff();
    delay(150);
  }
}

void efeitoErro() {
  ledOn();
  delay(600);
  ledOff();
}

void PlayMatematica() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("> Matematica!  <");
  lcd.setCursor(0, 1);
  lcd.print("Pronto? [dir]");

  // Espera confirmação pra começar

  while (true) {
    int botao = qualBotaoPress();
    if (botao == 1) {
      break;
    }  // RIGHT
  }
  delay(300);
  lcd.clear();

  bool continuar = true;

  while (continuar) {
    // Gera nova operação
    int num1 = random(0, 21);
    int num2 = random(0, 21);
    int operacao = random(0, 2);  // 0 = +, 1 = -
    int respostaCerta = (operacao == 0) ? num1 + num2 : num1 - num2;
    int respostaAtual = 0;

    while (true) {

      lcd.setCursor(0, 0);
      lcd.print(" ");
      lcd.print(num1);
      if (operacao == 0)
        lcd.print(" + ");
      else
        lcd.print(" - ");
      lcd.print(num2); 
      lcd.print(" = ? ");

      lcd.setCursor(0, 1);
      lcd.print("Resp: ");
      lcd.print(respostaAtual);
      lcd.print("    ");

      int botao = qualBotaoPress();

      if (botao == 2) {  // UP
        efeitoClique();
        respostaAtual = respostaAtual + 1;
        delay(200);
      } else if (botao == 3) {  // DOWN
        efeitoClique();
        respostaAtual = respostaAtual - 1;
        delay(200);
      } else if (botao == 1) {  // RIGHT = confirmar
        efeitoClique();
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Verificando...");
        delay(500);

        if (respostaAtual == respostaCerta) {
          lcd.clear();
          lcd.print("Acertou! :D");
          efeitoAcerto();
          delay(1200);
          lcd.clear();

          break;
        } else {
          lcd.clear();
          lcd.print("Errou! :(");
          efeitoErro();
          lcd.setCursor(0, 1);
          lcd.print("Certo: ");
          lcd.print(respostaCerta);
          delay(2000);
          lcd.clear();
          estado = 1;         // volta pro menu
          continuar = false;  // encerra loop principal do jogo
          return;
        }
      } else if (botao == 4) {  // LEFT = sair manualmente
        efeitoClique();
        lcd.clear();
        lcd.print("Saindo...");
        delay(800);
        lcd.clear();
        estado = 1;
        continuar = false;
        return;
      }
    }
  }
}
