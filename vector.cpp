#include <iostream>
#include <cmath>



class V3Vector{
public:
    explicit V3Vector(float _x=0, float _y=0, float _z=0){
        x=_x;
        y=_y;
        z=_z;
    }

    float getLength(){
        return sqrt(x*x + y*y + z*z);
    }

    float getX(){
        return x;
    }

    float getY(){
        return y;
    }

    float getZ(){
        return z;
    }


    void  addition (V3Vector a){
        x += a.getX();
        y += a.getY();
        z += a.getZ();
    }

    void subtraction(V3Vector a){
        x -= a.getX();
        y -= a.getY();
        z -= a.getZ();
    }

    float scalarMultiplication(V3Vector a){
        return x*a.getX() + y*a.getY() + z*a.getZ();
    }

    void multiplication(V3Vector a) {
        float new_x = y*a.getZ() - a.getY()*z;
        float new_y = -(x*a.getZ() - a.getX()*z);
        float new_z = x*a.getY() - a.getX()*y;
        x = new_x;
        y = new_y;
        z = new_z;
    }

    void multiplication(float _num){
        x *= _num;
        y *= _num;
        z *= _num;
    }

    
                                      
    V3Vector operator+(V3Vector a) const {
        V3Vector b = V3Vector(x, y, z);
        b.addition(a);
        return b;
    }

    V3Vector operator-(V3Vector a) const {
        V3Vector b = V3Vector(x, y, z);
        b.subtraction(a);
        return b;
    }

    V3Vector operator*(float a) const {
        V3Vector b = V3Vector(x, y, z);
        b.multiplication(a);
        return b;
    }

    float operator*(V3Vector a) {
        return scalarMultiplication(a);
    }

    V3Vector operator[](V3Vector a) const{
        V3Vector b = V3Vector(x, y, z);
        b.multiplication(a);
        return b;
    }

    private:
    float x;
    float y;
    float z;
};



int main() {
    float tmp;
    V3Vector a = V3Vector(1, 2, 3);
    V3Vector b = V3Vector(5, 2, 3);
    V3Vector c;
    std::cout<<"Vector a+b:"<<std::endl;
    c=a+b;
    std::cout<<"X:"<< c.getX()  <<"  Y:"<< c.getY()<<"  Z:"<< c.getZ() << std::endl;
    c=a-b;
    std::cout<<"Vector a-b:"<<std::endl;
    std::cout<<"X:"<< c.getX()  <<"  Y:"<< c.getY()<<"  Z:"<< c.getZ() << std::endl;
    std::cout<<"Vector a*b:" << std::endl;
    tmp =a*b;
    std::cout<< "Result: " << tmp << std::endl;
    std::cout<<"Vector a*5:" << std::endl;
    c=a*5;
    std::cout<<"X:"<< c.getX()  <<"  Y:"<< c.getY()<<"  Z:"<< c.getZ() << std::endl;
    return 0;
    
}