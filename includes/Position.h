#ifndef POSITION_H
#define POSITION_H

/*****************************************************
 * Position Class
Base class representing an arbitrary position on a 2D integer valued board

Position objects have an x attribute representing their x-coordinate, and a y
attribute representing their y-coordinate

Position objects support a distance function (indicating distance from another
Position), but not sorting
******************************************************/

class Position
{
  friend ostream& operator<<(ostream&, const Position&);
  public:
    Position(int=0, int=0);
    Position(const Position&);
    ~Position();
    Position& operator=(const Position&);
    bool operator==(const Position&) const;
    int getX() const;
    int getY() const;
    void setX(int);
    void setY(int);
    void setPosition(int, int);
    double distanceFrom(Position&);

  private:
    int x;
    int y;
};

#endif
