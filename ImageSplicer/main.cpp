#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace sf;
int main()
{
    //array holding original image dimensions and destination sprite dimensions
    int* dimensions = new int[4];
    
    /* Basic Input Questions */
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
    
    //Calculate number of files
    int numfiles = dimensions[2] / dimensions[0] * dimensions[3] / dimensions[1];
    
    //Generate Filepath string
    string filepath;
    filepath = "Input/" + filename + ".png";
    string outputpath;
    
    //end path to place files
    outputpath = "Output/";
    
    Image image;
    image.loadFromFile(filepath);
    Image* output = new Image[numfiles];
    int left = numfiles * dimensions[1] / dimensions[3];
    int top = numfiles * dimensions[0] / dimensions[2];
    int countsuccess = 0;
    
    //Slice the image into pieces, save to file location as filename + Number
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
    //Print Total vs successes
    cout << numfiles << " Attempted. " << countsuccess << " Succeeded" << endl;
    //destroy all pointers
    delete[] output;
    delete[] dimensions;
    dimensions = nullptr;
    output = nullptr;
    return 0;
}
