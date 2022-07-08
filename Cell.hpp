#ifndef DEF_CELL
#define DEF_CELL

class Cell {
protected:
    bool character;
    
public:
    Cell();
    ~Cell();
    bool isOccupied();
    void setOccupied(bool occupied);
};

#endif