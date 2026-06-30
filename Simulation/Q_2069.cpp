#include <bits/stdc++.h>
using namespace std;

class Robot 
{
public:
    int idx = 0;
    bool moved = false;
    vector<vector<int>> path;

    Robot(int width, int height) 
    {
        // TC: O(width + height)
        // SC: O(width + height)

        // bottom row
        for (int x = 0; x < width; x++)
        {
            path.push_back({x, 0, 0});
        }

        // right column
        for (int y = 1; y < height; y++)
        {
            path.push_back({width - 1, y, 1});
        }

        // top row
        for (int x = width - 2; x >= 0; x--)
        {
            path.push_back({x, height - 1, 2});
        }

        // left column
        for (int y = height - 2; y > 0; y--)
        {
            path.push_back({0, y, 3});
        }

        path[0][2] = 3;
    }
    
    void step(int num) 
    {
        // TC: O(1)
        // SC: O(1)

        moved = true;
        idx = (idx + num) % path.size();
    }
    
    vector<int> getPos() 
    {
        // TC: O(1)
        // SC: O(1)

        return {path[idx][0], path[idx][1]};
    }
    
    string getDir() 
    {
        // TC: O(1)
        // SC: O(1)

        if (!moved) return "East";

        int d = path[idx][2];

        if (d == 0) return "East";
        else if (d == 1) return "North";
        else if (d == 2) return "West";
        else return "South";
    }
};

int main() 
{
    // TC: O(width + height) for constructor
    // SC: O(width + height)

    int width = 6, height = 3;

    Robot obj(width, height);

    // TC: O(1)
    // SC: O(1)
    obj.step(2);

    // TC: O(1)
    // SC: O(1)
    vector<int> pos = obj.getPos();

    // TC: O(1)
    // SC: O(1)
    string dir = obj.getDir();

    cout << "Position: (" << pos[0] << ", " << pos[1] << ")" << endl;
    cout << "Direction: " << dir << endl;

    return 0;
}
