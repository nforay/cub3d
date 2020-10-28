[![Codacy Badge](https://app.codacy.com/project/badge/Grade/03efa6450cb54dfea18446eef947abf3)](https://www.codacy.com/gh/nforay/cub3d/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=nforay/cub3d&amp;utm_campaign=Badge_Grade)

# cub3d
This project is inspired by the world-famous eponymous 90’s game, which was the first FPS ever. It will enable you to explore ray-casting. Your goal will be to make a dynamic view inside a maze, in which you’ll have to find your way.

## Note
***115/100*** :white_check_mark:

## Prerequisites
`sudo apt-get install libbsd-dev libx11-dev libxext-dev`

## Utilisation

1. Run `make` to compile the base version and `make bonus` for a more complete experience.
2. Follow the instructions.

![Bonus map preview](https://i.imgur.com/6rNnVWi.png)

## Controls
If you are running Linux the controls are based on a AZERTY keyboard and on MAC a QWERTY keyboard.

ZQSD / Arrows : Move and Strafe

### Bonus controls:
Bonus version enable mouse camera control, you can change mouse sensitivity by setting `ROT <int>` in the cub file and movement speed (basically the speed at which the game is running) by setting `SP <int>`.
Default ROT is 5 and default SP is 4.
You should play around with these depending of your computer specs.

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

[valgrind_log](https://gist.github.com/nforay/cc2233d9e3b6daee35bdc844f8451363)

[Video preview](https://streamable.com/sqpsp6)
