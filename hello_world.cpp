#include <iostream>
#include <string>

int main(){
	std::string name;
	std::cout<<"Your name: ";
	std::getline(cin, name); 
	std::cout<<"Hello world from "<<name<<std::endl;
}
