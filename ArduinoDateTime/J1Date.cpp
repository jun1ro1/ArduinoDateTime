//
//  Date.cpp
//  ArduinoDateTime
//
//  Created by OKU Junichirou on 2015/10/04.
//  Copyright © 2015年 OKU Junichirou. All rights reserved.
//

#include <string>
#include <ostream>
#include <sstream>
#include <stdio.h>
#include "J1Date.hpp"

constexpr static unsigned char _days[2][12] = {
    { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
    { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};


class J1Date {
protected:
    unsigned char _year;
    unsigned char _month;
    unsigned char _day;

public:
    // constructors
    J1Date( unsigned char year, unsigned char month, unsigned char day ) {
        this->_year  = year;
        this->_month = month;
        this->_day   = day;
    }
    
    J1Date( unsigned int days ) {
        this->_year  = 0;
        this->_month = 0;
        this->_day   = 0;
        // year
        int dd = isLeap(this->_year) ? 366 : 365;
        while (days >= dd) {
            days -= dd;
            this->_year++;
            dd = isLeap(this->_year) ? 366 : 365;
        }
        // month
        dd = _days[isLeap(this->_year) ? 1 : 0][this->_month];
        while (days >= dd) {
            days -= dd;
            this->_month++;
            dd = _days[isLeap(this->_year) ? 1 : 0][this->_month];
        }
        this->_month++;
        this->_day = days + 1;
    }

    
    // utility functions
    static bool isLeap( int year ) {
        year = year + 2000;
        return ( year % 400 == 0 ) || (( year % 4 == 0 ) && ( year % 100 !=0 ));
    }
    
    // accessors
    unsigned char year() const {
        return this->_year;
    }
    
    unsigned char month() const {
        return this->_month;
    }
    unsigned char day() const {
        return this->_day;
    }
    
    // properties
    unsigned int days() const {
        int days = 0;
        
        // before the year
        for (int y = 0; y <= this->_year - 1; y++) {
            days += isLeap(y) ? 366 : 365;
        }
        
        // this year and before th month
        for (int m = 0; m < this->_month-1; m++) {
            days += (int)_days[ this->isLeap(this->_year)? 1 : 0][m];
        }
        
        days += this->_day - 1;
        
        return days;
    }

    
    // operators
    bool operator== (const J1Date &rhs) {
        return (this->_year == rhs._year) && (this->_month == rhs._month)
        && (this->_day == rhs._day);
    }
    
    bool operator!= (const J1Date &rhs){
        return !(*this == rhs);
    }
    
    J1Date operator+ (int days) {
        return J1Date(this->days() + days);
    }
    
    J1Date& operator++ () {
        J1Date d = (*this + 1);
        this->_year  = d._year;
        this->_month = d._month;
        this->_day   = d._day;
        return *this;
    }
  
    // utility functions
    std::string str() const {
        char str[16];
        sprintf(str, "%d-%02d-%02d", this->_year + 2000, this->_month, this->_day);
        return str;
    }
    

};
