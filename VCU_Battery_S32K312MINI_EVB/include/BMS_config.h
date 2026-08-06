#define NIMIC __asm volatile ("nop");  //asta e un breakpoint universal. NU il sterg ca l-am cautat de m-a luat naiba
#define useUART_messaging true //daca folosim si scrierea pe UART, obligatoriu la utilizarea chargerului
#define useCAN_messaging true //daca folosim si scrierea pe UART, obligatoriu la utilizarea chargerului
#define useCHARGER false
#define numberOfFailsBeforeAMS 1 //cate sampleuri eronate imi trebuie inainte sa dau trigger la AMS
#define OFFSET_ADC_thermistor -3000 //cat adaugam/scadem din termistori ca sa aduce caracteristica la ambient

#define overVoltageCelula 420000 //4.2V cf datasheet
#define underVoltageCelula 250000 //2,5V cf datasheet

#define chargeVoltage 1008 //100,8V
#define chargeCurrent 300 //30,0A din max 32A
