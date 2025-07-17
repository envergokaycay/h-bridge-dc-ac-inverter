// === Pin Tanımları ===
const int HIN1 = 9;    // OC1A - Timer1
const int LIN1 = 10;   // OC1B - Timer1
const int HIN2 = 3;    // Software PWM
const int LIN2 = 11;   // Software PWM

// === Zamanlama Ayarları ===
const int deadTimeMicros = 5;     // 5 µs dead time
const int onTimeMicros = 20;      // 20 µs aktif süre (%50 duty @ 20kHz)

void setup() {
  // Pin modları
  pinMode(HIN1, OUTPUT);
  pinMode(LIN1, OUTPUT);
  pinMode(HIN2, OUTPUT);
  pinMode(LIN2, OUTPUT);

  // === Timer1 Ayarı (Donanımsal PWM için) ===
  TCCR1A = 0;
  TCCR1B = 0;

  // Fast PWM, Mode 14: ICR1 top
  TCCR1A |= (1 << COM1A1) | (1 << COM1B1); // OC1A & OC1B non-inverting
  TCCR1A |= (1 << WGM11);
  TCCR1B |= (1 << WGM12) | (1 << WGM13);
  TCCR1B |= (1 << CS10); // No prescaler

  ICR1 = 800;     // 16 MHz / 800 = 20kHz
  OCR1A = 0;      // Başta OFF
  OCR1B = 0;      // Başta OFF
}

void loop() {
  // === Timer1: HIN1 ve LIN1 kontrolü (donanımsal) ===

  // Üst MOSFET ON (HIN1), Alt OFF (LIN1)
  OCR1A = 400;  // %50 duty
  OCR1B = 0;
  delayMicroseconds(onTimeMicros);

  // Her iki çıkışı kapat (dead time)
  OCR1A = 0;
  delayMicroseconds(deadTimeMicros);

  // Alt MOSFET ON (LIN1), Üst OFF (HIN1)
  OCR1B = 400;
  OCR1A = 0;
  delayMicroseconds(onTimeMicros);

  // Her iki çıkışı kapat (dead time)
  OCR1B = 0;
  delayMicroseconds(deadTimeMicros);

  // === Yazılımsal PWM: HIN2 ve LIN2 ===

  // Üst MOSFET ON (HIN2), Alt OFF (LIN2)
  digitalWrite(HIN2, HIGH);
  digitalWrite(LIN2, LOW);
  delayMicroseconds(onTimeMicros);
  digitalWrite(HIN2, LOW);
  delayMicroseconds(deadTimeMicros);

  // Alt MOSFET ON (LIN2), Üst OFF (HIN2)
  digitalWrite(LIN2, HIGH);
  digitalWrite(HIN2, LOW);
  delayMicroseconds(onTimeMicros);
  digitalWrite(LIN2, LOW);
  delayMicroseconds(deadTimeMicros);
}