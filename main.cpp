#include <vector> 
#include <iostream>


//* Create a vector of direction offsets.
std::vector<int> dir_offset = { 8, -8, 1, -1, 7, -7, 9, -9 };
std::vector<int> knight_offsets = { 17, -17, 6, -6 };


//* Precompute amount of squares to end of board from every position (multi-dimensional array)
std::vector<std::vector<int>> computeNumSquaresToEdge() {

    std::vector<std::vector<int>> numSquaresToEdge(64, std::vector<int>(4));

    for (int i = 0; i < 64; ++i) {

        int row = i / 8;
        int col = i % 8;

        // NSEW
        numSquaresToEdge[i][0] = 7 - row;
        numSquaresToEdge[i][1] = row;
        numSquaresToEdge[i][2] = 7 - col;
        numSquaresToEdge[i][3] = col;
    }

    // NOTE: Index of square is square value - 1
    return numSquaresToEdge;
}


//* Function to grab specific squares from the multidimentional array and stores in a single dimentional array
std::vector<int> getSquaresToEdge(int squareIndex) {

    std::vector<std::vector<int>> numSquaresToEdge = computeNumSquaresToEdge();
    std::vector<int> squareDistanceVector;

    for (int i = 0; i < 4; i++) {
        squareDistanceVector.push_back(numSquaresToEdge[squareIndex][i]);
    }

    // [N, S, E, W]
    return squareDistanceVector;
}


//* Create struct for Moves
struct Moves {
    int Startpos;
    int Endpos;
};


//! Generate pseudo-legal moves for a given position
//* Each functions takes in the piece and the starting square of that piece

//? Sliding pieces (Bishop, Rook, Queen)
// Loop over 8 different directions, and loop over number of squares to the edge in that direction (Using prepared function from earlier)
// Use direction offsets to check this
// Skip further checks if there is a friendly piece in the way
// Skip further checks if there is an enemy piece in the way (After adding that piece)
// Add logic so that Bishop checks the last 4 offsets (Horizontal), and Rook checks first 4 (straight). Queen can use all 8. 

//? King
// Uses direction offsets to check all adjacent squares 
// Skip check if there is a friendly piece in the way
// Add checks if there is an enemy piece in the way
// Uses boolean state to determine if king can castle

//? Pawns
// Checks square directly in front to check if pawn is allowed to push (using directional offsets, checks if there is any piece)
// Checks offsets 7 and 9 (front diagonal) to see if there is an enemy piece for there (skips if friendly piece)
// Uses boolean logic to see if pawn is on first rank (checks 2 spots infront)
// Checks offsets 1 and -1 to check if there is an enemy piece. If there is, pass in en passant as a legal move

//? Knight
// Use custom made knight offsets vector to determine possible moves
// Checks if possible positions are off the board (< 1 or > 64), and exterminates impossible moves.
// Checks if there are friendly pieces in the way, and exterminates impossible moves.




//! Generate legal moves given pseudo-legal moves





void testComputeFunc() {
    std::vector<std::vector<int>> numSquaresToEdge = computeNumSquaresToEdge();
    std::vector<int>squareDistanceVector = getSquaresToEdge(1);

    for (int i = 0; i < 64; ++i) {
        std::cout << "[";
        std::cout << numSquaresToEdge[i][0] << ", ";
        std::cout << numSquaresToEdge[i][1] << ", ";
        std::cout << numSquaresToEdge[i][2] << ", ";
        std::cout << numSquaresToEdge[i][3] << "], ";
    }

    std::cout << "" << std::endl;
    std::cout << "" << std::endl;

    std::cout << squareDistanceVector[0] << ", ";
    std::cout << squareDistanceVector[1] << ", ";
    std::cout << squareDistanceVector[2] << ", ";
    std::cout << squareDistanceVector[3] << std::endl;
}

int main() {
    testComputeFunc();
    return 0;
}