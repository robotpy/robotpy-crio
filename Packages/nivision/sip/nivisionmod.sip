//
//  nivisionmod.sip - SIP bindings for wpilib nivision library
//  This file is part of RobotPy.
//

%Module _nivision

%Copying
Copyright (c) 2011 Peter Johnson

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
%End

%DefaultEncoding "UTF-8"

%ModuleCode
#include <WPILib/nivision.h>
%End

//============================================================================
//  Enumerated Types
//============================================================================
enum SearchStrategy {
    IMAQ_CONSERVATIVE               = 1,
    IMAQ_BALANCED                   = 2,
    IMAQ_AGGRESSIVE                 = 3,
    IMAQ_VERY_AGGRESSIVE            = 4,
    IMAQ_SEARCH_STRATEGY_SIZE_GUARD = 0xFFFFFFFF   
};

enum MeterArcMode {
    IMAQ_METER_ARC_ROI             = 0,
    IMAQ_METER_ARC_POINTS          = 1,
    IMAQ_METER_ARC_MODE_SIZE_GUARD = 0xFFFFFFFF   
};

enum MorphologyMethod {
    IMAQ_AUTOM                        = 0,
    IMAQ_CLOSE                        = 1,
    IMAQ_DILATE                       = 2,
    IMAQ_ERODE                        = 3,
    IMAQ_GRADIENT                     = 4,
    IMAQ_GRADIENTOUT                  = 5,
    IMAQ_GRADIENTIN                   = 6,
    IMAQ_HITMISS                      = 7,
    IMAQ_OPEN                         = 8,
    IMAQ_PCLOSE                       = 9,
    IMAQ_POPEN                        = 10,
    IMAQ_THICK                        = 11,
    IMAQ_THIN                         = 12,
    IMAQ_MORPHOLOGY_METHOD_SIZE_GUARD = 0xFFFFFFFF   
};

enum ObjectType {
    IMAQ_BRIGHT_OBJECTS         = 0,
    IMAQ_DARK_OBJECTS           = 1,
    IMAQ_OBJECT_TYPE_SIZE_GUARD = 0xFFFFFFFF   
};

enum OutlineMethod {
    IMAQ_EDGE_DIFFERENCE           = 0,
    IMAQ_EDGE_GRADIENT             = 1,
    IMAQ_EDGE_PREWITT              = 2,
    IMAQ_EDGE_ROBERTS              = 3,
    IMAQ_EDGE_SIGMA                = 4,
    IMAQ_EDGE_SOBEL                = 5,
    IMAQ_OUTLINE_METHOD_SIZE_GUARD = 0xFFFFFFFF   
};

enum PaletteType {
    IMAQ_PALETTE_GRAY            = 0,
    IMAQ_PALETTE_BINARY          = 1,
    IMAQ_PALETTE_GRADIENT        = 2,
    IMAQ_PALETTE_RAINBOW         = 3,
    IMAQ_PALETTE_TEMPERATURE     = 4,
    IMAQ_PALETTE_USER            = 5,
    IMAQ_PALETTE_TYPE_SIZE_GUARD = 0xFFFFFFFF   
};

enum ParticleInfoMode {
    IMAQ_BASIC_INFO                    = 0,
    IMAQ_ALL_INFO                      = 1,
    IMAQ_PARTICLE_INFO_MODE_SIZE_GUARD = 0xFFFFFFFF   
};

enum PhotometricMode {
    IMAQ_WHITE_IS_ZERO               = 0,
    IMAQ_BLACK_IS_ZERO               = 1,
    IMAQ_PHOTOMETRIC_MODE_SIZE_GUARD = 0xFFFFFFFF   
};

enum Plane3D {
    IMAQ_3D_REAL             = 0,
    IMAQ_3D_IMAGINARY        = 1,
    IMAQ_3D_MAGNITUDE        = 2,
    IMAQ_3D_PHASE            = 3,
    IMAQ_PLANE_3D_SIZE_GUARD = 0xFFFFFFFF   
};

enum PointSymbol {
    IMAQ_POINT_AS_PIXEL          = 0,
    IMAQ_POINT_AS_CROSS          = 1,
    IMAQ_POINT_USER_DEFINED      = 2,
    IMAQ_POINT_SYMBOL_SIZE_GUARD = 0xFFFFFFFF   
};

enum PolarityType {
    IMAQ_EDGE_RISING              = 1,
    IMAQ_EDGE_FALLING             = -1,
    IMAQ_POLARITY_TYPE_SIZE_GUARD = 0xFFFFFFFF   
};

enum RakeDirection {
    IMAQ_LEFT_TO_RIGHT             = 0,
    IMAQ_RIGHT_TO_LEFT             = 1,
    IMAQ_TOP_TO_BOTTOM             = 2,
    IMAQ_BOTTOM_TO_TOP             = 3,
    IMAQ_RAKE_DIRECTION_SIZE_GUARD = 0xFFFFFFFF   
};

enum RectOrientation {
    IMAQ_BASE_INSIDE                 = 0,
    IMAQ_BASE_OUTSIDE                = 1,
    IMAQ_TEXT_ORIENTATION_SIZE_GUARD = 0xFFFFFFFF   
};

enum ReferenceMode {
    IMAQ_COORD_X_Y                 = 0,
    IMAQ_COORD_ORIGIN_X            = 1,
    IMAQ_REFERENCE_MODE_SIZE_GUARD = 0xFFFFFFFF   
};

enum WindowOptions {
    IMAQ_WIND_RESIZABLE            = 1,
    IMAQ_WIND_TITLEBAR             = 2,
    IMAQ_WIND_CLOSEABLE            = 4,
    IMAQ_WIND_TOPMOST              = 8,
    IMAQ_WINDOW_OPTIONS_SIZE_GUARD = 0xFFFFFFFF   
};

enum ThresholdMethod {
    IMAQ_THRESH_CLUSTERING           = 0,
    IMAQ_THRESH_ENTROPY              = 1,
    IMAQ_THRESH_METRIC               = 2,
    IMAQ_THRESH_MOMENTS              = 3,
    IMAQ_THRESH_INTERCLASS           = 4,
    IMAQ_THRESHOLD_METHOD_SIZE_GUARD = 0xFFFFFFFF   
};

enum AttenuateMode {
    IMAQ_ATTENUATE_LOW             = 0,
    IMAQ_ATTENUATE_HIGH            = 1,
    IMAQ_ATTENUATE_MODE_SIZE_GUARD = 0xFFFFFFFF   
};

enum VisionInfoType {
    IMAQ_ANY_VISION_INFO             = 0,
    IMAQ_PATTERN_MATCHING_INFO       = 1,
    IMAQ_CALIBRATION_INFO            = 2,
    IMAQ_OVERLAY_INFO                = 3,
    IMAQ_VISION_INFO_TYPE_SIZE_GUARD = 0xFFFFFFFF   
};

enum VerticalTextAlignment {
    IMAQ_BOTTOM                             = 0,
    IMAQ_TOP                                = 1,
    IMAQ_BASELINE                           = 2,
    IMAQ_VERTICAL_TEXT_ALIGNMENT_SIZE_GUARD = 0xFFFFFFFF   
};

enum TwoEdgePolarityType {
    IMAQ_NONE                              = 0,
    IMAQ_RISING_FALLING                    = 1,
    IMAQ_FALLING_RISING                    = 2,
    IMAQ_RISING_RISING                     = 3,
    IMAQ_FALLING_FALLING                   = 4,
    IMAQ_TWO_EDGE_POLARITY_TYPE_SIZE_GUARD = 0xFFFFFFFF   
};

enum TruncateMode {
    IMAQ_TRUNCATE_LOW             = 0,
    IMAQ_TRUNCATE_HIGH            = 1,
    IMAQ_TRUNCATE_MODE_SIZE_GUARD = 0xFFFFFFFF   
};

enum ScalingMethod {
    IMAQ_SCALE_TO_PRESERVE_AREA    = 0,
    IMAQ_SCALE_TO_FIT              = 1,
    IMAQ_SCALING_METHOD_SIZE_GUARD = 0xFFFFFFFF   
};

enum TIFFCompressionType {
    IMAQ_NO_COMPRESSION                   = 0,
    IMAQ_JPEG                             = 1,
    IMAQ_RUN_LENGTH                       = 2,
    IMAQ_ZIP                              = 3,
    IMAQ_TIFF_COMPRESSION_TYPE_SIZE_GUARD = 0xFFFFFFFF   
};

enum ScalingMode {
    IMAQ_SCALE_LARGER            = 0,
    IMAQ_SCALE_SMALLER           = 1,
    IMAQ_SCALING_MODE_SIZE_GUARD = 0xFFFFFFFF   
};

enum TextAlignment {
    IMAQ_LEFT                      = 0,
    IMAQ_CENTER                    = 1,
    IMAQ_RIGHT                     = 2,
    IMAQ_TEXT_ALIGNMENT_SIZE_GUARD = 0xFFFFFFFF   
};

enum SpokeDirection {
    IMAQ_OUTSIDE_TO_INSIDE          = 0,
    IMAQ_INSIDE_TO_OUTSIDE          = 1,
    IMAQ_SPOKE_DIRECTION_SIZE_GUARD = 0xFFFFFFFF   
};

enum SkeletonMethod {
    IMAQ_SKELETON_L                 = 0,
    IMAQ_SKELETON_M                 = 1,
    IMAQ_SKELETON_INVERSE           = 2,
    IMAQ_SKELETON_METHOD_SIZE_GUARD = 0xFFFFFFFF   
};

enum SizeType {
    IMAQ_KEEP_LARGE           = 0,
    IMAQ_KEEP_SMALL           = 1,
    IMAQ_SIZE_TYPE_SIZE_GUARD = 0xFFFFFFFF   
};

enum ShapeMode {
    IMAQ_SHAPE_RECT            = 1,
    IMAQ_SHAPE_OVAL            = 2,
    IMAQ_SHAPE_MODE_SIZE_GUARD = 0xFFFFFFFF   
};

enum MatchingMode {
    IMAQ_MATCH_SHIFT_INVARIANT    = 1,
    IMAQ_MATCH_ROTATION_INVARIANT = 2,
    IMAQ_MATCHING_MODE_SIZE_GUARD = 0xFFFFFFFF   
};

enum Tool {
    IMAQ_NO_TOOL              = -1,
    IMAQ_SELECTION_TOOL       = 0,
    IMAQ_POINT_TOOL           = 1,
    IMAQ_LINE_TOOL            = 2,
    IMAQ_RECTANGLE_TOOL       = 3,
    IMAQ_OVAL_TOOL            = 4,
    IMAQ_POLYGON_TOOL         = 5,
    IMAQ_CLOSED_FREEHAND_TOOL = 6,
    IMAQ_ANNULUS_TOOL         = 7,
    IMAQ_ZOOM_TOOL            = 8,
    IMAQ_PAN_TOOL             = 9,
    IMAQ_POLYLINE_TOOL        = 10,
    IMAQ_FREEHAND_TOOL        = 11,
    IMAQ_ROTATED_RECT_TOOL    = 12,
    IMAQ_TOOL_SIZE_GUARD      = 0xFFFFFFFF   
};

enum CalibrationROI {
    IMAQ_FULL_IMAGE                 = 0,
    IMAQ_CALIBRATION_ROI            = 1,
    IMAQ_USER_ROI                   = 2,
    IMAQ_CALIBRATION_AND_USER_ROI   = 3,
    IMAQ_CALIBRATION_OR_USER_ROI    = 4,
    IMAQ_CALIBRATION_ROI_SIZE_GUARD = 0xFFFFFFFF   
};

enum MeasurementValue {
    IMAQ_AREA                         = 0,
    IMAQ_AREA_CALIBRATED              = 1,
    IMAQ_NUM_HOLES                    = 2,
    IMAQ_AREA_OF_HOLES                = 3,
    IMAQ_TOTAL_AREA                   = 4,
    IMAQ_IMAGE_AREA                   = 5,
    IMAQ_PARTICLE_TO_IMAGE            = 6,
    IMAQ_PARTICLE_TO_TOTAL            = 7,
    IMAQ_CENTER_MASS_X                = 8,
    IMAQ_CENTER_MASS_Y                = 9,
    IMAQ_LEFT_COLUMN                  = 10,
    IMAQ_TOP_ROW                      = 11,
    IMAQ_RIGHT_COLUMN                 = 12,
    IMAQ_BOTTOM_ROW                   = 13,
    IMAQ_WIDTH                        = 14,
    IMAQ_HEIGHT                       = 15,
    IMAQ_MAX_SEGMENT_LENGTH           = 16,
    IMAQ_MAX_SEGMENT_LEFT_COLUMN      = 17,
    IMAQ_MAX_SEGMENT_TOP_ROW          = 18,
    IMAQ_PERIMETER                    = 19,
    IMAQ_PERIMETER_OF_HOLES           = 20,
    IMAQ_SIGMA_X                      = 21,
    IMAQ_SIGMA_Y                      = 22,
    IMAQ_SIGMA_XX                     = 23,
    IMAQ_SIGMA_YY                     = 24,
    IMAQ_SIGMA_XY                     = 25,
    IMAQ_PROJ_X                       = 26,
    IMAQ_PROJ_Y                       = 27,
    IMAQ_INERTIA_XX                   = 28,
    IMAQ_INERTIA_YY                   = 29,
    IMAQ_INERTIA_XY                   = 30,
    IMAQ_MEAN_H                       = 31,
    IMAQ_MEAN_V                       = 32,
    IMAQ_MAX_INTERCEPT                = 33,
    IMAQ_MEAN_INTERCEPT               = 34,
    IMAQ_ORIENTATION                  = 35,
    IMAQ_EQUIV_ELLIPSE_MINOR          = 36,
    IMAQ_ELLIPSE_MAJOR                = 37,
    IMAQ_ELLIPSE_MINOR                = 38,
    IMAQ_ELLIPSE_RATIO                = 39,
    IMAQ_RECT_LONG_SIDE               = 40,
    IMAQ_RECT_SHORT_SIDE              = 41,
    IMAQ_RECT_RATIO                   = 42,
    IMAQ_ELONGATION                   = 43,
    IMAQ_COMPACTNESS                  = 44,
    IMAQ_HEYWOOD                      = 45,
    IMAQ_TYPE_FACTOR                  = 46,
    IMAQ_HYDRAULIC                    = 47,
    IMAQ_WADDLE_DISK                  = 48,
    IMAQ_DIAGONAL                     = 49,
    IMAQ_MEASUREMENT_VALUE_SIZE_GUARD = 0xFFFFFFFF   
};

enum ComplexPlane {
    IMAQ_REAL                     = 0,
    IMAQ_IMAGINARY                = 1,
    IMAQ_MAGNITUDE                = 2,
    IMAQ_PHASE                    = 3,
    IMAQ_COMPLEX_PLANE_SIZE_GUARD = 0xFFFFFFFF   
};

enum ComparisonFunction {
    IMAQ_CLEAR_LESS                  = 0,
    IMAQ_CLEAR_LESS_OR_EQUAL         = 1,
    IMAQ_CLEAR_EQUAL                 = 2,
    IMAQ_CLEAR_GREATER_OR_EQUAL      = 3,
    IMAQ_CLEAR_GREATER               = 4,
    IMAQ_COMPARE_FUNCTION_SIZE_GUARD = 0xFFFFFFFF   
};

enum ColorSensitivity {
    IMAQ_SENSITIVITY_LOW              = 0,
    IMAQ_SENSITIVITY_MED              = 1,
    IMAQ_SENSITIVITY_HIGH             = 2,
    IMAQ_COLOR_SENSITIVITY_SIZE_GUARD = 0xFFFFFFFF   
};

enum ColorMode {
    IMAQ_RGB                   = 0,
    IMAQ_HSL                   = 1,
    IMAQ_HSV                   = 2,
    IMAQ_HSI                   = 3,
    IMAQ_CIE                   = 4,
    IMAQ_CIEXYZ                = 5,
    IMAQ_COLOR_MODE_SIZE_GUARD = 0xFFFFFFFF   
};

enum ContourType {
    IMAQ_EMPTY_CONTOUR           = 0,
    IMAQ_POINT                   = 1,
    IMAQ_LINE                    = 2,
    IMAQ_RECT                    = 3,
    IMAQ_OVAL                    = 4,
    IMAQ_CLOSED_CONTOUR          = 5,
    IMAQ_OPEN_CONTOUR            = 6,
    IMAQ_ANNULUS                 = 7,
    IMAQ_ROTATED_RECT            = 8,
    IMAQ_CONTOUR_TYPE_SIZE_GUARD = 0xFFFFFFFF   
};

enum CalibrationUnit {
    IMAQ_UNDEFINED                   = 0,
    IMAQ_ANGSTROM                    = 1,
    IMAQ_MICROMETER                  = 2,
    IMAQ_MILLIMETER                  = 3,
    IMAQ_CENTIMETER                  = 4,
    IMAQ_METER                       = 5,
    IMAQ_KILOMETER                   = 6,
    IMAQ_MICROINCH                   = 7,
    IMAQ_INCH                        = 8,
    IMAQ_FOOT                        = 9,
    IMAQ_NAUTICMILE                  = 10,
    IMAQ_GROUNDMILE                  = 11,
    IMAQ_STEP                        = 12,
    IMAQ_CALIBRATION_UNIT_SIZE_GUARD = 0xFFFFFFFF   
};

enum DetectionMode {
    IMAQ_DETECT_PEAKS              = 0,
    IMAQ_DETECT_VALLEYS            = 1,
    IMAQ_DETECTION_MODE_SIZE_GUARD = 0xFFFFFFFF   
};

enum CalibrationMode {
    IMAQ_PERSPECTIVE                = 0,
    IMAQ_NONLINEAR                  = 1,
    IMAQ_SIMPLE_CALIBRATION         = 2,
    IMAQ_CORRECTED_IMAGE            = 3,
    IMAQ_DISTORTION_MODE_SIZE_GUARD = 0xFFFFFFFF   
};

enum BrowserLocation {
    IMAQ_INSERT_FIRST_FREE           = 0,
    IMAQ_INSERT_END                  = 1,
    IMAQ_BROWSER_LOCATION_SIZE_GUARD = 0xFFFFFFFF   
};

enum BrowserFrameStyle {
    IMAQ_RAISED_FRAME                   = 0,
    IMAQ_BEVELLED_FRAME                 = 1,
    IMAQ_OUTLINE_FRAME                  = 2,
    IMAQ_HIDDEN_FRAME                   = 3,
    IMAQ_STEP_FRAME                     = 4,
    IMAQ_RAISED_OUTLINE_FRAME           = 5,
    IMAQ_BROWSER_FRAME_STYLE_SIZE_GUARD = 0xFFFFFFFF   
};

enum BorderMethod {
    IMAQ_BORDER_MIRROR            = 0,
    IMAQ_BORDER_COPY              = 1,
    IMAQ_BORDER_CLEAR             = 2,
    IMAQ_BORDER_METHOD_SIZE_GUARD = 0xFFFFFFFF   
};

