#include <iostream>
#include <qrencode.h>
#include <png.h>
#include <fstream>

using namespace std;

void savePNG(QRcode *qrcode, const char *filename) {
    int size = 10;
    int margin = 4;
    int width = (qrcode->width + margin * 2) * size;

    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        cerr << "Failed to open file for writing." << endl;
        return;
    }

    png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    png_infop info = png_create_info_struct(png);
    if (!png || !info) {
        fclose(fp);
        return;
    }
    if (setjmp(png_jmpbuf(png))) {
        fclose(fp);
        return;
    }
    png_init_io(png, fp);
    png_set_IHDR(png, info, width, width, 8, PNG_COLOR_TYPE_GRAY, PNG_INTERLACE_NONE,
                 PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
    png_write_info(png, info);

    png_bytep row = (png_bytep)malloc(width * sizeof(png_byte));
    for (int y = -margin; y < qrcode->width + margin; ++y) {
        for (int x = -margin; x < qrcode->width + margin; ++x) {
            int pixel = ((x >= 0 && y >= 0 && x < qrcode->width && y < qrcode->width) &&
                         (qrcode->data[y * qrcode->width + x] & 1))
                        ? 0 : 255;
            for (int i = 0; i < size; ++i) {
                row[(x + margin) * size + i] = pixel;
            }
        }
        for (int i = 0; i < size; ++i) {
            png_write_row(png, row);
        }
    }

    png_write_end(png, NULL);
    png_destroy_write_struct(&png, &info);
    free(row);
    fclose(fp);
}

int main() {
    string input;
    cout << "Enter text to generate QR code: ";
    getline(cin, input);

    QRcode *qrcode = QRcode_encodeString(input.c_str(), 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (!qrcode) {
        cerr << "QR code generation failed!" << endl;
        return 1;
    }

    savePNG(qrcode, "qrcode.png");
    QRcode_free(qrcode);
    cout << "QR Code generated as 'qrcode.png'" << endl;
    return 0;
}
