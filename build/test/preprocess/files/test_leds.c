#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"
#include "src/leds.h"


uint16_t puerto;



void setUp(void)

{

    LedsInit(&puerto);

}



void tearDown(void)

{

}





void test_ledsApagadosDespuesDeInicio(void)

{

    uint16_t puerto = 0xFFFF;

    LedsInit(&puerto);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((puerto)), (

   ((void *)0)

   ), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prenderUnLed(void)

{

    uint16_t led = 3;

    LedsTurnOn(led);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << (led - 1))), (UNITY_INT)(UNITY_INT16)((puerto)), (

   ((void *)0)

   ), (UNITY_UINT)(43), UNITY_DISPLAY_STYLE_HEX16);

}







void test_apagoUnLed(void)

{

    uint16_t led = 2;

    LedsTurnOn(led);

    LedsTurnOff(led);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((puerto)), (

   ((void *)0)

   ), (UNITY_UINT)(53), UNITY_DISPLAY_STYLE_HEX16);

}







void test_prenderApagarVariosLeds(void)

{

    uint16_t led = 3;

    LedsTurnOn(led);

    LedsTurnOn(5);

    LedsTurnOff(5);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << (led - 1))), (UNITY_INT)(UNITY_INT16)((puerto)), (

   ((void *)0)

   ), (UNITY_UINT)(64), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prenderTodosLedsJuntos(void)

{

    AllLedsTurnOn();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFFF)), (UNITY_INT)(UNITY_INT16)((puerto)), (

   ((void *)0)

   ), (UNITY_UINT)(71), UNITY_DISPLAY_STYLE_HEX16);

}





void test_apagarTodosLedsJuntos(void)

{

    AllLedsTurnOn();

    AllLedsTurnOff();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((puerto)), (

   ((void *)0)

   ), (UNITY_UINT)(79), UNITY_DISPLAY_STYLE_HEX16);

}





void test_determinarLedEncendido(void)

{

    uint16_t led = 3;

    LedsTurnOn(led);

    do {if ((LedIsOn(led))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(87)));}} while(0);

}







void test_determinarLedApagado(void)

{

    uint16_t led = 3;

    do {if (!(LedIsOn(led))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(95)));}} while(0);

}
