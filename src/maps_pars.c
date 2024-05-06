#include "so_long.h"

void flood_fill(char **map, int x, int y, char target, char new_char) {
    if (map[y][x] != target) {
        return;
    }

    map[y][x] = new_char;

    flood_fill(map, x + 1, y, target, new_char);
    flood_fill(map, x - 1, y, target, new_char);
    flood_fill(map, x, y + 1, target, new_char);
    flood_fill(map, x, y - 1, target, new_char);
}