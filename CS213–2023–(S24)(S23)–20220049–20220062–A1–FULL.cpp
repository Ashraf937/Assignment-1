
// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:  RGB Image filters program
// Last Modification Date:	18/10

// Student 1 and ID and Group:	 Ahmed Yehia Zakaria        ( 20220049 )   (S24)        ( ay8452884@gmail.com )
// Student 2 and ID and Group:	 Ashraf Abdallah Elmamony   ( 20220062 )   (S23)      ( ashrafabdallah937@gmail.com )

// Purpose: we are doing this program to Learn and Practice and to improve our coding skills in C++,
//          including understanding the language's syntax, data structures, and algorithms.
//          This program often involve problem-solving.
//          we are required to devise solutions to specific problems or tasks,
//          which helps develop critical thinking and analytical skills.

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char second_image[SIZE][SIZE];

void loadImage ();
void loadImage2 ();
void saveImage ();
void BW ();
void Invert ();
void Merge ();
void Flip_horizontal ();
void Flip_vertical ();
void Lighten ();
void Darken ();
void Rotate ();
void Detect ();
void shrink ();
void Enlarge ();
void Mirror_l ();
void Mirror_r ();
void Mirror_u ();
void Mirror_d ();
void Shuffle ();
void Blur ();
void Crop ();
void Skew_hz ();
void Skew_vt ();

int main() {

    //menu
    char ans;
    char x;
    cout << " " << endl
         << "Ahlan ya user ya habibi ;) " << endl
         << "Select a filter to apply :- " << endl
         << "1- Black and White Filter" << endl
         << "2- Invert Filter" << endl
         << "3- Merge Filter" << endl
         << "4- Flip Image" << endl
         << "5- Darken or lighten Image" << endl
         << "6- Rotate Image" << endl
         << "7- Detect Edges Image" << endl
         << "8- Enlarge Image" << endl
         << "9- shrink Image" << endl
         << "a- Mirror Image" << endl
         << "b- Shuffle Image" << endl
         << "c- Blur Image" << endl
         << "d- Crop Image" << endl
         << "e- Skew Image Right" << endl
         << "f- Skew Image Up" << endl
         << "0- Exit" << endl;
    do {

        loadImage();
        cout << "Enter your desired filter's number : ";

        cin >> x;

        if (x == '1' ) {
            BW();
            saveImage();
        }

        if (x == '2') {
            Invert();
            saveImage();
        }

        if (x == '3') {
            Merge();
            saveImage();
        }

        if (x == '4') {
            char x;
            cout << "horizontal or vertical flip ( h / v ) ? " << endl;
            cin >> x;
            if (x == 'h') {
                Flip_horizontal();
                saveImage();
            }
            if (x == 'v') {
                Flip_vertical();
                saveImage();
            }
        }

        if (x == '5') {
            char x;
            cout << "Lighten or Darken ( l / d ) ? " << endl;
            cin >> x;
            if (x == 'l') {
                Lighten();
                saveImage();
            }
            if (x == 'd') {
                Darken();
                saveImage();
            }
        }

        if (x == '6') {
            Rotate();
            saveImage();
        }

        if (x == '7') {
            Detect();
            saveImage();
        }

        if (x == '8') {
            Enlarge();
            saveImage();
        }

        if (x == '9') {
            shrink();
            saveImage();
        }

        if (x == 'a') {
            char mirror_side;
            cout<<"Mirror (l)eft, (r)ight, (u)pper, (d)own side : ";
            cin>>mirror_side;
            if (mirror_side == 'l'){
                Mirror_l();
                saveImage();
            }
            if (mirror_side== 'r'){
                Mirror_r();
                saveImage();
            }
            if (mirror_side == 'u'){
                Mirror_u();
                saveImage();
            }
            if (mirror_side == 'd'){
                Mirror_d();
                saveImage();
            }
        }

        if (x == 'b') {
            Shuffle();
            saveImage();
        }

        if ( x== 'c') {
            Blur();
            saveImage();
        }

        if (x == 'd'){
            Crop();
            saveImage();
        }

        if (x == 'e') {
            Skew_hz();
            saveImage();
        }

        if (x == 'f'){
            Skew_vt();
            saveImage();
        }

        cout<< "do you wish to proceed on another image (y/n) " << endl;
        cin>>ans;
    }
    while (ans == 'y');
}



