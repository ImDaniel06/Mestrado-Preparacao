// Arquivo: Pisca_Registradores.ino
// Autor: Daniel Martins
// Hardware: LED no pino 7 (PD7) com resistor 330 ohms

void setup() {
  // Configuração: Queremos PD7 como SAÍDA (Output).
  // O registrador DDRD controla os pinos 0 a 7.
  // Binário: 00000000 (tudo entrada) -> Queremos o bit 7 como 1.
  // 1 << 7 resulta em 10000000.
  
  DDRD |= (1 << 7); // Configura APENAS o pino 7 como saída, sem mexer nos outros (0-6).
}

void loop() {
  // 1. LIGAR O LED
  // Define o bit 7 do registrador PORTD como 1 (5V)
  PORTD |= (1 << 7);
  
  delay(1000); // Espera 1 segundo (ainda usaremos delay por hoje)
  
  // 2. DESLIGAR O LED
  // Para desligar, precisamos zerar o bit 7.
  // ~(1 << 7) inverte a máscara: vira 01111111.
  // O operador AND (&) com 0 zera o bit alvo e mantém os outros.
  PORTD &= ~(1 << 7);
  
  delay(1000);
}