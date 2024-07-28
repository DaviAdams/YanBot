//Codigo feito por Davi Adams 07/2024 @davi.adams_2010.   .
//https://github.com/DaviAdams/YanBot.git                 .
//.........................................................
//Feito para usar na placa da Robocore BlackBoard Rocky.  .
//App celular  Bluetooth RC Control.                      .
//.........................................................
//Para fazer upload do codigo selecionar placa ESP32 Dev  .
//.........................................................
#include <RoboCore_Rocky.h> //Biblioteca Rocky.
#include <Arduino.h> //Biblioteca Arduino.
#include "BluetoothSerial.h" //Biblioteca bluetooth ESP32.

BluetoothSerial SerialBT; //Variavel Bluetooth.
RockyMotors motors; //Variavel motores Rocky.

void setup() { //Config geral.
  Serial.begin(115200); //Define velocidade monitor serial.
  Serial.println("Iniciando..."); //Escreve no monitor serial (Iniciando...)
  SerialBT.begin("YanBot"); //Define nome do bluetooth.
  Serial.println("Bluetooth ativo"); //Escreve no monitor serial (Bluetooth ativo)
}

void loop() { //Config que vai ficar repetindo.
   if (SerialBT.available()) { //Se o bluetooth estiver disponivel...
    char comando = SerialBT.read(); //...vai ler dados do app.

    if (comando == 'F') { //Se o app mandar o comando F...
      frente(); //...vai para frente.
    } else if (comando == 'B') { //Se o app mandar o comando B...
      tras(); //...vai para tras.
    } else if (comando == 'R') { //Se o app mandar o comando R...
      direita(); //...vai para direita.
    } else if (comando == 'L') { //Se o app mandar o comando L...
      esquerda(); //...vai para esquerda.
    } else if (comando == 'G') { //Se o app mandar o comando G...
      Fesquerda(); //...vai para frente esquerda.
    } else if (comando == 'I') { //Se o app mandar o comando I...
      Fdireita(); //...vai para frente direita.
    } else if (comando == 'H') { //Se o app mandar o comando H...
      Tesquerda(); //...vai para tras esquerda.
    } else if (comando == 'J') { //Se o app mandar o comando J...
      Tdireita(); //...vai para tras direita.
    } else if (comando == '0') { //Se o app mandar o comando 0...
      ZeroLed(); //...Desliga o led.
    } else if (comando == '1') { //Se o app mandar o comando 1...
      DezLed(); //...Led 10%.
    } else if (comando == '2') { //Se o app mandar o comando 2...
      VinteLed(); //...Led 20%.
    } else if (comando == '3') { //Se o app mandar o comando 3...
      TrintaLed(); //...Led 30%.
    } else if (comando == '4') { //Se o app mandar o comando 4...
      QuarentaLed(); //...Led 40%.
    } else if (comando == '5') { //Se o app mandar o comando 5...
      CinquentaLed(); //...Led 50%.
    } else if (comando == '6') { //Se o app mandar o comando 6...
      SesentaLed(); //...Led 60%.
    } else if (comando == '7') { //Se o app mandar o comando 7...
      SetentaLed(); //...Led 70%.
    } else if (comando == '8') { //Se o app mandar o comando 8...
      OitentaLed(); //...Led 80%.
    } else if (comando == '9') { //Se o app mandar o comando 9...
      NoventaLed(); //...Led 90%.
    } else if (comando == 'q') { //Se o app mandar o comando q...
      CemLed(); //...Led 100%.
    }

    else { //Se o app nao mandar nada...
      parado(); //fica parado.
    }
  }
}

