
#include "Reservoir.h"
#include <iostream>
using namespace std;

Reservoir::Reservoir() : sName(nullptr), type(nullptr), width(0), length(0), maximum_depth(0) {}

Reservoir::Reservoir(char* userName, int userWidth, int userLength, int userMaximum_depth)
    : width(userWidth), length(userLength), maximum_depth(userMaximum_depth) {
    if (userName != nullptr) {
        int size = strlen(userName);
        this->sName = new char[size + 1];
        this->sName[size] = '\0';
        strcpy_s(this->sName, size + 1, userName);
    }
}

Reservoir::Reservoir(const Reservoir& other) {
    this->width = other.width;
    this->length = other.length;
    this->maximum_depth = other.maximum_depth;
    int size = strlen(other.sName);
    this->sName = new char[size + 1];
    strcpy_s(this->sName, size + 1, other.sName);
}

Reservoir::~Reservoir() {
    if (this->sName != nullptr)
    {
        delete[] this->sName;
    }
}

double Reservoir::Determining_the_approximate_volume() {
    return width * length * maximum_depth;
}

int Reservoir::water_surface_area()
{
    return width * length;
}

bool Reservoir::check_if_the_type_of_water(const Reservoir& other)
{
    for (int i = 0; i < strlen(other.type) || i < strlen(this->type); ++i) {
        if (this->type[i] != other.type[i]) {
            return false; 
        }
    }
    return true;
}

bool Reservoir::ater_bodies_belong_to_the_same_type(Reservoir& other)
{
    if (this->check_if_the_type_of_water(other))
    {
        if (this->water_surface_area() == other.water_surface_area()) {
            cout << this->sName << " and " << other.sName << " are equal" << endl;
        }
        else if (this->water_surface_area() > other.water_surface_area()) {
            cout << this->sName << " bigger than " << other.sName << endl;
        }
        else if (this->water_surface_area() < other.water_surface_area()) {
            cout << this->sName << " smaller than " << other.sName << endl;
        }
        return true;
    }
    return false;
}

void Reservoir::output()
{
    
    cout << "Name: " << this->sName << endl;
    cout << "Width: " << this->width << endl;
    cout << "Length: " << this->length << endl;
    cout << "Maximum depth: " << this->maximum_depth << endl;
    cout << "Type: " << this->type << endl;
    cout << "Determining the approximate volume: " << this->Determining_the_approximate_volume() << endl;
    cout << "Determining the approximate volume: " << this->water_surface_area() << endl;
}

void Reservoir::input()
{
    int width, length, maximum_depth;
    char* NewName = new char[255];
    char* type = new char[255];

    cin.ignore();
    cout << "Input name: ";
    cin.getline(NewName, 255);
    SetsName(NewName);
    delete[] NewName;

    cout << "Input width: ";
    cin >> width;
    SetWidth(width);

    cout << "Input length: ";
    cin >> length;
    SetLength(length);

    cout << "Input maximum depth: ";
    cin >> maximum_depth;
    SetMaximum_depth(maximum_depth);

    cin.ignore();
    cout << "Input type: ";
    cin.getline(type, 255);
    SetType(type);
    delete[] type;
}


void Reservoir::remove(Reservoir*& array, int index, int& size) {
    Reservoir* newArray = new Reservoir[size - 1];
    for (int i = 0, j = 0; i < size; i++) {
        if (i != index) {
            newArray[j] = array[i]; 
            j++;
        }
    }

    array = newArray;
}



