
#include <iostream>
#include <string>
class Image_File_Format {
public:
  Image_File_Format(std::size_t height, std::size_t width,
                    std::size_t num_of_colors, std::size_t sh_of_gray,
                    const std::string &format_name = "")
      : height_(height), width_(width), num_of_colors_(num_of_colors),
        shades_of_gray_(sh_of_gray), format_name_(format_name) {
    switch (num_of_colors) {
    case 2:
      bit_depth_ = 2;
      break;
    case 16:
      bit_depth_ = 4;
      break;
    case 128:
      bit_depth_ = 7;
      break;
    case 256:
      bit_depth_ = 8;
      break;
    case 65536:
      bit_depth_ = 16;
      break;
    case 16000000:
      bit_depth_ = 24;
      break;
    case 256000000000000:
      bit_depth_ = 48;
      break;
    default:
      bit_depth_ = 2;
      break;
    }
    size_ = ((height * width * bit_depth_) / 8) / 1024.0;
  }

  std::size_t height() const { return height_; };
  std::size_t width() const { return width_; };
  std::size_t num_of_colors() const { return num_of_colors_; }
  std::size_t shades_of_gray() const { return shades_of_gray_; };
  std::size_t bit_depth() const { return bit_depth_; };
  double size() const { return size_; }
  std::string format_name() const { return format_name_; };

  virtual std::string format_type() const = 0;

protected:
  std::size_t height_ = 0;
  std::size_t width_ = 0;
  std::size_t num_of_colors_ = 0;
  std::string format_name_ = "";
  std::size_t shades_of_gray_ = 0;
  std::size_t bit_depth_ = 0;
  double size_ = 0;
};

class Raster_Format : public Image_File_Format {
public:
  Raster_Format() = delete;

protected:
  Raster_Format(std::size_t height, std::size_t width,
                std::size_t num_of_colors, std::size_t sh_of_gray,
                const std::string &format_name = "")
      : Image_File_Format(height, width, num_of_colors, sh_of_gray,
                          format_name) {}

  std::string format_type() const { return format_type_; }

private:
  std::string format_type_ = "Raster";
};

class Vector_Format : public Image_File_Format {
public:
  std::string format_type() const { return "Vector"; }
};

class JPEG_JFIF : public Raster_Format {
public:
  JPEG_JFIF(std::size_t height, std::size_t width)
      : Raster_Format(height, width, 16000000, 256, "JPEG") {}
};

class TIFF : public Raster_Format {
public:
  TIFF(std::size_t height, std::size_t width)
      : Raster_Format(height, width, 16000000, 256, "TIFF") {}
};

class BMP : public Raster_Format {

public:
  BMP(std::size_t height, std::size_t width)
      : Raster_Format(height, width, 16000000, 256, "BMP") {}
};

class PNG : public Raster_Format {
public:
  PNG(std::size_t height, std::size_t width)
      : Raster_Format(height, width, 256000000000000, 65536, "PNG") {}
};
/* class PPM : Raster_Format; */
/* class WebP : Raster_Format; */
/* class HDR : Raster_Format; */
/* class HEIF : Raster_Format; */

/* class CGM : Vector_Format; */
/* class RS_274X : Vector_Format; */
/* class SVG : Vector_Format; */

int main() {
  JPEG_JFIF jpg(540, 230);
  PNG png(1280, 720);
  /* std::cout << jpg.size(); */
  std::cout << png.size();
  /* std::cout << jpg.format_name(); */
}
