
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

//This code is just the same as the grey scaled code with just adding the RGB matrices.

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE][RGB];
unsigned char second_image[SIZE][SIZE][RGB];

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



//load image functions :-
void loadImage () {
    char imageFileName[100];
    cout << " Enter the source image file name : ";
    cin >> imageFileName;
    strcat (imageFileName, ".bmp");
    readRGBBMP(imageFileName, image);
}
void loadImage2 () {
    char imageFileName[100];
    cout << " Enter the source image file name : ";
    cin >> imageFileName;
    strcat (imageFileName, ".bmp");
    readRGBBMP(imageFileName, second_image);
}

//save image functions :-
void saveImage () {
    char imageFileName[100];
    cout << "Enter the target image file name: ";
    cin >> imageFileName;
    strcat (imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image);
}



// Black and White Filter :-
void BW() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // Calculate the average grayscale value using the RGB channels
            unsigned char grayscale = (image[i][j][0] + image[i][j][1] + image[i][j][2]) / 3;

            // Set all RGB channels to the grayscale value
            for (int r = 0; r < RGB; r++) {
                image[i][j][r] = grayscale;
            }
        }
    }
}



// Invert filter by reversing the black pixels to white pixels :-
void Invert() {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int r = 0; r < RGB; r++) {
                image[i][j][r] = 255 - image[i][j][r];
            }
        }
    }
}



// Merge filter merging the pixels into each other by adding them and divide them by 2 :-
void Merge () {

    loadImage2();
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int r = 0; r < RGB; r++) {
                image[i][j][r] = (image[i][j][r] + second_image[i][j][r]) / 2;
            }
        }
    }
}



// Flip filters horizontally or vertically by swapping the last coulomb or raw with the first :-
void Flip_horizontal () {

    for (int i = 0; i < SIZE / 2; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int r = 0; r < RGB; r++) {
                swap(image[i][j][r], image[255 - 1 - i][j][r]);
            }
        }
    }
}
void Flip_vertical () {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE / 2; j++) {
            for (int r = 0; r < RGB; r++) {
                swap(image[i][j][r], image[i][255 - 1 - j][r]);
            }
        }
    }
}



// Brightness filters lighten up the image or darken it 50% by adding more white or black to the image :-
void Lighten() {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            for (int r = 0; r < RGB; r++) {
                image[i][j][r] = (255 + image[i][j][r]) / 2;
            }
        }
    }
}
void Darken () {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            for (int r = 0; r < RGB; r++) {
                image[i][j][r] = (image[i][j][r] / 2);
            }
        }
    }
}



// Rotation filter rotate the image in 90 or 180 or 270 degrees :-
void Rotate () {

    int y,x;
    int temp [SIZE][SIZE][RGB];
    cout<<"Please enter the rotation Degree (90 - 180 - 270): ";
    cin>>y ;
    x = (0.5 * y);
    while(x--){

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int r = 0; r < RGB; r++) {
                    temp[i][j][r] = image[i][j][r];
                }
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int r = 0; r < RGB; r++) {
                    image[i][j][r] = temp[255 - j][i][r];
                }
            }
        }
    }
}



// Detect the edges of the image by checking the difference of color between pixels :-
void Detect(){

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int r = 0; r < RGB; r++) {

                if ((abs(image[i][j][r] - image[i][j + 1][r]) >= 32) || (abs(image[i][j][r] - image[i + 1][j][r]) >= 32)) {
                    image[i][j][r] = 0;
                } else
                    image[i][j][r] = 250;

            }
        }
    }
}



