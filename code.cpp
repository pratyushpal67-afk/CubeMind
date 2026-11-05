#include <bits/stdc++.h>
using namespace std;

enum Face {
    U, R, F, B, L, D
};

enum Color {
    WHITE,
    RED,
    GREEN,
    BLUE,
    ORANGE,
    YELLOW
};

using Cube = vector<vector<vector<Color>>>;

vector<string> moves = {
    "U", "U'", "U2",
    "R", "R'", "R2",
    "F", "F'", "F2",
    "L", "L'", "L2",
    "B", "B'", "B2",
    "D", "D'", "D2"
};

unordered_map<string, int> transTable;


Cube createSolvedCube() {
    Cube cube(6, vector<vector<Color>>(3, vector<Color>(3)));

    for (int face = 0; face < 6; face++) {
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                cube[face][row][col] = static_cast<Color>(face);
            }
        }
    }

    return cube;
}


bool isSolved(const Cube& cube) {
    for (int face = 0; face < 6; face++) {
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                if (cube[face][row][col] != face) {
                    return false;
                }
            }
        }
    }

    return true;
}


char colorToChar(Color color) {
    switch (color) {
        case WHITE:  return 'W';
        case RED:    return 'R';
        case GREEN:  return 'G';
        case BLUE:   return 'B';
        case ORANGE: return 'O';
        case YELLOW: return 'Y';
    }

    return '?';
}


void rotateFace(Cube& cube, Face face) {
    vector<vector<Color>> temp(3, vector<Color>(3));

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            temp[col][2 - row] = cube[face][row][col];
        }
    }

    cube[face] = temp;


    if (face == U) {
        vector<Color> t = cube[F][0];

        for (int col = 0; col < 3; col++) {
            cube[F][0][col] = cube[R][0][col];
            cube[R][0][col] = cube[B][0][col];
            cube[B][0][col] = cube[L][0][col];
            cube[L][0][col] = t[col];
        }
    }


    if (face == R) {
        vector<Color> t = {
            cube[U][0][2],
            cube[U][1][2],
            cube[U][2][2]
        };

        for (int row = 0; row < 3; row++) {
            cube[U][row][2] = cube[F][row][2];
        }

        for (int row = 0; row < 3; row++) {
            cube[F][row][2] = cube[D][row][2];
        }

        for (int row = 0; row < 3; row++) {
            cube[D][row][2] = cube[B][2 - row][0];
        }

        for (int row = 0; row < 3; row++) {
            cube[B][2 - row][0] = t[row];
        }
    }


    if (face == F) {
        vector<Color> t = {
            cube[U][2][0],
            cube[U][2][1],
            cube[U][2][2]
        };

        for (int col = 0; col < 3; col++) {
            cube[U][2][col] = cube[L][2 - col][2];
        }

        for (int row = 0; row < 3; row++) {
            cube[L][row][2] = cube[D][0][row];
        }

        for (int col = 0; col < 3; col++) {
            cube[D][0][col] = cube[R][2 - col][0];
        }

        for (int row = 0; row < 3; row++) {
            cube[R][row][0] = t[row];
        }
    }


    if (face == L) {
        vector<Color> t = {
            cube[U][0][0],
            cube[U][1][0],
            cube[U][2][0]
        };

        for (int row = 0; row < 3; row++) {
            cube[U][row][0] = cube[B][2 - row][2];
        }

        for (int row = 0; row < 3; row++) {
            cube[B][2 - row][2] = cube[D][row][0];
        }

        for (int row = 0; row < 3; row++) {
            cube[D][row][0] = cube[F][row][0];
        }

        for (int row = 0; row < 3; row++) {
            cube[F][row][0] = t[row];
        }
    }


    if (face == B) {
        vector<Color> t = {
            cube[U][0][0],
            cube[U][0][1],
            cube[U][0][2]
        };

        for (int col = 0; col < 3; col++) {
            cube[U][0][col] = cube[R][col][2];
        }

        for (int row = 0; row < 3; row++) {
            cube[R][row][2] = cube[D][2][2 - row];
        }

        for (int col = 0; col < 3; col++) {
            cube[D][2][col] = cube[L][2 - col][0];
        }

        for (int row = 0; row < 3; row++) {
            cube[L][row][0] = t[row];
        }
    }


    if (face == D) {
        vector<Color> t = cube[F][2];

        for (int col = 0; col < 3; col++) {
            cube[F][2][col] = cube[L][2][col];
            cube[L][2][col] = cube[B][2][col];
            cube[B][2][col] = cube[R][2][col];
            cube[R][2][col] = t[col];
        }
    }
}


