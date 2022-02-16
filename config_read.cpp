
#include "interfaces.hpp"
#include <cctype>
#include "my_string.hpp"
#include <cstdint>
#include <cstring>

struct pair_t {
	char* name;
	char* value;
};

int get_section_name(const char** section_name, char* name);

pair_t* fill_up_line(const char** current_char);

int get_white_sp(const char** current_char);

int Parcer_ini::config_read(const char* __ini_data, config_t* __out_config)
{
	int cSec = 0;
	
	char* name = new char[MAX_SECTION_NAME_SIZE];
	pair_t *tmp_pair;
	
	char c;
	
	if( !get_white_sp(&__ini_data)) {
		printf("Bad file format or there is not the file!!!\n");
		return 0;
	}
	
	while((c = *__ini_data++) && cSec < COUNT_SECTIONS) { 	
			if (c == '[' ) {
				get_section_name(&__ini_data, name); 
			} else if(cSec == 3) {
				printf("All file is read\n");
			}
			else{;
				printf("\nBad format for section name!!!\n");
				return -1;
			}
			
			//change section for fill up the struct
			if(my_strcmp(name, "day") == 0) {				
				for(int i = 0; i < 2; i++) { ////////////define
					tmp_pair = fill_up_line(&__ini_data);
					if(my_strcmp(tmp_pair->name, "sunrise") == 0) {
						__out_config->day.sunrise =   (time_t)atoi(tmp_pair->value); 
						//test print
						//printf("__out_config->day.sunrise = %d\n", __out_config->day.sunrise );
					
					} else if(my_strcmp(tmp_pair->name, "sunset") == 0) {
						__out_config->day.sunset = (time_t)atoi(tmp_pair->value);
						//test print
						//printf("__out_config->day.sunset = %d\n", __out_config->day.sunset );
					} else {
						printf("???Bad file format(bad name for config data)\n");
						return 0;
					}
					
					//printf("After fill_up_st_day(&__ini_data):\n %s \n", __ini_data);
				}
				
				free(tmp_pair);
				cSec++;
			}
			
			else if(my_strcmp(name, "pwm") == 0) {
				for(int i = 0; i < 5; i++) { ////////////define
					tmp_pair = fill_up_line(&__ini_data);
					
					///print
					
					if(my_strcmp(tmp_pair->name, "ch1") == 0) {
						__out_config->pwm.ch1 =   (uint32_t)atoi(tmp_pair->value);
						//test print
						//printf("__out_config->pwm.ch1 = %d\n", __out_config->pwm.ch1 );
					
					} else if(my_strcmp(tmp_pair->name,"ch2") == 0) {
						__out_config->pwm.ch2 =  (uint32_t)atoi(tmp_pair->value);
						//test print
						//printf("__out_config->pwm.ch2 = %d\n", __out_config->pwm.ch2 );
						
					} else if(my_strcmp(tmp_pair->name,"ch3") == 0) {
						__out_config->pwm.ch3 =   (uint32_t)atoi(tmp_pair->value);
						//test print
						//printf("__out_config->pwm.ch3 = %d\n", __out_config->pwm.ch3 );
					
					} else if(my_strcmp(tmp_pair->name,"ch4") == 0) {
						__out_config->pwm.ch4 =   (uint32_t)atoi(tmp_pair->value);
						//test print
						//printf("__out_config->pwm.ch4 = %d\n", __out_config->pwm.ch4 );
					
					}else if(my_strcmp(tmp_pair->name,"ch5") == 0) {
						__out_config->pwm.ch5 =   (uint32_t)atoi(tmp_pair->value);
						//test print
						//printf("__out_config->pwm.ch5 = %d\n", __out_config->pwm.ch5 );
					
					} else{
						printf("???Bad file format(bad name for config data)\n");
						return 0;
					}
					//test print
					//printf("After fill_up_line(&__ini_data):\n %s \n", __ini_data);
				}
				free(tmp_pair);		
				cSec++;
			}
			
			else if(my_strcmp(name, "wifi") == 0) {
				//fill_up_st_wifi(&__ini_data);
				//cSec++;
				
				//////////////////////////
				for(int i = 0; i < 2; i++) { ////////////define
				tmp_pair = fill_up_line(&__ini_data);
				
				//test print
				//printf("\ntmp->name = %s\n", tmp_pair->name);
				
				if(my_strcmp(tmp_pair->name, "ssid") == 0) {
					__out_config->wifi.ssid =   tmp_pair->value; //my_strcpy(result, ctime(&(__config->day.sunrise)));
					//test print
					//printf("__out_config->wifi.ssid = %s\n", __out_config->wifi.ssid );
				} else if(my_strcmp(tmp_pair->name, "pass") == 0) {
					__out_config->wifi.pass = tmp_pair->value;
					//test print
					//printf("__out_config->wifi.pass = %s\n", __out_config->wifi.pass );
				} else {
					printf("!!!!Bad file format(bad name for config data)\n");
					return 0;
				}
				}
				
				free(tmp_pair);
				
				cSec++;
			}
			
			else {
				printf("There are not the same name of section!!!\n");
				return 0;
			}

			if( !get_white_sp(&__ini_data) && cSec < 3) {
				printf("Bad file format!\n");
				return 0;
			}
	
	}
	
	delete [] name;
	
	return cSec;
}

