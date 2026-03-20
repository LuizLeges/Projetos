// ===== JOGO EMBARALHADO =====

extern LiquidCrystal_I2C lcd;
extern int estado;
extern int qualBotaoPress();

const char* palavras[] = {
  "Arroz", "Banana", "Escola", "Programar", "Arduino", "Monitor",
  "Corrente", "Parede", "Motor", "Manga", "Chuva", "Computadores",
  "Computador", "Notebook", "Carro", "Mouse", "Dia De Chuva",
  "Doce De Leite", "Videogame", "Caminhao", "Oleo", "Chevete",
  "Intel Core I5", "Televisao", "Noticia", "Papel", "Impressora",
  "Python", "Servidor Web", "Mochila Azul", "Caixa De Som", "Musica",
  "Motocicleta", "Minecraft", "Futebol", "Windows 10", "Teclado"
};

const int totalPalavras = sizeof(palavras) / sizeof(palavras[0]);

char palavra[17];
char palavraOriginal[17];

bool palavraRevelada = false;
bool jogoIniciado = false;

void embaralhar() {

  int indice = random(0, totalPalavras);  //variável só pra alguma palavra aleatória ser escolhida

  strcpy(palavra, palavras[indice]);          //o C é incompetente e não consegue copiar usando atribuição, o =, esse strcpy faz isso, sendo strcpy(destino, origem)
  strcpy(palavraOriginal, palavras[indice]);  //eu to sabidos

  int tamanho = strlen(palavra);

  for (int i = 0; i < 10; i++) {
    int a = random(0, tamanho);
    int b = random(0, tamanho);

    char temp = palavra[a];
    palavra[a] = palavra[b];
    palavra[b] = temp;
  }

  palavraRevelada = false;
  jogoIniciado = true;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Descubra:");
  lcd.setCursor(0, 1);
  lcd.print(palavra);
}


void PlayBaralho() {

  if (!jogoIniciado) {
    embaralhar();
  }

  int botao = qualBotaoPress();

  // DIR revela
  if (botao == 1 && !palavraRevelada) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Resposta:");
    ledOn();
    lcd.setCursor(0, 1);
    lcd.print(palavraOriginal);
    palavraRevelada = true;
    delay(2000);
    ledOff();
  }

  // LEFT volta ao menu
  if (botao == 4 && palavraRevelada) {
    estado = 1;
    jogoIniciado = false;
    lcd.clear();
    delay(300);
  }
}
