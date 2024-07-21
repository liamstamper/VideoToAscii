# Video to ASCII 
This project captures video from your webcam and converts each frame into ASCII art, displaying it in the terminal in real-time.

https://github.com/user-attachments/assets/3aca8ce8-2981-448b-9a62-358adb6ccc99

## Prerequisites

- OpenCV 4.0 or higher
- CMake 

## Installation

### macOS

1. **Install OpenCV**:
    ```sh
    brew install opencv
    ```

2. **Install CMake**:
    ```sh
    brew install cmake
    ```

## Building the Project

You can build the project using either CMake or a simple Makefile.

### Using CMake

1. **Create a `CMakeLists.txt` file**:
    ```cmake
    cmake_minimum_required(VERSION 3.10)
    project(VideoToAscii)

    find_package(OpenCV REQUIRED)
    include_directories(${OpenCV_INCLUDE_DIRS})

    add_executable(VideoToAscii main.cpp)
    target_link_libraries(VideoToAscii ${OpenCV_LIBS})
    ```

2. **Create a Build Directory and Compile**:
    ```sh
    mkdir build
    cd build
    cmake ..
    make
    ```

3. **Run the Executable**:
    ```sh
    ./VideoToAscii
    ```

### Using a Makefile

1. **Create a `Makefile`**:
    ```makefile
    CXX = g++
    CXXFLAGS = `pkg-config --cflags opencv4`
    LDFLAGS = `pkg-config --libs opencv4`
    TARGET = VideoToAscii

    $(TARGET): main.o
        $(CXX) -o $(TARGET) main.o $(LDFLAGS)

    main.o: main.cpp
        $(CXX) $(CXXFLAGS) -c main.cpp

    clean:
        rm -f *.o $(TARGET)
    ```

2. **Build the Project**:
    ```sh
    make
    ```

3. **Run the Executable**:
    ```sh
    ./VideoToAscii
    ```

## Running the Program

Make sure your webcam is connected and accessible by your system. Run the compiled executable to start capturing video and displaying it as ASCII art in the terminal.

## Troubleshooting

1. **Camera Not Opening**:
   - Ensure no other application is using the camera
   - Verify camera permissions in `System Preferences` -> `Security & Privacy` -> `Privacy` -> `Camera`.

2. **Continuity Camera Issues**:
   - Disconnect your iPhone if it's connected.
   - Disable Continuity Camera on your iphone in `General` ->  `Airplay & Handoff` by unchecking "Continuity Camera".

