/*
------ FCAI - Programming 1 - 2022 - Assignment 3 ------

Program Name:           Photoshop-A3
Program Purpose:        Edit 256*256 greyscale images.
Program Description:    This program edits 256*256 greyscale images by adding filters to them.
                        It has 12 filters that can be applied to the images.

Author 1, ID, Group:    Youssef Moataz  -- 20210488 -- Group A - S4
Author 2, ID, Group:    Seif Ibrahim    -- 20210164 -- Group A - S3
Author 3, ID, Group:    Mohamed Essam   -- 20210582 -- Group A - S4
Teaching assistants:    Eng. Yousra Ayman, Eng. Nesma Mohamed

Last Modification:      April 15, 2022
Version:                v1.12.0
*/

#include <iostream>
#include <cstring>
#include "bmplib.cpp"

using namespace std;

// Master image matrix
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
            loadImage();
            blackAndWhiteFilter();
        } else if (choice == "2") {
            loadImage();
            invertFilter();
        } else if (choice == "3") {
            loadImage();
            mergeFilter();
        } else if (choice == "4") {
            loadImage();
            flipImage();
        } else if (choice == "5") {
            loadImage();
            darkenAndLightenImage();
        } else if (choice == "6") {
            loadImage();
            rotateImage();
        } else if (choice == "7") {
            loadImage();
            detectImageEdges();
        } else if (choice == "8") {
            loadImage();
            enlargeImage();
        } else if (choice == "9") {
            loadImage();
            shrinkImage();
        } else if (choice == "a") {
            loadImage();
            mirrorImage();
        } else if (choice == "b") {
            loadImage();
            shuffleImage();
        } else if (choice == "c") {
            loadImage();
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
    cout << "Enter the source image file name (0 to continue using the same image if available): ";
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
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);

}

// Action 2 - Seif
void invertFilter() {

    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            image[i][j] = 255 - image[i][j];
        }
    }

}

// Action 5 - Seif
void darkenAndLightenImage() {

    char choice;

    cout << "Do you want to (d)arken or (l)ighten ?" << endl;
    cout << "Enter (d) to darken or (l) to lighten : " << endl;

    cin >> choice;

    if (choice == 'd' || choice == 'D') {

        for (int i = 0; i < SIZE; i++) {

            for (int j = 0; j < SIZE; j++) {
                image[i][j] -= (image[i][j] * 0.5);
            }

        }

    } else if (choice == 'l' || choice == 'L') {

        for (int i = 0; i < SIZE; i++) {

            for (int j = 0; j < SIZE; j++) {
                if (image[i][j] <= 200) {
                    image[i][j] += 50;
                }
            }

        }

    } else {
        cout << "Wrong input" << endl;
    }

}

// Action 8 - Seif
void enlargeImage() {


    int choice;
    unsigned char enlargedImage[SIZE][SIZE];

    cout << "Which quarter to enlarge 1, 2, 3 or 4 ? " << endl;
    cin >> choice;

    if (choice == 1) {
        int n = 0;
        for (int i = 0; i < SIZE; i += 2, n++) {
            int k = 0;
            for (int j = 0; j < SIZE; j += 2, k++) {
                enlargedImage[i][j] = image[n][k];
                enlargedImage[i + 1][j] = image[n][k];
                enlargedImage[i][j + 1] = image[n][k];
                enlargedImage[i + 1][j + 1] = image[n][k];
            }
        }
    } else if (choice == 2) {
        int n = 0;
        for (int i = 0; i < SIZE; i += 2, n++) {
            int k = 127;
            for (int j = 0; j < SIZE; j += 2, k++) {
                enlargedImage[i][j] = image[n][k];
                enlargedImage[i + 1][j] = image[n][k];
                enlargedImage[i][j + 1] = image[n][k];
                enlargedImage[i + 1][j + 1] = image[n][k];
            }
        }
    } else if (choice == 3) {
        int n = 127;
        for (int i = 0; i < SIZE; i += 2, n++) {
            int k = 0;
            for (int j = 0; j < SIZE; j += 2, k++) {
                enlargedImage[i][j] = image[n][k];
                enlargedImage[i + 1][j] = image[n][k];
                enlargedImage[i][j + 1] = image[n][k];
                enlargedImage[i + 1][j + 1] = image[n][k];
            }
        }
    } else if (choice == 4) {
        int n = 127;
        for (int i = 0; i < SIZE; i += 2, n++) {
            int k = 127;
            for (int j = 0; j < SIZE; j += 2, k++) {
                enlargedImage[i][j] = image[n][k];
                enlargedImage[i + 1][j] = image[n][k];
                enlargedImage[i][j + 1] = image[n][k];
                enlargedImage[i + 1][j + 1] = image[n][k];
            }
        }
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = enlargedImage[i][j];
        }
    }

}

