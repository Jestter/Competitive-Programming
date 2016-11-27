#include <stdio.h>
#include <math.h>
#include <string>
#include <sstream>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void reduce_fraction(int &numerator, int &denominator)
{
    for (int i = denominator * numerator; i > 1; i--)
    {
        if ((denominator % i == 0) && (numerator % i == 0))
        {
            denominator /= i;
            numerator /= i;
        }
    }
}

class Gear
{
  public:
    Gear(int x, int y, int r)
    {
        this->x = x;
        this->y = y;
        this->radius = r;
    }
    bool connected_to(Gear gear, int colour)
    {
        double euclidean_dist = sqrt(((this->x - gear.x) * (this->x - gear.x)) + ((this->y - gear.y) * (this->y - gear.y)));
        if (this->radius + gear.radius - (int)(euclidean_dist) == 0)
        {
            return true;
        }
        return false;
    }

    string to_string()
    {
        stringstream ss;
        ss << "X=" << this->x << " Y=" << this->y << " R=" << this->radius;
        return ss.str();
    }

    vector<int> related_to;
    int x;
    int y;
    int colour = 0;
    int radius;
};

int main()
{
    int n = 0;
    scanf("%d\n", &n);

    vector<Gear> gears;
    while (n--)
    {
        int x, y, r;
        scanf("%d %d %d", &x, &y, &r);
        Gear temp(x, y, r);
        //match graph
        if (gears.size() > 0)
        {
            for (int i = 0; i < gears.size(); i++)
            {
                if (gears[i].connected_to(temp, 0))
                {
                    gears[i].related_to.push_back(gears.size());
                    // temp.related_to.push_back(i);
                    // cout << "matched  to: " << gears[i].to_string();
                }
            }
        }
        gears.push_back(temp);
    }

    gears[0].colour = 1;
    queue<int> bfs_stack;
    bfs_stack.push(0);

    int color = 1;

    bool failed_colouring = false;

    while (bfs_stack.size() != 0 && !failed_colouring)
    {
        int gear_index = bfs_stack.front();
        bfs_stack.pop();
        if (gears[gear_index].colour != 0)
        {
            //paint using current color
            color = gears[gear_index].colour;

            for (int i = 0; i < gears[gear_index].related_to.size(); i++)
            {
                int rel_idx = gears[gear_index].related_to[i];
                if (gears[rel_idx].colour == 0)
                {
                    gears[rel_idx].colour = (color == 1) ? 2 : 1;
                    bfs_stack.push(rel_idx);
                }
                else
                {
                    if (gears[rel_idx].colour == gears[gear_index].colour)
                    {
                        failed_colouring = true;
                        break;
                    }
                }
            }
        }
    }

    //if colour did not fail, then we need to know if there is a connection from one point to another.
    if (failed_colouring)
    {
        cout << "The input gear cannot move.\n";
    }
    else if (gears[gears.size() - 1].colour != 0)
    {

        int x = gears[0].radius, y = gears[gears.size()-1].radius;
        
        reduce_fraction(x, y);
        if (gears[0].colour == gears[gears.size() - 1].colour)
        {
            cout << x <<":" << y << endl;
        }
        else{
            cout << "-" << x <<":" << y << endl;
        }
    }
    else if (gears[gears.size() - 1].colour == 0)
    {
        cout << "The input gear is not connected to the output gear.";
    }
    // cout << failed_colouring << "\n";

    // for( Gear g : gears){
    //     cout << g.to_string() << " RELATED: ";
    //     for(int agg : g.related_to){
    //         cout << agg << " ";
    //     }
    //     cout << endl;
    // }
}