enum BarcodeType {
    IMAQ_INVALID                 = -1,
    IMAQ_CODABAR                 = 1,
    IMAQ_CODE39                  = 2,
    IMAQ_CODE93                  = 4,
    IMAQ_CODE128                 = 8,
    IMAQ_EAN8                    = 16,
    IMAQ_EAN13                   = 32,
    IMAQ_I2_OF_5                 = 64,
    IMAQ_MSI                     = 128,
    IMAQ_UPCA                    = 256,
    IMAQ_PHARMACODE              = 512,
    IMAQ_RSS_LIMITED             = 1024,
    IMAQ_BARCODE_TYPE_SIZE_GUARD = 0xFFFFFFFF   
};

enum AxisOrientation {
    IMAQ_DIRECT                      = 0,
    IMAQ_INDIRECT                    = 1,
    IMAQ_AXIS_ORIENTATION_SIZE_GUARD = 0xFFFFFFFF   
};

enum ColorIgnoreMode {
    IMAQ_IGNORE_NONE                        = 0,
    IMAQ_IGNORE_BLACK                       = 1,
    IMAQ_IGNORE_WHITE                       = 2,
    IMAQ_IGNORE_BLACK_AND_WHITE             = 3,
    IMAQ_BLACK_WHITE_IGNORE_MODE_SIZE_GUARD = 0xFFFFFFFF   
};

enum ImageType {
    IMAQ_IMAGE_U8              = 0,
    IMAQ_IMAGE_U16             = 7,
    IMAQ_IMAGE_I16             = 1,
    IMAQ_IMAGE_SGL             = 2,
    IMAQ_IMAGE_COMPLEX         = 3,
    IMAQ_IMAGE_RGB             = 4,
    IMAQ_IMAGE_HSL             = 5,
    IMAQ_IMAGE_RGB_U64         = 6,
    IMAQ_IMAGE_TYPE_SIZE_GUARD = 0xFFFFFFFF   
};

enum WindowThreadPolicy {
    IMAQ_CALLING_THREAD                  = 0,
    IMAQ_SEPARATE_THREAD                 = 1,
    IMAQ_WINDOW_THREAD_POLICY_SIZE_GUARD = 0xFFFFFFFF   
};

enum MappingMethod {
    IMAQ_FULL_DYNAMIC              = 0,
    IMAQ_DOWNSHIFT                 = 1,
    IMAQ_RANGE                     = 2,
    IMAQ_90_PCT_DYNAMIC            = 3,
    IMAQ_PERCENT_RANGE             = 4,
    IMAQ_MAPPING_METHOD_SIZE_GUARD = 0xFFFFFFFF   
};

enum LineGaugeMethod {
    IMAQ_EDGE_TO_EDGE                 = 0,
    IMAQ_EDGE_TO_POINT                = 1,
    IMAQ_POINT_TO_EDGE                = 2,
    IMAQ_POINT_TO_POINT               = 3,
    IMAQ_LINE_GAUGE_METHOD_SIZE_GUARD = 0xFFFFFFFF   
};

enum LevelType {
    IMAQ_ABSOLUTE              = 0,
    IMAQ_RELATIVE              = 1,
    IMAQ_LEVEL_TYPE_SIZE_GUARD = 0xFFFFFFFF   
};

enum LearningMode {
    IMAQ_LEARN_ALL                  = 0,
    IMAQ_LEARN_SHIFT_INFORMATION    = 1,
    IMAQ_LEARN_ROTATION_INFORMATION = 2,
    IMAQ_LEARNING_MODE_SIZE_GUARD   = 0xFFFFFFFF   
};

enum ConcentricRakeDirection {
    IMAQ_COUNTER_CLOCKWISE                    = 0,
    IMAQ_CLOCKWISE                            = 1,
    IMAQ_CONCENTRIC_RAKE_DIRECTION_SIZE_GUARD = 0xFFFFFFFF   
};

enum InterpolationMethod {
    IMAQ_ZERO_ORDER                      = 0,
    IMAQ_BILINEAR                        = 1,
    IMAQ_QUADRATIC                       = 2,
    IMAQ_CUBIC_SPLINE                    = 3,
    IMAQ_BILINEAR_FIXED                  = 4,
    IMAQ_INTERPOLATION_METHOD_SIZE_GUARD = 0xFFFFFFFF   
};

enum MathTransformMethod {
    IMAQ_TRANSFORM_LINEAR                 = 0,
    IMAQ_TRANSFORM_LOG                    = 1,
    IMAQ_TRANSFORM_EXP                    = 2,
    IMAQ_TRANSFORM_SQR                    = 3,
    IMAQ_TRANSFORM_SQRT                   = 4,
    IMAQ_TRANSFORM_POWX                   = 5,
    IMAQ_TRANSFORM_POW1X                  = 6,
    IMAQ_MATH_TRANSFORM_METHOD_SIZE_GUARD = 0xFFFFFFFF   
};

enum ImageFeatureMode {
    IMAQ_COLOR_AND_SHAPE_FEATURES = 0,
    IMAQ_COLOR_FEATURES           = 1,
    IMAQ_SHAPE_FEATURES           = 2,
    IMAQ_FEATURE_MODE_SIZE_GUARD  = 0xFFFFFFFF   
};

enum FontColor {
    IMAQ_WHITE                 = 0,
    IMAQ_BLACK                 = 1,
    IMAQ_INVERT                = 2,
    IMAQ_BLACK_ON_WHITE        = 3,
    IMAQ_WHITE_ON_BLACK        = 4,
    IMAQ_FONT_COLOR_SIZE_GUARD = 0xFFFFFFFF   
};

enum FlipAxis {
    IMAQ_HORIZONTAL_AXIS      = 0,
    IMAQ_VERTICAL_AXIS        = 1,
    IMAQ_CENTER_AXIS          = 2,
    IMAQ_DIAG_L_TO_R_AXIS     = 3,
    IMAQ_DIAG_R_TO_L_AXIS     = 4,
    IMAQ_FLIP_AXIS_SIZE_GUARD = 0xFFFFFFFF   
};

enum EdgeProcess {
    IMAQ_FIRST                   = 0,
    IMAQ_FIRST_AND_LAST          = 1,
    IMAQ_ALL                     = 2,
    IMAQ_BEST                    = 3,
    IMAQ_EDGE_PROCESS_SIZE_GUARD = 0xFFFFFFFF   
};

enum DrawMode {
    IMAQ_DRAW_VALUE           = 0,
    IMAQ_DRAW_INVERT          = 2,
    IMAQ_PAINT_VALUE          = 1,
    IMAQ_PAINT_INVERT         = 3,
    IMAQ_HIGHLIGHT_VALUE      = 4,
    IMAQ_DRAW_MODE_SIZE_GUARD = 0xFFFFFFFF   
};

enum Direction3D {
    IMAQ_3D_NW                   = 0,
    IMAQ_3D_SW                   = 1,
    IMAQ_3D_SE                   = 2,
    IMAQ_3D_NE                   = 3,
    IMAQ_DIRECTION_3D_SIZE_GUARD = 0xFFFFFFFF   
};

enum KernelFamily {
    IMAQ_GRADIENT_FAMILY          = 0,
    IMAQ_LAPLACIAN_FAMILY         = 1,
    IMAQ_SMOOTHING_FAMILY         = 2,
    IMAQ_GAUSSIAN_FAMILY          = 3,
    IMAQ_KERNEL_FAMILY_SIZE_GUARD = 0xFFFFFFFF   
};

enum WindowEventType {
    IMAQ_NO_EVENT                     = 0,
    IMAQ_CLICK_EVENT                  = 1,
    IMAQ_DRAW_EVENT                   = 2,
    IMAQ_MOVE_EVENT                   = 3,
    IMAQ_SIZE_EVENT                   = 4,
    IMAQ_SCROLL_EVENT                 = 5,
    IMAQ_ACTIVATE_EVENT               = 6,
    IMAQ_CLOSE_EVENT                  = 7,
    IMAQ_DOUBLE_CLICK_EVENT           = 8,
    IMAQ_WINDOW_EVENT_TYPE_SIZE_GUARD = 0xFFFFFFFF   
};

enum SearchDirection {
    IMAQ_SEARCH_DIRECTION_LEFT_TO_RIGHT = 0,
    IMAQ_SEARCH_DIRECTION_RIGHT_TO_LEFT = 1,
    IMAQ_SEARCH_DIRECTION_TOP_TO_BOTTOM = 2,
    IMAQ_SEARCH_DIRECTION_BOTTOM_TO_TOP = 3,
    IMAQ_SEARCH_DIRECTION_SIZE_GUARD    = 0xFFFFFFFF   
};

enum WaveletTransformMode {
    IMAQ_WAVELET_TRANSFORM_INTEGER         = 0,
    IMAQ_WAVELET_TRANSFORM_FLOATING_POINT  = 1,
    IMAQ_WAVELET_TRANSFORM_MODE_SIZE_GUARD = 0xFFFFFFFF   
};

enum DataMatrixGradingMode {
    IMAQ_NO_GRADING                          = 0,
    IMAQ_PREPARE_FOR_AIM                     = 1,
    IMAQ_DATA_MATRIX_GRADING_MODE_SIZE_GUARD = 0xFFFFFFFF   
};

enum DataMatrixRotationMode {
    IMAQ_UNLIMITED_ROTATION                   = 0,
    IMAQ_0_DEGREES                            = 1,
    IMAQ_90_DEGREES                           = 2,
    IMAQ_180_DEGREES                          = 3,
    IMAQ_270_DEGREES                          = 4,
    IMAQ_DATA_MATRIX_ROTATION_MODE_SIZE_GUARD = 0xFFFFFFFF   
};

enum DataMatrixMirrorMode {
    IMAQ_AUTO_DETECT_MIRROR                 = -2,
    IMAQ_APPEARS_NORMAL                     = 0,
    IMAQ_APPEARS_MIRRORED                   = 1,
    IMAQ_DATA_MATRIX_MIRROR_MODE_SIZE_GUARD = 0xFFFFFFFF   
};

enum DataMatrixCellSampleSize {
    IMAQ_AUTO_DETECT_CELL_SAMPLE_SIZE            = -2,
    IMAQ_1x1                                     = 1,
    IMAQ_2x2                                     = 2,
    IMAQ_3x3                                     = 3,
    IMAQ_4x4                                     = 4,
    IMAQ_5x5                                     = 5,
    IMAQ_6x6                                     = 6,
    IMAQ_7x7                                     = 7,
    IMAQ_DATA_MATRIX_CELL_SAMPLE_SIZE_SIZE_GUARD = 0xFFFFFFFF   
};

enum DataMatrixCellFilterMode {
    IMAQ_AUTO_DETECT_CELL_FILTER_MODE            = -2,
    IMAQ_AVERAGE_FILTER                          = 0,
    IMAQ_MEDIAN_FILTER                           = 1,
    IMAQ_CENTRAL_AVERAGE_FILTER                  = 2,
    IMAQ_HIGH_AVERAGE_FILTER                     = 3,
    IMAQ_LOW_AVERAGE_FILTER                      = 4,
    IMAQ_VERY_HIGH_AVERAGE_FILTER                = 5,
    IMAQ_VERY_LOW_AVERAGE_FILTER                 = 6,
    IMAQ_ALL_CELL_FILTERS                        = 8,
    IMAQ_DATA_MATRIX_CELL_FILTER_MODE_SIZE_GUARD = 0xFFFFFFFF   
};

enum DataMatrixPolarity {
    IMAQ_AUTO_DETECT_POLARITY            = -2,
    IMAQ_BLACK_DATA_ON_WHITE_BACKGROUND  = 0,
    IMAQ_WHITE_DATA_ON_BLACK_BACKGROUND  = 1,
    IMAQ_DATA_MATRIX_POLARITY_SIZE_GUARD = 0xFFFFFFFF   
};

enum DataMatrixECC {
    IMAQ_AUTO_DETECT_ECC            = -2,
    IMAQ_ECC_000                    = 0,
    IMAQ_ECC_050                    = 50,
    IMAQ_ECC_080                    = 80,
    IMAQ_ECC_100                    = 100,
    IMAQ_ECC_140                    = 140,
    IMAQ_ECC_000_140                = 190,
    IMAQ_ECC_200                    = 200,
    IMAQ_DATA_MATRIX_ECC_SIZE_GUARD = 0xFFFFFFFF   
};

enum DataMatrixDemodulationMode {
    IMAQ_AUTO_DETECT_DEMODULATION_MODE            = -2,
    IMAQ_HISTOGRAM                                = 0,
    IMAQ_LOCAL_CONTRAST                           = 1,
    IMAQ_COMBINED                                 = 2,
    IMAQ_ALL_DEMODULATION_MODES                   = 3,
    IMAQ_DATA_MATRIX_DEMODULATION_MODE_SIZE_GUARD = 0xFFFFFFFF   
};

enum DataMatrixCellFillMode {
    IMAQ_AUTO_DETECT_CELL_FILL_MODE            = -2,
    IMAQ_LOW_FILL                              = 0,
    IMAQ_NORMAL_FILL                           = 1,
    IMAQ_DATA_MATRIX_CELL_FILL_MODE_SIZE_GUARD = 0xFFFFFFFF   
};

enum AIMGrade {
    IMAQ_AIM_GRADE_F                      = 0,
    IMAQ_AIM_GRADE_D                      = 1,
    IMAQ_AIM_GRADE_C                      = 2,
    IMAQ_AIM_GRADE_B                      = 3,
    IMAQ_AIM_GRADE_A                      = 4,
    IMAQ_DATA_MATRIX_AIM_GRADE_SIZE_GUARD = 0xFFFFFFFF   
};

enum EdgePolaritySearchMode {
    IMAQ_SEARCH_FOR_ALL_EDGES          = 0,
    IMAQ_SEARCH_FOR_RISING_EDGES       = 1,
    IMAQ_SEARCH_FOR_FALLING_EDGES      = 2,
    IMAQ_EDGE_POLARITY_MODE_SIZE_GUARD = 0xFFFFFFFF   
};

enum ColumnProcessingMode {
    IMAQ_AVERAGE_COLUMNS                   = 0,
    IMAQ_MEDIAN_COLUMNS                    = 1,
    IMAQ_COLUMN_PROCESSING_MODE_SIZE_GUARD = 0xFFFFFFFF   
};

enum QRDemodulationMode {
    IMAQ_QR_DEMODULATION_MODE_AUTO_DETECT    = -2,
    IMAQ_QR_DEMODULATION_MODE_HISTOGRAM      = 0,
    IMAQ_QR_DEMODULATION_MODE_LOCAL_CONTRAST = 1,
    IMAQ_QR_DEMODULATION_MODE_COMBINED       = 2,
    IMAQ_QR_DEMODULATION_MODE_ALL            = 3,
    IMAQ_QR_DEMODULATION_MODE_SIZE_GUARD     = 0xFFFFFFFF   
};

enum FindTransformMode {
    IMAQ_FIND_REFERENCE                 = 0,
    IMAQ_UPDATE_TRANSFORM               = 1,
    IMAQ_FIND_TRANSFORM_MODE_SIZE_GUARD = 0xFFFFFFFF   
};

enum FindReferenceDirection {
    IMAQ_LEFT_TO_RIGHT_DIRECT          = 0,
    IMAQ_LEFT_TO_RIGHT_INDIRECT        = 1,
    IMAQ_TOP_TO_BOTTOM_DIRECT          = 2,
    IMAQ_TOP_TO_BOTTOM_INDIRECT        = 3,
    IMAQ_RIGHT_TO_LEFT_DIRECT          = 4,
    IMAQ_RIGHT_TO_LEFT_INDIRECT        = 5,
    IMAQ_BOTTOM_TO_TOP_DIRECT          = 6,
    IMAQ_BOTTOM_TO_TOP_INDIRECT        = 7,
    IMAQ_FIND_COORD_SYS_DIR_SIZE_GUARD = 0xFFFFFFFF   
};

enum MulticoreOperation {
    IMAQ_GET_CORES                      = 0,
    IMAQ_SET_CORES                      = 1,
    IMAQ_USE_MAX_AVAILABLE              = 2,
    IMAQ_MULTICORE_OPERATION_SIZE_GUARD = 0xFFFFFFFF   
};

enum GroupBehavior {
    IMAQ_GROUP_CLEAR               = 0,
    IMAQ_GROUP_KEEP                = 1,
    IMAQ_GROUP_TRANSFORM           = 2,
    IMAQ_GROUP_BEHAVIOR_SIZE_GUARD = 0xFFFFFFFF   
};

enum QRDimensions {
    IMAQ_QR_DIMENSIONS_AUTO_DETECT = 0,
    IMAQ_QR_DIMENSIONS_11x11       = 11,
    IMAQ_QR_DIMENSIONS_13x13       = 13,
    IMAQ_QR_DIMENSIONS_15x15       = 15,
    IMAQ_QR_DIMENSIONS_17x17       = 17,
    IMAQ_QR_DIMENSIONS_21x21       = 21,
    IMAQ_QR_DIMENSIONS_25x25       = 25,
    IMAQ_QR_DIMENSIONS_29x29       = 29,
    IMAQ_QR_DIMENSIONS_33x33       = 33,
    IMAQ_QR_DIMENSIONS_37x37       = 37,
    IMAQ_QR_DIMENSIONS_41x41       = 41,
    IMAQ_QR_DIMENSIONS_45x45       = 45,
    IMAQ_QR_DIMENSIONS_49x49       = 49,
    IMAQ_QR_DIMENSIONS_53x53       = 53,
    IMAQ_QR_DIMENSIONS_57x57       = 57,
    IMAQ_QR_DIMENSIONS_61x61       = 61,
    IMAQ_QR_DIMENSIONS_65x65       = 65,
    IMAQ_QR_DIMENSIONS_69x69       = 69,
    IMAQ_QR_DIMENSIONS_73x73       = 73,
    IMAQ_QR_DIMENSIONS_77x77       = 77,
    IMAQ_QR_DIMENSIONS_81x81       = 81,
    IMAQ_QR_DIMENSIONS_85x85       = 85,
    IMAQ_QR_DIMENSIONS_89x89       = 89,
    IMAQ_QR_DIMENSIONS_93x93       = 93,
    IMAQ_QR_DIMENSIONS_97x97       = 97,
    IMAQ_QR_DIMENSIONS_101x101     = 101,
    IMAQ_QR_DIMENSIONS_105x105     = 105,
    IMAQ_QR_DIMENSIONS_109x109     = 109,
    IMAQ_QR_DIMENSIONS_113x113     = 113,
    IMAQ_QR_DIMENSIONS_117x117     = 117,
    IMAQ_QR_DIMENSIONS_121x121     = 121,
    IMAQ_QR_DIMENSIONS_125x125     = 125,
    IMAQ_QR_DIMENSIONS_128x128     = 128,
    IMAQ_QR_DIMENSIONS_133x133     = 133,
    IMAQ_QR_DIMENSIONS_137x137     = 137,
    IMAQ_QR_DIMENSIONS_141x141     = 141,
    IMAQ_QR_DIMENSIONS_145x145     = 145,
    IMAQ_QR_DIMENSIONS_149x149     = 149,
    IMAQ_QR_DIMENSIONS_153x153     = 153,
    IMAQ_QR_DIMENSIONS_157x157     = 157,
    IMAQ_QR_DIMENSIONS_161x161     = 161,
    IMAQ_QR_DIMENSIONS_165x165     = 165,
    IMAQ_QR_DIMENSIONS_169x169     = 169,
    IMAQ_QR_DIMENSIONS_173x173     = 173,
    IMAQ_QR_DIMENSIONS_177x177     = 177,
    IMAQ_QR_DIMENSIONS_SIZE_GUARD  = 0xFFFFFFFF   
};