// Enlarge filter :-
void Enlarge (){

    unsigned char temp[SIZE][SIZE][RGB];
    int q;
    cout<<"Which quarter to enlarge 1, 2, 3 or 4?";
    cin>>q;


    if (q == 1) {
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                for (int r = 0; r < RGB; r++) {
                    temp[2 * i][2 * j][r] = image[i][j][r];
                    temp[2 * i + 1][2 * j][r] = image[i][j][r];
                    temp[2 * i][2 * j + 1][r] = image[i][j][r];
                    temp[2 * i + 1][2 * j + 1][r] = image[i][j][r];
                }
            }
        }
    }
    else if (q == 2) {
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 128; j < SIZE; j++) {
                for (int r = 0; r < RGB; r++) {
                    temp[2 * i][2 * (j - SIZE / 2)][r] = image[i][j][r];
                    temp[2 * i + 1][2 * (j - SIZE / 2)][r] = image[i][j][r];
                    temp[2 * i][2 * (j - SIZE / 2) + 1][r] = image[i][j][r];
                    temp[2 * i + 1][2 * (j - SIZE / 2) + 1][r] = image[i][j][r];
                }
            }
        }
    }
    else if (q == 3) {
        for (int i = 128; i < SIZE; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                for (int r = 0; r < RGB; r++) {
                    temp[2 * (i - SIZE / 2)][2 * j][r] = image[i][j][r];
                    temp[2 * (i - SIZE / 2) + 1][2 * j][r] = image[i][j][r];
                    temp[2 * (i - SIZE / 2)][2 * j + 1][r] = image[i][j][r];
                    temp[2 * (i - SIZE / 2) + 1][2 * j + 1][r] = image[i][j][r];
                }
            }
        }
    }
    else if (q == 4) {
        for (int i = 128; i < SIZE; i++) {
            for (int j = 128; j < SIZE; j++) {
                for (int r = 0; r < RGB; r++) {
                    temp[2 * (i - SIZE / 2)][2 * (j - SIZE / 2)][r] = image[i][j][r];
                    temp[2 * (i - SIZE / 2) + 1][2 * (j - SIZE / 2)][r] = image[i][j][r];
                    temp[2 * (i - SIZE / 2)][2 * (j - SIZE / 2) + 1][r] = image[i][j][r];
                    temp[2 * (i - SIZE / 2) + 1][2 * (j - SIZE / 2) + 1][r] = image[i][j][r];
                }
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int r = 0; r < RGB; r++) {
                image[i][j][r] = temp[i][j][r];
            }
        }
    }
}



// Shrink filter :-
void shrink (){

    int temp[SIZE][SIZE][RGB];
    int s;
    cout<<"Shrink to ?"<<endl
        <<"1- (1/2)" <<endl
        <<"2- (1/3)" <<endl
        <<"3- (1/4)"<<endl;
    cin >>s;
    if (s == 1){
        for (int i = 0; i < 256; i++) {
            for (int j = 0; j < 256; j++) {
                for (int r = 0; r < RGB; r++) {
                    temp[i][j][r] = 255;
                }
            }
        }
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                for (int r = 0; r < RGB; r++) {
                    temp[i][j][r] = (image[2 * i][2 * j][r] + image[2 * i][2 * j + 1][r] + image[2 * i + 1][2 * j][r] +
                                     image[2 * i + 1][(j * 2) + 1][r]) / 4;
                }
            }
        }
    }
    if (s == 2){
        for (int i = 0; i < 256; i++) {
            for (int j = 0; j < 256; j++) {
                for (int r = 0; r < RGB; r++) {
                    temp[i][j][r] = 255;
                }
            }
        }
        for (int i = 0; i < 86; i++) {
            for (int j = 0; j < 86; j++) {
                for (int r = 0; r < RGB; r++) {
                    temp[i][j][r] = (image[3 * i][3 * j][r] + image[3 * i][3 * j + 1][r] + image[3 * i + 1][3 * j][r] +
                                  image[3 * i + 1][(j * 3) + 1][r] + image[3 * i + 1][3 * j][r] +
                                  image[3 * i][3 * j + 2][r] + image[3 * i + 2][3 * j + 2][r]) / 7;
                }
            }
        }
    }
    if (s == 3) {
        for (int i = 0; i < 256; i++) {
            for (int j = 0; j < 256; j++) {
                for (int r = 0; r < RGB; r++) {
                    temp[i][j][r] = 255;
                }
            }
        }
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                for (int r = 0; r < RGB; r++) {
                    temp[i][j][r] = (image[2 * i][2 * j][r] + image[2 * i][2 * j + 1][r] + image[2 * i + 1][2 * j][r] +
                                     image[2 * i + 1][(j * 2) + 1][r]) / 4;
                }
            }
        }
        for (int i = 0; i < 256; i++) {
            for (int j = 0; j < 256; j++) {
                for (int r = 0; r < RGB; r++) {
                    image[i][j][r] = temp[i][j][r];
                }
            }
        }
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                for (int r = 0; r < RGB; r++) {
                    temp[i][j][r] = (image[2 * i][2 * j][r] + image[2 * i][2 * j + 1][r] + image[2 * i + 1][2 * j][r] +
                                     image[2 * i + 1][(j * 2) + 1][r]) / 4;
                }
            }
        }
    }
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            for (int r = 0; r < RGB; r++) {
                image[i][j][r] = temp[i][j][r];
            }
        }
    }
}



