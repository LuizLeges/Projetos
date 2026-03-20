extern LiquidCrystal lcd;
extern int estado;
extern int qualBotaoPress();


// ===== VARIÁVEIS DO JOGO ===== - by mano chatppt
int playerPos = 1;
int obstaclePos = 15;
bool pulando = false;
int scoreJump = 0;

// ===== INICIALIZAÇÃO =====
void Jump_Init() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Jump Game");
  lcd.setCursor(0,1);
  lcd.print("SELECT inicia");

  jumpIniciado = false;
}

// ===== LOOP DO JOGO =====
void PlayJump() {

  int botao = qualBotaoPress();

  // Sair com LEFT
  if (botao == 4) {
    jumpIniciado = false;
    estado = 1;
    lcd.clear();
    delay(200);
    return;
  }

  // Iniciar com SELECT
  if (!jumpIniciado) {
    if (botao == 5) {
      lcd.clear();
      jumpIniciado = true;
      obstaclePos = 15;
      scoreJump = 0;
    }
    return;
  }

  // Pular com UP
  if (botao == 2) {
    pulando = true;
  }

  lcd.clear();

  // desenha jogador
  if (pulando) {
    lcd.setCursor(1,0);
    lcd.print("O");
  } else {
    lcd.setCursor(1,1);
    lcd.print("O");
  }

  // desenha obstáculo
  lcd.setCursor(obstaclePos,1);
  lcd.print("#");

  obstaclePos--;

  if (obstaclePos < 0) {
    obstaclePos = 15;
    scoreJump++;
  }

  // colisão
  if (obstaclePos == 1 && !pulando) {
    lcd.clear();
    lcd.print("Game Over");
    lcd.setCursor(0,1);
    lcd.print("Score: ");
    lcd.print(scoreJump);
    delay(2000);
    jumpIniciado = false;
  }

  pulando = false;
  delay(200);
}