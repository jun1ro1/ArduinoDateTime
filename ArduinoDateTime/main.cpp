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
    
    J1Date d = J1Date(15,10,5);
    int ds = d.getDays();
    J1Date d2 = J1Date(00,0,0);
    d2.setDays(ds);
    std::cout << d.str() << " : " << ds << " : " << d2.str() << std::endl;
   
    d = J1Date(0,1,1);
    ds = d.getDays();
    d2 = J1Date(00,0,0);
    d2.setDays(ds);
    std::cout << d.str() << " : " << ds << " : " << d2.str() << std::endl;
    
    d = J1Date(1,1,1);
    ds = d.getDays();
    d2 = J1Date(00,0,0);
    d2.setDays(ds);
    std::cout << d.str() << " : " << ds << " : " << d2.str() << std::endl;
    
    return 0;
}