void rotateUPrime(Cube& cube) {
    rotateFace(cube, U);
    rotateFace(cube, U);
    rotateFace(cube, U);
}

void rotateU2(Cube& cube) {
    rotateFace(cube, U);
    rotateFace(cube, U);
}

void rotateRPrime(Cube& cube) {
    rotateFace(cube, R);
    rotateFace(cube, R);
    rotateFace(cube, R);
}

void rotateR2(Cube& cube) {
    rotateFace(cube, R);
    rotateFace(cube, R);
}

void rotateFPrime(Cube& cube) {
    rotateFace(cube, F);
    rotateFace(cube, F);
    rotateFace(cube, F);
}

void rotateF2(Cube& cube) {
    rotateFace(cube, F);
    rotateFace(cube, F);
}

void rotateLPrime(Cube& cube) {
    rotateFace(cube, L);
    rotateFace(cube, L);
    rotateFace(cube, L);
}

void rotateL2(Cube& cube) {
    rotateFace(cube, L);
    rotateFace(cube, L);
}

void rotateBPrime(Cube& cube) {
    rotateFace(cube, B);
    rotateFace(cube, B);
    rotateFace(cube, B);
}

void rotateB2(Cube& cube) {
    rotateFace(cube, B);
    rotateFace(cube, B);
}

void rotateDPrime(Cube& cube) {
    rotateFace(cube, D);
    rotateFace(cube, D);
    rotateFace(cube, D);
}

void rotateD2(Cube& cube) {
    rotateFace(cube, D);
    rotateFace(cube, D);
}


void applyMove(Cube& cube, const string& move) {
    if (move == "U")
        rotateFace(cube, U);
    else if (move == "U'")
        rotateUPrime(cube);
    else if (move == "U2")
        rotateU2(cube);

    else if (move == "R")
        rotateFace(cube, R);
    else if (move == "R'")
        rotateRPrime(cube);
    else if (move == "R2")
        rotateR2(cube);

    else if (move == "F")
        rotateFace(cube, F);
    else if (move == "F'")
        rotateFPrime(cube);
    else if (move == "F2")
        rotateF2(cube);

    else if (move == "L")
        rotateFace(cube, L);
    else if (move == "L'")
        rotateLPrime(cube);
    else if (move == "L2")
        rotateL2(cube);

    else if (move == "B")
        rotateFace(cube, B);
    else if (move == "B'")
        rotateBPrime(cube);
    else if (move == "B2")
        rotateB2(cube);

    else if (move == "D")
        rotateFace(cube, D);
    else if (move == "D'")
        rotateDPrime(cube);
    else if (move == "D2")
        rotateD2(cube);
}


string getState(const Cube& cube) {
    string state;
    state.reserve(54);

    for (int face = 0; face < 6; face++) {
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                state += colorToChar(cube[face][row][col]);
            }
        }
    }

    return state;
}


string inverseMove(const string& move) {
    if (move == "U")  return "U'";
    if (move == "U'") return "U";
    if (move == "U2") return "U2";

    if (move == "R")  return "R'";
    if (move == "R'") return "R";
    if (move == "R2") return "R2";

    if (move == "F")  return "F'";
    if (move == "F'") return "F";
    if (move == "F2") return "F2";

    if (move == "L")  return "L'";
    if (move == "L'") return "L";
    if (move == "L2") return "L2";

    if (move == "B")  return "B'";
    if (move == "B'") return "B";
    if (move == "B2") return "B2";

    if (move == "D")  return "D'";
    if (move == "D'") return "D";
    if (move == "D2") return "D2";

    return "";
}


