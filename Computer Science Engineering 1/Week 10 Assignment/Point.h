/*-------------------------------------------------------*/
/* Point class Chapter6_7 */
/* Filename: Point.h */
class Point
{
    // Type declaration statements
    // Data members.
private:
    double xCoord, yCoord; // Class attributes
public:
    // Declaration statements for class methods
    // Constructors for Point class
    Point();                   // default constructor
    Point(double x, double y); // parameterized constructor
    // Overloaded operators
    double operator-(const Point &rhs) const;
    bool operator==(const Point &rhs) const;
    // Accessor Methods Definitions
    double getX() const { return xCoord; }
    double getY() const { return yCoord; }
    // Mutator methods
    void setX(double newX);
    void setY(double newY);
};