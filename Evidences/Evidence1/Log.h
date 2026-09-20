#ifndef Log_h
#define Log_h
#include <vector>
#include <iostream>
#include <string>
using namespace std;

struct Log{
    int year;
    string month;
    int day;
    string time;
    string ip;
    string message;
    string key;
    // constructores
    Log();
    Log(int year, string month, int day, string time,
        string ip, string message, string key);
    // metodos
    string createKey();

    bool operator>(const Log& other) const;
    bool operator<(const Log& other) const;
    bool operator>=(const Log& other) const;
    bool operator<=(const Log& other) const;
    bool operator==(const Log& other) const;
};

// constructor vacio
Log::Log(){
    year = 0;
    month = "";
    day = 0;
    time = "";
    ip = "";
    message = "";
    key = "";
}
// constructor con datos
Log::Log(int year, string month, int day, string time,
         string ip, string message, string key){

    this->year = year;
    this->month = month;
    this->day = day;
    this->time = time;
    this->ip = ip;
    this->message = message;
    this->key = key;
}
// crear llave para ordenar por fecha y hora
string Log::createKey(){

    string numMonth;

    if(month == "Jan"){
        numMonth = "01";
    }
    else if(month == "Feb"){
        numMonth = "02";
    }
    else if(month == "Mar"){
        numMonth = "03";
    }
    else if(month == "Apr"){
        numMonth = "04";
    }
    else if(month == "May"){
        numMonth = "05";
    }
    else if(month == "Jun"){
        numMonth = "06";
    }
    else if(month == "Jul"){
        numMonth = "07";
    }
    else if(month == "Aug"){
        numMonth = "08";
    }
    else if(month == "Sep"){
        numMonth = "09";
    }
    else if(month == "Oct"){
        numMonth = "10";
    }
    else if(month == "Nov"){
        numMonth = "11";
    }
    else if(month == "Dec"){
        numMonth = "12";
    }

    string numDay;

    if(day < 10){
        numDay = "0" + to_string(day);
    }
    else{
        numDay = to_string(day);
    }

    key = to_string(year) + numMonth + numDay + time;

    return key;
}

// operadores
bool Log::operator>(const Log& other) const{
    return key > other.key;
}

bool Log::operator<(const Log& other) const{
    return key < other.key;
}

bool Log::operator>=(const Log& other) const{
    return key >= other.key;
}

bool Log::operator<=(const Log& other) const{
    return key <= other.key;
}

bool Log::operator==(const Log& other) const{
    return key == other.key;
}

bool fechaValida(string month, int day, int year, string time){

    bool mesValido = false;

    if(month == "Jan" || month == "Feb" || month == "Mar" ||
       month == "Apr" || month == "May" || month == "Jun" ||
       month == "Jul" || month == "Aug" || month == "Sep" ||
       month == "Oct" || month == "Nov" || month == "Dec"){
        mesValido = true;
    }

    if(!mesValido){
        return false;
    }

    if(day < 1 || day > 31){
        return false;
    }

    if(year < 2000 || year > 2100){
        return false;
    }

    if(time.size() != 8 || time[2] != ':' || time[5] != ':'){
        return false;
    }

    return true;
}

#endif