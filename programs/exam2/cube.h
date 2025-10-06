#ifndef CUBE_H
#define CUBE_H

class Cube {
private:
    int side;

public:
    Cube(int s = 1);         
    void setSide(int s);      
    int getSide() const;      
    void draw() const;        
};

#endif