// Action b - Seif
void shuffleImage() {

    string quarters;
    cout << "New order of quarters ? " << endl;

    cin.ignore();
    getline(cin, quarters);

    unsigned char shuffledImage[SIZE][SIZE];
    int n = 0;
    int k = 0;
    int c = 0;
    int r = 0;

    for (int i = 0; i < quarters.length(); i++) {
        
        if (isdigit(quarters[i])) {

            c += 1;

            (c % 2 == 1) ? r = 0 : r = 128;

            (c <= 2) ? n = 0 : n = 128;

            if (quarters[i] == '1') {
                for (int i = 0; i < 128; i++, n++) {
                    k = r;
                    for (int j = 0; j < 128; j++, k++) {
                        shuffledImage[n][k] = image[i][j];
                    }
                }
            } else if (quarters[i] == '2') {
                for (int i = 0; i < 128; i++, n++) {
                    k = r;
                    for (int j = 128; j < SIZE; j++, k++) {
                        shuffledImage[n][k] = image[i][j];
                    }
                }
            } else if (quarters[i] == '3') {
                for (int i = 128; i < SIZE; i++, n++) {
                    k = r;
                    for (int j = 0; j < 128; j++, k++) {
                        shuffledImage[n][k] = image[i][j];
                    }
                }
            } else if (quarters[i] == '4') {
                for (int i = 128; i < SIZE; i++, n++) {
                    k = r;
                    for (int j = 128; j < SIZE; j++, k++) {
                        shuffledImage[n][k] = image[i][j];
                    }
                }
            } else {
                cout << "Wrong input" << endl;
            }
        } else {
            continue;
        }
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = shuffledImage[i][j];
        }
    }

}

// Action 3 - Youssef
void mergeFilter() {

    cout << "Please enter name of image file to merge with:";
    char otherImage[100];

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

    for (int i = 0; i < SIZE; ++i) {

        for (int j = 0; j < SIZE; ++j) {

            image[i][j] = merged[i][j];

        }

    }

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

        for (int i = 0; i < SIZE; ++i) {

            for (int j = 0; j < SIZE; ++j) {

                image[i][j] = mat2[i][j];

            }

        }

    } else if (degree == 180) {

        unsigned char mat2[SIZE][SIZE];

        for (int i = 0; i < SIZE; ++i) {

            for (int j = 0; j < SIZE; ++j) {

                mat2[SIZE - 1 - i][j] = image[i][j];

            }

        }

        for (int i = 0; i < SIZE; ++i) {

            for (int j = 0; j < SIZE; ++j) {

                image[i][j] = mat2[i][j];

            }

        }

    } else if (degree == 270) {

        unsigned char mat2[SIZE][SIZE];

        for (int i = 0; i < SIZE; ++i) {

            for (int j = 0; j < SIZE; ++j) {

                mat2[SIZE - 1 - j][i] = image[i][j];

            }

        }

        for (int i = 0; i < SIZE; ++i) {

            for (int j = 0; j < SIZE; ++j) {

                image[i][j] = mat2[i][j];

            }

        }

    } else if (degree == 360) {

        for (int i = 0; i < SIZE; ++i) {

            for (int j = 0; j < SIZE; ++j) {

                image[i][j] = image[i][j];

            }

        }

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

        for (int i = 0; i < SIZE; ++i) {

            for (int j = 0; j < SIZE; ++j) {

                image[i][j] = mat2[i][j];

            }

        }

    } else if (shrinkRatio == "1/3") {

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

        for (int i = 0; i < SIZE; ++i) {

            for (int j = 0; j < SIZE; ++j) {

                image[i][j] = mat2[i][j];

            }

        }

    } else if (shrinkRatio == "1/4") {

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

        for (int i = 0; i < SIZE; ++i) {

            for (int j = 0; j < SIZE; ++j) {

                image[i][j] = mat2[i][j];

            }

        }

    }

}