int heuristic(const Cube& cube) {
    int corners = 0;
    int edges = 0;

    if (!(cube[U][2][2] == WHITE &&
          cube[F][0][2] == GREEN &&
          cube[R][0][0] == RED))
        corners++;

    if (!(cube[U][2][0] == WHITE &&
          cube[F][0][0] == GREEN &&
          cube[L][0][2] == ORANGE))
        corners++;

    if (!(cube[U][0][2] == WHITE &&
          cube[B][0][0] == BLUE &&
          cube[R][0][2] == RED))
        corners++;

    if (!(cube[U][0][0] == WHITE &&
          cube[B][0][2] == BLUE &&
          cube[L][0][0] == ORANGE))
        corners++;

    if (!(cube[D][0][2] == YELLOW &&
          cube[F][2][2] == GREEN &&
          cube[R][2][0] == RED))
        corners++;

    if (!(cube[D][0][0] == YELLOW &&
          cube[F][2][0] == GREEN &&
          cube[L][2][2] == ORANGE))
        corners++;

    if (!(cube[D][2][2] == YELLOW &&
          cube[B][2][0] == BLUE &&
          cube[R][2][2] == RED))
        corners++;

    if (!(cube[D][2][0] == YELLOW &&
          cube[B][2][2] == BLUE &&
          cube[L][2][0] == ORANGE))
        corners;


    if (!(cube[U][2][1] == WHITE &&
          cube[F][0][1] == GREEN))
        edges++;

    if (!(cube[U][1][2] == WHITE &&
          cube[R][0][1] == RED))
        edges++;

    if (!(cube[U][0][1] == WHITE &&
          cube[B][0][1] == BLUE))
        edges++;

    if (!(cube[U][1][0] == WHITE &&
          cube[L][0][1] == ORANGE))
        edges++;

    if (!(cube[F][1][2] == GREEN &&
          cube[R][1][0] == RED))
        edges++;

    if (!(cube[F][1][0] == GREEN &&
          cube[L][1][2] == ORANGE))
        edges++;

    if (!(cube[B][1][0] == BLUE &&
          cube[R][1][2] == RED))
        edges++;

    if (!(cube[B][1][2] == BLUE &&
          cube[L][1][0] == ORANGE))
        edges++;

    if (!(cube[D][0][1] == YELLOW &&
          cube[F][2][1] == GREEN))
        edges++;

    if (!(cube[D][1][2] == YELLOW &&
          cube[R][2][1] == RED))
        edges++;

    if (!(cube[D][2][1] == YELLOW &&
          cube[B][2][1] == BLUE))
        edges++;

    if (!(cube[D][1][0] == YELLOW &&
          cube[L][2][1] == ORANGE))
        edges++;


    int cornerBound = (corners + 3) / 4;
    int edgeBound = (edges + 3) / 4;

    return max(cornerBound, edgeBound);
}


bool idaDFS(
    Cube& cube,
    int depth,
    int limit,
    const string& lastMove,
    vector<string>& path
) {
    if (isSolved(cube))
        return true;

    int h = heuristic(cube);

    if (depth + h > limit)
        return false;

    string key = getState(cube) + lastMove;

    auto it = transTable.find(key);

    if (it != transTable.end() && it->second <= depth)
        return false;

    transTable[key] = depth;


    for (const string& move : moves) {
        if (!lastMove.empty() &&
            move == inverseMove(lastMove))
            continue;

        Cube next = cube;
        applyMove(next, move);

        path.push_back(move);

        if (idaDFS(
                next,
                depth + 1,
                limit,
                move,
                path
            )) {
            return true;
        }

        path.pop_back();
    }

    return false;
}


vector<string> idaStar(Cube cube) {
    int limit = heuristic(cube);
    vector<string> path;

    while (true) {
        transTable.clear();
        path.clear();

        if (idaDFS(
                cube,
                0,
                limit,
                "",
                path
            )) {
            return path;
        }

        limit++;
    }
}


int main() {
    Cube cube = createSolvedCube();

    vector<string> scramble = {
        "U", "R", "F", "D'", "R", "R", "R"
    };

    for (string move : scramble)
        applyMove(cube, move);

    vector<string> solution = idaStar(cube);

    Cube check = cube;

    for (string move : solution)
        applyMove(check, move);

    if (isSolved(check)) {
        for (int i = 0; i < solution.size(); i++) {
            if (i > 0) cout << " ";
            cout << solution[i];
        }
        cout << endl;
    }

    return 0;
}