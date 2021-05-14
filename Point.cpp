#include "Point.hpp"
Point::Point(double Latitude, double Longitude, std::string Type, std::string SubType, std::string Name, std::string Adress){
    latitude = Latitude;
    longitude = Longitude;
    type = Type;
    subtype = SubType;
    name = Name;
    adress = Adress;
}

void Point::print(){
    std::cout << "Широта: " << latitude << ", Довгота: " << longitude << std::endl << "Тип: "
              << type << ", Підтип: " << subtype << "\nНазва: " << name << ", Адреса: " << adress << std::endl;
}