void frente() { //Config frente:
  motors.setSpeedA(100); //Velocidade do motor A em 100%.
  motors.setSpeedB(100); //Velocidade do motor B em 100%.
  Serial.println("Frente"); //Escreve no monitor serial (Frente)
}
void tras() { //Config tras:
  motors.setSpeedA(-100); //Velocidade do motor A em -100%.
  motors.setSpeedB(-100); //Velocidade do motor B em -100%.
  Serial.println("Tras"); //Escreve no monitor serial (Tras)
}
void direita() { //Config direita:
  motors.setSpeedA(100); //Velocidade do motor A em 100%.
  motors.setSpeedB(-100); //Velocidade do motor B em -100%.
  Serial.println("Direita"); //Escreve no monitor serial (Direita)
}
void esquerda() { //Config esquerda:
  motors.setSpeedA(-100); //Velocidade do motor A em -100%.
  motors.setSpeedB(100); //Velocidade do motor B em 100%.
  Serial.println("Esquerda"); //Escreve no monitor serial (Esquerda)
}
void Fdireita() { //Config frente direita:
  motors.setSpeedA(100); //Velocidade do motor A em 100%.
  motors.setSpeedB(0); //Velocidade do motor B em 0%.
  Serial.println("Frente direita"); //Escreve no monitor serial (Frente direita)
}
void Fesquerda() { //Config frente esquerda:
  motors.setSpeedA(0); //Velocidade do motor A em 0%.
  motors.setSpeedB(100); //Velocidade do motor B em 100%.
  Serial.println("Frente esquerda"); //Escreve no monitor serial (Frente esquerda)
}
void Tdireita() { //Config tras direita:
  motors.setSpeedA(-100); //Velocidade do motor A em -100%.
  motors.setSpeedB(0); //Velocidade do motor B em 0%.
  Serial.println("Tras direita"); //Escreve no monitor serial (Tras direita)
}
void Tesquerda() { //Config tras esquerda:
  motors.setSpeedA(0); //Velocidade do motor A em 0%.
  motors.setSpeedB(-100); //Velocidade do motor B em -100%.
  Serial.println("Tras esquerda"); //Escreve no monitor serial (Tras esquerda)
}
void parado() { //Config parado:
  motors.setSpeedA(0); //Velocidade do motor A em 0%.
  motors.setSpeedB(0); //Velocidade do motor B em 0%.
  Serial.println("Parado"); //Escreve no monitor serial (Parado)
}
void ZeroLed() { //Config Led:
  motors.setSpeedC(0); //Led desligado.
  Serial.println("Led Desligado"); //Escreve no monitor serial (Led Desligado)
}
void DezLed() { //Config Led:
  motors.setSpeedC(10); //Led 10%.
  Serial.println("Led 10%"); //Escreve no monitor serial (Led 10%)
}
void VinteLed() { //Config Led:
  motors.setSpeedC(20); //Led 20%.
  Serial.println("Led 20%"); //Escreve no monitor serial (Led 20%)
}
void TrintaLed() { //Config Led:
  motors.setSpeedC(30); //Led 30%.
  Serial.println("Led 30%"); //Escreve no monitor serial (Led 30%)
}
void QuarentaLed() { //Config Led:
  motors.setSpeedC(40); //Led 40%.
  Serial.println("Led 40%"); //Escreve no monitor serial (Led 40%)
}
void CinquentaLed() { //Config Led:
  motors.setSpeedC(50); //Led 50%.
  Serial.println("Led 50%"); //Escreve no monitor serial (Led 50%)
}
void SesentaLed() { //Config Led:
  motors.setSpeedC(60); //Led 60%.
  Serial.println("Led 60%"); //Escreve no monitor serial (Led 60%)
}
void SetentaLed() { //Config Led:
  motors.setSpeedC(70); //Led 70%.
  Serial.println("Led 70%"); //Escreve no monitor serial (Led 70%)
}
void OitentaLed() { //Config Led:
  motors.setSpeedC(80); //Led 80%.
  Serial.println("Led 80%"); //Escreve no monitor serial (Led 80%)
}
void NoventaLed() { //Config Led:
  motors.setSpeedC(90); //Led 90%.
  Serial.println("Led 90%"); //Escreve no monitor serial (Led 90%)
}
void CemLed() { //Config Led:
  motors.setSpeedC(100); //Led 100%.
  Serial.println("Led 100%"); //Escreve no monitor serial (Led 100%)
}