enum QRModelType {
    IMAQ_QR_MODELTYPE_AUTO_DETECT = 0,
    IMAQ_QR_MODELTYPE_MICRO       = 1,
    IMAQ_QR_MODELTYPE_MODEL1      = 2,
    IMAQ_QR_MODELTYPE_MODEL2      = 3,
    IMAQ_QR_MODEL_TYPE_SIZE_GUARD = 0xFFFFFFFF   
};

enum QRCellSampleSize {
    IMAQ_QR_CELL_SAMPLE_SIZE_AUTO_DETECT = -2,
    IMAQ_QR_CELL_SAMPLE_SIZE1X1          = 1,
    IMAQ_QR_CELL_SAMPLE_SIZE2X2          = 2,
    IMAQ_QR_CELL_SAMPLE_SIZE3X3          = 3,
    IMAQ_QR_CELL_SAMPLE_SIZE4X4          = 4,
    IMAQ_QR_CELL_SAMPLE_SIZE5X5          = 5,
    IMAQ_QR_CELL_SAMPLE_SIZE6X6          = 6,
    IMAQ_QR_CELL_SAMPLE_SIZE7X7          = 7,
    IMAQ_QR_CELL_SAMPLE_TYPE_SIZE_GUARD  = 0xFFFFFFFF   
};

enum QRStreamMode {
    IMAQ_QR_MODE_NUMERIC      = 0,
    IMAQ_QR_MODE_ALPHANUMERIC = 1,
    IMAQ_QR_MODE_RAW_BYTE     = 2,
    IMAQ_QR_MODE_EAN128_TOKEN = 3,
    IMAQ_QR_MODE_EAN128_DATA  = 4,
    IMAQ_QR_MODE_ECI          = 5,
    IMAQ_QR_MODE_KANJI        = 6,
    IMAQ_QR_MODE_SIZE_GUARD   = 0xFFFFFFFF   
};

enum QRMirrorMode {
    IMAQ_QR_MIRROR_MODE_AUTO_DETECT = -2,
    IMAQ_QR_MIRROR_MODE_MIRRORED    = 1,
    IMAQ_QR_MIRROR_MODE_NORMAL      = 0,
    IMAQ_QR_MIRROR_MODE_SIZE_GUARD  = 0xFFFFFFFF   
};

enum QRPolarities {
    IMAQ_QR_POLARITY_AUTO_DETECT     = -2,
    IMAQ_QR_POLARITY_BLACK_ON_WHITE  = 0,
    IMAQ_QR_POLARITY_WHITE_ON_BLACK  = 1,
    IMAQ_QR_POLARITY_MODE_SIZE_GUARD = 0xFFFFFFFF   
};

enum QRRotationMode {
    IMAQ_QR_ROTATION_MODE_UNLIMITED   = 0,
    IMAQ_QR_ROTATION_MODE_0_DEGREES   = 1,
    IMAQ_QR_ROTATION_MODE_90_DEGREES  = 2,
    IMAQ_QR_ROTATION_MODE_180_DEGREES = 3,
    IMAQ_QR_ROTATION_MODE_270_DEGREES = 4,
    IMAQ_QR_ROTATION_MODE_SIZE_GUARD  = 0xFFFFFFFF   
};

enum QRGradingMode {
    IMAQ_QR_NO_GRADING              = 0,
    IMAQ_QR_GRADING_MODE_SIZE_GUARD = 0xFFFFFFFF   
};

enum StraightEdgeSearchMode {
    IMAQ_USE_FIRST_RAKE_EDGES            = 0,
    IMAQ_USE_BEST_RAKE_EDGES             = 1,
    IMAQ_USE_BEST_HOUGH_LINE             = 2,
    IMAQ_USE_FIRST_PROJECTION_EDGE       = 3,
    IMAQ_USE_BEST_PROJECTION_EDGE        = 4,
    IMAQ_STRAIGHT_EDGE_SEARCH_SIZE_GUARD = 0xFFFFFFFF   
};

enum LinearAveragesMode {
    IMAQ_COLUMN_AVERAGES                 = 1,
    IMAQ_ROW_AVERAGES                    = 2,
    IMAQ_RISING_DIAGONAL_AVERAGES        = 4,
    IMAQ_FALLING_DIAGONAL_AVERAGES       = 8,
    IMAQ_ALL_LINEAR_AVERAGES             = 15,
    IMAQ_LINEAR_AVERAGES_MODE_SIZE_GUARD = 0xFFFFFFFF   
};

enum QRCellFilterMode {
    IMAQ_QR_CELL_FILTER_MODE_AUTO_DETECT       = -2,
    IMAQ_QR_CELL_FILTER_MODE_AVERAGE           = 0,
    IMAQ_QR_CELL_FILTER_MODE_MEDIAN            = 1,
    IMAQ_QR_CELL_FILTER_MODE_CENTRAL_AVERAGE   = 2,
    IMAQ_QR_CELL_FILTER_MODE_HIGH_AVERAGE      = 3,
    IMAQ_QR_CELL_FILTER_MODE_LOW_AVERAGE       = 4,
    IMAQ_QR_CELL_FILTER_MODE_VERY_HIGH_AVERAGE = 5,
    IMAQ_QR_CELL_FILTER_MODE_VERY_LOW_AVERAGE  = 6,
    IMAQ_QR_CELL_FILTER_MODE_ALL               = 8,
    IMAQ_QR_CELL_FILTER_MODE_SIZE_GUARD        = 0xFFFFFFFF   
};

enum ParticleClassifierType {
    IMAQ_PARTICLE_LARGEST                    = 0,
    IMAQ_PARTICLE_ALL                        = 1,
    IMAQ_PARTICLE_CLASSIFIER_TYPE_SIZE_GUARD = 0xFFFFFFFF   
};

enum NormalizationMethod {
    IMAQ_NORMALIZATION_NONE               = 0,
    IMAQ_NORMALIZATION_HISTOGRAM_MATCHING = 1,
    IMAQ_NORMALIZATION_AVERAGE_MATCHING   = 2,
    IMAQ_NORMALIZATION_SIZE_GUARD         = 0xFFFFFFFF   
};

enum ParticleType {
    IMAQ_PARTICLE_BRIGHT          = 0,
    IMAQ_PARTICLE_DARK            = 1,
    IMAQ_PARTICLE_TYPE_SIZE_GUARD = 0xFFFFFFFF   
};

enum VisionInfoType2 {
    IMAQ_VISIONINFO_CALIBRATION       = 0x01,
    IMAQ_VISIONINFO_OVERLAY           = 0x02,
    IMAQ_VISIONINFO_GRAYTEMPLATE      = 0x04,
    IMAQ_VISIONINFO_COLORTEMPLATE     = 0x08,
    IMAQ_VISIONINFO_GEOMETRICTEMPLATE = 0x10,
    IMAQ_VISIONINFO_CUSTOMDATA        = 0x20,
    IMAQ_VISIONINFO_GOLDENTEMPLATE    = 0x40,
    IMAQ_VISIONINFO_ALL               = 0xFFFFFFFF,
};

enum ReadClassifierFileMode {
    IMAQ_CLASSIFIER_READ_ALL                   = 0,
    IMAQ_CLASSIFIER_READ_SAMPLES               = 1,
    IMAQ_CLASSIFIER_READ_PROPERTIES            = 2,
    IMAQ_READ_CLASSIFIER_FILE_MODES_SIZE_GUARD = 0xFFFFFFFF   
};

enum WriteClassifierFileMode {
    IMAQ_CLASSIFIER_WRITE_ALL                   = 0,
    IMAQ_CLASSIFIER_WRITE_CLASSIFY_ONLY         = 1,
    IMAQ_WRITE_CLASSIFIER_FILE_MODES_SIZE_GUARD = 0xFFFFFFFF   
};

enum ClassifierEngineType {
    IMAQ_ENGINE_NONE                       = 0,
    IMAQ_ENGINE_NEAREST_NEIGHBOR           = 1,
    IMAQ_CLASSIFIER_ENGINE_TYPE_SIZE_GUARD = 0xFFFFFFFF   
};

enum NearestNeighborMethod {
    IMAQ_MINIMUM_MEAN_DISTANCE              = 0,
    IMAQ_K_NEAREST_NEIGHBOR                 = 1,
    IMAQ_NEAREST_PROTOTYPE                  = 2,
    IMAQ_NEAREST_NEIGHBOR_METHOD_SIZE_GUARD = 0xFFFFFFFF   
};

enum Barcode2DType {
    IMAQ_PDF417                     = 0,
    IMAQ_DATA_MATRIX_ECC_000        = 1,
    IMAQ_DATA_MATRIX_ECC_050        = 2,
    IMAQ_DATA_MATRIX_ECC_080        = 3,
    IMAQ_DATA_MATRIX_ECC_100        = 4,
    IMAQ_DATA_MATRIX_ECC_140        = 5,
    IMAQ_DATA_MATRIX_ECC_200        = 6,
    IMAQ_BARCODE_2D_TYPE_SIZE_GUARD = 0xFFFFFFFF   
};

enum ButtonLabel {
    IMAQ_BUTTON_OK               = 0,
    IMAQ_BUTTON_SAVE             = 1,
    IMAQ_BUTTON_SELECT           = 2,
    IMAQ_BUTTON_LOAD             = 3,
    IMAQ_BUTTON_LABEL_SIZE_GUARD = 0xFFFFFFFF   
};

enum GeometricMatchingMode {
    IMAQ_GEOMETRIC_MATCH_SHIFT_INVARIANT     = 0,
    IMAQ_GEOMETRIC_MATCH_ROTATION_INVARIANT  = 1,
    IMAQ_GEOMETRIC_MATCH_SCALE_INVARIANT     = 2,
    IMAQ_GEOMETRIC_MATCH_OCCLUSION_INVARIANT = 4,
    IMAQ_GEOMETRIC_MATCHING_MODE_SIZE_GUARD  = 0xFFFFFFFF   
};

enum MeasurementType {
    IMAQ_MT_CENTER_OF_MASS_X                    = 0,
    IMAQ_MT_CENTER_OF_MASS_Y                    = 1,
    IMAQ_MT_FIRST_PIXEL_X                       = 2,
    IMAQ_MT_FIRST_PIXEL_Y                       = 3,
    IMAQ_MT_BOUNDING_RECT_LEFT                  = 4,
    IMAQ_MT_BOUNDING_RECT_TOP                   = 5,
    IMAQ_MT_BOUNDING_RECT_RIGHT                 = 6,
    IMAQ_MT_BOUNDING_RECT_BOTTOM                = 7,
    IMAQ_MT_MAX_FERET_DIAMETER_START_X          = 8,
    IMAQ_MT_MAX_FERET_DIAMETER_START_Y          = 9,
    IMAQ_MT_MAX_FERET_DIAMETER_END_X            = 10,
    IMAQ_MT_MAX_FERET_DIAMETER_END_Y            = 11,
    IMAQ_MT_MAX_HORIZ_SEGMENT_LENGTH_LEFT       = 12,
    IMAQ_MT_MAX_HORIZ_SEGMENT_LENGTH_RIGHT      = 13,
    IMAQ_MT_MAX_HORIZ_SEGMENT_LENGTH_ROW        = 14,
    IMAQ_MT_BOUNDING_RECT_WIDTH                 = 16,
    IMAQ_MT_BOUNDING_RECT_HEIGHT                = 17,
    IMAQ_MT_BOUNDING_RECT_DIAGONAL              = 18,
    IMAQ_MT_PERIMETER                           = 19,
    IMAQ_MT_CONVEX_HULL_PERIMETER               = 20,
    IMAQ_MT_HOLES_PERIMETER                     = 21,
    IMAQ_MT_MAX_FERET_DIAMETER                  = 22,
    IMAQ_MT_EQUIVALENT_ELLIPSE_MAJOR_AXIS       = 23,
    IMAQ_MT_EQUIVALENT_ELLIPSE_MINOR_AXIS       = 24,
    IMAQ_MT_EQUIVALENT_ELLIPSE_MINOR_AXIS_FERET = 25,
    IMAQ_MT_EQUIVALENT_RECT_LONG_SIDE           = 26,
    IMAQ_MT_EQUIVALENT_RECT_SHORT_SIDE          = 27,
    IMAQ_MT_EQUIVALENT_RECT_DIAGONAL            = 28,
    IMAQ_MT_EQUIVALENT_RECT_SHORT_SIDE_FERET    = 29,
    IMAQ_MT_AVERAGE_HORIZ_SEGMENT_LENGTH        = 30,
    IMAQ_MT_AVERAGE_VERT_SEGMENT_LENGTH         = 31,
    IMAQ_MT_HYDRAULIC_RADIUS                    = 32,
    IMAQ_MT_WADDEL_DISK_DIAMETER                = 33,
    IMAQ_MT_AREA                                = 35,
    IMAQ_MT_HOLES_AREA                          = 36,
    IMAQ_MT_PARTICLE_AND_HOLES_AREA             = 37,
    IMAQ_MT_CONVEX_HULL_AREA                    = 38,
    IMAQ_MT_IMAGE_AREA                          = 39,
    IMAQ_MT_NUMBER_OF_HOLES                     = 41,
    IMAQ_MT_NUMBER_OF_HORIZ_SEGMENTS            = 42,
    IMAQ_MT_NUMBER_OF_VERT_SEGMENTS             = 43,
    IMAQ_MT_ORIENTATION                         = 45,
    IMAQ_MT_MAX_FERET_DIAMETER_ORIENTATION      = 46,
    IMAQ_MT_AREA_BY_IMAGE_AREA                  = 48,
    IMAQ_MT_AREA_BY_PARTICLE_AND_HOLES_AREA     = 49,
    IMAQ_MT_RATIO_OF_EQUIVALENT_ELLIPSE_AXES    = 50,
    IMAQ_MT_RATIO_OF_EQUIVALENT_RECT_SIDES      = 51,
    IMAQ_MT_ELONGATION_FACTOR                   = 53,
    IMAQ_MT_COMPACTNESS_FACTOR                  = 54,
    IMAQ_MT_HEYWOOD_CIRCULARITY_FACTOR          = 55,
    IMAQ_MT_TYPE_FACTOR                         = 56,
    IMAQ_MT_SUM_X                               = 58,
    IMAQ_MT_SUM_Y                               = 59,
    IMAQ_MT_SUM_XX                              = 60,
    IMAQ_MT_SUM_XY                              = 61,
    IMAQ_MT_SUM_YY                              = 62,
    IMAQ_MT_SUM_XXX                             = 63,
    IMAQ_MT_SUM_XXY                             = 64,
    IMAQ_MT_SUM_XYY                             = 65,
    IMAQ_MT_SUM_YYY                             = 66,
    IMAQ_MT_MOMENT_OF_INERTIA_XX                = 68,
    IMAQ_MT_MOMENT_OF_INERTIA_XY                = 69,
    IMAQ_MT_MOMENT_OF_INERTIA_YY                = 70,
    IMAQ_MT_MOMENT_OF_INERTIA_XXX               = 71,
    IMAQ_MT_MOMENT_OF_INERTIA_XXY               = 72,
    IMAQ_MT_MOMENT_OF_INERTIA_XYY               = 73,
    IMAQ_MT_MOMENT_OF_INERTIA_YYY               = 74,
    IMAQ_MT_NORM_MOMENT_OF_INERTIA_XX           = 75,
    IMAQ_MT_NORM_MOMENT_OF_INERTIA_XY           = 76,
    IMAQ_MT_NORM_MOMENT_OF_INERTIA_YY           = 77,
    IMAQ_MT_NORM_MOMENT_OF_INERTIA_XXX          = 78,
    IMAQ_MT_NORM_MOMENT_OF_INERTIA_XXY          = 79,
    IMAQ_MT_NORM_MOMENT_OF_INERTIA_XYY          = 80,
    IMAQ_MT_NORM_MOMENT_OF_INERTIA_YYY          = 81,
    IMAQ_MT_HU_MOMENT_1                         = 82,
    IMAQ_MT_HU_MOMENT_2                         = 83,
    IMAQ_MT_HU_MOMENT_3                         = 84,
    IMAQ_MT_HU_MOMENT_4                         = 85,
    IMAQ_MT_HU_MOMENT_5                         = 86,
    IMAQ_MT_HU_MOMENT_6                         = 87,
    IMAQ_MT_HU_MOMENT_7                         = 88,
    IMAQ_MEASUREMENT_TYPE_SIZE_GUARD            = 0xFFFFFFFF   
};

enum ReadStrategy {
    IMAQ_READ_AGGRESSIVE          = 0,
    IMAQ_READ_CONSERVATIVE        = 1,
    IMAQ_READ_STRATEGY_SIZE_GUARD = 0xFFFFFFFF   
};

enum ThresholdMode {
    IMAQ_FIXED_RANGE               = 0,
    IMAQ_COMPUTED_UNIFORM          = 1,
    IMAQ_COMPUTED_LINEAR           = 2,
    IMAQ_COMPUTED_NONLINEAR        = 3,
    IMAQ_THRESHOLD_MODE_SIZE_GUARD = 0xFFFFFFFF   
};

enum ReadResolution {
    IMAQ_LOW_RESOLUTION             = 0,
    IMAQ_MEDIUM_RESOLUTION          = 1,
    IMAQ_HIGH_RESOLUTION            = 2,
    IMAQ_READ_RESOLUTION_SIZE_GUARD = 0xFFFFFFFF   
};

enum NearestNeighborMetric {
    IMAQ_METRIC_MAXIMUM                     = 0,
    IMAQ_METRIC_SUM                         = 1,
    IMAQ_METRIC_EUCLIDEAN                   = 2,
    IMAQ_NEAREST_NEIGHBOR_METRIC_SIZE_GUARD = 0xFFFFFFFF   
};

enum ExtractionMode {
    IMAQ_NORMAL_IMAGE               = 0,
    IMAQ_UNIFORM_REGIONS            = 1,
    IMAQ_EXTRACTION_MODE_SIZE_GUARD = 0xFFFFFFFF   
};

enum RoundingMode {
    IMAQ_ROUNDING_MODE_OPTIMIZE   = 0,
    IMAQ_ROUNDING_MODE_TRUNCATE   = 1,
    IMAQ_ROUNDING_MODE_SIZE_GUARD = 0xFFFFFFFF   
};

