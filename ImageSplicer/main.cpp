#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace sf;
int main()
{

    int* dimensions = new int[4];
    std::string filename;
    cout << "Enter image name";
    cin >> filename;
    cout << "Enter Sprite width";
    cin >> dimensions[0];
    cout << "Enter Sprite Hight";
    cin >> dimensions[1];
    cout << "Enter image width";
    cin >> dimensions[2];
    cout << "Enter Image height";
    cin >> dimensions[3];
    int numfiles = dimensions[2] / dimensions[0] * dimensions[3] / dimensions[1];
    string filepath;
    filepath = "Input/" + filename + ".png";
    string outputpath;
    outputpath = "Output/";
    Image image;
    image.loadFromFile(filepath);
    Image* output = new Image[numfiles];
    int left = numfiles * dimensions[1] / dimensions[3];
    int top = numfiles * dimensions[0] / dimensions[2];
    int countsuccess = 0;
    for (int j = 0; j < top; j++) {
        for (int i = 0; i < left; i++) {
            char buffer[25];
            
            sprintf_s(buffer, "file%d-%d.png",j,i);
            output[i].create(dimensions[0], dimensions[1]);
            output[i].copy(image, 0, 0, IntRect(dimensions[0] * i, dimensions[1] * j, dimensions[0], dimensions[1]),true);
            string savelloc;
            savelloc = outputpath + filename + buffer;
            countsuccess += output[i].saveToFile(savelloc);
        }
    }
    cout << numfiles << " Attempted. " << countsuccess << " Succeeded" << endl;
    delete[] output;
    output = nullptr;
    return 0;
}