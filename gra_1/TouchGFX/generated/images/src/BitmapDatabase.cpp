// 4.16.0 0x0d3d0b14
// Generated by imageconverter. Please, do not edit!

#include <BitmapDatabase.hpp>
#include <touchgfx/Bitmap.hpp>

extern const unsigned char image_blue_buttons_round_small[]; // BITMAP_BLUE_BUTTONS_ROUND_SMALL_ID = 0, Size: 170x60 pixels
extern const unsigned char image_blue_buttons_round_small_pressed[]; // BITMAP_BLUE_BUTTONS_ROUND_SMALL_PRESSED_ID = 1, Size: 170x60 pixels
extern const unsigned char image_dluuuugi_obraz[]; // BITMAP_DLUUUUGI_OBRAZ_ID = 2, Size: 4592x344 pixels
extern const unsigned char image_game_over[]; // BITMAP_GAME_OVER_ID = 3, Size: 821x423 pixels
extern const unsigned char image_ptaszek[]; // BITMAP_PTASZEK_ID = 4, Size: 163x161 pixels
extern const unsigned char image_tlo_2[]; // BITMAP_TLO_2_ID = 5, Size: 1920x1200 pixels
extern const unsigned char image_trasa[]; // BITMAP_TRASA_ID = 6, Size: 3306x262 pixels

const touchgfx::Bitmap::BitmapData bitmap_database[] =
{
    { image_blue_buttons_round_small, 0, 170, 60, 23, 5, 124, (uint8_t)(touchgfx::Bitmap::ARGB8888) >> 3, 48, (uint8_t)(touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_blue_buttons_round_small_pressed, 0, 170, 60, 23, 5, 124, (uint8_t)(touchgfx::Bitmap::ARGB8888) >> 3, 48, (uint8_t)(touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_dluuuugi_obraz, 0, 4592, 344, 0, 0, 4592, (uint8_t)(touchgfx::Bitmap::RGB565) >> 3, 344, (uint8_t)(touchgfx::Bitmap::RGB565) & 0x7 },
    { image_game_over, 0, 821, 423, 0, 0, 821, (uint8_t)(touchgfx::Bitmap::RGB565) >> 3, 423, (uint8_t)(touchgfx::Bitmap::RGB565) & 0x7 },
    { image_ptaszek, 0, 163, 161, 0, 0, 163, (uint8_t)(touchgfx::Bitmap::RGB565) >> 3, 161, (uint8_t)(touchgfx::Bitmap::RGB565) & 0x7 },
    { image_tlo_2, 0, 1920, 1200, 0, 0, 1920, (uint8_t)(touchgfx::Bitmap::RGB565) >> 3, 1200, (uint8_t)(touchgfx::Bitmap::RGB565) & 0x7 },
    { image_trasa, 0, 3306, 262, 0, 0, 3306, (uint8_t)(touchgfx::Bitmap::RGB565) >> 3, 262, (uint8_t)(touchgfx::Bitmap::RGB565) & 0x7 }
};

namespace BitmapDatabase
{
const touchgfx::Bitmap::BitmapData* getInstance()
{
    return bitmap_database;
}

uint16_t getInstanceSize()
{
    return (uint16_t)(sizeof(bitmap_database) / sizeof(touchgfx::Bitmap::BitmapData));
}
}
