# Atividade 1: Temporizador Periódico (Semáforo)

Este projeto implementa um semáforo utilizando o **Raspberry Pi Pico W** e a função `add_repeating_timer_ms()` da **Pico SDK**. Os LEDs mudam de estado a cada **3 segundos**, simulando um ciclo de trânsito.

## Requisitos do Projeto
- Utilizar **3 LEDs** (Vermelho, Amarelo e Verde) com **resistores de 330Ω**.
- Alterar o estado dos LEDs na ordem: **Vermelho → Amarelo → Verde → Vermelho**.
- O temporizador deve ter um **atraso de 3 segundos** por mudança de estado.
- Exibir mensagens na **porta serial** a cada 1 segundo.
- Código compatível com **BitDogLab**, utilizando os **GPIOs 11, 12 e 13** para o LED RGB.

## **Componentes Utilizados**
- Raspberry Pi Pico W
- LED Vermelho, Amarelo e Verde
- Resistores de 330Ω
- **BitDogLab** 

## 📝 **Como Executar**
1. Instale a **Pico SDK** e o **CMake**.
2. Compile o código e carregue no Raspberry Pi Pico W.
3. Conecte à **porta serial** para visualizar as mensagens.
