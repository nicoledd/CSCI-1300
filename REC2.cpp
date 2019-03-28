#include <iostream>
using namespace std;

// given radius of a sphere, calculates its volume
void sphereVolume(float radius){
    
    float volume = 0.0;
    
    volume = (4 * 3.14159265 * radius * radius * radius) / 3;
    
    cout << "volume: " << volume << "\n";
}

// given radius of a sphere, calculates its surface area
void sphereSurfaceArea(float radius){
    
    float surface_area = 0.0;
    
    surface_area = 4 * 3.14159265 * radius * radius;
    
    cout << "surface area: " << surface_area << "\n";
    
    return;
}

int main(){
    
    float radius;
    
    cout << "Enter a radius:\n";
    cin >> radius;
    
    sphereVolume(radius);
    sphereSurfaceArea(radius);
    
    return 0;
}
