This will be your last Lab Assignment :)

Create a base class called Vehicle that has the manufacturer's name (type
string), number of cylinders in the engine (type int), and owner (type
string). Include a default constructor that would initialize the manufacturer
to an empty string and the number of cylinders to 0, and call the default
constructor of the Person class to initialize the owner. Also include a
constructor that would accept the manufacturer's name, number of cylinders,
and a Person object to initialize the corresponding member variables. Include
the aproppriate get/set member functions for all member variables.
Then create a class called Truck that is derived from the Vehicle class
and has these additional properties: the load capacity in tons (type double)
and towing capacity in pounds (type int). Include a default constructor that
would set all member variables to 0 and call the default constructor of class
Vehicle; also include a constructor that would initialize the object to the
values of its arguments. Overload the << operator such that it outputs a
string of the following format:

Mack (12 cylinders, 22 tons maximum load, 17000 lbs towing capacity), owned by Jim

Write a test program that would prompt the user for the number of trucks
they wish to enter, then for each of the trucks read in the data from standard
input, and finally output the "winner" -- i.e. the truck that has the greatest
combined load and towing capacity.

Sample Output:

Enter·the·number·of·contestants:2↵ Enter·contestant·1·info.↵ Enter·truck's·manufacturer:Ford↵ Enter·truck's·number·of·cylinders:12↵ Enter·truck's·owner:John↵ Enter·truck's·maximum·load·(in·tons):20.5↵ Enter·truck's·maximum·towing·capacity·(in·pounds):13000↵ Enter·contestant·2·info.↵ Enter·truck's·manufacturer:Dodge↵ Enter·truck's·number·of·cylinders:8↵ Enter·truck's·owner:Richard↵ Enter·truck's·maximum·load·(in·tons):18↵ Enter·truck's·maximum·towing·capacity·(in·pounds):10150↵The·winner·is:·Ford·(12·cylinders,·20.5·tons·maximum·load,·13000·lbs·towing·capacity),·owned·by·John↵

To get you started here is the Vehicle class and main,  you will need to write the Truck class:

class Vehicle {
    protected:
        string make;
        int cylinders;
        string owner;
    public:
        Vehicle(): make(""), cylinders(0), owner(string()) {}
        Vehicle(string m, int c, string own): make(m), cylinders(c), owner(own) {}

        string getMake() {
            return make;
        }
        int getCyl() {
            return cylinders;
        }
        string getOwner() {
            return owner;
        }

        void setMake(string str) {
            make = str;
            return;
        }
        void setCyl(int n) {
            cylinders = n;
            return;
        }
        void setOwner(string str) {
            owner = str;
            return;
        }
};


"int main() {
    Truck *trucks[5];
    string tmp_make, tmp_own;
    int tmp_cyl, tmp_tow;
    double tmp_max;
    int n=0;
    cout << "Enter the number of contestants:";
    cin >> n;
    for ( int i=0; i<n; i++ ) {
        cout << "Enter contestant " << i+1 << " info.\n";
        cout << "Enter truck's manufacturer:";
        cin >> tmp_make;
        cout << "Enter truck's number of cylinders:";
        cin >> tmp_cyl;
        cout << "Enter truck's owner:";
        cin >> tmp_own;
        cout << "Enter truck's maximum load (in tons):";
        cin >> tmp_max;
        cout << "Enter truck's maximum towing capacity (in pounds):";
        cin >> tmp_tow;
        trucks[i] = new Truck(tmp_max, tmp_tow, tmp_make, tmp_cyl, tmp_own);
    }
    cout << "The winner is: " << *trucks[getWinner(trucks, n)] << endl;
    for ( int i=0; i<n; i++ )
        delete trucks[i];
    return 0;
}"