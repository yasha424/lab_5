#include "Point.hpp"
Point::Point(double Longitude, double Latitude, string Type, string SubType, string Name, string Adress){
    longitude = Longitude;
    latitude = Latitude;
    type = Type;
    subtype = SubType;
    name = Name;
    adress = Adress;
}

void Point::print(){
    cout << "Широта: " << latitude << ", Довгота: " << longitude << endl << "Тип: "
              << type << ", Підтип: " << subtype << "\nНазва: " << name << ", Адреса: " << adress << endl;
}

void Point::make_point(string str){
    
}
