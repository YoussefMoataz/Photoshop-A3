/*
Student with smallest ID does filters 1, 4, 7, a - Mohamed
Student with middle ID does filters 2, 5, 8, b - Seif
Student with biggest does filters 3, 6, 9, c - Youssef
 */

#include <iostream>
#include <cstring>
#include <iomanip>
#include "bmplib.cpp"

using namespace std;

unsigned char image[SIZE][SIZE];


void getUserChoice(); // Starting function
void loadImage(); // Get the image file name and load it

// Start menu functions
void saveImage(); // Action s
void invertFilter(); // Action 2
void darkenAndLightenImage(); // Action 5
void enlargeImage(); // Action 8
void shuffleImage(); // Action b
void mergeFilter(); // Action 3
void rotateImage(); // Action 6
void shrinkImage(); // Action 9
void blurImage(); // Action c
void blackAndWhiteFilter(); // Action 1
void flipImage(); // Action 4
void detectImageEdges(); // Action 7
void mirrorImage(); // Action a
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

    char imageFileName[50];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    readGSBMP(imageFileName, image);

}

// Action s
void saveImage() {

    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
    
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

// Action 3 - Youssef
void mergeFilter() {

    cout << "Please enter name of image file to merge with:";
    char otherImage [100];

    cin >> otherImage;
    strcat(otherImage, ".bmp");

    unsigned char image2[SIZE][SIZE];
    readGSBMP(otherImage, image2);

    unsigned char merged[SIZE][SIZE];

    for (int i = 0; i < SIZE; ++i) {

        for (int j = 0; j < SIZE; ++j) {

            merged[i][j] = (image[i][j] + image2[i][j]) / 2;

        }

    }

    char imageFileNameOutput[100] = "Merged-";
    strcat(imageFileNameOutput, imageFileName);
    writeGSBMP(imageFileNameOutput, merged);

}

// Action 6 - Youssef
void rotateImage() {

    cout << "Rotate (90), (180) or (360) degrees?";
    int degree;
    cin >> degree;

    if (degree == 90) {

        unsigned char mat2[SIZE][SIZE];

        for (int i = 0; i < SIZE; ++i) {

            for (int j = 0; j < SIZE; ++j) {

                mat2[j][SIZE - 1 - i] = image[i][j];

            }

        }

        char imageFileNameOutput[100] = "Rotated-90-";
        strcat(imageFileNameOutput, imageFileName);
        writeGSBMP(imageFileNameOutput, mat2);

    } else if (degree == 180) {

        unsigned char mat2[SIZE][SIZE];

        for (int i = 0; i < SIZE; ++i) {

            for (int j = 0; j < SIZE; ++j) {

                mat2[SIZE - 1 - i][j] = image[i][j];

            }

        }

        char imageFileNameOutput[100] = "Rotated-180-";
        strcat(imageFileNameOutput, imageFileName);
        writeGSBMP(imageFileNameOutput, mat2);

    } else if (degree == 270) {

        unsigned char mat2[SIZE][SIZE];

        for (int i = 0; i < SIZE; ++i) {

            for (int j = 0; j < SIZE; ++j) {

                mat2[SIZE - 1 - j][i] = image[i][j];

            }

        }

        char imageFileNameOutput[100] = "Rotated-270-";
        strcat(imageFileNameOutput, imageFileName);
        writeGSBMP(imageFileNameOutput, mat2);

    } else if (degree == 360) {

        char imageFileNameOutput[100] = "Rotated-360-";
        strcat(imageFileNameOutput, imageFileName);
        writeGSBMP(imageFileNameOutput, image);

    }

}

// Action 9 - Youssef
void shrinkImage() {

    cout << "Shrink to (1/2), (1/3) or (1/4)?";
    string shrinkRatio;
    cin >> shrinkRatio;

    if (shrinkRatio == "1/2") {

        unsigned char mat2[SIZE][SIZE];

        int m = 0, n = 0;

        for (int i = 0; i < SIZE; i += 2, m++) {

            n = 0;

            for (int j = 0; j < SIZE; j += 2, n++) {

                mat2[m][n] = image[i][j];

            }

        }

        for (int i = 0; i < SIZE; i += 1) {

            for (int j = 0; j < SIZE; j += 1) {

                if (i < m && j < n) {
                    continue;
                } else {
                    mat2[i][j] = 255;
                }

            }

        }

        char imageFileNameOutput[100] = "Shrink-2-";
        strcat(imageFileNameOutput, imageFileName);
        writeGSBMP(imageFileNameOutput, mat2);

    }else if (shrinkRatio == "1/3") {

        unsigned char mat2[SIZE][SIZE];

        int m = 0, n = 0;

        for (int i = 0; i < SIZE; i += 3, m++) {

            n = 0;

            for (int j = 0; j < SIZE; j += 3, n++) {

                mat2[m][n] = image[i][j];

            }

        }

        for (int i = 0; i < SIZE; i += 1) {

            for (int j = 0; j < SIZE; j += 1) {

                if (i < m && j < n) {
                    continue;
                } else {
                    mat2[i][j] = 255;
                }

            }

        }

        char imageFileNameOutput[100] = "Shrink-3-";
        strcat(imageFileNameOutput, imageFileName);
        writeGSBMP(imageFileNameOutput, mat2);

    }else if (shrinkRatio == "1/4") {

        unsigned char mat2[SIZE][SIZE];

        int m = 0, n = 0;

        for (int i = 0; i < SIZE; i += 4, m++) {

            n = 0;

            for (int j = 0; j < SIZE; j += 4, n++) {

                mat2[m][n] = image[i][j];

            }

        }

        for (int i = 0; i < SIZE; i += 1) {

            for (int j = 0; j < SIZE; j += 1) {

                if (i < m && j < n) {
                    continue;
                } else {
                    mat2[i][j] = 255;
                }

            }

        }

        char imageFileNameOutput[100] = "Shrink-4-";
        strcat(imageFileNameOutput, imageFileName);
        writeGSBMP(imageFileNameOutput, mat2);

    }

}

// Action c - Youssef
void blurImage() {

}

// Action 1
void blackAndWhiteFilter() {

}

// Action 4
void flipImage() {

}

// Action 7
void detectImageEdges() {

}

// Action a
void mirrorImage() {

}

// End of the file