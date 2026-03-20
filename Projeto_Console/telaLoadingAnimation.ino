
void LoadingAlt() {
  lcd.clear();
  lcd.print("Um instante...");
  lcd.setCursor(0, 1);
  lcd.print("[");
  lcd.setCursor(15, 1);
  lcd.print("]");
  lcd.setCursor(1, 1);

  for (int i = 0; i < 4; i++) {  //piscadas do led, só bonitinho
    ledOn();
    delay(200);
    ledOff();
    delay(200);
  }
  for (int i = 0; i < 14; i++) {  //animação de loading aíó
    lcd.print("o");
    delay(120);
    if (i == 10 || i == 8) {  //if pra simular uma lerdeza no carregamento
      delay(300);
    }
  }
  lcd.clear();
}

void LoadingCurto() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Carregando");
  delay(600);
  lcd.print(".");
  delay(600);
  lcd.print(".");
  delay(600);
  lcd.print(".");
  delay(500);
  lcd.clear();
}

void Loading() {
  lcd.clear();
  lcd.print("Um instante...");
  lcd.setCursor(0, 1);
  lcd.print("[");
  lcd.setCursor(5, 1);
  lcd.print("]");
  lcd.setCursor(1, 1);

  for (int i = 0; i < 4; i++) {  //piscadas do led, só bonitinho
    ledOn();
    delay(200);
    ledOff();
    delay(200);
  }

  lcd.setCursor(1, 1);  // início. Animação manual
  lcd.print("oooo");
  delay(200);
  // ida de O's maiúsculos pra direita ->
  for (int g = 0; g < 3; g++) {
    lcd.setCursor(1, 1);
    lcd.print("O");
    delay(110);

    lcd.setCursor(1, 1);
    lcd.print("o");
    delay(110);

    lcd.setCursor(2, 1);
    lcd.print("O");
    delay(110);

    lcd.setCursor(2, 1);
    lcd.print("o");
    delay(110);

    lcd.setCursor(3, 1);
    lcd.print("O");
    delay(110);

    lcd.setCursor(3, 1);
    lcd.print("o");
    delay(110);

    lcd.setCursor(4, 1);
    lcd.print("O");
    delay(110);

    lcd.setCursor(4, 1);
    lcd.print("o");
    delay(110);
  }
  lcd.clear();
}

void avisoSairSnake() {
  lcd.setCursor(0, 0);
  ledOn();
  lcd.print("Atencao:");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Por motivo de");
  lcd.setCursor(0, 1);
  lcd.print("limitacoes:");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Sair do Snake:");
  lcd.setCursor(0, 1);
  lcd.print("Perder ou [RST]");
  delay(2000);
  ledOff();
  lcd.clear();
}