// load image functions :-
void loadImage () {
    char imageFileName[100];
    cout << " Enter the source image file name : ";
    cin >> imageFileName;
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}
void loadImage2 () {
    char imageFileName[100];
    cout << "Enter the second source image file name: ";
    cin >> imageFileName;
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, second_image);
}

// save image functions :-
void saveImage () {
    char imageFileName[100];
    cout << "Enter the target image file name: ";
    cin >> imageFileName;
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}



// Black and white filter :-
void BW() {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            if (image[i][j] > 127)
                // If the pixel intensity is greater than 127, set it to 255 (white).
                image[i][j] = 255;
                // If the pixel intensity is 127 or less, set it to 0 (black).
            else
                image[i][j] = 0;
        }
    }
}



// invert filter by reversing the black pixels to white pixels :-
void Invert (){

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            // Invert the pixel intensity at position (i, j) by subtracting it from the maximum value, 255.
            image[i][j] = 255 - image[i][j];
        }
    }
}



// Merge filter merging the pixels into each other :-
void Merge () {

    loadImage2();
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // Merge the pixel intensities from both images by taking their average.
            image[i][j] = (image[i][j] + second_image[i][j])/2;
        }
    }
}



// flip filters horizontally or vertically :-
void Flip_horizontal () {

    for (int i = 0; i < SIZE / 2; i++) {
        for (int j = 0; j < SIZE; j++) {
            // Swap the pixel values between the current row (i) and its corresponding row in the bottom half.
            swap(image[i][j], image[255 - 1 - i][j]);
        }
    }
}
void Flip_vertical () {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE / 2; j++) {
            // Swap the pixel values between the current column (j) and its corresponding column on the right side.
            swap(image[i][j], image[i][255 - 1 - j]);
        }
    }
}



// Brightness filters lighten up the image or darken it 50% by adding more white or black to the image :-
void Lighten() {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            image[i][j]=(255+image[i][j])/2;
        }
    }
}
void Darken () {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            image[i][j]=(image[i][j]/2);
        }
    }
}



// Rotation filter rotate the image in 90 or 180 or 270 degrees :-
void Rotate () {

    int y,x;  //store the rotation degree.
    int temp [SIZE][SIZE];
    cout<<"Please enter the rotation Degree (90 - 180 - 270): ";
    cin>>y ;
    x = (0.5 * y);
    while(x--){

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                temp [i][j]= image [i][j];
            }
        }
        // Rotate the image 90 degrees clockwise by swapping elements.
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image [i][j]= temp[255-j][i];
            }
        }
    }
}



// Detect the edges of the image by checking the difference of color between pixels :-
void Detect(){

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // Check if the absolute difference between the current pixel and its right or bottom pixel is greater than or equal to 32.
            if((abs(image[i][j] - image[i][j + 1] )>= 32) || (abs(image[i][j] - image[i + 1][j ] )>= 32)) {
                image[i][j]=0;
            }
            else
                image[i][j]=250;
        }
    }
}