enum CompressionType {
    IMAQ_COMPRESSION_NONE            = 0,
    IMAQ_COMPRESSION_JPEG            = 1,
    IMAQ_COMPRESSION_PACKED_BINARY   = 2,
    IMAQ_COMPRESSION_TYPE_SIZE_GUARD = 0xFFFFFFFF   
};

enum FlattenType {
    IMAQ_FLATTEN_IMAGE                 = 0,
    IMAQ_FLATTEN_IMAGE_AND_VISION_INFO = 1,
    IMAQ_FLATTEN_TYPE_SIZE_GUARD       = 0xFFFFFFFF   
};

enum LocalThresholdMethod {
    IMAQ_NIBLACK                           = 0,
    IMAQ_BACKGROUND_CORRECTION             = 1,
    IMAQ_LOCAL_THRESHOLD_METHOD_SIZE_GUARD = 0xFFFFFFFF   
};

enum FeatureType {
    IMAQ_NOT_FOUND_FEATURE                   = 0,
    IMAQ_CIRCLE_FEATURE                      = 1,
    IMAQ_ELLIPSE_FEATURE                     = 2,
    IMAQ_CONST_CURVE_FEATURE                 = 3,
    IMAQ_RECTANGLE_FEATURE                   = 4,
    IMAQ_LEG_FEATURE                         = 5,
    IMAQ_CORNER_FEATURE                      = 6,
    IMAQ_PARALLEL_LINE_PAIR_FEATURE          = 7,
    IMAQ_PAIR_OF_PARALLEL_LINE_PAIRS_FEATURE = 8,
    IMAQ_LINE_FEATURE                        = 9,
    IMAQ_CLOSED_CURVE_FEATURE                = 10,
    IMAQ_FEATURE_TYPE_SIZE_GUARD             = 0xFFFFFFFF   
};

enum ClassifierType {
    IMAQ_CLASSIFIER_CUSTOM          = 0,
    IMAQ_CLASSIFIER_PARTICLE        = 1,
    IMAQ_CLASSIFIER_TYPE_SIZE_GUARD = 0xFFFFFFFF   
};

enum WindowBackgroundFillStyle {
    IMAQ_FILL_STYLE_SOLID      = 0,
    IMAQ_FILL_STYLE_HATCH      = 2,
    IMAQ_FILL_STYLE_DEFAULT    = 3,
    IMAQ_FILL_STYLE_SIZE_GUARD = 0xFFFFFFFF   
};

enum RegistrationMethod {
    IMAQ_REGISTRATION_NONE        = 0,
    IMAQ_REGISTRATION_PERSPECTIVE = 1,
    IMAQ_REGISTRATION_SIZE_GUARD  = 0xFFFFFFFF   
};

enum EdgeFilterSize {
    IMAQ_FINE                        = 0,
    IMAQ_NORMAL                      = 1,
    IMAQ_EDGE_FILTER_SIZE_SIZE_GUARD = 0xFFFFFFFF   
};

enum Barcode2DSearchMode {
    IMAQ_SEARCH_MULTIPLE                   = 0,
    IMAQ_SEARCH_SINGLE_CONSERVATIVE        = 1,
    IMAQ_SEARCH_SINGLE_AGGRESSIVE          = 2,
    IMAQ_BARCODE_2D_SEARCH_MODE_SIZE_GUARD = 0xFFFFFFFF   
};

enum DataMatrixSubtype {
    IMAQ_ALL_DATA_MATRIX_SUBTYPES             = 0,
    IMAQ_DATA_MATRIX_SUBTYPES_ECC_000_ECC_140 = 1,
    IMAQ_DATA_MATRIX_SUBTYPE_ECC_200          = 2,
    IMAQ_DATA_MATRIX_SUBTYPE_SIZE_GUARD       = 0xFFFFFFFF   
};

enum Barcode2DShape {
    IMAQ_SQUARE_BARCODE_2D           = 0,
    IMAQ_RECTANGULAR_BARCODE_2D      = 1,
    IMAQ_BARCODE_2D_SHAPE_SIZE_GUARD = 0xFFFFFFFF   
};

enum Barcode2DCellShape {
    IMAQ_SQUARE_CELLS                     = 0,
    IMAQ_ROUND_CELLS                      = 1,
    IMAQ_BARCODE_2D_CELL_SHAPE_SIZE_GUARD = 0xFFFFFFFF   
};

enum Barcode2DContrast {
    IMAQ_ALL_BARCODE_2D_CONTRASTS       = 0,
    IMAQ_BLACK_ON_WHITE_BARCODE_2D      = 1,
    IMAQ_WHITE_ON_BLACK_BARCODE_2D      = 2,
    IMAQ_BARCODE_2D_CONTRAST_SIZE_GUARD = 0xFFFFFFFF   
};

enum WindowBackgroundHatchStyle {
    IMAQ_HATCH_STYLE_HORIZONTAL        = 0,
    IMAQ_HATCH_STYLE_VERTICAL          = 1,
    IMAQ_HATCH_STYLE_FORWARD_DIAGONAL  = 2,
    IMAQ_HATCH_STYLE_BACKWARD_DIAGONAL = 3,
    IMAQ_HATCH_STYLE_CROSS             = 4,
    IMAQ_HATCH_STYLE_CROSS_HATCH       = 5,
    IMAQ_HATCH_STYLE_SIZE_GUARD        = 0xFFFFFFFF   
};


//============================================================================
//  Forward Declare Data Structures
//============================================================================
typedef struct CharSet_struct CharSet;
typedef struct ClassifierSession_struct ClassifierSession;
//typedef struct Image_struct Image;
typedef struct MultipleGeometicPattern_struct MultipleGeometricPattern;
typedef struct Overlay_struct Overlay;
typedef struct ROI_struct ROI;

struct Image {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    Image(ImageType type, int borderSize);
    %MethodCode
        Py_BEGIN_ALLOW_THREADS
        sipCpp = imaqCreateImage(a0, a1);
        Py_END_ALLOW_THREADS
    %End
    Image(const Image& image);
    %MethodCode
        Py_BEGIN_ALLOW_THREADS
        ImageType type;
        int borderSize;
        imaqGetImageType(a0, &type);
        imaqGetBorderSize(a0, &borderSize);
        sipCpp = imaqCreateImage(type, borderSize);
        imaqDuplicate(sipCpp, a0);
        Py_END_ALLOW_THREADS
    %End
    ~Image();
    %MethodCode
        Py_BEGIN_ALLOW_THREADS
        imaqDispose(sipCpp); sipCppV = 0;
        Py_END_ALLOW_THREADS
    %End
};

typedef int ContourID;
typedef unsigned long SESSION_ID;
typedef int	AVISession;
typedef char* FilterName;

%ModuleCode
typedef const void* Kernel;
%End
typedef const void* Kernel;

/*
//typedef char String255[256];
%MappedType String255
{
%TypeHeaderCode
#include <WPIlib/nivision.h>
%End

%ConvertFromTypeCode
    size_t len = 0;
    while (len < 256 && (*sipCpp)[len] != '\0')
        ++len;
    return PyUnicode_FromStringAndSize(*sipCpp, len);
%End

%ConvertToTypeCode
    // Allow a Python string (or a unicode string) whenever a string is
    // expected.
    // If argument is a Unicode string, just decode it to UTF-8
    // If argument is a Python string, assume it's UTF-8
    if (sipIsErr == NULL)
        return PyUnicode_Check(sipPy);
    if (sipPy == Py_None) {
        sipCppPtr[0] = '\0';
        return 1;
    }
    if (PyUnicode_Check(sipPy)) {
        PyObject* s = PyUnicode_AsEncodedString(sipPy, "UTF-8", "");
        strncpy(*sipCppPtr, PyBytes_AS_STRING(s), 256);
        Py_DECREF(s);
        return 1;
    }
    return 0;
%End
};
*/

//============================================================================
// Data Structures
//============================================================================

struct ParticleFilterOptions2 {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    int rejectMatches;
    int rejectBorder;
    int fillHoles;
    int connectivity8;
};

struct RGBValue {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    unsigned char B;
    unsigned char G;
    unsigned char R;
    unsigned char alpha;
};

struct EdgeOptions2 {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    EdgePolaritySearchMode polarity;
    int                    kernelSize;
    int                    width;
    float                  minThreshold;
    InterpolationMethod    interpolationType;
    ColumnProcessingMode   columnProcessingMode;
};

struct FindEdgeOptions2 {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    RakeDirection direction;
    int           showSearchArea;
    int           showSearchLines;
    int           showEdgesFound;
    int           showResult;
    RGBValue      searchAreaColor;
    RGBValue      searchLinesColor;
    RGBValue      searchEdgesColor;
    RGBValue      resultColor;
    char*         overlayGroupName;
    EdgeOptions2  edgeOptions;
};
/*
struct FindEdgeReport {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    StraightEdge* straightEdges;
    unsigned int  numStraightEdges;
};

struct FindTransformRectOptions2 {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    FindReferenceDirection direction;
    int                    showSearchArea;
    int                    showSearchLines;
    int                    showEdgesFound;
    int                    showResult;
    RGBValue               searchAreaColor;
    RGBValue               searchLinesColor;
    RGBValue               searchEdgesColor;
    RGBValue               resultColor;
    char*                  overlayGroupName;
    EdgeOptions2           edgeOptions;
};

struct FindTransformRectsOptions2 {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    FindReferenceDirection direction;
    int                    showSearchArea;
    int                    showSearchLines;
    int                    showEdgesFound;
    int                    showResult;
    RGBValue               searchAreaColor;
    RGBValue               searchLinesColor;
    RGBValue               searchEdgesColor;
    RGBValue               resultColor;
    char*                  overlayGroupName;
    EdgeOptions2           primaryEdgeOptions;
    EdgeOptions2           secondaryEdgeOptions;
};

struct ReadTextReport3 {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    const char*  readString;
    CharReport3* characterReport;
    int          numCharacterReports;
    ROI*         roiBoundingCharacters;
};

struct CharacterStatistics {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    int left;
    int top;
    int width;
    int height;
    int characterSize;
};

struct CharReport3 {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    const char*         character;
    int                 classificationScore;
    int                 verificationScore;
    int                 verified;
    int                 lowThreshold;
    int                 highThreshold;
    CharacterStatistics characterStats;
};
*/
struct PointFloat {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    float x;
    float y;
};
/*
struct ArcInfo2 {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    PointFloat center;
    double     radius;
    double     startAngle;
    double     endAngle;
};

struct EdgeReport2 {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    EdgeInfo*    edges;
    unsigned int numEdges;
    //TODO double*      gradientInfo;
    unsigned int numGradientInfo;
    int          calibrationValid;
};

struct SearchArcInfo {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    ArcInfo2    arcCoordinates;
    EdgeReport2 edgeReport;
};

struct ConcentricRakeReport2 {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    EdgeInfo*      firstEdges;
    unsigned int   numFirstEdges;
    EdgeInfo*      lastEdges;
    unsigned int   numLastEdges;
    SearchArcInfo* searchArcs;
    unsigned int   numSearchArcs;
};

struct SpokeReport2 {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    EdgeInfo*       firstEdges;
    unsigned int    numFirstEdges;
    EdgeInfo*       lastEdges;
    unsigned int    numLastEdges;
    SearchLineInfo* searchLines;
    unsigned int    numSearchLines;
};

struct EdgeInfo {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    PointFloat position;
    PointFloat calibratedPosition;
    double     distance;
    double     calibratedDistance;
    double     magnitude;
    double     noisePeak;
    int        rising;
};

struct LineFloat {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    PointFloat start;
    PointFloat end;
};

struct SearchLineInfo {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    LineFloat   lineCoordinates;
    EdgeReport2 edgeReport;
};

struct RakeReport2 {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    EdgeInfo*       firstEdges;
    unsigned int    numFirstEdges;
    EdgeInfo*       lastEdges;
    unsigned int    numLastEdges;
    SearchLineInfo* searchLines;
    unsigned int    numSearchLines;
};

struct TransformBehaviors {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    GroupBehavior ShiftBehavior;
    GroupBehavior ScaleBehavior;
    GroupBehavior RotateBehavior;
    GroupBehavior SymmetryBehavior;
};

struct QRCodeDataToken {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    QRStreamMode   mode;
    unsigned int   modeData;
    unsigned char* data;
    unsigned int   dataLength;
};
*/
struct ParticleFilterOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    int rejectMatches;
    int rejectBorder;
    int connectivity8;
};
/*
struct StraightEdgeReport2 {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    StraightEdge*   straightEdges;
    unsigned int    numStraightEdges;
    SearchLineInfo* searchLines;
    unsigned int    numSearchLines;
};

struct StraightEdgeOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    unsigned int           numLines;
    StraightEdgeSearchMode searchMode;
    double                 minScore;
    double                 maxScore;
    double                 orientation;
    double                 angleRange;
    double                 angleTolerance;
    unsigned int           stepSize;
    double                 minSignalToNoiseRatio;
    double                 minCoverage;
    unsigned int           houghIterations;
};

struct StraightEdge {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    LineFloat    straightEdgeCoordinates;
    LineFloat    calibratedStraightEdgeCoordinates;
    double       angle;
    double       calibratedAngle;
    double       score;
    double       straightness;
    double       averageSignalToNoiseRatio;
    int          calibrationValid;
    EdgeInfo*    usedEdges;
    unsigned int numUsedEdges;
};

struct QRCodeSearchOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    QRRotationMode     rotationMode;
    unsigned int       skipLocation;
    unsigned int       edgeThreshold;
    QRDemodulationMode demodulationMode;
    QRCellSampleSize   cellSampleSize;
    QRCellFilterMode   cellFilterMode;
    unsigned int       skewDegreesAllowed;
};

struct QRCodeSizeOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    unsigned int minSize;
    unsigned int maxSize;
};

struct QRCodeDescriptionOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    QRDimensions dimensions;
    QRPolarities polarity;
    QRMirrorMode mirror;
    QRModelType  modelType;
};

struct QRCodeReport {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    unsigned int       found;
    unsigned char*     data;
    unsigned int       dataLength;
    //TODO: PointFloat         boundingBox[4];
    QRCodeDataToken*   tokenizedData;
    unsigned int       sizeOfTokenizedData;
    unsigned int       numErrorsCorrected;
    unsigned int       dimensions;
    unsigned int       version;
    QRModelType        modelType;
    QRStreamMode       streamMode;
    QRPolarities       matrixPolarity;
    unsigned int       mirrored;
    unsigned int       positionInAppendStream;
    unsigned int       sizeOfAppendStream;
    int                firstEAN128ApplicationID;
    int                firstECIDesignator;
    unsigned int       appendStreamIdentifier;
    unsigned int       minimumEdgeStrength;
    QRDemodulationMode demodulationMode;
    QRCellSampleSize   cellSampleSize;
    QRCellFilterMode   cellFilterMode;
};

struct AIMGradeReport {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    AIMGrade overallGrade;
    AIMGrade decodingGrade;
    AIMGrade symbolContrastGrade;
    float    symbolContrast;
    AIMGrade printGrowthGrade;
    float    printGrowth;
    AIMGrade axialNonuniformityGrade;
    float    axialNonuniformity;
    AIMGrade unusedErrorCorrectionGrade;
    float    unusedErrorCorrection;
};

struct DataMatrixSizeOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    unsigned int minSize;
    unsigned int maxSize;
    unsigned int quietZoneWidth;
};

struct DataMatrixDescriptionOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    float                  aspectRatio;
    unsigned int           rows;
    unsigned int           columns;
    int                    rectangle;
    DataMatrixECC          ecc;
    DataMatrixPolarity     polarity;
    DataMatrixCellFillMode cellFill;
    float                  minBorderIntegrity;
    DataMatrixMirrorMode   mirrorMode;
};

struct DataMatrixSearchOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    DataMatrixRotationMode     rotationMode;
    int                        skipLocation;
    unsigned int               edgeThreshold;
    DataMatrixDemodulationMode demodulationMode;
    DataMatrixCellSampleSize   cellSampleSize;
    DataMatrixCellFilterMode   cellFilterMode;
    unsigned int               skewDegreesAllowed;
    unsigned int               maxIterations;
    unsigned int               initialSearchVectorWidth;
};

struct DataMatrixReport {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    int                        found;
    int                        binary;
    unsigned char*             data;
    unsigned int               dataLength;
    //TODO: PointFloat                 boundingBox[4];
    unsigned int               numErrorsCorrected;
    unsigned int               numErasuresCorrected;
    float                      aspectRatio;
    unsigned int               rows;
    unsigned int               columns;
    DataMatrixECC              ecc;
    DataMatrixPolarity         polarity;
    DataMatrixCellFillMode     cellFill;
    float                      borderIntegrity;
    int                        mirrored;
    unsigned int               minimumEdgeStrength;
    DataMatrixDemodulationMode demodulationMode;
    DataMatrixCellSampleSize   cellSampleSize;
    DataMatrixCellFilterMode   cellFilterMode;
    unsigned int               iterations;
};

struct JPEG2000FileAdvancedOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    WaveletTransformMode waveletMode;
    int                  useMultiComponentTransform;
    unsigned int         maxWaveletTransformLevel;
    float                quantizationStepSize;
};

struct MatchGeometricPatternAdvancedOptions2 {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    int    minFeaturesUsed;
    int    maxFeaturesUsed;
    int    subpixelIterations;
    double subpixelTolerance;
    int    initialMatchListLength;
    float  matchTemplateCurveScore;
    int    correlationScore;
    double minMatchSeparationDistance;
    double minMatchSeparationAngle;
    double minMatchSeparationScale;
    double maxMatchOverlap;
    int    coarseResult;
    int    smoothContours;
    int    enableCalibrationSupport;
};

struct InspectionAlignment {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    PointFloat position;
    float      rotation;
    float      scale;
};

struct InspectionOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    RegistrationMethod  registrationMethod;
    NormalizationMethod normalizationMethod;
    int                 edgeThicknessToIgnore;
    float               brightThreshold;
    float               darkThreshold;
    int                 binary;
};

struct CharReport2 {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    const char* character;
    //TODO: PointFloat  corner[4];
    int         lowThreshold;
    int         highThreshold;
    int         classificationScore;
    int         verificationScore;
    int         verified;
};

struct CharInfo2 {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    const char*  charValue;
    const Image* charImage;
    const Image* internalImage;
    int          isReferenceChar;
};

struct ReadTextReport2 {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    const char*  readString;
    CharReport2* characterReport;
    int          numCharacterReports;
};

struct EllipseFeature {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    PointFloat position;
    double     rotation;
    double     minorRadius;
    double     majorRadius;
};

struct CircleFeature {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    PointFloat position;
    double     radius;
};

struct ConstCurveFeature {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    PointFloat position;
    double     radius;
    double     startAngle;
    double     endAngle;
};

struct RectangleFeature {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    PointFloat position;
    //TODO: PointFloat corner[4];
    double     rotation;
    double     width;
    double     height;
};

struct LegFeature {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    PointFloat position;
    //TODO: PointFloat corner[4];
    double     rotation;
    double     width;
    double     height;
};

struct CornerFeature {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    PointFloat position;
    double     rotation;
    double     enclosedAngle;
    int        isVirtual;
};

struct LineFeature {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    PointFloat startPoint;
    PointFloat endPoint;
    double     length;
    double     rotation;
};

struct ParallelLinePairFeature {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    PointFloat firstStartPoint;
    PointFloat firstEndPoint;
    PointFloat secondStartPoint;
    PointFloat secondEndPoint;
    double     rotation;
    double     distance;
};

struct PairOfParallelLinePairsFeature {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    ParallelLinePairFeature firstParallelLinePair;
    ParallelLinePairFeature secondParallelLinePair;
    double                  rotation;
    double                  distance;
};

// TODO
//typedef union GeometricFeature_union {
//    CircleFeature*                  circle;
//    EllipseFeature*                 ellipse;
//    ConstCurveFeature*              constCurve;
//    RectangleFeature*               rectangle;
//    LegFeature*                     leg;
//    CornerFeature*                  corner;
//    ParallelLinePairFeature*        parallelLinePair;
//    PairOfParallelLinePairsFeature* pairOfParallelLinePairs;
//    LineFeature*                    line;
//    ClosedCurveFeature*             closedCurve;
//};

struct FeatureData {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    FeatureType      type;
    PointFloat*      contourPoints;
    int              numContourPoints;
    //TODO GeometricFeature feature;
};

struct GeometricPatternMatch2 {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    PointFloat   position;
    float        rotation;
    float        scale;
    float        score;
    //TODO PointFloat   corner[4];
    int          inverse;
    float        occlusion;
    float        templateMatchCurveScore;
    float        matchTemplateCurveScore;
    float        correlationScore;
    String255    label;
    //TODO FeatureData* featureData;
    int          numFeatureData;
    PointFloat   calibratedPosition;
    float        calibratedRotation;
    //TODO PointFloat   calibratedCorner[4];
};

struct ClosedCurveFeature {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    PointFloat position;
    double     arcLength;
};

struct LineMatch {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    PointFloat startPoint;
    PointFloat endPoint;
    double     length;
    double     rotation;
    double     score;
};

struct LineDescriptor {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    double minLength;
    double maxLength;
};

struct RectangleDescriptor {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    double minWidth;
    double maxWidth;
    double minHeight;
    double maxHeight;
};

struct RectangleMatch {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    //TODO PointFloat corner[4];
    double     rotation;
    double     width;
    double     height;
    double     score;
};
*/
struct EllipseDescriptor {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    double minMajorRadius;
    double maxMajorRadius;
    double minMinorRadius;
    double maxMinorRadius;
};

