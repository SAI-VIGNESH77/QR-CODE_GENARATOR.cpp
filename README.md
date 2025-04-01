# QR-CODE_GENARATOR.cpp
Description
This C++ program generates a QR code from user input and saves it as a PNG file. It uses the libqrencode library to encode the data and libpng to create the image.

FEATURES

->Converts user input into a QR code

->Saves the QR code as qrcode.png

->Uses libqrencode for encoding

->Uses libpng to generate the PNG file

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

