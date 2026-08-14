#include <SPI.h>
#include <Ethernet.h>

// Portul TCP utilizat de server
const int portServer = 4080;

// Adresa MAC a platformei Arduino #2
byte adresaMAC[] = {0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02};

// Crearea serverului TCP
EthernetServer serverTCP(portServer);

void setup() {
  // Inițializarea comunicației seriale
  Serial.begin(9600);

  Serial.println("ARDUINO #2: SERVER TCP");

  // Inițializarea modulului Ethernet și obținerea adresei IP prin DHCP
  if (Ethernet.begin(adresaMAC) == 0) {
    Serial.println("Eroare la configurarea Ethernet prin DHCP");
  }

  // Afișarea adresei IP primite de server
  Serial.print("Adresa IP a serverului TCP: ");
  Serial.println(Ethernet.localIP());

  Serial.println("-> Introduceți această adresă în programul Arduino #1");

  // Pornirea serverului TCP
  serverTCP.begin();

  Serial.print("Serverul TCP asculta pe portul: ");
  Serial.println(portServer);
}

void loop() {
  // Verificarea existenței unui client TCP
  EthernetClient client = serverTCP.available();

  // Dacă există un client conectat
  if (client) {
    // Citirea primului caracter transmis de client
    char comanda = client.read();

    Serial.print("- Comanda primita: ");
    Serial.println(comanda);

    // Verificarea existenței altor date disponibile
    if (client.available() > 0) {
      // Citirea caracterului primit
      char caracterPrimit = client.read();

      // Retransmiterea caracterului către client
      serverTCP.write(caracterPrimit);

      // Afișarea caracterului primit în Serial Monitor
      Serial.write(caracterPrimit);
    }
  }
}
