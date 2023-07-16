#pragma once

#include <stdint.h>

namespace FITSWriter {
    bool save_frame_to_fits(const char *path, const uint8_t *img, const int width, const int height, const int depth);
}
