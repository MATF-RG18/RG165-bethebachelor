#ifndef __IMAGE_HPP_
#define __IMAGE_HPP_

/*
 * Dve strukture koje opisuju strukturu dva zaglavlja
 * kojima pocinje svaka slika u bmp formatu.
 */
typedef struct {
  unsigned short type;
  unsigned int size;
  unsigned short reserved1;
  unsigned short reserved2;
  unsigned int offsetbits;
} BITMAPFILEHEADER;

typedef struct {
  unsigned int size;
  unsigned int width;
  unsigned int height;
  unsigned short planes;
  unsigned short bitcount;
  unsigned int compression;
  unsigned int sizeimage;
  int xpelspermeter;
  int ypelspermeter;
  unsigned int colorsused;
  unsigned int colorsimportant;
} BITMAPINFOHEADER;

/* Struktura za smestanje podataka o slici. */
typedef struct Image {
  int width, height; /* Dimenzije slike. */
  char *pixels; /* Niz u kojem se cuvaju podaci za sve piksele u obliku (R, G, B). */
} Image;

/* Funkcija koja inicijalizuje strukturu i vraca pokazivac na nju. */
Image *image_init(int width, int height);


void image_read(Image *image, char *filename);

/*
 * Funkcija koja oslobadja prostor u kojem su se cuvali
 * podaci o slici.
 */
void image_done(Image *image);



#endif