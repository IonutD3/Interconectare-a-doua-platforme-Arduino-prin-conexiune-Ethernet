#include <SPI.h>
#include <Ethernet.h>

// Portul TCP al serverului
const int portServer = 4080;

// Adresa MAC a platformei Arduino #1
byte adresaMAC[] = {0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x03};

// Adresa IP a serverului TCP - Arduino #2
// Înlocuiți această adresă cu adresa afișată de Arduino #2.
IPAddress adresaServer(192, 168, 0, 209);

// Crearea clientului TCP
EthernetClient clientTCP;

void setup() {
  // Inițializarea comunicației seriale
  Serial.begin(9600);

  Serial.println("ARDUINO #1: CLIENT TCP");

  // Inițializarea modulului Ethernet și obținerea adresei IP prin DHCP
  if (Ethernet.begin(adresaMAC) == 0) {
    Serial.println("Eroare la configurarea Ethernet prin DHCP");
  }

  // Conectarea la serverul TCP - Arduino #2
  Serial.print("Se incearca conectarea la serverul TCP...");

  if (clientTCP.connect(adresaServer, portServer)) {
    Serial.println();
    Serial.println("Conectare reusita la serverul TCP.");
  } else {
    Serial.println();
    Serial.println("Eroare: conectarea la serverul TCP a esuat.");
  }
}

void loop() {
  // Verificarea existenței datelor primite de la server
  if (clientTCP.available()) {
    char caracter = clientTCP.read();

    // Afișarea caracterului primit
    Serial.print(caracter);
  }

  // Citirea datelor introduse în Serial Monitor
  // și transmiterea lor către serverul TCP
  while (Serial.available() > 0) {
    char caracterTrimis = Serial.read();

    if (clientTCP.connected()) {
      clientTCP.print(caracterTrimis);
    }
  }

  // Verificarea stării conexiunii cu serverul
  if (!clientTCP.connected()) {
    Serial.println();
    Serial.println("Conexiunea cu serverul a fost intrerupta.");
    Serial.println("Clientul TCP se opreste.");

    clientTCP.stop();

    // Oprirea execuției până la resetarea plăcii Arduino
    while (true) {
      delay(1);
    }
  }
}
