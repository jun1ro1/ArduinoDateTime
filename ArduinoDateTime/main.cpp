//
//  main.cpp
//  ArduinoDateTime
//
//  Created by OKU Junichirou on 2015/10/04.
//  Copyright © 2015年 OKU Junichirou. All rights reserved.
//

#include <iostream>
#include "J1Date.cpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    J1Date d1 = J1Date(15,10,5);
    int    ds = d1.days();
    J1Date d2 = J1Date(ds);
    std::string s = (d1 == d2) ? "OK" : "NG";
    std::cout << d1.str() << " : " << ds << " : " << d2.str() << " : " << s << std::endl;
   
    d1 = J1Date(0,1,1);
    ds = d1.days();
    d2 = J1Date(ds);
    s = (d1 == d2) ? "OK" : "NG";
    std::cout << d1.str() << " : " << ds << " : " << d2.str() << " : " << s << std::endl;
    
    d1 = J1Date(1,1,1);
    ds = d1.days();
    d2 = J1Date(ds);
    s = (d1 == d2) ? "OK" : "NG";
    std::cout << d1.str() << " : " << ds << " : " << d2.str() << " : " << s << std::endl;

    d2 = J1Date(99,12,31);
    d1 = J1Date(00,01,01);
    int dl = d2.days();
    for (int d = 0; d <= dl; d++) {
        d2 = J1Date(d);
        if (d1 != d2) {
            std::cout << "NG "  << d1.str() << " : " << d2.str() << std::endl;
        }
        else if (d1.year() % 10 ==0 && d1.month() == 1 && d1.day() == 1) {
            std::cout << d1.str() << " : " << d2.str() << std::endl;
        }
        
        ++d1;
    }
    
    return 0;
}
