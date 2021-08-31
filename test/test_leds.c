/*
Prendo un led
Apago un led
Determinar si un led esta prendido
Determinar si un led esta apagado
Prendo todos los leds en una peracion
Apago todos los leds en una operacion
Ver si los indices corresponden con los leds
Secuencia del primero al ultimo
Prender un led sin afectar al resto
Valores de borde para los parametros
Verificar que funciona con logica positiva
Valores invalidos para los parametros
*/

#include "leds.h"
#include "unity.h"

uint16_t puerto;

void setUp(void)
{
    LedsInit(&puerto);
}

void tearDown(void)
{
}

/* Cuando inicializo el controlador todos los leds quedan apagados*/
void test_ledsApagadosDespuesDeInicio(void)
{
    uint16_t puerto = 0xFFFF;
    LedsInit(&puerto);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto);
}

/* Prendo un led*/
void test_prenderUnLed(void)
{
    uint16_t led = 3;
    LedsTurnOn(led);
    TEST_ASSERT_EQUAL_HEX16(1 << (led - 1), puerto);
}

/* Apago un led*/

void test_apagoUnLed(void)
{
    uint16_t led = 2;
    LedsTurnOn(led);
    LedsTurnOff(led);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto);
}

/* Prender un led si afectar al resto*/

void test_prenderApagarVariosLeds(void)
{
    uint16_t led = 3;
    LedsTurnOn(led);
    LedsTurnOn(5);
    LedsTurnOff(5);
    TEST_ASSERT_EQUAL_HEX16(1 << (led - 1), puerto);
}

/* Prender todos los leds en una operacion*/
void test_prenderTodosLedsJuntos(void)
{
    AllLedsTurnOn();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, puerto);
}

/* Apagar todos los leds en una operacion*/
void test_apagarTodosLedsJuntos(void)
{
    AllLedsTurnOn();
    AllLedsTurnOff();
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto);
}

/* Determinar si un led esta encendido*/
void test_determinarLedEncendido(void)
{
    uint16_t led = 3;
    LedsTurnOn(led);
    TEST_ASSERT_TRUE(LedIsOn(led));
}

/* Determinar si un led esta apagado*/

void test_determinarLedApagado(void)
{
    uint16_t led = 3;
    TEST_ASSERT_FALSE(LedIsOn(led));
}