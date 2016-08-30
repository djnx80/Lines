#ifndef _LINES_H_
#define _LINES_H_

class Lines {
private:
    float xC, yC;
    int ile;
    float dlugosc[20];
    float X[20];
    float Y[20];
    float xMax,yMax;
    unsigned char r[20];
    unsigned char g[20];
    unsigned char b[20];
    float dX[20];

public:
    void init(int, float, float, float, unsigned char, unsigned char, unsigned char);
    void rysujLinie();
    void ruszLinie();
    Lines();

};

#endif
