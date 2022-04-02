#include <iostream>
#include "bmplib.cpp"

using namespace std;

void getUserChoice(); // Starting function
void loadImage(); // Get the image file name and load it

// Start menu functions
void saveImage(); // Action s
void invertFilter(); // Action 2
void darkenAndLightenImage(); // Action 5
void enlargeImage(); // Action 8
void shuffleImage(); // Action b
void blackAndWhiteFilter(); // Action 1
void mergeFilter(); // Action 3
void flipImage(); // Action 4
void rotateImage(); // Action 6
void detectImageEdges(); // Action 7
void shrinkImage(); // Action 9
void mirrorImage(); // Action a
void blurImage(); // Action c
// End menu functions

int main() {
    cout << "  --- Welcome to our Photoshop ! ---  " << endl;
    getUserChoice();

    return 0;
}

// Starting function
void getUserChoice() {
    while (true) {
        string choice;

        loadImage();

        cout << endl;
        cout << "Ahlan ya user ya habibi" << endl;
        cout << "Please select a filter to apply or 0 to exit: " << endl;
        cout << "1- Black & White Filter " << endl;
        cout << "2- Invert Filter " << endl;
        cout << "3- Merge Filter " << endl;
        cout << "4- Flip Image " << endl;
        cout << "5- Darken and Lighten Image  " << endl;
        cout << "6- Rotate Image " << endl;
        cout << "7- Detect Image Edges " << endl;
        cout << "8- Enlarge Image " << endl;
        cout << "9- Shrink Image " << endl;
        cout << "a- Mirror 1/2 Image " << endl;
        cout << "b- Shuffle Image " << endl;
        cout << "c- Blur Image " << endl;
        cout << "s- Save the image to a file " << endl;
        cout << "0- Exit " << endl;


        cin >> choice;
        if (choice == "0") {
            cout << "Thanks for using our photoshop, Bye !" << endl;
            break;
        } else if (choice == "1") {
            blackAndWhiteFilter();
        } else if (choice == "2") {
            invertFilter();
        } else if (choice == "3") {
            mergeFilter();
        } else if (choice == "4") {
            flipImage();
        } else if (choice == "5") {
            darkenAndLightenImage();
        } else if (choice == "6") {
            rotateImage();
        } else if (choice == "7") {
            detectImageEdges();
        } else if (choice == "8") {
            enlargeImage();
        } else if (choice == "9") {
            shrinkImage();
        } else if (choice == "a") {
            mirrorImage();
        } else if (choice == "b") {
            shuffleImage();
        } else if (choice == "c") {
            blurImage();
        } else if (choice == "s") {
            saveImage();
        } else {
            cout << "Wrong input ! " << endl;
        }

    }

}

void loadImage() {

}

// Action s
void saveImage() {

}

// Action 2
void invertFilter() {

}

// Action 5
void darkenAndLightenImage() {

}

// Action 8
void enlargeImage() {

}

// Action b
void shuffleImage() {

}

// Action 1
void blackAndWhiteFilter() {

}

// Action 3
void mergeFilter() {

}

// Action 4
void flipImage() {

}

// Action 6
void rotateImage() {

}

// Action 7
void detectImageEdges() {

}

// Action 9
void shrinkImage() {

}

// Action a
void mirrorImage() {

}

// Action c
void blurImage() {

}

// End of the file