struct EllipseMatch {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    PointFloat position;
    double     rotation;
    double     majorRadius;
    double     minorRadius;
    double     score;
};

struct CircleMatch {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    PointFloat position;
    double     radius;
    double     score;
};

struct CircleDescriptor {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    double minRadius;
    double maxRadius;
};

struct RangeFloat {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    float minValue;
    float maxValue;
};

struct ShapeDetectionOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    unsigned int mode;
    //TODO:RangeFloat*  angleRanges;
    int          numAngleRanges;
    RangeFloat   scaleRange;
    double       minMatchScore;
};

struct Curve {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    //TODO:PointFloat*  points;
    unsigned int numPoints;
    int          closed;
    double       curveLength;
    double       minEdgeStrength;
    double       maxEdgeStrength;
    double       averageEdgeStrength;
};

struct CurveOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    ExtractionMode extractionMode;
    int            threshold;
    EdgeFilterSize filterSize;
    int            minLength;
    int            rowStepSize;
    int            columnStepSize;
    int            maxEndPointGap;
    int            onlyClosed;
    int            subpixelAccuracy;
};
/*
struct Barcode2DInfo {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    Barcode2DType  type;
    int            binary;
    unsigned char* data;
    unsigned int   dataLength;
    //TODO PointFloat     boundingBox[4];
    unsigned int   numErrorsCorrected;
    unsigned int   numErasuresCorrected;
    unsigned int   rows;
    unsigned int   columns;
};

struct DataMatrixOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    Barcode2DSearchMode searchMode;
    Barcode2DContrast   contrast;
    Barcode2DCellShape  cellShape;
    Barcode2DShape      barcodeShape;
    DataMatrixSubtype   subtype;
};

struct ClassifierAccuracyReport {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    int     size;
    float   accuracy;
    //TODO char**  classNames;
    //TODO double* classAccuracy;
    //TODO double* classPredictiveValue;
    //TODO int**   classificationDistribution;
};

struct NearestNeighborClassResult {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    char* className;
    float standardDeviation;
    int   count;
};

struct NearestNeighborTrainingReport {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    //TODO float**                     classDistancesTable;
    //TODO NearestNeighborClassResult* allScores;
    int                         allScoresSize;
};

struct ParticleClassifierPreprocessingOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    int             manualThreshold;
    RangeFloat      manualThresholdRange;
    ThresholdMethod autoThresholdMethod;
    RangeFloat      limits;
    ParticleType    particleType;
    int             rejectBorder;
    int             numErosions;
};

struct ClassifierSampleInfo {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    char*   className;
    //TODO double* featureVector;
    int     featureVectorSize;
    Image*  thumbnail;
};

struct ClassScore {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    char* className;
    float distance;
};

struct ClassifierReport {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    char*       bestClassName;
    float       classificationScore;
    float       identificationScore;
    ClassScore* allScores;
    int         allScoresSize;
};

struct NearestNeighborOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    NearestNeighborMethod method;
    NearestNeighborMetric metric;
    int                   k;
};

struct ParticleClassifierOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    float scaleDependence;
    float mirrorDependence;
};

struct RGBU64Value {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    unsigned short B;
    unsigned short G;
    unsigned short R;
    unsigned short alpha;
};

struct GeometricPatternMatch {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    PointFloat position;
    float      rotation;
    float      scale;
    float      score;
    //TODO PointFloat corner[4];
    int        inverse;
    float      occlusion;
    float      templateMatchCurveScore;
    float      matchTemplateCurveScore;
    float      correlationScore;
};

struct MatchGeometricPatternAdvancedOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    int    minFeaturesUsed;
    int    maxFeaturesUsed;
    int    subpixelIterations;
    double subpixelTolerance;
    int    initialMatchListLength;
    int    matchTemplateCurveScore;
    int    correlationScore;
    double minMatchSeparationDistance;
    double minMatchSeparationAngle;
    double minMatchSeparationScale;
    double maxMatchOverlap;
    int    coarseResult;
};

struct MatchGeometricPatternOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    unsigned int mode;
    int          subpixelAccuracy;
    RangeFloat*  angleRanges;
    int          numAngleRanges;
    RangeFloat   scaleRange;
    RangeFloat   occlusionRange;
    int          numMatchesRequested;
    float        minMatchScore;
};

struct LearnGeometricPatternAdvancedOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    int    minRectLength;
    double minRectAspectRatio;
    int    minRadius;
    int    minLineLength;
    double minFeatureStrength;
    int    maxFeaturesUsed;
    int    maxPixelDistanceFromLine;
};

struct FitEllipseOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    int    rejectOutliers;
    double minScore;
    double pixelRadius;
    int    maxIterations;
};

struct FitCircleOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    int    rejectOutliers;
    double minScore;
    double pixelRadius;
    int    maxIterations;
};

struct ConstructROIOptions2 {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    int          windowNumber;
    const char*  windowTitle;
    PaletteType  type;
    RGBValue*    palette;
    int          numColors;
    unsigned int maxContours;
};
*/
struct HSLValue {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    unsigned char L;
    unsigned char S;
    unsigned char H;
    unsigned char alpha;
};

struct HSVValue {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    unsigned char V;
    unsigned char S;
    unsigned char H;
    unsigned char alpha;
};

struct HSIValue {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    unsigned char I;
    unsigned char S;
    unsigned char H;
    unsigned char alpha;
};

struct CIELabValue {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    double        b;
    double        a;
    double        L;
    unsigned char alpha;
};

struct CIEXYZValue {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    double        Z;
    double        Y;
    double        X;
    unsigned char alpha;
};
/*
// TODO
//typedef union Color2_union {
//    RGBValue    rgb;
//    HSLValue    hsl;
//    HSVValue    hsv;
//    HSIValue    hsi;
//    CIELabValue cieLab;
//    CIEXYZValue cieXYZ;
//    int         rawValue;
//};
typedef RGBValue Color2;

struct BestEllipse2 {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    PointFloat center;
    PointFloat majorAxisStart;
    PointFloat majorAxisEnd;
    PointFloat minorAxisStart;
    PointFloat minorAxisEnd;
    double     area;
    double     perimeter;
    double     error;
    int        valid;
    //TODO int*       pointsUsed;
    int        numPointsUsed;
};

struct LearnPatternAdvancedOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    LearnPatternAdvancedShiftOptions*    shiftOptions;
    LearnPatternAdvancedRotationOptions* rotationOptions;
};

struct AVIInfo {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    unsigned int width;
    unsigned int height;
    ImageType    imageType;
    unsigned int numFrames;
    unsigned int framesPerSecond;
    char*        filterName;
    int          hasData;
    unsigned int maxDataSize;
};

struct LearnPatternAdvancedShiftOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    int    initialStepSize;
    int    initialSampleSize;
    double initialSampleSizeFactor;
    int    finalSampleSize;
    double finalSampleSizeFactor;
    int    subpixelSampleSize;
    double subpixelSampleSizeFactor;
};

struct LearnPatternAdvancedRotationOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    SearchStrategy searchStrategySupport;
    int            initialStepSize;
    int            initialSampleSize;
    double         initialSampleSizeFactor;
    int            initialAngularAccuracy;
    int            finalSampleSize;
    double         finalSampleSizeFactor;
    int            finalAngularAccuracy;
    int            subpixelSampleSize;
    double         subpixelSampleSizeFactor;
};

struct MatchPatternAdvancedOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    int            subpixelIterations;
    double         subpixelTolerance;
    int            initialMatchListLength;
    int            matchListReductionFactor;
    int            initialStepSize;
    SearchStrategy searchStrategy;
    int            intermediateAngularAccuracy;
};
*/
struct ParticleFilterCriteria2 {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    MeasurementType parameter;
    float           lower;
    float           upper;
    int             calibrated;
    int             exclude;
};

struct BestCircle2 {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    PointFloat center;
    double     radius;
    double     area;
    double     perimeter;
    double     error;
    int        valid;
    //TODO int*       pointsUsed;
    int        numPointsUsed;
};

struct OCRSpacingOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    int minCharSpacing;
    int minCharSize;
    int maxCharSize;
    int maxHorizontalElementSpacing;
    int maxVerticalElementSpacing;
    int minBoundingRectWidth;
    int maxBoundingRectWidth;
    int minBoundingRectHeight;
    int maxBoundingRectHeight;
    int autoSplit;
};

struct OCRProcessingOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    ThresholdMode mode;
    int           lowThreshold;
    int           highThreshold;
    int           blockCount;
    int           fastThreshold;
    int           biModalCalculation;
    int           darkCharacters;
    int           removeParticlesTouchingROI;
    int           erosionCount;
};

struct ReadTextOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    //TODO String255      validChars[255];
    int            numValidChars;
    char           substitutionChar;
    ReadStrategy   readStrategy;
    int            acceptanceLevel;
    int            aspectRatio;
    ReadResolution readResolution;
};
/*
struct CharInfo {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    const char*  charValue;
    const Image* charImage;
    const Image* internalImage;
};
*/
struct Rect {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    int top;
    int left;
    int height;
    int width;
};
/*
struct CharReport {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    const char* character;
    //TODO PointFloat  corner[4];
    int         reserved;
    int         lowThreshold;
    int         highThreshold;
};

struct ReadTextReport {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    const char*       readString;
    const CharReport* characterReport;
    int               numCharacterReports;
};
*/
struct Point {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    int x;
    int y;
};

struct Annulus {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    Point  center;
    int    innerRadius;
    int    outerRadius;
    double startAngle;
    double endAngle;
};
/*
struct EdgeLocationReport {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    PointFloat* edges;
    int         numEdges;
};

struct EdgeOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    unsigned            threshold;
    unsigned            width;
    unsigned            steepness;
    InterpolationMethod subpixelType;
    unsigned            subpixelDivisions;
};

struct EdgeReport {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    float        location;
    float        contrast;
    PolarityType polarity;
    float        reserved;
    PointFloat   coordinate;
};

struct ExtremeReport {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    double location;
    double amplitude;
    double secondDerivative;
};

struct FitLineOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    float minScore;
    float pixelRadius;
    int   numRefinements;
};

struct GridDescriptor {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    float           xStep;
    float           yStep;
    CalibrationUnit unit;
};

struct DisplayMapping {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    MappingMethod method;
    int           minimumValue;
    int           maximumValue;
    int           shiftCount;
};

struct DetectExtremesOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    double threshold;
    int    width;
};

struct ImageInfo {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    CalibrationUnit imageUnit;
    float           stepX;
    float           stepY;
    ImageType       imageType;
    int             xRes;
    int             yRes;
    int             xOffset;
    int             yOffset;
    int             border;
    int             pixelsPerLine;
    void*           reserved0;
    void*           reserved1;
    void*           imageStart;
};

struct LCDOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    int   litSegments;
    float threshold;
    int   sign;
    int   decimalPoint;
};

struct LCDReport {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    const char*  text;
    LCDSegments* segmentInfo;
    int          numCharacters;
    int          reserved;
};

struct LCDSegments {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    unsigned a;
    unsigned b;
    unsigned c;
    unsigned d;
    unsigned e;
    unsigned f;
    unsigned g;
};

struct LearnCalibrationOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    CalibrationMode mode;
    ScalingMethod   method;
    CalibrationROI  roi;
    int             learnMap;
    int             learnTable;
};

struct LearnColorPatternOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    LearningMode      learnMode;
    ImageFeatureMode  featureMode;
    int               threshold;
    ColorIgnoreMode   ignoreMode;
    ColorInformation* colorsToIgnore;
    int               numColorsToIgnore;
};
*/
struct Line {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    Point start;
    Point end;
};
/*
struct LinearAverages {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    //TODO float* columnAverages;
    int    columnCount;
    //TODO float* rowAverages;
    int    rowCount;
    //TODO float* risingDiagAverages;
    int    risingDiagCount;
    //TODO float* fallingDiagAverages;
    int    fallingDiagCount;
};
*/
struct LineEquation {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    double a;
    double b;
    double c;
};

struct LineProfile {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    //TODO float* profileData;
    Rect   boundingBox;
    float  min;
    float  max;
    float  mean;
    float  stdDev;
    int    dataCount;
};

struct MatchColorPatternOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    MatchingMode        matchMode;
    ImageFeatureMode    featureMode;
    int                 minContrast;
    int                 subpixelAccuracy;
    //TODO RotationAngleRange* angleRanges;
    int                 numRanges;
    double              colorWeight;
    ColorSensitivity    sensitivity;
    SearchStrategy      strategy;
    int                 numMatchesRequested;
    float               minMatchScore;
};

struct HistogramReport {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    //TODO int*  histogram;
    int   histogramCount;
    float min;
    float max;
    float start;
    float width;
    float mean;
    float stdDev;
    int   numPixels;
};

struct ArcInfo {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    Rect   boundingBox;
    double startAngle;
    double endAngle;
};

struct AxisReport {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    PointFloat origin;
    PointFloat mainAxisEnd;
    PointFloat secondaryAxisEnd;
};

struct BarcodeInfo {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    const char* outputString;
    int         size;
    char        outputChar1;
    char        outputChar2;
    double      confidenceLevel;
    BarcodeType type;
};

struct BCGOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    float brightness;
    float contrast;
    float gamma;
};

struct BestCircle {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    PointFloat center;
    double     radius;
    double     area;
    double     perimeter;
    double     error;
};

struct BestEllipse {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    PointFloat center;
    PointFloat majorAxisStart;
    PointFloat majorAxisEnd;
    PointFloat minorAxisStart;
    PointFloat minorAxisEnd;
    double     area;
    double     perimeter;
};

struct BestLine {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    PointFloat   start;
    PointFloat   end;
    LineEquation equation;
    int          valid;
    double       error;
    //TODO int*         pointsUsed;
    int          numPointsUsed;
};

struct BrowserOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    int               width;
    int               height;
    int               imagesPerLine;
    RGBValue          backgroundColor;
    int               frameSize;
    BrowserFrameStyle style;
    float             ratio;
    RGBValue          focusColor;
};

struct CoordinateSystem {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    PointFloat      origin;
    float           angle;
    AxisOrientation axisOrientation;
};
/*
struct CalibrationInfo {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    //TODO float*                  errorMap;
    int                     mapColumns;
    int                     mapRows;
    ROI*                    userRoi;
    ROI*                    calibrationRoi;
    LearnCalibrationOptions options;
    GridDescriptor          grid;
    CoordinateSystem        system;
    RangeFloat              range;
    float                   quality;
};

struct CalibrationPoints {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    PointFloat* pixelCoordinates;
    PointFloat* realWorldCoordinates;
    int         numCoordinates;
};

struct CaliperOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    TwoEdgePolarityType polarity;
    float               separation;
    float               separationDeviation;
};

struct CaliperReport {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    float      edge1Contrast;
    PointFloat edge1Coord;
    float      edge2Contrast;
    PointFloat edge2Coord;
    float      separation;
    float      reserved;
};

struct DrawTextOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    //TODO char          fontName[32];
    int           fontSize;
    int           bold;
    int           italic;
    int           underline;
    int           strikeout;
    TextAlignment textAlignment;
    FontColor     fontColor;
};

struct CircleReport {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    Point center;
    int   radius;
    int   area;
};

struct ClosedContour {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    Point* points;
    int    numPoints;
};
*/
struct ColorHistogramReport {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    HistogramReport plane1;
    HistogramReport plane2;
    HistogramReport plane3;
};

struct ColorInformation {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    ~ColorInformation();
    %MethodCode
        Py_BEGIN_ALLOW_THREADS
        imaqDispose(sipCpp); sipCppV = 0;
        Py_END_ALLOW_THREADS
    %End
    int     infoCount;
    int     saturation;
    //TODO double* info;
};

