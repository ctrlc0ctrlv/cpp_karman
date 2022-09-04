#include <fstream>
#include <iostream>
#include "drawer.hpp"

// TESTS:
// #define BMP_TEST

Drawer::Drawer(int w, int h)
{
    width = w;
    height = h;
    gridUpdated = false;
    grid = std::vector<std::vector<int>>(width);
    pole = std::vector<std::vector<double>>(width);
    figures = std::vector<Figure *>(0);
    for (size_t i = 0; i < width; i++)
    {
        grid[i] = std::vector<int>(height, 0);
        pole[i] = std::vector<double>(height, 0);
    }
}

Drawer::~Drawer()
{
    // freeing figure pointers as they were recieved using 'new'
    for (std::vector<Figure *>::iterator pObj = figures.begin(); pObj != figures.end(); ++pObj)
        delete *pObj;
}

void Drawer::updateGrid()
{
    if (!gridUpdated)
        for (size_t i = 0; i < width; i++)
        {
            for (size_t j = 0; j < height; j++)
            {
                for (auto f : figures)
                {
                    if (f->check(i, j))
                    {
                        grid[i][j] = 1;
                        break;
                    }
                }
            }
        }
    gridUpdated = true;
}

void Drawer::drawArr()
{
    updateGrid();
    for (size_t y = 0; y < height; y++)
    {
        for (size_t x = 0; x < width; x++)
            std::cout << grid[x][y];
        std::cout << std::endl;
    }
}

void Drawer::addFig(Figure *fig)
{
    figures.push_back(fig);
    gridUpdated = false;
}

void Drawer::drawBMP(std::string filename)
{
    // point (0, 0) is left bottom corner of .bmp file
    updateGrid();
    int filesize = 54 + 3 * width * height;
    // unsigned char img[54 + 3 * 100 * 25];
    std::vector<char> img(filesize);
    int i, j;
    double min_field = INF, max_field = -INF, MN = INF;
    int x, y;

    // поиск экстремальных значений поля
    for (i = 0; i < width; i++)
        for (j = 0; j < height; j++)
        {
            min_field = std::min(min_field, pole[i][j]);
            max_field = std::max(max_field, pole[i][j]);
        }
    min_field /= skala; // определение границ цветовой шкалы по значениям
    max_field /= skala; // изменение этого значения изменяет цветовую шкалу

    double hue;
    // красный цвет - максимальное значение, фиолетовый цвет - минимальное значение!
    std::array<double, 3> rgb;

#ifdef BMP_TEST
    std::cout << "BMP_TEST_1" << std::endl;
#endif

    for (j = 0; j < height; j++)
    {
        for (i = 0; i < width; i++)
        {
            HSV color(pole[i][j], 1, 1);
            hue = pole[i][j];
            hue = std::max(hue, min_field);
            hue = std::min(hue, max_field);
            hue = 360 - 360 * (hue - min_field) / (max_field - min_field);
            hue *= 0.8;

            while (hue > 360)
                hue -= 360;
            while (hue < 0)
                hue += 360;

            if (grid[i][j])
                color.value = 0;
            rgb = color.asRGB();

            double r = rgb[0] * 255;
            double g = rgb[1] * 255;
            double b = rgb[2] * 255;

            x = i;
            y = (height - 1) - j;
            img[(x + y * width) * 3 + 2] = (unsigned char)(r);
            img[(x + y * width) * 3 + 1] = (unsigned char)(g);
            img[(x + y * width) * 3 + 0] = (unsigned char)(b);
        }
    }
#ifdef BMP_TEST
    std::cout << "BMP_TEST_2" << std::endl;
#endif

    char bmpfileheader[14] = {'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0};
    char bmpinfoheader[40] = {40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0};
    char bmppad[3] = {0, 0, 0};

    bmpfileheader[2] = (unsigned char)(filesize);
    bmpfileheader[3] = (unsigned char)(filesize >> 8);
    bmpfileheader[4] = (unsigned char)(filesize >> 16);
    bmpfileheader[5] = (unsigned char)(filesize >> 24);

    bmpinfoheader[4] = (unsigned char)(width);
    bmpinfoheader[5] = (unsigned char)(width >> 8);
    bmpinfoheader[6] = (unsigned char)(width >> 16);
    bmpinfoheader[7] = (unsigned char)(width >> 24);
    bmpinfoheader[8] = (unsigned char)(height);
    bmpinfoheader[9] = (unsigned char)(height >> 8);
    bmpinfoheader[10] = (unsigned char)(height >> 16);
    bmpinfoheader[11] = (unsigned char)(height >> 24);

    // WORKS GREAT, BUT WE NEED VECTORS!
    // FILE *f;
    // f = fopen(filename.c_str(), "wb");
    // fwrite(bmpfileheader, 1, 14, f);
    // fwrite(bmpinfoheader, 1, 40, f);
#ifdef BMP_TEST
    std::cout << "BMP_TEST_3" << std::endl;
#endif
    // for (i = 0; i < height; i++)
    // {
    // fwrite(img + (width * (height - i - 1) * 3), sizeof(unsigned char) * 3, width, f);
    // before: fwrite(img + (width * (height - i - 1) * 3), 3, width, f);
    // fwrite(bmppad, sizeof(unsigned char), (4 - (width * 3) % 4) % 4, f);
    // before: fwrite(bmppad, 1, (4 - (width * 3) % 4) % 4, f);
    // }
    // fclose(f);
    //

    std::ofstream outfile(filename, std::ios::binary);
    outfile.write(bmpfileheader, 14);
    outfile.write(bmpinfoheader, 40);
#ifdef BMP_TEST
    std::cout << "BMP_TEST_4" << std::endl;
#endif
    for (i = 0; i < height; i++)
    {
        auto it = img.begin() + (width * (height - i - 1) * 3);
        outfile.write(&(*(it)), width * 3);
        outfile.write(bmppad, (4 - (width * 3) % 4) % 4);
    }
    outfile.close();
#ifdef BMP_TEST
    std::cout << "BMP_TEST_5" << std::endl;
#endif
}

///////////////////////////////////////////////////////////////////////////////

HSV::HSV(double h, double s, double v)
{
    hue = h;
    sat = s;
    value = v;
}

std::array<double, 3> HSV::asRGB()
{
    int i;
    double f, p, q, t;
    double red, green, blue;
    if (value == 0)
    {
        red = 0;
        green = 0;
        blue = 0;
    }
    else
    {
        hue /= 60;
        i = (int)floor(hue);
        f = hue - i;
        p = value * (1 - sat);
        q = value * (1 - (sat * f));
        t = value * (1 - (sat * (1 - f)));
        switch (i)
        {
        case 0:
            red = value;
            green = t;
            blue = p;
            break;
        case 1:
            red = q;
            green = value;
            blue = p;
            break;
        case 2:
            red = p;
            green = value;
            blue = t;
            break;
        case 3:
            red = p;
            green = q;
            blue = value;
            break;
        case 4:
            red = t;
            green = p;
            blue = value;
            break;
        case 5:
            red = value;
            green = p;
            blue = q;
            break;
        default:
            break;
        }
    }
    return {red, green, blue};
}