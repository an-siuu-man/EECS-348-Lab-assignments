#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <iomanip>

// Function prototypes
void printMatrix(const std::vector<std::vector<int>>& matrix);
std::vector<std::vector<int>> matrixOperation(const std::vector<std::vector<int>>& matrixA, const std::vector<std::vector<int>>& matrixB, char operation);

int main() {
    const int MAX_SIZE = 100;
    int size = 0;
    std::vector<std::vector<int>> matrixA;
    std::vector<std::vector<int>> matrixB;

    // Get file name from the user
    std::string fileName;
    std::cout << "Enter the name of the input file: ";
    std::cin >> fileName;

    // Open file
    std::ifstream inFile(fileName);

    try {
        if (!inFile.is_open()) {
            throw std::runtime_error("Unable to open the file");
        }

        // Read size and validate
        inFile >> size;
        if (size > MAX_SIZE || size <= 0) {
            throw std::runtime_error("Invalid matrix size");
        }

        // Resize matrices
        matrixA.resize(size, std::vector<int>(size));
        matrixB.resize(size, std::vector<int>(size));

        // Read matrices from file
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                inFile >> matrixA[i][j];
            }
        }
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                inFile >> matrixB[i][j];
            }
        }

        // Close the file
        inFile.close();

        // Print matrices
        std::cout << "\nMatrix A:\n";
        printMatrix(matrixA);

        std::cout << "\nMatrix B:\n";
        printMatrix(matrixB);

        // Perform matrix operations and print results
        std::cout << "\nMatrix Sum (A + B):\n";
        printMatrix(matrixOperation(matrixA, matrixB, '+'));

        std::cout << "\nMatrix Product (A * B):\n";
        printMatrix(matrixOperation(matrixA, matrixB, '*'));

        std::cout << "\nMatrix Difference (A - B):\n";
        printMatrix(matrixOperation(matrixA, matrixB, '-'));

        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}

// Function to print a matrix
void printMatrix(const std::vector<std::vector<int>>& matrix) {
    int size = matrix.size();
    int width = 0;

    // Find the maximum width of matrix elements
    for (const auto& row : matrix) {
        for (int element : row) {
            int elementWidth = std::to_string(element).length();
            if (elementWidth > width) {
                width = elementWidth;
            }
        }
    }

    // Print the matrix
    for (const auto& row : matrix) {
        for (int element : row) {
            std::cout << std::setw(width) << element << " ";
        }
        std::cout << std::endl;
    }
}

// Function to perform matrix addition, multiplication, or subtraction
std::vector<std::vector<int>> matrixOperation(const std::vector<std::vector<int>>& matrixA, const std::vector<std::vector<int>>& matrixB, char operation) {
    int size = matrixA.size();
    std::vector<std::vector<int>> result(size, std::vector<int>(size, 0));

    // Perform matrix operation
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            switch (operation) {
                case '+':
                    result[i][j] = matrixA[i][j] + matrixB[i][j];
                    break;
                case '-':
                    result[i][j] = matrixA[i][j] - matrixB[i][j];
                    break;
                case '*':
                    for (int k = 0; k < size; ++k) {
                        result[i][j] += matrixA[i][k] * matrixB[k][j];
                    }
                    break;
                default:
                    throw std::invalid_argument("Invalid operation");
            }
        }
    }

    return result;
}
