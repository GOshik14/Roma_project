#include "interfaces.hpp"
#include <cstdint>


void Parcer_ini::print_structure(const config_t* config)
{	
	//one_day_t day;
	cout<< endl << "Print all lines from struct: " << endl << endl
		<< "Substruct day, type struct one_day_t:" << endl
		<< "sunrise = " << ctime(&(config->day.sunrise))  
		<< "sunset = " << ctime(&(config->day.sunset)) << endl
	
	//pwm_t pwm;
	<< "Substruct pwm, type struct pwm_t:" << endl
		<< "ch1 = " << config->pwm.ch1 << endl
		<< "ch2 = " << config->pwm.ch2 << endl
		<< "ch3 = " << config->pwm.ch3 << endl
		<< "ch4 = " << config->pwm.ch4 << endl
		<< "ch5 = " << config->pwm.ch5 << endl << endl
	
	//wifi_t wifi; 
	<< "Substruct wifi, type struct wifi_t:" << endl
		<< "ssid = " << config->wifi.ssid << endl
		<< "pass = " << config->wifi.ssid << endl;
	
	
}