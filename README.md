[![Codacy Badge](https://app.codacy.com/project/badge/Grade/b6f6463b200e4c5b8afe79afe34e45ee)](https://www.codacy.com?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=nforay/cub3d&amp;utm_campaign=Badge_Grade)

# cub3d
Ce projet est inspiré du jeu éponyme mondialement connu, considéré comme le premier FPS jamais développé. Il vous permettra d’explorer la technique du ray-casting. Votre objectif est de faire une vue dynamique au sein d’un labyrinthe, dans lequel vous devrez trouver votre chemin.

## Note
***115/100*** :white_check_mark:

## Utilisation

1. Run `make` to compile the base version and `make bonus` for a more complete experience.
2. Follow the instructions.

![Bonus map preview](https://i.imgur.com/6rNnVWi.png)

## Controls
If you are running Linux the controls are based on a AZERTY keyboard and on MAC a QWERTY keyboard.

ZQSD / Arrows : Move and Strafe
### Bonus keybinds:
| Key | Action |
|--|--|
| 1 | increase distant shading |
| 2 | decrease distant shading |
| 3 | Buffer overlay |
| 4 | Toggle Interlacing |
| 5 | Print map |
| Shift | Sprint |

### Map editor controls:
| Key | Action |
|--|--|
| Ctrl | (Hold) add floor and ceiling |
| Numpad1 | (Toggle) Wall <-> Interior empty space (0 <-> 1) |
| Numpad2 | (Toggle) Exterior Floor w/ skybox <-> Interior Floor w/ skybox |
| Numpad3 | (Toggle) Alternate wall texture |
| Numpad4 | Pushable wall |
| Numpad5 | (Toggle) Doors (Unlocked > Locked Key 1 > Locked Key 2) |
| Numpad6 | Spinning cylinder |
| Numpad7 | (Toggle) Angled wall (2 diagonals) |
| Numpad8 | (Toggle) Rounded wall (one for each corner) |

[Video preview](https://streamable.com/sqpsp6)
