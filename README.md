# Interconectare a două platforme Arduino prin conexiune Ethernet / Interconnection of Two Arduino Platforms via Ethernet Connection

**Versiune în limba română / English version below**

---

# 🇷🇴 Română

## Descriere

Acest proiect prezintă realizarea unei comunicații între două platforme Arduino prin intermediul unei conexiuni Ethernet, utilizând protocolul **TCP/IP** și modelul de comunicare **client-server**.

Proiectul este alcătuit din două platforme Arduino:

- **Arduino #1** funcționează ca TCP Client
- **Arduino #2** funcționează ca TCP Server
- Serverul ascultă pe portul **4080**.

Clientul se conectează la adresa IP a serverului prin rețeaua Ethernet și transmite caractere introduse prin interfața Serial Monitor.

Serverul primește datele și le retransmite către client, realizând o comunicare de tip **echo**, afișându-le și în Serial Monitor.

## Arhitectura sistemului

```text
                    CONEXIUNE ETHERNET
                 TCP / Port 4080

┌─────────────────────────┐       ┌─────────────────────────┐
│       Arduino #1        │       │       Arduino #2        │
│                         │       │                         │
│      TCP CLIENT         │──────>│      TCP SERVER         │
│                         │       │                         │
│   Serial Monitor        │<──────│   Serial Monitor        │
│                         │  Echo │                         │
└─────────────────────────┘       └─────────────────────────┘
```

## Obiective

- realizarea unei comunicații Ethernet între două platforme Arduino;
- utilizarea protocolului TCP/IP;
- implementarea arhitecturii client-server;
- transmiterea datelor între două dispozitive;
- utilizarea unei conexiuni Ethernet pentru comunicarea între microcontrolere;
- observarea și testarea datelor transmise prin Serial Monitor.

## Componente necesare

- 2 × platforme Arduino compatibile;
- 2 × Ethernet Shield/module Ethernet;
- cabluri Ethernet;
- calculator pentru programarea platformelor Arduino;
- rețea locală compatibilă cu configurarea Ethernet utilizată.

## Software

Proiectul utilizează:

- Arduino IDE;
- biblioteca `SPI`;
- biblioteca `Ethernet`;
- protocolul TCP/IP.

Bibliotecile utilizate în cod sunt:

```cpp
#include <SPI.h>
#include <Ethernet.h>
```

## Configurarea sistemului

### Arduino #2 – TCP Server

Arduino #2 funcționează ca server TCP și utilizează portul:

```cpp
const int serverPort = 4080;
```

Adresa MAC utilizată de server este:

```cpp
byte mac[] = {0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02};
```

Adresa IP este obținută prin DHCP.

După pornire, serverul afișează în Serial Monitor adresa IP obținută:

```text
TCP Server IP address: xxx.xxx.xxx.xxx
-> Se pune adresa obtinuta in Arduino #1
```

Această adresă trebuie introdusă în programul Arduino #1.

### Arduino #1 – TCP Client

Arduino #1 utilizează următoarea adresă MAC:

```cpp
byte mac[] = {0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x03};
```

Adresa IP a serverului este definită prin:

```cpp
IPAddress serverAddress(192, 168, 0, 209);
```

**Important:** adresa `192.168.0.209` este doar un exemplu. Ea trebuie înlocuită cu adresa IP afișată de Arduino #2.

Portul utilizat pentru conexiunea TCP este:

```cpp
const int serverPort = 4080;
```

## Mod de funcționare

1. Arduino #2 este pornit și configurează conexiunea Ethernet.
2. Arduino #2 obține o adresă IP prin DHCP.
3. Adresa IP a serverului este afișată în Serial Monitor.
4. Adresa IP este introdusă în programul Arduino #1.
5. Arduino #1 este pornit și încearcă să se conecteze la server.
6. Dacă conexiunea este realizată, clientul afișează `Connected to TCP server`.
7. Utilizatorul introduce caractere în Serial Monitor-ul Arduino #1.
8. Caracterele sunt transmise către Arduino #2 prin TCP.
9. Arduino #2 afișează datele primite și le retransmite către client.
10. Arduino #1 primește datele retransmise și le afișează în Serial Monitor.

### Tehnologii

- Arduino
- C++ / Arduino IDE
- Ethernet
- TCP/IP
- comunicare Client-Server
- Serial Monitor

## Parametri de comunicare

| Parametru | Valoare |
|---|---|
| Protocol | TCP/IP |
| Port TCP | 4080 |
| Arduino #1 | TCP Client |
| Arduino #2 | TCP Server |
| Configurare IP | DHCP |
| Comunicare Serial | 9600 baud |
| Tip comunicare | Echo |

