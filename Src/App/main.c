#include "Port.h"
#include "Dio.h"
#include "Mcu_Hw.h"
#include "Port_Cfg.h"
#include "Timer.h"
#include "IntCtrl.h"

extern const Port_ConfigType Port_Config[];
extern const Gpt_ConfigType Gpt_Config[];



int main ( void )
{
	Port_Init(Port_Config);
	IntCrtl_Init();
	Gpt_Init(Gpt_Config);
	Gpt_StartTimer(GPT_16_32_BIT_TIMER0,500);
	Gpt_EnableNotification(GPT_16_32_BIT_TIMER0);

	while (1) 
	{  
			
	}
}