#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Dish object
struct Dish
{
    string dishName;
    bool isClean;
};

// Prints intro instructions
void displayInstructions()
{
    cout << "Welcome to Eric's Restaurant" << endl;
    cout << "Where only one guest can be attended at a time. Let me see if I can seat you." << endl;
}

// Checks if any guests are in the restaurant
bool checkQueue(queue<string> &inRestaurantQueue)
{
    string guestName = "";
    // If no guest are in restaurant, let them in (add to restaurant queue)
    if (inRestaurantQueue.empty())
    {
        cout << "Hello, my name is Eric. What's your name?" << endl;
        cin >> guestName;

        // Add name to restaurant queue
        inRestaurantQueue.push(guestName);
        return true;
    }

    return false;
}

// Attend guest
void attendGuest(queue<string> &inRestaurantQueue, stack<Dish *> &dishStack)
{
    vector<string> menuVector = {"burger", "pizza", "wings"};
    string foodItem = "", guestName = "";
    bool foodValid = false;

    guestName = inRestaurantQueue.front();

    cout << "Awesome " + guestName + ", what can we get for you today from our menu? (burger, pizza, wings)" << endl;

    while (!foodValid)
    {
        cin >> foodItem;
        cin.ignore();

        // Converts all characters in food item to lower case
        for_each(foodItem.begin(), foodItem.end(), [](char &c)
                 { c = ::tolower(c); });

        auto it = find(menuVector.begin(), menuVector.end(), foodItem);
        if (it == menuVector.end())
        {
            cout << "Sorry. That item is not in our menu. Please make another selection." << endl;
            continue;
        }
        {
            cout << "Awesome. We'll be right back with your " + foodItem << endl;
            Dish *dish = new Dish();
            dish->dishName = foodItem;
            dish->isClean = false;
            dishStack.push(dish);
            foodValid = true;
        }

        cout << "Here's your " + foodItem << endl;
        cout << "Enjoy!" << endl;
        cout << endl;
    }
}

// Push name in last by popping from front until size is 0
void queueHelper2(queue<string> guestQueue, int queueSize)
{
    // Base condition
    if (queueSize <= 0)
        return;

    // Pop front element and push this last name in queue
    guestQueue.push(guestQueue.front());
    guestQueue.pop();

    // Recursive call for pushing name
    queueHelper2(guestQueue, queueSize - 1);
}

// Push name in the queue while keeping it sorted
void queueHelper(queue<string> guestQueue, string name, int queueSize)
{
    // Base condition
    if (guestQueue.empty() || queueSize == 0)
    {
        guestQueue.push(name);
        return;
    }

    // If name is before name in front
    else if (name <= guestQueue.front())
    {
        guestQueue.push(name);

        // Recursive call for inserting front name of queue to last
        queueHelper2(guestQueue, queueSize);
    }
    else
    {
        // Push front name into last in queue
        guestQueue.push(guestQueue.front());
        guestQueue.pop();

        // Recursive call for pushing name in queue
        queueHelper(guestQueue, name, queueSize - 1);
    }
}

// Sort queue in alphabetical order
void sortQueue(queue<string> guestQueue)
{
    // Base case
    if (guestQueue.empty())
        return;

    // Get front element
    string frontName = guestQueue.front();

    // Remove front element
    guestQueue.pop();

    // Recursive call
    sortQueue(guestQueue);

    // Push current name into queue in alphabetical order
    queueHelper(guestQueue, frontName, guestQueue.size());
}

// Print names in queue
void printQueue(queue<string> guestQueue)
{
    cout << "These are the people in front of you: " << endl;
    while (!guestQueue.empty())
    {
        cout << guestQueue.front() << endl;
        guestQueue.pop();
    }
    cout << endl;
}

// Put customer in queue
void queueGuest(queue<string> &guestQueue, queue<string> &inRestaurantQueue)
{
    string guestName = "", currentAttendedGuestName = "";
    currentAttendedGuestName = inRestaurantQueue.front();
    cout << "Currently serving " + currentAttendedGuestName << endl;
    cout << "Sorry. It appears we are at max capacity of 1 guest." << endl;
    cout << "I can put you in queue. I just need your name" << endl;
    cin >> guestName;

    // Sort the queue in alphabetical order
    sortQueue(guestQueue);
    // Print the names in the queue
    printQueue(guestQueue);

    // Add next guest name to wait queue
    guestQueue.push(guestName);
}

// Dynamically deallocates dishes
void cleanDishes(stack<Dish *> dishStack)
{
    if (dishStack.size())
    {
        cout << "Dish has been washed" << endl;
        cout << endl;
        delete dishStack.top();
    }
}

bool checkOut(queue<string> &guestQueue, queue<string> &inRestaurantQueue, stack<Dish *> dishStack)
{
    string customerName = "", nextCustomer = "";
    char readyCharacter = ' ';
    bool isReady = false;
    // Get the name of the customer in restaurant
    customerName = inRestaurantQueue.front();
    cout << "Are you ready to check out " + customerName + "? (Y or N)" << endl;
    cin >> readyCharacter;
    cin.ignore();

    while (!isReady)
    {
        // If guest is ready to leave, pop him from restaurant queue
        if (tolower(readyCharacter) == 'y')
        {
            cout << "Thank you for stopping by. Have a great rest of your day " + customerName + "!" << endl;
            cout << endl;
            inRestaurantQueue.pop();
            // Check if there's a guest waiting to be served
            if (!guestQueue.empty())
            {
                // Get the name of the first customer in queue
                nextCustomer = guestQueue.front();
                // Remove that first customer from the queue
                guestQueue.pop();
                // Add to in restaurant queue
                inRestaurantQueue.push(nextCustomer);
            }
            // Ready to checkout and check in next next
            isReady = true;

            // Time to clean dishes
            cleanDishes(dishStack);

            return true;
        }
        // Current guest is not ready to checkout yet
        else if (tolower(readyCharacter) == 'n')
        {
            cout << "Sounds good. I'll keep checking up on you " + customerName + "!" << endl;
            cout << endl;
            return false;
        }
        // Invalid input. Reenter
        else
        {
            cout << "Invalid input. Please enter 'Y' or 'N' character." << endl;
            cin >> readyCharacter;
        }
    }

    return false;
}

int main()
{
    // Guest Queue
    queue<string> guestQueue;

    // In-Restaurant Queue
    queue<string> inRestaurantQueue;

    // Dish Stack
    stack<Dish *> dishStack;

    // Bool flag for seating
    bool seatActive = false, isCheckedOut = false;

    while (guestQueue.size() < 5)
    {
        // Print intro
        displayInstructions();

        // Gets availability for seating
        seatActive = checkQueue(inRestaurantQueue);

        // Intro attend guest when there's no one in the store
        if (seatActive)
        {
            attendGuest(inRestaurantQueue, dishStack);
        }
        // Let guest know the people in front of them (including guest attended) in alphabetical order (only my restaurant does this)
        else
        {
            queueGuest(guestQueue, inRestaurantQueue);
        }

        // Is in restaurant guest ready to check out?
        isCheckedOut = checkOut(guestQueue, inRestaurantQueue, dishStack);

        // Scenario where we serve the next guest
        if (isCheckedOut)
        {
            attendGuest(inRestaurantQueue, dishStack);
        }

        isCheckedOut = false;
    }

    cout << "Too many people. Me go home." << endl;

    // Dynamically deallocate stack if there's any in memory
    while (!dishStack.empty())
    {
        delete dishStack.top();
    }

    return 0;
}