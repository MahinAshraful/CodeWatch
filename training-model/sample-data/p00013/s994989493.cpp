#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iterator>

static int createListOfInputData(std::vector<int>& vec);
static int switchingRailroadCars(std::vector<int>& vec, std::vector<int>& data);
static void showData(std::vector<int>& vec);

int main()
{
    std::vector<int> v;
    std::vector<int> r;

    if (createListOfInputData(v)) {
        std::cout << "Failure";
        exit (8);
    }

    if (switchingRailroadCars(v, r)) {
        std::cout << "Failure";
        exit (8);
    }

    showData(r);

    return 0;
}

static int createListOfInputData(std::vector<int>& vec)
{
    int t = 0;

    if ( 0x00 == &vec ) {
        return 1;
    }

    while (std::cin >> t) {
        if ( 100 < t ) {
            return 1;
        }
        vec.push_back(t);
    }

    return 0;
}

static int switchingRailroadCars(std::vector<int>& vec, std::vector<int>& data)
{
    std::vector<int>::iterator it;

    if ( 0x00 == &vec ) {
        return 1;
    }

    it = vec.begin();

    while (vec.end() != it) {
        if ( 0 == *it ) {
            data.push_back(*(it - 1));
            vec.erase(it);
            it = vec.erase(it - 1);
        } else {
            it++;
        }
    }

    return 0;
}

static void showData(std::vector<int>& vec)
{
    if ( 0x00 == &vec ) {
        return;
    }

    for ( unsigned int i = 0; i < vec.size(); i++ ) {
        std::cout << vec.at(i) << std::endl;
    }
}