// Enlarge filter :-
void Enlarge (){

    unsigned char temp[SIZE][SIZE];
    int q;
    cout<<"Which quarter to enlarge 1, 2, 3 or 4?";
    cin>>q;

        // Enlarge the First quarter of the image.
    if (q == 1) {
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                // Duplicate each pixel in the original image to a 2x2 block in the enlarged image.
                temp[2 * i][2 * j] = image[i][j];
                temp[2 * i + 1][2 * j] = image[i][j];
                temp[2 * i][2 * j + 1] = image[i][j];
                temp[2 * i + 1][2 * j + 1] = image[i][j];
            }
        }
    }
        // Enlarge the Second quarter of the image.
    else if (q == 2) {
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 128; j < SIZE; j++) {
                // Duplicate each pixel in the original image (right half) to a 2x2 block in the enlarged image.
                temp[2 * i][2 * (j - SIZE / 2)] = image[i][j];
                temp[2 * i + 1][2 * (j - SIZE / 2)] = image[i][j];
                temp[2 * i][2 * (j - SIZE / 2) + 1] = image[i][j];
                temp[2 * i + 1][2 * (j - SIZE / 2) + 1] = image[i][j];

            }
        }
    }
        // Enlarge the third quarter of the image.
    else if (q == 3) {
        for (int i = 128; i < SIZE; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                // Duplicate each pixel in the original image (bottom half) to a 2x2 block in the enlarged image.
                temp[2 * (i - SIZE / 2)][2 * j] = image[i][j];
                temp[2 * (i - SIZE / 2) + 1][2 * j] = image[i][j];
                temp[2 * (i - SIZE / 2)][2 * j + 1] = image[i][j];
                temp[2 * (i - SIZE / 2) + 1][2 * j + 1] = image[i][j];
            }
        }
    }
        // Enlarge the Fourth quarter of the image.
    else if (q == 4) {
        for (int i = 128; i < SIZE; i++) {
            for (int j = 128; j < SIZE; j++) {
                // Duplicate each pixel in the original image (bottom-right quarter) to a 2x2 block in the enlarged image.
                temp[2 * (i - SIZE / 2)][2 * (j - SIZE / 2)] = image[i][j];
                temp[2 * (i - SIZE / 2) + 1][2 * (j - SIZE / 2)] = image[i][j];
                temp[2 * (i - SIZE / 2)][2 * (j - SIZE / 2) + 1] = image[i][j];
                temp[2 * (i - SIZE / 2) + 1][2 * (j - SIZE / 2) + 1] = image[i][j];
            }
        }
    }
    // Copy the enlarged image from the temporary array back to the original image.
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = temp[i][j];
        }
    }
}



// Shrink filter :-
void shrink (){

    int temp[SIZE][SIZE];
    int s;

    cout<<"Shrink to ?"<<endl
        <<"1- (1/2)" <<endl
        <<"2- (1/3)" <<endl
        <<"3- (1/4)"<<endl;

    cin >>s;

    if (s == 1){

        // Shrink to 1/2 size
        for (int i = 0; i < 256; i++) {
            for (int j = 0; j < 256; j++) {
                temp[i][j] = 255;
            }
        }

        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                // Shrink each 2x2 block of the original image into one pixel in the temporary array.
                temp[i][j] = (image[2 * i][2 * j] + image[2 * i][2 * j + 1] + image[2 * i + 1][2 * j] +
                              image[2 * i + 1][(j * 2) + 1]) / 4;
            }
        }
    }

    if (s == 2){

        // Shrink to 1/3 size
        for (int i = 0; i < 256; i++) {
            for (int j = 0; j < 256; j++) {
                temp[i][j] = 255;
            }
        }
        for (int i = 0; i < 86; i++) {
            for (int j = 0; j < 86; j++) {

                //As the 1/2 size case but taking a 3x3 block and averaging to a single pixel.
                temp[i][j] = (image[3 * i][3 * j] + image[3 * i][3 * j + 1] + image[3 * i + 1][3 * j] +
                              image[3 * i + 1][(j * 3) + 1]+ image[3 * i + 1][3 * j]+ image[3 * i][3 * j + 2]+ image[3 * i + 2][3 * j + 2]) / 7;
            }
        }
    }

    if (s == 3) {

        // Shrink to 1/4 size
        for (int i = 0; i < 256; i++) {
            for (int j = 0; j < 256; j++) {
                temp[i][j] = 255;
            }
        }

        // Similar to the 1/2 size case but Twice.
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                temp[i][j] = (image[2 * i][2 * j] + image[2 * i][2 * j + 1] + image[2 * i + 1][2 * j] +
                              image[2 * i + 1][(j * 2) + 1]) / 4;
            }
        }

        for (int i = 0; i < 256; i++) {
            for (int j = 0; j < 256; j++) {
                image[i][j] = temp[i][j];
            }
        }

        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                temp[i][j] = (image[2 * i][2 * j] + image[2 * i][2 * j + 1] + image[2 * i + 1][2 * j] +
                              image[2 * i + 1][(j * 2) + 1]) / 4;
            }
        }
    }

    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            image[i][j] = temp[i][j];
        }
    }
}



