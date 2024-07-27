//Codigo feito por Davi Adams 07/2024 @davi.adams_2010.   .
//https://github.com/DaviAdams/YanBot.git                 .
//.........................................................
//Feito para usar na placa da Robocore BlackBoard Rocky.  .
//App celular  Bluetooth RC Control.                      .
//.........................................................
//Para fazer upload do codigo selecionar placa ESP32 Dev  .
//.........................................................
#include <RoboCore_Rocky.h> //Biblioteca Rocky.
#include "BluetoothSerial.h" //Biblioteca bluetooth ESP32.
#include <Arduino.h> //Biblioteca Arduino.

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
    }
    else { //Se o app nao mandar nada...
      parado(); ///fica parado.
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