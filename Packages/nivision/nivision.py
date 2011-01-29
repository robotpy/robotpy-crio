from _nivision import *

IMAQ_RGB_TRANSPARENT = RGBValue(   0,   0,   0, 1 )
IMAQ_RGB_RED         = RGBValue(   0,   0, 255, 0 )
IMAQ_RGB_BLUE        = RGBValue( 255,   0,   0, 0 )
IMAQ_RGB_GREEN       = RGBValue(   0, 255,   0, 0 )
IMAQ_RGB_YELLOW      = RGBValue(   0, 255, 255, 0 )
IMAQ_RGB_WHITE       = RGBValue( 255, 255, 255, 0 )
IMAQ_RGB_BLACK       = RGBValue(   0,   0,   0, 0 )

IMAQ_NO_RECT = imaqMakeRect( 0, 0, 0x7FFFFFFF, 0x7FFFFFFF)
IMAQ_NO_ROTATED_RECT = imaqMakeRotatedRect( 0, 0, 0x7FFFFFFF, 0x7FFFFFFF, 0)
IMAQ_NO_POINT = Point( -1, -1)
IMAQ_NO_POINT_FLOAT = PointFloat( -1.0, -1.0 )
IMAQ_NO_OFFSET = PointFloat( 0.0, 0.0 )

