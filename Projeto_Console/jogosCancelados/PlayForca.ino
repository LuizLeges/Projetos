// ===== VARIÁVEIS DO JOGO =====
String palavraFORCA = "ARDUINO";
String exibicao = "";
int erros = 0;
bool forcaIniciado = false;
char letraAtual = 'A';

int ultimoBotaoForca = 0;


// ===== INICIAR FORCA =====
void Forca_Init() {
  exibicao = "";
  erros = 0;
  letraAtual = 'A';

  for (int i = 0; i < palavraFORCA.length(); i++) {
    exibicao += "_";
  }

  forcaIniciado = true;
  lcd.clear();
}


// ===== VERIFICAR LETRA =====
void verificarLetra(char letra) {

  bool acertou = false;

  for (int i = 0; i < palavraFORCA.length(); i++) {
    if (palavraFORCA[i] == letra) {
      exibicao[i] = letra;
      acertou = true;
    }
  }

  if (!acertou) {
    erros++;
  }

  // venceu?
  if (exibicao == palavraFORCA) {
    lcd.clear();
    lcd.print("VOCE VENCEU!");
    delay(2000);
    forcaIniciado = false;
  }

  // perdeu?
  if (erros >= 6) {
    lcd.clear();
    lcd.print("VOCE PERDEU!");
    lcd.setCursor(0,1);
    lcd.print(palavraFORCA);
    delay(3000);
    forcaIniciado = false;
  }
}


// ===== LOOP DA FORCA =====
void PlayForca() {

  if (!forcaIniciado) {
    iniciarForca();
  }

  int botao = qualBotaoPress();

  // evita repetição segurando botão
  if (botao != 0 && botao != ultimoBotaoForca) {

    // UP -> próxima letra
    if (botao == 2) {
      letraAtual++;
      if (letraAtual > 'Z') letraAtual = 'A';
    }

    // DOWN -> letra anterior
    if (botao == 3) {
      letraAtual--;
      if (letraAtual < 'A') letraAtual = 'Z';
    }

    // SELECT -> confirmar letra
    if (botao == 5) {
      verificarLetra(letraAtual);
    }

    ultimoBotaoForca = botao;
  }

  if (botao == 0) {
    ultimoBotaoForca = 0;
  }

  // ===== ATUALIZA LCD =====
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,0);
  lcd.print(exibicao);

  lcd.setCursor(0,1);
  lcd.print("Erros:");
  lcd.print(erros);

  lcd.setCursor(12,1);
  lcd.print(letraAtual);
}