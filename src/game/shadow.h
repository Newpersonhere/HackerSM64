#ifndef SHADOW_H
#define SHADOW_H

#include <PR/ultratypes.h>
#include <PR/gbi.h>

/**
 * Shadow types. Shadows are circles, squares, or hardcoded rectangles, and
 * can be composed of either 4 or 9 vertices.
 */
enum ShadowType {
    SHADOW_CIRCLE_9_VERTS             =  0,
    SHADOW_CIRCLE_4_VERTS             =  1,
    SHADOW_CIRCLE_4_VERTS_FLAT_UNUSED =  2,
    SHADOW_SQUARE_PERMANENT           = 10,
    SHADOW_SQUARE_SCALABLE            = 11,
    SHADOW_SQUARE_TOGGLABLE           = 12,
    /**
     * This defines an offset after which rectangular shadows with custom
     * widths and heights can be defined.
     */
    SHADOW_RECTANGLE_HARDCODED_OFFSET = 50,
    SHADOW_CIRCLE_PLAYER              = 99
};

enum ShadowFlags {
    SHADOW_FLAGS_NONE         = (0 << 0),
    // Flag for if the current shadow is above water or lava.
    SHADOW_FLAG_WATER_BOX     = (1 << 0),
    SHADOW_FLAG_WATER_SURFACE = (1 << 1),
    // Flag for if Mario is on ice or a flying carpet.
    SHADOW_FLAG_ICE_CARPET    = (1 << 2),
    // Flag for if Mario is on a flying carpet.
    SHADOW_FLAG_RAISED        = (1 << 3),
};

extern s8 gShadowFlags;

/**
 * Given the (x, y, z) location of an object, create a shadow below that object
 * with the given initial solidity and "shadowType" (described above).
 */
Gfx *create_shadow_below_xyz(f32 xPos, f32 yPos, f32 zPos, s16 shadowScale, u8 shadowSolidity, s8 shadowType);

#endif // SHADOW_H