int get_section_name(const char** current_char, char* name)
{
	//int err = 0;
	int c_count = 0;
	char c; // insted of EOF -> '\0' we can use the char!
	char* tpr_name = name;
	
	while((c = *(*current_char)++) && c != ']' && c_count < MAX_SECTION_NAME_SIZE) {
		if(c == ' ' || c == '\t' || c == '\n') 
			;
		else if(isalpha(c) || isdigit(c) || c == '_') 
			*tpr_name++ = c;
			c_count++;
		}
		*tpr_name = '\0';
		
	if(c == '\0') return 1;
	if(c_count > MAX_SECTION_NAME_SIZE) return 2;
		
	return 0;
}

pair_t* fill_up_line(const char** current_char)
{
	pair_t* result = (pair_t*)malloc(sizeof(pair_t));
	
	int n_str = 2; //////////////////#def max 2
	int char_counter  = MAX_SECTION_NAME_SIZE; //////////////////#def max 20
	
	char* name = (char*)malloc(MAX_SECTION_NAME_SIZE*sizeof(char));
	char* tpr_name = name;
	if( !get_white_sp(current_char)) {
		printf("Bad file format!\n");
		return NULL;
	}
	
	char c;
	while((c = **current_char) != '=') {
		if(char_counter >0 && (isalpha(c) || isdigit(c) || c == '_') ) {
			*tpr_name++ = c;
			char_counter--;
		} 
		else if (char_counter < 0) {
			printf("Too long name for variable!\n");
			return NULL;
		}
		
		(*current_char)++;
	
	}
	
	*tpr_name = '\0';
	
	result->name = name;
	
	(*current_char)++; //delete '='
		
	char* value = (char*)malloc(MAX_VALUE_SIZE*sizeof(char));
	char* tpr_value = value;
	//char_counter = MAX_WHITE_SIMBOLS_TOGETHER; 
	if( !get_white_sp(current_char)) {
		printf("Bad file format!\n");
		return NULL;
	}
		while((c = *(*current_char)++) && c != '\n' && char_counter > 0) {
			*tpr_value++ = c;
			char_counter--;
		} 
		
		if (char_counter < 0) {
			printf("Too long name for variable!\n");
			return NULL;
		}
	
	*tpr_value = '\0';
	
	result->value = value;
	
	return result;
}

int get_white_sp(const char** current_char) 
{
	char c;
	while((c = (**current_char)) && ( c == '\n' || c == ' ' || c == '\t' )) {
		(*current_char)++;
	}
	
	if(c == ';') {
		while((c = (**current_char)) != '\n') {
			(*current_char)++;
		}
	}
	
	while((c = (**current_char)) && ( c == '\n' || c == ' ' || c == '\t' )) {
		(*current_char)++;
	}
		
	if(  c != '\n' || c != ' ' || c != '\t' ) *current_char--;
	if(c == '\0')
		return 0;
	else
		return 1;
}
