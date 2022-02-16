#pragma once

#define MAX_FILE_SIZE 10000
#define MAX_UINT_SIZE 11
#define MAX_VALUE_SIZE 11 // redefine #define MAX_UINT_SIZE 11
#define MAX_SECTION_NAME_SIZE 20
#define COUNT_SECTIONS 3
#define MAX_WHITE_SIMBOLS_TOGETHER 200

//C++
#include <iostream>//#include <stdio.h>
#include <string>
#include <fstream>

//C
#include <ctime>
#include <cstdlib> //exit()
#include <cstdint>

using std::cout;
using std::cin;
using std::endl;
using std::string;

using std::ofstream;
using std::ifstream;
using std::cerr;
using std::getline;

struct wifi_t {
	char* ssid;
	char* pass;
};

struct pwm_t {
	uint32_t ch1;
	uint32_t ch2;
	uint32_t ch3;
	uint32_t ch4;
	uint32_t ch5;
};

struct one_day_t {
	time_t sunrise;
	time_t sunset;
};

struct config_t {
	one_day_t day;
	pwm_t pwm;
	wifi_t wifi;
};

class Parcer_ini 
{
	config_t st_config;
	string file_path;
	
public:
	static int config_read(const char* __ini_data, config_t* __out_config);
	static char* config_write(const config_t* __config);
	static void print_structure(const config_t* config);
};







//int config_read(const char* __ini_data, config_t* __out_config);
//char* config_write(const config_t* __config);
//void print_structure(const config_t* config);
