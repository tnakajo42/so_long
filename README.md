#### so_long
___

> 42 first game project

[![so_long](https://github.com/user-attachments/assets/14e04941-df34-443f-964c-e97891aa646f)](https://youtu.be/zaKGzGfHjAQ)

# DOWNLOAD MLX42

first, you need to install [MLX42](https://github.com/codam-coding-college/MLX42) library.
MLX42 is a performant, easy to use, cross-platform, minimal windowing graphics library to create graphical applications without having to work directly with the native windowing framework of the given operating system.

```shell
$ make download_mlx42
```

if you do not have cmake in your laptop, try:

```shell
$ brew install cmake
```

# DOWNLOAD MUSIC

Berore play, please download miniaudio to add music.

```shell
$ make download_music
```

> I download a music from the url below

https://downloads.khinsider.com/game-soundtracks/album/dragon-quest-game-music-super-collection-vol.1


# PLAY GAME

```shell
$ make
```

if you fail to make, try:

```shell
$ brew install glfw
```

There are several maps in `./map` folder. Try one of them. \n
for example:

```shell
$ ./so_long ./map/map.ber
```

# CHANGE YOUR CHARACTER AND FIELDS

You can also change the player and enemies image, and map textures. \n
Try:

```shell
$ make switch_charactor
```

# ASSETS

I used textures from the website below

- https://stock.adobe.com/jp/images/rpg/480950138
- https://stock.adobe.com/jp/images/rpg/493247944