// Action c - Youssef
void blurImage() {

    for (int i = 0; i < SIZE; i += 1) {
        for (int j = 0; j < SIZE; j += 1) {

            image[i - 1][j - 1] = (image[i][j] + image[i - 1][j - 1]) / 2;
            image[i][j - 1] = (image[i][j] + image[i][j - 1]) / 2;
            image[i - 1][j] = (image[i][j] + image[i - 1][j]) / 2;

            image[i + 1][j + 1] = (image[i][j] + image[i + 1][j + 1]) / 2;
            image[i][j + 1] = (image[i][j] + image[i][j + 1]) / 2;
            image[i + 1][j] = (image[i][j] + image[i + 1][j]) / 2;

            image[i - 1][j + 1] = (image[i][j] + image[i - 1][j + 1]) / 2;
            image[i + 1][j - 1] = (image[i][j] + image[i + 1][j - 1]) / 2;

        }
    }

}

// Action 1 - Mohamed
void blackAndWhiteFilter() {

    for (int i = 0; i < SIZE; i++) {

        for (int j = 0; j < SIZE; j++) {
            if (image[i][j] > 127) {
                image[i][j] = 255;
            } else {
                image[i][j] = 0;
            }
        }

    }

}

// Action 4 - Mohamed
void flipImage() {
    char choice;
    bool valid;
    int temp;
    do {
        cout << "Would you like to flip the image (V)ertically or (H)orizontally [Please select the respective letter]"
             << endl;
        cin >> choice;
        if (choice == 'H' || choice == 'h') {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE / 2; j++) {
                    temp = image[i][j];
                    image[i][j] = image[i][SIZE - 1 - j];
                    image[i][SIZE - 1 - j] = temp;
                    valid = true;
                }
            }
        } else if (choice == 'V' || choice == 'v') {
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE; j++) {
                    temp = image[i][j];
                    image[i][j] = image[SIZE - 1 - i][j];
                    image[SIZE - 1 - i][j] = temp;
                    valid = true;
                }
            }
        } else {
            cout << "Please select a valid letter (V or H)" << endl;;
            valid = false;
        }
    } while (!valid);
}

// Action 7 - Mohamed
void detectImageEdges() {
    blackAndWhiteFilter();
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            if (image[i][j] != image[i][j+1]){
                image [i][j] = 0;
            }
            else{
                image[i][j] = 255;
            }
        }
    }


}

// Action a - Mohamed
void mirrorImage() {
    char selection;
    bool valid;
    do{
    cout << "Please select which half you'd like to mirror by selecting the respective letter! [(L)eft, (R)ight, (T)op, or (B)ottom]" << endl;
    cin >> selection;
    if (selection == 'L' || selection == 'R' || selection == 'T' || selection == 'B'){
        valid = true;
    }
    else{
        cout << "Sorry, that's an invalid letter" << endl;
    }
}
    while (!valid);
    if (selection == 'L'){
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j < SIZE / 2; j++){
                image[i][SIZE - j] = image[i][j];
            }
        }
    }
    else if (selection == 'R'){
        for (int i =  0; i < SIZE; i++){
            for (int j = SIZE / 2; j < SIZE; j++){
                image[i][SIZE - j] = image[i][j];
            }
        }
    }
    else if (selection == 'T'){
        for (int i = 0; i < SIZE / 2; i++){
            for (int j = 0; j < SIZE; j++){
                image[SIZE - i][j] = image[i][j];
            }
        }
    }
    else if (selection == 'B'){
        for (int i = SIZE / 2; i < SIZE; i++){
            for (int j = 0; j < SIZE; j++){
                image[SIZE - i][j] = image[i][j];
            }
        }
    }

}

// End of the file