struct Complex {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    float r;
    float i;
};
/*
struct ConcentricRakeReport {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    //TODO ArcInfo*            rakeArcs;
    int                 numArcs;
    //TODO PointFloat*         firstEdges;
    int                 numFirstEdges;
    //TODO PointFloat*         lastEdges;
    int                 numLastEdges;
    //TODO EdgeLocationReport* allEdges;
    //TODO int*                linesWithEdges;
    int                 numLinesWithEdges;
};

struct ConstructROIOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    int         windowNumber;
    const char* windowTitle;
    PaletteType type;
    //TODO RGBValue*   palette;
    int         numColors;
};

struct ContourInfo {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    ContourType type;
    unsigned    numPoints;
    //TODO Point*      points;
    RGBValue    contourColor;
};

// TODO
//typedef union ContourUnion_union {
//    Point*         point;
//    Line*          line;
//    Rect*          rect;
//    Rect*          ovalBoundingBox;
//    ClosedContour* closedContour;
//    OpenContour*   openContour;
//    Annulus*       annulus;
//    RotatedRect*   rotatedRect;
//};

struct ContourInfo2 {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    ContourType  type;
    RGBValue     color;
    //TODO ContourUnion structure;
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
};
*/
struct ContourPoint {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    double x;
    double y;
    double curvature;
    double xDisplacement;
    double yDisplacement;
};

struct CoordinateTransform {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    Point initialOrigin;
    float initialAngle;
    Point finalOrigin;
    float finalAngle;
};

struct CoordinateTransform2 {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    CoordinateSystem referenceSystem;
    CoordinateSystem measurementSystem;
};

struct CannyOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    float sigma;
    float upperThreshold;
    float lowerThreshold;
    int   windowSize;
};

struct Range {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    int minValue;
    int maxValue;
};
/*
struct UserPointSymbol {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    int  cols;
    int  rows;
    //TODO int* pixels;
};
*/
struct View3DOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    int         sizeReduction;
    int         maxHeight;
    Direction3D direction;
    float       alpha;
    float       beta;
    int         border;
    int         background;
    Plane3D     plane;
};
/*
struct MatchPatternOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    MatchingMode        mode;
    int                 minContrast;
    int                 subpixelAccuracy;
    //TODO RotationAngleRange* angleRanges;
    int                 numRanges;
    int                 numMatchesRequested;
    int                 matchFactor;
    float               minMatchScore;
};

struct TIFFFileOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    int                 rowsPerStrip;
    PhotometricMode     photoInterp;
    TIFFCompressionType compressionType;
};
*/
// TODO
//typedef union Color_union {
//    RGBValue rgb;
//    HSLValue hsl;
//    HSVValue hsv;
//    HSIValue hsi;
//    int      rawValue;
//};
//
//typedef union PixelValue_union {
//    float       grayscale;
//    RGBValue    rgb;
//    HSLValue    hsl;
//    Complex     complex;
//    RGBU64Value rgbu64;
//};
typedef RGBValue Color;
typedef RGBValue PixelValue;
/*
struct OpenContour {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    Point* points;
    int    numPoints;
};

struct OverlayTextOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    const char*           fontName;
    int                   fontSize;
    int                   bold;
    int                   italic;
    int                   underline;
    int                   strikeout;
    TextAlignment         horizontalTextAlignment;
    VerticalTextAlignment verticalTextAlignment;
    RGBValue              backgroundColor;
    double                angle;
};

struct ParticleFilterCriteria {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    MeasurementValue parameter;
    float            lower;
    float            upper;
    int              exclude;
};

struct ParticleReport {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    int   area;
    float calibratedArea;
    float perimeter;
    int   numHoles;
    int   areaOfHoles;
    float perimeterOfHoles;
    Rect  boundingBox;
    float sigmaX;
    float sigmaY;
    float sigmaXX;
    float sigmaYY;
    float sigmaXY;
    int   longestLength;
    Point longestPoint;
    int   projectionX;
    int   projectionY;
    int   connect8;
};

struct PatternMatch {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    PointFloat position;
    float      rotation;
    float      scale;
    float      score;
    //TODO PointFloat corner[4];
};

struct QuantifyData {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    float mean;
    float stdDev;
    float min;
    float max;
    float calibratedArea;
    int   pixelArea;
    float relativeSize;
};

struct QuantifyReport {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    QuantifyData  global;
    QuantifyData* regions;
    int           regionCount;
};

struct RakeOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    int                 threshold;
    int                 width;
    int                 steepness;
    int                 subsamplingRatio;
    InterpolationMethod subpixelType;
    int                 subpixelDivisions;
};

struct RakeReport {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    //TODO LineFloat*          rakeLines;
    int                 numRakeLines;
    //TODO PointFloat*         firstEdges;
    unsigned int        numFirstEdges;
    //TODO PointFloat*         lastEdges;
    unsigned int        numLastEdges;
    //TODO EdgeLocationReport* allEdges;
    //TODO int*                linesWithEdges;
    int                 numLinesWithEdges;
};

struct TransformReport {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    //TODO PointFloat* points;
    //TODO int*        validPoints;
    int         numPoints;
};
*/
struct ShapeReport {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    ~ShapeReport();
    %MethodCode
        Py_BEGIN_ALLOW_THREADS
        imaqDispose(sipCpp); sipCppV = 0;
        Py_END_ALLOW_THREADS
    %End
    Rect   coordinates;
    Point  centroid;
    int    size;
    double score;
private:
    ShapeReport();
    ShapeReport(const ShapeReport&);
};

struct MeterArc {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    ~MeterArc();
    %MethodCode
        Py_BEGIN_ALLOW_THREADS
        imaqDispose(sipCpp); sipCppV = 0;
        Py_END_ALLOW_THREADS
    %End
    PointFloat  needleBase;
    //TODO PointFloat* arcCoordPoints;
    int         numOfArcCoordPoints;
    int         needleColor;
private:
    MeterArc();
    MeterArc(const MeterArc&);
};

struct ThresholdData {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    float rangeMin;
    float rangeMax;
    float newValue;
    int   useNewValue;
};

struct StructuringElement {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    int  matrixCols;
    int  matrixRows;
    int  hexa;
    //TODO int* kernel;
};
/*
struct SpokeReport {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    //TODO LineFloat*          spokeLines;
    int                 numSpokeLines;
    //TODO PointFloat*         firstEdges;
    int                 numFirstEdges;
    //TODO PointFloat*         lastEdges;
    int                 numLastEdges;
    //TODO EdgeLocationReport* allEdges;
    //TODO int*                linesWithEdges;
    int                 numLinesWithEdges;
};

struct SimpleEdgeOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    LevelType   type;
    int         threshold;
    int         hysteresis;
    EdgeProcess process;
    int         subpixel;
};

struct SelectParticleCriteria {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    MeasurementValue parameter;
    float            lower;
    float            upper;
};

struct SegmentInfo {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    int           numberOfPoints;
    int           isOpen;
    double        weight;
    //TODO ContourPoint* points;
};
*/
struct RotationAngleRange {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    float lower;
    float upper;
};

struct RotatedRect {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    int    top;
    int    left;
    int    height;
    int    width;
    double angle;
};
/*
struct ROIProfile {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    LineProfile report;
    //TODO Point*      pixels;
};

struct ToolWindowOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    int showSelectionTool;
    int showZoomTool;
    int showPointTool;
    int showLineTool;
    int showRectangleTool;
    int showOvalTool;
    int showPolygonTool;
    int showClosedFreehandTool;
    int showPolyLineTool;
    int showFreehandTool;
    int showAnnulusTool;
    int showRotatedRectangleTool;
    int showPanTool;
    int reserved1;
    int reserved2;
    int reserved3;
    int reserved4;
};

struct SpokeOptions {
%TypeHeaderCode
#include <WPILib/nivision.h>
%End
    int                 threshold;
    int                 width;
    int                 steepness;
    double              subsamplingRatio;
    InterpolationMethod subpixelType;
    int                 subpixelDivisions;
};

//============================================================================
//  Globals
//============================================================================
//const RGBValue IMAQ_RGB_TRANSPARENT = {   0,   0,   0, 1 };
//const RGBValue IMAQ_RGB_RED         = {   0,   0, 255, 0 };
//const RGBValue IMAQ_RGB_BLUE        = { 255,   0,   0, 0 };
//const RGBValue IMAQ_RGB_GREEN       = {   0, 255,   0, 0 };
//const RGBValue IMAQ_RGB_YELLOW      = {   0, 255, 255, 0 };
//const RGBValue IMAQ_RGB_WHITE       = { 255, 255, 255, 0 };
//const RGBValue IMAQ_RGB_BLACK       = {   0,   0,   0, 0 };

//============================================================================
//  Display functions
//============================================================================
int   imaqAreToolsContextSensitive(int* sensitive);
int   imaqCloseWindow(int windowNumber);
int   imaqDisplayImage(const Image* image, int windowNumber, int resize);
int   imaqGetLastKey(char* keyPressed, int* windowNumber, int* modifiers);
void* imaqGetSystemWindowHandle(int windowNumber);
int   imaqGetWindowCenterPos(int windowNumber, Point* centerPosition);
int   imaqSetToolContextSensitivity(int sensitive);
int   imaqShowWindow(int windowNumber, int visible);

//============================================================================
//  Acquisition functions
//============================================================================
Image* imaqCopyFromRing(SESSION_ID sessionID, Image* image, int imageToCopy, int* imageNumber, Rect rect);
Image* imaqEasyAcquire(const char* interfaceName);
Image* imaqExtractFromRing(SESSION_ID sessionID, int imageToExtract, int* imageNumber);
Image* imaqGrab(SESSION_ID sessionID, Image* image, int immediate);
int    imaqReleaseImage(SESSION_ID sessionID);
int    imaqSetupGrab(SESSION_ID sessionID, Rect rect);
int    imaqSetupRing(SESSION_ID sessionID, Image** images, int numImages, int skipCount, Rect rect);
int    imaqSetupSequence(SESSION_ID sessionID, Image** images, int numImages, int skipCount, Rect rect);
Image* imaqSnap(SESSION_ID sessionID, Image* image, Rect rect);
int    imaqStartAcquisition(SESSION_ID sessionID);
int    imaqStopAcquisition(SESSION_ID sessionID);

//============================================================================
//  Arithmetic functions
//============================================================================
int imaqAbsoluteDifference(Image* dest, const Image* sourceA, const Image* sourceB);
int imaqAbsoluteDifferenceConstant(Image* dest, const Image* source, PixelValue value);
int imaqAdd(Image* dest, const Image* sourceA, const Image* sourceB);
int imaqAddConstant(Image* dest, const Image* source, PixelValue value);
int imaqAverage(Image* dest, const Image* sourceA, const Image* sourceB);
int imaqAverageConstant(Image* dest, const Image* source, PixelValue value);
int imaqDivide2(Image* dest, const Image* sourceA, const Image* sourceB, RoundingMode roundingMode);
int imaqDivideConstant2(Image* dest, const Image* source, PixelValue value, RoundingMode roundingMode);
int imaqMax(Image* dest, const Image* sourceA, const Image* sourceB);
int imaqMaxConstant(Image* dest, const Image* source, PixelValue value);
int imaqMin(Image* dest, const Image* sourceA, const Image* sourceB);
int imaqMinConstant(Image* dest, const Image* source, PixelValue value);
int imaqModulo(Image* dest, const Image* sourceA, const Image* sourceB);
int imaqModuloConstant(Image* dest, const Image* source, PixelValue value);
int imaqMulDiv(Image* dest, const Image* sourceA, const Image* sourceB, float value);
int imaqMultiply(Image* dest, const Image* sourceA, const Image* sourceB);
int imaqMultiplyConstant(Image* dest, const Image* source, PixelValue value);
int imaqSubtract(Image* dest, const Image* sourceA, const Image* sourceB);
int imaqSubtractConstant(Image* dest, const Image* source, PixelValue value);

//============================================================================
//  Caliper functions
//============================================================================
CaliperReport*         imaqCaliperTool(const Image* image, const Point* points, int numPoints, const EdgeOptions* edgeOptions, const CaliperOptions* caliperOptions, int* numEdgePairs);
ConcentricRakeReport2* imaqConcentricRake2(Image* image, ROI* roi, ConcentricRakeDirection direction, EdgeProcess process, int stepSize, EdgeOptions2* edgeOptions);
ExtremeReport*         imaqDetectExtremes(const double* pixels, int numPixels, DetectionMode mode, const DetectExtremesOptions* options, int* numExtremes);
int                    imaqDetectRotation(const Image* referenceImage, const Image* testImage, PointFloat referenceCenter, PointFloat testCenter, int radius, float precision, double* angle);
EdgeReport2*           imaqEdgeTool4(Image* image, ROI* roi, EdgeProcess processType, EdgeOptions2* edgeOptions, const unsigned int reverseDirection);
FindEdgeReport*        imaqFindEdge2(Image* image, const ROI* roi, const CoordinateSystem* baseSystem, const CoordinateSystem* newSystem, const FindEdgeOptions2* findEdgeOptions, const StraightEdgeOptions* straightEdgeOptions);
int                    imaqFindTransformRect2(Image* image, const ROI* roi, FindTransformMode mode, CoordinateSystem* baseSystem, CoordinateSystem* newSystem, const FindTransformRectOptions2* findTransformOptions, const StraightEdgeOptions* straightEdgeOptions, AxisReport* axisReport);
int                    imaqFindTransformRects2(Image* image, const ROI* primaryROI, const ROI* secondaryROI, FindTransformMode mode, CoordinateSystem* baseSystem, CoordinateSystem* newSystem, const FindTransformRectsOptions2* findTransformOptions, const StraightEdgeOptions* primaryStraightEdgeOptions, const StraightEdgeOptions* secondaryStraightEdgeOptions, AxisReport* axisReport);
int                    imaqLineGaugeTool2(const Image* image, Point start, Point end, LineGaugeMethod method, const EdgeOptions* edgeOptions, const CoordinateTransform2* transform, float* distance);
RakeReport2*           imaqRake2(Image* image, ROI* roi, RakeDirection direction, EdgeProcess process, int stepSize, EdgeOptions2* edgeOptions);
PointFloat*            imaqSimpleEdge(const Image* image, const Point* points, int numPoints, const SimpleEdgeOptions* options, int* numEdges);
SpokeReport2*          imaqSpoke2(Image* image, ROI* roi, SpokeDirection direction, EdgeProcess process, int stepSize, EdgeOptions2* edgeOptions);
StraightEdgeReport2*   imaqStraightEdge(const Image* image, const ROI* roi, SearchDirection searchDirection, const EdgeOptions2* edgeOptions, const StraightEdgeOptions* straightEdgeOptions);

//============================================================================
//  Spatial Filters functions
//============================================================================
int imaqCannyEdgeFilter(Image* dest, const Image* source, const CannyOptions* options);
int imaqConvolve2(Image* dest, Image* source, float* kernel, int matrixRows, int matrixCols, float normalize, Image* mask, RoundingMode roundingMode);
int imaqCorrelate(Image* dest, Image* source, const Image* templateImage, Rect rect);
int imaqEdgeFilter(Image* dest, Image* source, OutlineMethod method, const Image* mask);
int imaqLowPass(Image* dest, Image* source, int width, int height, float tolerance, const Image* mask);
int imaqMedianFilter(Image* dest, Image* source, int width, int height, const Image* mask);
int imaqNthOrderFilter(Image* dest, Image* source, int width, int height, int n, const Image* mask);

//============================================================================
//  Drawing functions
//============================================================================
int imaqDrawLineOnImage(Image* dest, const Image* source, DrawMode mode, Point start, Point end, float newPixelValue);
int imaqDrawShapeOnImage(Image* dest, const Image* source, Rect rect, DrawMode mode, ShapeMode shape, float newPixelValue);
int imaqDrawTextOnImage(Image* dest, const Image* source, Point coord, const char* text, const DrawTextOptions* options, int* fontNameUsed);

//============================================================================
//  Interlacing functions
//============================================================================
int imaqInterlaceCombine(Image* frame, const Image* odd, const Image* even);
int imaqInterlaceSeparate(const Image* frame, Image* odd, Image* even);

//============================================================================
//  Image Information functions
//============================================================================
//TODO char** imaqEnumerateCustomKeys(const Image* image, unsigned int* size);
int    imaqGetBitDepth(const Image* image, unsigned int* bitDepth);
int    imaqGetBytesPerPixel(const Image* image, int* byteCount);
int    imaqGetImageInfo(const Image* image, ImageInfo* info);
int    imaqGetImageSize(const Image* image, int* width, int* height);
int    imaqGetImageType(const Image* image, ImageType* type);
int    imaqGetMaskOffset(const Image* image, Point* offset);
void*  imaqGetPixelAddress(const Image* image, Point pixel);
int    imaqGetVisionInfoTypes(const Image* image, unsigned int* present);
int    imaqIsImageEmpty(const Image* image, int* empty);
void*  imaqReadCustomData(const Image* image, const char* key, unsigned int* size);
int    imaqRemoveCustomData(Image* image, const char* key);
int    imaqRemoveVisionInfo2(const Image* image, unsigned int info);
int    imaqSetBitDepth(Image* image, unsigned int bitDepth);
int    imaqSetImageSize(Image* image, int width, int height);
int    imaqSetMaskOffset(Image* image, Point offset);
int    imaqWriteCustomData(Image* image, const char* key, const void* data, unsigned int size);

//============================================================================
//  Tool Window functions
//============================================================================
int   imaqCloseToolWindow();
int   imaqGetCurrentTool(Tool* currentTool);
int   imaqGetLastEvent(WindowEventType* type, int* windowNumber, Tool* tool, Rect* rect);
void* imaqGetToolWindowHandle();
int   imaqGetToolWindowPos(Point* position);
int   imaqIsToolWindowVisible(int* visible);
int   imaqMoveToolWindow(Point position);
int   imaqSetCurrentTool(Tool currentTool);
int   imaqSetToolColor(const RGBValue* color);
int   imaqSetupToolWindow(int showCoordinates, int maxIconsPerLine, const ToolWindowOptions* options);
int   imaqShowToolWindow(int visible);

//============================================================================
//  Morphology functions
//============================================================================
int           imaqConvexHull(Image* dest, Image* source, int connectivity8);
int           imaqDanielssonDistance(Image* dest, Image* source);
int           imaqFillHoles(Image* dest, const Image* source, int connectivity8);
CircleReport* imaqFindCircles(Image* dest, Image* source, float minRadius, float maxRadius, int* numCircles);
int           imaqLabel2(Image* dest, Image* source, int connectivity8, int* particleCount);
int           imaqMorphology(Image* dest, Image* source, MorphologyMethod method, const StructuringElement* structuringElement);
int           imaqRejectBorder(Image* dest, Image* source, int connectivity8);
int           imaqSegmentation(Image* dest, Image* source);
int           imaqSeparation(Image* dest, Image* source, int erosions, const StructuringElement* structuringElement);
int           imaqSimpleDistance(Image* dest, Image* source, const StructuringElement* structuringElement);
int           imaqSizeFilter(Image* dest, Image* source, int connectivity8, int erosions, SizeType keepSize, const StructuringElement* structuringElement);
int           imaqSkeleton(Image* dest, Image* source, SkeletonMethod method);

//============================================================================
//  Logical functions
//============================================================================
int imaqAnd(Image* dest, const Image* sourceA, const Image* sourceB);
int imaqAndConstant(Image* dest, const Image* source, PixelValue value);
int imaqCompare(Image* dest, const Image* source, const Image* compareImage, ComparisonFunction compare);
int imaqCompareConstant(Image* dest, const Image* source, PixelValue value, ComparisonFunction compare);
int imaqLogicalDifference(Image* dest, const Image* sourceA, const Image* sourceB);
int imaqLogicalDifferenceConstant(Image* dest, const Image* source, PixelValue value);
int imaqNand(Image* dest, const Image* sourceA, const Image* sourceB);
int imaqNandConstant(Image* dest, const Image* source, PixelValue value);
int imaqNor(Image* dest, const Image* sourceA, const Image* sourceB);
int imaqNorConstant(Image* dest, const Image* source, PixelValue value);
int imaqOr(Image* dest, const Image* sourceA, const Image* sourceB);
int imaqOrConstant(Image* dest, const Image* source, PixelValue value);
int imaqXnor(Image* dest, const Image* sourceA, const Image* sourceB);
int imaqXnorConstant(Image* dest, const Image* source, PixelValue value);
int imaqXor(Image* dest, const Image* sourceA, const Image* sourceB);
int imaqXorConstant(Image* dest, const Image* source, PixelValue value);

//============================================================================
//  Particle Analysis functions
//============================================================================
int imaqCountParticles(Image* image, int connectivity8, int* numParticles);
int imaqMeasureParticle(Image* image, int particleNumber, int calibrated, MeasurementType measurement, double* value);
int imaqParticleFilter4(Image* dest, Image* source, const ParticleFilterCriteria2* criteria, int criteriaCount, const ParticleFilterOptions2* options, const ROI* roi, int* numParticles);

//============================================================================
//  Analytic Geometry functions
//============================================================================
int           imaqBuildCoordinateSystem(const Point* points, ReferenceMode mode, AxisOrientation orientation, CoordinateSystem* system);
BestCircle2*  imaqFitCircle2(const PointFloat* points, int numPoints, const FitCircleOptions* options);
BestEllipse2* imaqFitEllipse2(const PointFloat* points, int numPoints, const FitEllipseOptions* options);
BestLine*     imaqFitLine(const PointFloat* points, int numPoints, const FitLineOptions* options);
int           imaqGetAngle(PointFloat start1, PointFloat end1, PointFloat start2, PointFloat end2, float* angle);
int           imaqGetBisectingLine(PointFloat start1, PointFloat end1, PointFloat start2, PointFloat end2, PointFloat* bisectStart, PointFloat* bisectEnd);
int           imaqGetDistance(PointFloat point1, PointFloat point2, float* distance);
int           imaqGetIntersection(PointFloat start1, PointFloat end1, PointFloat start2, PointFloat end2, PointFloat* intersection);
int           imaqGetMidLine(PointFloat refLineStart, PointFloat refLineEnd, PointFloat point, PointFloat* midLineStart, PointFloat* midLineEnd);
int           imaqGetPerpendicularLine(PointFloat refLineStart, PointFloat refLineEnd, PointFloat point, PointFloat* perpLineStart, PointFloat* perpLineEnd, double* distance);
SegmentInfo*  imaqGetPointsOnContour(const Image* image, int* numSegments);
Point*        imaqGetPointsOnLine(Point start, Point end, int* numPoints);
int           imaqGetPolygonArea(const PointFloat* points, int numPoints, float* area);
//TODO float*        imaqInterpolatePoints(const Image* image, const Point* points, int numPoints, InterpolationMethod method, int subpixel, int* interpCount);

//============================================================================
//  Clipboard functions
//============================================================================
int imaqClipboardToImage(Image* dest, RGBValue* palette);
int imaqImageToClipboard(const Image* image, const RGBValue* palette);

//============================================================================
//  Border functions
//============================================================================
int imaqFillBorder(Image* image, BorderMethod method);
int imaqGetBorderSize(const Image* image, int* borderSize);
int imaqSetBorderSize(Image* image, int size);

//============================================================================
//  Image Management functions
//============================================================================
int    imaqArrayToImage(Image* image, const void* array, int numCols, int numRows);
*/
Image* imaqCreateImage(ImageType type, int borderSize) /Factory/;
/*
void*  imaqImageToArray(const Image* image, Rect rect, int* columns, int* rows);

//============================================================================
//  Color Processing functions
//============================================================================
Color2                imaqChangeColorSpace2(const Color2* sourceColor, ColorMode sourceSpace, ColorMode destSpace, double offset, const CIEXYZValue* whiteReference);
int                   imaqColorBCGTransform(Image* dest, const Image* source, const BCGOptions* redOptions, const BCGOptions* greenOptions, const BCGOptions* blueOptions, const Image* mask);
int                   imaqColorEqualize(Image* dest, const Image* source, int colorEqualization);
ColorHistogramReport* imaqColorHistogram2(Image* image, int numClasses, ColorMode mode, const CIEXYZValue* whiteReference, Image* mask);
int                   imaqColorLookup(Image* dest, const Image* source, ColorMode mode, const Image* mask, const short* plane1, const short* plane2, const short* plane3);
int                   imaqColorThreshold(Image* dest, const Image* source, int replaceValue, ColorMode mode, const Range* plane1Range, const Range* plane2Range, const Range* plane3Range);

//============================================================================
//  Transform functions
//============================================================================
int imaqBCGTransform(Image* dest, const Image* source, const BCGOptions* options, const Image* mask);
int imaqEqualize(Image* dest, const Image* source, float min, float max, const Image* mask);
int imaqInverse(Image* dest, const Image* source, const Image* mask);
int imaqLookup(Image* dest, const Image* source, const short* table, const Image* mask);
int imaqMathTransform(Image* dest, const Image* source, MathTransformMethod method, float rangeMin, float rangeMax, float power, const Image* mask);
int imaqWatershedTransform(Image* dest, const Image* source, int connectivity8, int* zoneCount);


//============================================================================
//  Window Management functions
//============================================================================
int   imaqAreScrollbarsVisible(int windowNumber, int* visible);
int   imaqBringWindowToTop(int windowNumber);
int   imaqGetMousePos(Point* position, int* windowNumber);
int   imaqGetWindowBackground(int windowNumber, WindowBackgroundFillStyle* fillStyle, WindowBackgroundHatchStyle* hatchStyle, RGBValue* fillColor, RGBValue* backgroundColor);
int   imaqGetWindowDisplayMapping(int windowNum, DisplayMapping* mapping);
int   imaqGetWindowGrid(int windowNumber, int* xResolution, int* yResolution);
int   imaqGetWindowHandle(int* handle);
int   imaqGetWindowPos(int windowNumber, Point* position);
int   imaqGetWindowSize(int windowNumber, int* width, int* height);
char* imaqGetWindowTitle(int windowNumber);
int   imaqGetWindowZoom2(int windowNumber, float* xZoom, float* yZoom);
int   imaqIsWindowNonTearing(int windowNumber, int* nonTearing);
int   imaqIsWindowVisible(int windowNumber, int* visible);
int   imaqMoveWindow(int windowNumber, Point position);
int   imaqSetupWindow(int windowNumber, int configuration);
int   imaqSetWindowBackground(int windowNumber, WindowBackgroundFillStyle fillStyle, WindowBackgroundHatchStyle hatchStyle, const RGBValue* fillColor, const RGBValue* backgroundColor);
int   imaqSetWindowDisplayMapping(int windowNumber, const DisplayMapping* mapping);
int   imaqSetWindowGrid(int windowNumber, int xResolution, int yResolution);
int   imaqSetWindowMaxContourCount(int windowNumber, unsigned int maxContourCount);
int   imaqSetWindowNonTearing(int windowNumber, int nonTearing);
int   imaqSetWindowPalette(int windowNumber, PaletteType type, const RGBValue* palette, int numColors);
int   imaqSetWindowSize(int windowNumber, int width, int height);
int   imaqSetWindowThreadPolicy(WindowThreadPolicy policy);
int   imaqSetWindowTitle(int windowNumber, const char* title);
int   imaqSetWindowZoomToFit(int windowNumber, int zoomToFit);
int   imaqShowScrollbars(int windowNumber, int visible);
int   imaqZoomWindow2(int windowNumber, float xZoom, float yZoom, Point center);
*/

