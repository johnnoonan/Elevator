#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>
using namespace std;

/* calculateElevatorTime
 *
 *   Parameters:
 *   vector totalFloors:  Vector populated with valid elevator floors
 *
 *   Usage:
 *   This function takes a vector of elevator floors, that has already been parsed for
 *   invalid data, and calculates the total amount of time it will take to traverse them.
 *   Then returns the result.
 *
 */
int calculateElevatorTime(vector<int> &totalFloors)
{
  const int singleFloorTime = 10;
  int totalTime = 0;

  // This loop finds the difference between the current floor and the next floor,
  // then adds this difference to the total time.
  for (int i = 0; i < totalFloors.size() - 1; i++)
  {
    totalTime += abs(totalFloors[i] - totalFloors[i + 1]);
  }

  totalTime = totalTime * singleFloorTime;

  return totalTime;
}

/* rebuildInputString
 *
 *   Parameters:
 *   string inputFloors:  Initial input string entered by the user
 *   vector totalFloors:  Vector populated with valid elevator floors
 *
 *   Usage:
 *   This function takes a string and the parsed vector of floors,
 *   then rebuilds the initial input string without any invalid floor data that
 *   it may have initially contained.
 *
 */
void rebuildInputString(string &inputFloors, vector<int> &totalFloors)
{
  // Setting the inputFloors string to empty, so it can be rebuilt
  inputFloors = "";
  for (int floor : totalFloors)
  {
    if (inputFloors != "")
    {
      inputFloors += ",";
    }

    inputFloors += to_string(floor);
  }
}

/* parseFloors
 *
 *   Parameters:
 *   string inputFloors:  Initial input string of floors to visit entered by the user
 *   vector totalFloors:  Vector to be populated with valid elevator floors
 *
 *   Usage:
 *   This function takes a string and an empty vector that needs to be populated with elevator floors.
 *   This function parses the input data and stops any invalid data from being entered into the floors vector.
 *   Invalid data includes, anything thats not an integer, duplicates, or out of bounds floors.
 *
 *   This function calls rebuildInputString to rebuild the initial user entered string with only valid data,
 *   to be printed out back to the user later.
 *
 */
void parseFloors(string &inputFloors, vector<int> &totalFloors)
{
  stringstream ss(inputFloors);
  string getCurrentFloor;

  bool validFloor;
  int currentFloor;
  int previousFloor;

  while (getline(ss, getCurrentFloor, ','))
  {
    validFloor = true;
    size_t floorValueSize;

    try
    {
      currentFloor = stoi(getCurrentFloor, &floorValueSize);
    }
    catch (const invalid_argument &e)
    {
      validFloor = false;
      cout << "Invalid floor value " << currentFloor << " entered. Removing it from list" << endl;
    }

    // Checking for non-Integer floor values like doubles and floats.
    // This check is comparing the length of the parsed value, to the length of the non-parsed value.
    // This avoids non-integer values that stoi() truncated down, and doesn't including them in the floor list.
    if (getCurrentFloor.length() != floorValueSize)
    {
      validFloor = false;
      cout << "Non-Integer floor value " << getCurrentFloor << " entered. Removing it from list" << endl;
    }

    // Checking that the current floor is not the same as the previous floor,
    // if it is, it won't be added to the list of floors visited.
    else if (previousFloor == currentFloor)
    {
      validFloor = false;
      cout << "Duplicate floor value " << currentFloor << " entered. The same value was entered twice in a row. Removing duplicate from list" << endl;
    }

    // Checking for floor values outside of the valid range, 0 to 163
    else if (currentFloor < 0 || currentFloor > 163)
    {
      validFloor = false;
      cout << "Out of Bounds floor value " << currentFloor << " entered. The valid range is 0 to 163. Removing it from list" << endl;
    }

    if (validFloor)
    {
      totalFloors.push_back(currentFloor);
      previousFloor = currentFloor;
    }
  }
  rebuildInputString(inputFloors, totalFloors);
}

int main()
{

  vector<int> totalFloors;
  string inputFloors;

  cout << "Enter a list of comma-separated floors for the elevator: ";
  getline(cin, inputFloors);

  parseFloors(inputFloors, totalFloors);
  int totalElevatorTime = calculateElevatorTime(totalFloors);

  cout << endl
       << "Total elevator time = " << totalElevatorTime << endl;
  cout << "Floors visited in order " << inputFloors << endl;

  return 0;
}