## Structura proiectului

```text
Interconectare-a-doua-platforme-Arduino-prin-conexiune-Ethernet/
├── README.md
├── Arduino_TCP_Server/
│   └── Arduino_TCP_Server.ino
├── Arduino_TCP_Client/
│   └── Arduino_TCP_Client.ino
└── Documentation/
    ├── documentatie.docx
    └── documentatie.pdf
```

---

# 🇬🇧 English

## Description

This project demonstrates communication between two Arduino platforms using an Ethernet connection, the **TCP/IP protocol**, and the **client-server communication model**.

The project consists of two Arduino platforms:

- **Arduino #1** acts as the TCP Client
- **Arduino #2** acts as the TCP Server
- The server listens on port **4080**.

Arduino #1 connects to Arduino #2 through the Ethernet network and sends characters entered through the Serial Monitor.

Arduino #2 receives the data and sends it back to the client, implementing a simple **echo** communication mechanism.

## System Architecture

```text
                    ETHERNET CONNECTION
                    TCP / Port 4080

┌─────────────────────────┐       ┌─────────────────────────┐
│       Arduino #1        │       │       Arduino #2        │
│                         │       │                         │
│       TCP CLIENT        │──────>│       TCP SERVER        │
│                         │       │                         │
│    Serial Monitor       │<──────│    Serial Monitor       │
│                         │  Echo │                         │
└─────────────────────────┘       └─────────────────────────┘
```

## Objectives

- establishing Ethernet communication between two Arduino platforms;
- using the TCP/IP protocol;
- implementing a client-server architecture;
- transmitting data between two devices;
- using an Ethernet connection for communication between microcontrollers;
- observing and testing transmitted data through the Serial Monitor.

## Required Components

- 2 × compatible Arduino platforms;
- 2 × Ethernet Shields/Ethernet modules;
- Ethernet cables;
- a computer for programming the Arduino platforms;
- a local network compatible with the Ethernet configuration.

## Software

The project uses:

- Arduino IDE;
- `SPI` library;
- `Ethernet` library;
- TCP/IP protocol.

The libraries used in the source code are:

```cpp
#include <SPI.h>
#include <Ethernet.h>
```

## System Configuration

### Arduino #2 – TCP Server

Arduino #2 acts as the TCP server and uses port:

```cpp
const int serverPort = 4080;
```

The MAC address used by the server is:

```cpp
byte mac[] = {0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02};
```

The IP address is obtained through DHCP.

After startup, the server displays the assigned IP address in the Serial Monitor:

```text
TCP Server IP address: xxx.xxx.xxx.xxx
-> Se pune adresa obtinuta in Arduino #1
```

This IP address must be entered in the Arduino #1 source code.

### Arduino #1 – TCP Client

Arduino #1 uses the following MAC address:

```cpp
byte mac[] = {0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x03};
```

The server IP address is defined using:

```cpp
IPAddress serverAddress(192, 168, 0, 209);
```

**Important:** `192.168.0.209` is only an example. It must be replaced with the IP address displayed by Arduino #2.

The TCP connection uses:

```cpp
const int serverPort = 4080;
```

## How It Works

1. Arduino #2 starts and initializes the Ethernet connection.
2. Arduino #2 obtains an IP address through DHCP.
3. The server IP address is displayed in the Serial Monitor.
4. The IP address is entered into the Arduino #1 source code.
5. Arduino #1 starts and attempts to connect to the server.
6. If the connection is successful, the client displays `Connected to TCP server`.
7. The user enters characters in the Arduino #1 Serial Monitor.
8. The characters are transmitted to Arduino #2 using TCP.
9. Arduino #2 displays the received data and sends it back to the client.
10. Arduino #1 receives the echoed data and displays it in the Serial Monitor.

### Technologies

- Arduino
- C++ / Arduino IDE
- Ethernet
- TCP/IP
- Client-Server communication
- Serial Monitor

## Communication Parameters

| Parameter | Value |
|---|---|
| Protocol | TCP/IP |
| TCP Port | 4080 |
| Arduino #1 | TCP Client |
| Arduino #2 | TCP Server |
| IP Configuration | DHCP |
| Serial Communication | 9600 baud |
| Communication Type | Echo |

## Project Structure

```text
Interconectare-a-doua-platforme-Arduino-prin-conexiune-Ethernet/
├── README.md
├── Arduino_TCP_Server/
│   └── Arduino_TCP_Server.ino
├── Arduino_TCP_Client/
│   └── Arduino_TCP_Client.ino
└── Documentation/
    ├── documentatie.docx
    └── documentatie.pdf
```

---

## Autor / Author

**IonutD**