// Mirror filter :-
void Mirror_l () {

    //this code to mirror the left 1/2 by starting from the first Pixel and reversing the last one
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE/2; j++) {
            int temp[SIZE][SIZE];
            temp[i][j] = image[i][j];
            image [i][255 - j] = temp[i][j];

        }
    }
}
void Mirror_r () {

    //this code to mirror the right 1/2 by starting from the first Pixel and reversing the last one
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE/2; j++) {
            int temp[SIZE][SIZE];
            temp[i][j] = image[i][128 + j];
            image [i][127 - j] = temp[i][j];

        }
    }
}
void Mirror_u () {

    //this code to mirror the upper 1/2 by starting from the first Pixel and reversing the last one.
    for (int i = 0; i < SIZE/2; i++) {
        for (int j = 0; j < SIZE; j++) {
            int temp[SIZE][SIZE];
            temp[i][j] = image[i][j];
            image [255 - i][j] = temp[i][j];

        }
    }
}
void Mirror_d () {

    //this code to mirror the lower 1/2 by starting from the first Pixel and reversing the last one.
    for (int i = 0; i < SIZE/2; i++) {
        for (int j = 0; j < SIZE; j++) {
            int temp[SIZE][SIZE];
            temp[i][j] = image[128 + i][j];
            image [127 - i][j] = temp[i][j];

        }
    }
}



// Shuffle the image :-
void Shuffle () {

    unsigned char temp1[SIZE][SIZE];
    unsigned char temp2[SIZE][SIZE];
    unsigned char temp3[SIZE][SIZE];
    unsigned char temp4[SIZE][SIZE];

    //saving the first quarter
    for (int i = 0; i < SIZE / 2; i++) {
        for (int j = 0; j < SIZE / 2; j++) {
            temp1[i][j] = image[i][j];
        }
    }

    //saving the second quarter
    for (int i = 0; i < SIZE / 2; i++) {
        for (int j = 128; j < SIZE; j++) {
            temp2[i][j - 128] = image[i][j];
        }
    }
    //saving the third quarter
    for (int i = 128; i < SIZE; i++) {
        for (int j = 0; j < SIZE / 2; j++) {
            temp3[i - 128][j] = image[i][j];
        }
    }

    //saving the fourth quarter
    for (int i = 128; i < SIZE; i++) {
        for (int j = 128; j < SIZE; j++) {
            temp4[i - 128][j - 128] = image[i][j];
        }
    }

    //here the user get to choose how to shuffle and saving each quarter in the first one.
    int order;
    cout << "New order of quarters : ";
    for (int i = 0; i < 4; i++) {
        int k, w;

        if (i == 0) {
            k = 0;
            w = 0;
        }
        if (i == 1) {
            k = 0;
            w = 128;
        }
        if (i == 2) {
            k = 128;
            w = 0;
        }
        if (i == 3) {
            k = 128;
            w = 128;
        }

        cin >> order;

        //here we put each quarter in its chosen place
        if (order == 1) {
            int n = 0;
            int m = 0;
            for (int i = k; i < k + 128; i++) {
                m = 0;
                for (int j = w; j < w + 128; j++) {
                    image[i][j] = temp1[n][m];
                    m++;
                }
                n++;
            }
        }

        if (order == 2) {
            int n = 0;
            int m = 0;
            for (int i = k; i < k + 128; i++) {
                m = 0;
                for (int j = w; j < w + 128; j++) {
                    image[i][j] = temp2[n][m];
                    m++;
                }
                n++;
            }
        }

        if (order == 3) {
            int n = 0;
            int m = 0;
            for (int i = k; i < k + 128; i++) {
                m = 0;
                for (int j = w; j < w + 128; j++) {
                    image[i][j] = temp3[n][m];
                    m++;
                }
                n++;
            }
        }

        if (order == 4) {
            int n = 0;
            int m = 0;
            for (int i = k; i < k + 128; i++) {
                m = 0;
                for (int j = w; j < w + 128; j++) {
                    image[i][j] = temp4[n][m];
                    m++;
                }
                n++;
            }
        }
    }
}



