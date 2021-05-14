#include "Point.hpp"
Point::Point(double Longitude, double Latitude, std::string Type, std::string SubType, std::string Name, std::string Adress){
    longitude = Longitude;
    latitude = Latitude;
    type = Type;
    subtype = SubType;
    name = Name;
    adress = Adress;
}

void Point::print(){
    std::cout << "Широта: " << latitude << ", Довгота: " << longitude << std::endl << "Тип: "
              << type << ", Підтип: " << subtype << "\nНазва: " << name << ", Адреса: " << adress << std::endl;
}
