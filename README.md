# kd-tree

This repository contains a C++ implementation of a kd-tree to handle point geometries.

## Project Structure

The project directory is organized as follows:

```
.
├── README.md
├── run.sh
└── src
    ├── CMakeLists.txt
    ├── geometry.hpp
    ├── kdtree.hpp
    └── main.cpp
```

## Source Files

- **src/CMakeLists.txt**: Contains the build configuration for the project.
- **src/geometry.hpp**: Defines the geometry structures used in the kd-tree.
- **src/kdtree.hpp**: Contains the implementation of the kd-tree.
- **src/main.cpp**: The main entry point of the project, which demonstrates the usage of the kd-tree.

## Getting Started

To build and run this project, you'll need the following software installed on your machine:

- A C++ compiler (e.g., g++)
- CMake

### Building the Project

You can build the project using the provided `run.sh` script. This script will configure and build the project using CMake. 

To build the project, open your terminal, navigate to the project directory, and run:

```sh
./run.sh
```

### Running the Project

After building the project, you can run the executable generated by the build process. The `run.sh` script also handles running the project for you.

## Contributing

We welcome contributions! If you have suggestions for improvements or bug fixes, please feel free to fork the repository and submit a pull request.

## License

`kd-tree` is distributed under the MIT license. See LICENSE for more details.
