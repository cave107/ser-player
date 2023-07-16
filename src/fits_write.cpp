#include "fits_write.h"

using namespace std;

#include "fitsio.h"

bool FITSWriter::save_frame_to_fits(const char *path, const uint8_t *img, const int width, const int height, const int depth) {
    fitsfile *fp;

    long dimensions[] = {width, height};

    int status = 0;
    int fileExists = 0;

    fits_file_exists(path, &fileExists, &status);

    if(fileExists) {
        fits_open_file(&fp, path, READWRITE, &status);
    } else {
        fits_create_file(&fp, path, &status);
    }

    if(status != 0) {
        fits_report_error(stderr, status);
        return false;
    }

    printf("[fits-writer] created file\n");

    if(fits_create_img(fp, depth*8, 2, dimensions, &status) != 0)
        return false;

    printf("[fits-writer] created phdu\n");

    long nPixels = width * height;
    fits_write_img(fp, TUSHORT, 1, nPixels, (void *)img, &status);

    printf("[fits-writer] written image\n");

    fits_close_file(fp, &status);

    printf("[fits-writer] closed file, deleted ptr\n");

    return true;
}
