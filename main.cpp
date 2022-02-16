#include "interfaces.hpp"
#include "my_string.hpp"

const char* path = "config.ini";

int main(int argc, char* argv[])
{
	config_t config;
	
	//fill up the config structure for writing example
	
	//write the substruct day:
	//time_t sunrise == sunset == "now", for example;
	config.day.sunrise = config.day.sunset = time(NULL);
		
	//write the substruct pwm:
	config.pwm.ch1 = 123;
	config.pwm.ch2 = 456;
	config.pwm.ch3 = 789;
	config.pwm.ch4 = 10;
	config.pwm.ch5 = 11;
	
	//write the substruct wifi
	config.wifi.ssid = (char*)"admin";
	config.wifi.pass = (char*)"admin";
	
	//empty structure for read file and write config_t
	config_t * tmp_empty_config = new config_t;
	
	
	if (argc == 1){
		cout << "You should write the command (read or write) after calling program! Restart programm and try again." << endl <<
			"For example: >ini_parcer.exe write or >ini_parcer.exe read." << endl;
	} else if(argc == 2 && string(argv[1]) == "write") {
		
		//create stream for write data to the file
		ofstream ofstrm;
		ofstrm.open(path);
		
		//could not open file for writing
		if(!ofstrm.is_open()) {
			cerr << "config.ini could not be opened for writing!" << endl;
			exit(1); 
		}
		
		ofstrm << Parcer_ini::config_write(&config);
		
		ofstrm.close();
		
	} else if(argc == 2 && string(argv[1]) == "read") {

		ifstream ifstrm;
		ifstrm.open(path);
		
		//could open file for reading
		if(!ifstrm.is_open()) {
			cerr << "config.ini could be opened for reading!" << endl;
			exit(1);
		}
		
		char* result = new char[MAX_FILE_SIZE];
		char* tmp_str_ptr = result;
		
		while(!ifstrm.eof())
		{
			*tmp_str_ptr++ = ifstrm.get();
		}
		//*tmp_str_ptr = '\0'; //null-term string 
		
		Parcer_ini::config_read(result, tmp_empty_config);
		
		ifstrm.close();
		delete [] result;
		
	} else if(argc == 3 && string(argv[1]) == "read" && string(argv[2]) == "print") {

		ifstream ifstrm;
		ifstrm.open(path);
		
		//could open file for reading
		if(!ifstrm.is_open()) {
			cerr << "config.ini could be opened for reading!" << endl;
			exit(1);
		}
		
		char* result = new char[MAX_FILE_SIZE]; 
		char* tmp_str_ptr = result;
		
		while(!ifstrm.eof())
		{
			*tmp_str_ptr++ = ifstrm.get();
		}
		//*tmp_str_ptr = '\0'; //null-term string 
		
		Parcer_ini::config_read(result, tmp_empty_config);
		
		ifstrm.close();
		
		Parcer_ini::print_structure(tmp_empty_config);	
		
		delete [] result;
	}
	else {
		cout << "You called bad command! Restart programm and try again." << endl;
	}
	
	
	return 0;
}
