#pragma once

/*
@file AsciiRenderer.hpp
@brief Declaration of ASCII image rendering utilities and AsciiRenderer class.
@author Onisim
@date 2025-12-05
*/

#include <string>
#include <vector>

using  ImageType = std::vector<std::string>; // Each string represents a line in the ASCII image

size_t GetImageWidth(const ImageType& image); // Returns the width of the widest line in the image
size_t GetImageHeight(const ImageType& image); // Returns the number of lines in the image

ImageType NormalizeImage(const ImageType& image, size_t width, size_t height); // Normalizes the image to the specified width and height by padding with spaces

ImageType FromFile(const std::string& filename); // Loads an ASCII image from a file
ImageType FlipImage(const ImageType& image); // Flips the image horizontally
ImageType MergeImages(const ImageType& left, const ImageType& right); // Merges two images side by side

class AsciiRenderer { // Renders ASCII images to the console
public:
    void DrawImage(const ImageType& image);
    ~AsciiRenderer() = default;
};