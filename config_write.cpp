#include "interfaces.hpp"
#include "my_string.hpp"

char* Parcer_ini::config_write(const config_t* __config)
{
	char* result = new char[MAX_FILE_SIZE];
	result[0] = '\0'; //init for my_strcpy
	
	//write the substruct day:
	my_strcpy(result, "[day]\n");
	
	//comment for people-reading format
	my_strcpy(result, ";sunrise=");
	my_strcpy(result, ctime(&(__config->day.sunrise)));
	my_strcpy(result, "sunrise=");
	my_strcpy(result, uitoa((unsigned int)__config->day.sunrise));
	my_strcpy(result, "\n");
	
	//comment for people-reading format
	my_strcpy(result, ";sunset=");
	my_strcpy(result, ctime(&(__config->day.sunrise)));
	my_strcpy(result, "sunset=");
	my_strcpy(result, uitoa((unsigned int)__config->day.sunset));
	my_strcpy(result, "\n");
	
	//write the substruct pwm:
	my_strcpy(result, "\n[pwm]\n");
	
	my_strcpy(result, "ch1=");
	my_strcpy(result, uitoa(__config->pwm.ch1));
	my_strcpy(result, "\n");
	//////////////////////////////////////////////////////////
	my_strcpy(result, "ch2=");
	my_strcpy(result, uitoa(__config->pwm.ch2));
	my_strcpy(result, "\n");
	
	my_strcpy(result, "ch3=");
	my_strcpy(result, uitoa(__config->pwm.ch3));
	my_strcpy(result, "\n");
	
	my_strcpy(result, "ch4=");
	my_strcpy(result, uitoa(__config->pwm.ch4));
	my_strcpy(result, "\n");
	
	my_strcpy(result, "ch5=");
	my_strcpy(result, uitoa(__config->pwm.ch5));
	my_strcpy(result, "\n");
	
	//write the substruct wifi:
	my_strcpy(result, "\n[wifi]\n");
	
	my_strcpy(result, "ssid=");
	my_strcpy(result, __config->wifi.ssid);
	my_strcpy(result, "\n");
	
	my_strcpy(result, "pass=");
	my_strcpy(result, __config->wifi.pass);
	
	return result;
}

