#ifndef Log_h// instruccion para el compilador
#include<vector>
#include <iostream>
#include<string>
using namespace std;

struct Log{
    int year;
    string month;
    int day;
    string time;
    string ip;
    string message;
    string key;
    //constructores
    Log();
    Log(int year; string month, int day, string time, string ip, string message, string key);
    //metodos
    string createKey();
    bool operator>(const Log&other)const;
    bool operator<(const Log&other)const;
    bool operator>=(const Log&other)const;
    bool operator<=(const Log&other)const;
    bool operator==(const Log&other)const;
};

bool Log:: operator>(const Log&lother,const{
    return key>other.key;
}


#define Log_h