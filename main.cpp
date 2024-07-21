#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <vector>

// Function to convert frame to grayscale
cv::Mat toGrayscale(const cv::Mat& frame) {
    cv::Mat gray;
    cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
    return gray;
}

// Function to map grayscale values to ASCII characters
std::string grayscaleToAscii(const cv::Mat& gray) {
    const std::string chars = "@%#*+=-:. "; // Light to dark characters
    std::string asciiArt;
    for (int y = 0; y < gray.rows; ++y) {
        for (int x = 0; x < gray.cols; ++x) {
            int grayValue = gray.at<uchar>(y, x);
            char asciiChar = chars[grayValue * chars.length() / 256];
            asciiArt += asciiChar;
        }
        asciiArt += '\n';
    }
    return asciiArt;
}

// Function to resize frame for terminal display
cv::Mat resizeFrame(const cv::Mat& frame, int width, int height) {
    cv::Mat resized;
    cv::resize(frame, resized, cv::Size(width, height));
    return resized;
}

// Function to display ASCII art
void displayAsciiArt(const std::string& asciiArt) {
    std::cout << asciiArt << std::endl;
}

int main() {
    cv::VideoCapture cap;

    // Try different camera indices
    for (int i = 0; i < 5; ++i) {
        cap.open(i);
        if (cap.isOpened()) {
            std::cout << "Camera opened at index " << i << std::endl;
            break;
        } else {
            std::cerr << "Error: Could not open camera at index " << i << std::endl;
        }
    }

    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open any camera." << std::endl;
        return -1;
    }

    cv::Mat frame;
    while (true) {
        cap >> frame; // Capture a new frame
        if (frame.empty()) {
            std::cerr << "Error: Blank frame grabbed." << std::endl;
            break;
        }
        cv::imshow("Camera Test", frame);
        if (cv::waitKey(30) >= 0) break; // Exit on any key press
    }

    return 0;
}

