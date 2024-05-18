// Definición de pines para los solenoides
const int solenoidPins[4][6] = {
  {13, 12, 11, 10, 9, 8}, 
  {5, 4, 3, 2, 1, 0},
  {16, 17, 18, 19, 20, 21},
  {22, 24, 26, 27, 25, 23}
}; // Asume 6 solenoides para una celda Braille

const int numRows = sizeof(solenoidPins) / sizeof(solenoidPins[0]);  // Número de filas (2)
const int numCols = sizeof(solenoidPins[0]) / sizeof(solenoidPins[0][0]);  // Número de columnas (6)

// Traducción de algunos caracteres a Braille (solo letras mayúsculas A, B, C)
int brailleChars[30][6] = {
  {1, 0, 0, 0, 0, 0},  // A
  {1, 1, 0, 0, 0, 0},  // B
  {1, 0, 0, 1, 0, 0},  // C
  {1, 0, 0, 1, 1, 0},  // D
  {1, 0, 0, 0, 1, 0},  // E
  {1, 1, 0, 1, 0, 0},  // F
  {1, 1, 0, 1, 1, 0},  // G
  {1, 1, 0, 0, 1, 0},  // H
  {0, 1, 0, 1, 0, 0},  // I
  {0, 1, 0, 1, 1, 0},  // J
  {1, 0, 1, 0, 0, 0},  // K
  {1, 1, 1, 0, 0, 0},  // L
  {1, 0, 1, 1, 0, 0},  // M
  {1, 0, 1, 1, 1, 0},  // N
  {1, 0, 1, 0, 1, 0},  // O
  {1, 1, 1, 1, 0, 0},  // P
  {1, 1, 1, 1, 1, 0},  // Q
  {1, 1, 1, 0, 1, 0},  // R
  {0, 1, 1, 1, 0, 0},  // S
  {0, 1, 1, 1, 1, 0},  // T
  {1, 0, 1, 0, 0, 1},  // U
  {1, 1, 1, 0, 0, 1},  // V
  {0, 1, 0, 1, 1, 1},  // W
  {1, 0, 1, 1, 0, 1},  // X
  {1, 0, 1, 1, 1, 1},  // Y
  {1, 0, 1, 0, 1, 1},  // Z
  {0, 1, 1, 0, 1, 1},  // ñ
  {0, 1, 0, 0, 1, 1},  // ç
};

void setup() {
  // Configura los pines de los solenoides como salidas
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numCols; j++) {
      pinMode(solenoidPins[i][j], OUTPUT);
      digitalWrite(solenoidPins[i][j], LOW); // Asegura que todos los solenoides estén apagados al inicio
    }
  }
}

void loop() {
  displayBraille("HOLA");  // Muestra la letra A en Braille
  delay(2000);          // Espera 2 segundos
  displayBraille("FGC");  // Muestra la letra E en Braille
  delay(2000);          // Espera 2 segundos
  displayBraille("WORD");  // Muestra la letra Y y O en Braille
  delay(2000);          // Espera 2 segundos
}

// Función para mostrar un carácter en Braille
void displayBraille(String text) {
  for (int k = 0; k < text.length(); k++) {
    char letra = text[k];
    int index = letra - 'A';  // Convierte el carácter a un índice basado en 'A' como 0
    if (index < 0 || index > 29) return;  // Verifica que el carácter sea válido

    // Activa los solenoides según el patrón Braille del carácter
    for (int i = 0; i < numCols; i++) {
      digitalWrite(solenoidPins[k % numRows][i], brailleChars[index][i]);
    }
   // Mantiene el carácter por 2 segundos
    // Apaga los solenoides después de mostrar el carácter
    
  }
    for (int k = text.length(); k < 4; k++) {
    for (int i = 0; i < numCols; i++) {
      digitalWrite(solenoidPins[k][i], LOW);
    }
   // Mantiene el carácter por 2 segundos
    // Apaga los solenoides después de mostrar el carácter
    
  }

}



/*
// Definición de pines para los solenoides
const int solenoidPins[2][6] = {
  {13, 12, 11, 10, 9, 8}, 
  {5, 4, 3, 2, 1, 0}
  }; // Asume 6 solenoides para una celda Braille
const int numSolenoids = sizeof(solenoidPins) / sizeof(solenoidPins[0]);

// Traducción de algunos caracteres a Braille (solo letras mayúsculas A, B, C)
int brailleChars[30][6] = {
  {1, 0, 0, 0, 0, 0},  // A
  {1, 1, 0, 0, 0, 0},  // B
  {1, 0, 0, 1, 0, 0},  // C
  {1, 0, 0, 1, 1, 0},  // D
  {1, 0, 0, 0, 1, 0},  // E
  {1, 1, 0, 1, 0, 0},  // F
  {1, 1, 0, 1, 1, 0},  // G
  {1, 1, 0, 0, 1, 0},  // H
  {0, 1, 0, 1, 0, 0},  // I
  {0, 1, 0, 1, 1, 0},  // J
  {1, 0, 1, 0, 0, 0},  // K
  {1, 1, 1, 0, 0, 0},  // L
  {1, 0, 1, 1, 0, 0},  // M
  {1, 0, 1, 1, 1, 0},  // N
  {1, 0, 1, 0, 1, 0},  // O
  {1, 1, 1, 1, 0, 0},  // P
  {1, 1, 1, 1, 1, 0},  // Q
  {1, 1, 1, 0, 1, 0},  // R
  {0, 1, 1, 1, 0, 0},  // S
  {0, 1, 1, 1, 1, 0},  // T
  {1, 0, 1, 0, 0, 1},  // U
  {1, 1, 1, 0, 0, 1},  // V
  {0, 1, 0, 1, 1, 1},  // W
  {1, 0, 1, 1, 0, 1},  // X
  {1, 0, 1, 1, 1, 1},  // Y
  {1, 0, 1, 0, 1, 1},  // Z
  {0, 1, 1, 0, 1, 1},  // ñ
  {0, 1, 0, 0, 1, 1},  // ç
};


void setup() {
  // Configura los pines de los solenoides como salidas
  for (int i = 0; i < numSolenoids; i++) {
    pinMode(solenoidPins[i], OUTPUT);
  }
}

void loop() {
  displayBraille("AA");  // Muestra la letra A en Braille
  delay(2000);          // Espera 2 segundos
  displayBraille("AA");  // Muestra la letra B en Braille
  delay(2000);          // Espera 2 segundos
  displayBraille("AA");  // Muestra la letra C en Braille
  delay(2000);          // Espera 2 segundos
}

// Función para mostrar un carácter en Braille
void displayBraille(String character) {
  char letra;
  int b = character.length();
  for (int k = 0; k < 2; k++) {
    letra = character[k];
    int index = letra - 'A';  // Convierte el carácter a un índice basado en 'A' como 0
    if (index < 0 || index > 27) return;  // Verifica que el carácter sea válido

    // Activa los solenoides según el patrón Braille del carácter
    for (int i = 0; i < numSolenoids; i++) {
      digitalWrite(solenoidPins[k][i], brailleChars[index][i]);
    }
  }
}
*/