//============================================================================
//  Utilities functions
//============================================================================
Kernel imaqGetKernel(KernelFamily family, int size, int number);
Annulus      imaqMakeAnnulus(Point center, int innerRadius, int outerRadius, double startAngle, double endAngle);
Point        imaqMakePoint(int xCoordinate, int yCoordinate);
PointFloat   imaqMakePointFloat(float xCoordinate, float yCoordinate);
Rect         imaqMakeRect(int top, int left, int height, int width);
Rect         imaqMakeRectFromRotatedRect(RotatedRect rotatedRect);
RotatedRect  imaqMakeRotatedRect(int top, int left, int height, int width, double angle);
RotatedRect  imaqMakeRotatedRectFromRect(Rect rect);
/*
int          imaqMulticoreOptions(MulticoreOperation operation, unsigned int* customNumCores);

//============================================================================
//  Image Manipulation functions
//============================================================================
int   imaqCast(Image* dest, const Image* source, ImageType type, const float* lookup, int shift);
*/
int   imaqCopyRect(Image* dest, const Image* source, Rect rect, Point destLoc);
int   imaqDuplicate(Image* dest, const Image* source);
/*
void* imaqFlatten(const Image* image, FlattenType type, CompressionType compression, int quality, unsigned int* size);
*/
int   imaqFlip(Image* dest, const Image* source, FlipAxis axis);
int   imaqMask(Image* dest, const Image* source, const Image* mask);
int   imaqResample(Image* dest, const Image* source, int newWidth, int newHeight, InterpolationMethod method, Rect rect);
int   imaqRotate2(Image* dest, const Image* source, float angle, PixelValue fill, InterpolationMethod method, int maintainSize);
int   imaqScale(Image* dest, const Image* source, int xScale, int yScale, ScalingMode scaleMode, Rect rect);
int   imaqShift(Image* dest, const Image* source, int shiftX, int shiftY, PixelValue fill);
int   imaqTranspose(Image* dest, const Image* source);
int   imaqUnflatten(Image* image, const void* data, unsigned int size);
int   imaqUnwrapImage(Image* dest, const Image* source, Annulus annulus, RectOrientation orientation, InterpolationMethod method);
int   imaqView3D(Image* dest, Image* source, const View3DOptions* options);

//============================================================================
//  Pattern Matching functions
//============================================================================
/*
CircleMatch*              imaqDetectCircles(const Image* image, const CircleDescriptor* circleDescriptor, const CurveOptions* curveOptions, const ShapeDetectionOptions* shapeDetectionOptions, const ROI* roi, int* numMatchesReturned);
EllipseMatch*             imaqDetectEllipses(const Image* image, const EllipseDescriptor* ellipseDescriptor, const CurveOptions* curveOptions, const ShapeDetectionOptions* shapeDetectionOptions, const ROI* roi, int* numMatchesReturned);
LineMatch*                imaqDetectLines(const Image* image, const LineDescriptor* lineDescriptor, const CurveOptions* curveOptions, const ShapeDetectionOptions* shapeDetectionOptions, const ROI* roi, int* numMatchesReturned);
RectangleMatch*           imaqDetectRectangles(const Image* image, const RectangleDescriptor* rectangleDescriptor, const CurveOptions* curveOptions, const ShapeDetectionOptions* shapeDetectionOptions, const ROI* roi, int* numMatchesReturned);
FeatureData*              imaqGetGeometricFeaturesFromCurves(const Curve* curves, unsigned int numCurves, const FeatureType* featureTypes, unsigned int numFeatureTypes, unsigned int* numFeatures);
FeatureData*              imaqGetGeometricTemplateFeatureInfo(const Image* pattern, unsigned int* numFeatures);
int                       imaqLearnColorPattern(Image* image, const LearnColorPatternOptions* options);
int                       imaqLearnGeometricPattern(Image* image, PointFloat originOffset, const CurveOptions* curveOptions, const LearnGeometricPatternAdvancedOptions* advancedLearnOptions, const Image* mask);
MultipleGeometricPattern* imaqLearnMultipleGeometricPatterns(const Image** patterns, unsigned int numberOfPatterns, const String255* labels);
int                       imaqLearnPattern3(Image* image, LearningMode learningMode, LearnPatternAdvancedOptions* advancedOptions, const Image* mask);
PatternMatch*             imaqMatchColorPattern(const Image* image, Image* pattern, const MatchColorPatternOptions* options, Rect searchRect, int* numMatches);
GeometricPatternMatch2*   imaqMatchGeometricPattern2(const Image* image, const Image* pattern, const CurveOptions* curveOptions, const MatchGeometricPatternOptions* matchOptions, const MatchGeometricPatternAdvancedOptions2* advancedMatchOptions, const ROI* roi, int* numMatches);
GeometricPatternMatch2*   imaqMatchMultipleGeometricPatterns(const Image* image, const MultipleGeometricPattern* multiplePattern, const ROI* roi, int* numMatches);
PatternMatch*             imaqMatchPattern2(const Image* image, const Image* pattern, const MatchPatternOptions* options, const MatchPatternOptions* advancedOptions, Rect searchRect, int* numMatches);
MultipleGeometricPattern* imaqReadMultipleGeometricPatternFile(const char* fileName, String255 description);
PatternMatch*             imaqRefineMatches(const Image* image, const Image* pattern, const PatternMatch* candidatesIn, int numCandidatesIn, MatchPatternOptions* options, MatchPatternAdvancedOptions* advancedOptions, int* numCandidatesOut);
int                       imaqSetMultipleGeometricPatternsOptions(MultipleGeometricPattern* multiplePattern, const char* label, const CurveOptions* curveOptions, const MatchGeometricPatternOptions* matchOptions, const MatchGeometricPatternAdvancedOptions2* advancedMatchOptions);
int                       imaqWriteMultipleGeometricPatternFile(const MultipleGeometricPattern* multiplePattern, const char* fileName, const char* description);

//============================================================================
//  Calibration functions
//============================================================================
int              imaqCopyCalibrationInfo2(Image* dest, Image* source, Point offset);
int              imaqCorrectCalibratedImage(Image* dest, const Image* source, PixelValue fill, InterpolationMethod method, const ROI* roi);
CalibrationInfo* imaqGetCalibrationInfo2(const Image* image);
int              imaqLearnCalibrationGrid(Image* image, const ROI* roi, const LearnCalibrationOptions* options, const GridDescriptor* grid, const CoordinateSystem* system, const RangeFloat* range, float* quality);
int              imaqLearnCalibrationPoints(Image* image, const CalibrationPoints* points, const ROI* roi, const LearnCalibrationOptions* options, const GridDescriptor* grid, const CoordinateSystem* system, float* quality);
int              imaqSetCoordinateSystem(Image* image, const CoordinateSystem* system);
int              imaqSetSimpleCalibration(Image* image, ScalingMethod method, int learnTable, const GridDescriptor* grid, const CoordinateSystem* system);
TransformReport* imaqTransformPixelToRealWorld(const Image* image, const PointFloat* pixelCoordinates, int numCoordinates);
TransformReport* imaqTransformRealWorldToPixel(const Image* image, const PointFloat* realWorldCoordinates, int numCoordinates);

//============================================================================
//  Overlay functions
//============================================================================
int imaqClearOverlay(Image* image, const char* group);
int imaqCopyOverlay(Image* dest, const Image* source, const char* group);
int imaqGetOverlayProperties(Image* image, const char* group, TransformBehaviors* transformBehaviors);
int imaqMergeOverlay(Image* dest, const Image* source, const RGBValue* palette, unsigned int numColors, const char* group);
int imaqOverlayArc(Image* image, const ArcInfo* arc, const RGBValue* color, DrawMode drawMode, const char* group);
int imaqOverlayBitmap(Image* image, Point destLoc, const RGBValue* bitmap, unsigned int numCols, unsigned int numRows, const char* group);
int imaqOverlayClosedContour(Image* image, const Point* points, int numPoints, const RGBValue* color, DrawMode drawMode, const char* group);
int imaqOverlayLine(Image* image, Point start, Point end, const RGBValue* color, const char* group);
int imaqOverlayMetafile(Image* image, const void* metafile, Rect rect, const char* group);
int imaqOverlayOpenContour(Image* image, const Point* points, int numPoints, const RGBValue* color, const char* group);
int imaqOverlayOval(Image* image, Rect boundingBox, const RGBValue* color, DrawMode drawMode, char* group);
int imaqOverlayPoints(Image* image, const Point* points, int numPoints, const RGBValue* colors, int numColors, PointSymbol symbol, const UserPointSymbol* userSymbol, const char* group);
int imaqOverlayRect(Image* image, Rect rect, const RGBValue* color, DrawMode drawMode, const char* group);
int imaqOverlayROI(Image* image, const ROI* roi, PointSymbol symbol, const UserPointSymbol* userSymbol, const char* group);
int imaqOverlayText(Image* image, Point origin, const char* text, const RGBValue* color, const OverlayTextOptions* options, const char* group);
int imaqSetOverlayProperties(Image* image, const char* group, TransformBehaviors* transformBehaviors);

//============================================================================
//  Color Matching functions
//============================================================================
*/
ColorInformation* imaqLearnColor(const Image* image, const ROI* roi, ColorSensitivity sensitivity, int saturation) /Factory/;
//TODO int*              imaqMatchColor(const Image* image, const ColorInformation* info, const ROI* roi, int* numScores);

//============================================================================
//  Meter functions
//============================================================================
MeterArc* imaqGetMeterArc(int lightNeedle, MeterArcMode mode, const ROI* roi, PointFloat base, PointFloat start, PointFloat end) /Factory/;
int       imaqReadMeter(const Image* image, const MeterArc* arcInfo, double* percentage /Out/, PointFloat* endOfNeedle /Out/);

//============================================================================
//  Barcode I/O functions
//============================================================================
/*
int               imaqGradeDataMatrixBarcodeAIM(const Image* image, AIMGradeReport* report);
BarcodeInfo*      imaqReadBarcode(const Image* image, BarcodeType type, const ROI* roi, int validate);
DataMatrixReport* imaqReadDataMatrixBarcode2(Image* image, const ROI* roi, DataMatrixGradingMode prepareForGrading, const DataMatrixDescriptionOptions* descriptionOptions, const DataMatrixSizeOptions* sizeOptions, const DataMatrixSearchOptions* searchOptions);
Barcode2DInfo*    imaqReadPDF417Barcode(const Image* image, const ROI* roi, Barcode2DSearchMode searchMode, unsigned int* numBarcodes);
QRCodeReport*     imaqReadQRCode(Image* image, const ROI* roi, QRGradingMode reserved, const QRCodeDescriptionOptions* descriptionOptions, const QRCodeSizeOptions* sizeOptions, const QRCodeSearchOptions* searchOptions);
*/


//============================================================================
//  Shape Matching functions
//============================================================================
ShapeReport* imaqMatchShape(Image* dest, Image* source, const Image* templateImage, int scaleInvariant, int connectivity8, double tolerance, int* numMatches /Out/) /Factory/;