// Mirror filter :-
void Mirror_l () {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE/2; j++) {
            for (int r = 0; r < RGB; r++) {
                int temp[SIZE][SIZE][RGB];
                temp[i][j][r] = image[i][j][r];
                image[i][255 - j][r] = temp[i][j][r];
            }
        }
    }
}
void Mirror_r () {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE/2; j++) {
            for (int r = 0; r < RGB; r++) {
                int temp[SIZE][SIZE][RGB];
                temp[i][j][r] = image[i][128 + j][r];
                image[i][127 - j][r] = temp[i][j][r];
            }
        }
    }
}
void Mirror_u () {

    for (int i = 0; i < SIZE/2; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int r = 0; r < RGB; r++) {
                int temp[SIZE][SIZE][RGB];
                temp[i][j][r] = image[i][j][r];
                image[255 - i][j][r] = temp[i][j][r];
            }
        }
    }
}
void Mirror_d () {

    for (int i = 0; i < SIZE/2; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int r = 0; r < RGB; r++) {
                int temp[SIZE][SIZE][RGB];
                temp[i][j][r] = image[128 + i][j][r];
                image[127 - i][j][r] = temp[i][j][r];
            }
        }
    }
}



// Shuffle the image :-
void Shuffle() {

    unsigned char temp1[SIZE][SIZE][RGB];
    unsigned char temp2[SIZE][SIZE][RGB];
    unsigned char temp3[SIZE][SIZE][RGB];
    unsigned char temp4[SIZE][SIZE][RGB];

    for (int i = 0; i < SIZE / 2; i++) {
        for (int j = 0; j < SIZE / 2; j++) {
            for (int r = 0; r < RGB; r++) {
                temp1[i][j][r] = image[i][j][r];
            }
        }
    }
    for (int i = 0; i < SIZE / 2; i++) {
        for (int j = 128; j < SIZE; j++) {
            for (int r = 0; r < RGB; r++) {
                temp2[i][j - 128][r] = image[i][j][r];
            }
        }
    }
    for (int i = 128; i < SIZE; i++) {
        for (int j = 0; j < SIZE / 2; j++) {
            for (int r = 0; r < RGB; r++) {
                temp3[i - 128][j][r] = image[i][j][r];
            }
        }
    }

    for (int i = 128; i < SIZE; i++) {
        for (int j = 128; j < SIZE; j++) {
            for (int r = 0; r < RGB; r++) {
                temp4[i - 128][j - 128][r] = image[i][j][r];
            }
        }
    }

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

        if (order == 1) {
            int n = 0;
            int m = 0;
            for (int i = k; i < k + 128; i++) {
                m = 0;
                for (int j = w; j < w + 128; j++) {
                    for (int r = 0; r < RGB; r++) {
                        image[i][j][r] = temp1[n][m][r];
                    }
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
                    for (int r = 0; r < RGB; r++) {
                        image[i][j][r] = temp2[n][m][r];
                    }
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
                    for (int r = 0; r < RGB; r++) {
                        image[i][j][r] = temp3[n][m][r];
                    }
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
                    for (int r = 0; r < RGB; r++) {
                        image[i][j][r] = temp4[n][m][r];
                    }
                    m++;
                }
                n++;
            }
        }
    }
}



