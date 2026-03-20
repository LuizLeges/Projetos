int telaDemonstrativa() {
  bool teclaSair = false;

  while (!teclaSair) {
    //int botaoAtual = qualBotaoPress();
    int botaoAtual = 0;

//    lcd.setCursor(0, 0);
//    lcd.print("Demonstração");
//    delay(2)

    lcd.setCursor(0, 0);
    lcd.print("Titulos como:");

    ledOn();
    delay(80);
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print("M"); delay(200); 
    lcd.print("a"); delay(200);
    lcd.print("t"); delay(200);
    lcd.print("e"); delay(200);
    lcd.print("m"); delay(200);
    lcd.print("a"); delay(200);
    lcd.print("t"); delay(200);
    lcd.print("i"); delay(200);
    lcd.print("c"); delay(200);
    lcd.print("a"); delay(200); 
    ledOff();

    delay(2000);
    ledOn();
    delay(80);
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print("> S");
    delay(500);
    lcd.print("na");
    delay(500);
    lcd.print("ke");
    delay(500);
    lcd.print(" Ga");
    delay(500);
    lcd.print("me");
    delay(500);
    ledOff();

    delay(2000);
    ledOn();
    delay(80);
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print("> De");
    delay(300);
    lcd.print("mons");
    delay(300);
    lcd.print("tra");
    delay(300);
    lcd.print("ti");
    delay(300);
    lcd.print("vo");
    delay(300);
    ledOff();

    delay(2000);
    ledOn();
    delay(80);
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print("> Ba");
    delay(500);
    lcd.print("ra");
    delay(500);
    lcd.print("lho");
    ledOff();

//=============================================
    delay(2000);
    lcd.setCursor(0, 0);
    lcd.print("                ");
    lcd.setCursor(0, 0);
    lcd.print("Recursos:");

    ledOn();
    delay(80);
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print("> Keypad incluso");
    ledOff();

    delay(2000);
    ledOn();
    delay(80);
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print("> Led interativo");
    ledOff();

    delay(2000);
    ledOn();
    delay(80);
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print("> Tela 16x2 LCD");
    ledOff();
    delay(2000);

    if (botaoAtual == 4) {
      teclaSair = true;
      break;
    }
  }
  estado = 0;
  return estado;
}