//============================================================================
//  Contours functions
//============================================================================
/*
ContourID     imaqAddAnnulusContour(ROI* roi, Annulus annulus);
ContourID     imaqAddClosedContour(ROI* roi, const Point* points, int numPoints);
ContourID     imaqAddLineContour(ROI* roi, Point start, Point end);
ContourID     imaqAddOpenContour(ROI* roi, const Point* points, int numPoints);
ContourID     imaqAddOvalContour(ROI* roi, Rect boundingBox);
ContourID     imaqAddPointContour(ROI* roi, Point point);
ContourID     imaqAddRectContour(ROI* roi, Rect rect);
ContourID     imaqAddRotatedRectContour2(ROI* roi, RotatedRect rect);
ContourID     imaqCopyContour(ROI* destRoi, const ROI* sourceRoi, ContourID id);
ContourID     imaqGetContour(const ROI* roi, unsigned int index);
int           imaqGetContourColor(const ROI* roi, ContourID id, RGBValue* contourColor);
int           imaqGetContourCount(const ROI* roi);
ContourInfo2* imaqGetContourInfo2(const ROI* roi, ContourID id);
int           imaqMoveContour(ROI* roi, ContourID id, int deltaX, int deltaY);
int           imaqRemoveContour(ROI* roi, ContourID id);
int           imaqSetContourColor(ROI* roi, ContourID id, const RGBValue* color);

//============================================================================
//  Regions of Interest functions
//============================================================================
int  imaqConstructROI2(const Image* image, ROI* roi, Tool initialTool, const ToolWindowOptions* tools, const ConstructROIOptions2* options, int* okay);
ROI* imaqCreateROI();
int  imaqGetROIBoundingBox(const ROI* roi, Rect* boundingBox);
int  imaqGetROIColor(const ROI* roi, RGBValue* roiColor);
ROI* imaqGetWindowROI(int windowNumber);
int  imaqSetROIColor(ROI* roi, const RGBValue* color);
int  imaqSetWindowROI(int windowNumber, const ROI* roi);

//============================================================================
//  Image Analysis functions
//============================================================================
int              imaqCentroid(const Image* image, PointFloat* centroid, const Image* mask);
Curve*           imaqExtractCurves(const Image* image, const ROI* roi, const CurveOptions* curveOptions, unsigned int* numCurves);
HistogramReport* imaqHistogram(const Image* image, int numClasses, float min, float max, const Image* mask);
LinearAverages*  imaqLinearAverages2(Image* image, LinearAveragesMode mode, Rect rect);
LineProfile*     imaqLineProfile(const Image* image, Point start, Point end);
QuantifyReport*  imaqQuantify(const Image* image, const Image* mask);

//============================================================================
//  Error Management functions
//============================================================================
int         imaqClearError();
char*       imaqGetErrorText(int errorCode);
int         imaqGetLastError();
const char* imaqGetLastErrorFunc();
int         imaqSetError(int errorCode, const char* function);

//============================================================================
//  Threshold functions
//============================================================================
ThresholdData* imaqAutoThreshold2(Image* dest, const Image* source, int numClasses, ThresholdMethod method, const Image* mask);
int            imaqLocalThreshold(Image* dest, const Image* source, unsigned int windowWidth, unsigned int windowHeight, LocalThresholdMethod method, double deviationWeight, ObjectType type, float replaceValue);
int            imaqMagicWand(Image* dest, const Image* source, Point coord, float tolerance, int connectivity8, float replaceValue);
int            imaqMultithreshold(Image* dest, const Image* source, const ThresholdData* ranges, int numRanges);
int            imaqThreshold(Image* dest, const Image* source, float rangeMin, float rangeMax, int useNewValue, float newValue);

//============================================================================
//  Memory Management functions
//============================================================================
int imaqDispose(void* object);

//============================================================================
//  File I/O functions
//============================================================================
int         imaqCloseAVI(AVISession session);
AVISession  imaqCreateAVI(const char* fileName, const char* compressionFilter, int quality, unsigned int framesPerSecond, unsigned int maxDataSize);
int         imaqGetAVIInfo(AVISession session, AVIInfo* info);
int         imaqGetFileInfo(const char* fileName, CalibrationUnit* calibrationUnit, float* calibrationX, float* calibrationY, int* width, int* height, ImageType* imageType);
//TODO FilterName* imaqGetFilterNames(int* numFilters);
//TODO char**      imaqLoadImagePopup(const char* defaultDirectory, const char* defaultFileSpec, const char* fileTypeList, const char* title, int allowMultiplePaths, ButtonLabel buttonLabel, int restrictDirectory, int restrictExtension, int allowCancel, int allowMakeDirectory, int* cancelled, int* numPaths);
AVISession  imaqOpenAVI(const char* fileName);
int         imaqReadAVIFrame(Image* image, AVISession session, unsigned int frameNum, void* data, unsigned int* dataSize);
int         imaqReadFile(Image* image, const char* fileName, RGBValue* colorTable, int* numColors);
int         imaqReadVisionFile(Image* image, const char* fileName, RGBValue* colorTable, int* numColors);
int         imaqWriteAVIFrame(Image* image, AVISession session, const void* data, unsigned int dataLength);
int         imaqWriteBMPFile(const Image* image, const char* fileName, int compress, const RGBValue* colorTable);
int         imaqWriteFile(const Image* image, const char* fileName, const RGBValue* colorTable);
int         imaqWriteJPEGFile(const Image* image, const char* fileName, unsigned int quality, void* colorTable);
int         imaqWriteJPEG2000File(const Image* image, const char* fileName, int lossless, float compressionRatio, const JPEG2000FileAdvancedOptions* advancedOptions, const RGBValue* colorTable);
int         imaqWritePNGFile2(const Image* image, const char* fileName, unsigned int compressionSpeed, const RGBValue* colorTable, int useBitDepth);
int         imaqWriteTIFFFile(const Image* image, const char* fileName, const TIFFFileOptions* options, const RGBValue* colorTable);
int         imaqWriteVisionFile(const Image* image, const char* fileName, const RGBValue* colorTable);

//============================================================================
//  Frequency Domain Analysis functions
//============================================================================
int imaqAttenuate(Image* dest, const Image* source, AttenuateMode highlow);
int imaqConjugate(Image* dest, const Image* source);
int imaqFFT(Image* dest, const Image* source);
int imaqFlipFrequencies(Image* dest, const Image* source);
int imaqInverseFFT(Image* dest, const Image* source);
int imaqTruncate(Image* dest, const Image* source, TruncateMode highlow, float ratioToKeep);

//============================================================================
//  Pixel Manipulation functions
//============================================================================
int    imaqArrayToComplexPlane(Image* dest, const Image* source, const float* newPixels, ComplexPlane plane);
//TODO float* imaqComplexPlaneToArray(const Image* image, ComplexPlane plane, Rect rect, int* columns, int* rows);
int    imaqExtractColorPlanes(const Image* image, ColorMode mode, Image* plane1, Image* plane2, Image* plane3);
int    imaqExtractComplexPlane(Image* dest, const Image* source, ComplexPlane plane);
int    imaqFillImage(Image* image, PixelValue value, const Image* mask);
void*  imaqGetLine(const Image* image, Point start, Point end, int* numPoints);
int    imaqGetPixel(const Image* image, Point pixel, PixelValue* value);
int    imaqReplaceColorPlanes(Image* dest, const Image* source, ColorMode mode, const Image* plane1, const Image* plane2, const Image* plane3);
int    imaqReplaceComplexPlane(Image* dest, const Image* source, const Image* newValues, ComplexPlane plane);
int    imaqSetLine(Image* image, const void* array, int arraySize, Point start, Point end);
int    imaqSetPixel(Image* image, Point coord, PixelValue value);

//============================================================================
//  LCD functions
//============================================================================
int        imaqFindLCDSegments(ROI* roi, const Image* image, const LCDOptions* options);
LCDReport* imaqReadLCD(const Image* image, const ROI* roi, const LCDOptions* options);

//============================================================================
//  Regions of Interest Manipulation functions
//============================================================================
ROI*        imaqMaskToROI(const Image* mask, int* withinLimit);
ROIProfile* imaqROIProfile(const Image* image, const ROI* roi);
int         imaqROIToMask(Image* mask, const ROI* roi, int fillValue, const Image* imageModel, int* inSpace);
int         imaqTransformROI2(ROI* roi, const CoordinateSystem* baseSystem, const CoordinateSystem* newSystem);

//============================================================================
//  OCR functions
//============================================================================
CharSet*         imaqCreateCharSet();
int              imaqDeleteChar(CharSet* set, int index);
int              imaqGetCharCount(const CharSet* set);
CharInfo2*       imaqGetCharInfo2(const CharSet* set, int index);
int              imaqReadOCRFile(const char* fileName, CharSet* set, String255 setDescription, ReadTextOptions* readOptions, OCRProcessingOptions* processingOptions, OCRSpacingOptions* spacingOptions);
ReadTextReport3* imaqReadText3(const Image* image, const CharSet* set, const ROI* roi, const ReadTextOptions* readOptions, const OCRProcessingOptions* processingOptions, const OCRSpacingOptions* spacingOptions);
int              imaqRenameChar(CharSet* set, int index, const char* newCharValue);
int              imaqSetReferenceChar(const CharSet* set, int index, int isReferenceChar);
int              imaqTrainChars(const Image* image, CharSet* set, int index, const char* charValue, const ROI* roi, const OCRProcessingOptions* processingOptions, const OCRSpacingOptions* spacingOptions);
//TODO int*             imaqVerifyPatterns(const Image* image, const CharSet* set, const String255* expectedPatterns, int patternCount, const ROI* roi, int* numScores);
//TODO int*             imaqVerifyText(const Image* image, const CharSet* set, const char* expectedString, const ROI* roi, int* numScores);
int              imaqWriteOCRFile(const char* fileName, const CharSet* set, const char* setDescription, const ReadTextOptions* readOptions, const OCRProcessingOptions* processingOptions, const OCRSpacingOptions* spacingOptions);

//============================================================================
//  Classification functions
//============================================================================
int                            imaqAddClassifierSample(Image* image, ClassifierSession* session, const ROI* roi, const char* sampleClass, double* featureVector, unsigned int vectorSize);
ClassifierReport*              imaqClassify(Image* image, const ClassifierSession* session, const ROI* roi, double* featureVector, unsigned int vectorSize);
ClassifierSession*             imaqCreateClassifier(ClassifierType type);
int                            imaqDeleteClassifierSample(ClassifierSession* session, int index);
ClassifierAccuracyReport*      imaqGetClassifierAccuracy(const ClassifierSession* session);
ClassifierSampleInfo*          imaqGetClassifierSampleInfo(const ClassifierSession* session, int index, int* numSamples);
int                            imaqGetNearestNeighborOptions(const ClassifierSession* session, NearestNeighborOptions* options);
int                            imaqGetParticleClassifierOptions(const ClassifierSession* session, ParticleClassifierPreprocessingOptions* preprocessingOptions, ParticleClassifierOptions* options);
ClassifierSession*             imaqReadClassifierFile(ClassifierSession* session, const char* fileName, ReadClassifierFileMode mode, ClassifierType* type, ClassifierEngineType* engine, String255 description);
int                            imaqRelabelClassifierSample(ClassifierSession* session, int index, const char* newClass);
int                            imaqSetParticleClassifierOptions(ClassifierSession* session, const ParticleClassifierPreprocessingOptions* preprocessingOptions, const ParticleClassifierOptions* options);
NearestNeighborTrainingReport* imaqTrainNearestNeighborClassifier(ClassifierSession* session, const NearestNeighborOptions* options);
int                            imaqWriteClassifierFile(const ClassifierSession* session, const char* fileName, WriteClassifierFileMode mode, const String255 description);

//============================================================================
//  Inspection functions
//============================================================================
int imaqCompareGoldenTemplate(const Image* image, Image* goldenTemplate, Image* brightDefects, Image* darkDefects, const InspectionAlignment* alignment, const InspectionOptions* options);
int imaqLearnGoldenTemplate(Image* goldenTemplate, PointFloat originOffset, const Image* mask);

//============================================================================
//  Morphology functions
//============================================================================
int imaqGrayMorphology(Image* dest, Image* source, MorphologyMethod method, const StructuringElement* structuringElement);
//============================================================================
//  Obsolete functions
//============================================================================
int                    imaqLineGaugeTool(const Image* image, Point start, Point end, LineGaugeMethod method, const EdgeOptions* edgeOptions, const CoordinateTransform* reference, float* distance);
int                    imaqWritePNGFile(const Image* image, const char* fileName, unsigned int compressionSpeed, const RGBValue* colorTable);
ParticleReport*        imaqGetParticleInfo(Image* image, int connectivity8, ParticleInfoMode mode, int* reportCount);
int                    imaqCalcCoeff(const Image* image, const ParticleReport* report, MeasurementValue parameter, float* coefficient);
EdgeReport*            imaqEdgeTool(const Image* image, const Point* points, int numPoints, const EdgeOptions* options, int* numEdges);
CircleReport*          imaqCircles(Image* dest, const Image* source, float minRadius, float maxRadius, int* numCircles);
int                    imaqLabel(Image* dest, Image* source, int connectivity8, int* particleCount);
int                    imaqFitEllipse(const PointFloat* points, int numPoints, BestEllipse* ellipse);
int                    imaqFitCircle(const PointFloat* points, int numPoints, BestCircle* circle);
Color                  imaqChangeColorSpace(const Color* sourceColor, ColorMode sourceSpace, ColorMode destSpace);
int                    imaqConstructROI(const Image* image, ROI* roi, Tool initialTool, const ToolWindowOptions* tools, const ConstructROIOptions* options, int* okay);
ParticleReport*        imaqSelectParticles(const Image* image, const ParticleReport* reports, int reportCount, int rejectBorder, const SelectParticleCriteria* criteria, int criteriaCount, int* selectedCount);
int                    imaqRotate(Image* dest, const Image* source, float angle, PixelValue fill, InterpolationMethod method);
int                    imaqLearnPattern(Image* image, LearningMode learningMode);
int                    imaqBestCircle(const PointFloat* points, int numPoints, PointFloat* center, double* radius);
int                    imaqSavePattern(const Image* pattern, const char* fileName);
int                    imaqLoadPattern(Image* pattern, const char* fileName);
int                    imaqTransformROI(ROI* roi, Point originStart, float angleStart, Point originFinal, float angleFinal);
int                    imaqCoordinateReference(const Point* points, ReferenceMode mode, Point* origin, float* angle);
ContourInfo*           imaqGetContourInfo(const ROI* roi, ContourID id);
int                    imaqSetWindowOverlay(int windowNumber, const Overlay* overlay);
Overlay*               imaqCreateOverlayFromROI(const ROI* roi);
Overlay*               imaqCreateOverlayFromMetafile(const void* metafile);
int                    imaqSetCalibrationInfo(Image* image, CalibrationUnit unit, float xDistance, float yDistance);
int                    imaqGetCalibrationInfo(const Image* image, CalibrationUnit* unit, float* xDistance, float* yDistance);
int                    imaqConvex(Image* dest, const Image* source);
int                    imaqParticleFilter2(Image* dest, Image* source, const ParticleFilterCriteria2* criteria, int criteriaCount, int rejectMatches, int connectivity8, int* numParticles);
int                    imaqGetWindowZoom(int windowNumber, int* xZoom, int* yZoom);
int                    imaqParticleFilter3(Image* dest, Image* source, const ParticleFilterCriteria2* criteria, int criteriaCount, const ParticleFilterOptions* options, const ROI* roi, int* numParticles);
ReadTextReport2*       imaqReadText2(const Image* image, const CharSet* set, const ROI* roi, const ReadTextOptions* readOptions, const OCRProcessingOptions* processingOptions, const OCRSpacingOptions* spacingOptions);
int                    imaqLearnPattern2(Image* image, LearningMode learningMode, LearnPatternAdvancedOptions* advancedOptions);
*/
int                    imaqConvolve(Image* dest, Image* source, Kernel kernel, int matrixRows, int matrixCols, float normalize, const Image* mask=0);
%MethodCode
    Py_BEGIN_ALLOW_THREADS
    sipRes = imaqConvolve(a0,a1,(const float*)a2,a3,a4,a5,a6);
    Py_END_ALLOW_THREADS
%End
/*
int                    imaqDivideConstant(Image* dest, const Image* source, PixelValue value);
int                    imaqDivide(Image* dest, const Image* sourceA, const Image* sourceB);
EdgeReport2*           imaqEdgeTool3(const Image* image, const ROI* roi, EdgeProcess processType, const EdgeOptions2* edgeOptions);
ConcentricRakeReport*  imaqConcentricRake(const Image* image, const ROI* roi, ConcentricRakeDirection direction, EdgeProcess process, const RakeOptions* options);
SpokeReport*           imaqSpoke(const Image* image, const ROI* roi, SpokeDirection direction, EdgeProcess process, const SpokeOptions* options);
int                    imaqParticleFilter(Image* dest, Image* source, const ParticleFilterCriteria* criteria, int criteriaCount, int rejectMatches, int connectivity8);
int                    imaqCopyCalibrationInfo(Image* dest, const Image* source);
int                    imaqZoomWindow(int windowNumber, int xZoom, int yZoom, Point center);
EdgeReport*            imaqEdgeTool2(const Image* image, const Point* points, int numPoints, EdgeProcess process, const EdgeOptions* options, int* numEdges);
ContourID              imaqAddRotatedRectContour(ROI* roi, RotatedRect rect);
Barcode2DInfo*         imaqReadDataMatrixBarcode(const Image* image, const ROI* roi, const DataMatrixOptions* options, unsigned int* numBarcodes);
LinearAverages*        imaqLinearAverages(const Image* image, Rect rect);
GeometricPatternMatch* imaqMatchGeometricPattern(const Image* image, const Image* pattern, const CurveOptions* curveOptions, const MatchGeometricPatternOptions* matchOptions, const MatchGeometricPatternAdvancedOptions* advancedMatchOptions, const ROI* roi, int* numMatches);
CharInfo*              imaqGetCharInfo(const CharSet* set, int index);
ReadTextReport*        imaqReadText(const Image* image, const CharSet* set, const ROI* roi, const ReadTextOptions* readOptions, const OCRProcessingOptions* processingOptions, const OCRSpacingOptions* spacingOptions);
ThresholdData*         imaqAutoThreshold(Image* dest, Image* source, int numClasses, ThresholdMethod method);
ColorHistogramReport*  imaqColorHistogram(Image* image, int numClasses, ColorMode mode, const Image* mask);
int                    imaqIsVisionInfoPresent(const Image* image, VisionInfoType type, int* present);
PatternMatch*          imaqMatchPattern(const Image* image, Image* pattern, const MatchPatternOptions* options, Rect searchRect, int* numMatches);
RakeReport*            imaqRake(const Image* image, const ROI* roi, RakeDirection direction, EdgeProcess process, const RakeOptions* options);
*/

