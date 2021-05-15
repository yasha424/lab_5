class Point{
public:
    double x, y;
    string type, subtype,
           name, address;

    Point(double _x,double _y, string _type, string _subtype, string _name, string _address){
        x = _x;
        y = _y;
        type = _type;
        subtype = _subtype;
        name = _name;
        address = _address;
    }
    double getX() const;
    double getY() const;
};