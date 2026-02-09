// Mestrado - Bloco 1: Domínio do Bit
// Lendo entrada sem componentes externos (Pull-Up Interno)

void setup() {
  // --- SAÍDA (LED) ---
  // Configura Pino 13 (Bit 5 do PORTB) como SAÍDA
  DDRB |= (1 << 5); 

  // --- ENTRADA (BOTÃO) ---
  // Configura Pino 8 (Bit 0 do PORTB) como ENTRADA (0)
  DDRB &= ~(1 << 0); 
  
  // --- ATIVAR PULL-UP ---
  // Escrevendo 1 no PORT de uma entrada, ativamos o resistor interno.
  // Isso segura o pino em 5V quando o fio está solto.
  PORTB |= (1 << 0); 
}

void loop() {
  // --- LEITURA ---
  // PINB é o registrador que "enxerga" a voltagem real nos pinos.
  // Verificamos se o bit 0 está LOW (fio encostado no GND).
  
  // A lógica: !(PINB & 1) significa "SE NÃO TIVER BIT 0" (ou seja, se for 0)
  if ( ! (PINB & (1 << 0)) ) { 
    // Botão Apertado (Fio no GND) -> Acende LED
    PORTB |= (1 << 5); 
  } else {
    // Botão Solto (Fio no ar) -> Apaga LED
    PORTB &= ~(1 << 5); 
  }
}