// Blur filter :-
void Blur() {

    unsigned char temp[SIZE][SIZE];
    int it = 5; // Number of blur iterations.

    while (it--){

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                temp[i][j] = 255;
            }
        }

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                // Apply a 3x3 averaging filter to blur the image.
                temp[i][j] = (image[i - 1][j - 1] + image[i - 1][j] + image[i - 1][j + 1] + image[i][j - 1]
                              + image[i][j] + image[i][j + 1] + image[i + 1][j - 1] + image[i + 1][j] +
                              image[i + 1][j + 1]) / 9;
            }
        }

        // Copy the blurred image from the temporary array to the original image.
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = temp[i][j];
            }
        }
    }
}



// Crop filter :-
void Crop() {

    int x, y, w, l;
    cout << "Please enter (x - y - l - w): ";
    cin >> x >> y >> l >> w;

    // Calculate the horizontal and vertical boundaries for cropping.
    int hz = x + w;
    int vt = y + l;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // Check if the current pixel is outside the defined cropping area.
            if ((i > hz) || (i < x) || (j > vt) || (j < y)) {
                // Set pixels outside the cropping area to 255 (white).
                image[i][j] = 255;
            }
        }
    }
}



// Skew Image Right :-
void Skew_hz() {

    int angle;
    double k, m, rad, x;

    cout << "Input the required angle :" << endl;
    cin  >> angle;

    // Calculate the skew angle.
    angle = 90 - angle;

    // Convert the skew angle to radians.
    rad = tan((angle * M_PI) / 180);

    // Calculate 'x' to determine the skew transformation.
    x = 256 / (1 + 1 / rad);

    // Calculate 'm' and 'k' parameters for transformation.
    m = SIZE - x;
    k = m / SIZE;

    unsigned char temp[SIZE][SIZE];

    // Calculate 'y' and 'count' to determine pixel positions during skew.
    float y = SIZE / x, count;

    // Perform skew transformation by sampling and interpolating pixels.
    for (int i = 0; i < SIZE; i++) {
        count = 0;
        for (int j = 0; j < x; j++) {
            count += y;
            temp[i][j] = image[i][int(count)];
        }
    }

    // Initialize the entire image with white pixels.
    for (int i = SIZE - 1; i >= 0; i--) {
        for (int j = SIZE - 1; j >= 0; j--) {
            image[i][j] = 255;
        }
    }

    // Fill the skewed image with transformed pixel values.
    for (int i = 0; i < SIZE; i++) {
        int length = m + x, n = 0;
        for (int j = m; j < length; j++) {
            image[i][j] = temp[i][n];
            n++;
        }
        m -= k;
    }
}



// Skew Image Up :-
void Skew_vt() {

    int angle;
    double k, m, rad, x;

    cout << "Input the required angle :"  << endl;
    cin >> angle;

    // Calculate the skew angle.
    angle = 90 - angle;

    // Convert the skew angle to radians.
    rad = tan((angle * M_PI) / 180);

    // Calculate the parameter 'x' to determine the skew transformation.
    x = 256 / (1 + 1 / rad);

    // Calculate 'm' and 'k' parameters for transformation.
    m = SIZE - x;
    k = m / SIZE;

    unsigned char temp[SIZE][SIZE];

    // Calculate 'y' and 'count' to determine pixel positions during skew.
    float y = SIZE / x, count;

    // Perform skew transformation by sampling and interpolating pixels.
    for (int i = 0; i < SIZE; i++) {
        count = 0;
        for (int j = 0; j < x; j++) {
            count += y;
            temp[j][i] = image[int(count)][i];
        }
    }

    // Initialize the entire image with white pixels.
    for (int i = SIZE - 1; i >= 0; i--) {
        for (int j = SIZE - 1; j >= 0; j--) {
            image[i][j] = 255;
        }
    }

    // Fill the skewed image with transformed pixel values.
    for (int i = 0; i < SIZE; i++) {
        int length = m + x, n = 0;
        for (int j = m; j < length; j++) {
            image[j][i] = temp[n][i];
            n++;
        }
        m -= k;
    }
}