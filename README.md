# QR-CODE_GENARATOR.cpp
Description
This C++ program generates a QR code from user input and saves it as a PNG file. It uses the libqrencode library to encode the data and libpng to create the image.

FEATURES

->Converts user input into a QR code

->Saves the QR code as qrcode.png

->Uses libqrencode for encoding

->Uses libpng to generate the PNG file
Built a CLI application in C++ that converts any text input into a QR code and saves it as a .png file.

Utilized libqrencode for QR code generation and libpng for image rendering.

Implemented margin and scaling options for better visual quality and customization.

Included error handling for file operations and library usage to improve robustness.

Demonstrated effective integration of third-party C/C++ libraries in real-world applications.

Ensured memory management and stability using structured exception checks (setjmp) and proper cleanup.



## Prerequisites
Before compiling and running the program, install the necessary libraries:
```sh
sudo apt update
sudo apt install libqrencode-dev libpng-dev
```
macOS (Homebrew)
```sh
brew install qrencode libpng
```
g++ -o qr_generator qr_generator.cpp -lqrencode -lpng

```sh
g++ -o qr_generator qr_generator.cpp -lqrencode -lpng
```
Output  

-->A PNG file (qrcode.png) containing the generated QR code.

Future Improvements  

-->Add an option to specify the output file name.

-->Implement a GUI interface.

-->Allow setting QR code size and error correction level.

