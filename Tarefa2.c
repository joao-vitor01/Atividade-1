#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define RED_LED 11    // GPIO para LED Vermelho
#define YELLOW_LED 12 // GPIO para LED Amarelo
#define GREEN_LED 13  // GPIO para LED Verde

volatile int state = 0; // Estado do semáforo

// Callback do temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    // Desligar todos os LEDs antes de mudar o estado
    gpio_put(RED_LED, 0);
    gpio_put(YELLOW_LED, 0);
    gpio_put(GREEN_LED, 0);
    
    // Mudar o estado do semáforo
    switch (state) {
        case 0:
            gpio_put(RED_LED, 1);
            state = 1;
            printf("Sinal: VERMELHO\n");
            break;
        case 1:
            gpio_put(YELLOW_LED, 1);
            state = 2;
            printf("Sinal: AMARELO\n");
            break;
        case 2:
            gpio_put(GREEN_LED, 1);
            state = 0;
            printf("Sinal: VERDE\n");
            break;
    }
    return true; // Mantém o temporizador ativo
}

int main() {
    stdio_init_all();
    
    gpio_init(RED_LED);
    gpio_set_dir(RED_LED, GPIO_OUT);
    gpio_init(YELLOW_LED);
    gpio_set_dir(YELLOW_LED, GPIO_OUT);
    gpio_init(GREEN_LED);
    gpio_set_dir(GREEN_LED, GPIO_OUT);
    
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);
    
    while (1) {
        printf("Sistema rodando...\n");
        sleep_ms(1000);
    }
}
