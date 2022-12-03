#include <cstdio>
#include <string>

using namespace std;

struct rgb {
    int r;
    int g;
    int b;
    rgb(int r, int g, int b): r(r), g(g), b(b) {}
    rgb() {}
};
rgb colors[] = {rgb(255,255,255),rgb(192,192,192),rgb(128,128,128),rgb(0,0,0),rgb(255,0,0),rgb(128,0,0),rgb(255,255,0),rgb(128,128,0),
rgb(0,255,0),rgb(0,128,0),rgb(0,255,255),rgb(0,128,128),rgb(0,0,255),rgb(0,0,128),rgb(255,0,255),rgb(128,0,128)};
string names[] = {"White","Silver","Gray","Black","Red","Maroon","Yellow","Olive","Lime","Green","Aqua","Teal","Blue","Navy","Fuchsia","Purple"};
rgb input;

int diff(rgb a, rgb b) {
    return (a.r-b.r)*(a.r-b.r) + (a.g-b.g)*(a.g-b.g) + (a.b-b.b)*(a.b-b.b);
}

int main() {
    while (true) {
        scanf("%d %d %d", &input.r, &input.g, &input.b);
        if (input.r == -1) {
            return 0;
        }
        int min = 1e9;
        int id = -1;
        for (int i = 0; i < 16; i++) {
            int d = diff(input, colors[i]);
            if (d < min) {
                min = d;
                id = i;
            }
        }
        printf("%s\n", names[id].c_str());
    }
    return 0;
}