// Blur filter :-
void Blur() {

    unsigned char temp[SIZE][SIZE][RGB];
    int c = 9;

    while (c--){

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int r = 0; r < RGB; r++) {
                    temp[i][j][r] = 255;
                }
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int r = 0; r < RGB; r++) {
                    temp[i][j][r] =
                            (image[i - 1][j - 1][r] + image[i - 1][j][r] + image[i - 1][j + 1][r] + image[i][j - 1][r]
                             + image[i][j][r] + image[i][j + 1][r] + image[i + 1][j - 1][r] + image[i + 1][j][r] +
                             image[i + 1][j + 1][r]) / 9;
                }
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int r = 0; r < RGB; r++) {
                    image[i][j][r] = temp[i][j][r];
                }
            }
        }
    }
}



// Crop filter :-
void Crop() {

    int x, y, w, l;
    cout << "Please enter (x - y - l - w): ";
    cin >> x >> y >> l >> w;

    int hz = x + w;
    int vt = y + l;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int r = 0; r < RGB; r++) {
                if ((i > hz) || (i < x) || (j > vt) || (j < y)) {
                    image[i][j][r] = 255;
                }
            }
        }
    }
}



// Skew Image Right :-
void Skew_hz() {

    int angle;
    double unit,step,rad,x;
    cout << "Input the required angle :" << endl;
    cin  >> angle;
    angle = 90 - angle;
    rad = (tan((angle*M_PI)/180));
    x= 256/(1+1/rad);
    step = SIZE -x;
    unit =step/SIZE;
    unsigned char temp[SIZE][SIZE][RGB];
    float y= SIZE/x,count;
    for (int i = 0; i < SIZE; i++) {
        count=0;
        for (int j = 0; j < x; j++) {
            count += y;
            for (int r = 0; r < RGB; r++) {
                temp[i][j][r] = image[i][int(count)][r];

            }
        }
    }
    for (int i = SIZE-1; i >= 0; i--) {
        for (int j = SIZE-1; j >= 0; j--) {
            for (int r = 0; r < RGB; r++) {
                image[i][j][r] = 255;
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        int length=step +x,n=0;
        for (int j = step; j < length; j++) {
            for (int r = 0; r < RGB; r++) {
                image[i][j][r] = temp[i][n][r];
            }
            n++;
        }
        step-=unit;
    }
}



// Skew Image Up :-
void Skew_vt() {

    int angle;
    double unit,step,rad,x;
    cout<<"Input the required angle :"  << endl;
    cin >> angle;
    angle = 90-angle;
    rad = (tan((angle*M_PI)/180));
    x= 256 / (1+1 / rad);
    step = SIZE -x;
    unit =step/SIZE;
    unsigned char temp[SIZE][SIZE][RGB];
    float y= SIZE/x,count;
    for (int i = 0; i < SIZE; i++) {
        count=0;
        for (int j = 0; j < x; j++) {
            count+=y;
            for (int r = 0; r < RGB; r++) {
                temp[j][i][r] = image[int(count)][i][r];
            }

        }
    }
    for (int i = SIZE-1; i >= 0; i--) {
        for (int j = SIZE-1; j >= 0; j--) {
            for (int r = 0; r < RGB; r++) {
                image[i][j][r] = 255;
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        int length = step +x,n=0;
        for (int j = step; j < length; j++) {
            for (int r = 0; r < RGB; r++) {
                image[j][i][r] = temp[n][i][r];
            }
            n++;
        }
        step-=unit;
    }
}